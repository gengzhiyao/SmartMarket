
#include "stm32f10x.h"                  // Device header
#include "SPI.h"

static void SPI1_Init(void);
static void SPI2_Init(void);
static uint8_t SPI_WriteRead(SPI_TypeDef* SPIx, uint8_t data, uint32_t timeout);
static void SPI_CS_WritePin(SPI_TypeDef* SPIx, BitAction bitVal);

SPIClassStruct SPIClass = {
	.SPI1_Init = SPI1_Init,
	.SPI2_Init = SPI2_Init,
	.WriteRead = SPI_WriteRead,
	.WriteCSPin = SPI_CS_WritePin
};
// SPI1 CS
#define SPI1_CS_GPIO_PORT    		GPIOB
#define SPI1_CS_GPIO_CLK 	    	RCC_APB2Periph_GPIOB
#define SPI1_CS_GPIO_PIN			GPIO_Pin_0
// SPI2 CS
#define SPI2_CS_GPIO_PORT    		GPIOA
#define SPI2_CS_GPIO_CLK 	    	RCC_APB2Periph_GPIOA
#define SPI2_CS_GPIO_PIN			GPIO_Pin_0

/**
  * @brief  SPI1��ʼ��
  * @param  None
  * @retval None
  */
static void SPI1_Init(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	SPI_InitTypeDef  SPI_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	// SPI1 SCK-PA5  MOSI-PA7
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	// SPI1 MISO-PA6
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	// software CS user write
	RCC_APB2PeriphClockCmd(SPI1_CS_GPIO_CLK, ENABLE);
	GPIO_InitStructure.GPIO_Pin = SPI1_CS_GPIO_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(SPI1_CS_GPIO_PORT, &GPIO_InitStructure);
	GPIO_WriteBit(SPI1_CS_GPIO_PORT, SPI1_CS_GPIO_PIN, Bit_SET); // ����Ƭѡ����
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1, ENABLE); // SPI1ʱ��ʹ��

	SPI_Cmd(SPI1, DISABLE);
	SPI_I2S_DeInit(SPI1);
	SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex; // SPI����Ϊ˫��ȫ˫��
	SPI_InitStructure.SPI_Mode = SPI_Mode_Master; // ����SPIΪ��ģʽ
	SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b; // SPI���ͽ���8λ֡�ṹ
	SPI_InitStructure.SPI_CPOL = SPI_CPOL_Low; // SPIʱ�ӿ���ʱΪ�͵�ƽ
	SPI_InitStructure.SPI_CPHA = SPI_CPHA_1Edge; // ��һ��ʱ���ؿ�ʼ��������
	SPI_InitStructure.SPI_NSS = SPI_NSS_Soft; // CS�ź����������
	SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_16; // SPI������Ԥ��Ƶֵ 72M / Prescaler
	SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB; // ���ݴ����MSBλ��ʼ
	SPI_InitStructure.SPI_CRCPolynomial = 7; // CRCֵ����Ķ���ʽ

	SPI_Init(SPI1, &SPI_InitStructure); // ����SPI_InitStruct��ָ���Ĳ�����ʼ������SPI�Ĵ���
	SPI_Cmd(SPI1, ENABLE); // ʹ��SPI
}

/**
  * @brief  SPI2��ʼ��
  * @param  None
  * @retval None
  */
static void SPI2_Init(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	SPI_InitTypeDef  SPI_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	// SPI1 SCK-PB13  MOSI-PB15
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13 | GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	// SPI1 MISO-PB14
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	// software CS user write
	RCC_APB2PeriphClockCmd(SPI2_CS_GPIO_CLK, ENABLE);
	GPIO_InitStructure.GPIO_Pin = SPI2_CS_GPIO_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(SPI2_CS_GPIO_PORT, &GPIO_InitStructure);
	GPIO_WriteBit(SPI2_CS_GPIO_PORT, SPI2_CS_GPIO_PIN, Bit_SET); // ����Ƭѡ����
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_SPI2, ENABLE); // SPI2ʱ��ʹ��

	SPI_Cmd(SPI2, DISABLE);
	SPI_I2S_DeInit(SPI2);
	SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex; // SPI����Ϊ˫��ȫ˫��
	SPI_InitStructure.SPI_Mode = SPI_Mode_Master; // ����SPIΪ��ģʽ
	SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b; // SPI���ͽ���8λ֡�ṹ
	SPI_InitStructure.SPI_CPOL = SPI_CPOL_Low; // SPIʱ�ӿ���ʱΪ�͵�ƽ
	SPI_InitStructure.SPI_CPHA = SPI_CPHA_1Edge; // ��һ��ʱ���ؿ�ʼ��������
	SPI_InitStructure.SPI_NSS = SPI_NSS_Soft; // CS�ź����������
	SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_8; // SPI������Ԥ��Ƶֵ 36M / Prescaler
	SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB; // ���ݴ����MSBλ��ʼ
	SPI_InitStructure.SPI_CRCPolynomial = 7; // CRCֵ����Ķ���ʽ

	SPI_Init(SPI2, &SPI_InitStructure); // ����SPI_InitStruct��ָ���Ĳ�����ʼ������SPI�Ĵ���
	SPI_Cmd(SPI2, ENABLE); // ʹ��SPI
}
/**
  * @brief  SPI��д����
  * @param  None
  * @retval 0-��ʱ 
  */
static uint8_t SPI_WriteRead(SPI_TypeDef* SPIx, uint8_t data, uint32_t timeout)
{
	uint32_t retry = 0;				 	
	/* Loop while DR register in not emplty */
	while (SPI_I2S_GetFlagStatus(SPIx, SPI_I2S_FLAG_TXE) == RESET) // ���ͻ����־λΪ��
	{
		retry++;
		if(retry > timeout) return 0;
	}			  
	SPI_I2S_SendData(SPIx, data); // ͨ������SPI2����һ������
	retry = 0;
	/* Wait to receive a byte */
	while (SPI_I2S_GetFlagStatus(SPIx, SPI_I2S_FLAG_RXNE) == RESET) // ���ջ����־λ��Ϊ��
	{
		retry++;
		if(retry > timeout) return 0;
	}	  						    
	/* Return the byte read from the SPI bus */
	return SPI_I2S_ReceiveData(SPIx); // ͨ��SPI2���ؽ�������	
}
/**
  * @brief  SPI��д����
  * @param  None
  * @retval 0-�ɹ�
  */
static void SPI_CS_WritePin(SPI_TypeDef* SPIx, BitAction bitVal)
{
	if(SPIx == SPI1) {
		GPIO_WriteBit(SPI1_CS_GPIO_PORT, SPI1_CS_GPIO_PIN, bitVal);
	} else if(SPIx == SPI2) {
		GPIO_WriteBit(SPI2_CS_GPIO_PORT, SPI2_CS_GPIO_PIN, bitVal);
	}
}




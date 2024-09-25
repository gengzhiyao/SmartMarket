//main.qml
import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtPositioning 5.12
import QtLocation 5.12
import Qt.labs.qmlmodels 1.0
import Abcd 1.0
import QtQuick.Dialogs 1.2
import QtGraphicalEffects 1.0
import QtQuick.Layouts 1.3



Window {
    property var mx
    property var my

    property var mcux:37
    property var mcuy:37

    visible: true
    width: mywidth
    height: myheight

    Myobj{
    id:cppobj
    }

    Connections //qml 连接 c++ 信号
       {
           target:cppobj
           function onShouData(li,a) {
           var lis=li
           var i=0;
            tableModel.clear()
            for(i;i<a;i=i+4)
            {//"商品编号","商品名字","商品价格","品牌"
             tableModel.appendRow({"商品编号":lis[i],"商品名字":lis[i+1],"商品价格":lis[i+2],"品牌":lis[i+3]})
             console.log(lis[i]+":"+lis[i+1]+":"+lis[i+2]+":"+lis[i+3]+":")
            }

           }

       }

Connections //qml 连接 c++ 信号
   {
       target:cppobj
       function onMcugps(a1,a2) {
           mcux=a2;mcuy=a1;
           console.log("x:"+mcux+" y"+mcuy);
           point_2.update();
       }

   }

    Connections //qml 连接 c++ 信号
       {
           target:cppobj
           function onShouText(str) {
             textEdit.text=str
           }

       }

    Connections //qml 连接 c++ 信号
       {
           target:cppobj
           function onSendstart(a) {
               switch(a)
               {
               case 1: id_mesDialog_1.icon=StandardIcon.Information;id_mesDialog_1.title="连接状态"
                       id_mesDialog_1.text="连接服务器成功";id_mesDialog_1.visible=true
                break;
               case 2: id_mesDialog_1.icon=StandardIcon.Critical;id_mesDialog_1.title="连接状态"
                       id_mesDialog_1.text="连接服务器失败";id_mesDialog_1.visible=true
                break;
               case 3: id_mesDialog_1.icon=StandardIcon.Information;id_mesDialog_1.title="登录状态"
                       id_mesDialog_1.text="登录成功";id_mesDialog_1.visible=true;myText.text="当前登录用户:"+filedUsr.text;cppobj.setphone(filedPawd.text)
                       denglu_item.visible=false;filedUsr.text='';filedPawd.text='';rowid.visible=true
                       btn1.visible=true;btn2.visible=false;btn3.visible=true;btn4.visible=true;

                break;
               case 4:
                   id_mesDialog_1.icon=StandardIcon.Critical;id_mesDialog_1.title="登录状态"
                   id_mesDialog_1.text="登录失败,用户名或者电话错误";id_mesDialog_1.visible=true
                break;
               case 5:
                   id_mesDialog_1.icon=StandardIcon.Critical;id_mesDialog_1.title="提示"
                   id_mesDialog_1.text="登录框不允许为空,或者电话格式错误";id_mesDialog_1.visible=true
                break;
               }
           }

       }

    Rectangle {
              id: frame;clip: true;x:0;y:2;border.width: 1;visible: false;width: parent.width;radius:5;
               anchors.top:header.bottom;anchors.left: parent.left;anchors.right: parent.right;anchors.bottom: parent.bottom;anchors.rightMargin:5;
               anchors.leftMargin: 5; anchors.bottomMargin:45;border.color: "black";
              //文本编辑器
              TextEdit {
                  id: textEdit;text: "";font.pointSize: 20;height: contentHeight;width: frame.width - vbar.width;y: -vbar.position * textEdit.height
                  wrapMode: TextEdit.Wrap;selectByMouse: true //支持鼠标选择
                  //鼠标区域
                  MouseArea{
                      anchors.fill: parent
                      //鼠标中键滚动信号
                      onWheel: {
                          if (wheel.angleDelta.y > 0) {
                              vbar.decrease();
                          }
                          else {
                              vbar.increase();
                          }
                      }

                  }
              }

              //滚动条
              ScrollBar {
                  id: vbar
                  hoverEnabled: true
                  active: hovered || pressed //鼠标在文本编辑框内或者按下鼠标显示滚动条
                  orientation: Qt.Vertical //垂直方向
                  size: frame.height / textEdit.height
                  width: 20
                  //滚动条位置-右边
                  anchors.top: parent.top;anchors.right: parent.right;anchors.bottom: parent.bottom
                  //滚动条背景
                  background: Rectangle{
                      color: "pink"
                  }
              }
          }


    Item {
            id:denglu_item
            width: 650
            height: 650
            anchors.centerIn: parent
            Item {
                width: 250
                height: 100
                anchors.centerIn: parent
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                GridLayout {
                    id: grid
                    rows:2
                    columns: 2
                    width: 250
                    height: 60
                    columnSpacing: 10
                    Text {
                        text: qsTr("姓名")
                        font.pointSize: 12
                        color: "black"
                    }
                    TextField {
                        id: filedUsr
                        Layout.preferredHeight: 35
                    }
                    Text {
                        text: qsTr("电话")
                        font.pointSize: 12
                        color: "black"
                    }
                    TextField {
                        id: filedPawd
                        Layout.preferredHeight: 35
                    }
                }

                //登录按钮
                Rectangle {
                    id: logBtn
                    width: 200
                    height: 33
                    color: "#6facf9"
                    radius: 4
                    border.width: 1
                    border.color: "black"
                    Text {
                        color: "#ffffff"
                        text: qsTr("登录")
                        anchors.centerIn: parent
                        font.pointSize: 12
                    }
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.top: grid.bottom
                    anchors.topMargin: 40

                    MouseArea {
                        anchors.fill: parent
                        hoverEnabled: true
                        onEntered: {
                            logBtn.color = "#333333"
                        }
                        onPressed: {
                            logBtn.color = "#111111"
                        }
                        onReleased: {
                            logBtn.color = "#333333"
                            cppobj.denglu(filedUsr.text,filedPawd.text);

                        }
                        onExited: {
                            logBtn.color = "#6facf9"
                        }
                    }
                }
            }

        }



    MessageDialog {
            id:id_mesDialog_1
            Component.onCompleted: visible =false
        }


    Label {
        id:lab;width: parent.width;height: 50
        anchors.top:header.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom:40+50
        anchors.topMargin:15
        text: "无人购物超市"
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.pixelSize: 50
        font.italic: true
        color: "#4F4F4F"
    }


    Column{
        visible: false
        id:rowid
        x:20
        y:113
        padding:16
        Label {
            id:lab2;width:50;height: 50
            Text {
                id: myText
                text: qsTr("当前登录用户:小明")
                anchors.centerIn: lab2
                anchors.horizontalCenter: lab2.horizontalCenter
                anchors.verticalCenter: lab2.verticalCenter
                font.pixelSize:12
                font.italic: true
               color: "#4F4F4F"
            }
        }
        Button{

            id:btn_lab;width:70;height:30;visible: true;
            Text {id: te_lab;text: qsTr("退出登录");anchors.centerIn: parent}
            background: Rectangle{id:rect_lab;radius:10;border.color: "black";border.width: 2;}
            onClicked: {btn1.visible=false;btn2.visible=false;denglu_item.visible=true;rowid.visible=false
                        btn3.visible=false;btn4.visible=false;lab.visible=true; Myphone=""}
        }
    }

    Column
    {
    spacing:10
    anchors.horizontalCenter: parent.horizontalCenter
    anchors.verticalCenter: parent.verticalCenter


    Button{
        id:btn1;width:90;height:90;visible: false;
        Text {id: te1;text: qsTr("商店位置");anchors.centerIn: parent}
        background: Rectangle{id:rect1;radius:20;border.color: "black";border.width: 5;}
        onClicked: {var mylist=cppobj.setgps();
                     my=mylist[0];mx= mylist[1];
                   item_map.update(); point_1.update();
                   item_map.visible=true;btn1.visible=false;btn2.visible=true;
                   btn3.visible=true;btn4.visible=true;lab.visible=false;rowid.visible=false }
    }

    Button{
        id:btn3;width:90;height:90;visible: false;
        Text {id: te3;text: qsTr("在售商品");anchors.centerIn: parent}
        background: Rectangle{id:rect3;radius:20;border.color: "black";border.width: 5;}
        onClicked: {cppobj.getData();
                   header.visible=true;btn1.visible=false;btn2.visible=false;tableView.visible=true
                   btn3.visible=false;btn4.visible=false;btn5.visible=true;lab.visible=false;rowid.visible=false}
    }

    Button{
        id:btn4;width:90;height:90;visible: false;
        Text {id: te4;text: qsTr("购买记录");anchors.centerIn: parent}
        background: Rectangle{id:rect4;radius:20;border.color: "black";border.width: 5;}
        onClicked: {cppobj.getText();
                   btn1.visible=false;btn2.visible=false;btn3.visible=false;frame.visible=true
                   btn4.visible=false;btn6.visible=true;lab.visible=false;rowid.visible=false}
    }

    }



    Button{
        id:btn2;x:parent.width/2-btn2.width/2;y:parent.height-btn2.height-10;width:90;height:30;visible: false;
        Text {id: te2;text: qsTr("定位退出");anchors.centerIn: parent}
        background: Rectangle{id:rect2;radius:20;border.color: "black";border.width: 5;}
        onClicked: { item_map.visible=false; btn1.visible=true;btn2.visible=false;
             btn3.visible=true;btn4.visible=true;lab.visible=true;rowid.visible=true}
    }
    Button{
        id:btn5;x:parent.width/2-btn5.width/2;y:parent.height-btn5.height-10;width:90;height:30;visible: false;
        Text {id: te5;text: qsTr("退出");anchors.centerIn: parent}
        background: Rectangle{id:rect5;radius:20;border.color: "black";border.width: 5;}
        onClicked: { header.visible=false; btn1.visible=true;btn2.visible=false;tableView.visible=false
                     btn3.visible=true;btn4.visible=true;btn5.visible=false;lab.visible=true;rowid.visible=true}
    }
    Button{
        id:btn6;x:parent.width/2-btn6.width/2;y:parent.height-btn6.height-10;width:90;height:30;visible: false;
        Text {id: te6;text: qsTr("退出");anchors.centerIn: parent}
        background: Rectangle{id:rect6;radius:20;border.color: "black";border.width: 5;}
        onClicked: { item_map.visible=false; btn1.visible=true;btn2.visible=false;frame.visible=false
                btn3.visible=true;btn4.visible=true;btn6.visible=false;lab.visible=true;rowid.visible=true}
    }



    //拖动窗口大小图元位置不能实时跟随，做此下策
    onWidthChanged: item_map.zoomLevel+=0.000001
    onHeightChanged: item_map.zoomLevel-=0.000001

    //绘制地图的容器
    Map{
        visible: false
        id: item_map
        anchors.fill: parent
        anchors.bottomMargin:45

        plugin: Plugin{
            //首选插件语言环境的有序列表,但是貌似没啥用
            locales: "zh-CN"

            //插件的名称
            //osm需要把openssl的dll放到运行目录
            //esri默认就能用,mapbox的我这里加载不了,here的不知道咋用
            //esri默认这个图成都那里不对（放大后）
            name: "osm" // "mapboxgl", "esri", "osm"...
        }

        //初始中心点-成都
        center: QtPositioning.coordinate(mx, my)
        //初始缩放等级
        zoomLevel: 12
        //最大缩放等级
        maximumZoomLevel: 15
        //最小缩放等级
        minimumZoomLevel: 1
        //背景色，没有正常加载时显色的图块颜色
        color: "green"
        //地图的方位
        //如果用于Map的插件支持方位，则该值的有效范围在0到360之间。
        //如果用于Map的插件不支持方位，则更改此属性将无效。
        bearing: bearing_slider.value

        //在地图上显示任意Qt Quick对象
        MapQuickItem{
            id: point_1
            //缩放等级默认0固定大小，否则会和缩放等级一起放大缩小
            zoomLevel: 0
            //指示的坐标点

            coordinate: QtPositioning.coordinate(mx, my)
            //sourceItem左上角相对于coordinate的偏移
            anchorPoint: Qt.point(sourceItem.width/2,sourceItem.height/2)
            //Qt Quick对象
            sourceItem: Rectangle{
                width: 10
                height:10
                radius: 8
                color: "red"
                border.color: "red"
                border.width: 1
                MouseArea{
                    anchors.fill: parent
                    onClicked: console.log("click")
                }
                //coordinate类型有经纬度高度三个属性
                //latitude 纬度
                //longitude 经度
                //altitude 海拔高度，单位米
                //以及计算距离和方位角的方法
                //这里用文本显示两个点的距离
                Text{
                    text: "   我"
                    color: "green"
                    font.bold: true
                    font.pixelSize: 16
                }

            }
            //Qt5.14加了一个淡入属性autoFadeIn
        }

        MapQuickItem{
            id: point_2
            zoomLevel: 0 //和缩放等级一起放大缩小
            coordinate: QtPositioning.coordinate(mcux,mcuy)
            anchorPoint: Qt.point(sourceItem.width/2,sourceItem.height/2)
            sourceItem: Rectangle{
                width: 12
                height: 12
                radius: 7
                color: "blue"
                border.color: "red"
                border.width: 1
                Text{
                    text: "   MCU所在位置\r\n   "+Math.round(point_1.coordinate.distanceTo(
                                                      point_2.coordinate))/1000+" km"
                    color: "green"
                    font.bold: true
                    font.pixelSize: 16
                }
            }
        }

        //此外，还有MapCircle，MapRectangle，MapPolygon等图元类型
        //他们是和地图成比例的

        Rectangle{
            x: 10
            y: 10
            height: item_center.height+20
            width: item_center.width+20
            color: "green"
            Text{
                id: item_center
                x: 10
                y: 10
                color: "white"
                font.pixelSize: 16
                font.bold: true
                //展示缩放等级 和 map的中心点经纬度
                text: "zoom level:"+Math.floor(item_map.zoomLevel)+
                      " center:"+item_map.center.latitude+
                      "  "+item_map.center.longitude
            }
        }
    }


    TableView{
            visible: false
            id:tableView
            width: parent.width
            anchors.top:header.bottom
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            anchors.bottomMargin:40
            clip: true
            boundsBehavior: Flickable.OvershootBounds


            ScrollBar.vertical: ScrollBar {
                anchors.right:parent.right
                anchors.rightMargin: 0
                visible: tableModel.rowCount > 5
                background: Rectangle{
                    color:"#666666"
                }
                onActiveChanged: {
                    active = true;
                }
                contentItem: Rectangle
                {
                    implicitWidth  : 6
                    implicitHeight : 30
                    radius : 3
                    color  : "#848484"
                }
            }

            model: TableModel {
                id:tableModel
                TableModelColumn{display: "商品编号"}
                TableModelColumn{display: "商品名字"}
                TableModelColumn{display: "商品价格"}
                TableModelColumn{display: "品牌"}

            }
            delegate: Rectangle{
                color: "#666666"
                implicitWidth: tableView.width/4
                implicitHeight: 32
                border.width: 1
                border.color: "#848484"
                Text {
                    text: display
                    anchors.centerIn: parent
                    font.pointSize: 12
                    color: "white"
                }
            }
        }

    Rectangle{
            id:header;width: parent.width;height: 30
           y:30
            visible: false
            Row{spacing: 0;
            Repeater{model: ["商品编号","商品名字","商品价格","品牌"]
                    Rectangle{width: header.width/4;height: header.height;color: "#666666";border.width: 1;
                        border.color: "#848484"
                        Text {text: modelData;anchors.centerIn: parent;font.pointSize: 12;color: "white"
                        }
                    }
                }
            }
        }


}

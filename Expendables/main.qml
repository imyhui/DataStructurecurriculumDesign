import QtQuick 2.5
import QtQuick.Window 2.2
import Union.Lotto.Circle 1.0
import QtQuick.Dialogs 1.1
import QtQuick.Controls 1.1

ApplicationWindow {
    id: applicationWindow1
    visible: true
    width: 580
    height: 420
    title: qsTr("数据结构课设——敢死队问题")

    Action {
        id: clearAction
        text: qsTr("清空")
        onTriggered: {
            show1.text = "当前执行任务者";
            show2.text = "";
            if (theModel.count==0)
            {
                messageDialog.title = "警告";
                messageDialog.text = "已经为空，如需报数，请输入元素并添加元素";
                messageDialog.visible = true;
            }
            else
            {
                //input.text = "";
                input.focus = true;
                theModel.clear();
                countnext.stop();
                outshowAction.key=1;
                messageDialog.title = "警告";
                messageDialog.text = "清空完成      ";
                messageDialog.visible = true;
            }
        }
    }
    Action {
        id: exitAction
        text: qsTr("退出")
        onTriggered: sure.visible =true
    }
    Action {
        id: aboutAction
        text: qsTr("关于")
        onTriggered:{
            messageDialog.title = "关于"
            messageDialog.text =  "\n\n数据结构课设：敢死队问题\n作者：刘永辉\n班级：计科1602\n学号：20168325\n专业：计算机科学与技术\nqq：1359158019\nblog:andyhui.top\ngithub:github.com/imyhui"
            messageDialog.visible = true;
    }
        }
    Action {
        id: addAction
        text: qsTr("添加")
        onTriggered: {
            input.focus = false;
            var n  = input.text;
            messageDialog.title = "警告"
            if (n=='')
            {
                messageDialog.text =  "输入为空,请重新输入      "
                messageDialog.visible = true;
                input.focus = true;
            }
            else if (theModel.count>0)
            {
                messageDialog.text = "已经添加元素请勿重复添加      ";
                messageDialog.visible = true;
            }
            else
            {
                for(var i = 1; i <= n;i++)
                {
                     theModel.append({"number": i});
                }
             }
        }
    }
    Action {
        id: outshowAction
        text: qsTr("出圈动画")
        onTriggered: {
            if (theModel.count==0)
            {
                messageDialog.title = "警告";
                messageDialog.text = "请添加元素      ";
                messageDialog.visible = true;
            }
            else{
                circle.begin();
//                var s = circle.getOutList();
//                var arr=s.split(" ");
//                var len = circle.getLen();
//                //console.log(len);
//                for (var i = 0;i< circle.getLen();i++)
//                {
//                    //console.log(arr[i].charCodeAt()-48);
//                    arr[i] =arr[i].charCodeAt()-48;
//                }
//                //console.log(len);
                m_GridView.currentIndex =circle.getTheFirst()-1;
                countnext.start();
//                for(var i = 0;i < len;i++)
//                {
//                    m_GridView.currentIndex =arr[i]-1;
//                    console.log(arr[i]-1);
//                    theModel.get(arr[i]-1).number = -1;
//                }

            }
        }
         property int key: 1;

    }
    Action {
        id: outinformAction
        text: qsTr("出圈顺序")
        onTriggered: {
            input.focus = false;
            messageDialog.title = "警告"
            if (input.text==''||input.text==0)
            {
                messageDialog.text =  "输入为空,请重新输入      "
                messageDialog.visible = true;
                input.focus = true;
            }
            else{
                circle.begin()
                var s = circle.getOutList();
                var arr=s.split(" ");
                var news='';
                for (var i = 0;i< circle.getLen();i++)
                {
                    //console.log(arr[i].charCodeAt()-48);
                    arr[i] =arr[i].charCodeAt()-48;
                    news+=arr[i]+' ';
                }
                messageDialog.title = "结果";
                messageDialog.text = "第一个执行任务的人为"+circle.getTheFirst()+"\n\n出圈顺序为"+news;
                messageDialog.visible = true;
            }
        }
    }

    Action {
        id: checkarray
        text: qsTr("数组")
        onTriggered: {data.key = 1;show4.text = "数组";}
        }
    Action {
        id: checksqlist
        text: qsTr("顺序表")
        onTriggered: {data.key = 2;show4.text = "顺序表";}
        }
    Action {
        id: checkqueue
        text: qsTr("队列")
        onTriggered: {data.key = 3;show4.text = "队列";}
        }
    Action {
        id: checklinklist
        text: qsTr("循环链表")
        onTriggered: {data.key = 4;show4.text = "循环链表";}
        }

    menuBar: MenuBar {
        Menu {
            title: qsTr("&系统")
            MenuItem { action: clearAction }
            MenuItem { action: exitAction }
            MenuSeparator {}
            MenuItem { action: aboutAction }
        }
        Menu {
            title: qsTr("&操作")
            MenuItem { action: addAction }
            MenuSeparator {}
            MenuItem { action: outshowAction }
            MenuItem { action: outinformAction }
//            MenuItem { action: selectAllAction }
        }
        Menu {
            id:data
            title: qsTr("&选择数据结构")
            MenuItem { action: checkarray}
            MenuItem { action: checksqlist }
            MenuItem { action: checkqueue }
            MenuItem { action: checklinklist }
            property int key: 1;
        }
    }
    toolBar: ToolBar {
        id:toolBar
        Row {
            anchors.fill: parent
            ToolButton { action: clearAction }
            ToolButton { action: addAction }
            ToolButton { action: outshowAction }
            ToolButton { action: outinformAction }
        }
        //输入框
        TextInput
            {
                id: input
                y: 285
                anchors.left: parent.left;
                anchors.right: parent.right;            width: 100; height: 20; focus: true
                //KeyNavigation.tab: input2
                IntValidator{id: intval; bottom: 10; top: 100;}
                text: ""
                transformOrigin: Item.Center
                font.bold: true
                horizontalAlignment: Text.AlignHCenter
                anchors.verticalCenterOffset: 4
                anchors.verticalCenter: parent.verticalCenter
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 4
                anchors.rightMargin: 246
                anchors.leftMargin: 266
                validator: intval;
            }
        Label {
            id:show0;
            x: 226
            anchors.right: parent.right;
            anchors.top: parent.top;
            text: "总人数:"
            anchors.rightMargin: 300
            anchors.topMargin: 14
            textFormat: Text.AutoText
            wrapMode: Text.NoWrap
        }
        Label {
            id:show1;
            anchors.right: parent.right;
            anchors.top: parent.top;
            text: "当前执行任务者"
            textFormat: Text.AutoText
            wrapMode: Text.NoWrap
        }
        Label {
            id:show2;
            color: "#df3737"
            anchors.right: show1.right;
            anchors.top: parent.top;
            text: ""
        }
        Label {
            id:show3;
            x: 325
            anchors.right: parent.right;
            anchors.top: parent.top;
            text: "数据结构选择:"
            anchors.rightMargin: 165
            anchors.topMargin: 14
            textFormat: Text.AutoText
            wrapMode: Text.NoWrap
        }
        Label {
            id:show4;
            x: 412
            height: 13
            anchors.right: parent.right;
            anchors.top: parent.top;
            text: "数组"
            horizontalAlignment: Text.AlignLeft
            font.bold: true
            anchors.rightMargin: 108
            anchors.topMargin: 13
            textFormat: Text.AutoText
            wrapMode: Text.NoWrap
        }
    }
    Rectangle {
        id: rectangle1
        anchors.left: parent.left;
        anchors.right: parent.right;
        anchors.top: parent.top;
        anchors.bottom: parent.bottom;

        //圆角
        radius: 20;
        anchors.topMargin: 5
        //框宽
        width: 580;
        //框高
        height: 700;
        //背景色渐变
        gradient: Gradient {
            GradientStop { position: 0.0; color: "#ffffff" }
            GradientStop { position: 1.0; color: "#5fc9f8"; }
        }
        Circle {
            id: circle
            onBegin:
                doSomething(input.text,data.key)
        }

        //list模型默认
        ListModel {
            id: theModel
//            ListElement { number: 1;color:"black"}
//            ListElement { number: 2; }
//            ListElement { number: 3; }
//            ListElement { number: 4; }
//            ListElement { number: 5; }
//            ListElement { number: 6; }
//            ListElement { number: 7; }
//            ListElement { number: 8; }
//            ListElement { number: 9; }
        }
        //弹出框
        MessageDialog {
            id: messageDialog
            title: ""
            text:""
            onAccepted: {
                //console.log("And of course you could only agree.")
            }
            Component.onCompleted: visible = false
        }
        //确定与否
        MessageDialog {
            id: sure
            title: "退出"
            text:"确定退出？"
            standardButtons: StandardButton.Yes | StandardButton.No
            onYes: {
                 Qt.quit();
                        }
            Component.onCompleted: visible = false
                    }
        GridView {
            id : m_GridView
            anchors.fill: parent;
            anchors.margins: 20;
            anchors.bottomMargin: 17

            clip: true;

            model: theModel;//绑定数据源

            cellWidth: 45;//设置项大小
            cellHeight: 45;
            delegate: numberDelegate;//设置绘制代理
            highlight: highlightComponent //定义高亮代理
            focus: true
        }
        //定义高亮
        Component {
                id: highlightComponent
                Rectangle {
                    z:1
//                    width: GridView.view.width
                    color: "transparent"
                    border.color: "blue"

                }
            }
        //自定义绘制代理
        Component {
            id: numberDelegate;

            Rectangle {
                id: wrapper;

                width: 40;
                height: 40;
                //渐变的矩形框
//                gradient: Gradient {
//                    GradientStop { position: 0.0; color: "#f8306a"; }
//                    GradientStop { position: 1.0; color: "#157efb"; }
//                }
                color: GridView.isCurrentItem?"#157efb":"#53d769";
                //文本值是number的数值
                Text {
                    anchors.centerIn: parent;

                    font.pixelSize: 10;

                    text: number;
                    color: "black"
                }

                //鼠标点击代理时，移除点击项
                MouseArea {
                    anchors.fill: parent;

                    onClicked: {
//                        if (!wrapper.GridView.delayRemove)//是否延迟移除
//                        {
//                            theModel.remove(index);
//                        }
                    }
                }

                //GridView移除项  顺序动画
                GridView.onRemove: SequentialAnimation {
                    //属性变化
                    PropertyAction {
                        target: wrapper;
                        property: "GridView.delayRemove";
                        value: true;
                    }
                    //数字动画
                    NumberAnimation {
                        target: wrapper;//目标对象
                        property: "scale";//执行动画的属性
                        to: 0;//结束值
                        duration: 250;//动画持续时长
                        easing.type: Easing.InOutQuad;//动画执行曲线
                    }
                    PropertyAction {
                        target: wrapper;
                        property: "GridView.delayRemove";
                        value: false;
                    }
                }

                //GridView新增项  顺序动画
                GridView.onAdd: SequentialAnimation {
                    NumberAnimation {
                        target: wrapper;
                        property: "scale";
                        from: 0;//开始值
                        to: 1;
                        duration: 250;
                        easing.type: Easing.InOutQuad;
                    }
                }
            }
        }
    }
    Timer {
        id : countnext;
        //interval属性用来设置时间间隔，单位是毫秒，默认值是1000毫秒；
        //repeat属性设置是否重复触发，如果为false，值触发一次，并将running自动设为false
        //running属性为true时开启定时器，否则停止定时器
        //定时器触发执行onTriggered()信号处理函数，可以定义一些操作
        //Timer还提供了一些函数，如restart()、start()和stop()等
        interval: 1000; running:false; repeat:true
        onTriggered:{
            var k = false;
            var s = m_GridView.currentIndex;
            while(!k)
            {
                if(s!=theModel.count-1)
                     s = (s+1);
                else
                    s = 0;
                if(theModel.get(s).number != -1)
                    k = true;
            }
            m_GridView.currentIndex = s;
            outshowAction.key++;
            show1.text = "\n当前元素为"+(s+1)+'\n'+"当前报数值为"+outshowAction.key;
            if(outshowAction.key==5)
            {
                    countnext.stop();
                    outshowAction.key=0;
                    countmove.start();
            }
        }
    }
    Timer {
        id : countmove;
        interval: 2000; running:false; repeat:false
        onTriggered:{
            if(m_GridView.currentIndex!=0)
                {
                show2.text = (m_GridView.currentIndex+1)+"任务失败，出圈！";
            theModel.get(m_GridView.currentIndex).number = -1;
            countnext.start();
                }
            else
            {
                messageDialog.title = "任务结束";
                messageDialog.text = "大吉大利，晚上吃鸡！";
                messageDialog.visible = true;
            }
        }
    }

}

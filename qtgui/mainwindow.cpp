#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "libcontroller.h"

int DeviceInit()
{
    devfd=device_open();
    if(devfd==0)
    {
        printf("open error\n");
        return 0;
    }
    printf("devfd=%d\n",devfd);

    return devfd;
}

void BroadCast()
{
    packet_set(&user_packet,0,255,2,0,0,0);
    ret=packet_send(devfd,user_packet);
    printf("send ret=%d\n",ret);
}



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ret = DeviceInit();
    BroadCast();

    ui->setupUi(this);

    //addTableItem("test", 0, 0, "tfc");
    MainListSet();
}

void MainWindow::MainListSet()
{
    get_devlist(devfd,dev_list);
    ui->mainList->setColumnCount(2);

    for(i=0; i<254; i++)
    {
        if(dev_list[i].addr==255)
            break;
        printf("dev_list[%d].addr=%d\n",i,dev_list[i].addr);
        printf("dev_list[%d].devicetype=%d\n",i,dev_list[i].devicetype);

        QString str = "";

        str.toStdString().c_str();


        if(dev_list[i].devicetype == 1)
        {
            ui->mainList->insertRow(i);
            QTableWidgetItem *item = new QTableWidgetItem( QString("TV"), 0);
            ui->mainList->setItem(i, 0, item);
            QTableWidgetItem *item2 = new QTableWidgetItem( str.setNum(dev_list[i].addr), 0);
            ui->mainList->setItem(i, 1, item2);
        }
        if(dev_list[i].devicetype == 2)
        {
            ui->mainList->insertRow(i);
            QTableWidgetItem *item = new QTableWidgetItem( QString("Refrigerator"), 0);
            ui->mainList->setItem(i, 0, item);
            QTableWidgetItem *item2 = new QTableWidgetItem( str.setNum(dev_list[i].addr), 0);
            ui->mainList->setItem(i, 1, item2);
        }
        if(dev_list[i].devicetype == 3)
        {
            ui->mainList->insertRow(i);
            QTableWidgetItem *item = new QTableWidgetItem( QString("Light"), 0);
            ui->mainList->setItem(i, 0, item);
            QTableWidgetItem *item2 = new QTableWidgetItem( str.setNum(dev_list[i].addr), 0);
            ui->mainList->setItem(i, 1, item2);
        }
        if(dev_list[i].devicetype == 4)
        {
            ui->mainList->insertRow(i);
            QTableWidgetItem *item = new QTableWidgetItem( QString("Air Controller"), 0);
            ui->mainList->setItem(i, 0, item);
            QTableWidgetItem *item2 = new QTableWidgetItem( str.setNum(dev_list[i].addr), 0);
            ui->mainList->setItem(i, 1, item2);
        }
    }
}


void MainWindow::addTableItem(char* str, int x, int y, char* name)
{


    for(int i =0; i<10; i++)
    {

    }
}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_mainStart_clicked()
{
    if(menu == 1)
        ui->zTvWidget->setGeometry(QRect(0, 0, 800, 480));
    else if(menu == 2)
        ui->zRefWidget->setGeometry(QRect(0, 0, 800, 480));
    else if(menu == 3)
        ui->zLightWidget->setGeometry(QRect(0, 0, 800, 480));
    else if(menu == 4)
        ui->zAirWidget->setGeometry(QRect(0, 0, 800, 480));
}

void MainWindow::DeleteItem()
{
    while(ui->mainList->columnCount() > 0)
    {
        ui->mainList->removeColumn(0);
        ui->mainList->insertRow(0);
    }
}

void MainWindow::on_mainTv_clicked()
{
    menu = 1;
    int j= 0;

    DeleteItem();
    get_devlist(devfd,dev_list);

    ui->mainList->setColumnCount(2);

    for(i=0; i<254; i++)
    {
        if(dev_list[i].addr==255)
            break;
        printf("dev_list[%d].addr=%d\n",i,dev_list[i].addr);
        printf("dev_list[%d].devicetype=%d\n",i,dev_list[i].devicetype);


        if(dev_list[i].devicetype == 1)
        {
            QString str = "TV";

            str.toStdString().c_str();
            ui->mainList->insertRow(j);
            QTableWidgetItem *item = new QTableWidgetItem( QString("TV"), 0);
            ui->mainList->setItem(j, 0, item);
            QTableWidgetItem *item2 = new QTableWidgetItem( str.setNum(dev_list[i].addr), 0);
            ui->mainList->setItem(j, 1, item2);
            j++;
        }


    }
}

void MainWindow::on_mainReg_clicked()
{
    menu = 2;
    int j=0;
    DeleteItem();
    get_devlist(devfd,dev_list);
    ui->mainList->setColumnCount(2);

    for(i=0; i<254; i++)
    {
        if(dev_list[i].addr==255)
            break;
        printf("dev_list[%d].addr=%d\n",i,dev_list[i].addr);
        printf("dev_list[%d].devicetype=%d\n",i,dev_list[i].devicetype);



        if(dev_list[i].devicetype == 2)
        {
            QString str = "TV";

            str.toStdString().c_str();

            ui->mainList->insertRow(j);
            QTableWidgetItem *item = new QTableWidgetItem( QString("Refrigerator"), 0);
            ui->mainList->setItem(j, 0, item);
            QTableWidgetItem *item2 = new QTableWidgetItem( str.setNum(dev_list[i].addr),0);
            ui->mainList->setItem(j, 1, item2);
            j++;
        }


    }
}

void MainWindow::on_mainLight_clicked()
{
    menu = 3;
    int j=0;
    DeleteItem();
    get_devlist(devfd,dev_list);
    ui->mainList->setColumnCount(2);

    for(i=0; i<254; i++)
    {
        if(dev_list[i].addr==255)
            break;
        printf("dev_list[%d].addr=%d\n",i,dev_list[i].addr);
        printf("dev_list[%d].devicetype=%d\n",i,dev_list[i].devicetype);


        if(dev_list[i].devicetype == 3)
        {
            QString str = "TV";

            str.toStdString().c_str();

            ui->mainList->insertRow(j);
            QTableWidgetItem *item = new QTableWidgetItem( QString("Light"), 0);
            ui->mainList->setItem(j, 0, item);
            QTableWidgetItem *item2 = new QTableWidgetItem( str.setNum(dev_list[i].addr), 0);
            ui->mainList->setItem(j, 1, item2);
            j++;
        }


    }
}

void MainWindow::on_mainAir_clicked()
{
    menu = 4;
    int j=0;
    DeleteItem();
    get_devlist(devfd,dev_list);
    ui->mainList->setColumnCount(2);

    for(i=0; i<254; i++)
    {
        if(dev_list[i].addr==255)
            break;
        printf("dev_list[%d].addr=%d\n",i,dev_list[i].addr);
        printf("dev_list[%d].devicetype=%d\n",i,dev_list[i].devicetype);


        if(dev_list[i].devicetype == 4)
        {
            QString str = "TV";

            str.toStdString().c_str();

            ui->mainList->insertRow(j);
            QTableWidgetItem *item = new QTableWidgetItem( QString("Air Controller"), 0);
            ui->mainList->setItem(j, 0, item);
            QTableWidgetItem *item2 = new QTableWidgetItem( str.setNum(dev_list[i].addr), 0);
            ui->mainList->setItem(j, 1, item2);
            j++;
        }

    }
}

void MainWindow::on_Back_clicked()
{
    menu = 0;
    ui->zTvWidget->setGeometry(QRect(0, 600, 800, 480));
}

void MainWindow::on_Power_clicked()
{
    //tv power on/off
    packet_set(&user_packet,0,number,1,1,1,0);
    ret=packet_send(devfd,user_packet);
    printf("send ret=%d\n",ret);

    packet_set(&user_packet,0,number,2,1,1,0);
    ret=packet_send(devfd,user_packet);
    printf("send ret=%d\n",ret);

    ret=packet_recv(devfd,&recv_packet);
    printf("recv ret=%d\n");

    printf("recv_packet.src=%d\n",recv_packet.src);
    printf("recv_packet.dst=%d\n",recv_packet.dst);
    printf("recv_packet.optype=%d\n",recv_packet.optype);
    printf("recv_packet.operation=%d\n",recv_packet.operation);
    printf("recv_packet.operand[0]=%d\n",recv_packet.operand[0]);
    printf("recv_packet.operand[1]=%d\n",recv_packet.operand[1]);
    
}

void MainWindow::on_tvChDown_clicked()
{
    //tv ch down
    packet_set(&user_packet,0,number,2,2,2,0);
    ret=packet_send(devfd,user_packet);
    printf("send ret=%d\n",ret);

    ret=packet_recv(devfd,&recv_packet);
    printf("recv ret=%d\n");

    printf("recv_packet.src=%d\n",recv_packet.src);
    printf("recv_packet.dst=%d\n",recv_packet.dst);
    printf("recv_packet.optype=%d\n",recv_packet.optype);
    printf("recv_packet.operation=%d\n",recv_packet.operation);
    printf("recv_packet.operand[0]=%d\n",recv_packet.operand[0]);
    printf("recv_packet.operand[1]=%d\n",recv_packet.operand[1]);

    recv_packet.operand[1]= recv_packet.operand[1]-1;

    packet_set(&recv_packet,0,number,1,2,1,1);
    ret=packet_send(devfd,recv_packet);
    printf("send ret=%d\n",ret);

    packet_set(&user_packet,0,number,2,1,1,0);
    ret=packet_send(devfd,user_packet);
    printf("send ret=%d\n",ret);
    ret=packet_recv(devfd,&recv_packet);
    printf("recv ret=%d\n");

    printf("recv_packet.src=%d\n",recv_packet.src);
    printf("recv_packet.dst=%d\n",recv_packet.dst);
    printf("recv_packet.optype=%d\n",recv_packet.optype);
    printf("recv_packet.operation=%d\n",recv_packet.operation);
    printf("recv_packet.operand[0]=%d\n",recv_packet.operand[0]);
    printf("recv_packet.operand[1]=%d\n",recv_packet.operand[1]);
}

void MainWindow::on_tvChUp_clicked()
{
    //tv ch up
    packet_set(&user_packet,0,number,2,2,2,0);
    ret=packet_send(devfd,user_packet);
    printf("send ret=%d\n",ret);

    ret=packet_recv(devfd,&recv_packet);
    printf("recv ret=%d\n");

    printf("recv_packet.src=%d\n",recv_packet.src);
    printf("recv_packet.dst=%d\n",recv_packet.dst);
    printf("recv_packet.optype=%d\n",recv_packet.optype);
    printf("recv_packet.operation=%d\n",recv_packet.operation);
    printf("recv_packet.operand[0]=%d\n",recv_packet.operand[0]);
    printf("recv_packet.operand[1]=%d\n",recv_packet.operand[1]);

    recv_packet.operand[1]= recv_packet.operand[1]+1;

    packet_set(&recv_packet,0,number,1,2,1,1);
    ret=packet_send(devfd,recv_packet);
    printf("send ret=%d\n",ret);
}

void MainWindow::on_tvVoDown_clicked()
{
    //tv vo down
}

void MainWindow::on_tvVoUp_clicked()
{
    //tv vo up
}

void MainWindow::on_Back_3_clicked()
{
    menu = 0;
    ui->zRefWidget->setGeometry(QRect(0, 600, 800, 480));
}

void MainWindow::on_Power_3_clicked()
{
    //ref power on/off
    packet_set(&user_packet,0,number,2,1,1,0);
    ret=packet_send(devfd,user_packet);
    printf("send ret=%d\n",ret);

    ret=packet_recv(devfd,&recv_packet);
    printf("recv ret=%d\n");

    printf("recv_packet.src=%d\n",recv_packet.src);
    printf("recv_packet.dst=%d\n",recv_packet.dst);
    printf("recv_packet.optype=%d\n",recv_packet.optype);
    printf("recv_packet.operation=%d\n",recv_packet.operation);
    printf("recv_packet.operand[0]=%d\n",recv_packet.operand[0]);
    printf("recv_packet.operand[1]=%d\n",recv_packet.operand[1]);
}

void MainWindow::on_refTemDown_clicked()
{
    //ref tem down
}

void MainWindow::on_refTemUp_clicked()
{
    //ref tem up
}

void MainWindow::on_Back_2_clicked()
{
    menu = 0;
    ui->zLightWidget->setGeometry(QRect(0, 600, 800, 480));
}

void MainWindow::on_Power_2_clicked()
{
    //light power on/off
    packet_set(&user_packet,0,number,3,1,1,0);
    ret=packet_send(devfd,user_packet);
    printf("send ret=%d\n",ret);

    ret=packet_recv(devfd,&recv_packet);
    printf("recv ret=%d\n");

    printf("recv_packet.src=%d\n",recv_packet.src);
    printf("recv_packet.dst=%d\n",recv_packet.dst);
    printf("recv_packet.optype=%d\n",recv_packet.optype);
    printf("recv_packet.operation=%d\n",recv_packet.operation);
    printf("recv_packet.operand[0]=%d\n",recv_packet.operand[0]);
    printf("recv_packet.operand[1]=%d\n",recv_packet.operand[1]);
}

void MainWindow::on_lightBrDown_clicked()
{
    //light brite down
}

void MainWindow::on_lightBrUp_clicked()
{
    //light bright up
}

void MainWindow::on_Back_4_clicked()
{
    menu = 0;
    ui->zAirWidget->setGeometry(QRect(0, 600, 800, 480));
}

void MainWindow::on_Power_4_clicked()
{
    //ait con power on/off
    packet_set(&user_packet,0,number,4,1,1,0);
    ret=packet_send(devfd,user_packet);
    printf("send ret=%d\n",ret);

    ret=packet_recv(devfd,&recv_packet);
    printf("recv ret=%d\n");

    printf("recv_packet.src=%d\n",recv_packet.src);
    printf("recv_packet.dst=%d\n",recv_packet.dst);
    printf("recv_packet.optype=%d\n",recv_packet.optype);
    printf("recv_packet.operation=%d\n",recv_packet.operation);
    printf("recv_packet.operand[0]=%d\n",recv_packet.operand[0]);
    printf("recv_packet.operand[1]=%d\n",recv_packet.operand[1]);
}

void MainWindow::on_airPowerDown_clicked()
{
    //air wind power down
}

void MainWindow::on_airPowerUp_clicked()
{
    //air wind power up
}

void MainWindow::on_airTempDown_clicked()
{
    //air temp down
}

void MainWindow::on_airTempUp_clicked()
{
    //air temp up
}

void MainWindow::on_mainList_cellClicked(int row, int column)
{
    //main list click  row = 0~254
    get_devlist(devfd,dev_list);
    ui->mainList->setColumnCount(2);

    for(i=0; i<254; i++)
    {
        if(dev_list[i].addr==255)
            break;
        printf("dev_list[%d].addr=%d\n",i,dev_list[i].addr);
        printf("dev_list[%d].devicetype=%d\n",i,dev_list[i].devicetype);

        QString str = "";

        str.toStdString().c_str();


        if( (dev_list[i].devicetype == 1) && (menu ==1))
        {
            if(i==row)
            {
                number = dev_list[i].addr;
            }
        }
        if((dev_list[i].devicetype == 2) && (menu ==2))
        {
            if(i==row)
            {
                number = dev_list[i].addr;
            }

        }
        if((dev_list[i].devicetype == 3) && (menu ==3))
        {
            if(i==row)
            {
                number = dev_list[i].addr;
            }
        }
        if((dev_list[i].devicetype == 4) && (menu ==4))
        {
            if(i==row)
            {
                number = dev_list[i].addr;
            }
        }
    }

}

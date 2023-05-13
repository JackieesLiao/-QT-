
#include "caculatorplus.h"
#include "ui_caculatorplus.h"
double calVal = 0.0;
double memory = 0.0;//记忆值
CaculatorPlus::CaculatorPlus(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CaculatorPlus)
{
    ui->setupUi(this);
    ui->display->setText(QString::number(calVal));
    //定义一个存放数字按钮的数组
    QPushButton*numButtons[10];
    for(int i=0;i<10;i++)
    {
        QString btnName = "Button_"+QString::number(i);
        numButtons[i] = CaculatorPlus::findChild<QPushButton*>(btnName);
        connect(numButtons[i],SIGNAL(released()),this,SLOT(NumPressed()));
    }
    connect(ui->Button_add,SIGNAL(released()),this,SLOT(mathButtonPressed()));
    connect(ui->Button_minus,SIGNAL(released()),this,SLOT(mathButtonPressed()));
    connect(ui->Button_multiply,SIGNAL(released()),this,SLOT(mathButtonPressed()));
    connect(ui->Button_divide,SIGNAL(released()),this,SLOT(mathButtonPressed()));

    connect(ui->Button_equal,SIGNAL(released()),this,SLOT(EqualButtonPressed()));
    connect(ui->Button_pm,SIGNAL(released()),this,SLOT(ChangeNumberSign()));

    connect(ui->Button_sqrt,SIGNAL(released()),this,SLOT(SqrtButtonPressed()));
    connect(ui->Button_divideByx,SIGNAL(released()),this,SLOT(DivideByXButtonPressed()));
    connect(ui->Button_divideBy,SIGNAL(released()),this,SLOT(DivideByNumButtonPressed()));

    connect(ui->Button_back,SIGNAL(released()),this,SLOT(BackSpaceButtonPressed()));
    connect(ui->Button_clear,SIGNAL(released()),this,SLOT(ClearButtonPressed()));
    connect(ui->Button_clearall,SIGNAL(released()),this,SLOT(ClearAllButtonPressed()));

    connect(ui->Button_mc,SIGNAL(released()),this,SLOT(McButtonPressed()));
    connect(ui->Button_mr,SIGNAL(released()),this,SLOT(MrButtonPressed()));
    connect(ui->Button_ms,SIGNAL(released()),this,SLOT(MsButtonPressed()));
    connect(ui->Button_m_plus,SIGNAL(released()),this,SLOT(MplusButtonPressed()));
}

CaculatorPlus::~CaculatorPlus()
{
    delete ui;
}

void CaculatorPlus::NumPressed()
{
    QPushButton* button =(QPushButton*)sender();
    QString btnVal = button->text();
    QString disPlayVal = ui->display->text();
    if(disPlayVal.toDouble()==0||disPlayVal.toDouble()==0.0)
    {
        //显示无数字，则将按钮上的数字显示到显示框里
        ui->display->setText(btnVal);
    }
    else
    {
        //有数字再拼接
        QString newVal = disPlayVal+btnVal;
        ui->display->setText(QString::number(newVal.toDouble(),'g',2));
    }
}

void CaculatorPlus::mathButtonPressed()
{
    addTrigger = false;
    minusTrigger = false;
    multiplyTrigger = false;
    divideTrigger = false;
    pmTrigger = false;
    QString disPlayVal = ui->display->text();
    calVal = disPlayVal.toDouble();//输入的第一个数
    //获取按钮文本
    QPushButton* button =(QPushButton*)sender();
    QString btnVal = button->text();
    ui->display->setText(btnVal);
    //Qt::CaseInsensitive(不区分大小写)
    if(QString::compare(btnVal,"+",Qt::CaseInsensitive)==0)
    {

        addTrigger =true;
    }
    else if(QString::compare(btnVal,"-",Qt::CaseInsensitive)==0)
    {
         minusTrigger = true;
    }
    else if(QString::compare(btnVal,"*",Qt::CaseInsensitive)==0)
    {
         multiplyTrigger = true;
    }
    else if(QString::compare(btnVal,"/",Qt::CaseInsensitive)==0){
         divideTrigger = true;
    }
    ui->display->setText(" ");
}

void CaculatorPlus::EqualButtonPressed()
{
    double answer =0.0;//二元运算解
    QString disPlayVal = ui->display->text();
    double newDisplayVal = disPlayVal.toDouble();//第二个参数
    if(addTrigger||minusTrigger||multiplyTrigger||divideTrigger)
    {
         if(addTrigger)//按下的是加法按钮
         {
//             QString add_text = ui->Button_add->text();
//             ui->display->setText(add_text);
             answer = calVal+newDisplayVal;
             memory =answer;
             ui->display->setText(QString::number(answer,'g',2));
         }
         else if(minusTrigger)
         {
             answer = calVal-newDisplayVal;
             memory =answer;
             ui->display->setText(QString::number(answer,'g',2));
         }
         else if(multiplyTrigger)
         {
             answer = calVal*newDisplayVal;
             memory =answer;
             ui->display->setText(QString::number(answer,'g',2));
         }
         else if(divideTrigger)
         {
             if(newDisplayVal==0)
             {
                 qDebug()<<"出错，除数不能为0";
                 return ;
             }
             answer = calVal/newDisplayVal;
             memory =answer;
             ui->display->setText(QString::number(answer,'g',2));
         }

    }
}

void CaculatorPlus::ChangeNumberSign()
{
    QString displayVal = ui->display->text();
    QRegularExpression reg("[-]?[0-9.]*");
    if(reg.match(displayVal).hasMatch())
    {
         double newDisplayVal = (-1)*(displayVal.toDouble());
         memory =answer;
         ui->display->setText(QString::number(newDisplayVal));
    }

}
//退格操作:使用chop即可
void CaculatorPlus::BackSpaceButtonPressed()
{
    QString displayval = ui->display->text();
    displayval.chop(1);
    ui->display->setText(displayval);
}
//
void CaculatorPlus::ClearButtonPressed()
{
    ui->display->clear();
}

void CaculatorPlus::ClearAllButtonPressed()
{
    ui->display->clear();
}

//开方
void CaculatorPlus::SqrtButtonPressed()
{
    QString displayVal = ui->display->text();
    double dblDisplayVal = displayVal.toDouble();
    double sqrtDbl = sqrt(dblDisplayVal);
    memory =answer;
    ui->display->setText(QString::number(sqrtDbl,'g',2));
}
//1/x
void CaculatorPlus::DivideByXButtonPressed()
{
    QString displayVal = ui->display->text();
    double dblDisplayVal = displayVal.toDouble();
    if(dblDisplayVal==0)
    {
          qDebug()<<"出错，除数不能为0";
          return ;
    }
    double divideDbl = 1/dblDisplayVal;
    memory =answer;
    ui->display->setText(QString::number(divideDbl,'g',2));
}
//x/262
void CaculatorPlus::DivideByNumButtonPressed()
{
    QString displayVal = ui->display->text();
    double dblDisplayVal = displayVal.toDouble();
    double divideDbl = dblDisplayVal/262;
    memory =answer;
    ui->display->setText(QString::number(divideDbl,'g',2));
}

void CaculatorPlus::McButtonPressed()
{
   //记忆清除
    memory = 0;
}

void CaculatorPlus::MrButtonPressed()
{
    ui->display->setText(QString::number(memory));
}

void CaculatorPlus::MsButtonPressed()
{
    memory = ui->display->text().toDouble();
}

void CaculatorPlus::MplusButtonPressed()
{
    QString displayVal = ui->display->text();
    double dblDisplayVal = displayVal.toDouble();
    memory+=dblDisplayVal;
}




#ifndef CACULATORPLUS_H
#define CACULATORPLUS_H
//********计算器*******
//*****作者：廖俊健****
//*****时间：2023/5/14*
//********************
#include<QWidget>
#include<QString>
#include<QPushButton>
#include<math.h>
#include<QDebug>
#include<QMessageBox>
#include<QRegularExpression>
#include<QRegularExpressionMatch>
QT_BEGIN_NAMESPACE
namespace Ui { class CaculatorPlus; }
QT_END_NAMESPACE

class CaculatorPlus : public QWidget

{
    Q_OBJECT

public:
    CaculatorPlus(QWidget *parent = nullptr);
    ~CaculatorPlus();
    //设置按钮的状态
    bool addTrigger;
    bool minusTrigger;
    bool multiplyTrigger;
    bool divideTrigger;
    bool pmTrigger;

//    bool backSpaceTrigger;
//    bool clearTrigger;
//    bool clearAllTrigger;
//    bool sqrtTrigger;
//    bool divideByXTrigger;
private:
    Ui::CaculatorPlus *ui;
    double memory = 0.0;//记忆值
    double answer =0.0;//二元运算解
private slots:
    //所有操作槽函数（slot）
    //二元运算
    void NumPressed();
    void mathButtonPressed();//+ - * /
    void EqualButtonPressed();// =
    void ChangeNumberSign();
    //一元运算
    void BackSpaceButtonPressed();
    void ClearButtonPressed();
    void ClearAllButtonPressed();
    void SqrtButtonPressed();
    void DivideByXButtonPressed();
    void DivideByNumButtonPressed();

    //记忆按钮：MC(记忆清除)、MR(记忆读取)、MS(记忆存储)和M+(记忆相加)按钮
    //设置相应槽函数
    void McButtonPressed();
    void MrButtonPressed();
    void MsButtonPressed();
    void MplusButtonPressed();
};

#endif // CACULATORPLUS_H

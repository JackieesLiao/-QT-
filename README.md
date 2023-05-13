# 基于QT的计算器 
# 一、运行环境：  
# 1:Qt creator 
# 2:Win 10 
# 二、编译环境：MSVC 
# 开发流程： 
## 1：首先创建Qt widgets applicaiton项目，将项目命名为CaculatorPlus。  
## 2：在ui文件中绘制界面，应定制0-9 10个数字按钮以及加减乘除运算符操作按钮，还有等于按钮
## 3：界面设计完毕后到caculatorplus.h中定义各种槽函数声明，例如mathButtonPressed()与EqualButtonPressed()，负责处理加减乘除运算符操作按钮的信号与等于处理逻辑；   
## 4：再到caculatorplus.cpp中设计对应的槽函数，并在CaculatorPlus有参构造函数中使用connect(Sender,SIGNAL(signal),Receiver,SLOT(slot))去将对应按钮的信号发送给对应的槽函数处理；  
### 例如当我按下数字1这个按钮时，Button_one会发出信号，然后NumPressed槽函数中会接受该信号然后进行处理。   
# 本计算器功能  
## 1：加  
## 2：减
## 3：乘  
## 4：除
## 5：sqrt开方
## 6：1/x
## 7:x/262
## 8:取正负
## 9：BackSpace(退格)，Clear(清零)
### 本计算器计算精度为0.01
# 运行效果图
## ![image](https://github.com/JackieesLiao/CaculatorPlus/blob/main/effect.png)

# Serial-Port-Motor-Controller
串口直流电机控制器
================

附：通信协议
===========
一、G0运动电机
-------------
**G0 1MXXX 2MXXX 3MXXX 4MXXX 5MXXX 6MXXX FVYYY\n**  
1M、2M...即表示驱动板上的M1、M2等6个电机插槽，后面的XXX表示运动时间，单位ms，通过正负区分旋转方向，FV表示整体速度。  
YYY速度取值范围：1~100  
XXX运动时间取值范围（32位整型）：-2147483648-2147483647（不可取0）  
当有不需要设置的电机时可直接缺省，但速度参数不可缺省。  
例：  
**G0 1M10000 2M10000 3M10000 4M10000 5M-10000 6M-10000 FV50\n**  
表示1、2、3、4号电机以50%速度正向旋转10000ms（10秒），5、6号电机以50%速度反向旋转10000ms（10秒）  
G0 1M10000 2M10000 FV50\n  
表示1、2号电机以50%速度正向旋转10000ms（10秒），其余电机任务不变  
返回值：OK\n  

二、G203停止移动
-------------
**G203\n**  
注：使全部电机停止转动，当想令某电机单独停止运动可使用G0命令，特定电机时间参数给1即可。  
例：G0 2M1 FV1即2号电机停止运动，后面的速度FV参数无效但是必须存在。  
返回值：OK\n  

三、G201开关LED
-------------
**G201 LEDX\n**  
注：X为1则LED开，0则关闭  
例：G201 LED1\n则打开LED  

四、M200\n
----------
查询是否有电机在运动  
返回值：OK V1\n表示运动中，OK V0\n表示无运转电机  
注：当前后命令有冲突时自动放弃前序命令，以最新接收到的指令为准开始执行  
Linzi GIE Studio 20200225

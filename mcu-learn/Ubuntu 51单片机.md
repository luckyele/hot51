
### ubuntu 16.04 51单片机

在ubuntu系统下，练习51单片机开发，主要使用以下工具，主要步骤包括：

1. 编译器：SDCC

sdcc 编译器可在sourceforce网站[下载](https://sourceforge.net/projects/sdcc/)下载安装最新版本。

也可以在终端运行：`sudo apt install sdcc`，直接安装。

安装完成后，可用命令：`sdcc sourcefile.c`，编译程序，生成.ihx文件。

2. 打包工具: packihx
打包 Intel hex 文件, 生成 .hex 文件。用法：
`packihx sourcefile.ihx > sourcefile.hex`

3. 格式转换工具：hex2bin

.hex也能烧录到芯片，但是hex比bin文件要大一些，这里建议用bin文件烧写。hex转成bin要用到一个Hex2Bin工具。用法：
运行 `hex2bin sourcefile.hex`，随后生成 sourcefile.bin。

该工具可在sourceforge网站[下载](https://sourceforge.net/projects/hex2bin/files/latest/download)。

4. 烧录工具：stcflash
将.bin文件烧录到STC芯片中。用法：
`sudo python stcflash.py sourcefile.bin。`

该工具可在github[下载](https://github.com/laborer/stcflash)，也有网友推荐使用stcgal。

简单整理一下，ubuntu环境51单片机编程的主要过程是：file.c -> file.ihx -> file.hex -> file.bin -> flash to chips.

环境搭建可参见CSDN上的相关[教程](https://blog.csdn.net/qq_21460229/article/details/73457996)

### HOT51单片机接口简介

- LED:接 P0 口
- 点阵:阳极通过 74HC573 接 P0 口,阴极接 P2 口
- 数码管: 段码通过 74HC573 接 P0 口, 位选码通过 74HC138 接 P2.0,P2.1,P2.2
- 1602 液晶:RS 接 P2.5,R/W 接 P2.6,E 接 P2.7,数据口接 P0
- 2864 液晶:RS 接 P2.5,R/2 接 P2.6,E 接 P2.7,数据口接 P0,PSB 接 2.4,RST 接 2.2
- 独立按键:分别接 P3.2,P3.3,P3.4
- 矩阵键盘: 接 P1 口
- 时钟芯片 DS1302:SClK 接 P1.6,RST 接 P1.7,I/O 接 P3.5
- 储存芯片 AT24C02:SClK 接 P1.5,SDA 接 P3.6
- 通讯芯片 MAX232:接 P3.0,P3.1
- USB 转串口芯片 Pl2303:接 P3.0,P3.1(注:这里有跳线帽进行选择)
- 红外解码芯片:接 P3.3
- PS2 接口:连接 P1.6,P1.7
- SD 卡座接口:接 P1.0,P1.1,P1.2,P1.3
- AD/DA 芯片 PCF8591T:接 P1.5,P3.6
- 继电器,蜂鸣器,步进电机,直流电机:最好用 P1 口控制。单片机 IO 控制 UlN2003 芯片去驱动以上器件。

#### LED

八个发光二极管 L1-L8 分别接在单片机的 P0.0-P0.7 接口上。点亮某个发光二极管，需要设置低电平（即置0）。

#### SDCC 编译多个文件

sdcc不支持同时编译多个文件，如要编译main.c, other.c，则需分步编译。其过程如下：
1. sdcc -c other.c
2. sdcc -c main.c
3. sdcc main.rel other.rel
最终生成 main.ihx


sdcc 编译生成多个后缀的文件，其含义分别如下：

这一步将完成编译,汇编和链接的源文件。输出文件如下:
.asm - 程序的汇编文件
.lst - 程序的列表文件
.rst - 被链接器更新的列表文件
.sym - 由链接器生成的符号清单
.rel - 由汇编器生成的对象文件，提供给链接器使用
.map - 被链接器更新的最终存储器映射
.mem - 内存的使用情况摘要
.ihx - 用于生成Intel Hex格式文件模块


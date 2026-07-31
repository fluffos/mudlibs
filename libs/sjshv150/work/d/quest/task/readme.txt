
//类西游记版本适用task系统
//windows系统mudos适用文件

因为很多类西游记系统都希望加上fy的task系统
而fy的task系统是带地层坐标的,所以要改变类xyj
系统的整个地层区域似乎等于要重写全部的,所以
借鉴jhfy的地层task方式(出口搜索路径)改制到
类xyj系统下是个很好的解决办法。

鉴于一些原因，我只提供出了魔神之界系统里的这套
系统大致的全部code和下面的几个路径的提示，别的
需要大家自己整了，以后很细的补丁readme应该少点
好，这样对大家熟悉系统运做原理和结构都有益。

1. /adm/daemons/questd.c
2. /adm/daemona/cron.c
3. /include/task.h
4. /include/globals
#define TASK_D        "/adm/daemons/questd"
#define CRON_D            "/adm/daemons/cron"
5. /cmds/usr/job.c
6. tu.c(我的这个文件是放在金兜洞里面，变制出了
两个dig 金丹砂的地方，两个dig tu的地方，由于对
于网站人数多的玩家得到的几率稍微小了点，所以做
成了autoload方式) 


祝大家新年顺意,少生孩子多种树(snicker),呵呵!!!

歪歪(waiwai) 2001/01/24
email:mszj@21cn.com


星月传奇提供下载
http://www.lywin.com
中国泥巴资源下载第一站
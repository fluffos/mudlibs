
[一、新增功能说明]

这是在jackyboy的topten的基础上经过改进得到的一个topten系统。
主要增加了以下几个功能：
1、克服了原来topten中增加新的排行榜比较难的问题，新增了两个命
   令topen和tclose，用来维护排行榜。topen用来新建一个排行榜，
   tclose用来删除一个排行榜。格式如下：
   topen <排行榜英文名称> <排行榜中文名称> <排序参数>
   	e.g. topen exp 道行高手 combat_exp
   	这个命令新建一个exp排行榜（如果已经存在则将删除原来的
   	排行榜），用来对玩家的"combat_exp"参数进行排序。
   tclose <排行榜英文名称>
   	e.g. tclose exp
   	这个命令删除exp排行榜。
2、增加了tset和tban两个命令。tset用来设置进入一个排行榜所需要
   达到的最小的相应值，tban用来ban掉一些不应出现在排行榜中的id。
   格式如下：
   tset [排行榜英文名称 最小值]
   	e.g. tset exp 12000
   	这个命令执行后，只有combat-exp值超过12000的玩家才能进
   	入exp排行榜。
   	e.g. tset
   	这个命令用来显示当前所有排行榜的最小限值。
   tban <排行榜英文名称> [-u] <玩家id>
   	e.g. tban exp misu
   	则misu将不会再出现在exp排行榜中。
   	e.g. tban exp -u misu
   	取消对misu这个id的ban。如果misu在线，并试图将其加入exp
   	排行榜。
3、topten命令的改进。
   如果topten命令不带参数，将显示目前所有的排行榜。

[二、安装说明]
1.把本目录下的文件解压缩，解压缩后应该放在mudlib的/topten目录下
2.把文件toptend.c移动到/adm/daemons/
3.把文件globals.h里关于topten部分copy到/include/globals.h里
4.把命令文件top.c移动到/cmds/usr,把topten.c移动到/cmds/std/
5.把命令文件tadd.c,tban.c,tset.c和tdel.c移动到/cmds/wiz
6.把命令文件topen.c tclose.c移动到/cmds/arch
7.在logind.c里用户登录的最后那里增加对toptend.c里的topten_checkplayer()函数的调用！
8.重新启动游戏，排行榜就起作用了

[三、问题]
1.只有在玩家login的时候才会对他进行排行
2.没有排除巫师，也就是说巫师也参加了排行
3.rich排行没有计算身上带的钱，仅计算了存款
4.exp排行不能代替比武！
5.对于功夫等级的排行可在get_all_data里面加入相应的语句。  

这些问题都很好解决，你自己去看看吧！

misu@xyz

有问题请mailto: whowillbe@sohu.com
http://202.114.98.14/mud

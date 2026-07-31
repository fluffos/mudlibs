		模拟华附玩家等级自动检测系统 V 0.2

*以下说明均以模拟华附最终测试版mudlib为准*

【最新改进】
    此版本人物升级系统是在根据Ｋittt建议的基础上对原版作较大改进而
成的，首先，用指针改写了原来的等级学分需求代码，避免了大量的重复
判断，同时，易于巫师的改写和重新制定升级学分要求。同时另一改进是
把原来的call_out呼叫检测玩家的check_all()函数改成了用localtime来
呼叫的方法，毕竟这样比较节省系统资源，而且localtime是efun，执行
起来也快。
    这个版本改过的文件包括upgraded.c和scmore.c，hp.c有一点小问
题，也改了一下。

【安装方法】
     本系统核心为upgraded.c，请将其解压至你的MUDlib的
/adm/daemons/目录下，并且，在/include/globals.h中加上：
#define UPGRADE_D	"/adm/daemons/upgraded"
这一句，同时建议在/adm/daemons/logind.c中连接的最后加上：
UPGRADE_D->upgrade(user); 这一句，使每次连入时自动检查能
否升级。并且，请将hp.c和scmore.c 解压至/cmds/usr/目录，假如
你的mudlib不是风云三类型的话，请作适当修改，主要这两个文件就
是增加了等级的显示和升下一等级需要的combat_exp。

【其他说明】
    本系统采用的是25分钟自动检测一次玩家的学分判断能否升级（可
以在upgraded.c文件中修改），所以假如有玩家觉得需要立即升级的
话，请将libiliang.c解压至/d/wiz/npc目录下覆盖源文件即可让玩家通
过“ask li about 升级”来升级。

				阿飞·【糊涂泥巴工作室】
			     版权所有·模拟华附 2000/12/07
//write by lbc(7/8/2001)

// /adm/single/master.c         修改玩家能看见"编译时段错误"的代码,对巫师过滤掉Warning信息,不向
//				log/log中写错误信息了
// /adm/daemons/regid.c         register不用信箱,直接告诉新密码
// /adm/daemons/securityd.c     NPC 靠边站,我叫lbc,嘿嘿
// /adm/etc/welcome             盗版?盗版!盗版......
// /d/city/guangchang.c     	修正bug 
// /d/city/npc/xunbu.c      	去掉wzfeng的超级巡捕代码段
// /include/mudlib.h        	盗版......
// /include/globls.h        	去掉重复定义的宏
// /include/net/config.h        盗版好,盗版妙......
// /cmds/usr/wizlist.c      	修正bug
// /cmds/wiz/setskill.c         来自xkx100,作者 // 9th, April 1997. - KEN.Q.Z.ZHANG
// /cmds/adm/gmap.c           我写的xkx的ftb job 系统地图生成指令 
// /data/securityd.o            tnnd,所有问题因它而起,注意格式就行,费我半天神,tnnd
// /clone/obj/genmap.c          xkx的ftb job系统地图生成器,chu 把queue物件指向他自己的目录了,
//                              要改,要改......
// /log/test                    添加此目录for wzfeng family job system,因为log_file() 好像只
//                              能创建文件,而不能建立目录
// /d/city/npc/maskman.c        将该处的maskmam.c改成maskman.c,文件名都错了

//(附:门派任务的开启方法)
//在一个新的系统中,在/d/wizard/center中,先执行job_setorg_default 生成/data/job_system/menpai.o
//文件,然后就可以使用center里的各种命令了,此命令只需执行一次,look gold word可看到各种命令
//(斧头帮的开启办法)
//将gmap.c cp 到/cmds/arch/ 然后执行,系统会花几分钟自动生成/data/map.o文件,等生成工作结束后
//ftb就ok了,同时这个map.o也解决了emei yun youmin和 wzfeng family job 的问题,也许还解决了其他
//需要调用/clone/obj/mapdb.c 数据库的问题,不得而知.

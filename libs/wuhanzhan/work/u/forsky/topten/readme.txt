topten排行榜 for XYJ

1,把所需文件复制到位
/adm/daemons/toptend.c
/topten/*.*
/cmds/usr/topten.c
2,在/adm/daemons/logind.c中，
把下列代码加在“varargs void enter_world(object ob, object user, int silent){”里边。
[	
//检查是否进入排行榜！add by jackyboy@cctx 1999/3/8
		TOPTEN_D->topten_checkplayer(user);
]
3,在/include/globals.h中加入下列代码
[
//added by JackyBoy @ CCTX for TOPTEN
#define TOPTEN_RICH 	"/topten/rich.txt"
#define TOPTEN_PKER	"/topten/pker.txt"
#define TOPTEN_EXP	"/topten/exp.txt"
#define TOPTEN_SHEN1	"/topten/shen1.txt"
#define TOPTEN_SHEN2	"/topten/shen2.txt"
#define TOPTEN_neili	"/topten/neili.txt"
#define TOPTEN_PER1	"/topten/per1.txt"
#define TOPTEN_PER2	"/topten/per2.txt"
#define TOPTEN_AGE	"/topten/age.txt"
#define RICH_B 		"十大富人"
#define PKER_B 		"十大杀人狂"
#define EXP_B  		"十大道行高手"
#define SHEN1_B 	"十大魔"
#define SHEN2_B 	"十大法力高手"
#define neili_B		"十大内力高手"
#define PER1_B		"十大白马王子"
#define PER2_B		"十大梦中情人"
#define AGE_B		"十大老不死"
#define TOPTEN_D	"/adm/daemons/toptend"
]

梦西游http://home.zjg.jsinfo.net/home/dreamxyj提供


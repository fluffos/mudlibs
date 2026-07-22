
//多少天后清除未上线的未交费用户
#define UNREG_IDLE      90
//是否使用MYSQL数据库及是否存储用户数据到MYSQL库里，不使用数据库则#undef DB_SAVE！
#undef DB_SAVE

//是否存储用户数据到文本文件里，定义了 1 就表示是，如果定义了 0 就表示否！
#define TX_SAVE         1
//是否定时为玩家保存档案
#define AUTO_SAVE       1
// #define NO_QUIT_DROP

//定义游戏的主页地址
#define URL "http://www.mudbuilder.com/"

//定义最多有多少个图标可以使用
#define MAX_ICONS 2159

//对所有物品都允许下线保留
// #define AUTO_LOAD_ALL 1

//客户端要求版本号
#define CURRENT_CLIENT_VERSION 2060

//对存入MYSQL的字符串做转换
#define DB_STR(x)    "'" + replace_string(x, "'", "''") + "'"

#define DM(x) "/adm/daemons/" x
#define TMI(x) (""+x+"")
#define TMA ""
#define TMB ""
#define INFO TMI
#define BASE_MENU "/adm/etc/base_menu.ini"
#define IP_ALLOW "/adm/etc/ip_allow.ini"
#define HEND sprintf("%c",18)

#define PTEXT(x) TMI("ptext "+x)
#define ALERT(x) TMI("alert "+x)
#define MTEXT(x) TMI("ptext "+x)
#define L_ITEM(x) RANK_D->new_short(x)
#define L_ICON(x) TMI("licon "+x)
#define CLEAN0  TMI("lbclear0")
#define ADD0(x) TMI("lbadd0 "+L_ITEM(x)+";")
#define REM0(x) TMI("lbrem0 "+L_ITEM(x)+";")
#define CLEAN1  TMI("lbclear1")
#define ADD1(x) TMI("lbadd1 "+L_ITEM(x)+";")
#define REM1(x) TMI("lbrem1 "+L_ITEM(x)+";")
#define CLEAN2  TMI("lbclear2")
#define ADD2(x) TMI("lbadd2 "+L_ITEM(x)+";")
#define REM2(x) TMI("lbrem2 "+L_ITEM(x)+";")
//这里不能有定义？


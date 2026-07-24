// Created by Aeddy@2003/01/20  NPC总调用
// 任何人增添路径时严格注意不要重复，不要写错
// 并且注明系统类型。特殊ROOM请在最顶部添加
// 继承这个后，房间内注意删除 inherit ROOM 

#include "command.h"
#include "mudlib.h"
inherit NPC;
string day_event(){return NATURE_D->outdoor_room_event();}

#define DROOM                   "/d/room/"
#define DNPC                    "/d/npc/"
#define DOBJ                    "/d/obj/"

//大唐长安
#define CITY_ROOM               "/d/city/"
#define CITY_NPC                "/d/city/npc/"
#define CITY_OBJ                "/d/city/obj/"

//长安以南
#define CAS_ROOM                "/d/changan/"
#define CAS_NPC         "/d/changan/npc/"
#define CAS_OBJ         "/d/changan/obj/"

//长安以东
#define CAE_ROOM                "/d/eastway/"
#define CAE_NPC         "/d/eastway/npc/"
#define CAE_OBJ         "/d/eastway/obj/"

//长安以西
#define CAW_ROOM                "/d/westway/"
#define CAW_NPC         "/d/westway/npc/"
#define CAW_OBJ         "/d/westway/obj/"

//开封
#define KAIFENG         "/d/kaifeng/"
#define KAIFENG_ROOM            "/d/kaifeng/room/"
#define KAIFENG_NPC             "/d/kaifeng/npc/"
#define KAIFENG_OBJ             "/d/kaifeng/obj/"

//江州城(取经)
#define JZC_ROOM                "/d/jz/"
#define JZC_NPC         "/d/jz/npc/"
#define JZC_OBJ         "/d/jz/obj/"

//昆仑月宫(门派)
#define MOON_ROOM               "/d/moon/"
#define MOON_NPC                "/d/moon/npc/"
#define MOON_OBJ                "/d/moon/obj/"

//高老庄(取经)
#define GLZ_ROOM                "/d/gao/"
#define GLZ_NPC         "/d/gao/npc/"
#define GLZ_OBJ         "/d/gao/obj/"

//阎罗地府(门派)(取经)(大闹天宫)
#define DIFU_ROOM               "/d/death/"
#define DIFU_NPC                "/d/death/npc/"
#define DIFU_OBJ                "/d/death/obj/"

//天宫1
#define SKY1_ROOM               "/d/sky/"
#define SKY1_NPC                "/d/sky/npc/"
#define SKY1_OBJ                "/d/sky/obj/"

//天宫2
#define SKY2_ROOM               "/d/dntg/sky/"
#define SKY2_NPC                "/d/dntg/sky/npc/"
#define SKY2_OBJ                "/d/dntg/sky/obj/"

//天宫3
#define DNTG_ROOM               "/d/dntg/yunlou/"
#define DNTG_NPC                "/d/dntg/yunlou/npc/"
#define DNTG_OBJ                "/d/dntg/yunlou/obj/"

//巫师(系统)
#define WIZ_ROOM                "/d/wiz/"
#define WIZ_NPC         "/d/wiz/npc/"
#define WIZ_OBJ         "/d/wiz/obj/"

//巫师/U/Aeddy(系统)
#define WAI_ROOM                "/u/aeddy/"
#define WAI_NPC         "/u/aeddy/npc/"
#define WAI_OBJ         "/u/aeddy/obj/"
#define WAIROOM         "/u/aeddy/room/auroom"

//巫师/U/ALWAYS(系统)
#define AWS_ROOM                "/u/always/"
#define AWS_NPC         "/u/always/npc/"
#define AWS_OBJ         "/u/always/obj/"

//江湖大道 /U/BANGHUI(系统)
#define UBH_ROOM                "/u/banghui/"
#define UBH_NPC         "/u/banghui/npc/"
#define UBH_OBJ         "/u/banghui/obj/"

//毒门大雪山(门派)
#define DXS_ROOM                "/d/xueshan/"
#define DXS_NPC         "/d/xueshan/npc/"
#define DXS_OBJ         "/d/xueshan/obj/"

//东海龙宫(大闹天宫)(门派)
#define SEAE_ROOM               "/d/sea/"
#define SEAE_NPC                "/d/sea/npc/"
#define SEAE_OBJ                "/d/sea/obj/"
 
//西海龙宫(取经)
#define SEAW_ROOM               "/d/qujing/xihai/"
#define SEAW_NPC                "/d/qujing/xihai/npc/"
#define SEAW_OBJ                "/d/qujing/xihai/obj/"

//南海龙宫(尚未建立)
#define SEAS_ROOM               "/d/seas/"
#define SEAS_NPC                "/d/seas/npc/"
#define SEAS_OBJ                "/d/seas/obj/"

//北海龙宫(尚未建立)
#define SEAN_ROOM               "/d/sean/"
#define SEAN_NPC                "/d/sean/npc/"
#define SEAN_OBJ                "/d/sean/obj/"

//灵台方寸山(门派)
#define LTFC_ROOM               "/d/lingtai/"
#define LTFC_NPC                "/d/lingtai/npc/"
#define LTFC_OBJ                "/d/lingtai/obj/"

//梅山
#define MEI_ROOM                "/d/meishan/"
#define MEI_NPC         "/d/meishan/npc/"
#define MEI_OBJ         "/d/meishan/obj/"

//大唐皇宫
#define HGDN_ROOM               "/d/huanggong/"
#define HGDN_NPC                "/d/huanggong/npc/"
#define HGDN_OBJ                "/d/huanggong/obj/"

//明教(战役)
#define MJZY_ROOM               "/d/mingjiao/"
#define MJZY_NPC                "/d/mingjiao/npc/"
#define MJZY_OBJ                "/d/mingjiao/obj/"
 
//南海普陀山(门派)
#define NANHAI_ROOM             "/d/nanhai/"
#define NANHAI_NPC              "/d/nanhai/npc/"
#define NANHAI_OBJ              "/d/nanhai/obj/"

//蓬莱仙岛
#define PENGL_ROOM              "/d/penglai/"
#define PENGL_NPC               "/d/penglai/npc/"
#define PENGL_OBJ               "/d/penglai/obj/"

//剑宗蜀山(门派)
#define SHUS_ROOM               "/d/shushan/"
#define SHUS_NPC                "/d/shushan/npc/"
#define SHUS_OBJ                "/d/shushan/obj/"

//水帘天蓬(门派)
#define TP_ROOM         "/d/tianpeng/"
#define TP_NPC          "/d/tianpeng/npc/"
#define TP_OBJ          "/d/tianpeng/obj/"

//大唐将军府(门派)
#define JJF_ROOM                "/d/jjf/"
#define JJF_NPC         "/d/jjf/npc/"
#define JJF_OBJ         "/d/jjf/obj/"

//盘丝(门派)
#define PSD_ROOM                "/d/pansi/"
#define PSD_NPC         "/d/pansi/npc/"
#define PSD_OBJ         "/d/pansi/obj/"

//西域碧波潭(取经)(门派)
#define BIBO_ROOM               "/d/qujing/bibotan/"
#define BIBO_NPC                "/d/qujing/bibotan/npc/"
#define BIBO_OBJ                "/d/qujing/bibotan/obj/"

//西域天竺国(取经)
#define TZG_ROOM                "/d/qujing/tianzhu/"
#define TZG_NPC         "/d/qujing/tianzhu/npc/"
#define TZG_OBJ         "/d/qujing/tianzhu/obj/"

//五庄观(取经)(门派)
#define WZG_ROOM                "/d/qujing/wuzhuang/"
#define WZG_NPC         "/d/qujing/wuzhuang/npc/"
#define WZG_OBJ         "/d/qujing/wuzhuang/obj/"

//西域火云洞(取经)(门派)
#define HYD_ROOM                "/d/qujing/kusong/"
#define HYD_NPC         "/d/qujing/kusong/npc/"
#define HYD_OBJ         "/d/qujing/kusong/obj/"

//西域盘丝岭(取经)
#define PSL_ROOM                "/d/qujing/pansi/"
#define PSL_NPC         "/d/qujing/pansi/npc/"
#define PSL_OBJ         "/d/qujing/pansi/obj/"

//西域双叉岭(取经)
#define SCL_ROOM                "/d/qujing/shuangcha/"
#define SCL_NPC         "/d/qujing/shuangcha/npc/"
#define SCL_OBJ         "/d/qujing/shuangcha/obj/"

//西域凤仙郡(取经)
#define FXJ_ROOM                "/d/qujing/fengxian/"
#define FXJ_NPC         "/d/qujing/fengxian/npc/"
#define FXJ_OBJ         "/d/qujing/fengxian/obj/"

//西域金兜山(取经)
#define JDS_ROOM                "/d/qujing/jindou/"
#define JDS_NPC         "/d/qujing/jindou/npc/"
#define JDS_OBJ         "/d/qujing/jindou/obj/"

//西域隐雾山(取经)
#define YWS_ROOM                "/d/qujing/yinwu/"
#define YWS_NPC         "/d/qujing/yinwu/npc/"
#define YWS_OBJ         "/d/qujing/yinwu/obj/"

//西域钦法国(取经)
#define QFG_ROOM                "/d/qujing/qinfa/"
#define QFG_NPC         "/d/qujing/qinfa/npc/"
#define QFG_OBJ         "/d/qujing/qinfa/obj/"

//西域祭赛国(取经)
#define JSG_ROOM                "/d/qujing/jisaiguo/"
#define JSG_NPC         "/d/qujing/jisaiguo/npc/"
#define JSG_OBJ         "/d/qujing/jisaiguo/obj/"

//西域金平府(取经)
#define JPF_ROOM                "/d/qujing/jinping/"
#define JPF_NPC         "/d/qujing/jinping/npc/"
#define JPF_OBJ         "/d/qujing/jinping/obj/"

//西域比丘国(取经)
#define BQG_ROOM                "/d/qujing/biqiu/"
#define BQG_NPC         "/d/qujing/biqiu/npc/"
#define BQG_OBJ         "/d/qujing/biqiu/obj/"

//西域玉华县(取经)
#define YHX_ROOM                "/d/qujing/yuhua/"
#define YHX_NPC         "/d/qujing/yuhua/npc/"
#define YHX_OBJ         "/d/qujing/yuhua/obj/"

//西域宝象国(取经)
#define BXG_ROOM                "/d/qujing/baoxiang/"
#define BXG_NPC         "/d/qujing/baoxiang/npc/"
#define BXG_OBJ         "/d/qujing/baoxiang/obj/"

//西域乌鸡国(取经)
#define WJG_ROOM                "/d/qujing/wuji/"
#define WJG_NPC         "/d/qujing/wuji/npc/"
#define WJG_OBJ         "/d/qujing/wuji/obj/"

//西域车迟国(取经)
#define CCG_ROOM                "/d/qujing/chechi/"
#define CCG_NPC         "/d/qujing/chechi/npc/"
#define CCG_OBJ         "/d/qujing/chechi/obj/"

//西域通天河(取经)
#define TTH_ROOM                "/d/qujing/tongtian/"
#define TTH_NPC         "/d/qujing/tongtian/npc/"
#define TTH_OBJ         "/d/qujing/tongtian/obj/"

//西域黑水河(取经)
#define HSH_ROOM                "/d/qujing/heishui/"
#define HSH_NPC         "/d/qujing/heishui/npc/"
#define HSH_OBJ         "/d/qujing/heishui/obj/"

//西域女儿国(取经)
#define NEG_ROOM                "/d/qujing/nuerguo/"
#define NEG_NPC         "/d/qujing/nuerguo/npc/"
#define NEG_OBJ         "/d/qujing/nuerguo/obj/"

//西域朱紫国(取经)
#define ZZG_ROOM                "/d/qujing/zhuzi/"
#define ZZG_NPC         "/d/qujing/zhuzi/npc/"
#define ZZG_OBJ         "/d/qujing/zhuzi/obj/"

//西域青龙山(取经)
#define QLS_ROOM                "/d/qujing/qinglong/"
#define QLS_NPC         "/d/qujing/qinglong/npc/"
#define QLS_OBJ         "/d/qujing/qinglong/obj/"

//轩辕古墓(取经)(门派)
#define GUMU_ROOM               "/d/qujing/xuanyuan/"
#define GUMU_NPC                "/d/qujing/xuanyuan/npc/"
#define GUMU_OBJ                "/d/qujing/xuanyuan/obj/"

//迷雾岛(特殊区域)
#define MIWU                    "/d/west/miwudao/"
#define MIWU_ROOM               "/d/west/miwudao/room/"
#define MIWUU_NPC               "/d/west/miwudao/npc/"
#define MIWU_OBJ                "/d/west/miwudao/obj/"

//金银岛(特殊区域)
#define GOLD_ROOM               "/d/tianpeng/jinyin/"
#define GOLD_NPC                "/d/tianpeng/jinyin/npc/"
#define GOLD_OBJ                "/d/tianpeng/jinyin/obj/"

//天涯海角(特殊区域)
#define TYHJ_ROOM               "/d/tianpeng/tianya/"
#define TYHJ_NPC                "/d/tianpeng/tianya/npc/"
#define TYHJ_OBJ                "/d/tianpeng/tianya/obj/"

//八娇湖(特殊区域)
#define BJH_ROOM                "/d/tianpeng/hu/"
#define BJH_NPC         "/d/tianpeng/hu/npc/"
#define BJH_OBJ         "/d/tianpeng/hu/obj/"

//暗黑城(特殊区域)
#define ANHEI_ROOM              "/d/diablo/"
#define ANHEI_NPC               "/d/diablo/npc/"
#define ANHEI_OBJ               "/d/diablo/obj/"

//荒郊(一般区域)
#define HOME_ROOM               "/d/ourhome/"
#define HOME_NPC                "/d/ourhome/npc/"
#define HOME_OBJ                "/d/ourhome/obj/"

//野羊寨(NPC帮会区域)
#define YYZ_ROOM                "/d/yeyangzhai/"
#define YYZ_NPC         "/d/yeyangzhai/npc/"
#define YYZ_OBJ         "/d/yeyangzhai/obj/"



//北侠名人堂
//whuan
//新蜡像馆,by all@pkuxkx, 2012/12/4
inherit ROOM;
#include <ansi.h>

int block_cmd();
void create()
{
        set("short", HIY"北侠BT蜡像馆"NOR);
                set("long",HIR"\n"
     HIR"这里是北侠的蜡像展厅，所有蜡像都在这一层陈列，\n"
     HIR"你可以根据门派瞻仰这些蜡像。\n"
     
     HIY"下面是各个门派房间的入口(用go进入），高手们的蜡像都在他们的初始门派房间中:\n"
HIW"
shaolin.少林   		wudang.武当   		gaibang.丐帮         
baituo.白驼    		xingxiu.星宿         	huashan.华山
emei.峨眉      		mingjiao.明教         	riyuejiao.日月教       
gumu.古墓      		lingjiu.灵鹫         	quanzhen.全真
tianlong.天龙  		taohua.桃花         	murong.慕容         
chaoting.朝廷  		tiandihui.天地会       	shenlong.神龙
dalun.大轮寺   		xueshan.凌霄雪山     	baixing.无门无派 \n"NOR);

        set("exits", ([
                "shaolin":"/d/wizard/nlx_shaolin",
                "wudang":"/d/wizard/nlx_wudang",
                "gaibang":"/d/wizard/nlx_gaibang",
                "baituo":"/d/wizard/nlx_baituo",
                "xingxiu":"/d/wizard/nlx_xingxiu",
                "huashan":"/d/wizard/nlx_huashan",
                "emei":"/d/wizard/nlx_emei",
                "mingjiao":"/d/wizard/nlx_mingjiao",
                "ruyuejiao":"/d/wizard/nlx_riyuejiao",
                "gumu":"/d/wizard/nlx_gumu",
                "lingjiu":"/d/wizard/nlx_lingjiu",
                "quanzhen":"/d/wizard/nlx_quanzhen",
                "tianlong":"/d/wizard/nlx_tianlong",
                "taohua":"/d/wizard/nlx_taohua",
                "murong":"/d/wizard/nlx_murong",
                "chaoting":"/d/wizard/nlx_chaoting",
                "tiandihui":"/d/wizard/nlx_tiandihui",
                "shenlong":"/d/wizard/nlx_shenlongjiao",
                "dalun":"/d/wizard/nlx_dalun",
                "xueshan":"/d/wizard/nlx_lingxiao",
                "baixing":"/d/wizard/nlx_baixing",
                "down":"/adm/room/lxguan",
        ]));
        
        set("room_location", "/d/city/");
        set("objects", ([
//                __DIR__"laxiang/atoy_npc": 1,
        ]));
        setup();
}
void init()
{   
        if (!wizardp(this_player()))
          add_action("block_cmd","",1);   
}

int block_cmd()
{        
       string verb = query_verb();  
       if (verb=="say") return 0; //allow say     
       if (verb=="chat") return 0;                
       if (verb=="quit") return 0;                                                         
       if (verb=="look") return 0;                
       if (verb=="down") return 0;
       if (verb=="go") return 0;       
/*       if (verb=="01") return 0;
       if (verb=="02") return 0;
       if (verb=="03") return 0;
       if (verb=="04") return 0;
       if (verb=="05") return 0;
       if (verb=="06") return 0;
       if (verb=="07") return 0;
       if (verb=="08") return 0;
       if (verb=="09") return 0;
       if (verb=="10") return 0;
       if (verb=="11") return 0;
       if (verb=="12") return 0;
       if (verb=="13") return 0;
       if (verb=="14") return 0;
       if (verb=="15") return 0;
       if (verb=="16") return 0;
       if (verb=="17") return 0;
       if (verb=="18") return 0;
       if (verb=="19") return 0;
       if (verb=="20") return 0;
       if (verb=="21") return 0;        
       if (verb=="22") return 0;
       if (verb=="23") return 0; */
       return 1;                                  
}

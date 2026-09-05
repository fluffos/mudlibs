//北侠名人堂
//whuan
//旧蜡像馆迁至长安凌烟阁，all@pkuxkx, 2012/12/4

inherit ROOM;
#include <ansi.h>

int block_cmd();
void create()
{
        set("short", HIY"北侠BT纪念馆"NOR);
                set("long",HIR"\n"
     HIR"这里是北侠的画像展厅，陈列着BT玩家画像，\n"
     HIR"这些玩家有的已退出江湖，有的仍旧活跃在北侠。\n"
     HIR"他们述说着北侠的神奇故事\n"     
     HIR"你可以根据门派来瞻仰这些高手。\n"
     
     HIY"下面是各个门派房间的入口，高手们的蜡像都在他们的初始门派房间中:\n"
HIW"
01.少林         02.武当         03.丐帮         
04.白驼         05.星宿         06.华山
07.峨眉         08.明教         09.日月教       
10.古墓         11.灵鹫         12.全真
13.天龙         14.桃花         15.慕容         
16.朝廷         17.天地会       18.神龙
19.大轮寺       20.凌霄雪山     21.大理段家
22.红花会       23.无门无派                \n"NOR);

        set("exits", ([
                "01":"/d/wizard/lx_shaolin",
                "02":"/d/wizard/lx_wudang",
                "03":"/d/wizard/lx_gaibang",
                "04":"/d/wizard/lx_baituo",
                "05":"/d/wizard/lx_xingxiu",
                "06":"/d/wizard/lx_huashan",
                "07":"/d/wizard/lx_emei",
                "08":"/d/wizard/lx_mingjiao",
                "09":"/d/wizard/lx_riyuejiao",
                "10":"/d/wizard/lx_gumu",
                "11":"/d/wizard/lx_lingjiu",
                "12":"/d/wizard/lx_quanzhen",
                "13":"/d/wizard/lx_tianlong",
                "14":"/d/wizard/lx_taohua",
                "15":"/d/wizard/lx_murong",
                "16":"/d/wizard/lx_chaoting",
                "17":"/d/wizard/lx_tiandihui",
                "18":"/d/wizard/lx_shenlongjiao",
                "19":"/d/wizard/lx_dalun",
                "20":"/d/wizard/lx_lingxiao",
                "23":"/d/wizard/lx_baixing",
                "out":"/d/changan/lingyange",
        ]));
        
        set("objects", ([
                __DIR__"laxiang/atoy_npc": 1,
        ]));
        set("room_location", "/d/changan/");
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
       if (verb=="out") return 0;
       if (verb=="01") return 0;
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
       if (verb=="23") return 0;                
       return 1;                                  
}

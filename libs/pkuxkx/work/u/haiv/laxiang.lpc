//北侠名人堂
//whuan

inherit ROOM;
#include <ansi.h>

int block_cmd();
void create()
{
        set("short", HIY"北侠BT蜡像馆"NOR);
                set("long",HIR"\n"
           HIR"这里是北侠的蜡像馆，超过100M的BT都在这里有一座蜡像，以供后人瞻仰。\n"
     HIR"这里记载着北侠的荣誉，这里记载着北侠的悲哀，多少人景仰这些高手们，同时，\n"
     HIR"多少人又痛恨着他们，因为他们的BT，因为他们几乎无法超越。\n"
     
     HIY"下面是各个门派房间的入口，高手们的蜡像都在他们的初始门派房间中:\n"
HIW"
01.少林         02.武当         03.丐帮         04.白驼         05.星宿         06.华山\n
07.峨眉         08.明教         09.日月教       10.古墓         11.灵鹫         12.全真\n
13.天龙         14.桃花         15.慕容         16.朝廷         17.天地会       18.神龙\n
19.大轮寺       20.凌霄雪山     21.无门无派\n"NOR);

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
                "21":"/d/wizard/lx_baixing",
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
       if (verb=="go") return 0; 
       if (verb=="out") return 0;
       return 1;                                  
}                                                 


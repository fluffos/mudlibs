//北侠名人堂——华山
// by hubo
inherit ROOM;
#include <ansi.h>
int block_cmd();
void create()
{
        set("short", HIY"华山派BT纪念馆"NOR);
        set("long", HIW@LONG
这是华山派的纪念馆，记载着华山派的传奇：
    提 剑 跨 骑 挥 鬼 雨
    华 山 白 骨 鸟 惊 飞
    尘 世 如 潮 人 如 水
    只 盼 独 孤 九 剑 回
LONG
NOR);
        set("exits", ([
                "out" :"/d/wizard/laxiang",
        ]));
        set("objects", ([
                __DIR__"laxiang/bugbug_npc": 1,
                __DIR__"laxiang/facehua_npc": 1,
                __DIR__"laxiang/chonger_npc": 1,
                	__DIR__"laxiang/xiaoxiaoxue_npc": 1,
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
       return 1;                                  
}             

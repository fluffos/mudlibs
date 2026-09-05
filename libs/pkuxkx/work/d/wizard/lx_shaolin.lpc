//北侠名人堂——少林
// by hubo

inherit ROOM;
#include <ansi.h>

int block_cmd();
void create()
{
        set("short", HIY"少林派BT纪念馆"NOR);
        set("long", HIC@LONG
这是少林派的纪念馆，记载着少林派的传奇：

    丈室客问禅      师云不可言
    
    神会祖来意      随处得心安
    
    如来家业重      有我来荷担
    
    少林闻天下      是拳更是禅

LONG
NOR);
        set("exits", ([
                "out" :"/d/wizard/laxiang",
        ]));
        set("objects", ([
                __DIR__"laxiang/piggest_npc": 1,
                __DIR__"laxiang/lastone_npc": 1,
                __DIR__"laxiang/highway_npc": 1,
                __DIR__"laxiang/atoz_npc": 1,
                __DIR__"laxiang/wellcomee_npc": 1,
                __DIR__"laxiang/sxh_npc": 1,
                __DIR__"laxiang/tianyue_npc": 1,
                __DIR__"laxiang/luohh_npc": 1,
                __DIR__"laxiang/harley_npc": 1,
		__DIR__"laxiang/larfy_npc": 1,
              
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


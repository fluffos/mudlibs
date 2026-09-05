//北侠名人堂——白驼山
// by hubo

inherit ROOM;
#include <ansi.h>

int block_cmd();
void create()
{
        set("short", HIY"白驼山BT纪念馆"NOR);
        set("long", HIW@LONG
这是白驼山的纪念馆，记载着白驼山的传奇：

    歹   毒   狠   心   肠
    
    欧   阳   白   驼   庄
    
    一   卷   错   经   文
    
    百   年   对   迷   茫

LONG
NOR);
        set("exits", ([
                "out" :"/d/wizard/laxiang",
        ]));
        set("objects", ([
                __DIR__"laxiang/cpcer_npc": 1,
                __DIR__"laxiang/asnake_npc": 1,
                __DIR__"laxiang/liushuii_npc": 1,
                	
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


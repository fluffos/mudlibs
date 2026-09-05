//北侠名人堂——神龙教 
// by hubo

inherit ROOM;
#include <ansi.h>

int block_cmd();
void create()
{
        set("short", HIY"神龙教BT纪念馆"NOR);
        set("long", HIC@LONG
这是神龙教的纪念馆，记载着神龙教的传奇：

    神      龙      教      主 
    
    仙      福      永      享 
    
    寿      与      天      齐

LONG
NOR);
        set("exits", ([
                "out" :"/d/wizard/laxiang",
        ]));
        set("objects", ([
                __DIR__"laxiang/organic_npc": 1,
                __DIR__"laxiang/jlau_npc": 1,
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


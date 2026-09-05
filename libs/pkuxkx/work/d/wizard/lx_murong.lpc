//北侠名人堂——姑苏慕容
// by hubo

inherit ROOM;
#include <ansi.h>

int block_cmd();
void create()
{
        set("short", HIY"姑苏慕容BT纪念馆"NOR);
        set("long", HIW@LONG
这是姑苏慕容的纪念馆，记载着姑苏慕容的传奇：

    姑     武     以     还   
    
    苏     学     彼     施   
    
    慕     精     之     彼   
    
    容     深     道     身   

LONG
NOR);
        set("exits", ([
                "out" :"/d/wizard/laxiang",
        ]));
       set("objects", ([
               __DIR__"laxiang/hbao_npc": 1,
               __DIR__"laxiang/opcer_npc": 1,
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


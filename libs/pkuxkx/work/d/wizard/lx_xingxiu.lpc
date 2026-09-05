//北侠名人堂——星宿
// by hubo

inherit ROOM;
#include <ansi.h>

int block_cmd();
void create()
{
        set("short", HIY"星宿派BT纪念馆"NOR);
        set("long", HIW@LONG
这是星宿派的纪念馆，记载着星宿派的传奇：

    星     德     威     古
    
    宿     配     震     今   
    
    门     天     当     无   
    
    人     地     世     比   

LONG
NOR);
        set("exits", ([
                "out" :"/d/wizard/laxiang",
        ]));
        set("objects", ([
            __DIR__"laxiang/meat_npc": 1,
            __DIR__"laxiang/swnt_npc": 1,	
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


//北侠名人堂——日月神教
// by hubo

inherit ROOM;
#include <ansi.h>

int block_cmd();
void create()
{
        set("short", HIY"日月神教BT纪念馆"NOR);
        set("long", HIW@LONG
这是日月神教的纪念馆，记载着日月神教的传奇：

    文           泽           千            一
    
    成           被           秋            统

    武           苍           万            江
    
    德           生           代            湖
    
LONG
NOR);
        set("exits", ([
                "out" :"/d/wizard/laxiang",
        ]));
        set("objects", ([
                __DIR__"laxiang/enni_npc": 1,
                __DIR__"laxiang/eastrain_npc": 1,
                __DIR__"laxiang/hubo_npc": 1, 
                __DIR__"laxiang/dzlc_npc": 1,	      
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


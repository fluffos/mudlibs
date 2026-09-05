//北侠名人堂——灵鹫宫
// by hubo

inherit ROOM;
#include <ansi.h>

int block_cmd();
void create()
{
        set("short", HIY"灵鹫宫BT纪念馆"NOR);
        set("long", HIM@LONG
这是灵鹫宫的纪念馆，记载着灵鹫宫的传奇：

    灵鹫飘渺山    光耀白玉盘
   
    八荒六合功    冰符生死寒
    
　　无涯逍遥派    本为一脉连

　　同相皆虚妄    唯情度万千 

LONG
NOR);
        set("exits", ([
                "out" :"/d/wizard/laxiang",
        ]));
        set("objects", ([
               __DIR__"laxiang/xumz_npc": 1,
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


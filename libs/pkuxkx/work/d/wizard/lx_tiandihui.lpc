//北侠名人堂——天地会
// by hubo

inherit ROOM;
#include <ansi.h>

int block_cmd();
void create()
{
        set("short", HIY"天地会BT纪念馆"NOR);
        set("long", HIC@LONG
这是天地会的纪念馆，记载着天地会的传奇：

    地 震 高 冈， 一 脉 溪 水 千 古 秀
    
    门 朝 大 海， 三 合 河 水 万 年 流

LONG
NOR);
        set("exits", ([
                "out" :"/d/wizard/laxiang",
        ]));
        set("objects", ([
                __DIR__"laxiang/changer_npc": 1,
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


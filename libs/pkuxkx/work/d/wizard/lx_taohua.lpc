//北侠名人堂——桃花岛
// by hubo

inherit ROOM;
#include <ansi.h>

int block_cmd();
void create()
{
        set("short", HIY"桃花岛BT纪念馆"NOR);
        set("long", HIM@LONG
这是桃花岛的纪念馆，记载着桃花岛的传奇：

    桃 花 影 落 飞 神 剑
    
    碧 海 潮 生 按 玉 箫

LONG
NOR);
        set("exits", ([
                "out" :"/d/wizard/laxiang",
        ]));
     set("objects", ([
             __DIR__"laxiang/mister_npc": 1,
             __DIR__"laxiang/fcukla_npc": 1,
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


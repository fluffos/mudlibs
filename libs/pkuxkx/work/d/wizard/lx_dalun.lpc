//北侠名人堂——大轮寺
// by hubo

inherit ROOM;
#include <ansi.h>

int block_cmd();
void create()
{
        set("short", HIY"大轮寺BT纪念馆"NOR);
        set("long", HIW@LONG
这是大轮寺的纪念馆，记载着大轮寺的传奇：

    茫 茫 雪 山， 奋 起 十 三 龙 象
    
    巍 巍 古 寺， 降 伏 天 人 五 衰
    
LONG
NOR);
        set("exits", ([
                "out" :"/d/wizard/laxiang",
        ]));
      set("objects", ([
              __DIR__"laxiang/matador_npc": 1,
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


//北侠名人堂——峨眉派
// by hubo

inherit ROOM;
#include <ansi.h>

int block_cmd();
void create()
{
        set("short", HIY"峨眉派BT纪念馆"NOR);
        set("long", HIW@LONG
这是峨眉派的纪念馆，记载着峨眉派的传奇：

    绝艺惊人侠士风    千年击技古今同
   
    堪开玄理树新帜    悟透禅机弃旧功
    
　　假身玉女虚是实    真谛峨眉有非空

　　诸家应复昔时而    妙处良然在个中 

LONG
NOR);
        set("exits", ([
                "out" :"/d/wizard/laxiang",
        ]));
      set("objects", ([
              __DIR__"laxiang/jessy_npc": 1,
              __DIR__"laxiang/windy_npc": 1,
              __DIR__"laxiang/littlexi_npc": 1,
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


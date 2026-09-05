//北侠名人堂——百姓
// by hubo

inherit ROOM;
#include <ansi.h>

int block_cmd();
void create()
{
        set("short", HIY"无门无派BT纪念馆"NOR);
        set("long", HIY@LONG
这是无门无派的普通人经验超过100m的纪念馆，我们可以想象在北侠
竞争如此激烈的环境下，无门无派的玩家能达到如此的高度是多么的艰辛
我们应该向他们致敬。正所谓：

                  天外有天，    人外有人
                  
                  岁月蹉跎,     还我本色  
LONG
NOR);
        set("exits", ([
                "out" :"/d/wizard/laxiang",
        ]));
      set("objects", ([
              __DIR__"laxiang/cjbd_npc": 1,
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


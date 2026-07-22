inherit ROOM;
#include <ansi.h> 
void create()
{
        set("short", "龙潭入口");
        set("long", HIG @LONG  
前方就是龙潭，进去前请三思。如果到此止步，还来得及。如要
回头，请键入back。在西面，有一个向下的通道，看来似乎相当深。
LONG);

        set("exits", ([ 
              "north" : "/d/tulong/dragoncave", 
              "westdown" : "/d/tulong/spirit7", 
           ]));
  set("objects", ([
		 "/quest/tulong/npc/zhanglao" : 1,
      ]));
set("no_fly",1); 
        setup();
}

void init()
{
        add_action("do_back", "back");
}


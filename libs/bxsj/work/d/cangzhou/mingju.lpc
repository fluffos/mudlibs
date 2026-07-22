#include <room.h>
inherit ROOM;

void create()
{
      set("short", "民居");
      set("long", @LONG
这里是一间静静的小屋，从竹藤扎就的窗外可以看到外面的大街。东首是
一张床，床头小柜上放了几只简单的竹编小筐。正对面有一张红木方桌。
LONG );
      set("exits", ([
          "east" : __DIR__"beijie3",
        ]));
        
      set("objects", ([
               __DIR__"npc/pingsi" : 1,
      ]));

      setup();
}

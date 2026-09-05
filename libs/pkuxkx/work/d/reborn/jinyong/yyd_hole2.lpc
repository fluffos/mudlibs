inherit ROOM;
#include <room.h>
#include <ansi.h>

void create ()
{
    set ("short", "废墟");
    set ("long", @LONG
一片废墟，黑乎乎的什么都看不清楚。
LONG);

        set("exits", ([ /* sizeof() == 3 */
        "north" : __DIR__"yyd_yuanyang",
        "south" : __DIR__"yyd_hole",
 ]));
    set("objects", 
      ([ //sizeof() == 1
      ]));
    setup();
}

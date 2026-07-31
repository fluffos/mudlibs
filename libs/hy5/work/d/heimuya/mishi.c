// room: laozhai.c
// Jay 4/8/96
#include <room.h>
#include <ansi.h>

inherit ROOM;
int do_break(string arg);

void create()
{
    set("short", "向阳老宅");
    set("long", @LONG
这里是福威镖局总镖头林震南在福建的旧居。室内的家具横七竖八地
倒在地上。房间的一角结着一张蜘蛛网，屋里到处是尘土，显然是已经很
久没有人住了。房间的尽头有一扇门(men)，但已被坍塌的砖瓦挡住了。
LONG
    );

    set("exits", ([
        "south" : __DIR__"xijie",
    ]));

    set("item_desc", ([
  "men" : "这扇门已被挡住无法通行，除非你打破(break)它。\n",
    ]) );
    setup();
}


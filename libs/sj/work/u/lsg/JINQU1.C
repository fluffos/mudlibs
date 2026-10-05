#include <room.h>

inherit ROOM;

void create()
{
        set("short", "禁区");
        set("long", @LONG
   这里就是圣殿的禁区,看你走了过来,周围武士都警戒的看着
你,仍至有几位已经把手放在了剑柄上.显然此地不能久留,还是
先走为妙.
                 [1m[1;31m前面危险   想好再走[2;37;0m


LONG );
        set("exits", ([
                "south" : __DIR__"jinqu2",
"southeast" : __DIR__"jinqu",
        ]));
        set("objects", ([

        ]));
        set("outdoors", "shendian");
        setup();
}

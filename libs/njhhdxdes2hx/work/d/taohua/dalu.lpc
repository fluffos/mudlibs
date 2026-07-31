#include <ansi.h>
inherit ROOM;

void create()
{
         set("short", BLK "牛家村街道" NOR);
        set("long", @LONG
你走在一条冷清的街道上，北边有一个很破旧的茅草房。
好象常年没人居住了。兵火之后，原来的家家户户，都
变成了断墙残瓦的破败之地。
LONG
        );
        set("outdoors", "city");

        set("exits", ([
              
    "south" :"/d/quanzhou/jiaxing",
       "north" : __DIR__"xiaowu",
        ]));

        setup();
        replace_program(ROOM);
}

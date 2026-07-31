// shanlu4.c By River 98/09

inherit ROOM;
#include <ansi.h>
void create()
{
    set("short", YEL"山路"NOR);
    set("long", @LONG
此处是一条崎岖山路，你睁大了眼四下眺望，惟见云生谷底，雾迷峰巅，
空山寂寂，微闻鸟语，天地茫茫，就只你一人而已。
LONG
        );

    set("exits", ([ 
		"east"  : __DIR__"shanlu5",
                "west"  : __DIR__"shanding",                     
    ]));

    set("outdoors", "绝情谷");
    setup();
    replace_program(ROOM);
}

// shanlu5.c By River 98/09

inherit ROOM;
#include <ansi.h>
void create()
{
    set("short", YEL"山路"NOR);
    set("long", @LONG
此处是一条崎岖山路，你睁大了眼四下眺望，惟见云生谷底，雾迷峰巅，
空山寂寂，微闻鸟语，天地茫茫，就只你一人而已。眼前出现两条岔路，你一
时竟不知向那一条走才是。
LONG
        );

    set("exits", ([ 
		"northup"  : __DIR__"shanlu6",
  		"eastup"  : __DIR__"shanlu9",
                "west" : __DIR__"shanlu4",  	
    ]));

    set("outdoors", "绝情谷");
    setup();
    replace_program(ROOM);
}

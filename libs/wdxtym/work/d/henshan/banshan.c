// Room: /d/henshan/banshan.c
#include <room.h>
inherit ROOM;
void create()
{
	set("short", "半山亭");
	set("long", @LONG
终于到了半山亭。这里离到祝融峰无论高程还是行程，均恰好是一
半之径，路边小亭显然已极古久，但仍为过往客旅遮风避雨。
LONG);
	set("exits", ([ /* sizeof() == 4 */
	   "southdown"  : __DIR__"shanlu4",
	   "northup"    : __DIR__"shanlu5",
	]));
	set("no_clean_up", 0);
	set("outdoors", "henshan");
	setup();
}


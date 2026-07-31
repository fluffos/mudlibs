// Room: /d/henshan/yushulou.c
#include <room.h>
inherit ROOM;
void create()
{
	set("short", "御书楼");
	set("long", @LONG
御书楼为南岳庙历代藏书之处，天子御赐，贤达乐捐，这里早已洋
洋大观。
LONG);
	set("exits", ([ /* sizeof() == 4 */
	   "south"  : __DIR__"jiayingmen",
	   "north"  : __DIR__"dadian",
	]));
	set("no_clean_up", 0);
	setup();
}


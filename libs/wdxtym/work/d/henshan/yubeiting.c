// Room: /d/henshan/yubeiting.c
#include <room.h>
inherit ROOM;
void create()
{
	set("short", "御碑亭");
	set("long", @LONG
御碑为重修南岳庙大石碑，高数丈，石碑竖立在重三万八千斤的大
石龟上，龟身雕刻细腻，极为生动。
LONG);
	set("exits", ([ /* sizeof() == 4 */
	   "south"  : __DIR__"zhengchuan",
	   "north"  : __DIR__"jiayingmen",
	]));
	set("no_clean_up", 0);
	setup();
}


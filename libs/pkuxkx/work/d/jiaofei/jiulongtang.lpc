//Create by whuan@pkuxkx
//铁掌帮
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "龙王塘");
	set("long", @LONG
顺着山路左转右拐，一个小水塘出现在你眼前。传说在一个风雨交加的晚上，
有人看到有龙从此塘飞升，龙王塘也由此得名。
    这里有几条小路朝不同方向延伸，看来是通往不同山峰的。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 5 */
		  "east" : __DIR__"xshanlu1",
		  "southdown" : __DIR__"jshanlu",
		  "north" : __DIR__"zshanlu1",
		  "northwest" : __DIR__"sshanlu1",
		  "northeast" : __DIR__"wshanlu1",
		]));
 	set("outdoors", "tiezhang");
    setup();
    replace_program(ROOM);
}

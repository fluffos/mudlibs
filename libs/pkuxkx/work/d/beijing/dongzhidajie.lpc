// Room: /d/beijing/dongzhidajie.c
#include <ansi.h>
inherit ROOM;

void fix_exits_for_night(int is_night)
{
    if (is_night) {
	set("exits", ([ /* sizeof() == 2 */
	  "west" : __DIR__"guloudajie_e2",
	  "south" : __DIR__"chaoyangdajie",
	  "north" : __DIR__"shiweiying",
	]));
    } else {
	set("exits", ([ /* sizeof() == 2 */
	  "west" : __DIR__"guloudajie_e2",
	  "east" : __DIR__"dongzhimen",
	  "south" : __DIR__"chaoyangdajie",
	  "north" : __DIR__"shiweiying",
	]));
    }
}

void create()
{
	set("short", HIC"东直门大街"NOR);
	set("long",
CYN"这是繁华热闹的东直门大街，大街街面宽阔，车水马龙，
川流不息，人群熙熙攘攘，来来往往。街边上耍枪买艺、百货
小吃，应有尽有，帝都风貌可见一斑。\n"NOR
	);
	fix_exits_for_night(0);
	set("outdoors", "beijing");

	set("outdoors", "beijing");

	setup();
}
string GATE_OUT_DIR1 = "east";
string GATE_OUT_DIR2 = "";
#include "gate.h"

// Room: /d/beijing/youandajie.c
#include <ansi.h>
inherit ROOM;

void fix_exits_for_night(int is_night);

void create()
{
	set("short", HIC"右安门大街"NOR);
	set("long",
CYN"这是繁华热闹的右安门大街，大街街面宽阔，车水马龙，川流不息，人群熙
熙攘攘，来来往往。街边上耍枪买艺、百货小吃，应有尽有，帝都风貌可见一斑。\n"NOR
	);
        set("outdoors", "beijing");
	fix_exits_for_night(0);

	setup();
}

void fix_exits_for_night(int is_night)
{
    object me = this_object();
    if (is_night) {
	me->set("exits", ([ /* sizeof() == 3 */
	      "east" : __DIR__"fenshen",
	      "north" : __DIR__"caishikou",
	]));
    }else{
	me->set("exits", ([ /* sizeof() == 4 */
	      "east" : __DIR__"fenshen",
	      "north" : __DIR__"caishikou",
	      "south" : __DIR__"youanmen",
	]));
    }
}
string GATE_OUT_DIR1 = "south";
string GATE_OUT_DIR2 = "";
#include "gate.h"

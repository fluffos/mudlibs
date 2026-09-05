#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIM"炼丹房"NOR);
	set("long",
HIC"你尚未进入房间已经离远闻到一股浓郁的药味，浓的、清香的，
还杂夹着你无法分辨的古怪味道。房间很大，到处摆满了冒着白气
的药罐，十几个小太监在来回走动，忙碌地看火、煎药。\n"NOR
	);

	set("exits", ([
//		"south" : __DIR__"zhidianjian",
//		"north" : __DIR__"shangbaojian",
		"east" : __DIR__"shangshanjian",
	]));
  set("objects", ([
               __DIR__"npc/xiaoguizi" : 1,
        ]));
	setup();
	replace_program(ROOM);
}

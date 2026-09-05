#include <ansi.h>
inherit ROOM;
void create()
{

	set("short", HIC"杨柳胡同"NOR);
	set("long",
CYN"你走在巷道上，感到似乎有些不妙。北边仍是空荡荡的小道,见不
到几个行人。东边是一家面馆。北边是西长安大道。一股阴风吹来，你
禁不住打了个寒颤。\n"NOR
	);

        set("outdoors", "city2");



	set("exits", ([

		"east" : __DIR__"guancaidian",

//		"north" : __DIR__"alley2",

		"south" : __DIR__"yangliu",

	]));
	setup();
	replace_program(ROOM);

}




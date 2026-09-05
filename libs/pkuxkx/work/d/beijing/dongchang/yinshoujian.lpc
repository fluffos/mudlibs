#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIM"印绶监"NOR);
	set("long",
HIC"这里是掌管印鉴、信符诸事的印绶监，本应该是十二监中的重要官署，
但近年御马监的实力日益膨胀，风头上已经完全压过印绶监，甚至自行出纳
令符火牌，侵夺了印绶监的职权。\n"NOR
	);

	set("exits", ([
		"south" : __DIR__"shangyijian",
		"north" : __DIR__"sishejian",
//		"east" : __DIR__"citang",
	]));

	setup();
	replace_program(ROOM);
}

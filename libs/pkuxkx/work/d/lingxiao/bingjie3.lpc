// File		: bingjie3.c
// Created By	: iszt@pkuxkx, 2006-08-15

#include <ansi.h>;

inherit ROOM;

void create()
{
	set("short", HIW"冰雪路口"NOR);
	set("long", @LONG
东西向的大街名叫雪街，同冰街一样，它也没有雪。雪街比冰街热闹的多，
凌霄城内的普通弟子大多住在那里。街上若干弟子正在巡逻，若干弟子正在当街
练剑，还有行色匆匆赶来赶去的，每人都忙忙碌碌。
LONG);
	
	set("outdoors", "凌霄城");
	set("no_sleep_room", 1);
	set("exits", ([
		"west" : __DIR__"xuejie3",
		"east" : __DIR__"xuejie4",
		"south" : __DIR__"bingjie2",
		"north" : __DIR__"bingjie4",
	]));
	set("objects", ([
		__DIR__"npc/dizixl" : 1,
                __DIR__"npc/kewanjun" : 1,
		__DIR__"npc/dizifr" : 1,
	]));

	setup();
	replace_program(ROOM);
}


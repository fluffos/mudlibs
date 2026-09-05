// File		: xuedi5.c
// Created By	: iszt@pkuxkx, 2006-08-15

#include <ansi.h>
#include "snow.h"

inherit ROOM;

void create()
{
	set("short", HIW"雪地"NOR);
	set("long", @LONG
这里是一片雪地，厚厚的积雪足以没膝，可见山上终年如此，而凌霄城处于
如此高寒之地，即便有独门的御寒之物，门下弟子也需要扎实的内功根基。路旁
是一条深达百丈的深谷，倘若失足，只怕就要粉身碎骨。
LONG);

	set("outdoors", "凌霄城");

	set("item_desc", ([
		"snow": (: snow :),
	]));

	set("objects", ([
		__DIR__"npc/wolf" : 1,
	]));

	set("exits", ([
		"north" : __DIR__"bridgee",
		"southdown" : __DIR__"xuepo4",
	]));

	setup();
}

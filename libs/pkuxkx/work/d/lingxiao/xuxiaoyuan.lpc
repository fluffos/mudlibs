// File		: xuenorth2.c
// Created By	: iszt@pkuxkx, 2006-09-04

#include <ansi.h>;

inherit ROOM;

void create()
{
	set("short", HIG"小院"NOR);
	set("long", @LONG
小院之中，翠云草贴地平铺，一碧无隙，看上去就如绿毯茵茵，春意盎
然。据说是徐元文见到好友熊赐履院中碧草，大为心折，才煞费苦心，在这
凌霄城造了一景。里边就是徐先生的书房了。
LONG);
	
	set("outdoors", "凌霄城");
	set("exits", ([
		"northeast" : __DIR__"xushufang",
		"south" : __DIR__"xuenorth2",
	]));

	setup();
	replace_program(ROOM);
}


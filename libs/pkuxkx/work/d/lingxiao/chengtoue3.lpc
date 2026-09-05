// File		: chengtoue3.c
// Created By	: iszt@pkuxkx, 2006-08-15

#include <ansi.h>;

inherit ROOM;

void create()
{
	set("short", WHT"城头"NOR);
	set("long", @LONG
这里便是凌霄城的城墙了。到了此处，城墙似乎也没有继续修筑的必要了。
只有几名雪山弟子，还在来回走动，防止外敌入侵。
LONG);
	
	set("outdoors", "凌霄城");
	set("no_sleep_room", 1);
	set("exits", ([
		"southwest" : __DIR__"chengtoue2",
	]));
	set("objects", ([
		__DIR__"npc/dizixl" : 1,
	]));

	setup();
	replace_program(ROOM);
}


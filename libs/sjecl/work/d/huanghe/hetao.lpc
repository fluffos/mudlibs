// by xiaoyao

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "河套");
	set("long", @LONG
常言到“黄河九害，富了一套”。河套地区灌溉系统发达，土地肥沃，是
种庄稼的好地方。
LONG );
	set("exits", ([
		"northwest" : __DIR__"huanghe_1",
		"south"      : __DIR__"weifen",
	]));

	set("objects",([
		NPC_D("tiao-fu") : 1,
	]));

	set("outdoors", "黄河");
	setup();
}

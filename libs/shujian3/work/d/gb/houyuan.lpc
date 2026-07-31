// Room : houyuan.c 后院
// Lklv 2001.5.27
// 2001.9.26 update

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "后院");
	set("long", @LONG
这是土地庙的后院，四周是高高低低的黄土墙，院中间有一口大锅，锅里
好象正煮着什么东西。不远处有几个中年乞丐，围坐在一个身材高大的老乞丐
周围。在高谈阔论着什么。声音很洪亮。
LONG
	);
	set("outdoors","苏州");
	set("valid_startroom", 1);

	set("exits", ([
		"south" : __DIR__"pomiao",
	]));

	set("objects", ([
		CLASS_D("gaibang") + "/h7g" : 1,
	]));
	create_door("south", "竹门", "north", DOOR_CLOSED);
	setup();
}
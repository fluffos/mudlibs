// Room: /d/emei/fushouanxxs.c

inherit ROOM;
#include <room.h>
void create()
{
	set("short", "休息室");
	set("long", @LONG
这是福寿庵接待峨嵋女侠们的休息室，峨嵋女弟子回山之前通常在此借宿
一宿，好备足体力上山。房内摆有一张长桌，靠墙设有几张木床。
LONG
	);
	set("exits", ([
		"southdown" : __DIR__"fushouanzt",
	]));
	set("sleep_room", 1);
	set("no_fight",1);
	create_door("southdown", "小门", "northup", DOOR_CLOSED);
	setup();
}

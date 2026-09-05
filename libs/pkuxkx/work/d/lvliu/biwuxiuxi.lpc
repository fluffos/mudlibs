#include <ansi.h>
#include <room.h>
#include "nodie.h"
inherit ROOM;
void create()
{
	set("short", "比武场休息室");
	set("long",	"这是比武场旁边的一个小房间，用来给参加比武场挑战的武林人士暂作休息之用。
地上简单地摆着几个坐垫，靠墙的位置是一整排大通铺，躺着几个在比武挑战中受了
伤被抬下来的武士。\n"NOR);
	set("no_fight", 1);
	set("no_perform", 1);
	set("no_steal", 1);
	set("sleep_room", 1);
	set("exits", ([
		"west" : __DIR__"biwulouxia",
	]));
	create_door("west","木门","east",DOOR_CLOSED);
	setup();
}

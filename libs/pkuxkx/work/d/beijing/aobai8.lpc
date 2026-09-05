// Room: /city2/aobai8.c
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
	set("short", HIY"牢房"NOR);
	set("long",
HIC"	这是一个昏暗的房间，窗户都被钉死。地上放着皮鞭、木棍等刑具，显然
这是鳌拜私立公堂，审讯人犯的所在。一个书生被捆在墙上，鲜血淋漓，遍体鳞伤。\n"NOR
	);
	set("objects", ([
		__DIR__"npc/zhuangyu" : 1,
	]));
	set("exits", ([
		"north" : __DIR__"aobai4",
	]));
	setup();
}
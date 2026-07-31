// By River@SJ

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "古浪");
	set("long", @LONG
古浪城建于西周，本名鬼武，后整修于汉，更名古浪。古浪是西北地区的
毛皮集散地，当初的紫羊羔皮袄，一出于张家口，另一出处就是古浪了，过了
古浪再往东四十里，跨过纪水河即到兰州。
LONG );
	set("exits", ([
		"east"      : __DIR__"yaocaidian",
                "southeast"      : __DIR__"xjqiao",
		"northwest" : __DIR__"dacaigou",
	]));
	set("objects", ([
		"/d/taishan/npc/dao-ke1" : 1,
	]));

	set("outdoors", "兰州");
	setup();
}

// liangong3.c 小练功室

inherit ROOM;

void create()
{
	set("short", "小练功室");
	set("long", @LONG
这里是一个小小的石室，地方狭窄，却摆了几个木人，不知道是
练功房摆不下还是因为别的什么原因。地上有些杂乱，看来不是经常
打扫。
LONG
	);

	set("exits", ([
		"north" : __DIR__"liangong2",
	]));
	set("objects", ([
		"/clone/npc/mu-ren" : 3,
	]));
	set("for_family", "古墓派");
	setup();
}

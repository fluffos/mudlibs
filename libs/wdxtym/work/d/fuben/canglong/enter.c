// Room: banfang.c

inherit ROOM;

void create()
{
	set("short", "卧龙堡入口");
	set("long", @LONG
这是一处古城堡，四处冷冷清清，空气中充满血腥的味道，你越走越害怕……。
LONG
	);
	set("exits", ([
		"north" : __DIR__"room1",
	]));
	setup();
}

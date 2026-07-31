// Room: /city/xsmidao4.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "雪山寺密道");
	set("long", @LONG
这是雪山寺的僧人为了方便往来中原，特地设置的密道，以便神
不知鬼不觉的往来西域。
LONG
	);

	set("exits", ([
		"southeast" : __DIR__"xsmidao3",
		"west" : __DIR__"xsmidao5",
	]));

	setup();
}

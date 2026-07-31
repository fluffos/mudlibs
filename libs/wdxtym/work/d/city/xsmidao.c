// Room: /city/xsmidao.c
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
		"up"   : __DIR__"dangpu",
		"west" : __DIR__"xsmidao1",
	]));

	setup();
}

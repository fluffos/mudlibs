// Room: tianjing.c
// Lklv Modify 2001.9.21

inherit ROOM;
void create()
{
	set("short", "天井");
	set("long", @LONG
你走进一个小天井，青石板铺路，路周围种着四季花草，两边有月亮门通
向别的院落，纵是一个小小的天井，布置的也是精巧细致，别具匠心。
LONG
	);
	set("objects", ([
                __DIR__"npc/jiading": 1,
		__DIR__"npc/wenfangshi": 1,
	]));
	set("outdoors", "襄阳");
	set("exits", ([
		"north": __DIR__"shidetang",
		"south": __DIR__"houhuayuan",
		"west":__DIR__"lianwu",
		"east":__DIR__"guifang",
	]) );

	set("incity",1);
	setup();
}

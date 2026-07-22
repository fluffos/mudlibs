// Room: /dali/nanjie3.c
// bbb 1997/06/11
// update cool 98.2.21
// Modify By River 98/12/
inherit ROOM;

void create()
{
	set("short", "太和南街");
	set("long", @LONG
你走在太和南街上，这里十分安静，大理百姓臣民走到这里，无不放慢了
脚步，以敬仰的目光向北看去，北边过青石街就是大理皇宫了。东西两边都是
大理南大街，南面就是大理的南门了。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"east" : __DIR__"nanjie4",
		"west" : __DIR__"nanjie2",
		"south" : __DIR__"nanmen",
		"north" : __DIR__"qsjie2",
	]));

	set("outdoors", "大理");
	setup();
}

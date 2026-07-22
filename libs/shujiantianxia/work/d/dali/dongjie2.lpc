// Room: /dali/dongjie2.c
// bbb 1997/06/11
// Modify By River 98/12
inherit ROOM;

void create()
{
	set("short", "东大街");
	set("long", @LONG
你走在东大街上，街道上花草和树木郁郁葱葱，花香阵阵，风中夹着一丝
丝从北边药房里传来的中药味，街道平滑如洗。透过树木，你可以看到西边是
一个豆腐坊，再往南就是太和东街了。
LONG
	);
	set("outdoors", "大理");
	set("exits", ([
		"east" : __DIR__"yaopu",
		"west" : __DIR__"doufufang",
		"north" : __DIR__"dongjie1",
		"south" : __DIR__"dongjie3",
	]));
	set("incity", 1);
	setup();
}

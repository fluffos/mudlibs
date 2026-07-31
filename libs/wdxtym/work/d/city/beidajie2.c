// Room: /city/beidajie2.c

inherit ROOM;

void create()
{
	set("short", "北大街");
	set("long", @LONG
这是一条宽阔的青石街道。北边是北城门通向城外，
南边显得很繁忙。东边是一座两层的楼阁，正是“醉仙楼”。西边就
是天下学武之人所共同敬仰的武庙了。
LONG );
	set("outdoors", "city");
	set("exits", ([
		"east"  : __DIR__"zuixianlou",
		"south" : __DIR__"beidajie1",
		"west"  : __DIR__"wumiao",
		"north" : __DIR__"beimen",
	]));
	set("objects", ([
	]));
	setup();
}


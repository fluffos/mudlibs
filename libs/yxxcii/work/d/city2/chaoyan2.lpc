//Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "朝阳路");
	set("long", @LONG
这是一条青石路，一路走来见不到几个行人。东南边是东门。朝阳门
在西北边。路面如此冷清，让人十分奇怪。
LONG
);
	set("outdoors", "city2");
	set("exits", ([
		"northwest" : __DIR__"chaoyang",
		"southeast" : __DIR__"dongmen",
	]));

	setup();
	replace_program(ROOM);
}



// Room: /d/fuzhou/yamen.c
// Date: may 12. 1998 Java

inherit ROOM;

void create()
{
	set("short", "西大街");
	set("long", @LONG
这里是一条宽阔的青石板街道，向东西两头延伸。西大街是衙门所在，行人稀少，静悄悄地很是冷清。
LONG );
	set("exits", ([
		"east" : __DIR__"nandajie",
		"west"    : __DIR__"xidajie",
	]));
	set("objects", ([
	
	]));
	set("no_fight", 1);
	set("outdoors", "by");
	setup();
}

int valid_leave(object me, string dir)
{
	object ob;

	if (objectp(ob = present("ge shiha", environment(me))) &&
	    dir != "east" && living(ob))
		return notify_fail("戈什哈喝道：“施大人已去校场阅兵，你来何干？”\n");

	return ::valid_leave(me, dir);
}

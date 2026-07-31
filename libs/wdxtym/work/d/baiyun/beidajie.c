// Room: /d/fuzhou/beidajie.c
// may. 12 1998 Java

inherit ROOM;

void create()
{
	set("short", "北大街");
	set("long", @LONG
这是一条宽阔的青石街道，向南北两头延伸。北边是北城门通向城外。
LONG );
	set("exits", ([
		"south"   : __DIR__"dongjiekou",
		"northup" : __DIR__"pingshan",
	]));
	set("outdoors", "by");
	setup();
}


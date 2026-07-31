// Room: /d/fuzhou/dongxiaojie.c
// may. 12 1998 Java

inherit ROOM;

void create()
{
	set("short", "东小街");
	set("long", @LONG
街道两侧，榕木参天。福州盛夏苦热，广植榕树以纳凉
爽，别名“榕城”。东面就出城了，西面是城中心。
LONG );
	set("exits", ([
		"east"    : __DIR__"dongmen",
		"west"    : __DIR__"dongdajie",
	]));
	set("outdoors", "fuzhou");
	setup();
}


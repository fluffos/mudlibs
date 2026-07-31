// Room: /d/fuzhou/xidajie.c
// may. 12 1998 Java

inherit ROOM;

void create()
{
	set("short", "西大街");
	set("long", @LONG
你走在西大街上，感到这里的街面要比别处的干净,整洁。
LONG );

	set("exits", ([
		//"southup" : __DIR__"wushan",
		//"north"   : __DIR__"biaoju",
		"east"    : __DIR__"yamen",
		"west"    : __DIR__"ximendajie",
	]));
set("outdoors", "by");
	setup();
}


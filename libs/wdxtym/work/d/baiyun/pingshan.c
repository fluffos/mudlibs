// Room: /d/fuzhou/pingshan.c
// Date: May 12, 98  Java

inherit ROOM;

void create()
{
	set("short", "白云城门");
	set("long", @LONG
悠悠天地几惊心，诺大空城唯白云。在走就是白云城了。
LONG );
	set("exits", ([
		"southdown" : __DIR__"beidajie",
	]));
	set("outdoors", "by");
	setup();
}


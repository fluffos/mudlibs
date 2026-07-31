// Room: /d/fuzhou/dongxiaojie.c
// may. 12 1998 Java

inherit ROOM;

void create()
{
	set("short", "城墙");
	set("long", @LONG
这里是白云城的城墙。青砖上血锈迹剑痕，述说着它的故事。
LONG );
	set("exits", ([
		//"east"    : __DIR__"dongmen",
		"west"    : __DIR__"dongdajie",
	]));
	set("objects", ([
			"/kungfu/class/baiyun/baixue" : 1,
	]));
set("outdoors", "by");
	setup();
}


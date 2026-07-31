// Room: /d/henshan/hsroad6.c 林间大道
// Modified by Java on Feb.14.1998
inherit ROOM;

void create()
{
	set("short", "林间大道");
	set("long", @LONG
这里是一条林间大道，在树丛中蜿蜒。这里是湖南境内。北边是
湖北。路边有可供路人休息的小茶亭。
LONG );
	set("outdoors", "hengyang");

	set("exits", ([
		"east"   : __DIR__"chating",
		"north"  : __DIR__"hsroad7",
		"south"  : __DIR__"hsroad5",
	]));

	setup();
}

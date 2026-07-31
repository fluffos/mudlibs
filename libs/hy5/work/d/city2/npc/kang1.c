// Room: /city2/kang1.c

inherit ROOM;

void create()
{
	set("short", "康府大门");
	set("long", @LONG
一座富丽堂皇的大宅院出现在你的眼前，两头高大的石狮子
镇住了大门两侧。门外有带刀侍卫把守，戒备森严。门上挂着两
个灯笼，赫然写着大大的“康”字。
LONG
	);

	set("exits", ([
		"south" : __DIR__"wangfu3",
		"north" : __DIR__"kang2",
	]));


	setup();
}


// Write By Yanyang@SJ 2001.9.20
// Room: /d/changan/northjie1.c

inherit ROOM;

void create()
{
        set("short", "北大街");
        set("long", @LONG
这是一条宽阔的青石街道，向南北两头延伸。北边是北城门通向城外。南
边则是城中心的钟楼。东边是一座两层的楼阁，门额上悬挂着一方横匾，“聚
豪酒楼”四字擦得闪闪发亮。西边是一家与酒楼同名的客栈。
LONG
        );
	set("outdoors", "长安");

	set("exits", ([
		"east"   : __DIR__"juhao",
		"south"  : __DIR__"zhonglou",
		"west"   : __DIR__"kezhan",
		"north"  : __DIR__"northjie2",
	]));
	set("objects", ([
		CLASS_D("gaibang/qigai") : 1,
	]));
	set("incity",1);
	setup();
}
// Write By Yanyang@SJ 2001.9.30
// Room: /d/changan/northjie2.c

inherit ROOM;

void create()
{
	set("short", "北大街");
	set("long", @LONG
这是一条宽阔的青石街道，向南北两头延伸。北边是北城门通向城外。南
边则是城中心的钟楼。东边是一家织布坊，里面不时传来织布机织布的声音。
西边是一家裁缝铺，顾客有进有出，生意不错。
LONG
	);
	set("outdoors", "长安");
	
	set("objects",([
		"/d/zhiye/npc/yangcan-popo" : 1,
	]));

	set("exits", ([
		"east"   : "/d/zhiye/zhibufang1",
		"west"   : "/d/zhiye/caifengpu1",
		"south"  : __DIR__"northjie1",
		"north"  : __DIR__"northjie3",
	]));

	set("incity",1);
	setup();
}

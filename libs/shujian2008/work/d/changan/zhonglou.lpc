// Write By Yanyang@SJ 2001.9.20
// Room: /d/changan/zhonglou.c

inherit ROOM;

void create()
{
	set("short", "钟楼");
	set("long", @LONG
这里是长安城东、西、南、北四条大街交会处的钟楼。钟楼整体为木质结
构，上有深绿色琉璃瓦覆盖，重檐复屋，楼内贴金绘彩，画栋雕梁。楼上大圆
金顶，表面贴有金箔，金光闪闪，灿烂夺目。由于地处中心，街上人来人往，
一片繁荣的景象。
LONG
	);
	set("outdoors", "长安");

	set("exits", ([
		"east"  : __DIR__"eastjie1",
		"south" : __DIR__"southjie1",
		"west"  : __DIR__"westjie1",
		"north" : __DIR__"northjie1",
		"northwest": __DIR__"gulou",
	]));

	set("objects", ([
		NPC_D("huolang") : 1,
	]));

	set("incity",1);
	setup();
}

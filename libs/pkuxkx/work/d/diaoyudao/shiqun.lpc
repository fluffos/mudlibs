// Room: /d/diaoyudao/shiqun.c 礁石群
// hongdou 98.09.20

inherit ROOM;

void create()
{
	set("short", "礁石群");
	set("long", @LONG
这里是岛里延伸出来的一小片礁石群，经过长期的海水拍打，礁石已
经被冲刷得失去了棱角。岩缝中藏着许多小螃蟹、海虫、贝壳等。东北不
远有一块大礁石，临近海边。
LONG
	);

	set("exits", ([
                "northeast" : __DIR__"jiaoshi",
		"southwest" : __DIR__"haitan5",
	]));

	set("outdoors", "diaoyudao");
	setup();
	replace_program(ROOM);
}


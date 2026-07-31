// Room: /d/jingzhou/lydao1.c
// congw 980830

inherit ROOM;

void create()
{
	set("short", "林荫道");
	set("long", @LONG
这是一条安静的林荫道，地上铺着奇奇怪怪五颜六色的石子，向南北两头延伸。北边是
热闹的西大街，南边远处有几个孩童在玩耍。西面是高大的荆州城墙。
LONG
	);
        set("outdoors", "jingzhou");

	set("exits", ([
		"north" : __DIR__"xidajie2",
		"south" : __DIR__"lydao2",
	]));

	setup();
	replace_program(ROOM);
}


// Room: /d/city/nandajie2.c

inherit ROOM;

void create()
{
	set("short", "南大街");
	set("long", @LONG
你走在一条繁华的街道上，向南北两头延伸。南边是几座园林，北边通往
市中心，西边是一家顾客众多的茶馆，三教九流人士都在那里谈天说地。东边
则是官府特设的扬州盐局。
LONG
	);
	set("outdoors", "扬州");

	set("exits", ([
		"east" : __DIR__"yanju",
		"south" : __DIR__"nandajie1",
		"west" : __DIR__"chaguan",
		"north" : __DIR__"nandajie3",
	]));

	set("objects", ([
		CLASS_D("shaolin") + "/tuoboseng" : 1,
	]));
	set("incity",1);
	setup();
}


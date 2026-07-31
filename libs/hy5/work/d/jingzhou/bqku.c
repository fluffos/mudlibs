// Room: /jingzhou/bqku.c
// congw 980830 

inherit ROOM;

void create()
{
	set("short", "兵器库");
	set("long", @LONG
这里就是荆州兵器库了，兵器架（jia)上放满了各式的刀枪剑等。。
LONG
	);

	set("exits", ([
		"east" : __DIR__"bqkumen",
	]));

	setup();
	replace_program(ROOM);
}


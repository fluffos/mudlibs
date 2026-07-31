// Room: /open/dt/mujiangpu.c

inherit ROOM;

void create()
{
	set("short", "木匠铺");
	set("long", @LONG
这是一家不大的木匠铺，三四个木匠正在满头大汉地忙着，
看他们手头活儿的形状，好像他们正在打一只木柜。屋里到处是
刨花，一股清新的木头香气充斥着这里，屋角零乱地散落着一些
木头块，一个人正在把一块木板锯成一根根木条。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"huayanlu4",
]));

	setup();
	replace_program(ROOM);
}

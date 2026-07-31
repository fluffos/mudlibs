// Room: /u/jpei/thd/jiangpan2.c

inherit ROOM;

void create()
{
	set("short", "江畔");
	set("long", @LONG
一条大江横亘在面前，江水浩浩，日日夜夜无穷无休地奔向大海。
LONG
	);
	set("no_clean_up", 0);
	set("outdoors","nio");

	set("exits", ([
		"northwest": __DIR__"jiangpan1.c",
		"east": __DIR__"jiangpan3.c",
	]) );

	setup();
	replace_program(ROOM);
}


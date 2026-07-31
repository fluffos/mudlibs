// Room: /u/jpei/thd/jiangpan1.c

inherit ROOM;

void create()
{
	set("short", "江畔");
	set("long", @LONG
一条大江横亘在面前，江水浩浩，日日夜夜无穷无休地奔向大海。这里有
一排乌柏树，叶子似火烧般红。两棵大松树下正围着一堆村民，聚精会神地听
着一个瘦削的老者说话。
LONG
	);
	set("no_clean_up", 0);
	set("outdoors","nio");

	set("exits", ([
		"north": __DIR__"njroad5.c",
		"southeast": __DIR__"jiangpan2.c",
	]) );

	setup();
	replace_program(ROOM);
}


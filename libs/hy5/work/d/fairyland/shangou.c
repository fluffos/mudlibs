// Room: /u/qingyun/jyzj/shangou.c
// Written by qingyun
// Updated by jpei

inherit ROOM;

void create()
{
	set("short", "山沟");
	set("long", @LONG
山壁之下的一条小山沟，这里绿草丛生，有许多雪鸡出没于其中。这里因
为背阴，生着许多无名的小草，看来可以入药。
LONG	);
	set("exits", ([
		"westup" : __DIR__"shanbi",
	]));
	set("objects",([
		__DIR__"npc/xueji" : 2,
		__DIR__"obj/yaocao" : 3,
	]));
	set("outdoors", "kunlun");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

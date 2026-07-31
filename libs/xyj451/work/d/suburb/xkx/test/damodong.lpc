// Room: /d/shaolin/damodong.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "废井");
	set("long", @LONG
这口井废置已久，落页败草，堆集腐烂，都化成了软泥。
LONG
	);

	set("exits", ([
		"out" : "/d/suburb/xkx/wizard/wizard_room",
	]));

	set("objects",([
		"/d/suburb/xkx/shaolin/obj/book-bamboo" : 1,
	]));

	setup();
}

void init()
{
	object me = this_player();

	if ((int)me->query_temp("bamboo/count") == 14 
	&&  (int)me->query_skill("dodge", 1) >= 30 
	&&  (int)me->query_skill("dodge", 1) <= 100 
	&&  present("bamboo", me) )
	{
		me->receive_damage("gin", 20);
		me->improve_skill("dodge", me->query("int"));
	}

}


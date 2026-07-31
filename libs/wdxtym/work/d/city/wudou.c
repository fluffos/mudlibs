#include <room.h>

inherit ROOM;
void create()
{
	set("short", "武斗场");
	set("long", "武林豪杰混战切磋的地方，这里没有规则，没有死亡惩罚，你可以尽情发挥！" );
	set("exits", ([
		"south":__DIR__"ximenroad",
	]));
	set("no_fight",1);
	set("action_list", ([
		"进入擂台":"wudou",
	]));
	set("objects", ([
	]));
	setup();
}

void init()
{
	add_action("wudou","wudou");
}

int wudou()
{
	object me = this_player();

	me->set_temp("backup/killer", me->query_killer());
	me->set_temp("backup/want", me->query_want());
	me->set_temp("in_pkd", 1);
	me->set("backup/condition", me->query_condition());
	me->clear_condition();
	me->move("/d/city/leitai2");
	return 1;
}

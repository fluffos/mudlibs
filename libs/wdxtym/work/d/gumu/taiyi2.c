// taiyi2.c
#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "太乙池");
	set("long", @LONG
你身在湖水里，只觉得湖水冰凉透骨。但见四周高峰环列，池面
碧波荡漾，山光水影，风景贻人。这里原来是太乙池的东岸，太累的
话，你可以爬(climb) 上岸。远远望去，西边的山峰之间似乎有一个
大洞。想不想游(swim)过去看？
LONG
	);
	set("item_desc", ([
		"【岸边】" : "这里离东岸不远，随时可以爬上去。\n"
		ZJOBACTS2"爬上岸:climb up\n",
		"【远山】" : "远处山峰之间似乎有个大洞，从没有人游过去过，却不知为什么仍有人时常在此游来游去，莫非是在练什么功夫？\n"
		ZJOBACTS2"游过去:swim\n",
	]) );
	set("outdoors", "gumu");
	setup();
}

void init()
{
	add_action("do_climb", "climb");
	add_action("do_swim", "swim");
}

int do_climb(string arg)
{
	object me = this_player(); 
	int c_exp;
	c_exp = me->query("combat_exp");
	if( !arg || arg != "up")
	{
		write("那个方向没法爬。\n");
		return 1;
	}

	message_vision("$N在太乙池中往岸上爬了上去。\n", me);
	me->move("/d/gumu/taiyi1");
	message_vision("$N从太乙池中爬了上去。\n", me);
	return 1;
}

int do_swim()
{
	int c_skill;
	object me = this_player();

	c_skill = me->query_skill("jinyan-gong", 1);

	if (me->query("qi") < 40)
		return notify_fail("你现在体力不支，没有力气游泳。\n");

	me->receive_damage("qi", 20 + random(20));
	message_vision("$N在太乙池中划了划水，用力游了起来。\n", me);
	if (c_skill < 1)
		return 1;

	if (me->can_improve_skill("jinyan-gong") && c_skill < 51)
		me->improve_skill("jinyan-gong",1 + me->query_skill("jinyan-gong", 1) / 15);
	return 1;
}

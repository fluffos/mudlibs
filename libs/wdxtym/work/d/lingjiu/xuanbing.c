//ROOM xuanbing.c

inherit ROOM;

int exercise_improve();
	
void create()
{
	set("short","玄冰室");
	set("long", @LONG
这是修练内功的地方。 屋子正中有一块千年玄冰(ice)，冰上冒出丝
丝寒气， 屋里因此寒气逼人，你不由得打了一个寒颤。
LONG );
	set("exits", ([
		"east" : __DIR__"changl13",
	]));

	set("item_desc", ([
	    "【玄冰】" : "这是一块采自天山之巅的千年玄冰，奇寒无比。\n",
	]));

	set("exercise_improve", (: exercise_improve :));

	setup();
}

int exercise_improve()
{
	object me;

	me = this_player();
	if (me->query_skill("bahuang-gong", 1) >= 10)
	{
		if (random(5) == 0)
			tell_object(me, "你运用八荒六合惟我独尊功抵御寒气，缓缓行功。\n");
		return me->query_skill("force") / 10;
	}

	tell_object(me, "你冻的牙齿直打颤，丹田内息也是一阵阵的混乱。\n");
	return -20;
}

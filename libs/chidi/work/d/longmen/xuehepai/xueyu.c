//xueyu。c  by baby

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "血狱");
	set("long", @LONG
这里是血河派的血狱。建筑外形象个涵洞，左右两堵墙，墙上镂有不
少名家书法、传世画卷，不少弟子正在琢磨这些书法和画卷。此处乃血河
后堂，气氛格外诡秘，闲杂人等还是速速离去，不可久留。
LONG);	
	set("valid_startroom",1);
	set("exits",([
		"east" : __DIR__"xueku",
		"west" : __DIR__"youmingge",
	]));
/*
	set("item_desc", ([
                "shufa" : "这是一些很平常的唐诗宋词，乃瘦金字体。不少弟子在吟颂(yin)。\n",
                "hua" : "这是一幅幅临摹名家的字画。不少弟子在看(kan)。\n",
	]));
*/
        set("area", "龙门");
	setup();
            replace_program(ROOM);
}/*

void init()
{
	add_action("do_look","kan");
	add_action("do_du","yin");
}

int do_look(string arg)
{
	object me;
	int cost;

	me = this_player();
	cost = 10 + ( 20 - (int)me->query_int() ) / 2;

        if ( cost < 1) cost = 0;

        if ( me->is_busy() )
                return notify_fail("你现在正忙着呢。\n");

	if ( arg == "hua")
	{
		if( (int)me->query_skill("literate", 1) > 50 )
notify_fail("你对着画卷仔细揣摩了一会儿，发现从中已经学不到什么了。\n");

		if ( (int)me->query("jingli") > cost && (int)me->query("potential") >= 1 )
		{
                        tell_object(me, "你专心地研读墙上的画卷，不时还伸出手指临摹一番。\n");
			me->improve_skill("literate", random( (int)me->query_skill("literate", 1) / 2 ) + 10 );
			me->receive_damage("jingli", cost );
			me->add("potential", -1 );
		}
		else
		{
			if ( (int)me->query("jingli") <= cost )
				write("你现在过于疲倦，无法专心下来研读新知。\n");

			if ( (int)me->query("potential") <= 0 )
                                write("你看着画卷反复琢磨，竟没有一丝心得。\n");
		}
		return 1;
	}
	else
		return 0;
}

int do_du(string arg)
{
	object me;
	int cost;

	me = this_player();
	cost = 10 + ( 30 - (int)me->query_int() ) / 2;

        if ( cost < 1) cost = 0;

        if ( me->is_busy() )
                return notify_fail("你现在正忙着呢。\n");

        if ( arg == "shufa")
	{
		if( (int)me->query_skill("literate", 1) < 51 )
                        return notify_fail("你琢磨了半天书法，发现竟什么也看不懂。\n");

		if( (int)me->query_skill("literate", 1) > 101 )
                        return notify_fail("你研读了一会，发现没有什么可学的了。\n");

		if ( (int)me->query("jingli") > cost && (int)me->query("potential") >= 1 )
		{
                        tell_object(me, "你专心地揣摩墙上的书法，读到忘情时竟读出了声。\n");
			me->improve_skill("literate", random( (int)me->query_skill("literate", 1) / 2 ) + 20 );
			me->receive_damage("jingli", cost );
			me->add("potential", -1 );

		}
		else
		{
			if ( (int)me->query("jingli") <= cost )
				write("你现在过于疲倦，无法专心下来研读新知。\n");

			if ( (int)me->query("potential") <= 0 )
                                write("你看着诗词书法反复默读，竟没有一丝心得。\n");
		}
		return 1;
	}
	else
		return 0;
}
*/

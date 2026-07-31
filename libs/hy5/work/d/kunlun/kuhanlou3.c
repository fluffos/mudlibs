// kuhanlou3.c
// Date: cck 6/6/97

#include <ansi.h>
#include <room.h>

int do_out(string arg);

inherit ROOM;

void create()
{
	set("short", "苦寒楼三层");
	set("long", @LONG
很快就到了苦寒楼顶层。这里可以看到山门以及北边的诸多昆仑山峰，四
周的杉林随风摇摆，发出“哗哗哗”的声音。山风夹着隐隐寒气，远处的景色
单调而苍凉，你心里顿时生出一种莫名寂寞的感觉。房间里的布置十分简单。
往外看，有个很大的红木窗台(out)。
LONG
	);

	set("exits", ([
		"down" : __DIR__"kuhanlou2",
	]));

	set("item_desc", ([
			"out" : "你突然有了一种想跳出去的欲望，怎么也克制不住。\n",
]));

	setup();
}

void init()
{
	object me = this_player();

if (((int)me->query_temp("count")==2)
	&&  (int)me->query_skill("dodge", 1) >= 30
	&&  (int)me->query_skill("dodge", 1) <= 101)
	{
		me->receive_damage("jing", 30);
		me->improve_skill("dodge", me->query("int"));
	}

                me->start_busy(random(3));

	add_action("do_out", "out");
}

int do_out(string arg)
{
	object me;
	int i, ging_cost, qi_cost;

	me = this_player();
	i = (int)me->query_skill("dodge") + random(200);
	ging_cost = 600 / (int)me->query("int");
	qi_cost = 500 / (int)me->query("int");
	if(((int)me->query("jing") < ging_cost) || ((int)me->query("qi") < qi_cost))
		i = 0;

	message_vision("$N爬上窗台，一个纵身，跳了下去。\n", me);
	me->move(__DIR__"houyuan");
	message_vision("只听『砰』地一声$N从楼顶跳了下来。\n", me);
	me->set_temp("last_damage_from", "从楼上跳下来摔");
	
	if ( i < 60)
		me->die();
	else if( i < 120)
		me->unconcious();
	else {
		message_vision("$N已稳稳地站在地上。\n", me);
		if( i > 250
		    && me->query_skill("dodge", 1) < 120 )
			me->improve_skill("dodge", 2*(int)me->query_skill("dodge", 1));
		me->receive_damage("jing", ging_cost );
		me->receive_damage("qi", qi_cost );
	}

	return 1;
}

//by 秦始皇 qsh ednpc tools.
// yixiantian.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","一线天");
	set("long","这里是一线天，管理员尚未设定本地详细描述。");
	set("exits", ([
		"east" : __DIR__"shidong1",
	]));
	set("item_desc", ([
		"石壁" : "这是一整块巨石雕成的石壁，上面刻了蝌蚪文。\n"
		ZJOBACTS2"研读:study1 table\n",	
		]));
	set("objects", ([
	]));
	setup();
}

void init()
{
	add_action("do_study", "study1");
}

int do_study(string arg)
{
	object me;
	string msg;

	me = this_player();

	if (arg != "table")
		return notify_fail("你要读什么？\n");
		
	if ((me->query("potential") - me->query("learned_points")) < 10)
		return notify_fail("你目前的潜能不足，无法从石壁上感悟到更多内容。\n");
		
	if (me->query_skill("literate"))
		return notify_fail("你觉得上面写的很有道理。\n");

	if (me->query_temp("stone_learned"))
		return notify_fail("你不是已经在研读了吗？还是脚踏实地练功，不要去投机取巧。\n");

	if (me->is_busy()) {
		call_out("do_lian3", 3, me);
		return notify_fail("你正忙碌中。\n");
	}

	if (me->query("jing") < 95)
	{
		write("你现在过于疲倦，等待恢复中...\n");
                tell_object(me,ZJFORCECMD("use huxin dan"));
	        call_out("do_lian3", 10, me);
		return 1;
	}

	me->receive_damage("jing", 90);
	msg = "你正专心研读石壁上的古怪蝌蚪文。\n";


		if ((int)me->query_skill("taixuan-gong", 1) < 180 && me->can_improve_skill("taixuan-gong"))
		{
			me->add("learned_points", 10);
	        me->improve_skill("taixuan-gong", 10 + random(me->query("int")*8));
			msg += "你看了一回儿，似乎对太玄功有点心得。\n";
			me->set_temp("stone_learned", 1);
		}

	if (! me->query_temp("stone_learned"))
		msg += "你对着石壁琢磨了一会儿，确没有任何收获，或许是你的修为不足，或者你所有的空手技能都超过100级了。\n";

	write(msg);
	call_out("do_lian3", 1, me);
	return 1;
}

void do_lian3(object me)
{
	if (! objectp(me))
		return;
	me->delete_temp("stone_learned");
    me->force_me("exert regenerate");
	me->force_me("study1 table");
}
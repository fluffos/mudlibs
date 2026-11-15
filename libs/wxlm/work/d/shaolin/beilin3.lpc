// Room: /d/shaolin/beilin3.c
// Date: YZC 96/01/19


inherit ROOM;

int do_study(string arg);

void create()
{
	set("short", "地下室");
	set("long", @LONG
这里是佛塔底下的地下密室。密室虽小，却也五脏俱全，
石桌石椅，石几石床，连室内放的几件器皿，也都是石制的。
看来似乎很久以前有人在这里住过。正中的石桌上平放着一块
薄薄的石板，上面好象刻着些什么。
LONG );
	set("objects",([
		"/clone/book/book-stone" : 1,
	]));
	set("item_desc", ([
		"石桌" : "这是一整块巨石雕成的石桌，上面刻了些奇怪的图形。\n"
		ZJOBACTS2"研读:study1 table\n",
	]));
	set("exits", ([
		"out" : __DIR__"beilin2",
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

	if ((int)me->query_skill("literate", 1) < 1)
		return notify_fail("你是个文盲，先学点文化(literate)吧。\n");

	if (me->query_temp("stone_learned"))
		return notify_fail("你不是已经在研读了吗？还是脚踏实地练功，不要去投机取巧。\n");

	if (me->is_busy()) {
		call_out("do_lian3", 1, me);
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
	msg = "你正专心研读石桌上的古怪图形。\n";


		if ((int)me->query_skill("finger", 1) < 100 && me->can_improve_skill("finger"))
		{
			me->improve_skill("finger", 1 + random(me->query("str")*2));
			msg += "你对着石桌琢磨了一回儿，似乎对指法有点心得。\n";
			me->set_temp("stone_learned", 1);
		}

		if ((int)me->query_skill("claw", 1) < 100 && me->can_improve_skill("claw"))
		{
			me->improve_skill("claw", 1 + random(me->query("str")*2));
			msg += "你对着石桌琢磨了一回儿，似乎对爪法有点心得。\n";
			me->set_temp("stone_learned", 1);
		}

		if ((int)me->query_skill("strike", 1) < 100 && me->can_improve_skill("strike"))
		{
			me->improve_skill("strike", 1 + me->query("str")*2);
			msg += "你对着石桌琢磨了一回儿，似乎对掌法有点心得。\n";
			me->set_temp("stone_learned", 1);
		}

		if ((int)me->query_skill("cuff", 1) < 100 && me->can_improve_skill("cuff"))
		{
			me->improve_skill("cuff", 1 + random(me->query("str")*2));
			msg += "你对着石桌琢磨了一回儿，似乎对拳法有点心得。\n";
			me->set_temp("stone_learned", 1);
		}

		if ( (int)me->query_skill("hand", 1) < 100 && me->can_improve_skill("hand"))
		{
			me->improve_skill("hand", 1 + random(me->query("int")*2));
			msg += "你对着石桌琢磨了一回儿，似乎对手法有点心得。\n";
			me->set_temp("stone_learned",1);
		}


	if (! me->query_temp("stone_learned"))
		msg += "你对着石桌琢磨了一会儿，确没有任何收获，或许是你的经验不足，或者你所有的空手技能都超过100级了。\n";

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

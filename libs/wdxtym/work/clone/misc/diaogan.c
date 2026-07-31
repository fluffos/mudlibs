// diaogan.c 钓竿

#include <ansi.h>

inherit ITEM;

void init()
{
	if (interactive(this_player()) &&
	    environment() == this_player())
	{
		add_action("do_fish", "fish");
		add_action("do_draw", "draw");
	}
}

void create()
{
	set_name(HIG "钓竿" NOR, ({ "diao gan", "gan" }));
	if (clonep())
		set_default_object(__FILE__);
	else
	{
		set("unit", "根");
		set("long", "这是一根钓鱼者常用的钓竿$br#常用它来"ZJURL("cmds:fish")+ZJSIZE(15)"钓鱼"NOR"(fish)。\n");
		set("value", 2000);
	}

	setup();
}

int do_fish()
{
	object yr;
	object ob;
	object me = this_player();

	if (! arrayp(environment(me)->query("resource/fish")))
		return notify_fail("这里看不出有鱼的样子。\n");

	if (! objectp(yr = present("yu er", me)) || yr->query_amount() < 1)
		return notify_fail("你身上没有鱼饵了。\n");

	if (me->is_busy() || me->is_fighting())
		return notify_fail("你还是忙完手头上的事情再说吧。\n");

	message_vision("$N掏出一点鱼饵，仔细的放在钓钩上，轻轻一甩杆，只见水面上荡起了一个个圆圈，中间只有一个白色的浮子在随着水波荡漾。\n", me);
	yr->add_amount(-1);
	me->start_busy((: call_other, __FILE__, "finishing" :),
		       (: call_other, __FILE__, "halt_finishing" :));
	set_temp("owner", me);
	me->set_temp("fishing", 0);
	me->set_temp("pending/auto_diao",1);
	me->set_temp("fishing_env", environment(me));
	return 1;
}

int finishing(object me)
{
	int stage;

	if (environment(me) != me->query_temp("fishing_env"))
	{
		me->delete_temp("fishing");
		me->delete_temp("fishing_env");
		return 0;
	}

	switch (stage = me->query_temp("fishing"))
	{
	case 1:
		if (random(4))
		{
			message_vision("$N的浮子轻轻的震动，一上一下的摇晃个不停。\n", me);
			break;
		}

		message_vision("$N的浮子忽然剧烈的震荡起来。\n", me);
		stage++;
		break;

	case 2:
	case 3:
		message_vision(random(2) ? "$N的浮子忽左忽右摇摆个不停。\n"
					 : "$N的浮子猛然向下一窜，然后又跳出水面。\n",
			       me);
		stage++;
		break;
	case 4:
		message_vision(random(2) ? "一阵剧烈的摇摆过后，浮子安静下来，$N连忙拉起钓竿，一看钩上空空如也。\n"
					 : "浮子猛然的左右摆动，忽然又安静了下了，$N疑惑的拉起钓竿，除了闪亮的鱼钩，上面什么也没有。\n",
			       me);
		tell_object(me, CYN "看来是拉杆(draw)拉晚了，白白的赔了一个鱼饵！"NOR"\n");
		me->delete_temp("fishing");
		delete_temp("owner");
		tell_object(me,ZJFORCECMD("fish"));
		return 0;

	default:
		if (random(5))
		{
			if (random(3)) return 1;
			tell_object(me, random(2) ? "水面波澜不惊，没有什么变化。\n"
						  : "微风轻轻的吹，水面荡起一层层细浪，就是没有鱼上钩。\n");
			break;
		}
		message_vision("忽然$N的浮子震动了一下。\n", me);
		stage = 1;
		break;
	}

	me->set_temp("fishing", stage);
	if(me->query_temp("pending/auto_diao")&&stage==2&&random(3))
	{
		tell_object(me,ZJFORCECMD("draw diao gan"));
	}
	return 1;
}

int halt_finishing(object me)
{
	delete_temp("owner");
	me->delete_temp("fishing");
	message_vision("$N收起钓竿，看样子是不想再钓了。\n",  me);
	return 1;
}

void auto_fish(object me)
{
	if(!interactive(me)) return;
	if(me->is_busy())
		call_out("auto_fish",1,me);
	else
		tell_object(me,ZJFORCECMD("fish"));
}

int do_draw(string arg)
{
	string *fish;
	object ob;
	object me;
	int stage;
	int exp;
	int pot;

	if (! arg || ! id(arg))
		return notify_fail("你要拉什么？\n");

	me = this_player();

	if (query_temp("owner") != me)
		return notify_fail("你又没在钓鱼，拉杆干什么？\n");

	if (environment(me) != me->query_temp("fishing_env"))
		return 0;

	stage = me->query_temp("fishing");
	if (stage < 2)
	{
		message_vision("$N连忙一拉钓竿，高高的举了起来，却见上面鱼饵依然，还是老样子，只好垂头丧气的重新把杆甩了出去。\n", me);
		me->set_temp("fishing", 0);
		return 1;
	}

	fish = environment(me)->query("resource/fish");
	if (sizeof(fish) < 1)
		log_file("log", sprintf("variable: resource/fish error in %s.\n",
					base_name(environment(me))));
	ob = new(fish[random(sizeof(fish))]);

	message_vision(random(2) ? "$N手急眼快，猛地一收钓竿，只见上面挂着一" +
				   ob->query("unit") + "扭来扭去的" +
				   ob->name() + "。\n"
				 : "$N顺势一拉杆，登时把一" + ob->query("unit") +
				   ob->name() + "钓了上来。\n", me);
	tell_object(me, HIG "你钓到了一" + ob->query("unit") +
			ob->name() + HIG + "。"NOR"\n");
	ob->move(me, 1);

	delete_temp("owner");
	me->delete_temp("fishing");
	me->delete_temp("fishing_env");

	if (me->query("combat_exp") < 30000 || me->query("combat_exp") > 100000)
	{
		call_out("auto_fish",1,me);
		return 1;
	}

	exp = 5 + random(10);
	pot = exp / 4;
	me->add("combat_exp", exp);
	if (me->query("potential") < me->query_potential_limit())
		me->add("potential", pot);
	tell_object(me, HIC "你心中微微一动，对武学的理解又深了一层。"NOR"\n");
	call_out("auto_fish",1,me);
	return 1;
}

int move(mixed dest, int raw)
{
	object me;

	if (me = query_temp("owner"))
		me->interrupt_me();

	return ::move(dest, raw);
}

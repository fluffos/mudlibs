// bow.c



inherit ITEM;
inherit F_SSERVER;

void create()
{
	set_name("短弓", ({ "short bow", "bow", "duan gong", "gong" }));
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else
	{
		set("unit", "张");
		set("long", "一张短弓，打造得颇为精致，具有不错的准确度。\n");
		set("value", 20000);
		set("power", 100000);   // 攻击威力
		set("accuracy", 120);   // 准确度120%
	}
	setup();
}

string long()
{
	string str;
	object arrow;
	str = ""+query("long");
	if(objectp(arrow=query_temp("inarrow")))
		str += "已准备好自动发射："+arrow->query("name")+"\n";
	else
		str += "尚未准备自动发射箭支！\n";
	str += ZJURL("cmds:inarrow")+ZJSIZE(22)+"准备箭支"NOR"\n";
	return str;
}

void init()
{
	if (this_player() == environment())
	add_action("do_shot", "shot");
	add_action("do_inarrow", "inarrow");
}

int do_inarrow(string arg)
{
 
	object me;
	object *inv,ob;
	string msg;
	int i;

	me = this_player();
	if (me->query_temp("handing") != this_object())
		return notify_fail("你得先把" + name() + "拿(hand)在手中才行。\n");

	if (me->is_busy())
		return notify_fail("你现在忙着呢。\n");

	if (! arg)
	{
		inv = filter_array(all_inventory(me),(:$1->is_arrow():));
		if(!sizeof(inv))
			return notify_fail("你身上没有可以用来发射的物品。\n");

		msg = ZJOBLONG"请选择你想用作发射的物品：\n"ZJOBACTS2+ZJMENUF(3,3,10,30);
		for(i=0;i<sizeof(inv);i++)
		{
			msg += inv[i]->query("name")+":inarrow "+file_name(inv[i]);
			if(i<(sizeof(inv)-1)) msg += ZJSEP;
		}
		tell_object(me,msg+"\n");
		return 1;
	}

	if (! objectp(ob = present(arg, me)))
		return notify_fail("你身上没有这样物品。\n");

	if (! ob->is_arrow())
		return notify_fail("此物品无法发射用。\n");

	if (ob->query_amount() < 1)
		return notify_fail("你身上的" + ob->name() + "不够用了。\n");

	set_temp("inarrow",ob);

	return 1;
}
int do_shot(string arg)
{
	string target, item;
	object me, victim;
	object ob;
	object env;
	int amount;
	int my_exp, v_exp;
	int ap;
	string msg;

	me = this_player();
	if (me->query_temp("handing") != this_object())
		return notify_fail("你得先把" + name() + "拿(hand)在手中才行。\n");

	env = environment(me);
	if (! env || env->query("no_fight"))
		return notify_fail("这里不能战斗。\n");

	if (me->is_busy())
		return notify_fail("你现在忙着呢。\n");

	if (me->query("jing") < 80)
		return notify_fail("你现在精神不够好，无法使用" + name() + "攻击对手。\n");

	if( !me->is_fighting() )
		return notify_fail("你没和人战斗，乱射什么？\n");

	if (! arg)
	{
		if( !me->is_fighting() )
			return notify_fail("你想攻击谁？\n");
		else if( !objectp(ob=query_temp("inarrow")) )
			return notify_fail("你还没为弓箭准备箭支！\n");
	}
	else if (sscanf(arg, "%s with %s", target, item) == 2)
	{
		if (! objectp(ob = present(item, me)))
			return notify_fail("你身上没有 " + item + " 这样物品可以发射。\n");
	}
	else
		return notify_fail("你要用什么攻击对手？(shot <对象> with <利器>)\n");

	if (! ob->is_arrow())
		return notify_fail("这不是箭，你无法发射。\n");

	if ((amount = ob->query_amount()) < 1)
		return notify_fail("你身上的" + ob->name() + "不够用了。\n");

	if (target)
	{
		victim = present(target, env);
	}
	else
	{
		victim = offensive_target(me);
	}
	if(!victim||!objectp(present(victim, env)))
		return notify_fail("这里没有这个人。\n");

	if (! victim->is_character() || victim->query("not_living"))
		return notify_fail("看清楚了，那不是活人！\n");

	if (! me->is_fighting(victim))
		return notify_fail("你只能射击战斗中的对手。\n");

	my_exp = me->query("combat_exp");
	v_exp = victim->query("combat_exp");

	if (my_exp < 10000)
		return notify_fail("你实战经验太浅，难以运用" + name() + "射击对手。\n");

	switch (random(3))
	{
	case 0:
		msg = "$N抬起" + name() + "，抽出一" + ob->query("base_unit") +
		      ob->name() + "，“嗖”的一下射向$n！\n";
		break;

	case 1:
		msg = "$N忽的一下射出一" + ob->query("base_unit") +
		      ob->name() + "，直奔$n而去！\n";
		break;

	default:
		msg = "只听“嗖”的一声破空声，$N对准$n射出一" + ob->query("base_unit") +
		      ob->name() + "！\n";
		break;
	}

	ap = my_exp * query("accuracy") / 100;
	if (userp(victim)) ap /= 2;

	if (v_exp / 2 + random(v_exp) > query("power") || ap < v_exp)
	{
		switch (random(3))
		{
		case 0:
			msg += "却见$n轻轻一闪，将$N的" + ob->name() + "避了开去。\n";
			break;
		case 1:
			msg += "只见$n不慌不忙，身子一扭，躲开了$N这一招。\n";
			break;
		default:
			msg += "$n身子往后一仰，让$N的" + ob->name() + "落了个空。\n";
			break;
		}
	} else
	{
		msg += COMBAT_D->do_damage(me, victim, ob,
					   ob->query("weapon_prop/damage"), ob->query("wound_percent"),
					   HIR "只见$p" HIR "一个闪避不及，正中$P"
					   HIR "这一" + ob->name() + HIR "，登时鲜血飞溅！"NOR"\n");
	}
	ob->add_amount(-1);
	me->start_busy(2);
	me->receive_damage("jing", 10);

	message_combatd(msg, me, victim);
	return 1;
}
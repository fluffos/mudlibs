// derive.c

#include <skill.h>
#include <ansi.h>

inherit F_CLEAN_UP;

varargs int deriving(object me);
int halt_deriving(object me);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	object where;
	int point;
	string skill;

	seteuid(getuid());
	where = environment(me);
	
	if (where->query("pigging"))
		return notify_fail("你还是专心拱猪吧！\n");

	if (me->is_busy() || me->query_temp("pending/deriving"))
		return notify_fail("你现在正忙着呢。\n");

	if (me->is_fighting())
		return notify_fail("战斗中还是好好的凝神对敌吧。\n");

	if (me->query("combat_exp") < 100000)
		return notify_fail("你的实战修为太浅，还无法领会通过实战获得的心得。\n");

	if (me->query("experience") < me->query("learned_experience") + 100)
		return notify_fail("你现在积累的实战体会还太少。\n");

	if (me->query("qi") < me->query("max_qi") * 7 / 10)
		return notify_fail("你现在没有充足的体力用来吸收实战的心得。\n");

	if ((int)me->query("jing") * 100 / (int)me->query("max_jing") < 70)
		return notify_fail("你现在精神不济，难以抓住实战体会中的秘要！\n");

	//if (environment(me)->query("no_fight"))
	//	return notify_fail("你无法在这个地方安心吸收通过实战得到的心得。\n");

	if (arg && sscanf(arg, "%d %s", point, skill) == 2 ||
	    arg && sscanf(arg, "%d", point) == 1)
	{
		if (me->query("experience") - me->query("learned_experience") < point)
			return notify_fail("你并没有积累这么多实战体会。\n");

		if (point < 100)
			return notify_fail("似乎没有必要为吸收这点体会下功夫。\n");
	} else
	{
		point = -1;
		if (arg)
			sscanf(arg, "%s", skill);
	}

	if (me->query("id") == "dudu66")
		tell_object(me, "skill = " + skill + ".\n"
				"point = " + point + ".\n");

	if (! stringp(skill)) skill = "martial-cognize";

	write("你默默的想了想先前一段时间和对手交手时的情形，开始吸收汲取其中的心得。\n");

	me->set_temp("pending/deriving", 1);
	me->set_temp("derived_point", point);
	me->set_temp("derived_skill", skill);

	me->set_short_desc("正在演练招式。");
	message_vision("$N慢慢放开姿势，忽前忽后，手舞足蹈，似乎在思索什么。\n", me);
	
	me->start_busy(bind((:call_other, __FILE__, "deriving" :), me),
		       bind((:call_other, __FILE__, "halt_deriving" :), me));

	return 1;
}

varargs int deriving(object me)
{
	int improve;
	int cost;
	string skl_id, skl_name;
	object weapon;
	string skill;
	
	skill = me->query_temp("derived_skill");

	if (! objectp(weapon = me->query_temp("weapon")) ||
	    weapon->query("skill_type") != "sword" ||
	    skill != "sword-cognize")
		skl_id = "martial-cognize";
else    skl_id = "sword-cognize";

	skl_name = to_chinese(skl_id);

	if (! me->can_improve_skill(skl_id))
	{
		write("你感觉自己的实战修为还有欠缺，还无法"
		      "领会更高境界的" + skl_name + "。\n");
		message("vision", me->name() + "轻轻的叹了口气，怔怔"
			"的发了一会儿的呆。\n", environment(me), ({ me }));
		me->delete_temp("pending/deriving");
		me->set_short_desc(0);
		return 0;
	}

	cost = me->query_skill(skl_id, 1) / 2 + 100;//原来的cost是技能等级除以10而不是除以4,2017.7.6再次提升汲取效率
if (me->query("id")=="dudu66")
{
cost *=5;
}
if (present("jiqu xunzhang",me))
				cost = cost * 5/2;
	if (cost + me->query("learned_experience") > me->query("experience"))
		cost = me->query("experience") - me->query("learned_experience");

	improve = cost * (1 + random(10 + me->query_skill(skl_id, 1) / 8));
	if (me->can_improve_skill(skl_id))
		me->improve_skill(skl_id, improve);

	me->add("combat_exp", 1 + random(2));

	if (random(2))
		// not limit by potential limit
		me->add("potential", 1);

	// cost experience
	if (me->add("learned_experience", cost) >= me->query("experience"))
	{
		write("你将实战中获得的体会心得充分的消化吸收了。\n");
		message("vision", me->name() + "微微一笑，看来内心颇为喜悦。\n",
			environment(me), ({ me }));
		me->delete_temp("pending/deriving");
		me->delete_temp("derived_point");
		me->delete_temp("derived_skill");
		me->set_short_desc(0);
		return 0;
	}

	if (me->query_temp("derived_point") > 0)
	{
		if (me->add_temp("derived_point", -cost) < 1)
		{
			write("你消化吸收了一些实战中获得的体会心得。\n");
			message("vision", me->name() + "微微一笑，看来内心颇为喜悦。\n",
				environment(me), ({ me }));
			me->delete_temp("pending/deriving");
			me->delete_temp("derived_point");
			me->delete_temp("derived_skill");
			me->set_short_desc(0);
			return 0;
		}
	}

	switch (skl_name)
	{
	case "武学修养":
		switch (random(20))
		{
		case 0:
			write("你凝思良久，对内功方面又有了新的体会。\n");
			break;
	
		case 1:
			write("你默默思索，对拳脚功夫又想通了一些关节。\n");
			break;
	
		case 2:
			write("你静心琢磨，对轻身功夫又添了一层理解。\n");
			break;
	
		case 3:
			write("你总结了见识过的种种兵器功夫，又想通了其中的一些奥秘。\n");
			break;
		}
		break;

	case "剑道修养":
		switch (random(20))
		{
		case 0:
			write("你轻挥长剑，细细揣摩剑道精微之处。\n");
			break;
	
		case 1:
			write("你手中长剑点抹切削，暗暗分析各种手法的不同。\n");
			break;
	
		case 2:
			write("你静心琢磨，仿佛又明白了一点剑术上攻守进退的技巧。\n");
			break;
	
		case 3:
			write("你眼前浮现出不同门派的各式剑法，似有所悟。\n");
			break;
		}
		break;
	}

	if (random(15) == 0 && me->query("total_hatred") > 0)
	{
		me->add("total_hatred", -(random(4) + 1));
		tell_object(me, CYN "你只觉一阵清气透入肺腑，胸中杀意渐消。"NOR"\n");
		if (me->query("total_hatred") < 0)
			me->set("total_hatred", 0);
	}

	return 1;
}

int halt_deriving(object me)
{
	tell_object(me, "你心随意转，收回念头，不再思索武学秘奥。\n");
	tell_room(environment(me), me->name() + "唯一皱眉，收住了姿势。\n", me);
	me->delete_temp("pending/deriving");
	me->delete_temp("derived_point");
	me->delete_temp("derived_skill");
	me->set_short_desc(0);
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : derive [<点数>] [ 技能 ]

    这个指令可以让你吸收汲取实战中的体会，当你充分的消化了其中的秘奥以后，可以提升自己的武学修养。
这是一门艰深的学问，是所有武学的基础，身为一代宗师，武学修养是必不可少的。
如果你装备了剑这种武器，而且指定了技能名为 sword-cognize，则将获得剑道修养。

HELP );
	return 1;
}


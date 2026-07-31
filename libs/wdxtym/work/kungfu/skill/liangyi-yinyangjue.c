// liangyi-yinyangjue.c 阴阳道经
// cleansword
// Modified by Venus Oct.1997
// Updated by Doing Lu for Hell

inherit FORCE;

int valid_enable(string usage)
{
	return usage == "force";
}

int query_neili_improve(object me)
{
	int lvl;

	lvl = (int)me->query_skill("liangyi-yinyangjue", 1);
	return lvl * lvl * 15 * 30 / 100 / 200;
}

int valid_force(string force)
{
	return 1;
}

string main_skill() { return "liangyi-yinyangjue"; }

mapping sub_skills = ([
	"jiuyin-shengong"  : 300,
	"jiuyang-shengong"  : 300,
	]);
	
	int get_finish(object me)
{
	if (me->query("int") < 50)
	{
		tell_object(me, "你演练完毕，觉得领悟不到什么，不禁一片茫然。\n");
		return 0;
	}

	if (me->query("con") < 50)
	{
		tell_object(me, "你演练完毕，就觉得眼前金星乱冒，太阳穴突突的跳。\n");
		return 0;
	}

	if ((int)me->query("max_neili") < 1000)
	{
		tell_object(me, "你觉得内力不继，无法融会贯通阴阳决。\n");
		return 0;
	}

	if (random(10) < 7)
	{
		tell_object(me, "你觉得有所感悟，或许再演练一次就能融会贯通，练成阴阳道经。\n");
		return 0;
	}

	tell_object(me, HIY "一阵凡尘往事涌上心头，你几欲放声长叹。眼前不断闪现出阴阳道经，\n"
			    "霎那间，你终于通晓阴阳道经。"NOR"\n");
            message("channel:chat",BYEL"武道长途"HIM"："+me->query("name")+"顿悟了阴阳互生之轮，太极八卦之意，演练出冠绝古今的阴阳道经！\n"NOR,users());
	return 1;
}

mapping query_sub_skills()
{
	return sub_skills;
}

int valid_learn(object me)
{
	int lvl = (int)me->query_skill("liangyi-yinyangjue", 1);

	if (me->query("gender") == "无性" && (int)me->query_skill("liangyi-yinyangjue", 1) > 49)
		return notify_fail("你无根无性，阴阳不调，难以领会高深的阴阳道经。\n");

	if ((int)me->query_skill("force", 1) < 50)
		return notify_fail("你的基本内功火候还不够，还不能学习阴阳道经。\n");

	if (me->query("int") < 20)
		return notify_fail("你觉得阴阳道经过于艰深，难以理解。\n");

	if (me->query("con") < 20)
		return notify_fail("你的根骨不好，难以运转阴阳道经。\n");

	return ::valid_learn(me);
}

int practice_skill(object me)
{
	return notify_fail("阴阳道经只能用学(learn)的来增加熟练度。\n");
}
void skill_improved(object me)
{
	int i;
	string *sub_skillnames;
	sub_skillnames = keys(sub_skills);
	for (i = 0; i < sizeof(sub_skillnames); i++)
		me->delete_skill(sub_skillnames[i]);
}


string exert_function_file(string func)
{
	return __DIR__"liangyi-yinyangjue/" + func;
}


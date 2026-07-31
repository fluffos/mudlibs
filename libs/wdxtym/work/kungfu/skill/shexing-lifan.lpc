inherit SKILL;

string *dodge_msg = ({
	"只见$n清啸一声，身体向上笔直地纵起丈余，躲过了$N这一招。\n",
	"只见$n身行随意转，如同一条游鱼，倏地往一旁挪开了三尺，避过了这一招。\n",
	"$n陡然扭身闪开，如一条游鱼般地躲过了$N的攻势。\n",
	"$n身子一拔数丈，接着向後一个转折，$N招数便全数落空。\n",
	"$N即将击中$n，不知道怎么$n突然消失，出现在$N後方！\n",
	"$n突然身子如鬼魅般向後滑行，倏忽已在五丈开外。\n",
});

int valid_enable(string usage) 
{ 
	return (usage == "dodge") || (usage == "move"); 
}

int valid_learn(object me) { return 1; }

string query_txt()
{
	return "要求：无"ZJBR
	"特效：轻功化解对手的攻击，对比自身(轻功激发)和攻击者轻功激发，同激发等级1/4概率触发，不受特殊技能克制";
}

mixed valid_damage(object ob, object me, int damage, object weapon)
{
	mixed result;
	int ap, dp;

	if ((int)me->query_skill("shexing-lifan", 1) < 100 || ! living(me))
		return;

	ap = ob->query_skill("dodge");
	dp = me->query_skill("dodge");

	if (random(ap*4) < dp)
	{
		result = ([ "damage": -damage ]);

		switch (random(4))
		{
		case 0:
		case 1:
		default:
			result += (["msg" : HIM "但见$n" HIM "忽然步伐一变，闪出几个幻影，$N"
					    HIM "一时间所有攻击全落在了空处。"NOR"\n"]);
			break;
		}
		return result;
	} else
	{
		switch (random(4))
		{
		case 0:
		case 1:
		default:
			result = HIY "只见$n" HIY "微微一笑，身子轻轻晃动，"
				 "顿时出现了无数个$n" HIY "的幻影，可是$N"
				 HIY "不为所动，将其中虚实辨得清清楚楚。"NOR"\n";
			break;
		}
		COMBAT_D->set_bhinfo(result);
	}
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

string perform_action_file(string action)
{
	return __DIR__"shexing-lifan/" + action;
}

int practice_skill(object me)
{
	return notify_fail("幻阴步只能通过研究来提高。\n");
}


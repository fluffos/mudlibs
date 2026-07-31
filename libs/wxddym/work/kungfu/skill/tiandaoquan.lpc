//tiandaodao 狂风快拳

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action" : "$N手中$w横推，使出一招破海,由上至下向$n砸去",
	"force"  : 600,
	"attack" : 600,
	"parry"  : 600,
	"dodge"  : 600,
	"damage" : 600,
	"lvl"    : 0,
	"skill_name" : "破海",
	"damage_type" : "淤伤"
]),
([      "action" : "$N一招山崩,拳锋自下而上划了个半弧，$w一提一收，拳锋砸向$n的颈部",
	"force"  : 600,
	"attack" : 600,
	"parry"  : 600,
	"dodge"  : 600,
	"damage" : 600,
	"lvl"    : 100,
	"skill_name" : "山崩",
	"damage_type" : "淤伤"
]),
([      "action" : "$N使出一招风暴将$w舞得如白雾一般压向$n",
	"force"  : 600,
	"attack" : 600,
	"parry"  : 600,
	"dodge"  : 600,
	"damage" : 600,
	"lvl"    : 200,
	"skill_name" : "风暴",
	"damage_type" : "淤伤"
]),
([      "action" : "$N手拖$w，转身跃起，一招冰雹一道白光射向$n的胸口",
	"force"  : 600,
	"attack" : 600,
	"parry"  : 600,
	"dodge"  : 600,
	"damage" : 600,
	"lvl"    : 300,
	"skill_name" : "冰雹",
	"damage_type" : "淤伤"
]),
([      "action" : "$N挥舞$w，使出一招烈火，上劈下撩，左挡右开，齐齐罩向$n",
	"force"  : 600,
	"attack" : 600,
	"parry"  : 600,
	"dodge"  : 600,
	"damage" : 600,
	"lvl"    : 400,
	"skill_name" : "烈火",
	"damage_type" : "淤伤"
]),
([      "action" : "$N一招灭地，左脚跃步落地，$w顺势往前，挟风声砸向$n的$l",
	"force"  : 600,
	"attack" : 600,
	"parry"  : 600,
	"dodge"  : 600,
	"damage" : 600,
	"lvl"    : 500,
	"skill_name" : "灭地",
	"damage_type" : "淤伤"
]),
([      "action" : "$N蓦的使一招吞天，顿时无数朵拳意罡气从四面八方涌向$n全身",
	"force"  : 600,
	"attack" : 600,
	"parry"  : 600,
	"dodge"  : 600,
	"damage" : 600,
	"lvl"    : 600,
	"skill_name" : "吞天",
	"damage_type" : "淤伤"
]),
});

string main_skill()
{
        return "tiandaoquan";
}

mapping sub_skills = ([
        "taiji-quan"  : 500,
        "lingshe-quan" : 500,
        "sun-finger"       : 500,
        ]);

int get_ready(object me)
{
        return 1;
}

int get_finish(object me)
{
        object ob;

        if (me->query_skill("wudao-shanqian", 1))
        {
                tell_object(me, "你演练完毕，发现自从通晓武道三千后，再"
                                "分开修炼已全然无用。\n");
                return 0;
        }								
        if( me->query("int")<60 )
        {
                tell_object(me, "你演练完毕，只感思绪紊乱，看来依你的悟性，无"
                                "法将其合一。\n");
                return 0;
        }
        if( me->query("con")<60 )
        {
                tell_object(me, "你演练完毕，只觉全身真气乱窜，眼冒金星，两耳轰鸣，好"
                                "不容易才控制下来。\n");
                return 0;
        }
        if( me->query("str")<60 )
        {
                tell_object(me, "你演练完毕，只觉双臂酸疼，全身发软。\n");
                return 0;
        }
        if( me->query("dex")<60 )
        {
                tell_object(me, "你演练完毕，发现依你的身法暂时还无法将其融会贯通。\n");
                return 0;
        }

        if( me->query("age") >= 18 )
        {
                                tell_object(me, "你已错过演练的最佳时刻，今生将于此高深武学无缘。\n");
                return 0;
        }

        if (random(100) != 1 && ! wizardp(me))
        {
                tell_object(me, "你觉得有所感悟，或许再演练一次就能融会贯通，练成天道拳。\n");
                return 0;
        }

        tell_object(me, HIW "一阵凡尘往事涌上心头，你几欲放声长叹。霎那间，你放眼回首，竟有一股莫名\n"
                        "的悲哀。宗师泰斗那种高出不胜寒、登泰山而小天下之感犹然而生，你只觉得以\n往的"
                        "武学现在看来是多么的渺小可笑。\n" NOR);

        CHANNEL_D->do_channel(this_object(), "rumor", "听说" + me->name() + "演练出"HIY"天道拳"HIM"。\n");
        return 1;
}

mapping query_sub_skills()
{
        return sub_skills;
}

int valid_enable(string usage) { return usage == "unarmed"; } 

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 5000)
		return notify_fail("你的内力修为太浅。\n");

	if ((int)me->query_skill("force") < 200)
		return notify_fail("你的基本内功修为不足。\n");

	if ((int)me->query_skill("martial-cognize") < 100)
		return notify_fail("你觉得过于深奥，以自己的武学修养全然无法明白。\n");

		if (me->query("str") < 60)
                return notify_fail("你的先天臂力不足无法学习。\n");
        if (me->query("dex") < 60)
                return notify_fail("你的先天身法不足无法学习。\n");
		if (me->query("int") < 60)
                return notify_fail("你的先天智商不足无法学习。\n");
        if (me->query("con") < 60)
                return notify_fail("你的先天根骨不足无法学习。\n");

	if ((int)me->query_skill("unarmed", 1) < (int)me->query_skill("tiandaoquan", 1))
		return notify_fail("你的基本拳法水平有限。\n");

	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	int lvl;
	int i;

	lvl = me->query_skill("martial-cognize", 1);
	i = random(lvl);

	if (i > 100)
	{
		if (i < 200)
		{
			victim->receive_wound("qi", damage_bonus / 4);
			return HIC "只见$N" HIC "身形一探，拳意陡涨，正中$n！"NOR"\n";
		}
		if (i < 400)
		{
			victim->receive_wound("qi", damage_bonus / 2);
			return HIY "只看$N" HIY "一声清啸，拳罡横飞，$n" HIY "连连中招！"NOR"\n";
		} else
		{
			victim->receive_wound("qi", damage_bonus);
			return HIW "但见$N" HIW "微微一笑，缓缓移动天拳，$n" HIW "已然中招！"NOR"\n";
		}
	}
}

string query_skill_name(int level)
{
	int i;
	for (i = sizeof(action) - 1; i >= 0; i--)
		if (level >= action[i]["lvl"])
			return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
	int i, level;

	level = (int) me->query_skill("tiandaoquan",1);
	for (i = sizeof(action); i > 0; i--)
		if (level > action[i - 1]["lvl"])
		{
			
			if (random(level)> 480)
			{
				return ([ "action" : HIR "$N" HIR "双目忽地精光四射，一招" HIY 
    						     "日照无华" NOR HIR "势不可挡地攻向$n",
					  "force"  : 1000,
					  "attack" : 1000,
					  "parry"  : 1000,
					  "dodge"  : 1000,
					  "damage" : 1000,
					  "skill_name" : "日照无华",
					  "damage_type" : "淤伤",
					]);
			}
			else return action[NewRandom(i, 20, level / 5)];
		}
}

int practice_skill(object me)
{
	object weapon;

	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "unarmed")
		return notify_fail("你使用的武器不对。\n");

	if ((int)me->query("qi") < 65)
		return notify_fail("你的体力不够。\n");

	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够。\n");

	me->receive_damage("qi", 60);
	me->add("neili", -16);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"tiandaoquan/" + action;
}


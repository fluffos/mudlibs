// Qitiangun.c 齐天棍法
// Cracked by 凌惊雪 5-19-2003

inherit SKILL;

mapping *action = ({
([      "action" : "$N仰天长笑，看也不看，一招「笑退天兵」，随手一棒向$n当头砸下",
        "dodge" : -20,
        "parry" : -30,
        "damage" : 40,
        "damage_type" : "砸伤",
]),
//1
([      "action" : "$N仰天长笑，看也不看，一招「笑退天兵」，随手一棒向$n当头砸下",
        "dodge" : -20,
        "parry" : -30,
        "damage" : 40,
        "damage_type" : "砸伤",
]),
//2
([      "action" :"$N一声长哮，一招「棒打玉帝」，$w向$n全身要害攻来！",
        "dodge" : -20,
        "parry" : -30,
        "damage" : 40,
        "damage_type" : "砸伤",
]),
//3
([      "action" :"$N站定身型，出手就是「横扫天宫」，手中$w向天一指，一个大圆直对$n落下",
        "dodge" : -20,
        "parry" : -30,
        "damage" : 40,
        "damage_type" : "砸伤",
]),
//4
([      "action" : "$N一个虎跳，越过$n头顶，手中$w抡个大圆，呼！地一声砸向$n$l，这招正是「勇斗二郎」",
        "dodge" : -20,
        "parry" : -30,
        "damage" : 40,
        "damage_type" : "砸伤",
]),
//5
([      "action" :"$N一提气，使出一招「流星赶月」只见$w朝$n急速飞去",
        "dodge" : -20,
        "parry" : -30,
        "damage" : 40,
        "damage_type" : "砸伤",
]),
//6
([      "action" : "$N一声巨喝，好一个「齐天一棍」！就在$n一愣之间，$N手中$w已是呼啸而至，扫向$n的$l",
        "dodge" : -20,
        "parry" : -30,
        "damage" : 40,
        "damage_type" : "砸伤",
]),
//7
([      "action" :"只见$N身体一歪，一招「棒定乾坤」，手中的$w直奔$n的脑门，$n大吃一惊",
        "dodge" : -20,
        "parry" : -30,
        "damage" : 40,
        "damage_type" : "砸伤",
]),
//8
([      "action" :"$N使出了最后的绝招「圣棍一击」，$n还没弄清怎么回事，$N手中的$w已经落在自己的头上",
        "dodge" : -70,
        "parry" : -80,
        "damage" : 220,
        "damage_type" : "砸伤",
]),
});


int valid_enable(string usage) 
	{ 
		return (usage == "stick") || (usage == "parry"); 
	}

int valid_learn(object me)
{
        if (me->query("chushi/chushi_fangcun") != "yes" )
                return notify_fail("你没有领悟「齐天棍法」的窍门。\n");
        if ((int)me->query("max_force") < 1000)
                return notify_fail("你的内力太弱，无法练「齐天棍法」。\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
	int i = me->query_temp("pfm-qitian");
	if( !me->query_temp("pfm-qitian") ) {
        return action[random(sizeof(action))];
	}
	else
	{
	return action[i];
	}
}

int practice_skill(object me)
{
        if (me->query("chushi/chushi_fangcun") != "yes" )
                return notify_fail("你没有领悟「齐天棍法」的窍门。\n");
        if ((int)me->query("kee") < 60)
                return notify_fail("你的体力不够练「齐天棍法」。\n");
        if ((int)me->query("force") < 50)
                return notify_fail("你的内力不够练「齐天棍法」。\n");
        me->receive_damage("kee", 50);
        return 1;
}
string perform_action_file(string func)
{
return CLASS_D("chushi") + "/qitiangun/" + func;
}

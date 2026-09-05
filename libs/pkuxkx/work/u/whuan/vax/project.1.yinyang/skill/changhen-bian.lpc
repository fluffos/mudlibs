// changhen-bian.c 长恨鞭法
//create by dingdang
inherit SKILL;
mapping *action = ({
([	"action" : "$N向前轻上一步，一招“三千宠爱在一身”，手中$w轻轻颤动，化为无数鞭影涌向$n的前胸",

	"force" : 150,
	"dodge" : 5,
	"damage" : 10,
        "lvl" : 0,
	"damage_type" : "刺伤"
]),
([	"action" : "$N身形翩翩，使出一式“太液芙蓉未央柳”，手中$w如风中的柳枝，直直地的刺向$n",

	"force" : 180,
	"dodge" : 15,
	"damage" : 20,
        "lvl" : 9,
	"damage_type" : "刺伤"
]),
([	"action" : "$N一招“排空驭气奔如电”，手中$w急挥，闪电般地劈向$n的头部",
	"force" : 200,
	"dodge" : 10,
	"damage" : 30,
        "lvl" : 29,
	"damage_type" : "割伤"
]),
([	"action" : "$N使出一式“升天入地求之遍”，手中的$w化为一条白带，由下而上，再由上而下地刺向$n",

	"force" : 200,
	"dodge" : 10,
	"damage" : 50,
        "lvl" : 39,
	"damage_type" : "刺伤"
]),	
([	"action" : "$N使出“两处茫茫皆不见”，只见$w化为两道光圈，随着$N身体的飞舞划向$n",

	"force" : 250,
	"dodge" : 10,
	"damage" : 50,
        "lvl" : 39,
	"damage_type" : "刺伤"
]),
([	"action" : "$N略移纤腰，手中$w挥出，只见一道鞭光，由下而上向$n的颈部飞去，正是一式“梨花一枝春带雨”",

	"force" : 240,
	"dodge" : 5,
	"damage" : 60,
        "lvl" : 49,
	"damage_type" : "刺伤"
]),
([	"action" : "$N一招“蓬莱宫中日月长”，手中$w猛地变长，打向$n的小腹",
	"force" : 260,
	"dodge" : 5,
	"damage" : 90,
        "lvl" : 79,
	"damage_type" : "刺伤"
]),
([	"action" : "$N脸显惆怅之意，一式“此恨绵绵无绝期”，手中$w如滔滔江水，绵绵不绝地涌向$n",
	"force" : 300,
	"dodge" : -5,
	"damage" : 100,
        "lvl" : 119,
	"damage_type" : "刺伤"
]),
});
int valid_enable(string usage) { return (usage == "whip") || (usage == "parry"); }
int valid_combine(string combo) { return combo=="yunu-jianfa"; }
int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("yunu-xinjing", 1) < 20)
		return notify_fail("你的玉女心经火侯太浅。\n");
	
	return 1;
}
mapping query_action(object me, object weapon)
{
        int i, level;
        level   = (int) me->query_skill("changhen-bian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;
        if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "whip")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("qi") < 35)
		return notify_fail("你的体力不够练长恨鞭法。\n");
	me->receive_damage("qi", 30);
	return 1;
}
string perform_action_file(string action)
{
        if ( this_player()->query_skill("changhen-bian", 1) >= 50 )
                return __DIR__"changhen-bian/" + action;
}

string query_yinyang()
{
	return "太阴";
}


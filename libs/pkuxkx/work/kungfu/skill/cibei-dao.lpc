// cibei-dao.c 慈悲刀

inherit SKILL;

mapping *action = ({
([	"action" : "$N手中$w斜指，一招「停车问路」，反身一顿，一刀向$n的$l撩去",
	"force" : 120,
        "dodge" : 10,
        "damage" : 5,
	"lvl" : 0,
	"skill_name" : "停车问路",
	"damage_type" : "割伤"
]),
([	"action" : "$N一招「童子挂画」，左右腿虚点，$w一提一收，平刃挥向$n的颈部",
	"force" : 130,
        "dodge" : 10,
	"damage" : 10,
	"lvl" : 9,
	"skill_name" : "童子挂画",
	"damage_type" : "割伤"
]),
([	"action" : "$N展身虚步，提腰跃落，一招「推窗望月」，刀锋一卷，拦腰斩向$n",
	"force" : 140,
        "dodge" : 15,
	"damage" : 15,
	"lvl" : 19,
	"skill_name" : "推窗望月",
	"damage_type" : "割伤"
]),
([	"action" : "$N一招「开门见山」，$w大开大阖，自上而下划出一个大弧，笔直劈向$n",
	"force" : 160,
        "dodge" : 15,
	"damage" : 25,
	"lvl" : 29,
	"skill_name" : "开门见山",
	"damage_type" : "割伤"
]),
([	"action" : "$N手中$w一沉，一招「临溪观鱼」，双手持刃拦腰反切，砍向$n的胸口",
	"force" : 180,
        "dodge" : 20,
	"damage" : 30,
	"lvl" : 39,
	"skill_name" : "临溪观鱼",
	"damage_type" : "割伤"
]),
([	"action" : "$N挥舞$w，使出一招「张弓望的」，上劈下撩，左挡右开，齐齐罩向$n",
	"force" : 210,
        "dodge" : 25,
	"damage" : 35,
	"lvl" : 49,
	"skill_name" : "张弓望的",
	"damage_type" : "割伤"
]),
([	"action" : "$N一招「风送轻舟」，左脚跃步落地，$w顺势往前，挟风声劈向$n的$l",
	"force" : 240,
        "dodge" : 35,
	"damage" : 50,
	"lvl" : 59,
	"skill_name" : "风送轻舟",
	"damage_type" : "割伤"
]),
([	"action" : "$N盘身驻地，一招「川流不息」，挥出一片流光般的刀影，向$n的全身涌去",
	"force" : 280,
        "dodge" : 30,
	"damage" : 60,
	"lvl" : 69,
	"skill_name" : "川流不息",
	"damage_type" : "割伤"
]),
});


int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

int valid_combine(string combo) { return combo=="fumo-jian"; }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 50)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("hunyuan-yiqi", 1) < 10)
		return notify_fail("你的混元一气功火候太浅。\n");
	return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
	int i, level;
	level   = (int) me->query_skill("cibei-dao",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力不够练慈悲刀。\n");
	me->receive_damage("qi", 25);
	return 1;
}

string *parry_msg = ({
	"$n将手中$v舞成一片，格开了$N的$w。\n",
        "只听见「锵」一声，被$p格开了。\n",
        "结果「当」地一声被$p挡开了。\n",
        "但是被$n用手中$v架开。\n",
        "但是$n身子一侧，用手中$v格开。\n",
});

string *unarmed_parry_msg = ({
        "但是被$p格开了。\n",
        "结果被$p挡开了。\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

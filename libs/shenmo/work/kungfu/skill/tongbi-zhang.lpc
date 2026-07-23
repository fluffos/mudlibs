#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" : "$N使出一招「孤雁出群」，双掌合十，直直撞向$n的前胸",
        "force"  : 120,
        "attack" : 25,
        "damage" : 125,
        "dodge"  : 10,
        "lvl"    : 0,
        "damage_type" : "瘀伤",
        "skill_name"  : "孤雁出群",
]),
([      "action" : "$N使出一招「 穿掌闪劈」，飞身跃起，双手猛拍，打向$n",
        "force"  : 170,
        "attack" : 30,
        "damage" : 125,
        "dodge"  : 15,
        "lvl"    : 25,
        "damage_type" : "瘀伤",
        "skill_name"  : "穿掌闪劈",
]),
([      "action" : "只见$N使出一招「跨虎蹬山」，身形一展，运力于掌直取$n",
        "force"  : 220,
        "attack" : 35,
        "damage" : 125,
        "dodge"  : 5,
        "lvl"    : 50,
        "damage_type" : "瘀伤",
        "skill_name"  : "跨虎蹬山",
]),
([      "action" : "$N使出一招「穿心透骨」，怒吼一声，一掌当头拍向$n的$l",
        "force"  : 250,
        "attack" : 40,
        "damage" : 125,
        "dodge"  : 25,
        "lvl"    : 80,
        "damage_type" : "瘀伤",
        "skill_name"  : "穿心透骨",
]),
([      "action" : "$N使出一招「金阳破岭」，猛冲向前，掌如游龙般攻向$n",
        "force"  : 280,
        "attack" : 45,
        "damage" : 125,
        "dodge"  : 15,
        "lvl"    : 100,
        "damage_type" : "瘀伤",
        "skill_name"  : "金阳破岭",
]),
([      "action" : "$N使出一招「六合劈」，伏身疾进，双掌自下扫向$n的$l",
        "force"  : 320,
        "attack" : 50,
        "damage" : 125,
        "dodge"  : 15,
        "lvl"    : 120,
        "damage_type" : "瘀伤",
        "skill_name"  : "六合劈",
]),
([      "action" : "$N使出一招「齐天神威」，飞身横跃，双掌前后击出，拍向$n",
        "force"  : 340,
        "attack" : 55,
        "damage" : 125,
        "dodge"  : 20,
        "lvl"    : 140,
        "damage_type" : "瘀伤",
        "skill_name"  : "齐天神威",
]),
([      "action" : "$N施展「大轮回」劲气弥漫，天空中出现无数掌影打向$n的$l",
        "force"  : 360,
        "attack" : 65,
        "dodge"  : 25,
        "damage" : 125,
        "lvl"    : 160,
        "damage_type" : "瘀伤",
        "skill_name"  : "大轮回",
]),
});

int valid_enable(string usage)
{
        return usage == "strike" || usage == "parry";
}

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练通臂六合掌必须空手。\n");

        if ((int)me->query("max_neili") < 200)
                return notify_fail("你的内力不够。\n");

        if ((int)me->query_skill("force") < 20)
                return notify_fail("你的内功火候太浅。\n");



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
        level = (int) me->query_skill("tongbi-zhang", 1);

        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level / 5)];
}

int practice_skill(object me)
{
        object weapon;

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练通臂六合掌必须空手。\n");

        if ((int)me->query("qi") < 50)
                return notify_fail("你的体力不够，练不了通臂六合掌。\n");

        if ((int)me->query("neili") < 40)
                return notify_fail("你的内力不够，练不了通臂六合掌。\n");

        me->receive_damage("qi", 35);
        me->add("neili", -30);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"tongbi-zhang/" + action;
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor, string limb)
{                                                                                                                
	int level, jiali, time,level2;
	object weapon;
        int lvl;
        int flvl;
string msg;
        lvl  = me->query_skill("guiyuan-tunafa", 1);
        flvl = me->query("jiali");

if (me->query_skill_mapped("force") == "guiyuan-tunafa" && lvl > 300 && random(8)==0)
{
                  msg = HIG"$N深吸一口气，身体如一片落叶随风飘舞,$n头一昏，不知所措!\n"NOR;

victim->start_busy(3);

                return msg;
}
}
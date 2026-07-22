//
// dashou-yin.c 密宗大手印
//
inherit SKILL;
mapping *action = ({
([      "action" : "$N使出一招「"+HIW+"莲花合掌印"+NOR+"」，双掌合十，直直撞向$n的前胸",
        "skill_name" : HIW "莲花合掌印" NOR,
        "force" : 100,
        "lvl" : 0,
        "damage_type" : "瘀伤",
]),
([      "action" : "$N使出一招「"+HIW+"合掌观音印"+NOR+"」，飞身跃起，双手如勾，抓向$n的$l",
        "skill_name" : HIW "合掌观音印" NOR,
        "force" : 200,
        "lvl" : 8,
        "damage_type" : "瘀伤",
]),
([      "action" : "$N使出一招「"+HIW+"准提佛母印"+NOR+"」，运力于指，直取$n的$l",
        "skill_name" : HIW "准提佛母印" NOR,
        "force" : 250,
        "lvl" : 16,
        "damage_type" : "瘀伤",
]),
([      "action" : "$N使出一招「"+HIW+"红阎婆罗印"+NOR+"」，怒吼一声，一掌当头拍向$n的$l",
        "skill_name" : HIW "红阎婆罗印" NOR,
        "force" : 300,
        "lvl" : 24,
        "damage_type" : "瘀伤",
]),
([      "action" : "$N使出一招「"+HIW+"药师佛根本印"+NOR+"」，猛冲向前，掌如游龙般攻向$n",
        "skill_name" : HIW "药师佛根本印" NOR,
        "force" : 350,
        "lvl" : 32,
        "damage_type" : "瘀伤",
]),
([      "action" : "$N使出一招「"+HIW+"威德金刚印"+NOR+"」，伏身疾进，双掌自下扫向$n的$l",
        "skill_name" : HIW "威德金刚印" NOR,
        "force" : 400,
        "lvl" : 40,
        "damage_type" : "瘀伤",
]),
([      "action" : "$N使出一招「"+HIW+"上乐金刚印"+NOR+"」，飞身横跃，双掌前后击出，抓向$n的咽喉",
        "skill_name" : HIW "上乐金刚印" NOR,
        "force" : 450,
        "lvl" : 48,
        "damage_type" : "瘀伤",
]),
([      "action" : "$N使出一招「"+HIW+"六臂智慧印"+NOR+"」，顿时劲气弥漫，天空中出现无数掌影打向$n的$l",
        "skill_name" : HIW "六臂智慧印" NOR,
        "force" : 500,
        "lvl" : 56,
        "damage_type" : "瘀伤",
]),
});
int practice_level(){   return 56;  }
int valid_enable(string usage) { return usage == "unarmed" || usage == "parry"; }
int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("练密宗大手印必须空手。\n");
    else if ((int)me->query("max_neili") < 150)
        return notify_fail("你的内力不够。\n");
    if (me->query_skill("unarmed", 1) <=me->query_skill("dashou-yin", 1))
        return notify_fail("你的基础不够，无法领会更高深的技巧。\n");
    if ((int)me->query_skill("longxiang", 1) >= 20 ||
        (int)me->query_skill("xiaowuxiang", 1) >= 20)
        return 1;
    else if ((int)me->query_skill("longxiang", 1) < 20)
        return notify_fail("你的龙象般若功火候太浅。\n");
    else if ((int)me->query_skill("xiaowuxiang", 1) < 20)
        return notify_fail("你的小无相功火候太浅。\n");

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
	mapping a_action;
        int i, level;
          level   = (int) me->query_skill("dashou-yin",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action = action[NewRandom(i, 20, level/5)];
			break;
		}
    a_action["dodge"]  = 0-me->query_skill("dashou-yin",1)/2;
    a_action["parry"]  = 0-me->query_skill("dashou-yin",1)/2;
    a_action["damage"] = me->query_skill("dashou-yin",1);
    return a_action;

}
int practice_skill(object me)
{
    object weapon;
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("练密宗大手印必须空手。\n");
    if ((int)me->query("qi") < 40)
        return notify_fail("你的体力不够，练不了密宗大手印。\n");
    me->receive_damage("qi", 20);
    return 1;
}

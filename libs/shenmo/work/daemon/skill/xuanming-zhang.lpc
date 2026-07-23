
// create by rcwiz 2003 for yanhuang online 

inherit SKILL;
#include <ansi.h>

mapping *action = ({
([      "action" : "$N使出一招「雪海茫茫」，双掌陡然攻出，带着丝丝阴风击向$n的$l",
        "force" : 100,
        "attack": 25,
        "dodge" : 15,
        "parry" : 20,
        "damage": 110,
        "lvl"   : 0,
        "skill_name" : "雪海茫茫",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N使出一招「幽冥寒山」，左掌护胸，右掌掌心带着极寒之气拍向$n的$l",
        "force" : 130,
        "attack": 30,
        "dodge" : 10,
        "parry" : 15,
        "damage": 120,
        "lvl"   : 30,
        "skill_name" : "幽冥寒山",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N怪叫一声，一招「阴风怒号」，双掌铺天盖地般拍向$n的$l",
        "force" : 160,
        "attack": 45,
        "dodge" : 20,
        "parry" : 20,
        "damage": 125,
        "lvl"   : 60,
        "skill_name" : "阴风怒号",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N一照「凄雨冷风」，双掌拍出满天阴风，忽然右掌悄无声息的拍向$n的$l",
        "force" : 180,
        "attack": 50,
        "dodge" : 20,
        "parry" : 30,
        "damage": 130,
        "lvl"   : 80,
        "skill_name" : "凄雨冷风",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N身形一跃，一招「亡命冰原」，左掌快若疾电般击向$n的$l",
        "force" : 210,
        "attack": 65,
        "dodge" : 25,
        "parry" : 20,
        "damage": 135,
        "lvl"   : 100,
        "skill_name" : "亡命冰原",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N阴笑一声，一招「孤山绝寒」，双掌一错，右掌忽然暴长数尺击向$n的$l",
        "force" : 280,
        "attack": 95,
        "dodge" : 25,
        "parry" : 25,
        "damage": 155,
        "lvl"   : 120,
        "skill_name" : "孤山绝寒",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N一招「雪原孤月」，身形急晃，一跃而至$n跟前，右掌带着冲天寒气击向$n的$l",
        "force" : 320,
        "attack": 110,
        "dodge" : 30,
        "parry" : 30,
        "damage": 170,
        "lvl"   : 140,
        "skill_name" : "雪原孤月",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N仰天长啸，一招「魂葬玄冥」，双掌掌风似千古不化的寒冰般扑向$n的$l",
        "force" : 360,
        "attack": 135,
        "dodge" : 30,
        "parry" : 35,
        "damage": 195,
        "lvl"   : 150,
        "skill_name" : "魂葬玄冥",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N身法陡然一变，使出一式「幽玄冥冥」，掌影千变万幻，令$n无法躲闪",
        "force" : 420,
        "attack": 150,
        "dodge" : 30,
        "parry" : 75,
        "damage": 140,
        "lvl"   : 160,
        "skill_name" : "幽玄冥冥",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N仰天一声狂啸，一式「冰坚地狱」，双掌携带着万古冰坚直直贯向$n",
        "force" : 450,
        "attack": 185,
        "dodge" : 40,
        "parry" : 80,
        "damage": 260,
        "lvl"   : 180,
        "skill_name" : "冰坚地狱",
        "damage_type" : "内伤"
])
});

int valid_enable(string usage)
{
        return usage=="strike" || usage=="parry" || usage == "unarmed";
}
int valid_combine(string combo) { return combo=="dulong-shenzhua" || combo == "diwangquan"; }
int valid_learn(object me)
{

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练玄冥神掌必须空手。\n");

        if ((int)me->query_skill("force") < 200)
                return notify_fail("你的内功火候不够，无法练习玄冥神掌。\n");

        if (me->query("con") < 28)
                return notify_fail("你先天根骨不足，无法修炼玄冥神掌。\n");
 
	if ((int)me->query_skill("shenlong-xinfa", 1) < 25)
		return notify_fail("你的神龙心法火候不够，无法学玄冥神掌.\n");

	if ((int)me->query_skill("shenlong-tuifa", 1) < 100)
		return notify_fail("你的神龙腿法火候不够，无法学玄冥神掌.\n");

        if ((int)me->query("max_neili") < 1000)
                return notify_fail("你的内力太弱，无法练习玄冥神掌。\n");

        if ((int)me->query_skill("strike", 1) < 100)
                return notify_fail("你的基本掌法火候不够，无法练玄冥神掌。\n");

        if ((int)me->query_skill("strike", 1) < (int)me->query_skill("xuanming-zhang", 1))
                return notify_fail("你的基本掌法水平有限，无法领会更高深的玄冥神掌。\n");

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
        level   = (int) me->query_skill("xuanming-zhang",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if (me->query("con") < 28)
                return notify_fail("你先天根骨不足，无法修炼玄冥神掌。\n");

	if ((int)me->query_skill("shenlong-tuifa", 1) < 100)
		return notify_fail("你的神龙腿法火候不够，无法学玄冥神掌.\n");

        if ((int)me->query("qi") < 100)
                return notify_fail("你的体力太低了。\n");

        if ((int)me->query("neili") < 100)
                return notify_fail("你的内力不够练玄冥神掌。\n");

        me->receive_damage("qi", 80);
        me->add("neili", -80);
        return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        int lvl;
        int flvl;
	int level, jiali, time,level2,damage,damage2;
	object weapon;
object target;

        level = (int) me->query_skill("shenlong-xinfa",1);
        level2= (int) me->query_skill("shenlong-xinfa",1);

damage2= (int) victim->query("neili",1)/8;
if (damage2>= 3800) damage2 = 3800;
	
if (random(8)==0 && level>=300 && me->query_skill_mapped("force") == "shenlong-xinfa")
{
	victim->apply_condition("snake_poison",15);
	victim->apply_condition("chanchu_poison",15);
	victim->apply_condition("ill_fashao",10);
	victim->apply_condition("ill_kesou",10);
	victim->apply_condition("ill_shanghan",10);
	victim->apply_condition("ill_zhongshu",10);
	victim->apply_condition("ill_dongshang",10);
 victim->apply_condition("xuanming_poison",10);
if (!victim->is_busy()) victim->start_busy(2);	
 return HIR "$N高声狂叫：战无不胜，攻无不克，无坚不摧，无敌不破！$n头一晕,鲜血喷出!\n";
}
        lvl  = me->query_skill("xuanming-zhang", 1);
        flvl = me->query("jiali");
        if (lvl < 100 || ! damage_bonus ||
            me->query_skill_mapped("force") != "shenlong-xinfa" ||
            me->query("neili") < 300)
                return;

        if (random(5)==0)
        {
if (victim->query("qi") > 500)
victim->add("qi",-250);
victim->add("eff_qi",-(50+random(200)));
                victim->apply_condition("xuanming_poison",20);
                victim->start_busy(3);
                me->add("neili", -20);
                return HIW "$n" HIW "忽然感到一股莫名的恶心，阴寒的冷气攻心，全身瘫软，嘴皮乌紫。\n" NOR;
        }
}

string perform_action_file(string action)
{
        return __DIR__"xuanming-zhang/" + action;
}


// tianchang-zhang.c 天长掌法
// modified by Venus Oct.1997

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" : "$N使出倚天屠龙掌中的一式"+HIY"『武林至尊』"NOR+"，一笔"
                   "一划，暗含内劲，击向$n的$l",
        "force" : 110,
        "dodge" : 5,
        "parry" : 7,
        "damage": 116,
        "damage_type" : "内伤",
        "lvl" : 0,
        "skill_name" : "武林至尊"
]),
([      "action" : "$N使出倚天屠龙掌中的一式"+HIY"『宝刀屠龙』"NOR+"，“龙"
                   "”字笔划甚多，笔划多的不觉其繁，击向$n的$l",
        "force" : 148,
        "dodge" : 15,
        "parry" : 27,
        "damage": 115,
        "damage_type" : "内伤",
        "lvl" : 30,
        "skill_name" : "宝刀屠龙"
]),
([      "action" : "$N使出倚天屠龙掌中的一式"+HIY"『号令天下』"NOR+"，“下"
                   "”字笔划甚少，笔划少的不见其陋，击向$n的$l",
        "force" : 195,
        "dodge" : 22,
        "parry" : 33,
        "damage": 119,
        "damage_type" : "内伤",
        "lvl" : 50,
        "skill_name" : "号令天下"
]),
([      "action" : "$N使出倚天屠龙掌中的一式"+HIY"『莫敢不从』"NOR+"，其缩"
                   "也凝重，似尺蠖之屈，其纵也险劲，如狡兔之脱，击\n向$n的$l",
        "force" : 245,
        "dodge" : 32,
        "parry" : 41,
        "damage": 123,
        "damage_type" : "内伤",
        "lvl" : 80,
        "skill_name" : "莫敢不从"
]),
([      "action" : "$N使出倚天屠龙掌中的一式"+HIY"『倚天不出』"NOR+"，淋漓"
                   "酣畅，雄浑刚健，俊逸处如风飘，如雪舞，厚重处如\n虎蹲，"
                   "如象步，击向$n的$l",
        "force" : 280,
        "dodge" : 37,
        "parry" : 46,
        "damage": 129,
        "damage_type" : "内伤",
        "lvl" : 120,
        "skill_name" : "倚天不出"
]),
([      "action" : "$N使出倚天屠龙掌中的一式"+HIY"『谁与争锋』"NOR+"，长啸"
                   "一声，右掌直划下来，当真是星剑光芒，如矢应机，\n霆不暇"
                   "发，电不及飞，这一直乃是“锋”字的最后一笔，直劈向$n的$l",
        "force" : 330,
        "dodge" : 45,
        "parry" : 57,
        "damage": 136,
        "damage_type" : "内伤",
        "lvl" : 160,
        "skill_name" : "谁与争锋"
]),
});

int valid_enable(string usage) { return usage == "strike" ||  usage == "parry"; }  

int valid_combine(string combo) { return combo == "paiyun-shou"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练倚天屠龙掌必须空手。\n");

        if ((int)me->query_skill("force") < 120)
                return notify_fail("你的内功火候不够，无法练倚天屠龙掌。\n");
        
        if ((int)me->query("max_neili") < 750)
                return notify_fail("你的内力太弱，无法练倚天屠龙掌。\n");

        if ((int)me->query_skill("strike", 1) < 80)
                return notify_fail("你的基本掌法火候不够，无法练习倚天屠龙掌。\n");

        if ((int)me->query_skill("strike", 1) < (int)me->query_skill("yitian-zhang", 1))
                return notify_fail("你的基本掌法水平有限，无法领会更高深的倚天屠龙掌。\n");

        return 1;
}

string query_skill_name(int level)
{
        int i;
        for (i = sizeof(action)-1; i >= 0; i--)
                if (level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int)me->query_skill("yitian-zhang", 1);
        for (i = sizeof(action); i > 0; i--)
                if (level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 70)
                return notify_fail("你的体力太低了。\n");

        if ((int)me->query("neili") < 70)
                return notify_fail("你的内力不够练倚天屠龙掌。\n");

        if ((int)me->query_skill("taiji-quan", 1) < 30)
                return notify_fail("你的「太极拳」火候太浅。\n");

        if ((int)me->query_skill("wudang-mianzhang", 1) < 30)
                return notify_fail("你的武当绵掌火候太浅。\n");

        me->receive_damage("qi", 55);
                me->add("neili", -62);

        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"yitian-zhang/" + action;
}



mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        int lev,damage, i;
        object weap;
        int level, jiali, time,level2;
        object weapon;
        int lvl;
        int flvl;
string msg;
        lvl  = me->query_skill("taiji-shengong", 1);
        flvl = me->query("jiali");

        weap = victim->query_temp("weapon");
        lev =me->query("yitian-zhang");
	if( damage_bonus < 20 ) return 0;
	if( damage_bonus/2+20  > victim->query_str() || random(6)==0) {
if(me->query_skill("taiji-shengong", 1) > 10 && random(3) == 1)
{
		victim->receive_wound("qi", (damage_bonus ) +20 );
		return HIC "倚天式! "+ victim->name()+"但觉一股劲风袭至胸口.结结实实吐出一口鲜血。\n" NOR;
}
}      

 
       
}


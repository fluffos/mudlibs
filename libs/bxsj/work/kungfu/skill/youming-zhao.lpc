// youming-zhao.c 幽冥鬼爪

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([     "action" : "$N左爪前伸，带着丝丝蓝阴鬼气，一式"RED"「元神出窍」"NOR"，猛得向$n的顶门插下",
       "force" : 150,
       "damage" : 30,
       "dodge" : 5,
       "lvl" : 0,
       "weapon" : "五指",
       "damage_type" : "抓伤"
]),
([     "action" : "$N双掌连拍，筑起一道气墙推向$n，忽然一爪"RED"「鬼魅穿心」"NOR"冲破气墙直插$n的$l",
       "force" : 160,
       "dodge" : 10,
       "damage": 30,
       "lvl" : 0,
       "weapon" : "指尖",
       "damage_type" : "刺伤"
]),
([     "action" : "$N使出"RED"「血鬼锁」"NOR"双爪游向$n扣住$l，气劲激发往左右两下一拉，便要将$n割成碎片",
       "force" : 170,
       "dodge" : 0,
       "damage": 40,
       "lvl" : 20,
       "weapon" : "指甲",
       "damage_type" : "割伤"
]),
([     "action" : "$N双爪拢住$n，使一式"BLU"「炼狱鬼嚎」"NOR"，阴毒内功随爪尖透入$n体内，直袭各大关节",
       "force" : 180,
       "dodge" : 5,
       "damage": 60,
       "lvl" : 30,
       "damage_type" : "内伤"
]),
([     "action" : "$N力透指尖，向$n虚虚实实连抓十五爪，"BLU"「妖风袭体」"NOR"带动无数阴气缠住$n",
       "force" : 200,
       "dodge" : 15,
       "damage": 60,
       "weapon" : "阴风",
       "lvl" : 40,
       "damage_type" : "拉伤"
]),
([     "action" : "$N一式"RED"「索命妖手」"NOR"，左爪上下翻动形成无数爪影，右臂一伸，鬼魅般抓向$n的$l",
       "force" : 260,
       "dodge" : 5,
       "damage": 70,
       "weapon" : "右抓",
       "lvl" : 50,
       "damage_type" : "抓伤"
]),
([     "action" : "$N探手上前，顺着$n的手臂攀缘直上，变手为爪，一招"RED"「孤魂驭魔」"NOR"抓向$n的$l",
       "force" : 300,
       "dodge" : 5,
       "damage": 70,
       "lvl" : 70,
       "weapon" : "五爪",
       "damage_type" : "抓伤"
]),
([     "action" : "$N凌空飞落，一爪突前，"BLU"「魔爪天下」"NOR"积聚全身功力于指尖，快绝无比地插向$n",
       "force" : 350,
       "dodge" : 10,
       "damage": 80,
       "lvl" : 90,
       "weapon" : "手爪",
       "damage_type" : "刺伤"
])
});

int valid_enable(string usage) { return usage=="claw" || usage=="parry"; }

int valid_learn(object me)
{
       if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
               return notify_fail("练爪功必须空手。\n");
       if ((int)me->query_skill("claw", 1) < 50)
               return notify_fail("你的基本爪功火候不够，无法学习。\n");
       if ((int)me->query("max_neili") < 1000)
               return notify_fail("你的内力太弱，无法练鬼爪功。\n");
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
       level   = (int) me->query_skill("youming-zhao",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
       if ((int)me->query("jingli") < 30)
               return notify_fail("你的体力太低了。\n");
       if ((int)me->query("neili") < 20)
               return notify_fail("你的内力不够练幽冥鬼爪。\n");
       me->receive_damage("jingli", 30);
       me->add("neili", -10);
       return 1;
}

string perform_action_file(string action)
{
        return __DIR__"youming-zhao/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{                
   if(me->query_temp("幽冥") && !me->query_temp("youming_hit")) {
        me->set_temp("youming_hit", 1);
        me->set_temp("apply/name", ({ me->query("name")+"的"HIB"鬼魂"NOR }));
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), 1);       
        me->delete_temp("apply/name");
        me->delete_temp("youming_hit");
        }
}


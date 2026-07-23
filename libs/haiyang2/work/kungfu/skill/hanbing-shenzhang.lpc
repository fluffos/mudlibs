// hanbing-shenzhang.c  寒冰神掌
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" : "却见$N右掌一缩，竟以左手单掌抵御对方掌力，接着运寒冰真气于右手，伸出食中二指向$n$l戳去",
        "force" : 300,
        "dodge" : 10,
        "damage" : 250,
        "damage_type" : "刺伤",
        "lvl" : 0,
]),
([      "action" : "$N竖掌挡开$n，左掌加运内劲，向$p背心直击而下，这一掌居高临下，夹杂寒风，势道奇劲",
        "force" : 350,
        "dodge" : 5,
        "damage" : 250,
        "damage_type" : "瘀伤",
        "lvl" : 10,
]),
([      "action" : "$N手腕一翻，左右两掌分别拍出，形态仿似太极拳的十字手，可随即跟来的却是两道阴冷的寒气",
        "force" : 310,
        "dodge" : 20,
        "damage" : 250,
        "damage_type" : "内伤",
        "lvl" : 30,
]),
([      "action" : "$N看似全然处于下风，双臂出招极短，攻不到一尺便即缩回，显似只守不攻，但突然右掌一伸，拍向$n",
        "force" : 400,
        "dodge" : 5,
        "damage" : 250,
        "damage_type" : "瘀伤",
        "lvl" : 50,
]),
([      "action" : "$N右手连指三指，逼得$n连退三步，接着无名指弹$p手腕，右手一抬，猛然按向$p$l，劲力阴冷狠辣",
        "force" : 450,
        "dodge" : 10,
        "damage_type" : "瘀伤",
        "damage" : 250,
        "lvl" : 70,
]),

});

int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练寒冰神掌必须空手。\n");
        if ((int)me->query_skill("songshan-qigong", 1) < 140)
                return notify_fail("你的嵩山气功火候不够，无法学寒冰神掌。\n");
        if ((int)me->query_skill("songyang-zhang", 1) < 140)
                return notify_fail("你的大嵩阳掌火候不够，无法学寒冰神掌。\n");
        if ((int)me->query("max_neili") < 2000)
                return notify_fail("你的内力太弱，无法练寒冰神掌。\n");
        return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}
int valid_combine(string combo) { return combo=="songyang-shou"; }
mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int)me->query_skill("hanbing-shenzhang", 1);
        if (me->query_temp("ss_feiwu") == 2){
            return([      
                   "action": HIW "紧接着$N"HIW"右手一放一收，在$n"HIW"还没有反应过来时飞身欺前，运起「寒冰真气」翻腕就是一掌」！"NOR,        
                   "force" : 480,
                   "dodge" : 40,
        "damage" : 650,
                   "damage_type" : "瘀伤",
                   ]);
            }
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        int lvl = me->query_skill("hanbing-shenzhang", 1);
        int i = sizeof(action);
        while (i--) if (lvl == action[i]["lvl"]) return 0;
        
        if ((int)me->query("jing") < 70)
                return notify_fail("你的精力太低了。\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("你的内力不够练寒冰神掌。\n");
        me->receive_damage("jing", 50);
        me->receive_damage("neili", 10);
        if(me->query_skill("hanbing-shenzhang", 1) > 160)
                me->receive_damage("jing", 10);
        if(me->query_skill("hanbing-shenzhang", 1) > 190)
                me->receive_damage("neili", 5);
        return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        if( random(me->query_skill("hanbing-shenzhang")) > 45) {
                  victim->apply_condition("cold_poison", random(3) + 2 +
                        victim->query_condition("cold_poison"));
        }
        if (me->query_temp("ss_feiwu"))
                  victim->apply_condition("cold_poison", 30 +
                        victim->query_condition("cold_poison"));
}

string perform_action_file(string action)
{
	return __DIR__"hanbing-shenzhang/" + action;
}


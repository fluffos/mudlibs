inherit SKILL;
#include <ansi.h>
mapping *action = ({
([      "action" : "$n身形一立，不慌不忙的一招「"HIM"凤"HIY"舞"HIC"九天"NOR"」，在原地弹地而起。\n",
        "dodge"  : 50,
]),
([      "action" : "$n一招「"WHT"扑朔"MAG"迷离"NOR"」，$N只觉眼前$n的身影顿时化作了五六个，不知如何是好。\n",
        "dodge"  : 50,
]),
([      "action" :  "$n一招「"HIB"风雨"HIR"飘摇"NOR"」，身形微晃，有惊无险地避开了$N这一招。\n",
        "dodge"  : 100,
]),
([      "action" : "只见$n身子向前一纵，一招「"HIY"兔起"HIG"凫举"NOR"」，猛的从$N头上飞过。\n" ,
        "dodge"  : 100,
]),
([      "action" : "$n一招「"MAG"腾"BLINK HIY"蛟"NOR HIG"起"HIM BLINK"凤"NOR"」，如鬼魂般飘向空中,$N的攻势立刻荡然无存。\n",
        "dodge"  : 150,
]),
([      "action" : "却见$n一式「"HIR"烘"HIC"云"YEL"托"HIB"月"NOR"」，冲天而起，身影布满整个天空，使得$N无可奈何。\n",
        "dodge"  : 200,
]),
([      "action" : ""HIG"只见天空一黑，$n飘然使出"HIR"究级式"HIG"「"HIW""BLINK"镜花水月"NOR""HIG"」，$N"HIG"的攻击全都打在了$n的"HIB""BLINK"幻影"NOR""HIG"上，这突然的变化惊得$N"HIG"目瞪口呆。"NOR"\n",
        "dodge"  : 300,
])
});
int practice_skill(object me)
{
        if( (int)me->query("qi") < 45 )
                return notify_fail("你的体力太差了，不能练镜花水月步。\n");
        me->receive_damage("qi", 35);
        return 1;
}

mapping query_action(object me, object weapon)
{
        int zhaoshu, level;
        zhaoshu = sizeof(action);
/*
        if ( random(me->query_skill("dodge")) > 450 &&
            me->query_skill("force") > 150 &&
            me->query("neili") > 50 ) {
            me->add("neili",-5);
            return (["action" :  
""HIG"只见天空一黑，$n飘然使出"HIR"究级式"HIG"「"HIW""BLINK"镜花水月"NOR""HIG"」，$N"HIG"的攻击全都打在了$n的"HIB""BLINK"幻影"NOR""HIG"上，这突然的变化惊得$N"HIG"目瞪口呆。"NOR"\n",
        "dodge"  : 600
                          ]); 
            }
*/
        return action[random(zhaoshu)];
}
int valid_enable(string usage) { return (usage == "dodge") || (usage == "move"); }

int valid_learn(object me) { return 1; }

string query_dodge_msg(string limb)
{
        object me, ob;
        mapping action;

        me = this_player();
        action = query_action(me, ob);

        return action["action"];
}


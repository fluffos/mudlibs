// zfwy-bu.c （追风无影步）

#include <ansi.h>
#include <skill.h>

inherit SKILL;

mapping *action = ({
([      "action" : "$n一式「越影追风」，在剌剌风声中，从$N头顶横跃而过。\n",
        "dodge"  : 10
]),
([      "action" : "$n一式「随风而至」，如一阵清风，舒缓地闪过了$N的凌厉攻势。\n",
        "dodge"  : 20
]),
([      "action" : "$n一式「无形无影」，轻盈地一跃，便消失在$N的眼前。\n",
        "dodge"  : 30
]),
([      "action" : "$n一式「随风而逝」，一眨眼间，身形向后飘出，离开了$N的视线。\n",
        "dodge"  : 40
]),
([      "action" : "$n一式「风起云涌」，身法陡然加快，在$N四周飘忽不定。\n",
        "dodge"  : 50
]),
([      "action" : "$n一式「分身化影」，立时在$N周围形成了无数幻影，令$N真假难辨！\n",
        "dodge"  : 60
]),
([      "action" : "$n一式「风驰电掣」，双脚点地，全身一道闪电，急速绕着$N飞奔。\n",
        "dodge"  : 70
]),
([      "action" : "$n一式「乘风弄影」，身形陡地随风摇摆，好似全无章法，令$N无从下手。\n",
        "dodge"  : 80
]),
});

mapping query_action(object me, object weapon)
{
        int zhaoshu, level;

        zhaoshu = sizeof(action);
        level   = (int) me->query_skill("zfwy-bu");

        if (level < 80 )
                zhaoshu--;

        if (level < 60 )
                zhaoshu--;

        if (level < 40 )
                zhaoshu--;
        
        if (random(me->query_skill("dodge")) > 100 &&
            me->query_skill("force") > 60 &&
            me->query("neili") > 30) {
            me->add("neili",-5);
            return (["action" : WHT"$n陡然使出「追风无影步」的终极境界「追风无影」，如鬼魅一般消失，使$N大吃一惊！\n"NOR,
                     "dodge"  : 200
                          ]); 
            }
        return action[random(zhaoshu)];
}

int valid_enable(string usage)
{
        return usage == "dodge" || usage == "move";
}

int valid_learn(object me)
{
        if ((int)me->query_skill("dodge", 1) < 20)
                return notify_fail("你的基本轻功火候不够，无法学「追风无影步」。\n");
        if ((int)me->query_skill("zhenfen-xinfa", 1) < 20)
                return notify_fail("你的「震风心法」火候不够，无法学「追风无影步」。\n");
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力太弱，无法练「追风无影步」。\n");
        return 1;
}

string query_dodge_msg(string limb)
{
        int i, level;
        object me, ob;
        mapping action;

        me = this_player();

        action = query_action(me, ob);

        return action["action"];
}

int practice_skill(object me)
{
        if( (int)me->query("qi") < 40 )
                return notify_fail("你的体力太差了，不能练「追风无影步」。\n");
        me->receive_damage("qi", 30);
        return 1;
}

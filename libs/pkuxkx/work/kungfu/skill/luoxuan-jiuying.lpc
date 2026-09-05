// 螺旋九影
// written by Zine

inherit SKILL;

string *dodge_msg = ({
	"$n如同鬼魅一般，让$N的招式完全落空。\n",
	"$n身形变淡，$N的凌厉攻势完全没有着力之处。\n",
	"$n身形疾转，向一旁窜出，$N完全不知所谓。\n"
        "但是$n身形飘忽，幻作九个身影，真人已不知去向。\n",
       "$n身随意转，贴着地面挪开了一丈，避过了这一招。\n",
        "可是$n左右晃动一下，$N这一招扑了个空。\n",
//        "却见$n足不点地，往旁窜开数尺，躲了开去。\n",
//        "$n身形微晃，有惊无险地避开了$N这一招。\n"
});

int valid_enable(string usage) { return (usage == "dodge"); }

int valid_learn(object me) { return 1; }

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("neili") < 40 )
                return notify_fail("你的内力太低了，不能练螺旋九影。\n");
        if( (int)me->query("qi") < 40 )
                return notify_fail("你的体力太差了，不能练螺旋九影。\n");
        me->receive_damage("qi", 10);
        me->add("neili", -10);
        if ((int)me->query_skill("luoxuan-jiuying",1)>1000)
        {
            me->add("neili", -10);
        }
        return 1;
}

string perform_action_file(string action)
   {     return __DIR__"luoxuan-jiuying/" + action;
 }


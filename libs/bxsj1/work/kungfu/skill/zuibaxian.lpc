// zui-baxian.c 醉八仙

inherit SKILL;

string *dodge_msg = ({
"$n忽然「咯」的一声喷出口酒气，刚巧腹部一缩，躲过了$N这一招。\n",
"$n醉眼朦胧，右脚一软，顺势倒入$N的怀里，$N的凌厉攻势一下全部打空。\n",
"$n双眼似睁似闭，顺着$N的招式一个举杯饮酒，全身自膝盖向后平平倒了下去。\n",
"但是$n喝醉了似的身子向后一倒，右脚却直踢而上，将$N逼了开去。\n",
"$n双腿无力，脚下一软坐倒在地，身形顿时矮半截，刚好逼过了$N的招式。\n",
"可是$n摇摇摆摆地乱走了几步，脚下不丁不八却已经转到了$N的身后。\n",
"却见$n左脚踩在自己右脚上一拌，身子向右歪去，刚巧躲过了$N的攻击。\n",
"$n满脸醉相，信步往左一踏，有惊无险地避开了$N这一招。\n"
});

int valid_enable(string usage) 
{ 
    return (usage == "dodge") || (usage == "move"); 
}

int valid_learn(object me) { return 1; }

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("jingli") < 40 )
                return notify_fail("你的体力太差了，不能练醉八仙。\n");
        me->receive_damage("jingli", 30);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"zuibaxian/" + action;
}
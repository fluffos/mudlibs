#include <ansi.h>

inherit SKILL;
mapping *action = ({
([      "action" : HIB"$n身形微晃已窜出，左足一点，“银鞍照白马，疯沓如流星”，恰似天马行空，
潇洒自如地闪过了$N这一招。\n"NOR,
        "dodge"  : 100
]),
([      "action" : HIG"可是就在这一刹那间，$N失去了$n的踪影，正在疑惑时，身后传来$n
的声音：“事了拂衣去，深藏身与名。”\n"NOR,
        "dodge"  : 150
]),
([      "action" : HIR"$n展开轻功，一招“将炙啖朱亥，持觞劝侯嬴”，不退反进，欺近$N三尺之内，
正当$N慌忙变招近守之时，却又一个跟头倒翻出去。\n"NOR,
        "dodge"  : 200
]),
([      "action" : HIW"$n微微一笑，突然开始围绕$N快速转圈，正是一式“眼花耳热后，意气素霓生”，
$N被$n绕得晕头转向，不由得停止了攻击。\n"NOR,
        "dodge"  : 300
]),
});
mapping query_action(object me, object weapon)
{
        int zhaoshu, level;
        zhaoshu = sizeof(action);
        level   = (int) me->query_skill("xiake-shenfa");
        if (level < 100 )
                zhaoshu--;
        if (level < 80 )
                zhaoshu--;
        if (level < 50 )
                zhaoshu--;
        return action[random(zhaoshu)];
}
int valid_enable(string usage)
{
        return usage == "dodge" || usage == "move";
}
int valid_learn(object me)
{
        return 1;
}

int practice_skill(object me)
{
        if( (int)me->query("qi") < 100 )
                return notify_fail("你的体力太差了，不能练侠客身法。\n");
        me->receive_damage("qi", 100);
        return 1;
}

string query_dodge_msg(string limb)
{
        object me, ob;
        mapping action;
        me = this_player();
        action = query_action(me, ob);
        return action["action"];
}

string query_yinyang()
{
	return "少阳";
}
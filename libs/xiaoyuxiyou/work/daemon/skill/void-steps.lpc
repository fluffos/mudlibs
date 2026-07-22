//凌空虚渡
//ephq
#include <ansi.h>

inherit SKILL;

string *dodge_msg = ({
        WHT"但是$n"NOR+WHT"身形一转，使出"HIW"「麝熏微度」"NOR+WHT"，蓦地不见，避开了这一招。\n"NOR,
        WHT"$n"NOR+WHT"使出"HIW"「洛河清波」"NOR+WHT"，犹如在水面滑行一般，身形晃了开去。\n"NOR,
        WHT"可是$n"NOR+WHT"的身影飘飘渺渺，竟丝毫不着力，是一式"HIW"「蓬山万重」"NOR+WHT"的身法。\n"NOR,
        WHT"$n"NOR+WHT"一式"HIW"「幻眼云烟」"NOR+WHT"，身形陡地变得飘忽不定，令$N"NOR+WHT"无法看清。\n"NOR,
                WHT"$n"NOR+WHT"一式"HIW"「寒江钓雪」"NOR+WHT"，不招不架，只微微一侧身，$N"NOR+WHT"犹如暴风骤雨般的进攻便即落空。\n"NOR,
        WHT"$n"NOR+WHT"一式"HIW"「烟雨飘渺」"NOR+WHT"，身体急转，化为一道白光，虚幻不定的出现在$N"NOR+WHT"的周围。\n"NOR,
        WHT"$n"NOR+WHT"一式"HIW"「移行幻影」"NOR+WHT"，身行一晃，顿时无数条身影一下子出现在$N"NOR+WHT"的面前。\n"NOR,
                WHT"$n"NOR+WHT"左足一点，一招"HIW"「逐影天枢」"NOR+WHT"腾空而起，避了开去。\n"NOR
});

int valid_enable(string usage)
{
        return usage == "dodge";
}

int valid_learn(object me) { return 1; }

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 35 )
                return notify_fail("你的体力太差了，不能练习凌空虚渡。\n");
        me->receive_damage("kee", 25);
        return 1;
}

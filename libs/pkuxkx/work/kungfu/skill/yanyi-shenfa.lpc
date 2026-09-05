// yanyi-shenfa 雁翼身法
// for 雪山派
// kiden
#include <ansi.h>
inherit SKILL;
string *dodge_msg = ({
        WHT"$n"WHT"足尖着地，行进轻快无比，恍似乘风在冰上滑行一般。\n"NOR,
        MAG"$n"MAG"凌空跃起，如大鹏展翅，以泰山压顶之势逼退了$N"MAG"这一招。\n"NOR,
        WHT"却见$n"WHT"展身平掠，有如大雁滑翔，穿身跃到$N"WHT"身后。\n"NOR,
        MAG"$n"MAG"几个起落，便如飞鸟急逝，远远跳出了$N"MAG"的攻击圈子。\n"NOR,
        });
int valid_enable(string usage) { return (usage == "dodge");}
int valid_learn(object me) {return 1;}
string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}
int practice_skill(object me)
{       
               if( (int)me->query("qi") < 40 )
                return notify_fail("你的体力太差了。\n");
        me->receive_damage("qi", 25);
        return 1;
}


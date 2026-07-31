inherit SKILL;
#include <ansi.h>
string *dodge_msg = ({
        "$n身形晃动，使出一招"HIM" 出有入无 "NOR"，似左实右，忽前忽后，若有若无的闪过$N的攻击。\n",
        "$n突然身子一缩，一招"HIB"藏形匿迹"NOR"，人已在三尺之外。\n",
        "可是$n一招"HIR" 飞灵八方 "NOR"猛然纵起丈余，身形晃动，躲过了$N的攻势。\n",
        "只见$n左走三步，又向右斜跨两步，一招"HIW" 隐景舞天 "NOR"，不知怎的$n已经到了$N的身后。\n",
        "$n不住倒退，忽然身形晃动，一招"RED" 解行遁变 "NOR"转到了$N的身侧。\n",
        "$n身随意走，一招"YEL" 弃厄飞霄 "NOR"躲过了$N的凌厉攻势。\n",
        "$n脚下一点，一招"HIY" 回神转玄 "NOR"斜斜的飞出恰巧躲开了$N的进攻。\n",
        "$n一招"MAG" 乘虚御空 "NOR"侧身一让，$N这招扑了个空。\n",
});

int valid_enable(string usage) { return (usage == "dodge") ;}

int valid_learn(object me) { return 1; }

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("qi") < 40 )
                return notify_fail("你的体力太差了，不能练金雁功。\n");
        me->receive_damage("qi", 30);
        return 1;
}



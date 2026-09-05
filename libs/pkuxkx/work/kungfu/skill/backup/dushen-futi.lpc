// 毒神附体 Zine for XX大招
#include <ansi.h>
inherit SKILL;

int valid_enable(string usage)
{
	return usage == "parry";
} 


int valid_learn(object me)
{
	return notify_fail("毒神附体无法通过别人请教学得。\n");
}

int valid_study(object me)
{
	if (me->query("family/family_name") != "星宿派")
	return notify_fail("毒神附体只有星宿派弟子才能学得。\n");
    if (me->query_skill("poison",1)<350)
    return notify_fail("你对于基本毒技的掌握还不到家，无法学习毒神附体。\n");
	return 1;

}

int practice_skill(object me)
{
	return notify_fail("『毒神附体』只能通过读书(study)来增加熟练度。\n");
}
string *parry_msg = ({
       BLU"只见$n将手中$v上下舞动，将$N的$w格了开去。\n",
       BLU"$n将手中$v舞成风车一般，滴水不漏。\n"NOR,
});

string *unarmed_parry_msg = ({
       HIB"但是$n不管不顾，$N不知虚实，停止了进攻。\n",
       HIB"$n大喝一声，硬挨$N的招式，却似乎无伤大雅。\n"NOR,
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

string perform_action_file(string action)
{
          return __DIR__"dushen-futi/" + action;
}

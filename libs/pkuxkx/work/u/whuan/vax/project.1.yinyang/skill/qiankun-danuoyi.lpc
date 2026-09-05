// shenghuolin.c
// Writed by yuer
#include <ansi.h>
inherit SKILL;

int valid_enable(string usage)
{
	return usage == "parry";
} 


int valid_learn(object me)
{
	int i, nb, nf, nh, ns, ts;
	nb = (int)me->query_skill("jiuyang-shengong", 1);
	nf = (int)me->query_skill("force", 1);
	nh = (int)me->query_skill("qiankun-danuoyi", 1);

     if ( nb < 100 || nb <= (nh-20) )
		return notify_fail("你的九阳神功修为不够，无法领会更高深的乾坤大挪移心法。\n");

	if ( nf < 80)
		return notify_fail("你的基本内功火候还不够，无法领会乾坤大挪移心法。\n");


	return 1;
}



int practice_skill(object me)
{
	return notify_fail("乾坤大挪移心法只能用学习(learn)或读书(study)来增加熟练度。\n");
}
string *parry_msg = ({
       GRN"只见$n将手中$v左一带，右一带，轻轻的将$N的$w各了开去。\n",
       GRN"$n用手中$v在$N的$w上轻轻一搭，\n$N的$w就如着了魔法一般，荡了开去。\n"NOR,
});

string *unarmed_parry_msg = ({
       GRN"但是$n用左手轻轻一推$N的$w，\n$N的$w就如着了魔法一般，荡了开去。\n",
       GRN"$n左手轻轻推出，拍向$N的$w，$N的攻击被移的无影无踪。\n"NOR,
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

string query_yinyang()
{
	return "纯阳";
}


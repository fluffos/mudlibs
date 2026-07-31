// dragonmedicine 神龙药理学

#include <ansi.h>

inherit SKILL;

int valid_enable(string usage) { return (usage == "poison"); }
int valid_learn(object me)
{
    if ((int)me->query_skill("literate", 1) < 50)
               return notify_fail("你的读书识字能力还不够。\n");   
        if( me->query_skill("shenlong-yaoli", 1 ) >= 200 ) 
              return notify_fail("你不能再提高神龙药理的等级了。\n");
    return 1;
}

int practice_skill(object me)
{
	return notify_fail("神龙药理学只能用学(learn)方法的来增加熟练度。\n");
}

/*string perform_action_file(string action)
{
       return __DIR__"lingshe-bianfa/" + action;
}*/

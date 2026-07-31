// tianmogong.c 天魔功

inherit FORCE;
#include "force.h"
int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
                if ( userp(me) )
                return notify_fail("学天魔功，要心狠手辣，奸恶歹毒，你可做得不够呀！\n");
        return 1;
}

int practice_skill(object me)
{
        return notify_fail("天魔功只能用学(learn)的来增加熟练度。\n");
}
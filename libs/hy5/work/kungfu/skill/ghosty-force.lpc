// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <ansi.h>
inherit FORCE;
int valid_enable(string usage) { return usage=="force"; }
int valid_learn(object me) { return 1; }
int practice_skill(object me)
{
        return 
notify_fail("无坎真阴只能用学的，或是从运用(exert)中增加熟练度。\n");
}

string exert_function_file(string func)
{
           return __DIR__"ghosty-force/" + func;
}
 
int effective_level() { return 10;}

int learn_bonus()
{
	return -110;
}
int practice_bonus()
{
	return -110;
}
int black_white_ness()
{
	return -20;
}


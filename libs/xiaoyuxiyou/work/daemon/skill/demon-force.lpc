// Demon-force.c 天魔心法
// Cracked by 凌惊雪 4-13-2003

inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me)
{

        if ( (int)me->query_skill("force", 1) < 200)
                  return notify_fail("你的基本内功火候还不够，无法领会天魔心法。(200级)\n");
        return 1;
}


int practice_skill(object me)
{
        return
	notify_fail("天魔心法只能向师父学，或是从运用(exert)中增加熟练度。\n");
}
string exert_function_file(string func)
{
        return CLASS_D("tianmo") + "/demon-force/" + func;
}



// renshu.c 忍术
// By snowman@SJ 25/01/2000

inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me)
{
	return notify_fail("NPC武功，不对玩家开放。\n");
}

string exert_function_file(string func)
{
    return __DIR__"renshu/" + func;
}
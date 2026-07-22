// huashan-neigong.c 华山内功
// Modified by Venus Oct.1997

inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
// need more limit here
{
    int i = (int)me->query_skill("huashan-neigong", 1);
    if ((int)me->query_skill("zixia-shengong", 1) < 10)
   return notify_fail("你的紫霞神功火候还不够。\n");
//    if ((int)me->query("shen") < (int)pow(i/10, 2) * 100)
//   return notify_fail("你的神太低了。\n");
    return 1;
}

int practice_skill(object me)
{
    return notify_fail("华山气功只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
    return SKILL_D(__DIR__"huashan-neigong/") + func;
}


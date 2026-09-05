// beiming-shengong 北冥神功
// by paladin
inherit FORCE;
int valid_enable(string usage) { return usage == "force"; }
int valid_learn(object me)
{
        int i = (int)me->query_skill("beiming-shengong", 1);
        int t = 1, j;
        for (j = 1; j < i / 10; j++) t*= 2;
        if ((int)me->query_skill("force", 1) < 10)
                return notify_fail("你的基本内功火候不足，不能学北冥神功。\n");
        if (i > 10 && (int)me->query("int", 1) < 35)
                return notify_fail("你的悟性不够高，学不了北冥神功. \n");

        if ( me->query_skill("hunyuan-yiqi",1)
        || me->query_skill("huntian-qigong",1)
        || me->query_skill("jiuyang-shengong",1)
        || me->query_skill("taiji-shengong",1) )
                return notify_fail("你不先散了别派内功，怎能学北冥神功？！\n");
        return 1;
}
int practice_skill(object me)
{
        return notify_fail("北冥神功只能用学(learn)的来增加熟练度。\n");
}
string exert_function_file(string func)
{
        return __DIR__"beiming-shengong/" + func;
}

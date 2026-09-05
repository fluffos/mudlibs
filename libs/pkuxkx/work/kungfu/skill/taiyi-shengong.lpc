//taiyi-shengong.c      太乙神功
//desighed for newbie training
//by zoom
//2003.4.6
//Modified by iszt@pkuxkx, 2007-04-02, allowed level 100
// 2009.8.17 finished by zgbl , edited exert heal/lifeheal/powerup , added new exert yangjing

inherit FORCE;

int valid_enable(string usage)
{
        return usage == "force";
}

int valid_learn(object me)
{
        if ((int)me->query_skill("force", 1) < 5)
                return notify_fail("你的基本内功火候不足，不能学太乙神功。\n");
	if ((int)me->query("family"))
		return notify_fail("往矣，非曳尾涂中之士，如何领悟太乙正道？\n");
    if (me->query("chushi"))
  		return notify_fail("往矣，非曳尾涂中之士，如何领悟太乙正道？\n");
    if (me->query("betrayer") > 0)
		return notify_fail("往矣，非曳尾涂中之士，如何领悟太乙正道？\n");
	if (me->query_skill("hunyuan-yiqi",1) > 0)
		return notify_fail("往矣，非曳尾涂中之士，如何领悟太乙正道？\n");
//有门派或者有过门派都无法学习，纯百姓技能
        return 1;
}

int practice_skill(object me)
{
        return notify_fail("太乙神功只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
        return __DIR__"taiyi-shengong/" + func;
}

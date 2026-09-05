inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
	int i = (int)me->query_skill("xiaowuxiang-gong", 1);
	int t = 1, j;

	for (j = 1; j < i / 10; j++) t*= 2;


       if (((int)me->query_skill("duzun-xinfa", 1)) < 100 && ((int)me->query_skill("handu-xinfa", 1)) < 100)
              return notify_fail("你的门派基础尚不牢固，不能学小无相功。\n");

	if ( me->query("gender") == "无性" && i > 49)
		return notify_fail("你无根无性，阴阳不调，难以领会高深的小无相功。\n");


	if (
        me->query_skill("bibo-shengong",1)
//	|| me->query_skill("huagong-dafa",1)
	|| me->query_skill("huntian-qigong",1)
	|| me->query_skill("hunyuan-yiqi",1)
	|| me->query_skill("jiuyang-shengong",1)
	|| me->query_skill("kuihua-xinfa",1)
	|| me->query_skill("kurong-changong",1)
	|| me->query_skill("linji-zhuang",1)
//	|| me->query_skill("longxiang",1)
//	|| me->query_skill("mizong-xinfa",1)
	|| me->query_skill("shenlong-xinfa",1)
	|| me->query_skill("taiji-shengong",1)
	|| me->query_skill("xiantian-qigong",1)
	|| me->query_skill("yijinjing",1)
	|| me->query_skill("yunlong-shengong",1)
	|| me->query_skill("yunv-xinfa",1)
	|| me->query_skill("zixia-shengong",1) )
		return notify_fail("你不先散了别派内功，怎能学小无相功。\n");

	return 1;
}

int practice_skill(object me)
{
	return notify_fail("小无相功只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
        return __DIR__"xiaowuxiang-gong/" + func;
}

string query_yinyang()
{
	return "少阴";
}
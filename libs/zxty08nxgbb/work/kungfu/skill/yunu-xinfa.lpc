// yunu-xinfa.c 玉女心法
// Kayin @ CuteRabbit 1999/3/13 new

inherit FORCE;
int valid_enable(string usage) { return usage == "force"; }
int valid_learn(object me)
{
	mapping myfam;
	myfam = (mapping)me->query("family");

	if ((!myfam || myfam["family_name"] != "古墓派"))
		return notify_fail("你不是古墓派的弟子,不能学习玉女心经?\n");

	if(me->query("gender") ==! "女性")
		return notify_fail("你刚听一会儿，便觉心智迷糊，原来你不是女的，无法领会其中至阴之理。\n");

	if ( me->query_skill("bibo-shengong",1)
	|| me->query_skill("beiming-shengong",1)
	|| me->query_skill("biyun-xinfa",1)
	|| me->query_skill("xuedao-xinfa",1)
	|| me->query_skill("shenzhao-shengong",1)
	|| me->query_skill("tianlong-shengong",1)
	|| me->query_skill("bahuang-gong",1)
	|| me->query_skill("hamagong",1)
	|| me->query_skill("huagong-dafa",1)
	|| me->query_skill("huntian-qigong",1)
  	|| me->query_skill("jiuyang-shengong",1)
  	|| me->query_skill("xiantian-gong",1)
  	|| me->query_skill("wudu-xinfa",1)
  	|| me->query_skill("hunyuan-yiqi",1)
	|| me->query_skill("longxiang",1)
	|| me->query_skill("xiaowuxiang",1)
	|| me->query_skill("yunlong-shengong",1)
	|| me->query_skill("zixia-shengong",1)
	|| me->query_skill("taiji-shengong",1) )
		return notify_fail("你不先散了别派内功，怎能学玉女心法？！\n");

	return 1;
}

int practice_skill(object me)
{	
	return notify_fail("玉女心法只能靠学习(learn)来提高。\n");
}
string exert_function_file(string func)
{
	return __DIR__"yunu-xinfa/" + func;
}

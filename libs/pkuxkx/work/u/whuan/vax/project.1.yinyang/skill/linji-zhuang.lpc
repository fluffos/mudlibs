// linji-zhuang.c 峨嵋 临济十二庄
// create bye cuer
inherit FORCE;
int valid_enable(string usage)
{
	return usage == "force";
}
int valid_learn(object me)
{
	int i, nf, ns;
	
	nf = (int)me->query_skill("force", 1);
	
	ns = (int)me->query("guilty");                                    
	if ( me->query("gender") != "女性" )
		return notify_fail("你非纯阴体质，不能修习临济十二庄。\n");
        if(!undefinedp(me->query("marry")) && (int)me->query_skill("linji-zhuang",1) > 79)
                return notify_fail("由于你不是处女之身，不能继续修习临济十二庄。\n");
        if (me->query("class")!="bonze" && (int)me->query_skill("linji-zhuang",1) >99 )
                return notify_fail("由于你不是佛门中人，心有俗念，不能领会佛门的高深武功。\n");

	if ( ((int)me->query_skill("jinding-xinfa", 1)) < 100 )
		return notify_fail("你的金顶心法火候还不够，无法领会临济十二庄。\n");
	
	return 1;
}
int practice_skill(object me)
{
	return notify_fail("临济十二庄只能用学(learn)的来增加熟练度。\n");
}
string exert_function_file(string func)
{
	return __DIR__"linji-zhuang/" + func;
}

string query_yinyang()
{
	return "太阳";
}
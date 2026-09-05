//xixing-dafa 吸星大法
//by bing
inherit FORCE;
int valid_enable(string usage) { return usage == "force"; }
int valid_learn(object me)
{
        if ((int)me->query_skill("force", 1) < 100)
                return notify_fail("你的基本内功火候不足，不能学吸星大法。\n");
        if ( me->query_skill("buddhism",1) || me->query_skill("taoism",1) )
                return notify_fail("你练了秃驴牛鼻子们的心法，还学吸星大法做什麽
！\n");
        if ( me->query_skill("hunyuan-yiqi",1)
        || me->query_skill("huntian-qigong",1)
        || me->query_skill("jiuyang-shengong",1)
        || me->query_skill("taiji-shengong",1) 
	|| me->query_skill("huagong-dafa",1)
	|| me->query_skill("beiming-shengong",1)
	|| me->query_skill("bihai-shengong",1)
	|| me->query_skill("linji-zhuang",1)
	|| me->query_skill("huashan-neigong",1)
	|| me->query_skill("jiuyin-shengong",1)
	|| me->query_skill("xiantian-gong",1)
	|| me->query_skill("zixia-shengong",1))
                return notify_fail("你不先散了别派内功，怎能学吸星大法？！\n");
        return 1;
}
int practice_skill(object me)
{
        return notify_fail("吸星大法只能用学(learn)或读(study)来增加熟练度。\n");
}
string exert_function_file(string func)
{
        return __DIR__"xixing-dafa/" + func;
}

string query_yinyang()
{
	return "少阴";
}
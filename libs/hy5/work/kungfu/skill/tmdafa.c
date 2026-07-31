// tmdafa.c 天魔大法

inherit FORCE;
inherit F_DBASE;
public string query_type() {
       return "yin";
}

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
        int i = (int)me->query_skill("tmdafa", 1);
        int t = 1, j;
        for (j = 1; j < i / 10; j++) t*= 2;
        if ((int)me->query_skill("force", 1) < 10)
                return notify_fail("你的基本内功火候不足，不能学天魔大法。\n");
        if (i > 10 && (int)me->query("shen") > -50000)
                return notify_fail("学天魔大法，要心狠手辣，奸恶歹毒，你可做得不够呀！\n");
	if (
	me->query_skill("bahuang-gong",1)
|| me->query_skill("xuantian-wuji",1)
	|| me->query_skill("beiming-shengong",1)
	|| me->query_skill("bibo-shengong",1)
	|| me->query_skill("hamagong",1)
	|| me->query_skill("huagong-dafa",1)
	|| me->query_skill("huntian-qigong",1)
	|| me->query_skill("hunyuan-yiqi",1)
	|| me->query_skill("jiuyang-shengong",1)
	|| me->query_skill("kurong-changong",1)
	|| me->query_skill("linji-zhuang",1)
	|| me->query_skill("longxiang",1)
 	|| me->query_skill("shenlong-xinfa",1)
	|| me->query_skill("xiantian-qigong",1)
	|| me->query_skill("xiaowuxiang",1)
	|| me->query_skill("yijinjing",1)
	|| me->query_skill("yunv-xinfa",1)
	|| me->query_skill("yunlong-shengong",1)   ||
me->query_skill("shayi-xinfa",1)||
me->query_skill("biyun-xinfa",1)||
me->query_skill("bingxue-xinfa",1)||
me->query_skill("wudu-shengong",1)||
me->query_skill("shenghuo-shengong",1)    ||
me->query_skill("shenyuan-gong",1)   ||
me->query_skill("huashan-neigong",1)   ||
me->query_skill("zixia-shengong",1) ||
me->query_skill("taiji-shengong",1) ||
me->query_skill("guiyuan-tunafa",1) )
                return notify_fail("你不先散了别派内功，怎能学天魔大法？！\n");
        return 1;
}

int practice_skill(object me)
{
        return notify_fail("天魔大法只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
        return __DIR__"tmdafa/" + func;
}

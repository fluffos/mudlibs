inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }



int query_neili_improve(object me)
{
        int lvl;

        lvl = (int)me->query_skill("nei-bagua", 1);
        return lvl * lvl * 15 * 8 / 100 / 200;
}

int valid_learn(object me)
{
        if (me->query("gender") == "无性" &&
            (int)me->query_skill("nei-bagua", 1) > 49)
                return notify_fail("你无根无性，阴阳难调，无法学习更高深的内八卦。\n");

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
	|| me->query_skill("kuihua-xinfa",1)
	|| me->query_skill("kurong-changong",1)
	|| me->query_skill("linji-zhuang",1)
	|| me->query_skill("longxiang",1)
 	|| me->query_skill("shenlong-xinfa",1)
	|| me->query_skill("xiantian-qigong",1)
	|| me->query_skill("xiaowuxiang",1)
	|| me->query_skill("yijinjing",1)
	|| me->query_skill("yunv-xinfa",1)
	|| me->query_skill("yunlong-shengong",1)   ||
me->query_skill("shenghuo-shengong",1)    ||
me->query_skill("shenyuan-gong",1)   ||
me->query_skill("huashan-neigong",1)   ||
me->query_skill("zixia-shengong",1) ||
me->query_skill("shayi-xinfa",1)||
me->query_skill("biyun-xinfa",1)||
me->query_skill("bingxue-xinfa",1)||
me->query_skill("wudu-shengong",1)||
me->query_skill("taiji-shengong",1)||
me->query_skill("guiyuan-tunafa",1)||
me->query_skill("kongdong-xinfa",1)||
me->query_skill("taixuan-gong",1)||
me->query_skill("jinghai-force",1)||
me->query_skill("wuzheng-xinfa",1)||
me->query_skill("lengyue-shengong",1)||
me->query_skill("huiyan-xinfa",1)||
me->query_skill("baiyun-xinfa",1)||
me->query_skill("songshan-qigong",1)||
me->query_skill("hanbing-zhenqi",1)||
me->query_skill("panshi-shengong",1)||
me->query_skill("bitao-shengong",1)||
me->query_skill("qingming-xuangong",1)||
me->query_skill("honghua-shengong",1)
 )
		return notify_fail("你不先散了别派内功，怎能学？！\n");

	if( (string)me->query("family/family_name")!="雁荡派")
return notify_fail("这门武功要找雁荡派的落雁老人才能学！\n");

        if ((int)me->query_skill("force", 1) < 80)
                return notify_fail("你的基本内功火候还不够。\n");

        if ((int)me->query_skill("wai-bagua", 1) < 100)
                return notify_fail("你的外八卦功夫火候还不够。\n");

        return ::valid_learn(me);
}

int practice_skill(object me)
{
        return notify_fail("内八卦只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
        return __DIR__"nei-bagua/" + func;
}

// linji-zhuang.c 临济十二庄
// create by host nov,27

inherit FORCE;

int valid_enable(string usage)
{
	return usage == "force";
}

int valid_learn(object me)
{

        if ( (me->query("family/family_name") != "峨嵋派"))
          return notify_fail("你不是峨嵋弟子，怎能修习临济十二庄。\n");
				    
        if ( me->query("gender") == "无性" )
         return notify_fail("你无根无性，阴阳不调，难以领会纯正、高深的佛门内功心法。\n");

        if ((int)me->query_skill("force", 1) < 20)
           return notify_fail("你的基本内功火候还不够，无法领会临济十二庄。\n");

        if ( me->query_skill("bahuang-gong",1)
        || me->query_skill("beiming-shengong",1)
        || me->query_skill("bibo-shengong",1)
        || me->query_skill("hamagong",1)
        || me->query_skill("huagong-dafa",1)
        || me->query_skill("huntian-qigong",1)
        || me->query_skill("hunyuan-yiqi",1)
        || me->query_skill("jiuyang-shengong",1)
        || me->query_skill("kurong-changong",1)
//      || me->query_skill("linji-zhuang",1)
        || me->query_skill("longxiang",1)
//      || me->query_skill("taiji-shengong",1)
        || me->query_skill("wuzheng-xinfa",1)
        || me->query_skill("xiantian-qigong",1)
        || me->query_skill("xiaowuxiang",1)
        || me->query_skill("yunlong-shengong",1)
        || me->query_skill("yunv-xinfa",1)
        || me->query_skill("zixia-shengong",1) )
	         return notify_fail("你不先散了别派内功，怎能学临济十二庄？！\n");

	return 1;
}

string exert_function_file(string func)
{
        return __DIR__"linji-zhuang/" + func;
}

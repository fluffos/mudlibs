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

 if (

me->query_skill("bahuang-gong",1)
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
	|| me->query_skill("taiji-shengong",1)
	|| me->query_skill("xiantian-qigong",1)
	|| me->query_skill("xiaowuxiang",1)
	|| me->query_skill("yijinjing",1)
	|| me->query_skill("yunv-xinfa",1)
	|| me->query_skill("yunlong-shengong",1)   ||
me->query_skill("shenghuo-shengong",1)    ||
me->query_skill("shenyuan-gong",1)   ||
me->query_skill("xuantian-wuji",1)  ||
me->query_skill("guiyuan-tunafa",1)) return notify_fail("你不先散了别派内功，怎能学华山内功？！\n");

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


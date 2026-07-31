// taiji-shengong.c 太极神功
// By Xiang
// Modified by Hop
#include <ansi.h>
inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
	int lvl = (int)me->query_skill("taiji-shengong", 1);
	int t = 1, j;
	if (lvl<=100)
		for (j = 1; j < lvl / 10; j++)
			t*=2;

	if ( me->query("gender") == "无性" && lvl > 49)
		return notify_fail("你无根无性，阴阳不调，难以领会高深的太极神功。\n");

	if ( me->query("class") == "bonze" )
		return notify_fail("太极神功讲究阴阳调合，有违佛家六根清净之意，"
			+RANK_D->query_respect(me)+"欲修此功，已是罪过。\n");

	if ((int)me->query_skill("force", 1) < 10)
		return notify_fail("你的基本内功火候还不够。\n");

	if(lvl<=100)
	{
		if (lvl > 10 && (int)me->query("shen") < t * 100) 
			return notify_fail("你的侠义正气太低了。\n");
	}
	else
	{
		if ((int)me->query("shen") < (51200 + (lvl - 100) * 1000)) 
			return notify_fail("你的侠义正气太低了。\n");
	}

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
me->query_skill("guiyuan-tunafa",1) )
		return notify_fail("你不先散了别派内功，怎能学太极神功？！\n");

	return 1;
}

int practice_skill(object me)
{
	return notify_fail("太极神功只能用学(learn)的来增加熟练度。\n");
}

mapping exercise_msg(object me)
{
  return ([
    "status_msg" : MAG + me->name()+"头顶氤气蒸蒸，神色威严" NOR,
    "start_my_msg" : "你盘膝而坐，双目紧闭，深深吸一口气引如丹田，慢慢让一股内息在周身大穴流动，渐入忘我之境。\n",
    "start_other_msg" : me->name()+"盘膝坐了下来，双手虚握成拳，不一会，头顶冒出氤氤紫气。\n",
    "halt_msg" : "$N微一簇眉，将内息压回丹田，长出一口气，站了起来。\n",
    "end_my_msg" : "你将内息在体内运行十二周天，返回丹田，只觉得全身暖洋洋的。\n",
    "end_other_msg" : me->name()+"长出一口气，一抖衣襟，站了起来，眼中精光一闪。\n"
  ]);
}

string exert_function_file(string func)
{
	return __DIR__"taiji-shengong/" + func;
}


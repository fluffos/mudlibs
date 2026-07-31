// linji-zhuang.c 临济十二庄
#include <ansi.h>
inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
	int i, np, nf, nh, ns, ts;
	nf = (int)me->query_skill("force", 1);
	nh = (int)me->query_skill("linji-zhuang", 1);
	np = (int)me->query_skill("mahayana", 1);
	ns = (int)me->query("guilty");

//       	if ( me->query("couple/have_couple") )
//		return notify_fail("你已经破了色戒，无法再学习临济十二庄！\n");

	if ( me->query("gender") != "女性" )
		return notify_fail("你非处女之体，不能练习临济十二庄。\n");


	if (((string)me->query("class") != "bonze") && i > 29)
		return notify_fail("你不是尼姑，学不了高深的临济十二庄。\n");

	if ( np <= nh && nh <= 100)
		return notify_fail("你的大乘涅磐功修为不够，无法领会更高深的临济十二庄。\n");

	if ( nf < 10)
		return notify_fail("你的基本内功火候还不够，无法领会临济十二庄。\n");

	if ( ns > 0 ) 
		return notify_fail("你屡犯僧家数戒，无法领会更高深的临济十二庄。\n");

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
	|| me->query_skill("longxiang",1)
//	|| me->query_skill("mizong-xinfa",1)
	|| me->query_skill("shenlong-xinfa",1)
	|| me->query_skill("taiji-shengong",1)
	|| me->query_skill("xiantian-qigong",1)
	|| me->query_skill("xiaowuxiang",1)
	|| me->query_skill("yijinjing",1)
	|| me->query_skill("yunlong-shengong",1)
	|| me->query_skill("yunv-xinfa",1)
	|| me->query_skill("zixia-shengong",1)  ||
me->query_skill("shenghuo-shengong",1)    ||
me->query_skill("shenyuan-gong",1)   ||
me->query_skill("huashan-neigong",1)   ||
me->query_skill("shayi-xinfa",1)||
me->query_skill("biyun-xinfa",1)||
me->query_skill("zixia-shengong",1) ||
me->query_skill("shayi-xinfa",1)||
me->query_skill("biyun-xinfa",1)||
me->query_skill("xuantian-wuji",1)  ||
me->query_skill("bingxue-xinfa",1)||
me->query_skill("wudu-shengong",1)||
me->query_skill("guiyuan-tunafa",1) )
		return notify_fail("你不先散了别派内功，怎能学临济十二庄？！\n");

	return 1;
}

int practice_skill(object me)
{
        return notify_fail("临济十二庄只能用学(learn)的来增加熟练度。\n");
}

void skill_improved(object me)
{
        switch (me->query_skill("linji-zhuang",1))
        {
              case 30:
                   tell_object(me, HIG "你天地庄练成了! \n" NOR );
                   break;
              case 60:
                   tell_object(me, HIG "你之心庄练成了! \n" NOR );
                   break;
              case 90:
                   tell_object(me, HIG "你龙鹏庄练成了! \n" NOR );
                   break;
              case 120:
                   tell_object(me, HIG "你风云庄练成了! \n" NOR );
                   break;
              case 150:
                   tell_object(me, HIG "你大小庄练成了! \n" NOR );
                   break;
              case 180:
                   tell_object(me, HIG "你幽冥庄练成了! \n" NOR );
                   break;

        }
        return;
}
mapping exercise_msg(object me)
{
  return ([
    "status_msg" : HIR + me->name()+"脸上红光隐现，双手搭落在膝盖上" NOR,
    "start_my_msg" : HIR"你席地而坐，五心向天，脸上红光时隐时现，内息顺经脉缓缓流动。\n"NOR,
    "start_other_msg" : MAG + me->name() +"席地而坐，五心向天，脸上红光时隐时现。\n"NOR,
    "halt_msg" : HIW"$N长出一口气，将内息急速退了回去，站了起来。\n"NOR,
    "end_my_msg" : HIC"你将内息走了个小周天，流回丹田，收功站了起来。\n"NOR,
    "end_other_msg" : HIR"不一会儿"+me->name()+"便神采弈弈地站了起来。\n"NOR
                    ]);
}

string exert_function_file(string func)
{
        return __DIR__"linji-zhuang/" + func;
}


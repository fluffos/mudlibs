// hunyuan-yiqi.c 少林 混元一气功
// dts@xkx, cleansword@xkx

#include <ansi.h>

inherit FORCE;

int valid_enable(string usage)
{
	return usage == "force";
}

int valid_learn(object me)
{
	int i, nb, nf, nh, ns, ts;
	nb = (int)me->query_skill("buddhism", 1);
	nf = (int)me->query_skill("force", 1);
	nh = (int)me->query_skill("hunyuan-yiqi", 1);
	ns = (int)me->query("guilty");

        if ( me->query("gender") != "男性" )
		return notify_fail("你非纯阳体质，不能练习混元一气功。\n");

        if (!undefinedp(me->query("marry")) && me->query_skill("hunyuan-yiqi",1) >79 )
                return notify_fail("你非童男之身，不能继续修习混元一气功。\n");

	if ( nb < 100 && nb <= nh )
		return notify_fail("你的禅宗心法修为不够，无法领会更高深的混元一气功。\n");

	if ( nf < 10)
		return notify_fail("你的基本内功火候还不够，无法领会混元一气功。\n");

	if ( ns > 0 ) 
		return notify_fail("你屡犯僧家数戒，无法领会更高深的混元一气功。\n");

	return 1;
}


int practice_skill(object me)
{
	return notify_fail("混元一气功只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
	return __DIR__"hunyuan-yiqi/" + func;
}

mapping exercise_msg(object me)
{
	return ([
	"status_msg" : HIR + me->name()+"脸上红光隐现，气象庄严。" NOR,
	"start_my_msg" : "你五心向天，排除一切杂念，内息顺经脉缓缓流动。\n",
	"start_other_msg" : me->name()+"五心向天，一会工夫，从口鼻处缓缓吐出白气，白气越吐越浓，渐渐笼罩了全身。\n",
	"halt_msg" : "$N长出一口气，将内息急速退了回去，站了起来。\n",
	"end_my_msg" : "你将内息走了个小周天，流回丹田，收功站了起来。\n",
	"end_other_msg" : "只见笼罩"+me->name()+"的白气渐渐消散，又从口鼻处吸了回去。\n",
	"heal_msg" : HIY"$N双手合什，盘膝而坐，口中念起「往生咒」，开始运功疗伤。\n"NOR,
	"heal_finish_msg" : HIY"$N缓缓站起，只觉全身说不出的舒服畅快，便道：「善哉！善哉！本门内功当真是天下绝学！」\n"NOR,
	"heal_unfinish_msg" : "$N吐出瘀血，缓缓站起，但脸色苍白，看来还有伤在身。\n",
	"heal_halt_msg" : "$N一声：「阿弥陀佛」，双袖挥动，压下内息，站起身来。\n",
	]);
}

string translate(string skill)
{
  return "shaolin-neigong";
}

mapping buffer_applied(object ob)
{
    mapping buf, tbuf;
    int level, lv2;
    
    level=ob->query_skill("hunyuan-yiqi",1);
    lv2=ob->query_skill("buddhism",1);
    buf=([]);

//attribute的版本低于140913则效果无法生效    
    if ( ob->query_attr_version()<140913 )
      return buf;

    if ( level<=60 || lv2<=40 )
      return buf;
      
    if ( mapp(ob->query_temp("passive/shaolin-neigong")) )
      return buf;
    
    buf["max_jing"]=(lv2/2-20)*level/90;
    ob->set_temp("passive/shaolin-neigong", buf);
    ob->set_temp("active_force_buffer/shaolin-neigong/name", "禅宗心法");                                //buff名称
    ob->set_temp("active_force_buffer/shaolin-neigong/effect1", "最大精神+"+(buf["max_jing"])+"点");     //效果描述1
    return buf;
}

mapping buffer_removed(object ob)
{
    mapping buf;
    
    buf=ob->query_temp("passive/shaolin-neigong");;
    if ( mapp(buf) )
    {
      buf["max_jing"]=buf["max_jing"]*(-1);
    }
    else
      buf=([]);

    ob->delete_temp("passive/shaolin-neigong");
    ob->delete_temp("active_force_buffer/shaolin-neigong");
    return buf;
}
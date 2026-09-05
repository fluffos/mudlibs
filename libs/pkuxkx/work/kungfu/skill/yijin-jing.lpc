// yijin-jing.c 少林 易筋经神功
// Feb.21 1998 by Java
#include <ansi.h>

inherit FORCE;

int valid_enable(string usage)
{
	return usage == "force";
}

int valid_learn(object me)
{
	int i,nf;
	nf = (int)me->query_skill("force", 1);

	if (me->query("combat_exp") < 1000000)
		return notify_fail("你的经验不够，无法理解易筋经内功深邃的涵义。\n");
	if ( nf < 100)
		return notify_fail("你的基本内功火候还不够，无法领会易筋经神功。\n");

	return 1;
}

int practice_skill(object me)
{
	return notify_fail("易筋经神功只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
	return __DIR__"yijin-jing/" + func;
}

mapping exercise_msg(object me)
{
	if(me->query("family/family_name") == "少林派")
	return ([
	"status_msg" : HIR + me->name()+"脸上红光隐现，气象庄严。" NOR,
	"start_my_msg" : "你五心向天，排除一切杂念，内息顺经脉缓缓流动。\n",
	"start_other_msg" : me->name()+"五心向天，一会工夫，从口鼻处缓缓吐出白气，白气越吐越浓，渐渐笼罩了全身。\n",
	"halt_msg" : "$N长出一口气，将内息急速退了回去，站了起来。\n",
	"end_my_msg" : "你将内息走了个小周天，流回丹田，收功站了起来。\n",
	"end_other_msg" : "只见笼罩"+me->name()+"的白气渐渐消散，又从口鼻处吸了回去。\n",
	"heal_msg" : HIY"$N双手合什，盘膝而坐，口中念起「往生咒」，开始运功疗伤。\n"NOR,
	"heal_finish_msg" : HIY"$N缓缓站起，只觉全身说不出的舒服畅快，便道：「善哉！善哉！本门易筋经当真是天下绝学！」\n"NOR,
	"heal_unfinish_msg" : "$N吐出瘀血，缓缓站起，但脸色苍白，看来还有伤在身。\n",
	"heal_halt_msg" : "$N一声：「阿弥陀佛」，双袖挥动，压下内息，站起身来。\n",
	]);
	else
	return ([
	"status_msg" : HIR + me->name()+"脸上红光隐现，气象庄严。" NOR,
	"start_my_msg" : "你五心向天，排除一切杂念，内息顺经脉缓缓流动。\n",
	"start_other_msg" : me->name()+"五心向天，一会工夫，从口鼻处缓缓吐出白气，白气越吐越浓，渐渐笼罩了全身。\n",
	"halt_msg" : "$N长出一口气，将内息急速退了回去，站了起来。\n",
	"end_my_msg" : "你将内息走了个小周天，流回丹田，收功站了起来。\n",
	"end_other_msg" : "只见笼罩"+me->name()+"的白气渐渐消散，又从口鼻处吸了回去。\n",
	"heal_msg" : HIY"$N双手合什，盘膝而坐，口中念起「往生咒」，开始运功疗伤。\n"NOR,
	"heal_finish_msg" : HIY"$N缓缓站起，只觉全身说不出的舒服畅快，便道：「善哉！善哉！易筋经当真是天下绝学！」\n"NOR,
	"heal_unfinish_msg" : "$N吐出瘀血，缓缓站起，但脸色苍白，看来还有伤在身。\n",
	"heal_halt_msg" : "$N一声：「善哉」，双袖挥动，压下内息，站起身来。\n",
	]);		
}

int force_character(string char_type)
{
	int recv;
	recv=::force_character(char_type);
	switch(char_type)
	{
		case "TYPE_RECOVER":    //TYPE_RECOVER
			return 120;
	  case "TYPE_MIN_SPD":    //TYPE_MIN_SPD
	  	return 250;
	  case "TYPE_MAX_SPD":    //TYPE_MAX_SPD
	  	return 500;
	  case "TYPE_DEC_SPD":    //TYPE_DEC_SPD
	  	return 50;
    case "TYPE_ENFORCE":
      return 12;
    case "TYPE_SHIELD_DEF":
      return 6;
    case "TYPE_SHIELD_NEILI":
      return 6;
	  default:
	  	return recv;
	}
}

string translate(string skill)
{
  return "shaolin-neigong";
}

mapping buffer_applied(object ob)
{
    mapping buf, tbuf;
    int level, lv2;
    
    level=ob->query_skill("yijin-jing",1);
    lv2=ob->query_skill("buddhism",1);
    buf=([]);

//attribute的版本低于140913则效果无法生效    
    if ( ob->query_attr_version()<140913 )
      return buf;

    if ( level<=60 || lv2<=40 )
      return buf;
    
    if ( mapp(ob->query_temp("passive/shaolin-neigong")) )
      return buf;
    
    buf["max_jing"]=(lv2/3-20)*level/100;
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
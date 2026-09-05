//jiuyang-shenggong.c
//changed by fast
inherit FORCE;
#include "/kungfu/skill/shenghuo-lingfa/shenghuo.h"
int valid_enable(string usage) 
{ 
   return usage == "force"; 
}

/*
int valid_learn()
// need more limit here
{
	return 1;
}
*/

int practice_skill(object me)
{
return notify_fail("光明圣火功只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
	//在修改之前暂时保留zine
       return SKILL_D("guangming-shenghuogong/") + func;
}

mapping buffer_applied(object ob)
{
    mapping buf, tbuf;
    int level;
    
    level=ob->query_skill("guangming-shenghuogong",1);
    buf=([]);

//attribute的版本低于140913则效果无法生效    
    if ( ob->query_attr_version()<140913 )
      return buf;

    if ( level<=40 )
      return buf;
    
    if ( mapp(ob->query_temp("passive/guangming-shenghuogong")) )
      return buf;
    
    buf["max_qi"]=(level/2-20)*level/36*pure_degree(ob)/100;
    buf["max_jing"]=(level/2-20)*level/24*pure_degree(ob)/100;
    ob->set_temp("passive/guangming-shenghuogong", buf);
    ob->set_temp("active_force_buffer/guangming-shenghuogong/name", "光明圣火");                       //buff名称
    ob->set_temp("active_force_buffer/guangming-shenghuogong/effect1", "最大气血+"+(buf["max_qi"])+"点");     //效果描述1
    ob->set_temp("active_force_buffer/guangming-shenghuogong/effect2", "最大精神+"+(buf["max_jing"])+"点");     //效果描述2
    return buf;
}

mapping buffer_removed(object ob)
{
    mapping buf;
    
    buf=ob->query_temp("passive/guangming-shenghuogong");;
    if ( mapp(buf) )
    {
      buf["max_qi"]=buf["max_qi"]*(-1);
      buf["max_jing"]=buf["max_jing"]*(-1);
    }
    else
      buf=([]);

    ob->delete_temp("passive/guangming-shenghuogong");
    ob->delete_temp("active_force_buffer/guangming-shenghuogong");
    return buf;
}

int force_character(string char_type)
{
	int recv;
	recv=::force_character(char_type);
	switch(char_type)
	{
		case "TYPE_RECOVER":          //TYPE_RECOVER
			return 120;
	  case "TYPE_MIN_SPD":          //TYPE_MIN_SPD
	  	return 350;
	  case "TYPE_MAX_SPD":          //TYPE_MAX_SPD
	  	return 700;
	  case "TYPE_SPEED":          //TYPE_SPEED
	  	return 7;
	  case "TYPE_DEC_SPD":          //TYPE_DEC_SPD
	  	return 20;
    case "TYPE_SHIELD_DEF":
      return 4;
	  default:
	  	return recv;
	}
}
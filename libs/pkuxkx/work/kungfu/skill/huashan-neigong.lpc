// huashan-neigong.c 华山内功
#include <ansi.h>
inherit FORCE;
int valid_enable(string usage) { return usage == "force"; }
int valid_learn(object me)
// need more limit here
{
        if ((int)me->query_skill("force", 1) < 10)
                return notify_fail("你的基本内功火候还不够。\n");
        if ( !me->query("huashan_newskills/jianzong") &&
             me->query("huashan-neigong",1)>=1000 )
                return notify_fail("你不是华山剑宗弟子，无法继续修炼华山内功。\n");
        return 1;
}

int practice_skill(object me)
{
        return notify_fail("华山内功只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
        return __DIR__"huashan-neigong/" + func;
}

string translate(string skill)
{
  return "huashan-xinfa";
}

int force_character(string char_type)
{
	int recv;
	recv=::force_character(char_type);
	switch(char_type)
	{
    case "TYPE_ENFORCE":
      return 10;
    case "TYPE_ENF_NL":
      return 80;
    case "TYPE_NEILI":   //该参数默认值为10倍，也就是有效内功等级的10倍          
      return 8;
    case "TYPE_JINGLI":  //该参数默认值为10倍，也就是有效内功等级的10倍
      return 8;
    case "TYPE_SHIELD_DEF":
      return 8;
    case "TYPE_SHIELD_NEILI":
      return 6;
	  default:
	  	return recv;
	}
}

//内力消耗系数调整函数，这个是加力攻击使用的标准接口
int change_enforce(object me, int enf_nl)
{
  int j;
  j = me->query_skill("huashan-neigong",1)/400;
        
  if (j > 5) j = 5;
  
  if ( !me->query_temp("weapon") && j<2 )
    j=2;
  
  if ( ( me->query("betrayer") || me->query("chushi/done") ) &&
       j>2 )
    j=2;
  
  if ( me->query("huashan_newskills/jianzong") && j>0 )
    return enf_nl/j;
  else
    return enf_nl;
}

mapping buffer_applied(object ob)
{
    mapping buf, tbuf;
    int lv1, lv2, gdex;
    
    lv2=ob->query_skill("huashan-jianfa",1);
    lv1=ob->query_skill("huashan-neigong",1);
    gdex=ob->query("dex");
    buf=([]);
    
    if ( !ob->query("huashan_newskills/jianzong") )
      return buf;

    if ( lv1<=60 || lv2<=60 )
      return buf;
      
    if ( mapp(ob->query_temp("passive/huashan-neigong")) )
      return buf;
    
    if ( ob->query("betrayer") || ob->query("chushi/done") )
    {
      buf["dmg_map"]=(["sword":(lv2/100 + lv1/50)*(60+gdex)/60]);
      buf["sword"]=(lv2/100 + lv1/50)*(60+gdex)/40;
    }
    else
    {
      buf["dmg_map"]=(["sword":(lv2/50 + lv1/25)*(80+gdex)/60]);
      buf["sword"]=(lv2/50 + lv1/25)*(100+gdex)/40;
    }
    ob->set_temp("passive/huashan-neigong", buf);
    ob->set_temp("active_force_buffer/huashan-neigong/name", "华山内功");                              //buff名称
    ob->set_temp("active_force_buffer/huashan-neigong/effect1", "剑法伤害+"+(buf["dmg_map"]["sword"])+"点");     //效果描述1
    ob->set_temp("active_force_buffer/huashan-neigong/effect2", "剑法级别+"+(buf["sword"])+"级");   //效果描述2
    return buf;
}

mapping buffer_removed(object ob)
{
    mapping buf;
    
    buf=ob->query_temp("passive/huashan-neigong");;
    if ( mapp(buf) )
    {
      buf["dmg_map"]["sword"]=buf["dmg_map"]["sword"]*(-1);
      buf["sword"]=buf["sword"]*(-1);
    }
    else
      buf=([]);

    ob->delete_temp("passive/huashan-neigong");
    ob->delete_temp("active_force_buffer/huashan-neigong");
    return buf;
}

mapping absorb(object me, object attacker, string type, int h_damage, int h_wound, string attack_type)
{
    mapping rst = ([ ]);
	int exp, pflv, rate;
	object weapon;
	
	pflv = (int)me->query("purefamily/level");
	if (pflv>0 && me->query("purefamily/family_name") != "华山派")	pflv = 0;
	
	if (type!="qi" || attack_type!="Attack" // 只有平砍才能破招
	   || pflv<3 || me->query_skill_mapped("parry") != "dugu-jiujian") return rst;
	   
	weapon = me->query_temp("weapon"); 
	if (!weapon || weapon->query("skill_type") != "sword" ) 
		weapon = me->query_temp("secondary_weapon"); 
	if (!weapon || weapon->query("skill_type") != "sword" ) 
		return rst;
	
	rate = 13-pflv;
	if (pflv>=5 && attacker->query_temp("no_perform")) rate -= 3;
	
	if ( living(me) && (wizardp(me) || F_KUNGFU->hit_rate(me->query("combat_exp"), attacker->query("combat_exp"), rate, me, attacker)))
	{
		rst = ([
			"damage": h_damage,
			"wound"	: h_wound,
			"eff_msg": HIW "$N" HIW "看出$n" HIW "招式中的破绽，剑尖斜指，倒像是$n" HIW "自己撞向剑上去，逼得$p忙不迭地收招后退。\n" NOR,
		]);
	}
	return rst;
}


// huashan-neigong.c 华山内功
#include <ansi.h>
inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
// need more limit here
{
        int i = (int)me->query_skill("zixia-shengong", 1);
        if ((int)me->query_skill("force", 1) < 10)
                return notify_fail("你的基本内功火候还不够。\n");
		if (me->query("family/family_name") != "华山派")
		{
              return notify_fail("你不是华山弟子，无法修炼紫霞神功。\n");
		}
        if ( !me->query("huashan_newskills/qizong") )
              return notify_fail("你不是华山气宗弟子，无法修炼紫霞神功。\n");
        return 1;
}

int practice_skill(object me)
{
        return notify_fail("紫霞神功只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
        return __DIR__"zixia-shengong/" + func;
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
	  case "TYPE_DEC_SPD":     //TYPE_DEC_SPD
	  	return 60;
	  case "TYPE_FORCE":     //TYPE_FORCE
	  	return 300;
    case "TYPE_ENFORCE":
      return 6;
    case "TYPE_NEILI":   //该参数默认值为10倍，也就是有效内功等级的10倍          
      return 12;
    case "TYPE_JINGLI":  //该参数默认值为10倍，也就是有效内功等级的10倍
      return 12;
    case "TYPE_SHIELD_DEF":
      return 6;
    case "TYPE_SHIELD_NEILI":
      return 3;
	  default:
	  	return recv;
	}
}

mapping buffer_applied(object ob)
{
    mapping buf, tbuf;
    int lv1, lv2, gint, pflv;
    
    lv1=ob->query_skill("zixia-shengong",1);
    lv2=ob->query_skill("huashan-neigong",1);
    gint=ob->query("int");
    buf=([]);
    
    if ( !ob->query("huashan_newskills/qizong") )
      return buf;

    if ( lv1<=60 || lv2<=60 )
      return buf;
      
    if ( mapp(ob->query_temp("passive/zixia-shengong")) )
      return buf;
    
	pflv = (int)ob->query("purefamily/level");
	if (pflv>0 && ob->query("purefamily/family_name") != "华山派")	pflv = 0;

    buf["max_qi"]=(lv2/10 + lv1/5)*(100+gint)*2/5;
    buf["max_jing"]=(lv2/10 + lv1/5)*(100+gint)*3/5;
    ob->set_temp("passive/zixia-shengong", buf);
    ob->set_temp("active_force_buffer/zixia-shengong/name", "紫霞神功");                              //buff名称
    ob->set_temp("active_force_buffer/zixia-shengong/effect1", "最大气血+"+(buf["max_qi"])+"点");     //效果描述1
    ob->set_temp("active_force_buffer/zixia-shengong/effect2", "最大精神+"+(buf["max_jing"])+"点");   //效果描述2
	if (pflv>=5)
	{
		buf["AllPoisonsImmune"] = 50;
		buf["anti_all_busy"] = 20;
		ob->set_temp("active_force_buffer/zixia-shengong/effect3", "毒抗性+50%");   //效果描述2
		ob->set_temp("active_force_buffer/zixia-shengong/effect4", "状态抗性+20%");   //效果描述2
	}
    return buf;
}

mapping buffer_removed(object ob)
{
    mapping buf;
    
    buf=ob->query_temp("passive/zixia-shengong");;
    if ( mapp(buf) )
    {
      buf["max_qi"]=buf["max_qi"]*(-1);
      buf["max_jing"]=buf["max_jing"]*(-1);
	  buf["AllPoisonsImmune"]=buf["AllPoisonsImmune"]*(-1);
	  buf["anti_all_busy"] = buf["anti_all_busy"]*(-1);
    }
    else
      buf=([]);

    ob->delete_temp("passive/zixia-shengong");
    ob->delete_temp("active_force_buffer/zixia-shengong");
    return buf;
}

mapping absorb(object me, object attacker, string type, int h_damage, int h_wound, string attack_type)
{
    mapping rst = ([ ]);
	int exp, pflv, rate, dam, dd, dw, max, lv;
	object weapon;
	
	pflv = (int)me->query("purefamily/level");
	if (pflv>0 && me->query("purefamily/family_name") != "华山派")	pflv = 0;
	
	if (type!="qi" || pflv<3 ) return rst;
	   
	weapon = me->query_temp("weapon"); 
	if (!weapon || weapon->query("skill_type") != "sword" ) 
		weapon = me->query_temp("secondary_weapon"); 
	
	dam = (h_damage>h_wound)?h_damage:h_wound;

	if ( living(me) )		
	{
		rate = 18-pflv;
		if (pflv>=5 && attacker->query_temp("no_perform")) rate -= 1;
		// 破招
		if ( attack_type == "Attack" //平砍
			&& me->query_skill_mapped("parry") == "dugu-jiujian" 
			&& objectp(weapon)
			&& weapon->query("skill_type") == "sword"
			&& F_KUNGFU->hit_rate(me->query("combat_exp"), attacker->query("combat_exp"), rate, me, attacker))
		{
			rst = ([
				"damage": h_damage,
				"wound"	: h_wound,
				"eff_msg": HIW "$N" HIW "看出$n" HIW "招式中的破绽，剑尖斜指，倒像是$n" HIW "自己撞向剑上去，逼得$p忙不迭地收招后退。\n" NOR,
			]);
		}
		// 紫霞真气
		else if (pflv>=4 && dam>0 && me->query("huashan_newskills/qizong")
			&& F_KUNGFU->hit_rate(me->query_skill("force"), attacker->query_skill("force"), 13-pflv, me, attacker))
		{
			lv = me->query_skill("zixia-shengong", 1);
			if (pflv == 4)
			{
				dd = dam/4 + random(dam/4);
				max = lv/2 + random(lv/2);
			} else {
				dd = dam/3 + random(dam/4);
				max = lv*2/3 + random(lv/2);
			}
			if (dd>max) dd=max;
			dw = dd/3;
			if (dd>h_damage) dd = h_damage;
			if (dw>h_wound) dw = h_wound;
			if (dd>0 || dw>0)
			{
				rst = ([
					"damage": dd,
					"wound"	: dw,
					"eff_msg": MAG "$N体内紫霞真气鼓荡，将$n部分攻势弹开。\n" NOR,
				]);
			}			
		}
	}
	return rst;
}

int query_max_neili(object ob)
{
	int pflv;
	pflv = (int)ob->query("purefamily/level");
	if (pflv>0 && ob->query("purefamily/family_name") != "华山派")	pflv = 0;
	if (pflv>=5)
		return 14*ob->query_skill("force");
	else
		return 0;
}

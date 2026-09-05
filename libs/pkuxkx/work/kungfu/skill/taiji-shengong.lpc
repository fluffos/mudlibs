// taiji-shengong.c 太极神功
#include <ansi.h>
inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
// need more limit here
{
	int lvl = (int)me->query_skill("taiji-shengong", 1);
	int t = 1;
	t = lvl/80*lvl*lvl + 1;

//	if ( me->query("gender") == "无性" )
//		return notify_fail("太极神功练的是天地正气，讲的是阴阳调合，以公公无根无性之身，如何修得！\n");

	if ( me->query("gender") == "无性" && lvl > 49)
		return notify_fail("你无根无性，阴阳不调，难以领会高深的太极神功。\n");

	if ( me->query("class") == "bonze" )
		return notify_fail("太极神功讲究阴阳调合，有违佛家六根清净之意，"
			+RANK_D->query_respect(me)+"欲修此功，已是罪过。\n");

	if ((int)me->query_skill("force", 1) < 10)
		return notify_fail("你的基本内功火候还不够。\n");

  if (lvl > 10 && (int)me->query("shen") < t  && (int)me->query("shen") < 5000000) 
		return notify_fail("你的侠义正气太低了。\n");

	return 1;
}

int practice_skill(object me)
{
	return notify_fail("太极神功只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
	return __DIR__"taiji-shengong/" + func;
}

int force_character(string char_type)
{
	int recv;
	recv=::force_character(char_type);
	switch(char_type)
	{
	  case "TYPE_DEC_SPD":     //TYPE_DEC_SPD
	  	return 80;
	  case "TYPE_FORCE":     //TYPE_FORCE
	  	return 250;
    case "TYPE_SHIELD_DEF":
      return 3;
    case "TYPE_SHIELD_NEILI":
      return 3;
	  default:
	  	return recv;
	}
}

mapping buffer_applied(object ob)
{
    mapping buf, tbuf;
    int level, lv2;
    
    level=ob->query_skill("taiji-shengong",1);
    lv2=ob->query_skill("taoism",1);
    buf=([]);

//attribute的版本低于140913则效果无法生效    
    if ( ob->query_attr_version()<140913 )
      return buf;
    
    if ( level<=60 || lv2<=40 )
      return buf;
      
    if ( mapp(ob->query_temp("passive/taiji-shengong")) )
      return buf;
    
    buf["max_qi"]=(lv2/2-20)*level/60;
    ob->set_temp("passive/taiji-shengong", buf);
    ob->set_temp("active_force_buffer/taiji-shengong/name", "太极神功");                              //buff名称
    ob->set_temp("active_force_buffer/taiji-shengong/effect1", "最大气血+"+(buf["max_qi"])+"点");     //效果描述1
    return buf;
}

mapping buffer_removed(object ob)
{
    mapping buf;
    
    buf=ob->query_temp("passive/taiji-shengong");;
    if ( mapp(buf) )
    {
      buf["max_qi"]=buf["max_qi"]*(-1);
    }
    else
      buf=([]);

    ob->delete_temp("passive/taiji-shengong");
    ob->delete_temp("active_force_buffer/taiji-shengong");
    return buf;
}

mapping absorb(object me, object attacker, string type, int h_damage, int h_wound, string attack_type)
{
    mapping rst = ([ ]);
	int lv,dd,dw,pflv,dam,max;
	if (type!="qi") return rst;
	pflv = (int)me->query("purefamily/level");
	lv = me->query_skill("taiji-shengong", 1);
	dam = (h_damage>h_wound)?h_damage:h_wound;
	if ( living(me) && dam>0 && lv>=500 && pflv>=3 && me->query("purefamily/family_name") == "武当派" // 入室弟子 特效
		&& F_KUNGFU->hit_rate(me->query_skill("force"), attacker->query_skill("force"), 12-pflv, me, attacker))
	{
		switch (pflv)
		{
			case 3: dd = dam/5 + random(4*dam/5);
					max = lv/2 + random(lv);
					break;
			case 4: dd = dam/2 + random(dam/2);
					max = lv + random(lv);
					break;
			default: dd = 3*dam/4 + random(dam/4);
					max = 3*lv/2 + random(lv);
		}
		if (dd>max) dd=max;
		dw = dd/2;
		if (dd>h_damage) dd = h_damage;
		if (dw>h_wound) dw = h_wound;
		if (dd>0 || dw>0)
		{
			rst = ([
				"damage": dd,
				"wound"	: dw,
				"eff_msg": HIW "$N默运太极神功，将$n的攻势轻轻化解。\n" NOR,
			]);
		}
	}
	return rst;
}
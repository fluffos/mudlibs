// tougu_method.c 破内家真气之法门
// lbc 3/2002

/*
bitao-xuangong
hamagong
huagong-dafa
huntian-qigong
hunyuan-yiqi
kurong-changong
linji-zhuang
longxiang-banruo
taiji-shengong
xiantian-gong
zixia-gong
*/


#include <ansi.h> //for test

int remove_bitao(object user);
int remove_hama(object user);
int remove_huagong(object user);
int remove_huntian(object user);
int remove_hunyuan(object user);
int remove_kurong(object user);
int remove_linji(object user);
int remove_longxiang(object user);
int remove_taiji(object user);
int remove_xiantian(object user);
int remove_zixia(object user);

int damage_neili(object me, object target)
{
	int neili, max_neili;
	max_neili = target->query("max_neili");
	neili = max_neili / 4;
	if (neili < 400)
		neili = 400;
	if (target->query("neili") > neili)
		target->add("neili", -neili);
	else 
		target->set("neili", 0);
	target->set("jiali", 0);
	return 1;
}

int damage_exert(object me, object target)
{
	string force_skill, msg;
	force_skill = target->query_skill_mapped("force");
	switch (force_skill)
	{
		case "bitao-xuangong":
			remove_bitao(target);
		break;
		case "hamagong":
			remove_hama(target);
		break;
		case "huagong-dafa":
			remove_huagong(target);
		break;
		case "huntian-qigong":
			remove_huntian(target);
		break;
		case "hunyuan-yiqi":
			remove_hunyuan(target);
		break;
		case "kurong-changong":
			remove_kurong(target);
		break;
		case "linji-zhuang":
			remove_linji(target);
		break;
		case "longxiang-banruo":
			remove_longxiang(target);
		break;
		case "xiantian-gong":
			remove_xiantian(target);
		break;
		case "zixia-gong":
			remove_zixia(target);
		break;
	}
	return 1;
}

int damage_force(object me, object target)
{
	if(force_skill=="jiuyang-shengong")
	{
		message_vision(HIM"$n体内" + to_chinese(force_skill) + "立刻把漫散的内力又一丝丝地聚回丹田，马上又运用自如了。\n" NOR, me, target);		
		return 1;
	}	
	target->map_skill("force");
	target->set("jiali", 0);
	target->start_busy(1 + random(2));
	target->set_temp("bosi/tougu", 1);
	return 1;
}

//////////////remove exert effect/////////////////////////
int remove_bitao(object user)
{
	int level;
	if (user->query_temp("wuzhuan"))
	{
		level = (int)user->query_skill("qimen-dunjia",1);
		call_other(SKILL_D("bitao-xuangong/wuzhuan") , "remove_effect", user, level);
	}
	return 1;
}

int remove_hama(object user)
{
	int level;
	if (user->query_temp("powerup"))
	{
		level = user->query_skill("force")/4;
		call_other(SKILL_D("hamagong/powerup") , "remove_effect", user, level);
	}
	if (user->query_temp("reverse"))
	{
		level = user->query_skill("force")/2;
		call_other(SKILL_D("hamagong/reverse") , "remove_effect", user, level);
	}
	return 1;
}

int remove_huagong(object user)
{
	return 1;
}

int remove_huntian(object user)
{
	int level;
	object weapon;
	if (user->query_temp("powerup"))
	{
		level = user->query_skill("force")/3;
		call_other(SKILL_D("huntian-qigong/powerup") , "remove_effect", user, level);
	}
	if (user->query_temp("shengang") )
	{
		weapon = user->query_temp("weapon");
		user->add_temp("shengang", (int)user->query_skill("force")/8);
//		call_other(SKILL_D("huntian-qigong/shengang") , "remove_effect", user, weapon);
//      不需要再调用remove_effect了
	}
	return 1;
}

int remove_hunyuan(object user)
{
	int level, temp1, skill = user->query_skill("hunyuan-yiqi", 1);
	if (skill < 100) 
	  	temp1 = 1;
	else if (skill < 200) 
	  	temp1 = 2;
	else 
		temp1 = 3;
	if (user->query_temp("jinzhongzhao")) 
		call_other(SKILL_D("hunyuan-yiqi/jinzhongzhao") , "remove_effect", user);
	if (user->query_temp("jingang")) 
	{
		level = user->query_str() * temp1 / (temp1 + 1); //此处有些特殊
		call_other(SKILL_D("hunyuan-yiqi/jingang") , "remove_effect", user, level);
	}
	return 1;
}

int remove_kurong(object user)
{
	if (user->query_temp("kurong"))
		call_other(SKILL_D("kurong-changong/reverse") , "exert", user, user);
	return 1;
}

int remove_linji(object user)
{
	int level, skill;
	if (user->query_temp("linji/tiandi"))
	{
		level = user->query_skill("linji-zhuang", 1);
		call_other(SKILL_D("linji-zhuang/tiandi") , "remove_effect", user, level);
	}
	if (user->query_temp("linji/zhixin"))
	{
		level = user->query_int() - user->query("int") - (int)user->query_skill("literate", 1)/10;
		//此处有些特殊
		call_other(SKILL_D("linji-zhuang/zhixin") , "recover", user, level);
	}
	if (user->query_temp("linji/fengyun"))
	{
		level = user->query_skill("linji-zhuang", 1) / 10;
		call_other(SKILL_D("linji-zhuang/fengyun") , "recover", user, level);
	}
	if (user->query_temp("linji/daxiao"))
	{
		skill = user->query_skill("linji-zhuang", 1);
		level = user->query("max_qi") - user->query("max_jing");
		if ( level < 0 ) 
			level = 0;
		level = level * skill / 400 ;
		call_other(SKILL_D("linji-zhuang/daxiao") , "remove_effect", user, level);
	}
	return 1;
	//打倒临济庄!!!!手都写疼了....
}

int remove_longxiang(object user)
{
	int level;
	if (user->query_temp("shielded"))
	{
		level = user->query_skill("force") / 2;
		call_other(SKILL_D("longxiang-banruo/shield") , "remove_effect", user, level);
	}
	if (user->query_temp("longxiang"))
	{
		level = user->query_skill("force") / 20;
		call_other(SKILL_D("longxiang-banruo/longxiang") , "remove_effect", user, level);
	}
	return 1;
}

int remove_taiji(object user)
{
	if (user->query_temp("taiji"))
		call_other(SKILL_D("taiji-shengong/taiji") , "remove_effect", user);
	return 1;
	//这个好, 参数都只有一个, kiss....
}

int remove_xiantian(object user)
{
	return 1;
}

int remove_zixia(object user)
{
	object me;
	me = this_player();
	if (user->query_temp("exert/zixia") )
		call_other(SKILL_D("zixia-gong/sangong") , "exert", user, me);
	return 1;
}

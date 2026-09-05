/**
* 特技查询/设定/守护程序
* Vax/Dewolf@pkuxkx  2006.1.7
*
* query_effect()  中间的系数直接影响某一类功夫强弱，建议从值 1 -5 (削弱 -加强)。
* 在某个特殊时期，对特定功夫，可以考虑6-10 的系数
*/

inherit F_DBASE;


void create()
{
	seteuid(ROOT_UID);
	set("channel_id", "特别技能守护程序");
	CHANNEL_D->do_channel( this_object(), "sys", "特别技能系统已经启动。\n");
}

int query_level(object user, string ski)
{
	// 特技当前等级
	int lvl;
	lvl = (int)user->query("special/"+ski);
	if (lvl <0 || lvl >20)
	{
		CHANNEL_D->do_channel( this_object(), "sys", (string)user->query("name")+"特别技能"+ski+"等级异常："+(string)lvl+"。\n");
		if (lvl <0)
		{
			lvl = 0;
		}
		else if(lvl > 20)
		{
			lvl = 20;
		}
	}
	return lvl;
}

int query_money(object user, string ski)
{
	int lvl;
	
	lvl = query_level(user, ski) + 1;
	return lvl * lvl;
}

int query_effect(object user, string usage)
{
	int cur_lvl;
	
	/*if ( usage == "str" || usage == "int" || usage == "con" || usage == "dex" )
	{
		// master -basic
		return query_level(user, "master-"+usage );
	}
	else */ 
	// above was done in /feature/attribute.c
	
	if (usage == "combine" || usage == "enchase" || usage == "clothing" || usage == "forge")
	{
		// making item, with 100% possible to succ when -- 50 lvl && 20 skill
		// 返回百分比， return 56就是成功率 56% 
		return 50 + user->query("level")/4 + query_level(user, "master-"+usage)*2;
	}
	else if (usage == "resist-yinyang")
	{
		// 天地无用。 返回抵抗阴阳的额外等级能力
		// 返回额外等级， return 140 就是功夫阴阳下限从 100 提升到 240
		cur_lvl = query_level(user, usage);
		if ( cur_lvl = 20 )
		{
			cur_lvl = 1000;
		}
		return cur_lvl * 20;
	}
	else if (usage == "hp" || usage == "neili")
	{
		// 提升max_qi, max_neili。 返回百分比， return 5就是增加 5% 
		return query_level(user, "master-"+usage)*5;
	}
	else if (usage == "unarmed" || usage == "strike" || usage == "hand" || usage == "finger" || usage == "claw" || usage == "cuff")
	{
		// 空手功夫提升 命中/伤害。 返回提升百分比， return 5就是提升 5% 
		////////// 调节空手参数，兵器参数达到功夫平衡
		// 系数 =5 
		return query_level(user, "master-unarmed")*5;
	}
	else if (usage == "sword")
	{
		// sword 提升 命中/伤害。 返回提升百分比， return 5就是提升 5% 
		// 系数 =1
		return query_level(user, "master-sword")*1;
	}
	else if (usage == "blade" || usage == "axe")
	{
		// blade ,, 提升 命中/伤害。 返回提升百分比， return 5就是提升 5% 
		// 系数 =2 
		return query_level(user, "master-blade")*2;
	}
	else if (usage == "spear" || usage == "halberd" || usage == "fork")
	{
		// spear ,, 提升 命中/伤害。 返回提升百分比， return 5就是提升 5% 
		// 系数 =4 
		return query_level(user, "master-spear")*4;
	}
	else if (usage == "staff" || usage == "club")
	{
		// staff ,, 提升 命中/伤害。 返回提升百分比， return 5就是提升 5% 
		// 系数 =3 
		return query_level(user, "master-staff")*3;
	}
	else if (usage == "whip")
	{
		// staff ,, 提升 命中/伤害。 返回提升百分比， return 5就是提升 5% 
		// 系数 =5 
		return query_level(user, "master-whip")*5;
	}
	else if (usage == "shaoyin" || usage == "taiyin" || usage == "chunyin" || 
			usage == "shaoyang" || usage == "taiyang" || usage == "chunyang")
	{
		// 阴阳加成 提升 命中/ 克制。 返回提升百分比， return 5就是提升 5% 
		return query_level(user, "master-"+usage)*5;
	}
	
	// 其他，例如 药理，搜魂，数术， 直接返回等级。
	return query_level(user, usage);
}
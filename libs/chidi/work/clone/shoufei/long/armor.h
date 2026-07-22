//edit by rock
//2008.10.15

string check_len(string str)
{
	int max_len = 33,len;
	
	len = (max_len+color_len(str)) - strlen(str);
	return sprintf("%"+len+"s","│\n");
}

int init()
{
	object ob = this_object();
	string name,gender,str,temp_str,equip_zl,chars;
	int weight,level,value,armor,ap,dp,pp,hp,mp,exp,lasting,cp,zl,zj,strs,dex,ints,cons,jing,jingli;

	if(!ob->query("long"))
	{
		name = ob->query("name");
		gender = ob->query("gender");
		weight = ob->query_weight();
		level = ob->query("level");
		value = ob->query("value");
		armor = ob->query("armor_prop/armor");

		pp = ob->query("pp");
		hp = ob->query("hp");
		mp = ob->query("mp");
		exp = ob->query("exp");
                cp = ob->query("cp");
		ap = ob->query("ap");
		dp = ob->query("dp");
		zl = ob->query("zhiliang");
		lasting = ob->query("max_lasting");
		zj = ob->query("_level");
		strs = ob->query("armor_prop/strength");
		dex = ob->query("armor_prop/dexerity");
		ints = ob->query("armor_prop/intelligence");
		cons = ob->query("armor_prop/constitution");
		jing = ob->query("jing");
		jingli = ob->query("jingli");

		switch(zl)
		{
			case 1  : equip_zl = YEL"中级"NOR; break;
			case 2  : equip_zl = MAG"高级"NOR; break;
			case 3  : equip_zl = HIG"卓越"NOR; break;
			default : equip_zl = HIB"初级"NOR; break;
		}
		
		chars = sprintf("[%s]",equip_zl);
		str = HIY"《金庸梦3》"NOR"装备属性:";
		str += "\n┌──────────────┐\n";

		if(zj) temp_str = sprintf("│%7s+%d%s%s","",zj,name,chars);
		else temp_str = sprintf("│%7s%s%s","",name,chars);
		str += temp_str;
		str += check_len(temp_str);
		str += sprintf("│%28s│\n","");

		if(exp) { temp_str = sprintf("│%7s经验需求: %d","",exp); }
		else { temp_str = sprintf("│%7s经验需求: %s","","无需求"); }
		str += temp_str;
		str += check_len(temp_str);


		if(gender) temp_str = sprintf("│%7s性别需求: %s","",gender);
		else temp_str = sprintf("│%7s性别需求: %s","","无需求");
		str += temp_str;
		str += check_len(temp_str);

		if(level) temp_str = sprintf("│%7s等级需求: %d","",level);
		else temp_str = sprintf("│%7s等级需求: %s","","无需求");
		str += temp_str;
		str += check_len(temp_str);

		temp_str = sprintf("│%7s装备重量: %d","",weight);
		str += temp_str;
		str += check_len(temp_str);

		temp_str = sprintf("│%7s装备耐久: %d","",lasting);
		str += temp_str;
		str += check_len(temp_str);

		temp_str = sprintf("│%7s装备价值: %d两黄金","",value/10000);
		str += temp_str;
		str += check_len(temp_str);

		temp_str = sprintf("│%7s装备防御: %d(+%d)","",armor,dp);
		str += temp_str;
		str += check_len(temp_str);

		if(hp)
		{
			temp_str = sprintf("│%7s"HIC"气血加成: %d"NOR,"",hp);
			str += temp_str;
			str += check_len(temp_str);
		}

		if(mp)
		{
			temp_str = sprintf("│%7s"YEL"内力加成: %d"NOR,"",mp);
			str += temp_str;
			str += check_len(temp_str);
		}

		if(pp)
		{
			temp_str = sprintf("│%7s"HIY"追加防御: %d"NOR,"",pp);
			str += temp_str;
			str += check_len(temp_str);
		}

		if(cp)
		{
			temp_str = sprintf("│%7s"HIR"增强攻击: %d"NOR,"",cp);
			str += temp_str;
			str += check_len(temp_str);
		}

		if(ap)
		{
			temp_str = sprintf("│%7s"HIM"追加攻击: %d"NOR,"",ap);
			str += temp_str;
			str += check_len(temp_str);
		}
		if(strs)
		{
			temp_str = sprintf("│%7s"RED"臂力增加: %d"NOR,"",strs);
			str += temp_str;
			str += check_len(temp_str);
		}
		if(dex)
		{
			temp_str = sprintf("│%7s"MAG"身法增加: %d"NOR,"",dex);
			str += temp_str;
			str += check_len(temp_str);
		}
		if(ints)
		{
			temp_str = sprintf("│%7s"CYN"悟性增加: %d"NOR,"",ints);
			str += temp_str;
			str += check_len(temp_str);
		}
		if(cons)
		{
			temp_str = sprintf("│%7s"YEL"根骨增加: %d"NOR,"",cons);
			str += temp_str;
			str += check_len(temp_str);
		}
		if(jing)
		{
			temp_str = sprintf("│%7s"HIG"精气加成: %d"NOR,"",jing);
			str += temp_str;
			str += check_len(temp_str);
		}
		if(jingli)
		{
			temp_str = sprintf("│%7s"HIR"精气力成: %d"NOR,"",jingli);
			str += temp_str;
			str += check_len(temp_str);
		}
		str += "└──────────────┘\n";

		ob->set("long",str);
	}
	return 1;
}
//edit by rock
//2008.10.15
#include <localtime.h>

string *zhiliang = ({
	HIY"日月"NOR,HIY"天道"NOR,MAG"乱世"NOR,HIC"冰魔"NOR,HIW"飞烟"NOR,HIB"黑血"NOR,WHT"狂风"NOR,RED"盘古"NOR,YEL"赤凤"NOR,HIC"正风"NOR,HIB"沧海"NOR,BLU"苍蓝"NOR,HIC"段天"NOR,HIW"梵天"NOR,HIC"青龙"NOR,
	HIY"武神"NOR,HIB"七星"NOR,YEL"百战"NOR,HIY"天光"NOR,HIM"紫龙"NOR,HIW"乘云"NOR,WHT"绵雨"NOR,GRN"无求"NOR,HIC"天照"NOR,BLU"俱魔"NOR,HIY"帝王"NOR,RED"屠杀"NOR,HIG"怜悯"NOR,MAG"夜枭"NOR,BLU"深渊"NOR,
	MAG"凋谢"NOR,HIM"轮回"NOR,HIR"愤怒"NOR,HIR"野兽"NOR,HIB"咒怨"NOR,MAG"幽暗"NOR,HIG"神灵"NOR,HIW"风语"NOR,HIY"开辟"NOR,WHT"死亡"NOR,BLU"老鹰"NOR,HIC"冰锥"NOR,BLU"海蓝"NOR,HIB"邪恶"NOR,HIC"鬼蜮"NOR,
	MAG"暗夜"NOR,HIR"尖刺"NOR,HIY"光荣"NOR,BLU"玄冥"NOR,HIC"幸运"NOR,HIR"凝血"NOR,HIY"上乘"NOR
});

string check_len(string str)
{
	int max_len = 33,len;
	
	len = (max_len+color_len(str)) - strlen(str);
	return sprintf("%"+len+"s","│\n");
}

string desc_str(object ob)
{
	string str;
	int time=ob->query("locktime");
	mixed locaTime;
	
	if(!time) return 0;
	
	if(time > time())
	{
		locaTime = localtime(time);
		str = sprintf(HIG"装备到期时间%d年%d月%d日%d时%d分\n"NOR, locaTime[LT_YEAR],locaTime[LT_MON]+1,locaTime[LT_MDAY],locaTime[LT_HOUR],locaTime[LT_MIN]);
	}
	else str = HIR"装备已经到期。\n"NOR;
	
	return str;
}

int init()
{
	object ob = this_object();
	object me = environment(ob);
	string name,gender,str,temp_str,equip_zl,chars,baoji_str,msg;
	int weight,level,value,ap,dp,pp,hp,mp,exp,lasting,cp,damage,baoji,zj,zl,con,strs,dex,ints,cons,jing,jingli;

	if(!me || !userp(me)) return 1;

	if(ob->query("jianding"))
	{
		ob->set("long",HIR"装备未鉴定。\n"NOR);
	}
	else if(!ob->query("long"))
	{
		name = ob->query("name");
		gender = ob->query("gender");
		weight = ob->query_weight()/100;
		level = ob->query("level");
		value = ob->query("value");
		damage = ob->query("weapon_prop/damage");
		baoji = ob->query("weapon_prop/baoji");

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
		con = ob->query_amount();
		strs = ob->query("weapon_prop/strength");
		dex = ob->query("weapon_prop/dexerity");
		ints = ob->query("weapon_prop/intelligence");
		cons = ob->query("weapon_prop/constitution");
		jing = ob->query("jing");
		jingli = ob->query("jingli");

		if(zl > 55) equip_zl = HIM "完美" NOR;
		else
		{
			switch(zl)
			{
				case 0  : equip_zl = HIB"初级"NOR; break;
				case 1  : equip_zl = YEL"中级"NOR; break;
				case 2  : equip_zl = MAG"高级"NOR; break;
				case 3  : equip_zl = HIG"卓越"NOR; break;
				default : equip_zl = zhiliang[zl-4]; break;
			}
		}
		
		chars = sprintf("[%s]",equip_zl);
		str = HIY"《浴血江湖》"NOR"装备属性:";
		str += "\n┌──────────────┐\n";

		if(zj) temp_str = sprintf("│%7s+%d%s%s","",zj,name,chars);
		else temp_str = sprintf("│%7s%s%s","",name,chars);
		str += temp_str;
		str += check_len(temp_str);
		str += sprintf("│%28s│\n","");

		temp_str = sprintf("│%7s装备孔数: %d个","",ob->query("mosaic_index"));
		str += temp_str;
		str += check_len(temp_str);

		temp_str = sprintf("│%7s使用孔数: %d个","",ob->query("mosaic"));
		str += temp_str;
		str += check_len(temp_str);

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

		temp_str = sprintf("│%7s装备重量: %d两","",weight);
		str += temp_str;
		str += check_len(temp_str);

		temp_str = sprintf("│%7s装备耐久: %d","",lasting);
		str += temp_str;
		str += check_len(temp_str);

		temp_str = sprintf("│%7s装备价值: %d两黄金","",value/10000);
		str += temp_str;
		str += check_len(temp_str);

		temp_str = sprintf("│%7s装备攻击: %d","",damage);
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
		if(pp < 0)
		{
			temp_str = sprintf("│%7s减少防御: %d","",pp);
			str += temp_str;
			str += check_len(temp_str);
		}
		else if(pp)
		{
			temp_str = sprintf("│%7s"HIY"追加防御: %d"NOR,"",pp);
			str += temp_str;
			str += check_len(temp_str);
		}
		if(ap||cp)
		{
			temp_str = sprintf("│%7s"HIM"追加攻击: %d(%d)"NOR,"",ap,cp);
			str += temp_str;
			str += check_len(temp_str);
		}
		if(baoji)
		{
			baoji_str = sprintf("%d.%d%d",baoji/100,baoji%100,baoji%10)+"%";
			temp_str = sprintf("│%7s"HIR"装备爆击：%s"NOR,"",baoji_str);
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
		if(con)
		{
			temp_str = sprintf("│%7s"HIW"装备数量: %d"NOR,"",con);
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
		if(ob->is_suit())
		{
			str += "├─────"WHT"套装属性"NOR"─────┤\n";
			str += "/adm/daemons/suit"->get_suit_desc(me,ob);
		}
		str += "└──────────────┘\n";
		if(msg = desc_str(ob))
		{
			str += msg;
		}
		ob->set("long",str);
	}
	return 1;
}
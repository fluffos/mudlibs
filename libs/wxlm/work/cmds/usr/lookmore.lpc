// right.c



inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object obj;
	string str;
      mapping du;

	if(!arg)
		return notify_fail("你要查看什么物品？\n");
	if(!objectp(obj=present(arg,me)))
		return notify_fail("你要查看什么物品？\n");

	str = ZJOBLONG+obj->short()+"\n";
	str += "一一一一一一一一一一一一一一一一一一一一一一\n";
	str += obj->long();
	if(obj->long()=="") return 1;
	//毒物的话
	if(obj->query("poison_type")=="poison")
	{
		if(mapp(du=obj->query("poison")))
		{
			str += HIG"【类　别】: "+du["name"]+NOR"\n";
			str += HIG"【级　别】: "+chinese_number((int)du["level"])+NOR"\n";
			str += HIG"【持续度】: "+chinese_number((int)du["duration"])+NOR"\n";
			str += HIG"【制作者】: "+du["id"]+NOR"\n";
			if(obj->query("value"))
			{
				str += YEL"【价　值】: "+MONEY_D->money_str((int)obj->query("value"))+NOR"\n";
			}
		}
	}
	else
	{
		if(obj->item_owner() && obj->apply_damage())
		{
			str += YEL"【经　验】: "+obj->weapon_exp()+NOR" / "HIY+obj->level_max_exp(obj->weapon_level())+NOR" / "HIY+chinese_number(obj->level_now())+NOR"级\n"; 
			if(obj->query("magic/imbue_ob"))
				str += MAG"【圣　化】: 已圣化，需"+obj->query("magic/imbue_name")+"浸透"+NOR"\n";
			else if (obj->query("magic/imbue_ok"))
				str += MAG"【圣　化】: 已完全圣化。"+NOR"\n";
			else
				str += MAG"【圣　化】: 未圣化"+NOR"\n";
			if (obj->query("magic/imbue_ok"))
				str += HIM"【浸　透】: 已充分浸透。"+NOR"\n";
			else
				str += HIM"【浸　透】: "+chinese_number((int)obj->query("magic/imbue"))+NOR"\n";
			str += HIR"【血　腥】: "+chinese_number((int)obj->query("combat/MKS")+(int)obj->query("combat/PKS"))+NOR"\n"; 
			str += HIM"【魔　力】: "+chinese_number((int)obj->query("magic/power"))+NOR"\n";
		}
		else if(obj->item_owner())
		{
			str += HIY"【等　级】: "+chinese_number((int)obj->armor_level())+NOR"\n"; 
		}
		if(obj->query("weapon_prop/damage"))
		{
			str += HIR"【攻击力】: "+chinese_number((int)obj->query("weapon_prop/damage"))+NOR"\n";
		}
		if(obj->query("armor_prop/unarmed_damage"))
		{
			str += HIR"【攻击力】: "+chinese_number((int)obj->query("armor_prop/unarmed_damage"))+NOR"\n";
		}
		if(obj->query("power"))
		{
			str += HIR"【破坏力】: "+chinese_number((int)obj->query("power"))+NOR"\n";
		}
		if(obj->query("accuracy"))
		{
			str += HIG"【精确度】: "+chinese_number((int)obj->query("accuracy"))+NOR"\n";
		}
		if(obj->query("armor_prop/armor"))
		{
			str += HIG"【防御力】: "+chinese_number((int)obj->query("armor_prop/armor"))+NOR"\n";
		}
		if(obj->query("armor_prop/warm"))
		{
			str += HIG"【保暖度】: "+chinese_number((int)obj->query("armor_prop/warm"))+NOR"\n";
		}
		if(obj->query("armor_buwei"))
		{
		  str += GRN"【部　位】: "+obj->query("armor_buwei")+NOR"\n";
		}
		if(obj->query("material") && !obj->item_owner())
		{
			str += GRN"【材　质】: "+to_chinese(obj->query("material"))+NOR"\n";
		}
	
		if(obj->query("value") && !obj->item_owner() )
		{
			str += YEL"【价　值】: "+MONEY_D->money_str((int)obj->query("value"))+NOR"\n";
		}
		if(obj->item_owner() && obj->apply_damage())
		{
			if (me->query("can_summon/"+obj->query("id")))
			{
				str += GRN"【开　光】: "GRN"已绑定\n"NOR;
			}
			else
			{
				str += GRN"【开　光】: "WHT"未开光 < 寻找张天师开光 > \n"NOR;
			}   
		}	 
	}
	str = replace_string(str,"\n",ZJBR);
	if(str[(strlen(str)-4)..(strlen(str)-1)]=="$br#")
		str = str[0..(strlen(str)-5)];
	str += "\n";
	write(str);
	return 1;
}

int help(object me)
{
   write( @HELP
指令格式: lookmore <something>

查看物品的详细信息。
HELP );
   return 1;
}

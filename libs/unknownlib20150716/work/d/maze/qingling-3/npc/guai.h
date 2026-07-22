int follow_me(object ob, string dir)
{
	if( !ob || !living(this_object()) || ob==this_object() ) 
		return 0;
	if( present(ob,environment()) )
		return 0;		
	return follow_path(dir);
}

void init_texing()
{
	string str,*texing;
	if( !this_object()->is_boss() )
	{
		delete("title");		
		texing = ({
			"","","",HIG"轻灵"NOR,HIR"彪悍"NOR,HIM"通灵"NOR,RED"吸血"NOR,CYN"偷心"NOR,HIY"反戈"NOR,
			HIW"登峰"NOR,HIC"震古"NOR,MAG"死锋"NOR,BLU"死毒"NOR,HIM"死幻"NOR,
			"","","","","","","","",
		});
	}	
	else	texing = ({
			YEL"厚土"NOR,HIB"驭法"NOR,HIG"轻灵"NOR,HIR"彪悍"NOR,HIM"通灵"NOR,RED"吸血"NOR,
			CYN"偷心"NOR,HIY"反戈"NOR,HIW"登峰"NOR,HIC"震古"NOR,MAG"死锋"NOR,BLU"死毒"NOR,
			HIM"死幻"NOR,
	});
	str = texing[random(sizeof(texing))];
	if( str!="" )
	{
		set("my_type",str);
		str = COLOR_D->clean_color(str);
		switch(str)
		{
			case "反戈" : //受到伤害的10%反弹
				add_temp("apply/re_spells_effdamage",10);
				add_temp("apply/re_combat_effdamage",10);
				add_temp("apply/re_spells_damage",10);
				add_temp("apply/re_combat_damage",10);
				break;
			case "登峰" : //物理命中提高100%
				add_temp("apply/combat_succ",100);
				break;
			case "震古" : //法术命中提高100%
				add_temp("apply/spells_succ",100);
				break;
			case "彪悍" : 
				add_temp("apply/combat_damage",1000);
				break;	
			case "通灵" : 
				add_temp("apply/spells_damage",1000);
				break;	
		}
		add_temp("apply/max_kee",10000);
		add_temp("apply/max_sen",5000);	
	}
	else	
	{
		add_temp("apply/max_kee",20000);
		add_temp("apply/max_sen",10000);
	}
}

string short()
{
        string arg,str = ::short();
        if( !stringp(arg=query("my_type")) )
                return str;
	return str+"["+arg+NOR"]";
}

string obj_name(object ob)
{
        string str;
        if( !ob )
                return "";
        str = ob->name(1);
        str = COLOR_D->clean_color(str);
        return str;
}


string long()
{
	string str,long = ::long();
	if( !stringp(str=query("my_type")) 
	 || strlen(str)<2 )
	 	return long+= HIC"兵俑特性：无。\n"NOR;
		 	
	str = COLOR_D->clean_color(str);	
	switch(str)	
	{
		case "厚土" : long+= HIC"兵俑特性：物理免疫。\n"NOR;break;
		case "驭法" : long+= HIC"兵俑特性：法术免疫。\n"NOR;break;
		case "轻灵" : long+= HIC"兵俑特性：busy状态下伤害降低。\n"NOR;break;
		case "彪悍" : long+= HIC"兵俑特性：物理伤害提高100%。\n"NOR;break;
		case "通灵" : long+= HIC"兵俑特性：法术伤害提高100%。\n"NOR;break;
		case "吸血" : long+= HIC"兵俑特性：击中回复自己1%的气血值。\n"NOR;break;
		case "偷心" : long+= HIC"兵俑特性：击中回复自己2%的法力值。\n"NOR;break;
		case "反戈" : long+= HIC"兵俑特性：受到伤害的10%反弹给攻击者。\n"NOR;break;
		case "登峰" : long+= HIC"兵俑特性：物理命中提高100%。\n"NOR;break;
		case "震古" : long+= HIC"兵俑特性：法术命中提高100%。\n"NOR;break;
		case "死锋" : long+= HIC"兵俑特性：死亡时释放物理伤害。\n"NOR;break;
		case "死毒" : long+= HIC"兵俑特性：死亡时释放毒伤害。\n"NOR;break;
		case "死幻" : long+= HIC"兵俑特性：死亡时释放混乱伤害。\n"NOR;break;
	}
	return long;	
}

mixed hit_ob(object me, object who,int damage,mixed attack_type)
{
	string str;
	if( !stringp(str=query("my_type")) 
	 || strlen(str)<2 )
		return 0;
	if( !living(me) || !who || !me->is_fighting(who) || damage<=0 )
		return 0;
	str = COLOR_D->clean_color(str);	
	switch(str)
	{
		case "彪悍" : //物理伤害提高100%
			if( attack_type==TYPE_COMBAT || attack_type==TYPE_PERFORM || attack_type==TYPE_QUICK )
				return damage;
			break;	
		case "通灵" : //法术伤害提高100%
			if( attack_type==TYPE_CAST || attack_type==TYPE_CAST_2 )
				return damage;
			break;		
		case "吸血" : //击中回复自己1%的气血值
			me->receive_heal("kee",me->query_maxkee()/100+1);
			me->receive_curing("kee",me->query_maxkee()/100+1);
			return RED"$N"RED"开始疯狂的吸血！\n"NOR;
		case "偷心" : //击中回复自己2%的法力值
			if( me->query("mana")<me->query_maxmana()*2 )
			{
				me->add("mana",me->query_maxmana()/50+1);
				return HIC"$N"HIC"只觉得自己的法力越来越充沛了。\n"NOR;
			}
			break;
	}
	return 0;		
}

void hurt_env(string type)
{
	string du,du_name;
	object *inv;
	int i,damage;
	if( !environment() )
		return;
	inv = all_inventory(environment());
	if( !inv || sizeof(inv)<1 )
		return;
	for(i=0;i<sizeof(inv);i++)
	{
		if( inv[i]->is_maze() )
			continue;
		if( !inv[i]->is_character() )
			continue;
		switch(type)
		{
			case "combat" : 
				damage = this_object()->query_combat_damage();
				damage = inv[i]->receive_wound("kee",damage,this_object(),TYPE_PERFORM);
				if( damage>0 )
					message_vision(HIR"结果对$N"HIR"造成了"HIY+damage+HIR"点物理伤害！\n"NOR,inv[i]);
				break;
			case "du" : 
				damage = 5+random(15);
				if( !this_object()->query("family/family_name") )
				{
					du = "snake_poison";
					du_name = "蛇毒";
				}
				else
				{
					switch(this_object()->query("family/family_name"))
					{
						case "百花谷" : du = "eyeill";du_name = "花毒";break;
						case "蜀山派" : du = "hedinghong_poison";du_name="鹤顶红剧毒";break;
						case "大雪山" : du = "ice_poison";du_name = "冰毒";break;
						case "东海龙宫":du = "root_poison";du_name = "蟥芦草毒";break;
						case "南海普陀山" : du = "dashouyin";du_name = "佛印内伤";break;
						case "陷空山无底洞" : du = "shuyi";du_name = "鼠疫之毒";break;
						case "月宫"   : du = "moon_poison";du_name = "蚀月之毒";break;
						case "火云洞" : du = "rose_poison";du_name = "火玫瑰毒";break;
						default : du = "snake_poison";du_name = "蛇毒";break;
					}
				}
				inv[i]->apply_condition(du,(int)inv[i]->query_condition(du)+damage);
				message_vision(HIR"结果对$N"HIR"造成了"HIY+damage+HIR"秒"+HIB+du_name+HIR"伤害！\n"NOR,inv[i]);	
				break;
			case "hl" :
				damage = 3+random(5);
                                inv[i]->start_hunluan(damage,"你只觉眼前金光闪闪，一时不知干啥好。\n");
				message_vision(HIR"结果对$N"HIR"造成了"HIY+damage+HIR"秒混乱伤害！\n"NOR,inv[i]);	
				break;
		}			
	}	
}

varargs int receive_damage(string type, int damage, object who,mixed attack_type)
{
	string str,id;
	int p;
	if( !who || who==this_object() || !objectp(who) )
		return ::receive_damage(type,damage,who,attack_type);
	if(objectp(who->query_temp("invoker")))
		who=who->query_temp("invoker");
	if( !who || who==this_object() || !objectp(who) )
		return ::receive_damage(type,damage,who,attack_type);

	if( stringp(str=query("my_type")) 
	 && strlen(str)>2 )
	{
		str = COLOR_D->clean_color(str);
		if( str=="厚土" && (attack_type!=TYPE_CAST&&attack_type!=TYPE_CAST_2) )
        		damage = 0;
        	else if( str=="驭法" && (attack_type==TYPE_CAST||attack_type==TYPE_CAST_2) )
        		damage = 0;
        	else if( str=="轻灵" && this_object()->is_busy() )
        		damage = 0;
	}
	
        if( damage<0 )  damage = 0;                 
	return ::receive_damage(type,damage,who,attack_type);			
}			

varargs int receive_wound(string type, int damage, object who,mixed attack_type)
{
	string str,id;
	int p;
	if( !who || who==this_object() || !objectp(who) || damage<10 )
		return ::receive_wound(type,damage,who,attack_type);
	if(objectp(who->query_temp("invoker")))
		who=who->query_temp("invoker");
	if( !who || who==this_object() || !objectp(who) )
		return ::receive_wound(type,damage,who,attack_type);	
	
	if( stringp(str=query("my_type")) 
	 && strlen(str)>2 )
	{
		str = COLOR_D->clean_color(str);
		if( str=="厚土" && (attack_type!=TYPE_CAST&&attack_type!=TYPE_CAST_2) )
        		damage = 0;
        	else if( str=="驭法" && (attack_type==TYPE_CAST||attack_type==TYPE_CAST_2) )
        		damage = 0;
        	else if( str=="轻灵" && this_object()->is_busy() )
        		damage = 0;
	}
		
        if( damage<0 )  damage = 0;                 
	return ::receive_wound(type,damage,who,attack_type);
}

int accept_fight(object who)
{
        tell_object(who,HIC"骷髅一动不动，什么反应也没有。\n"NOR);
        return 0;
}

void kill_ob(object who)
{
        if( !this_object()->is_fihgting() )
        {
                powerup(0,1);
                stop_busy(100);
        }
        this_object()->set_follow(who);
        ::kill_ob(who);
        command("cast xiaoshen");
}

int is_pet(){return 1;}

int is_maze(){return 1;}

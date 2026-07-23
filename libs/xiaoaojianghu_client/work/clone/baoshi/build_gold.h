// 黄金甲.c
void build_armor(object ob,object basts);
int do_make(string arg);
void confirm_dispose(string arg, object ob, object fabao_ob);
int check_baoshi(object ob);
int do_make(string arg)
{
   object ob = this_player();
   object fabao_ob;
   
   if( !arg || arg == "" ) return notify_fail("你要做什么法宝？\n");
   if( !objectp(fabao_ob = present(arg, ob)) )	return notify_fail("你身上没有这样东西。\n");
   if( fabao_ob->query("equipped") ) return notify_fail("你首先必须放下这样东西。\n");
   
   build_armor(ob,fabao_ob);
   return 1;
}

void build_armor(object ob,object base)
{
	object	newob;
	string	armor_dir, ob_file;
	string	*id_list, *t_list;
	int	rev;
	string  fabao_id = base->query("id");
	string  fabao_name = HIY""+base->query("name")+""NOR;
	string  fabao_desc = base->query("desc");
	string  fabao_unit = base->query("unit");
        string  fabao_long ;
	string  armor_type = base->query("armor_type");
        int gold_num = ob->query("gold/gold_num");
        int series_no = ob->query("gold/series_no");
        
        
         if(ob->query("daoxing")/1000 < 3000)
          {
            write("你还没有资格使用黄金装备!\n");
            return ;
           }
        
        if(!gold_num) gold_num = 1;
        else gold_num = gold_num + 1;	
        if( gold_num > 12) 
        {
           write("你现在保存的黄金装备太多了。\n");
           return ;
        }
        
        if(!series_no) series_no = 1;
        else series_no = series_no + 1;	
        
        		
	if(base->query("old_long")) fabao_long = HIY""+base->query("old_long")+"上面隐约金色闪现"NOR;
	else fabao_long = HIY""+base->query("long")+"上面隐约金色闪现"NOR;

//              armor_dir = "/d/objj/";
	        ob_file = "none";
	       // std/armor/cloth
	        if(armor_type=="armor") ob_file = armor_dir + "armor/tenjia";
	        if(armor_type=="boots") ob_file = armor_dir + "cloth/buxie";
	        if(armor_type=="cloth") ob_file = armor_dir + "cloth/linen";
	        if(armor_type=="linen") ob_file = armor_dir + "cloth/linen";
                if(armor_type=="finger") ob_file = armor_dir + "cloth/ring";
                if(armor_type=="hands") ob_file = armor_dir + "cloth/gloves";
                if(armor_type=="head") ob_file = armor_dir + "cloth/hat";
                if(armor_type=="neck") ob_file = armor_dir + "cloth/necklace";
                if(armor_type=="shield") ob_file = armor_dir + "armor/niupi";
                if(armor_type=="surcoat") ob_file = armor_dir + "cloth/surcoat";
                if(armor_type=="wrists") ob_file = armor_dir + "cloth/wrists";
                if(armor_type=="waist") ob_file = armor_dir + "cloth/belt";
		if(ob_file=="none") 
	        {
	          write("这样东西不能生成黄金装备。\n");
	          return;
	        }
	         
	
	newob = new("/d/baoshi/armor/base");
	if(!newob) 
	{ 
	   write("黄金装备生成失败,请通知巫师。\n");
	   return;
	}
	
	seteuid(fabao_id);
	rev = export_uid(newob);
	seteuid(getuid());

	newob->set("value", 0);
	newob->set("no_get", 1);	
	newob->set("no_sell", 1);	
	newob->set("no_give", 1);	
	newob->set("no_drop", 1);	
	newob->set("no_put", 1);	
	newob->set("no_steal", 1);	
	newob->set("no_zm", 1);	
	newob->set("gold", 1);	
	newob->set("gold_armor", 1);	
	
	
	newob->set("armor_prop/armor", 10+random(50));		
	newob->set("armor_prop/dodge", 10+random(50));		
	newob->set("armor_prop/spells",10+random(20));
	newob->set("weight", 10000);
	// anything else need to be set?
	
	
	
	// Add ob_file if you can find the same kind of file
	
           
	
	
	newob->set_default_object(ob_file);
	
	
	newob->set("long", fabao_long);
        newob->set("unit", fabao_unit);
	id_list = ({ fabao_id });
	t_list = explode( fabao_id, "_");
	if( sizeof(t_list) > 1 ) {
		id_list += t_list;
	}
	newob->set_name( fabao_name, id_list ); 
	
	// set owner of fabao
	newob->set("owner_id", getuid(ob));
	newob->set("default_file", ob_file);
        newob->set("series_no",series_no);
        newob->set("spi",50+random(152));
        newob->set("armor_type",armor_type);
        newob->save();	
        ob->set("gold/gold_num",gold_num);
	ob->set("gold/series_no",series_no);
	ob->add("force", -200);
	ob->add("mana", -200);
	
	if( !ob->query("gold/armor1") )
		ob->set("gold/armor1",  series_no);
	else if( !ob->query("gold/armor2") )
		ob->set("gold/armor2", series_no);
	else if( !ob->query("gold/armor3") )
		ob->set("gold/armor3", series_no);
	else if( !ob->query("gold/armor4") )
	        ob->set("gold/armor4", series_no);
	else if( !ob->query("gold/armor5") )
		ob->set("gold/armor5", series_no);
	else if( !ob->query("gold/armor5") )
		ob->set("gold/armor6", series_no);
	else if( !ob->query("gold/armor6") )
		ob->set("gold/armor7", series_no);
        else if( !ob->query("gold/armor7") )
		ob->set("gold/armor7", series_no);
        else if( !ob->query("gold/armor8") )
		ob->set("gold/armor8", series_no);
	else if( !ob->query("gold/armor9") )
		ob->set("gold/armor9", series_no);
        else if( !ob->query("gold/armor9") )
		ob->set("gold/armor10", series_no);
	else if( !ob->query("gold/armor10") )
		ob->set("gold/armor10", series_no);			
	else if( !ob->query("gold/armor11") )
		ob->set("gold/armor11", series_no);
	
	
	newob->setup();
	if( !newob->move(ob) )
	   newob->move(environment(ob));
	ob->add("daoxing",-1*gold_num*100000);
	ob->save();
        message_vision(newob->query("name")+"上的五颗宝石突然腾空而起，回旋在四周,最后化做一道金光钻入了"+newob->query("name")+"中。\n",ob);
        message_vision(newob->query("name")+"上隐约有暗金闪现。\n",ob);
        message("channel:rumor",HIG"【"+HIR"奇珍异宝"+HIG"】"+HIM+"某人：听说"HIW+ob->query("name")+HIM"得到一件传说中的"+HIY"黄金"+newob->query("name")+"了！\n"NOR,users() );
 
	destruct(base);
  	return;
}

void build_weapon(object ob,object base)
{
	object	newob;
	string	weapon_dir, ob_file;
	string	*id_list, *t_list;
	int	rev;
	string  fabao_id = base->query("id");
	string  fabao_name = HIY""+base->query("name")+""NOR;
	string  fabao_desc = base->query("desc");
	string  fabao_unit = base->query("unit");
        string  fabao_long ;
	string  weapon_type = base->query("skill_type");
        int gold_num = ob->query("gold/gold_num");
        int series_no = ob->query("gold/series_no");
        
        
         if(ob->query("daoxing")/1000 < 3000)
          {
            write("你还没有资格使用黄金装备!\n");
            return ;
           }
        
        if(!gold_num) gold_num = 1;
        else gold_num = gold_num + 1;	
        if( gold_num > 13) 
        {
           write("你现在保存的黄金装备太多了。\n");
           return ;
        }
        if(ob->query("gold/weapon"))
        {
           write("你已经有一样黄金武器了。\n");
           return ;
        }
        
        
        if(!series_no) series_no = 1;
        else series_no = series_no + 1;	
        
        		
	if(base->query("old_long")) fabao_long = HIY""+base->query("old_long")+"上面隐约金色闪现"NOR;
	else fabao_long = HIY""+base->query("long")+"上面隐约金色闪现"NOR;

//              weapon_dir = "/std/weapon/";
              weapon_dir = "/clone/weapon/";
	        ob_file = "none";
	       // std/armor/cloth
	        if(weapon_type=="axe") ob_file = weapon_dir + "axe";
	        if(weapon_type=="blade") ob_file = weapon_dir + "blade";
	        if(weapon_type=="spear") ob_file = weapon_dir + "spear";
	        if(weapon_type=="axe") ob_file = weapon_dir + "axe";
                if(weapon_type=="fork") ob_file = weapon_dir + "fork";
                if(weapon_type=="hammer") ob_file = weapon_dir + "hammer";
                if(weapon_type=="mace") ob_file = weapon_dir + "mace";
                if(weapon_type=="rake") ob_file = weapon_dir + "rake";
                if(weapon_type=="sword") ob_file = weapon_dir + "sword";
                if(weapon_type=="staff") ob_file = weapon_dir + "staff";
                if(weapon_type=="stick") ob_file = weapon_dir + "stick";
                if(weapon_type=="whip") ob_file = weapon_dir + "whip";
		if(ob_file=="none") 
	        {
	          write("这样东西不能生成黄金装备。\n");
	          return;
	        }
	         
	
	newob = new("/d/baoshi/weapon/base");
	if(!newob) 
	{ 
	   write("黄金装备生成失败,请通知巫师。\n");
	   return;
	}
	
	seteuid(fabao_id);
	rev = export_uid(newob);
	seteuid(getuid());

	newob->set("value", 0);
	newob->set("no_get", 1);	
	newob->set("no_sell", 1);	
	newob->set("no_give", 1);	
	newob->set("no_drop", 1);	
	newob->set("no_put", 1);	
	newob->set("no_steal", 1);	
	newob->set("no_zm", 1);	
	newob->set("gold", 1);	
	newob->set("gold_weapon", 1);	
	
	
	newob->set("weapon_prop/dodge", 10+random(50));		
	newob->set("weapon_prop/damage", 100+random(50));		
	newob->set("weight", 10000);
	// anything else need to be set?
	
	
	
	// Add ob_file if you can find the same kind of file
	
           
	
	
	newob->set_default_object(ob_file);
	
	
	newob->set("long", fabao_long);
        newob->set("unit", fabao_unit);
	id_list = ({ fabao_id });
	t_list = explode( fabao_id, "_");
	if( sizeof(t_list) > 1 ) {
		id_list += t_list;
	}
	newob->set_name( fabao_name, id_list ); 
	
	// set owner of fabao
	newob->set("owner_id", getuid(ob));
	newob->set("default_file", ob_file);
        newob->set("series_no",series_no);
        newob->set("spi",10+random(50));
        newob->set("skill_type",weapon_type);
        newob->save();	
        ob->set("gold/gold_num",gold_num);
	ob->set("gold/series_no",series_no);
	ob->add("force", -200);
	ob->add("mana", -200);
	ob->set("gold/weapon",  series_no);
	
	newob->setup();
	if( !newob->move(ob) )
	   newob->move(environment(ob));
	ob->add("daoxing",-1*gold_num*100000);
	ob->save();
        message_vision(newob->query("name")+"上的五颗宝石突然腾空而起，回旋在四周,最后化做一道金光钻入了"+newob->query("name")+"中。\n",ob);
        message_vision(newob->query("name")+"上隐约有暗金闪现。\n",ob);
        message("channel:rumor",HIG"【"+HIR"奇珍异宝"+HIG"】"+HIM+"某人：听说"HIW+ob->query("name")+HIM"得到一件传说中的"+HIY"黄金"+newob->query("name")+"了！\n"NOR,users() );
 
	destruct(base);
  	return;
}
int check_baoshi(object ob)
{
   int gold_armor = 1;
   if(!ob->query("inset_r")) gold_armor = 0;
   if(!ob->query("inset_z")) gold_armor = 0;
   if(!ob->query("inset_b")) gold_armor = 0;
   if(!ob->query("inset_g")) gold_armor = 0;
   if(!ob->query("inset_y")) gold_armor = 0;
   return gold_armor;
}





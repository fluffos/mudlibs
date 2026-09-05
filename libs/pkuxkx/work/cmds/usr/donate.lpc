// 给襄阳捐献兵器盔甲，得道德


inherit F_CLEAN_UP;

int calc_value(object ob)
{
    int value;
    //视攻击和防御力定
    //让道德涨幅随武器和装备的攻击力防御力稀有程度作递增
    if ( ob->query("armor_type") == "neck" ||
           ob->query("armor_type") == "finger" )
    {
        value = ob->query("armor_prop/armor") * 4;
        if ( value >= 120 &&
               value < 160 ) 
            value+=( value - 120 ) * 6;
        else if ( value >= 160 )
            value+= 240 + ( value - 160 ) * 6;
    }
    else if ( ob->query("armor_type") == "shield" ||
                ob->query("armor_type") == "armor" )
    {
        value = ob->query("armor_prop/armor") / 2;
        if ( value >= 150 &&
               value < 200 )
          value+=( value - 150 ) * 4;
        else if ( value >= 200 )
          value+= 200 + ( value - 200 ) * 9;
    }
    else if ( ob->query("armor_type") )
    {
        value = ob->query("armor_prop/armor") * 2;
        if ( value >= 400 )
            value = value * 2;
        else if ( value >= 140 &&
             value < 170 )
          value+=( value - 140 ) * 4;
        else if ( value >= 170 )
          value+= 120 + ( value - 170 ) * 9;
    }
    else if ( ob->query("skill_type") &&
                ob->query("weapon_prop/damage") )
    {
        value = 2 * ob->query("weapon_prop/damage");
        if ( value >= 200 &&
               value < 400 )
            value+= ( value - 200 ) * 2;
        else if ( value >= 400 )
            value+= 400 + ( value - 400 ) * 10;
    }
    
//        value = ob->query("armor_prop/armor") + 2 * ob->query("weapon_prop/damage");
    //随机装备还要看孔数 高孔数的装备有额外道德加成
    if(ob->query("forge/max") > 0)
    {
        value = value * (ob->query("forge/max") + 1);
        if ( ( ob->query("armor_type") == "neck" ||
                ob->query("armor_type") == "finger" ) &&
               ob->query("forge/max") >= 2 )
            value = value * ob->query("forge/max");
          else if ( ob->query("forge/max") >= 3 )
            value = value * ob->query("forge/max");        	  	
    }
    value = value / 2;
    if(ob->query_temp("from_dealer"))
    {
        value = value / 10;
    }
    
    if(ob->query_amount()>0 )
      value=value/5;
    
    if(value < 1) value = 1;

    value += random(value);
    return value;
}
int main(object me, string arg)
{
    object ob;
    int value;
    
    if(!arg || !objectp(ob=present(arg,me))) 
    {
        return notify_fail("什么？\n");
    }
        
    if(me->is_busy() || me->is_fighting())
    {
        return notify_fail("你正忙着呢。\n");
    }
    
    if(ob->is_equip() == 1 && 
    	 !ob->query("no_give") && 
    	 !ob->query("gem_ob_autoloaded") &&
    	 !ob->query("auto_load") )
    {
        value = calc_value(ob);

        write("你把"+ob->name()+"交给一名襄阳来的士兵。他对你表示感谢。\n");
        write("你的道德增加了"+chinese_number(value)+"点\n");
        me->add("shen",value);
        me->add_busy(1);
        if(ob->query_amount()>0 )
          ob->add_amount(-1);
        else        
          destruct(ob);
        return 1;
    }
    else
    {
        return notify_fail("保卫襄阳急需兵器盔甲。\n");        
    }
    
	return 1;

}
int help(object me)
{
	write(@HELP
指令格式：donate 武器/盔甲的ID
捐赠武器盔甲，保卫襄阳。
HELP
	);
	return 1;
}

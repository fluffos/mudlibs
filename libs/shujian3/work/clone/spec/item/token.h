string s_power(int i)
{	
	if( i >= 60 )	return RED"开元创世"NOR;
	if( i >= 50 )	return HIR"天下无双"NOR;	
	if( i >= 40 )	return HIY"举世无匹"NOR;
	if( i >= 30 )	return HIM"无与伦比"NOR;	
	if( i >= 20 )	return HIC"极高"NOR;
	if( i >= 15 )	return YEL"很高"NOR;	
	if( i >= 10 )	return WHT"不错"NOR;	
	if( i >= 5 )	return GRN"一般"NOR;	
	return BLU"低劣"NOR;
}

void token_reload()
{
	string str;
	int i;
	if(mapp(this_player()->query("token/"+query("id"))))
	{			
		if (i=this_player()->query("token/"+query("id")+"/armor")) 
		{
			set("armor_prop/armor",i);
			str="防御力";
		}	
		else if (i=this_player()->query("token/"+query("id")+"/parry"))
		{
			set("armor_prop/parry",i);
			str="格挡率";
		}
		else if (i=this_player()->query("token/"+query("id")+"/dodge"))
		{
			set("armor_prop/dodge",i);
			str="躲避率";
		}
		set("long",query("long")+" "+this_player()->query("token/"+query("id")+"/desc")+NOR"\n"
			+"\n这个"+query("name")+"看起来有着"+s_power(i)+"的"+str+"。\n");
		wear();
	}
}

int do_discard(string arg)
{
	object me = this_player();
	if (arg!=query("id"))
      		return notify_fail("你要丢弃什么?\n");
 	
	tell_object(me, "你要丢弃"+query("name")+"？请"ZJURL("cmds:Y")ZJSIZE(20)"确定"NOR" or "ZJURL("cmds:N")ZJSIZE(20)"取消"NOR"。\n");

	input_to("confirm_discard",me);
      	return 1;
}

private void confirm_discard(string arg,object me)
{
	if( arg[0]=='y' || arg[0]=='Y' )
	{
		me->delete("token/"+query("id"));
		write("你卸下"+query("name")+"轻轻地丢到没人注意的脚落。\n");
		destruct(this_object());
	}
	else
	{
		write("\n你决定保留"+ query("name")+"。\n");
	}
}

int query_autoload()
{
	return 1;
}

int unequip()
{
	object ob = environment();

	if (ob && userp(ob))
		return notify_fail("如果不想戴了你就把它丢弃(discard)了吧。\n");

	return ::unequip();
}
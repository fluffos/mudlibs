string s_power(int i)
{
	if( i >= 18 )	return HIW"极高"NOR;
	if( i >= 14 )	return HIG"很高"NOR;	
	if( i >= 7 )	return HIY"不错"NOR;		
	return "一般";
}

void token_reload()
{
	string str;
	int i;
	if(mapp(this_player()->query("token/"+query("id"))))
	{			
		if (i=this_player()->query("token/"+query("id")+"/parry")) 
		{
			set("armor_prop/parry",i);
			str="防御力";
		}	
		if (i=this_player()->query("token/"+query("id")+"/dodge"))
		{
			set("armor_prop/dodge",i);
			str="躲避率";
		}
		set("long",query("long")+" "+this_player()->query("token/"+query("id")+"/desc")+"\n"NOR
			+"\n这个"+query("name")+"看起来有着"+s_power(i)+"的"+str+"。\n");
		wear();
	}
}

int do_discard(string arg)
{
	object me = this_player();
	if (arg!=query("id"))
      		return notify_fail("你要丢弃什么?\n");
      	
      	write("你要丢弃"+query("name")+",确定吗？[Y|N]：");
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
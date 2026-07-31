// money.c

inherit COMBINED_ITEM;

int value() { return query_amount() * (int)query("base_value"); }

void give_money(object who)
{
	if( !who || !present(this_object(),who) )
	{
		delete("check");
		return;
	}
	who->money_add(value());
	who->save();
	tell_object(who,"你得到了"+MONEY_D->money_str(value())+"。\n");
	destruct(this_object());
}

void init()
{
	object me = this_player();
	if( present(this_object(),me)
	 && userp(me) && !query("check") )
	{
		set("check",1);
		remove_call_out("give_money");
		call_out("give_money",random(3),me);
	}	 
}
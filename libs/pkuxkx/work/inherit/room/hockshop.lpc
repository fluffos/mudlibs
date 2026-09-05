// hockshop.c

inherit ROOM;

void init()
{
	add_action("do_value", "value");
	add_action("do_pawn", "pawn");
	add_action("do_sell", "sell");
}

string value_string(int value)
{
	if( value < 1 ) value = 1;
	else if( value < 100 )
		return chinese_number(value) + "文钱";
	else
		return chinese_number(value/100) + "两"
			+ (value%100? "又" + chinese_number(value%100) + "文钱": "");
}

void pay_player(object who, int amount)
{
	object ob;

	if( amount < 1 ) amount = 1;
	if( amount/100 ) {
		ob = new(SILVER_OB);
		ob->set_amount(amount/100);
		ob->move(who);
		amount %= 100;
	}
	if( amount ) {
		ob = new(COIN_OB);
		ob->set_amount(amount);
		ob->move(who);
	}
}

int do_value(string arg)
{
	object ob;
	int value;

	if( !arg || !(ob = present(arg, this_player())) )
		return notify_fail("你要拿什么物品给当铺估价？\n");

	if( ob->query("money_id") )
		return notify_fail("这是「钱」，你没见过吗？\n");

	value = ob->query("value");
	if( !value ) printf("%s一文不值。\n", ob->query("name"));
	else 
		printf("%s价值%s。\n如果你要典当(pawn)，可以拿到%s及一张当票。\n如果卖断(sell)，可以拿到%s。\n",
			ob->query("name"), value_string(value),
			value_string(value * 60 / 100), value_string(value * 80 / 100));

	return 1;
}

int do_pawn(string arg)
{
	object ob;
	int value;

	if( !arg || !(ob = present(arg, this_player())) )
		return notify_fail("你要典当什么物品？\n");
            if (ob->query("shaolin"))
                return notify_fail("少林的宝物小的可不敢要呀！\n");
            if (ob->query("mingjiao"))
                return notify_fail("魔教的财产小的可不敢要呀！\n");
            if (ob->query("chaoting"))
                return notify_fail("大内的物品小的可不敢要呀！\n");
            if (ob->query("zijin"))
                return notify_fail("大内的物品小的可不敢要呀！\n");
            if (ob->query("no_pawn")||ob->query("no_sell")||ob->query("no_store"))
                return notify_fail("这样东西不能当。\n");


	if( ob->query("money_id") )	return notify_fail("你要当「钱」？\n");

	value = ob->query("value");
        if( value<2 ) return notify_fail("这样东西不值钱。\n");

	message_vision("$N把身上的" + ob->query("name") + "拿出来典当了"
		+ value_string(value * 60 / 100) + "。\n", this_player());

	pay_player(this_player(), value * 60 / 100);
	destruct(ob);

	return 1;
}

int do_sell(string arg)
{
	object ob;
	int value;

	if( !arg || !(ob = present(arg, this_player())) )
		return notify_fail("你要卖断什么物品？\n");
            if (ob->query("shaolin"))
                return notify_fail("少林的宝物小的可不敢要呀！\n");
            if (ob->query("mingjiao"))
                return notify_fail("魔教的财产小的可不敢要呀！\n");
            if (ob->query("chaoting"))
                return notify_fail("大内的物品小的可不敢要呀！\n");
            if (ob->query("no_pawn"))
                return notify_fail("这种东西小的可不敢收。\n");

	if( ob->query("money_id") )	return notify_fail("你要卖「钱」？\n");
	value = ob->query("value");
        if( value<2 ) return notify_fail("这样东西不值钱。\n");
        //从!value改过来，避免卖一文钱的东西时出现0 iszt, 2006-09-02


	message_vision("$N把身上的" + ob->query("name") + "卖掉。\n",
		this_player());

	pay_player(this_player(), value * 80 / 100);
	destruct(ob);

	return 1;
}


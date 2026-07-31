// moneyd.c  钱的功能

#pragma optimize
#pragma save_binary

string money_str(int amount)
{
        string output;

        if (amount / 10000) {
                output = (amount / 10000) + "金";
                amount %= 10000;
        }
        else
                output = "";
        if (amount / 100) {
                output = output + (amount / 100) + "银";
                amount %= 100;
        }
        if (amount)
                return output + (amount) + "铜";
        return output;
}

string price_str(int amount)
{
	string output;

        if (amount < 1)
                amount = 1;

        if (amount / 10000) {
                output = chinese_number(amount / 10000) + "金";
                amount %= 10000;
        }
        else
                output = "";
        if (amount / 100) {
		if (output != "")
                	output += "又" + chinese_number(amount / 100) + "银";
		else
			output = chinese_number(amount / 100) + "银";
                amount %= 100;
        }
        if (amount)
		if (output != "")
                	return output + "又" + chinese_number(amount) + "铜";
		else
			return chinese_number(amount) + "铜";
        return output;
}

void pay_player(object who, int amount)
{
	int v;
	object ob;

	seteuid(getuid());
	if (amount < 1)
		amount = 1;
	if (v = amount / 100000)
	{
		ob = new(CASH_OB);
		ob->set_amount(amount / 100000);
		ob->move(who, 1);
		amount %= 100000;
	}
	if (v = amount / 10000)
	{
		ob = new(GOLD_OB);
		ob->set_amount(amount / 10000);
		ob->move(who, 1);
		amount %= 10000;
	}
	if (amount / 100)
	{
		ob = new(SILVER_OB);
		ob->set_amount(amount / 100);
		ob->move(who, 1);
		amount %= 100;
	}
	if (amount)
	{
		ob = new(COIN_OB);
		ob->set_amount(amount);
		ob->move(who, 1);
	}
}

int player_pay(object who, int amount)
{
	object t_ob, g_ob, s_ob, c_ob;
	int tc, gc, sc, cc, left;
	int v;

	seteuid(getuid());

	if (t_ob = present("cash_money", who))
		tc = t_ob->query_amount();
	else
		tc = 0;

	if (g_ob = present("gold_money", who))
		gc = g_ob->query_amount();
	else
		gc = 0;

	if (s_ob = present("silver_money", who))
		sc = s_ob->query_amount();
	else
		sc = 0;

	if (c_ob = present("coin_money", who))
		cc = c_ob->query_amount();
	else
		cc = 0;
	
	v = cc + sc * 100 + gc * 10000 + tc * 100000;

	if (v < amount) 
		return 0;
	else {
		left = v - amount;

		tc = left / 100000;
		left %= 100000;

		gc = left / 10000;
		left = left % 10000;

		sc = left / 100;
		cc = left % 100;

		if (!t_ob && tc)
		{
			t_ob = new(CASH_OB);
			t_ob->move(who, 1);
		}
		if (!g_ob && gc)
		{
			g_ob = new(GOLD_OB);
			g_ob->move(who, 1);
		}
		if (!s_ob && sc)
		{
			s_ob = new(SILVER_OB);
			s_ob->move(who, 1);
		}
		if (!c_ob && cc)
		{
			c_ob = new(COIN_OB);
			c_ob->move(who, 1);
		}

		if (t_ob)
			t_ob->set_amount(tc);
		if (g_ob)
			g_ob->set_amount(gc);
		if (s_ob)
		 	s_ob->set_amount(sc);
		if (c_ob)
			c_ob->set_amount(cc);

		return 1;
	}
}

int player_carry(object ob)
{
        object cash_ob;
        object gold_ob;
        object silver_ob;
        object coin_ob;
        int gold;

        gold = ob->query("balance") / 10000;

        cash_ob = present("cash_money", ob);
        gold_ob = present("gold_money", ob);
        silver_ob = present("silver_money", ob);
        coin_ob = present("coin_money", ob);
        if (cash_ob) gold += cash_ob->query_amount() * 10;
        if (gold_ob) gold += gold_ob->query_amount();
        if (silver_ob) gold += silver_ob->query_amount() / 100;
        if (coin_ob)   gold += coin_ob->query_amount() / 10000;
        return gold;
}


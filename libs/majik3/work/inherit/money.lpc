/*
 *    majik monetary system / money object
 * 
 *    coder                   dazzt
 * */

inherit BASE;

/* --- -- - variables - -- --- */

int amount;                         /* amount of coins in this stack        */
int weight;                         /* how much do these coins weigh?       */
int bmuvalue;                       /* value of one coin in BMU's           */

string coin_name;                   /* the name of the coin (florine)       */
string coin_material;               /* material coins are made from (gold)  */

/* --- function prototypes --- */

set_amount(int);
set_value(int);
add_amount(int);

set_coin_name(string);
set_coin_material(string);

int query_amount();
int query_value();
int query_bmuvalue();
int query_weight();

/* --- -- - -- - - -- - -- --- */

// create()                         (driver apply)
// coder                            dazzt

create()
{
	set_name(({ "coin", "coins", "money" }));
	amount = 0;
	bmuvalue = 0;
	THOB->create_money();
	set_no_clean_up(1);
}

// short()
// coder                            dazzt

string short()
{
	string str;
	string *n = ({ "zero", "one", "two", "three", "four", "five", "six", "seven", 
			"eight", "nine", "ten" });

	if (amount == 0)
		return "money object (empty)";
		
	if (amount == 1)
	{
		if (member_array(coin_material[0..0], ({ "a", "e", "i", "o", "u" })) == -1)
			str = "a ";
		else
			str = "an ";
		str += coin_material + " " + coin_name;
		return str;
	}

	if (amount <= 10)
		str = n[amount];
	else
		str = sprintf("%d", amount);

	str += " " + coin_material + " " + pluralize(coin_name);
	return str;
}

int move(mixed targ)
{
	object ob;
	
	ob = present(coin_material + " " + coin_name, targ);
	if (ob)
	{
		ob->add_amount(amount);
		THOB->add_amount(-amount);
	}
	else if (targ)
		move_object(targ);
	return 1;
}

set_coin_name(string str) 
{
	coin_name = str;
	set_name(({ "coin", "coins", "money", "money_object", coin_name, 
			coin_material, pluralize(coin_name), coin_material + " " + coin_name }));
	return str;  
}

set_coin_material(string str) 
{
	coin_material = str;
	set_name(({ "coin", "coins", "money", "money_object", coin_name, 
			coin_material, pluralize(coin_name), coin_material + " " + coin_name }));
	return str; 
}

int add_amount(int i)
{
	amount += i;
	weight += 3 * i;
	if (amount == 0)
		destruct(THOB);
	
	return amount;
}

int set_amount(int i)
{
	amount = i;
	weight = 3 * i;
	if (amount == 0)
		destruct(THOB);
	
	return i;
}

set_value(int i)       { return bmuvalue = i; }
int query_value()      { return amount * bmuvalue; }
int query_bmuvalue()   { return bmuvalue; }
int query_amount()     { return amount; }
int query_weight()     { return weight; }
int get()	           { return 1; }
string query_author()  { return "dazzt"; }
int is_money()         { return 1; }




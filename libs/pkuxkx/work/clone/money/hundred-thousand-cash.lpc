// thousand.c

inherit MONEY;

void create()
{
          set_name("十万两银票", ({"hundred-thousand-cash", "cash","cash_money", "hundred-thousand-cash_money"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("money_id", "hundred-thousand-cash");
                  set("long", "一张面额值十万两银子的银票。\n");
		set("unit", "叠");
                   set("base_value", 10000000);
		set("base_unit", "张");
                set("base_weight", 1);
	}
	set_amount(1);
}


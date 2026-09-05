#pragma save_binary
// million.c

inherit MONEY;

void create()
{
	set_name("十亿两银票", ({"billion-cash", "billion-cash_money", "cash"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("money_id", "billion-cash");
		set("long", "一张面额值十亿两银子的银票。\n");
		set("unit", "叠");
		set("base_value", 100000000000);
		set("base_unit", "张");
		set("base_weight", 5);
	}
	set_amount(1);
}


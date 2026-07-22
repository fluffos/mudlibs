// silver.c

inherit MONEY;

void create()
{
	set_name("三钱散碎银子", ({"sanqian_silver", "ingot", "silver_money"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("money_id", "silver");
		set("long", "白花花的银子，人见人爱的银子。\n");
		set("unit", "块");
		set("base_value", 30);
		set("base_unit", "块");
		set("base_weight", 10);
	}
	set_amount(1);
}


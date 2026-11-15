

inherit COMBINED_ITEM;
string query_autoload() { return query_amount() + ""; }

void autoload(string param)
{
	int amt;

	if (sscanf(param, "%d", amt) == 1)
		set_amount(amt);
}

void setup()
{
	set_amount(1);
	::setup();
}

void create()
{
	set_name(HIY "挑战令牌" NOR, ({ "tiaozhan ling" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是从侠客岛传出的一块挑战令牌。\n");
		set("base_unit", "块");
		set("base_value", 500000);
		set("yuanbao", 10);
		set("base_weight", 1);
	}
	setup();
}


inherit COMBINED_ITEM;

void create_veg(mapping veg_info)
{
	set_name(veg_info["name"], ({veg_info["id"]}));
	set("long", "这是一棵" + veg_info["name"] + "。\n");
	set("base_unit", "棵");
	set("base_value", 1);
	set("base_weight", 1);
	set("no_sell", 1);
	set("veg_info", ([
		]));
	set_amount(1);
	setup();
}

string query_autoload() { return query_amount() + ""; }

void autoload(string param)
{
	int amt;

	if (sscanf(param, "%d", amt) == 1)
		set_amount(amt);
}

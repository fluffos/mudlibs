inherit COMBINED_ITEM;

void create_meat(mapping meat_info)
{
    set_name(meat_info["name"], ({ meat_info["id"] }));
    set("base_unit", "块");
    set("long", "这是" + meat_info["name"] + "。\n");
    set("base_weight", 1);
    set("base_value", 1);
    
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
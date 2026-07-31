
inherit COMBINED_ITEM_BANG;
inherit F_LIQUID;

void create()
{
	set_name(HIG"五宝花蜜酒"NOR, ({"wu bao", "wine"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一个用来装酒的酒壶·。\n");
		set("base_unit", "壶");
		set("base_weight",300);
		set("unit", "壶");
		set("base_value", 50000);
		set("max_liquid", 10);
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"type": "alcohol",
		"name": "五宝花蜜酒",
		"bei": "暂无",
		
		"drunk_apply": 10,
	]));
	setup();
	set_amount(1);
}

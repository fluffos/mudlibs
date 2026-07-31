

inherit COMBINED_ITEM_BANG;
inherit F_LIQUID;

void create()
{
	set_name(HIW"ÓñÂ¶¾ÆÌ³"NOR, ({"yulu jiu", "wine"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "Ò»¸öÓÃÀ´×°¾ÆµÄ¾ÆÌ³¡£\n");
		set("base_unit", "Ì³");
		set("base_weight",300);
		set("unit", "Ì³");
		set("base_value", 100);
		set("max_liquid", 10);
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"type": "alcohol",
		"name": "ÓñÂ¶¾Æ",
		"bei": "ÁğÁ§±­",
		
		"drunk_apply": 15,
	]));
	setup();
	set_amount(1);
}

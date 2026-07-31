
inherit COMBINED_ITEM_BANG;
inherit F_LIQUID;

void create()
{
	set_name(HIC"¶Å¿µ¾Æ"NOR, ({"du kang", "wine"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "Ò»¸öÓÃÀ´×°¾ÆµÄ¾ÆÌ³¡£\n");
		set("base_unit", "Ì³");
		set("base_weight",300);
		set("unit", "Ì³");
		set("base_value", 30000);
		set("max_liquid", 10);
		set("end",1);
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"type": "alcohol",
		"name": "¶Å¿µ¾Æ",
		"bei": "ÔÝÎÞ",
		
		"drunk_apply": 4,
	]));
	setup();
	set_amount(1);
}

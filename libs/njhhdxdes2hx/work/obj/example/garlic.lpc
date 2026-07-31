// garlic.c

inherit COMBINED_ITEM;

void create()
{
	set_name("大蒜", ({"garlic"}) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "大蒜是常见的调味品。\n");
		set("unit", "些");
		set("base_unit", "颗");
		set("base_weight", 20);
		set("base_value", 5);
		set("medical_effect/水", ({ 3, 2, -2 }) );
	}
	set_amount(1);
}

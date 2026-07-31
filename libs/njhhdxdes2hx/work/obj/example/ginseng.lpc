// ginseng.c

inherit COMBINED_ITEM;

void create()
{
	set_name("人参", ({"ginseng"}) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "人参是一种有名的补品。\n");
		set("unit", "些");
		set("base_unit", "枝");
		set("base_weight", 70);
		set("base_value", 400);
		set("medical_effect/木", ({ 6, 5, 10 }) );
	}
	set_amount(1);
}

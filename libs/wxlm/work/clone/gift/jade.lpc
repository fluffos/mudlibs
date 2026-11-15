// jade.c 翡翠


inherit COMBINED_ITEM;

void create()
{
	set_name(HIG "翡翠" NOR, ({ "jade" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", HIG "一块碧透欲滴的翡翠。"NOR"\n");
		set("base_value", 50000);
		set("base_weight", 1);
		set("base_unit", "块");
		set("can_be_enchased", __DIR__"fjade");
		set("enchased_need", 3);
		set("magic/type", "cold");
		set("magic/power", 60);
	}
	set_amount(1);
	setup();
}

// jinsha.c


inherit COMBINED_ITEM;
void setup()
{
	set_amount(1);
	::setup();
}

void create()
{
	set_name(HIY "金砂" NOR, ({ "jin sha" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "用来强化装备的道具。\n");
		set("base_unit", "粒");
		set("base_value", 500);
		set("yuanbao", 10);
		set("item_exp",2500);
		set("base_weight", 1);
	}
	setup();
}


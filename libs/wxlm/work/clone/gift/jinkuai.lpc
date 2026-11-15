// jinkuai.c 金块



inherit ITEM;

void create()
{
	set_name(YEL "金块" NOR, ({ "jin kuai", "jin", "kuai" }));
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一锭黄澄澄的金块。\n");
		set("value", 2000000);
		set("suit_point",30);
		set("unit", "锭");
	}
}


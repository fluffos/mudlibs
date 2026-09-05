// fish

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(HIY"金色鲤鱼"NOR, ({"fish", "yu"}));
	set_weight(40);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", HIY"一条金色大鲤鱼。\n"NOR);
		set("unit", "条");
		set("value", 100);
	}
}


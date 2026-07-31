// by tie@fengyun

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("√‚»‚", ({"liewu1"}) );
	set_weight(50000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "“ªøÈ√‚»‚\n");
		set("unit", "øÈ");
		set("value", 250);
		set("food_remaining", 3);
		set("food_supply", 60);

		set("no_get",1);
		set("no_give",1);
		set("no_steal",1);

		set("no_put",1);
	}
}

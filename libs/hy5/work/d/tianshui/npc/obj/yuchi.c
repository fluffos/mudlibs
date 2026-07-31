// yuchi.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("飞花鱼翅", ({ "yuchi"}) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "由醉仙阁精心烹制的飞花鱼翅。\n");
		set("unit", "份");
		set("value", 2000);
		set("food_remaining", 4);
		set("food_supply", 20);
	}
	setup();
}
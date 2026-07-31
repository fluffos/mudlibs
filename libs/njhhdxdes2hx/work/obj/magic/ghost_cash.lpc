// ghost_cash.c

inherit COMBINED_ITEM;

void create()
{
	set_name("冥纸", ({ "ghost cash", "cash" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "这是人们用来烧给阴间亲友的冥纸，也就是俗称的纸钱。\n");
		set("unit", "叠");
		set("material", "paper");
		set("base_unit", "张");
		set("base_weight", 3);
		set("base_value", 1);
	} 
	set_amount(1);
}

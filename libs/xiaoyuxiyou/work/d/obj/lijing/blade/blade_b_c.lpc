#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()
{
	set_name(HIR"鬼头刀"NOR, ({"blade","dao"}) );
	set_weight(7500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("value", 50000);
                set("no_put",1);
                set("no_zm",1);
		set("material", "iron");
		set("long", "这是一柄寻常的长刀。\n");
		set("wield_msg", "$N抽出一把$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插入腰间的刀鞘。\n");
	}
	init_blade(120);
	setup();
}

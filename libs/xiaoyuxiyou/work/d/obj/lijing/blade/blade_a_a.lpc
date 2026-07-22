#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()
{
	set_name(HIG"冷月刀"NOR, ({"blade","dao"}) );
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("value", 10000);
                set("no_put",1);
                set("no_zm",1);
		set("material", "iron");
		set("long", "这是一柄寻常的长刀。\n");
		set("wield_msg", "$N抽出一把$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插入腰间的刀鞘。\n");
	}
	init_blade(100);
	setup();
}

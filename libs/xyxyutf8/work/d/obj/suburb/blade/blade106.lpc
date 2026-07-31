#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()
{
	set_name(HIC"天残月弯刀"HIR"("HIY"力量"HIR")"NOR, ({ "blade","dao"}) );
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("material", "steel");
		set("value", 100000);
                set("no_put",1);
                set("no_dzm",1);
                set("no_zm",1);
                set("weapon_prop/strength", 30);
		set("long", "这是一件传说中的神器。\n");
		set("wield_msg", "$N抽出一把$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插入腰间的刀鞘。\n");
	}
	init_blade(150+random(50));
	setup();
}

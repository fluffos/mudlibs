#include <weapon.h>
#include <ansi.h>
inherit WHIP;
void create()
{
	set_name(HIC"七定混天索"HIR"("HIY"幸运"HIR")"NOR, ({ "whip","bian"}) );
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
                set("weapon_prop/karma", 30);
		set("long", "这是一件传说中的神器。\n");
		set("wield_msg", "只听「啪」的一声响，$N的手中闪出一条$n。\n");
		set("unwield_msg", "$N把手中$n缠回腰间．\n");
	}
	init_whip(150+random(50));
	setup();
}

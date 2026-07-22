#include <weapon.h>
#include <ansi.h>
inherit AXE;
void create()
{
	set_name(HIC"九宫定神斧"HIR"("HIY"气血诅咒"HIR")"NOR, ({ "axe","fu"}) );
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
		set("long", "这是一件传说中的神器。\n");
		set("wield_msg", "$N拿出一把$n，握在手中当作武器。\n");
		set("unwield_msg", "$N放下手中的$n。\n");
	}
	init_axe(150+random(50));
	setup();
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
        victim->receive_damage("kee",50);
        return HIG "九宫定神斧一震，$N的眼里映着九宫定神斧闪出的诡异光芒．．．\n" NOR;
}
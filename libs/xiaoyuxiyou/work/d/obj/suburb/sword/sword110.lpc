#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void create()
{
	set_name(HIC"天罡巨阕剑"HIR"("HIY"精神诅咒"HIR")"NOR, ({ "sword","jian"}) );
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
        	set("wield_msg","一道金光闪过，$N手中已多了把$n。\n");
        	set("unwield_msg", "$N放下手中的$n。\n");
	}
	init_sword(150+random(50));
	setup();
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
        victim->receive_damage("sen",50);
        return HIG "九宫定神斧一震，$N的眼里映着九宫定神斧闪出的诡异光芒．．．\n" NOR;
}
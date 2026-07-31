#include <weapon.h>
#include <ansi.h>
inherit FORK;
void create()
{
	set_name(HIC"寸阴若梦叉"HIR"("HIY"精神诅咒"HIR")"NOR, ({ "fork","cha"}) );
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
                set("wield_msg", "$N抄起一柄$n，还拿衣服擦了擦叉尖。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
	}
	init_fork(150+random(50));
	setup();
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
        victim->receive_damage("sen",50);
        return HIG "九宫定神斧一震，$N的眼里映着九宫定神斧闪出的诡异光芒．．．\n" NOR;
}
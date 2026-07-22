#include <weapon.h>
#include <ansi.h>
inherit STAFF;
void create()
{
	set_name(HIC"紫玉龙须杖"HIR"("HIY"幸运"HIR")"NOR, ({ "staff","zhang"}) );
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
		set("wield_msg", "$N拿出一把$n，握在手中当作武器。\n");
		set("unwield_msg", "$N放下手中的$n。\n");
	}
	init_staff(150+random(50));
	setup();
}

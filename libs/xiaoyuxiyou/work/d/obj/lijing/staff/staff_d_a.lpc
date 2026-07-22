#include <weapon.h>
#include <ansi.h>
inherit STAFF;
void create()
{
	set_name(HIC"拨云扫月杖"NOR, ({"staff","zhang" }) );
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "根");
                set("no_put",1);
                set("no_zm",1);
		set("value", 500000);
		set("material", "steel");
		set("weapon_prop/intelligence", 3);
		set("long","这是一件传说中的神器。\n");
                set("wield_msg","$N拿出一把$n，握在手中。\n");
                set("unwield_msg", "$N放下手中的$n。\n");		
	}
        init_staff(170+random(20));
	setup();
}

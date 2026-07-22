#include <weapon.h>
#include <ansi.h>
inherit STAFF;
void create()
{
	set_name(HIY"击顶金瓜"NOR, ({"staff","zhang" }) );
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "根");
                set("no_put",1);
                set("no_zm",1);
		set("value", 200000);
		set("material", "steel");
		set("weapon_prop/courage", 5);
		set("long","这是一件上古宝物。\n");
                set("wield_msg","$N拿出一把$n，握在手中。\n");
                set("unwield_msg", "$N放下手中的$n。\n");		
	}
        init_staff(150);
	setup();
}

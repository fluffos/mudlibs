#include <weapon.h>
#include <ansi.h>
inherit STAFF;
void create()
{
	set_name(HIR"白骨杖"NOR, ({"staff","zhang" }) );
	set_weight(7500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "根");
                set("no_put",1);
                set("no_zm",1);
		set("value", 50000);
		set("material", "steel");
		set("long","这是一把禅杖，上面几个铁环叮当作响．\n");
                set("wield_msg","$N拿出一把$n，握在手中。\n");
                set("unwield_msg", "$N放下手中的$n。\n");		
	}
        init_staff(120);
	setup();
}

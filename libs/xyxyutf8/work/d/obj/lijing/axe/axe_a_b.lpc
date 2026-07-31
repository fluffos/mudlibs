#include <weapon.h>
#include <ansi.h>
inherit AXE;
void create()
{
	set_name(HIG"宣花斧"NOR, ({ "axe","fu"}) );
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("material", "steel");
		set("value", 10000);
                set("no_put",1);
                set("no_zm",1);
		set("long", "这是把沉重的大斧，有八尺多长，锋利无比．\n");
		set("wield_msg", "$N拿出一把$n，握在手中当作武器。\n");
		set("unwield_msg", "$N放下手中的$n。\n");
	}
	init_axe(100);
	setup();
}

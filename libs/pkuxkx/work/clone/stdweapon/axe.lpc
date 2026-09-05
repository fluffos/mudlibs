// standard axe

#include <ansi.h>
#include <weapon.h>

inherit AXE;

void create()
{
	set_name( color + "名字" + NOR , ({ "ＩＤ" }) );
	set_weight(3000);
	if ( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long", "这是一把沉甸甸的铁斧。\n");
		set("no_get", 1);
		set("no_drop", 1);
		set("no_steal", 1);
		set("auto_load", 1);
		set("unit", "把");
		set("material", "iron");
		set("rigidity", 300);
		set("wield_msg", "$N从腰间取出一把$n，双手紧紧握住。\n");
		set("unwield_msg", "$N将$n顺手别在腰带上。\n");
	}

	init_axe(30);

	setup();
}

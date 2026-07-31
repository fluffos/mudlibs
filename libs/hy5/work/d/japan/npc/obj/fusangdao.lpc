// blade.c

#include <weapon.h>

inherit BLADE;

void create()
{
      set_name("扶桑刀", ({ "fusang dao", "blade", "dao" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
              set("value", 8500);
		set("material", "iron");
            set("long", "这是一把锋利的单刀，泛出一道寒光。\n");
		set("wield_msg", "$N抽出一把明晃晃的$n握在手中。\n");
		set("unequip_msg", "$N将手中的$n插入腰间的刀鞘。\n");
	}
        init_blade(130);
	setup();
}

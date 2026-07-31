#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void create()
{
    set_name(HIC"八卦风魔剑"NOR, ({"sword","jian" }) );
    set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        	set("unit", "柄");
                set("no_put",1);
                set("no_zm",1);
                set("value", 500000);
                set("material", "iron");
                set("weapon_prop/intelligence", 3);
        	set("long", "这是一件传说中的神器。\n");
        	set("wield_msg","一道金光闪过，$N手中已多了把$n。\n");
        	set("unwield_msg", "$N放下手中的$n。\n");
	}
        init_sword(170+random(20));
	setup();
}

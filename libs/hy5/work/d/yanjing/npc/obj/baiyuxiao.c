#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("白玉箫",({"baiyu xiao","xiao"}));
        set_weight(2300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", "通体洁白,只在吹口处有几点朱红．\n");
                set("value", 5000);
                set("material", "stone");
set("wield_msg","$N取出$n,在嘴边吹了两声!\n");;
                set("unwield_msg", "$N吹罢一曲,惆怅得放下手中的$n。\n");
        }

init_sword(20);
        setup();
}


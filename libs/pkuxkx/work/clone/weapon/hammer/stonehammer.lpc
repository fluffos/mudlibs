// stonehammer.c
// Last Modified by winder on May. 25 2001

#include <weapon.h>
inherit HAMMER;

void create()
{
        set_name("石锁", ({"stone hammer","stone", "hammer"}));
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", "一把沉重的石锁。\n");
                set("material", "stone");
                set("wield_msg", "$N“呼”的一声拿起一把石锁。\n");
                set("unwield_msg", "$N放下手中的$n，累得浑身都是臭汗，就快虚脱了。\n");
        }
        init_hammer(25);
        setup();
}



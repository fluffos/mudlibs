#include <weapon.h>

inherit CLUB;

void create()
{
set_name("半截铁枪",({"iron spear","qiang","spear"}));
set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
set("long","这铁枪只剩下半截,枪尖刻了个[扬]字.\n");
set("value",600);
                set("material", "iron");
set("wield_msg","$N拿出一把$n,在手中舞了个枪花!\n");;
                set("unwield_msg", "$N放下手中的$n。\n");
        }

init_club(40);
        setup();
}


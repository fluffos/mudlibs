#include <weapon.h>

inherit CLUB;

void create()
{
        set_name("铁枪", ({"iron spear", "qiang", "spear"}));
        set_weight(9000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把长枪，枪尖略显银光．\n");
                set("value", 500);
                set("material", "iron");
set("wield_msg","$N拿出一把$n,在手中舞了个枪花!\n");;
                set("unwield_msg", "$N放下手中的$n。\n");
        }

init_club(20);
        setup();
}


#include <weapon.h>

inherit HAMMER;

void create()
{
set_name("药锄",({"yao chu"}));
set_weight(1200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit","把");
set("long","一把用来采药材的小锄头.\n");
set("value",1200);
                set("material", "iron");
set("wield_msg","$N掏出一把$n晃了晃.\n");
set("unwield_msg","$放下手中的$n,喘了口气.\n");
        }

        init_hammer(15);
        setup();
}

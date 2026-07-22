
#include <weapon.h>

inherit FORK;

void create()
{
        set_name("镐头", ({"gao tou", "tou","gao"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把镐，是用来开采矿石的。\n");
                set("value", 500);
                set("material", "iron");
                set("wield_msg","$N拿出一把$n，握在手中。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }

        init_fork(25,100,100);
        setup();
}


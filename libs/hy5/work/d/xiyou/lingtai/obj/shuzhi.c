#include <weapon.h>

inherit STAFF;

void create()
{
        set_name("Ê÷Ö¦", ({"shuzhi"}));
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "°Ñ");
                set("material", "wood");
        }
        init_staff(10);
        setup();
}


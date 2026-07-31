#include <weapon.h>

inherit STAFF;

void create()
{
        set_name("Öñ½Ú±Þ", ({"bamboo mace", "mace"}));
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "°Ñ");
                set("value", 500);
                set("material", "wood");
        }

        init_staff(15);
        setup();
}


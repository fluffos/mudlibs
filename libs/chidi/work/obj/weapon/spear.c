#pragma save_binary
// sword.c : an example weapon

#include <weapon.h>

inherit SPEAR;

void create()
{
    set_name("长枪", ({ "long_spear" }) );
    set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit", "杆");
        set("long", "这是一把看起相当普通的长枪，份量大约有二十来斤左右。\n");
                set("value", 400);
                set("material", "steel");
        }
        init_spear(40);

// These properties are optional, if you don't set them, it will use the
// default values.

        set("wield_msg", "$N「唰」地一声抽出一把$n握在手中。\n");
    set("unwield_msg", "$N当的一声将手中的$n竖在地上。\n");

// The setup() is required.

        setup();
}


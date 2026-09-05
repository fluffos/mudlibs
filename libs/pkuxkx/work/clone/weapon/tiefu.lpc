
#include <weapon.h>

inherit AXE;
void create()
{
    set_name("铁斧", ({ "tie fu", "axe"}) );
    set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("value", 1500);
                set("material", "iron");
                set("long", "这是一柄普通的铁斧，不过磨的闪亮闪亮的，看起来还象把利器。\n");
                set("wield_msg","$N抡起一把$n。\n");
                set("unwield_msg", "$N反手将$n别在背后。\n");
        }
        init_axe(50);
        setup();
}

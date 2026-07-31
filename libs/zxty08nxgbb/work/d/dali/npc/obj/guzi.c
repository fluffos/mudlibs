// guzi.c
#include <weapon.h>
inherit THROWING;
void create()
{
        set_name("骰子", ({ "guzi" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",     "骰子除了是一种赌具外，也是一种较轻的暗器。\n");
                set("unit", "把");
                set("base_unit", "枚");
                set("base_weight", 2);
                set("base_value", 10);
        }
        set_amount(200);
        init_throwing(2);
        setup();
}

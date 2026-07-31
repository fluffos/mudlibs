// 常州木梳 /clone/wear/head/mu_shu.c
// by lala, 1997-12-16

#include <armor.h>

inherit HEAD;

void create()
{
    set_name( "常州木梳", ({"mu shu", "mushu"}));
    set_weight( 200 );
    if (clonep())
        set_default_object(__FILE__);
    else {
        set("long", query("name") + "是常州的特产之一。\n");
        set("unit", "把");
        set("value", 400 + random( 500 ) );
        set("armor_prop/personality", 10);
    }
}

 // boot.c
#include <armor.h> 
inherit BOOTS; 
void create()
{
        set_name("¹ƤСѥ", ({ "deer boots","boots" }) );
        set_weight(400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "wood");
                set("unit", "˫");
                set("value", 100);
                set("armor_prop/dodge", 2 );
        }
        setup();
}

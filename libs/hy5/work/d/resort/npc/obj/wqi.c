 // pearl.c
#include <weapon.h> 
inherit THROWING; 
void create()
{
        set_name("°×Æå×Ó", ({ "go piece", "piece" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",     "´¿ºº°×Óñµñ³ÉµÄÆå×Ó¶ù\n");
                set("unit", "¶Ñ");
                set("base_unit", "Á£");
                set("base_weight", 1);
                set("base_value", 1);
        }
        set_amount(99);
        init_throwing(100);
        setup();

}      

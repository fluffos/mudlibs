 // hat.c
#include <armor.h>
inherit HEAD; 
void create()
{
        set_name("×Ï½ð¹Ú", ({ "gold hat", "hat" }) );
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¶¥");
                set("value", 7000);
                set("material", "cloth");
                set("armor_prop/armor", 10);
        }
        setup();
} 

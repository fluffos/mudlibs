// cloth: wcloth.c
// Jay 3/17/96

#include <armor.h>
inherit CLOTH;

void create()
{
        set_name("锦绣皮袄", ({ "jinxiu piao", "piao"}) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("long", "这是一件针制绣成的锦绣皮袄，用来御寒。\n");
                set("material", "cloth");
                set("value",2500);
                set("armor_prop/armor", 10); 
        }
        setup();
}

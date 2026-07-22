// cubu-cloth.c thd 四代弟子穿

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("粗布长袍", ({ "cloth" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","这是一件粗布长袍。\n");
                set("unit", "件");
                set("material", "cloth");
                set("armor_prop/armor", 10);
        }
        setup();
}

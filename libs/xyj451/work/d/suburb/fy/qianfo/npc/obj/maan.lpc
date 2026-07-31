// 
// 

#include <armor.h>
inherit CLOTH;
void create()
{
        set_name("牛皮马鞍", ({ "maan" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("material", "cloth");
                set("armor_prop/armor", 30);
                set("armor_prop/dodge", -30);
        }
        setup();
}

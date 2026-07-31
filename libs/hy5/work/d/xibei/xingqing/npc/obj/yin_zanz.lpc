#include <armor.h>
inherit HEAD;
void create()
{
        set_name("银簪子", ({ "zan zi", }) );
        set_weight(30);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是一件用白银打成的首饰。\n");
                set("unit", "根");
                set("value", 1200);
                set("material", "iron");
                set("armor_prop/armor", 1);
                set("armor_prop/personality", 1);
                set("female_only", 1);
        }
        setup();
}


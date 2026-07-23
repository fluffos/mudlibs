#include <ansi.h>
#include <armor.h>
inherit CLOTH;

void create()
{
        set_name(HIW"银甲"NOR, ({ "yin jia", "armor", "jia" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("material", "silver");
                set("value", 10000);
                set("armor_prop/armor", 75);
        }
        setup();
}


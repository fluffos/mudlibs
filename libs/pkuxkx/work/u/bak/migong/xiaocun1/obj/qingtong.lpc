#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name(YEL"青铜甲"NOR, ({ "qingtong jia","jia","armor" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("material", "steel");
                 set("value", 150000);
                set("armor_prop/armor", 100);
        }
        setup();
}



#include <ansi.h>
#include <armor.h>
inherit CLOTH;

void create()
{
        set_name( HIM "红色绸裙" NOR, ({ "red dress", "dress" }) );
        set_weight(700);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("value", 4000);
                set("material", "cloth");
                set("armor_prop/armor", 3);
                set("armor_prop/dodge", 10);
        }
        setup();
}


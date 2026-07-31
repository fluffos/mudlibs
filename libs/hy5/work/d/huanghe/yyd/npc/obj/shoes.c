
#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create()
{
        set_name( HIC "麻布鞋" NOR, ({ "mabu xie", "xie", "shoes" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "双");
                set("long", "这是一双麻布鞋，不易大滑，供游人登山使用。");
                set("value", 6000);
                set("material", "boots");
                set("armor_prop/dodge", 2);
        }
        setup();
}

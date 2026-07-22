
#include <ansi.h>
#include <armor.h>
inherit CLOTH;
void create()
{
        set_name( HIC"ÐþÌìÕ½ÅÛ"NOR, ({ "armor"}) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼þ");
                set("material", "leather");
                set("value", 4000);
                set("merit", 30);
                set("armor_prop/armor", 500);
 set("armor_prop/armor_vs_force", 1000);
                set("armor_prop/intelligence", 500);
                set("armor_prop/attack", -10);
                set("armor_prop/dodge", -10);
        }
        setup();
}

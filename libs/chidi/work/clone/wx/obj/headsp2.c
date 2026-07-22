
#include <ansi.h>
#include <armor.h>
inherit CLOTH;
void create()
{
        set_name( YEL"ÌúÍ·¿ø"NOR, ({ "tie toukui","toukui"}) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¶¥");
               set("head_type",1);
                set("material", "leather");               
                set("armor_prop/armor", 1);
        }
        setup();
}


#include <ansi.h>
#include <armor.h>
inherit CLOTH;
void create()
{
        set_name( RED"²¼Ö¸Ì×"NOR, ({ "bu zhitao","zhitao"}) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¸ù");
               set("finger_type",1);
                set("material", "leather");               
                set("armor_prop/armor", 1);
        }
        setup();
}

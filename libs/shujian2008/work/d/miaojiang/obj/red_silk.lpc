#include <ansi.h>
#include <armor.h>
inherit NECK;
void create()
{
        set_name(HIW"白丝巾"NOR, ({ "white silk", "silk" }) );
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","一条雪白的丝巾，围在身上，风采翩翩。\n");
		set("unit", "条");
                set("value", 0);
                set("material", "cloth");
                set("armor_type", "cloth");       
                set("armor_prop/armor", 5);
                
        }
setup();
}

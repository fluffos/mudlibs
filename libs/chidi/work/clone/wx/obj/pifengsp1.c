
#include <ansi.h>
#include <armor.h>
inherit CLOTH;
void create()
{
        set_name( HIB"²¼Åû·ç"NOR, ({ "bu pifeng","pifeng"}) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼þ");
               set("pifeng_type",1);
                set("material", "leather");               
                set("armor_prop/armor", 1);
        }
        setup();
}

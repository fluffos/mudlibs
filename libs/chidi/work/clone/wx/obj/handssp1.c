
#include <ansi.h>
#include <armor.h>
inherit CLOTH;
void create()
{
        set_name( HIW"²¼ÊÖÌ×"NOR, ({ "bu shoutao","shoutao"}) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "Ë«");
               set("hands_type",1);
                set("material", "leather");               
                set("armor_prop/armor", 1);
        }
        setup();
}

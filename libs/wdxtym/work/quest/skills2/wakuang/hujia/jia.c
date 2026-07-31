// jia ¼×
//ÐÇÐÇ£¨lywin£©

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name(YEL"¼×"NOR, ({ "jia" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼þ");
                set("material", "steel");
                set("value", 2000);
                set("armor_prop/armor", 10);
        }
        setup();
}


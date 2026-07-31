// tiejia.c Ìú¼×
//

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("[1;33m»Æ½ð¼×[2;37;0m", ({ "armor" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼þ");
                set("material", "steel");
		set("value", 2000);
                set("armor_prop/armor", 100);
        }
        setup();
}


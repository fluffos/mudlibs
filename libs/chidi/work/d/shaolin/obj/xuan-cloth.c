// xuan-cloth.c
//
#include <armor.h>
inherit CLOTH;
void create()
{
        set_name("»¤·¨ôÂôÄ", ({ "jia sha" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼þ");
            set("shaolin",1);
                set("material", "cloth");
        set("armor_prop/intelligence", 15);
                set("armor_prop/armor", 50);
        }
        setup();
}
int query_autoload() { return 1; }

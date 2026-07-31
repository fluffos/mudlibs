// magua.c

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("ÃÜÁÖÇàÒÂ", ({"milin cloth","milin","cloth"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼ş");
                set("value", 10);
                set("material", "cloth");
                set("armor_prop/armor", 2);
        }
        setup();
}



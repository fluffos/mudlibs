// lvshan.c 绿衫

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("绿袍",({"lv pao", "pao", "cloth"}));
    set_weight(1500);
    if( clonep() )
       set_default_object(__FILE__);
    else {
	    set("female_only", 1);
        set("unit", "件");
        set("long","这是一件绿色的长袍。 \n");
        set("material", "cloth");
        set("armor_prop/armor", 15);
    }
    setup();
}

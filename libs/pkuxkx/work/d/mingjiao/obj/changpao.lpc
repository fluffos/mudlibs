#include <armor.h>

inherit CLOTH;

void create()
{
    set_name("白色长袍", ({"pao", "cloth", "chang pao"}) );
    set_weight(1500);
    if( clonep() )
       set_default_object(__FILE__);
    else {
        set("unit", "件");
        set("long", "这是件质地粗糙的白色长袍，前胸后背都绣着一团火红的圣火。\n");
        set("material", "cloth");
        set("armor_prop/armor", 1);
    }
    setup();
}


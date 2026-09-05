#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("白色长袍", ({ "chang pao","cloth", "changpao", "pao" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是一件白色长袍，雪山派上上下下都是这样的装束。\n");
                set("unit", "件");
                set("value", 0);
                set("material", "cloth");
                set("armor_prop/armor", 2 );
                set("armor_prop/dodge", 0 );
        }
        setup();
}

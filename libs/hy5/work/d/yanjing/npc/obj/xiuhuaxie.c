#include <armor.h>
inherit BOOTS;

void create()
{
set_name("绣花鞋",({"xiuhua xie","shoe"}));
        set_weight(700);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit","只");
set("long","小巧精致的绣花鞋,黄色的鞋帮上绣着两只紫色的蝴蝶.\n");
                set("value", 400);
                set("material", "cloth");
                set("armor_prop/armor", 3);
        }
        setup();
}


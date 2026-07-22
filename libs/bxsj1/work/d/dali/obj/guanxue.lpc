#include <armor.h>

inherit BOOTS;

void create()
{
       set_name("便靴", ({ "bianxue", "xue", "xie" }) );
       set_weight(1000);
       if( clonep() )
               set_default_object(__FILE__);
       else {
               set("unit", "双");
               set("long", "一双薄底黑色便靴");
                 set("value", 10);
               set("material", "boots");
               set("armor_prop/dodge", 1);
       }
       setup();
}

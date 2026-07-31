#include <armor.h>

inherit BOOTS;

void create()
{
       set_name("ɮЬ", ({ "seng xie", "xie" }) );
       set_weight(1000);
       if( clonep() )
               set_default_object(__FILE__);
       else {
               set("unit", "˫");
               set("long", "һ˫�಼ɮЬ");
               set("value", 30);
               set("material", "boots");
               set("armor_prop/dodge", 1);
       }
       setup();
}

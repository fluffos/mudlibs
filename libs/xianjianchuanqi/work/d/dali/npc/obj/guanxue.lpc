// Modify By River 98/12
#include <armor.h>
inherit BOOTS;

void create()
{
       set_name("黑底便靴", ({ "heidi bianxue", "bianxue", "shoe" }) );
       set_weight(1000);
       if( clonep() )
               set_default_object(__FILE__);
       else {
               set("unit", "双");
               set("long", "一双薄底黑色便靴，一般管宦人家经常穿着。\n");               
               set("material", "boots");
               set("armor_prop/dodge", 1);
       }
       setup();
}

#include <ansi.h>
inherit COMBINED_ITEM;
#include "/inherit/item/embed.h"

void create()
{
        set_name(HIY"芙蓉金针"NOR, ({ "furong jinzhen","furong","jinzhen", "zhen" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
               set("long", "这是一根细如头发的金针，出自武当派。\n");
               set("unit", "些");
               set("damage", 3);
               set("base_value", 2000);
               set("base_unit", "枚");
               set("base_weight", 100);
               set("material", "gold");
               set("embed", 1);
        }
         set_amount(2);
}

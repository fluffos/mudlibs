// yao3a.c

#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{

       set_name(HIB"点燃的冰魄粉"NOR, ({ "bingbo fen", "fen", "bingbo" }) );
       if( clonep() )
               set_default_object(__FILE__);
       else {
               set("long",
                       "一包透着阴深冷气的毒粉。已经点燃，可以涂(tu)在兵器上了。\n" );
               set("unit", "些");
               set("base_value", 5000);
               set("base_unit", "包");
               set("base_weight", 30);
               set("drug_color", ""HIB"阴气森森"NOR"");
               set("poison", "bing_poison");
       }
       set_amount(1);
}

#include "yaoa.h";
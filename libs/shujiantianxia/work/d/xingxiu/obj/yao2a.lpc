// yao2a.c

#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{

       set_name(HIR"点燃的红磷粉"NOR, ({ "honglin fen", "fen", "honglin" }) );
       if( clonep() )
               set_default_object(__FILE__);
       else {
               set("long",
                       "一包腥红色的毒粉。已经点燃，可以涂(tu)在兵器上了。\n" );
               set("unit", "些");
               set("base_value", 5000);
               set("base_unit", "包");
               set("base_weight", 30);
               set("drug_color", ""HIR"红光闪闪"NOR"");
               set("poison", "hot_poison");
       }
       set_amount(1);
}

#include "yaoa.h";

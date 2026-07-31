// yao1a.c

#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{

       set_name(WHT"点燃的银磷粉"NOR, ({ "yinlin fen", "fen", "yinlin" }) );
       if( clonep() )
               set_default_object(__FILE__);
       else {
               set("long",
                       "一包银光闪闪的毒粉。已经点燃，可以涂(tu)在兵器上了。\n" );
               set("unit", "些");
               set("base_value", 5000);
               set("base_unit", "包");
               set("base_weight", 30);
               set("drug_color", ""WHT"银光闪闪"NOR"");
               set("poison", "cold_poison");
       }
       set_amount(1);
}

#include "yaoa.h";
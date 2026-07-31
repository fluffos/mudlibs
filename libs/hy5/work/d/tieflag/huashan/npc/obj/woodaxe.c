 // woodaxe.c
#include <ansi.h>
#include <weapon.h>
inherit AXE;
void create()
{
        set_name(HIR"斧头"NOR, ({ "woodaxe" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long", 
"一柄用来伐木的的斧头。\n"
);
                set("value", 1000);
                set("material", "steel");
                set("rigidity", 10000);
                
        } 
        ::init_axe(20); 
}
   

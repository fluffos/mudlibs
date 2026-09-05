// pifeng.c
 
#include <ansi.h> 
#include <armor.h> 
 
inherit CLOTH; 
 
void create() 
{ 
        set_name( WHT + BBLK "黑色披风" NOR, ({ "heise pifeng", "pifeng" }) ); 
        set_weight(300); 
        if( clonep() ) 
                set_default_object(__FILE__); 
        else { 
                set("unit", "件"); 
                set("long", "这是一件黑色的披风。\n"); 
                set("value", 300); 
                set("material", "cloth"); 
                set("armor_prop/armor", 10); 
              } 
        setup(); 
} 


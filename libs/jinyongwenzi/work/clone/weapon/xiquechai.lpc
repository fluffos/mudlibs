// xiquechai.c
 
#include <ansi.h> 
#include <armor.h> 
 
inherit HEAD; 
 
void create() 
{ 
        set_name( WHT"喜鹊梅枝钗" NOR, ({ "xique chai", "meizhi chai" , "chai"}) ); 
        set_weight(100); 
        if( clonep() ) 
                set_default_object(__FILE__); 
        else { 
                set("unit", "件"); 
                set("long", "这是一件玉钗，玉质晶莹惕透，一只昂首的喜鹊站在梅花树枝上，梅枝延伸成为钗柄。\n"); 
                set("value", 8000); 
                set("material", "stone"); 
             } 
        setup(); 
} 

// pijia.c

#include <armor.h> 

inherit CLOTH; 

void create() 
{ 
        set_name("皮甲", ({ "pi jia", "jia" , "armor" }) ); 
        set_weight(3300); 
        if( clonep() ) 
                set_default_object(__FILE__); 
        else { 
                set("unit", "件"); 
                set("long", "这是一件以硬牛皮和薄铁片缝制而成的皮甲，虽然工艺粗糙，可防护性能还不错。\n"); 
                set("value", 3300); 
                set("material", "cloth"); 
                set("armor_prop/armor", 30);
              } 
        setup(); 
} 

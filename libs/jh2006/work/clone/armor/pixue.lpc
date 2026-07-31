// pixue.c

#include <armor.h> 
 
inherit BOOTS; 
 
void create() 
{ 
        set_name("皮靴", ({ "pi xue", "shoe" , "pixue"}) ); 
        set_weight(2000); 
        if( clonep() ) 
                set_default_object(__FILE__); 
        else { 
                set("unit", "双"); 
                set("long", "这是一双动物皮缝制的薄皮靴，保暖相当好。\n"); 
                set("value", 800); 
                set("material", "cloth"); 
                set("armor_prop/armor", 3);
		set("armor_prop/dodge", 3);
              } 
        setup(); 
} 

// dingxie.c

#include <armor.h> 
 
inherit BOOTS; 
 
void create() 
{ 
        set_name("钉鞋", ({ "ding xie", "shoe" , "dingxie"}) ); 
        set_weight(2000); 
        if( clonep() ) 
                set_default_object(__FILE__); 
        else { 
                set("unit", "双"); 
                set("long", "攀登用的工具，鞋底遍布锋利的小刺以防止打滑。\n"); 
                set("value", 50); 
                set("material", "iron"); 
                set("armor_prop/armor", 3);
		set("armor_prop/dodge", -5);
              } 
        setup(); 
} 

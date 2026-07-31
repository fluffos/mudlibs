// pidun.c

#include <armor.h> 
 
inherit SHIELD; 
 
void create() 
{ 
        set_name("皮盾", ({ "pi dun", "dun" , "pidun" ,"shield"}) ); 
        set_weight(2300); 
        if( clonep() ) 
                set_default_object(__FILE__); 
        else { 
                set("unit", "面"); 
                set("long", "这是一面以柳条密编，数层硬牛皮蒙面绷成的皮盾，可以挡住远处飞来的箭矢。\n"); 
                set("value", 1500); 
                set("material", "cloth"); 
                set("armor_prop/armor", 15);
		set("armor_prop/dodge", -2);
              } 
        setup(); 
} 

//poxie.c                                                
                                                              
#include <armor.h>                                            
                                                              
inherit BOOTS;                                                
                                                              
void create()                                                 
{                                                             
        set_name("破鞋", ({ "po xie", "xie" }) );             
        set_weight(1);                                        
        if( clonep() )                                        
                set_default_object(__FILE__);                 
        else {                                                
                set("material", "leather");                   
                set("unit", "只");                            
                set("long", "一只破鞋，鞋底还没了，鞋帮子也烂的不成样子！\n");
                set("value", 0);                              
                set("armor_prop/dodge", 8);                   
        }                                                     
        setup();                                              
}                                                             

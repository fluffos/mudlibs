// yanling.c 雁翎
// by iceland
#include <ansi.h> 
#include <armor.h> 
 
inherit HEAD; 
 
void create() 
{ 
        set_name( WHT "雁翎" NOR, ({ "yan ling", "yanling","ling" }) ); 
        set_weight(50); 
        if( clonep() ) 
                set_default_object(__FILE__); 
        else { 
                set("unit", "根"); 
                set("long", "这是一根长长的大雁翎毛，看花纹似乎在中原不太多见，所以比较珍贵。\n"); 
                set("value", 500); 
                set("material", "cloth"); 
                set("armor_prop/armor", 1); 
                set("wear_msg", "$N拿着雁翎想了想，抬手夹在了耳朵上。\n");
             } 
        setup(); 
} 

// qinxiu-jiasha.c
 
#include <ansi.h> 
#include <armor.h> 
 
inherit CLOTH; 
 
void create() 
{ 
        set_name( WHT "勤修袈裟" NOR, ({ "qinxiu jiasha", "jiasha" , "jia sha"}) ); 
        set_weight(1000); 
        if( clonep() ) 
                set_default_object(__FILE__); 
        else { 
                set("unit", "件"); 
                set("long", "这是一件喇嘛穿的袈裟，上面绣着些梵文，是佛经中鼓励勤学修炼的意思。\n"); 
                set("value", 0); 
                set("material", "cloth"); 
                set("armor_prop/armor", 20); 
              } 
        setup(); 
} 

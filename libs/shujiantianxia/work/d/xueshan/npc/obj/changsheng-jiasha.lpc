// changsheng-jiasha.c
 
#include <ansi.h> 
#include <armor.h> 
 
inherit CLOTH; 
 
void create() 
{ 
        set_name( RED "常胜袈裟" NOR, ({ "changsheng jiasha", "jiasha" , "jia sha"}) ); 
        set_weight(1000); 
        if( clonep() ) 
                set_default_object(__FILE__); 
        else { 
                set("unit", "件"); 
                set("long", "这是一件喇嘛穿的袈裟，上面绣着些梵文，是佛经中向佛护法的意思。\n"); 
                set("value", 0); 
                set("material", "cloth"); 
                set("armor_prop/armor", 40); 
              } 
        setup(); 
} 

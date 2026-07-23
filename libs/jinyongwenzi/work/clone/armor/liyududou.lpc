// liyududou.c
 
#include <ansi.h> 
#include <armor.h> 
 
inherit CLOTH; 
 
void create() 
{ 
        set_name( RED "鲤鱼肚兜" NOR, ({ "liyu dudou", "dudou" }) ); 
        set_weight(300); 
        if( clonep() ) 
                set_default_object(__FILE__); 
        else { 
                set("unit", "件"); 
                set("long", "这是一件红色的肚兜，上面用金线绣着一条栩栩如生的大鲤鱼。\n"); 
                set("value", 300); 
                set("material", "cloth"); 
              } 
        setup(); 
} 

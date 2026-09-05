#include <ansi.h> 
#include <armor.h> 
 
inherit SURCOAT; 
 
void create() 
{ 
        set_name( BLK + HIR "国旗" NOR, ({ "guo qi", "qi", "flag" }) ); 
        set_weight(300); 
        if( clonep() ) 
                set_default_object(__FILE__); 
        else { 
                set("unit", "面"); 
                set("long", "这是一件神圣的五星红旗，你可以用它为中国队呐喊助威，也可以像冠军们一样把它披在身上。\n"); 
                set("no_drop","国旗怎么可以乱扔呢？！");
                set("no_give",1);
                set("material", "cloth"); 
                set("armor_prop/armor", 1000); 
              } 
        setup(); 
} 


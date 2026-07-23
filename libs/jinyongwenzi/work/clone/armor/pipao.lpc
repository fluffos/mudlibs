// pipao.c

#include <armor.h> 

inherit CLOTH; 

void create() 
{ 
        set_name("皮袍", ({ "pi pao", "cloth" , "pipao" ,"pao"}) ); 
        set_weight(2500); 
        if( clonep() ) 
                set_default_object(__FILE__); 
        else { 
                set("unit", "件"); 
                set("long", "这是一件吐蕃人日常所穿的衣服，以麻、棉等布料织成。有钱人通常还要缀以毛皮。\n"); 
                set("value", 900); 
                set("material", "cloth"); 
                set("armor_prop/armor", 2);
              } 
        setup(); 
} 

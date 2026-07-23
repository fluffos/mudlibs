// qilinsuo.c
 
#include <ansi.h> 
#include <armor.h> 
 
inherit NECK; 
 
void create() 
{ 
        set_name( YEL "麒麟踏云锁" NOR, ({ "qilin suo", "suo" }) ); 
        set_weight(600); 
        if( clonep() ) 
                set_default_object(__FILE__); 
        else { 
                set("unit", "条"); 
                set("long", "这是一条打造得非常精美的长命锁，锁坠是一头脚踏祥云的麒麟。据说可以驱魔辟妖。\n"); 
                set("value", 3000); 
                set("material", "gold"); 
                set("armor_prop/armor", 5); 
             } 
        setup(); 
} 

 // cloth.c
// 
#include <armor.h> 
inherit CLOTH;
#include <ansi.h>
void create()
{
    set_name(GRN"ËØæý³¤È¹"NOR, ({ "greenskirt" }) );
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼þ"); 
                set("long", "Ò»¼þÂÌÈ¹ËÆºÉÒ¶Æ®µ´£¬ÂÞÍàÎ¢³¾¡£\n");
                set("material", "cloth");
        set("value", 2000);
         set("armor_prop/armor", 3);
                set("armor_prop/dodge", 1);
                set("armor_prop/personality", 1);
                set("female_only", 1);
        }
        
}     

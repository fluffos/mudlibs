 // cloth.c
// 
#include <armor.h> 
inherit WAIST;
#include <ansi.h>
void create()
{
     set_name(YEL"ÇïÏã³¤ËëË¿ÌĞ"NOR , ({ "fallgirth" }) );
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "Ìõ"); 
        set("long","ÊøÖ®ÏËÑü³ş³ş£¬»Ø·çÎèÑ©¡£\n");
                set("material", "cloth");
                set("value", 7000);
                set("armor_prop/armor", 1);
                set("armor_prop/dodge", 1);
                set("armor_prop/personality", 1);
                set("female_only", 1);
        }
        
}       

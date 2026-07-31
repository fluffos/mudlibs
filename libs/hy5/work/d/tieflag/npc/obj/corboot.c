 // color_boot.c
#include <ansi.h>
#include <armor.h> 
inherit BOOTS; 
void create()
{
        set_name(  "²ÊÑ¥" , ({ "color boots", "boots" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit", "¼þ");
        set("value", 800);
        set("material", "cloth");
        set("armor_prop/armor", 1);
        set("armor_prop/dodge", 5);
        set("female_only", 1);
        }
        
}       

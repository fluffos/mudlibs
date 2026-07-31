#include <armor.h>
#include <ansi.h>
inherit CLOTH; 
void create()
{
    set_name(HIG"ÂÌÈ¹"NOR, ({ "cloth" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼þ");
                set("material", "cloth");
        set("armor_prop/armor", 10);
        set("value", 8000);
        }
        
}    

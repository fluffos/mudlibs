#include <armor.h>
#include <ansi.h>
inherit CLOTH; 
void create()
{
    set_name(HIG"±ÌÂÌµÄ½ôÉíÒÂ"NOR, ({ "cloth" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼ş");
                set("material", "cloth");
        set("armor_prop/armor", 25);
        set("value", 8000);
        }
        
}    

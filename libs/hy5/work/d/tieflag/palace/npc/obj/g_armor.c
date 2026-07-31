#include <ansi.h>
#include <armor.h>
inherit ARMOR;
void create()
{
        set_name(HIY"黄金甲"NOR, ({ "golden chainarmor","chainarmor"}) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("material", "gold");
                set("long", "一件闪闪发光的黄金盔甲。\n");
                set("value", 1000);
                set("armor_prop/armor", 80);
        }
        
}    

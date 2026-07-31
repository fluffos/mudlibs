#include <armor.h>
inherit CLOTH; 
void create()
{
    set_name("短裤头", ({"shorts"}));
    set_weight(200);
    if( clonep() )
        set_default_object(__FILE__);
    else 
    {
        set("unit", "件");
        set("value", 2000);
        set("long", "一件短裤，两条裤腿中间还有个小洞，似乎有特殊功能．\n");
        set("material", "cloth");
        set("armor_prop/armor", 10);
        set("armor_prop/dodge", 5);
        set("armor_prop/courage",2);
        set("armor/flexibility", -4);
    }
    
}   

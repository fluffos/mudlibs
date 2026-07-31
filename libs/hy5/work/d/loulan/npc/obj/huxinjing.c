#include <ansi.h>
#include <armor.h>
inherit WAIST; 
void create()
{
        set_name(RED"紫铜护心镜"NOR , ({ "copper plate", "plate" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("long", "一块紫铜护心镜，上面赫然刻着个『一』字。\n");
                set("value", 7000);
                set("material", "copper");
                set("armor_prop/armor", 5);
                set("armor_prop/dodge", 5);
        }
//      ::init_waist();
}      

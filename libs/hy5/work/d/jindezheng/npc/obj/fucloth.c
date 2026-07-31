#include <armor.h>

inherit CLOTH;

void create()
{
       set_name("五福朝寿衣", ({"cloth", "pao"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long",
"名贵绸缎所裁剪而成,用金丝绣出[福]的字样．\n");
                set("unit", "件");
                set("value", 6000);
                set("material", "cloth");
                set("armor_prop/armor", 120);
             }
}


// hua3.c

#include <ansi.h>;
#include <armor.h>;
inherit HEAD;

void create()
{
	set_name(HIB"蕙兰花"NOR, ({"huilan hua", "flower", "hua"}));
	set_weight(110);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "朵");
                set("long", "这是一朵美丽的蕙兰花，香气清新。\n");
                set("value", 0);
                set("material", "plant");
                set("armor_prop/armor", 0);
                set("armor_prop/personality", 1);
                set("wear_msg", "$N轻轻地把一朵$n戴在头上。\n");
                set("unequip_msg", "$N轻轻地把$n从头上摘了下来。\n");
        }
        setup();
}

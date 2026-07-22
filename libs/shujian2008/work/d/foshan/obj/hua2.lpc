// hua2.c
#include <ansi.h>;
#include <armor.h>;
inherit HEAD;

void create()
{
	set_name(HIR"莎椤花"NOR, ({"shaluo hua" "flower", "hua"}));
        set_weight(140);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "朵");
                set("long", "这是一朵美丽的莎椤花，香气清新。\n");
                set("value", 230);
                set("material", "plant");
                set("armor_prop/armor", 0);
                set("armor_prop/personality", 1);
                set("wear_msg", "$N轻轻地把一朵$n戴在头上。\n");
                set("unequip_msg", "$N轻轻地把$n从头上摘了下来。\n");
        }
        setup();
}

// erhuan.c 铜耳环
// hongdou 98.10.02

#include <ansi.h>
#include <armor.h>

inherit NECK;

void create()
{
        set_name(HIY"铜耳环"NOR, ({ "er huan","erhuan","huan" }));
        set_weight( 500);
	set("long", "这是一副廉价的铜耳环，只有寻常的贫民女孩才会佩带。\n");
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "副");
                set("value",500);
                 set("material", "coin");
                set("armor_prop/armor", 1);
        }
        setup();
}

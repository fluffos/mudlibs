// 新手用boots
// By kiden@pkuxkx

#include <armor.h>
#include <ansi.h>

inherit BOOTS;

void create()
{
        set_name("北侠战靴", ({ "pkuxkx zhanxue", "zhanxue", "boots" }));
        set_weight(2000);
        if (clonep())
             set_default_object(__FILE__);
        else {
             set("long", "北侠大神给新手准备的战靴。\n");
             set("material", "cloth");
             set("unit", "双");
             set("value", 0);
             set("armor_prop/armor", 30);
        }
        setup();
}

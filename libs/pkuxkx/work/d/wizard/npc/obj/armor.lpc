// 新手用armor
// By kiden@pkuxkx

#include <armor.h>
#include <ansi.h>

inherit ARMOR;

void create()
{
        set_name("北侠战甲", ({ "pkuxkx zhanjia", "zhanjia", "armor" }));
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
             set("long", "北侠大神给新手准备的战甲。\n");
             set("material", "cloth");
             set("unit", "件");
             set("value", 0);
             set("armor_prop/armor", 100);
        }
        setup();
}

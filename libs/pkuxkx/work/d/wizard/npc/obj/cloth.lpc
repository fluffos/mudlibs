// 新手用cloth
// By kiden@pkuxkx

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name("北侠战衣", ({ "pkuxkx zhanyi", "zhanyi", "cloth" }));
        set_weight(2000);
        if (clonep())
             set_default_object(__FILE__);
        else {
             set("long", "北侠大神给新手准备的战衣。\n");
             set("material", "cloth");
             set("unit", "件");
             set("value", 0);
             set("armor_prop/armor", 30);
        }
        setup();
}

// 新手用surcoat
// By kiden@pkuxkx

#include <armor.h>
#include <ansi.h>

inherit SURCOAT;

void create()
{
        set_name("北侠战袍", ({ "pkuxkx zhanpao", "zhanpao", "surcoat" }));
        set_weight(2000);
        if (clonep())
             set_default_object(__FILE__);
        else {
             set("long", "北侠大神给新手准备的战袍。\n");
             set("material", "cloth");
             set("unit", "件");
             set("value", 0);
             set("armor_prop/armor", 60);
        }
        setup();
}

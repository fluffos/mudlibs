// 新手用head
// By kiden@pkuxkx

#include <armor.h>
#include <ansi.h>

inherit HEAD;

void create()
{
        set_name("北侠战盔", ({ "pkuxkx zhankui", "zhankui", "head" }));
        set_weight(2000);
        if (clonep())
             set_default_object(__FILE__);
        else {
             set("long", "北侠大神给新手准备的战盔。\n");
             set("material", "iron");
             set("unit", "顶");
             set("value", 0);
             set("armor_prop/armor", 30);
        }
        setup();
}

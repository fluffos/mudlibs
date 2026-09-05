// pilidan.c 霹雳弹

#include <weapon.h>
#include <ansi.h>
inherit THROWING;

void create()
{
    set_name("霹雳弹", ({"pili dan", "dan"}));
    set_weight(80);
    set("is_pilidan",1);
    if (clonep())
        set_default_object(__FILE__);
    else {
        set("long", "一粒精致但威力无比的霹雳弹。\n");
        set("unit", "堆");
        set("base_unit", "粒");
        set("value", 100);
        set("base_weight", 80);
        set("wield_msg", "$N从腰间锦囊中轻轻拈起一粒$n，捏在手中。\n");
        set("unwield_msg", "$N将手中的$n放回腰间锦囊。\n");
    }
    set_amount(1);
    init_throwing(20);
    setup();
}


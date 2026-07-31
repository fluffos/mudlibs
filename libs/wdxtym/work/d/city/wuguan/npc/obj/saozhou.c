//saozhou.c 
#include <weapon.h>
inherit CLUB;

void create()
{
        set_name("扫帚", ({ "sao zhou", "sao", "club" }));
        set_weight(500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把扫帚，普通百姓的日常用品。\n");
                set("value", 0);
                set("material", "steel");
                set("wield_msg", "$N拿出一把$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n抗在肩上。\n");
        }
        init_club(4);
        setup();
}

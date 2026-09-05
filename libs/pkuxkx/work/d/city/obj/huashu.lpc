// huashu.c 花束

#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
        set_name("花束", ({ "hua shu", "hua" }) );
        set_weight(350);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一束美丽的花。\n");
                set("unit", "束");
                set("value", 120);
                set("wield_msg", "$N抓起一枝$n，握在手中当武器。\n");
                set("material", "flower");
        }

        init_sword(1);

        setup();
}



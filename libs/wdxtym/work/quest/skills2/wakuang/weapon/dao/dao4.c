// /clone/weapon/xuedao.c
// by dubei
#include <weapon.h>
#include <ansi.h>
inherit BLADE;
inherit F_UNIQUE;

void create()
{

        set_name(RED"大砍刀"NOR, ({ "kandao","blade","dao" }));
        set_weight(15000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("rigidity", 5);
                set("sharpness", 3);
                set("long", "一柄软软的缅刀，刀身不住颤动，宛如活蛇一般。引光望去，刀锋全是暗红之色。，
血光隐隐,极是可怖.\n");
                set("value", 1000);
                set("unique", 1);

        }
        init_blade(100);
        setup();
}

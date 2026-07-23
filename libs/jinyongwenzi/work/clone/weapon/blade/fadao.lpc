// fadao.c 法刀
// By Looklove@SJ 2000/10/06

#include <ansi.h>
#include <weapon.h>

inherit BLADE;
#include "/inherit/item/embed.h"

void create()
{
        set_name(HIW "法刀" NOR, ({ "fa dao", "dao", "knife"}));
        set_weight(150);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("damage", 30);
               set("embed", 1);
               set("unit", "柄");
               set("throw_msg",
                    HIW"$N手腕一翻，一柄小刀自手心飞出直向$n急射而去！\n"NOR);
               set("long", "一枚纯钢的小刀，刀身雪亮，打造得极是精致。锋利无比。\n");
                set("value", 2000000000);
               set("wield_msg", "$N手指一动，不知什么时候手里已经多了一柄小刀。\n");
               set("unwield_msg", "$N手掌一收，$n突然消失在手中。\n");
        }
        init_blade(20);
        setup();
}

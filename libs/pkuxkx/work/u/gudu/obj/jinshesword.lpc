
#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
        set_name( HIY "金蛇剑" NOR, ({ "jinshe jian" }) );
    set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long",

"这是一把金蛇郎君纵横江湖时使用的金蛇剑。\n"
);
                set("value", 21500);
                set("material", "steel");
                set("rigidity", 100000);
                set("wield_msg", "$N一反腕从背后拔出一把$n握在手中，一股森冷的剑气直逼过来。\n");
                set("unequip_msg", "呛啷一声，$N反腕将手中的$n插到背后。\n");
        }

     init_sword(160);
        setup();

}



string query_autoload()
{
        return query("name");
}

void autoload()
{}


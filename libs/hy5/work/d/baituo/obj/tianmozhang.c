#include <weapon.h>
#include <ansi.h>
inherit STAFF;

void create()
{
        set_name(BLU"天魔杖"NOR, ({ "tianmo zhang" , "zhang"}) );
        set_weight(30000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", "这是白驼山的镇山之宝-天魔杖!");
                set("value", 3000);
                set("material", "steel");
        }
        init_staff(620);
        set("wield_msg", HIW"只听“唰”的一声，一道黑光闪过，$N的手中多了把天魔杖。\n"NOR);

        setup();
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
        victim->apply_condition("qx_snake_poison");

        return HIR "$n面孔怪异的扭曲，显然是中了传说中的七修蛇毒！\n\n" NOR;
}



#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name(NOR + WHT "黑剑" NOR, ({ "hei jian", "jian", "hei", "sword" }));
        set_weight(6200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIY "这是一柄黑色的宝剑，剑身发出阴寒之气，令人"
                            "毛骨悚然。\n" NOR);
                set("unit", "柄");
                set("value", 8000);
                set("treasure", 1);
                set("material", "steel");
                set("wield_msg", HIY "$N" HIY "抽出一柄黑色的宝剑，顿觉寒气弥"
                               "漫于四周。\n" NOR);
                set("unwield_msg", HIC "$N" HIC "剑转三周，插剑入鞘，寒气隐于"
                                   "剑鞘之中。\n" NOR);
                set("stable", 100);
        }                                                                                                                    
        init_sword(600+random(320));
        setup();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int n;

              
        if(random(8) == 4)
        {
                n = me->query_skill("sword");
                victim->receive_damage("qi", n);
                victim->receive_wound("qi", n);
                return HIG "\n$N" HIG "踏前一步，手中" HIB "黑剑" HIG 
                       "一抖，平平刺出，$n" HIG "顿觉一股寒气扑面而"
                       "来。\n" NOR;
        }
        return damage_bonus;
}

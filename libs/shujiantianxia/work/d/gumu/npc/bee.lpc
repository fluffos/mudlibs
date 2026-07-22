// bee.c
// Modify By River 98/09
inherit NPC;
#include <ansi.h>
void create()
{
        set_name("玉蜂", ({ "yu feng", "bee","feng" }) );
        set("race", "野兽");
        set("age", 4);
        set("long", "只见玉蜂右翅上有“情谷底”三字，左翅上有“我在绝”三字，每个字细如米\n"+
                    "粒，但笔划清楚，显是用极细的针刺成。\n");
        set("attitude", "peaceful");         

        set("str", 20);
        set("con", 30);

        set("limbs", ({  "身体",  "翅膀" }) );
        set("verbs", ({ "bite" }) );

        set("combat_exp", 5000);

        set_temp("apply/attack", 35);
        set_temp("apply/damage", 23);
        set_temp("apply/armor", 24);

        setup();
}


void die()
{
        message_vision("$N被你一掌挥落，魂消烟散，尸骨全无。\n", this_object());
        destruct(this_object());
}

int hit_ob(object me, object victim, int damage)
{
        victim->apply_condition("bee_poison", victim->query_condition("bee_poison") + 20);
        return 0;
}     

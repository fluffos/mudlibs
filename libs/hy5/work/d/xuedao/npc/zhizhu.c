// zhizhu.c

#include <ansi.h>
inherit NPC;
void create()
{
    set_name(HIB"毒蜘蛛"NOR, ({ "du zhizhu" }));
    set("long", "一只有毒蜘蛛。\n");

    set("race", "野兽");
    set("age", 3);
    set("attitude", "peaceful");

    set("max_ging", 2000);
    set("max_qi", 2000);
    set("str", 100);
    set("cor", 50);

    set("limbs", ({ "嘴","触角", "身体", "尾刺"}));
    set("verbs", ({ "bite" }) );

    set_temp("apply/attack", 100);
    set_temp("apply/damage", 1000);
    set_temp("apply/armor", 1000);
set_temp("apply/defense", 100);
    set("combat_exp", 800000);
    setup();
}

int hit_ob(object me, object ob, int damage)
{
    if ((int)ob->query("combat_exp") > 10000) return 1 ;
    if( random(damage) > (int)ob->query_temp("apply/armor")
    &&  (int)ob->query_condition("scorpion_poison") < 10 )
    {
        ob->apply_condition("scorpion_poison", 20);
        tell_object(ob, HIG "你开始感到身体变得冰凉。！\n" NOR );
    }
}

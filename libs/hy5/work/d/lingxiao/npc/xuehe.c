//LUCAS 2000-6-18
// xuehe.c

inherit NPC;
#include <ansi.h>;
void create()
{
        set_name(HIW"雪鹤"NOR, ({ "xue he", "he"}));
        set("race", "野兽");
        set("age", 3);
        set("long", "一只全身洁白的雪鹤，是大雪山的特产。\n");
        set("attitude", "peaceful");

        set("limbs", ({ "头部", "身体", "翅膀", "爪子", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("combat_exp", 300);
        set_temp("apply/attack", 5);
        set_temp("apply/defense", 7);
        set_temp("apply/armor", 7);

        setup();
}


// Jay 5/23/96

inherit NPC;

void create()
{
        set_name("秃鹰", ({ "eagle" }) );
        set("race", "野兽");
        set("age", 3);
        set("long", "一只黑色的秃鹰，秃头黑羽，好吃腐尸，看起来讨厌极了。\n");
        set("attitude", "peaceful");

        set("limbs", ({ "头部", "身体", "翅膀", "爪子", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("combat_exp", 3000);
        set_temp("apply/attack", 30);
        set_temp("apply/defense", 50);
        set_temp("apply/armor", 10);

        setup();
}

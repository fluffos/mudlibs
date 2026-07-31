
inherit NPC;

void create()
{
        set_name("山羊", ({ "goat" }) );
        set("race", "野兽");
        set("age", 5);
        set("long", "一只美丽的山羊，正在低头吃草.\n");

        set("limbs", ({ "头部", "身体", "尾巴" }) );
        set("verbs", ({ "bite" }) );

        set("combat_exp", 15000);

        setup();
}



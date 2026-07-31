 inherit NPC;
void create()
{
        set_name("花蝴蝶", ({ "butterfly" }) );
        set("race", "野兽");
        set("per", 30);
        set("age", 1);
        set("yes_carry", 1);
        set("long",
                "一只粉红色的蝴蝶。\n"
        );
        set("limbs", ({ "头部", "身体", "翅膀" }) );
        set("verbs", ({ "bite" }) );
        set_temp("apply/attack", 10);
        set_temp("apply/armor", 3);
        set_temp("apply/dodge", 100);
        setup();
}

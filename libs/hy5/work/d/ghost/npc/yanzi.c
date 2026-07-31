 inherit NPC;
void create()
{
        set_name("燕子", ({ "yan zi", "yan" }) );
        set("race", "野兽");
        set("age", 2);
        set("yes_carry", 1);
        set("long",
                "一只小燕子。\n"
        );
        set("limbs", ({ "头部", "身体", "翅膀", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );
        set_temp("apply/attack", 10);
        set_temp("apply/armor", 3);
        set_temp("apply/dodge", 100);
        setup();
}    

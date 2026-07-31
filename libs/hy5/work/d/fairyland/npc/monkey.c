// monkey.c

inherit NPC;

void create()
{
        set_name("猴子", ({ "monkey", "hou" }) );
        set("race", "野兽");
        set("age", 3);
        set("long", "一只正在树上蹦来蹦去的猴儿。\n");

        set("limbs", ({ "头部", "身体", "前爪", "后爪", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("combat_exp", 100);
    
	set_temp("apply/attack", 30);
        set_temp("apply/defense", 30);
        set_temp("apply/damage", 30);
        set_temp("apply/armor", 10);

        setup();
}

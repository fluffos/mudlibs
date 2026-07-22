// shanyang.c

inherit NPC;

void create()
{
        set_name("野山羊", ({"shan yang", "yang"}));
        set("race", "野兽");
        set("age", 5);
        set("long", "一只温顺可爱的野山羊。\n");

        set("limbs", ({ "头部", "身体", "前爪", "后爪", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("combat_exp", 100);
    
	set_temp("apply/attack", 30);
        set_temp("apply/defense", 30);
        set_temp("apply/damage", 30);
        set_temp("apply/armor", 10);

        setup();
}

void die()
{
       message_vision("$N惨嚎一声，慢慢倒下死了！\n", this_object());
       new_ob("../obj/yang-rou")->move(environment());
       destruct(this_object());
}

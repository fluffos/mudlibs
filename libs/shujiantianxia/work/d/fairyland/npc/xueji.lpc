// xueji.c

inherit NPC;

void create()
{
        set_name("雪鸡", ({"xue ji","ji"}));
        set("race", "野兽");
        set("age", 2);
        set("long", "一只肥肥白白的雪鸡。\n");

        set("limbs", ({ "头部", "身体", "前爪", "后爪", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("combat_exp", 100);

	set_temp("apply/attack", 20);
        set_temp("apply/defense", 20);
        set_temp("apply/damage", 20);
        set_temp("apply/armor", 10);

        setup();
}

void die()
{
       message_vision("$N惨嚎一声，慢慢倒下死了！\n", this_object());
       new_ob("../obj/xueji-rou")->move(environment());
       destruct(this_object());
}

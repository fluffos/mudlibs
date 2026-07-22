// animal: snake.c
// Jay 3/18/96

inherit NPC;

void create()
{
        set_name("山羊", ({ "shan yang", "yang" }) );
        set("race", "野兽");
        set("age", 20);
        set("long", "一只可爱的小山羊。\n");
        set("attitude", "peaceful");
	set("no_quest", 1);

        set("str", 26);
        set("cor", 30);

        set("limbs", ({ "头部", "身体", "尾巴" }) );
        set("verbs", ({ "bite" }) );

        set("combat_exp", 10000);

        set_temp("apply/attack", 250);
        set_temp("apply/damage", 300);
        set_temp("apply/armor", 400);

        setup();
}

/*void die()
{
        object ob;
        message_vision("$N“咩”一声死了。\n", this_object());
ob = new(__DIR__"pi");
        ob->move(environment(this_object()));
        destruct(this_object());
}*/


// animal: wugong.c  蜈蚣
// Jay 3/18/96

inherit NPC;

void create()
{
        set_name("蜈蚣", ({ "wu gong", "wugong" }) );
        set("race", "野兽");
        set("age", 4);
        set("long", "一条有毒的大蜈蚣，无数的腿在蠕动，使你觉得异常恶心。\n");
        set("attitude", "peaceful");

        set("str", 26);
        set("cor", 30);

        set("limbs", ({ "头部", "身体", "触角", "腿" }) );
        set("verbs", ({ "bite" }) );

        set("combat_exp", 1000);

        set_temp("apply/attack", 15);
        set_temp("apply/damage", 6);
        set_temp("apply/armor", 2);

        setup();
}

void init()
{
        object ob;
        ::init();
        if (interactive(ob = this_player()) &&
                random(ob->query_kar() + ob->query_per()) < 30) {
                        remove_call_out("kill_ob");
                        call_out("kill_ob", 1, ob); 
        }
}
void die()
{
        object ob;
        message_vision("$N啪的一声断成两截！$N死了。\n", this_object());
//        ob = new(__DIR__"obj/shedan");
//        ob->move(environment(this_object()));
        destruct(this_object());
}



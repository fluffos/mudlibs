// animal: snake.c
// Eric 96.9.26

inherit NPC;

void create()
{
        set_name("毒蛇", ({ "snake", "she" }) );
        set("race", "野兽");
        set("age", 4);
        set("long", "一条金色的毒蛇，口中嘶嘶作响，边向你扑来！\n");
        set("attitude", "peaceful");

        set("str", 26);
        set("cor", 30);

        set("limbs", ({ "头部", "身体", "七寸", "尾巴" }) );
        set("verbs", ({ "bite" }) );

        set("combat_exp", 1000);

        set_temp("apply/attack", 15);
        set_temp("apply/damage", 6);
        set_temp("apply/armor", 2);

        set("shen_type",-1);
set("score",200);
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
        ob = new(__DIR__"obj/shedan");
        ob->move(environment(this_object()));
        destruct(this_object());
}



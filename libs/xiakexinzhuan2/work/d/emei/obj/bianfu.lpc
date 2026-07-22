// animal: bianfu
// Jay 3/18/96

inherit NPC;

void create()
{
        set_name("蝙蝠", ({ "bian fu", "fu" }) );
        set("race", "野兽");
        set("age", 20);
        set("long", "一只蝙蝠倒挂在石洞壁上。\n");
        set("attitude", "peaceful");

        set("str", 26);
        set("cor", 30);

        set("limbs", ({ "头部", "颈部", "后背", "腹部", "脚爪", "翅膀" }) );
        set("verbs", ({ "bite" }) );

        set("combat_exp", 50000);

        set_temp("apply/attack", 250);
        set_temp("apply/damage", 300);
        set_temp("apply/armor", 400);

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
        message_vision("$N啊~~的一声撕列的叫声死了。\n", this_object());
        destruct(this_object());
}

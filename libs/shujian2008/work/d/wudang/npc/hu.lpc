// NPC : /d/wudang/npc/hu.c 虎


inherit NPC;

void create()
{
        set_name("老虎", ({ "lao hu", "hu" }) );
        set("race", "野兽");
        set("age", 20);
        set("long", "一只斑斓大虎，重达三百多斤。\n");
        set("attitude", "peaceful");
        set("str", 26);
        set("cor", 30);

        set("limbs", ({ "头部", "身体", "虎脚", "尾巴" }) );
        set("verbs", ({ "bite" }) );

        set("combat_exp", 80000);
        set("chat_chance", 25);
        set("chat_msg", ({
              (: random_move :),
        }) );

        set_temp("apply/attack", 350);
	 set_temp("apply/defense",400);
        set_temp("apply/damage", 400);
        set_temp("apply/armor", 500);

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
        message_vision("$N仰天一声咆吼死了。\n", this_object());
        ob = new(ARMOR_D("hupi"));
        ob->move(environment(this_object()));
        destruct(this_object());
}


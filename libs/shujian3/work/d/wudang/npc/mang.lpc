// NPC : /d/wudang/npc/mang.c 莽


inherit NPC;

void create()
{
        set_name("巨蟒", ({ "ju mang", "mang" }) );
        set("race", "野兽");
        set("long", "一只花纹怪异，身型奇大的巨蟒蛇。\n");
        set("attitude", "peaceful");
        set("str", 26);
        set("cor", 30);

        set("limbs", ({ "头部", "身体", "七寸", "尾巴" }) );
        set("verbs", ({ "bite" }) );


        set("combat_exp", 80000);
        set("chat_chance", 25);
        set("chat_msg", ({
              (: random_move :),
        }) );

        set_temp("apply/attack", 450);
	 set_temp("apply/defense",500);
        set_temp("apply/damage", 450);
        set_temp("apply/armor", 600);

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


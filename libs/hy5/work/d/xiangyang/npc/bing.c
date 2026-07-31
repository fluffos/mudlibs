// bing.c 宋兵

inherit NPC;

void create()
{
	set_name("宋兵", ({ "song bing", "bing" }));
	set("age", 22);
	set("gender", "男性");
	set("long", "大宋官兵的武艺不能和武林人士相比，但襄阳守军之精，天下第一。\n");
	set("attitude", "peaceful");
//	set("vendetta_mark", "authority");
//      set("pursuer", 1);

	set("str", 24);
	set("dex", 16);

	set("shen_type", 1);

	set("combat_exp", 810000);
	set("shen_type", 1);

    set("max_neili",8500);
    set("neili",8500);
    set("qi",8500);
    set("eff_qi",8500);
    set("max_qi",8500);

    set("jing",8500);
    set("eff_jing",8500);
    set("max_jing",8500);
        set_skill("force", 180+random(180));

        set_skill("unarmed", 180+random(180));
        set_skill("blade", 180+random(180));
        set_skill("parry", 180+random(180));
        set_skill("dodge", 180+random(180));
        set_skill("kuang-blade", 280+random(180));
        map_skill("blade", "kuang-blade");
        map_skill("parry", "kuang-blade");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "blade.leitingpili" :),
                (: perform_action, "blade.kuang" :),

        }) );

	set_temp("apply/attack", 40);
	set_temp("apply/defense", 40);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 40);

        set("chat_chance_combat", 10);
	set("chat_msg_combat", ({
		"宋兵喝道：大胆刁民，竟敢造反不成？\n",
		"宋兵喝道：跑得了和尚跑不了庙，你还是快快束手就擒！\n",
	}));
	setup();
	carry_object("/clone/weapon/gangdao")->wield();
	carry_object("/d/city/npc/obj/junfu")->wear();
}

void init()
{
	object ob;
	::init();
	if (interactive(ob = this_player()) && 
		(int)ob->query_condition("killer")) {
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob);
	}
}

int accept_fight(object me)
{
	command("say 大爷我正想找人杀呐，今天算你倒霉。\n");
//	me->apply_condition("killer", 500);
	kill_ob(me);
	return 1;
}

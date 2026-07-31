// Write By Yanyang@SJ 2001.10.2
// NPC : /d/changan/npc/xunbu.c

inherit NPC;

void create()
{
        set_name("巡捕", ({ "xun bu", "xunbu" }));
        set("age", 22);
        set("gender", "男性");
        set("long", "他站在那里，的确有说不出的威风。\n");
        set("attitude", "peaceful");

        set("str", 24);
        set("dex", 16);
        set("combat_exp", 10000);
        set("shen_type", 1);

        set_skill("unarmed", 40);
        set_skill("dodge", 40);
        set_skill("parry", 40);
        set_skill("blade", 40);
        set_skill("force", 40);
        set_temp("apply/attack", 40);
        set_temp("apply/defense", 40);
        set_temp("apply/damage", 20);
        set_temp("apply/armor", 40);

        set("chat_chance", 2);
        set("chat_msg", ({
                "巡捕上上下下地打量你一番，又拿出官府通谍对了对，低声嘀咕着什么。\n",
                "巡捕向你喝道：站住！干什么的！把脸给我抬起来！\n",
		(: random_move :),
        }));
        setup();
        carry_object(BINGQI_D("blade"))->wield();
        carry_object(ARMOR_D("ruanxue2"))->wear();
        carry_object(ARMOR_D("armor"))->wear();
}

void init()
{
        object ob;
        ::init();
        if (interactive(ob = this_player()) && living(this_object()) &&
                (int)ob->query_condition("killer")) {
                remove_call_out("kill_ob");
                call_out("kill_ob", 1, ob);
        }
}

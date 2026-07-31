// wujiang.c 武将

inherit NPC;

void create()
{
        set_name("武将", ({ "wu jiang", "wu", "jiang" }));
        set("gender", "男性");
        set("age", random(10) + 30);
        set("str", 25);
        set("dex", 16);
        set("long", "他站在那里，的确有说不出的威风。\n");
        set("combat_exp", 7500000);
        set("shen_type", 1);
        set("attitude", "peaceful");

        set_skill("unarmed", 600);
        set_skill("force", 600);
        set_skill("sword", 600);
        set_skill("dodge", 600);
        set_skill("parry", 600);
        set_temp("apply/attack", 150);
        set_temp("apply/defense", 150);
        set_temp("apply/armor", 150);
        set_temp("apply/damage", 130);

        set("neili", 400);
        set("max_neili", 400);
        set("jiali", 10);

        setup();
        carry_object(__DIR__"weapon/sword")->wield();
        carry_object(__DIR__"armor/tiejia")->wear();
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

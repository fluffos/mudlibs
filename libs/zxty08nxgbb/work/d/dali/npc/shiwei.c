// shiwei.c ½ð¼×´øµ¶ÊÌÎÀ

inherit NPC;

void create()
{
        set_name("[1;33m½ð¼×´øµ¶ÊÌÎÀ[2;37;0m", ({ "shi wei", "shi", "wei" }));
        set("gender", "ÄÐÐÔ");
        set("age", random(20) + 30);
        set("str", 25);
        set("dex", 16);
        set("long", "ËûÉí´©½ð¼×£¬ÊÖÎÕ¸Öµ¶£¬Ä¿ÊÓÇ°·½£¬ÕæÊÇÍþ·çÁÝÁÝ¡£\n");
        set("combat_exp", 150000);
        set("shen_type", 1);

        set_skill("unarmed", 120);
        set_skill("force", 120);
        set_skill("blade", 120);
        set_skill("dodge", 120);
        set_skill("parry", 120);
        set_temp("apply/attack", 100);
        set_temp("apply/defense", 100);
        set_temp("apply/armor", 100);
        set_temp("apply/damage", 60);

        set("neili", 800); 
        set("max_neili", 800);
        set("jiali", 20);

        add_money("silver", random(15));
        setup();
        carry_object(__DIR__"obj/gangdao")->wield();
        carry_object(__DIR__"obj/goldjia")->wear();
}

void init(string arg)
{
        object ob;
        ::init();
        if (!living(this_object()))     return;
        if (interactive(ob = this_player())){
                if (    (int)ob->query_condition("killer") ){
                        command("say ¹þ£¡×ÜËã¸ø´óÒ¯´þ×¡ÁË£¬É±ÈË·¸£¬ÄÇÀïÌÓ£¿\n");
                        remove_call_out("kill_ob");
                        call_out("kill_ob", 1, ob);
                }
        }

        if( this_player()->query_temp("dalikill") )
        kill_ob(this_player());
        add_action("do_kill","kill");
        add_action("do_kill","hit");
}
int do_kill(string arg)
{
        object ob;
        if (living(this_object()) && this_object()->id(arg)){
                command("say Ïë´ò¼Ü£¿ÐÖµÜÃÇ£¬ÉÏ£¡");
                if (ob=present("wu jiang",environment()))
                        ob->kill_ob(this_player());
                if (ob=present("shiwei",environment()))
                        ob->kill_ob(this_player());
        }
        if (living(this_object()) && this_object()->id(arg))
        {
         this_player()->set_temp("dalikill", 1);
        }
        return 0;
}
int accept_fight(object me)
{
        command("say ´óÒ¯ÎÒÕýÏëÕÒÈËÉ±ÄÅ£¬½ñÌìËãÄãµ¹Ã¹¡£\n");
        me->apply_condition("killer", 500);
        kill_ob(me);
        return 1;
}

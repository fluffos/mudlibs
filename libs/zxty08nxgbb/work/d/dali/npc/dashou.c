// dashou.c 打手

inherit NPC;

void create()
{
        set_name("打手", ({ "da shou", "da" }));
        set("age", 22);
        set("gender", "男性");
        set("long", "这家伙满面横肉，打架一起上以多欺少是他们的作风。\n");
        set("attitude", "peaceful");
//      set("vendetta_mark", "authority");
//      set("pursuer", 1);

        set("str", 24);
        set("dex", 16);
        set("combat_exp", 15000);
        set("shen_type", 1);

        set_skill("unarmed", 45);
        set_skill("dodge", 45);
        set_skill("parry", 45);
        set_skill("force", 45);
        set_skill("blade", 40);
        set_temp("apply/attack", 40);
        set_temp("apply/defense", 40);
        set_temp("apply/damage", 20);
        set_temp("apply/armor", 40);

//      if (random(2) == 1) {
//              set("chat_chance", 10);
//              set("chat_msg", ({
//                      (: random_move :),
//              }));
//      }

        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
                "打手喝道：你竟敢太岁头上土？纳命来\n",
                "打手喝道：你也不看看这是谁的地方，今天要你走着来，躺着回去。\n",
        }));
        setup();
        carry_object("/clone/weapon/gangdao")->wield();
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        ::init();
        if( this_player()->query_temp("dalikill") )
        {
                 kill_ob(this_player());
        }
        add_action("do_kill","kill");
}

int do_kill(string arg)
{
        object ob;
        if (living(this_object()) && this_object()->id(arg)){
                command("say 想打架？兄弟们，上！");
                if (ob=present("da shou",environment()))
                        ob->kill_ob(this_player());
        }
        this_player()->set_temp("dalikill", 1);
        return 0;
}

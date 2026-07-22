// bing.c 官兵
inherit BHNPC;
void create()
{
        set_name("大理官兵", ({ "guan bing", "bing" }));
        set("age", 22);
        set("gender", "男性");
        set("long", "虽然官兵的武艺不能和武林人士相比，可是他们讲究的是人多力量大。\n");
        set("attitude", "peaceful");
        set("str", 24);
        set("dex", 16);
        set("combat_exp", 20000);
        set("shen_type", 1);
        set_skill("unarmed", 80);
        set_skill("dodge", 80);
        set_skill("parry", 80);
        set_skill("blade", 80);
        set_skill("force", 80);
        set_temp("apply/attack", 80);
        set_temp("apply/defense", 80);
        set_temp("apply/damage", 40);
        set_temp("apply/armor", 80);
        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
                "官兵喝道：大胆刁民，竟敢造反不成？\n",
                "官兵喝道：跑得了和尚跑不了庙，你还是快快束手就擒！\n",
        }));
        setup();
        carry_object(__DIR__"obj/gangdao")->wield();
        carry_object(__DIR__"obj/junfu")->wear();
}
void init(string arg)
{
        object ob;
        ::init();
        if (!living(this_object()))     return;
        if (interactive(ob = this_player())){
                if (    (int)ob->query_condition("killer") ){
                        command("say 哈！总算给大爷逮住了，杀人犯，那里逃？\n");
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
                command("say 想打架？兄弟们，上！");
                if (ob=present("wu jiang",environment()))
                        ob->kill_ob(this_player());
                if (ob=present("guan bing",environment()))
                        ob->kill_ob(this_player());
        }
        if (living(this_object()) && this_object()->id(arg))
        {
         this_player()->set_temp("dalikill", 1);
        }
        return 0;
}
/*
int accept_fight(object me)
{
        command("say 大爷我正想找人杀呐，今天算你倒霉。\n");
        me->apply_condition("killer", 500);
        kill_ob(me);
        return 1;
}
*/

// bing.c 官兵
inherit NPC;
void create()
{
        set_name("官兵", ({ "guan bing", "bing" }));
        set("age", 32);
        set("gender", "男性");
        set("long", "他是个戍边多年的老兵。年纪不小了，但尚未成家。\n");
        set("attitude", "peaceful");
        set("str", 24);
        set("dex", 16);
        set("combat_exp", 10000);
        set_skill("unarmed", 40);
        set_skill("dodge", 40);
        set_skill("parry", 40);
        set_skill("blade", 40);
        set_skill("force", 40);
        set_temp("apply/attack", 40);
        set_temp("apply/defense", 40);
        set_temp("apply/damage", 20);
        set_temp("apply/armor", 40);

        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
                "官兵喝道：大胆刁民，竟敢造反不成？\n",
                "官兵喝道：跑得了和尚跑不了庙，你还是快快束手就擒！\n",
        }));
        setup();
        carry_object(__DIR__"obj/gangdao")->wield();
        carry_object(__DIR__"obj/junfu")->wear();
}
void init()
{
    object ob;
    ::init();
    if (!living(this_object())) return;
    if (interactive(ob = this_player())){
        if (    (int)ob->query_condition("killer") &&   this_player()->name()==this_player()->name(1)   ) {
            command("say 哈！总算给大爷逮住了，杀人犯，那里逃？\n");
            remove_call_out("kill_ob");
            call_out("kill_ob", 1, ob);
        }
        if( this_player()->query_temp("illicit") ){
            command("say 盐枭！那里逃？\n");
            remove_call_out("kill_ob");
            call_out("kill_ob", 1, ob);
        }
    }
    add_action("do_kill","kill");
    add_action("do_kill","hit");
}
int do_kill(string arg)
{
    object ob;
    if (living(this_object()) && this_object()->id(arg)){
        command("say 想打架？兄弟们，上！");
        if (ob=present("wu jiang",environment()))
                     if (!ob->is_killing(this_player()))  ob->kill_ob(this_player());
        if (ob=present("guan bing",environment()))
                     if (!ob->is_killing(this_player()))  ob->kill_ob(this_player());
    }
    return 0;
}
int accept_fight(object me)
{
        command("say 大爷我守边关累得要死，没空和" + RANK_D->query_respect(me)
        + "过招玩。\n");
        return 0;
}

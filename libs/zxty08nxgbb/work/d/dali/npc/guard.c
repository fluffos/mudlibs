inherit NPC;
 
void do_drink();
 
void create()
{
        seteuid(getuid());
        set_name("打更的", ({"guard", "boat guard", "boater"}));
        set("long",
                "一个醉熏熏的打更的\n");
        set("gender","男性");
        set("combat_exp", 999999);
        set_skill("unarmed", 100);

        setup();
        carry_object("/clone/misc/cloth")->wear();
}
int accept_object(object me, object obj)
{
        command("smile");
        command("say 多谢这位" + RANK_D->query_respect(me) +
"，您一定会在这儿玩的开心的！");
        return 1;
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
        this_player()->set_temp("dalikill", 1);
        return 0;
}

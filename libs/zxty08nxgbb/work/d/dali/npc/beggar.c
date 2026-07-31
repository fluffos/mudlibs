// beggar.c

inherit NPC;

void create()
{
        set_name("老汉", ({ "laohan" }) );
        set("gender", "男性" );
        set("age", 53);
        set("long", "一个正在风烛残年中挣扎的老汉\n");
        set("combat_exp", 100);
        set("str", 27);
        set("neili", 200);
        set("attitude", "friendly");
        set("max_neili", 200);
        set("jiali", 2);
        setup();
        set("chat_chance", 5);
        set("chat_msg", ({
"老汉停下来，将地上的垃圾捡了起来．\n",
                (: random_move :)
        }) );
        set("inquiry", ([
                "湖上八娇" : "哦，她们都住在荷花荡上\n",
                "湖上月" : "她？她最爱吃生烧扒翅了．\n",
                "yue" : "她？她最爱吃生烧扒翅了．\n",
        ]) );
        carry_object("/clone/misc/cloth")->wear();
}

int accept_object(object me, object obj)
{
        command("smile");
        command("say 多谢这位" + RANK_D->query_respect(me) + 
"，您一定会在这儿玩的开心的！");
        return 1;
}

/*
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

*/

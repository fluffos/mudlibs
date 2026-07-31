// worker.c

inherit NPC;

void create()
{
        set_name("丫环", ({ "yahuan", "ya" }) );
        set("gender", "女性" );
        set("age", 11);
        set("long", "天真可爱的丫环正在相互低头切切私语。 \n");
        set("combat_exp", 700);
        set("attitude", "friendly");
        set_skill("unarmed", 10);
        set("chat_chance", 10);
        set("chat_msg", ({
"一个丫环叽叽喳喳的告诉另一个丫环：昨天来了个异人，给湖上八个姐姐一人一颗水灵珠．\n",
"一个丫环叽叽喳喳的告诉另一个丫环：柳姐姐的那一头秀发真让人羡慕！\n",
        }) );

        setup();
        carry_object(__DIR__"obj/wch_skirt")->wear();
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
/*
        if( this_player()->query_temp("dalikill") )
        {
                 kill_ob(this_player());
        }
*/
        add_action("do_kill","kill");
}

int do_kill(string arg)
{
        this_player()->set_temp("dalikill", 1);
        return 0;
}

inherit NPC;
#include <ansi.h>;
mixed out_master(mixed arg);
mixed out_master(mixed arg)
{
        object ob, me;
        me = this_player();
        if (!(int)this_player()->query_temp("xmark/学员"))
         {
                tell_object(me,"考官对你说，你不是本校学员，不要来捣乱。\n");
                return 1;
        }

        tell_object(me,"考官沉吟了一会,对"+me->query("name")+"说道:要想毕业,
         你必须过我这关(accept test).\n");
        add_action("do_accept","accept");
        return 1;
}
int do_accept(string arg)
{ 
      mapping guild;
      object ob, me;
        me = this_player();

        if( arg== "test" ) {

                say("\n考官点了点头，说道：很好，小心了　，这是第一招....\n\n");
                COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon"));
                if( (int)this_player()->query("qi") < 0
                        || !present(this_player(), environment()))
                {
                say("考官叹了口气，说道：嘻嘻，连第一招都撑不过，真是自不量力....\n");
                       return 1;
                }
                say("\n考官喝道：第二招....\n\n");
                COMBAT_D->do_attack(this_object(), this_player(),query_temp("weapon"));
                if( (int)this_player()->query("qi") < 0
                || !present(this_player(), environment())) {
                        say("考官叹道：这样子还想出师,唉.....\n");
                        return 1;
                }
                say("\n考官喝道：第三招，你注意了!....\n\n");
                COMBAT_D->do_attack(this_object(), this_player(),query_temp("weapon"));
                if( (int)this_player()->query("qi") < 0
                || !present(this_player(), environment())) {
                        say("考官笑道：你还是回去多多练习吧.....\n");
                        return 1;
        }
        say("\n考官微笑道：恭喜,你可以毕业了，这是你的毕业证，拿好了。\n\n");
        this_player()->set("title","凤凰国防军准尉");
        ob = new(__DIR__"obj/zhengshu1");
        ob->move(this_player());
        this_player()->delete_temp("xmark/学员");
        this_player()->add_temp("bmark/毕业生", 1);
                return 1;
        }
        return 0;
}
void create()
{
        set_name("纪卡诺", ({ "kao guan", "kao" }) );
        set("title", "凤凰军校主考官");
        set("gender", "男性");
        set("age", 35);
        set("long",
                "他是凤凰军校的主考官，学员要毕业，必须过他这关。\n");
        set("attitude", "peaceful");
        set("str", 26);
        set("con", 30);
        set("dex", 30);
        set("int", 28);

        set("neili", 500);
        set("max_neili", 500);
        set("jiali", 2);
        set("max_qi",500);
        set("max_jing",500);

        set("combat_exp", 50000);
        set("apprentice_available", 3);

        set("inquiry", ([
            "毕业": (: out_master :),
        ]) );

        set_skill("unarmed", 60);
        set_skill("sword", 60);
        set_skill("force", 60);
        set_skill("parry", 60);
        set_skill("dodge", 60);
        set_skill("literate", 100);
        setup();

        carry_object("/u/zhangm/fenghuang/obj/sword")->wield();
        carry_object("/u/zhangm/fenghuang/obj/beixin")->wear();
}
void reset()
{
//        delete_temp("learned");
        set("apprentice_available", 3);
}



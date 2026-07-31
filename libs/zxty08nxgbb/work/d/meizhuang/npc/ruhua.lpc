inherit NPC;
 
void create()
{
        set_name("如花", ({ "ru hua","ru","hua" }) );
        set("gender", "女性" );
        set("age",18);
        set("long", @TEXT
如花是大庄主从小收养的孤女。学得了一手人人称绝的
烹调手法，因此梅庄的膳食就由她负责。
TEXT
        );
        set("per", 30);
        set("combat_exp", 10000);
        set_skill("unarmed",30);
        set_skill("dodge", 30);
        set_skill("force",30);
        set("neili", 500);
        set("max_neili", 500);
        set("chat_chance", 7);
        set("chat_msg", ({
        "如花高兴的说：有幸见到您真高兴！\n",
        "如花微笑著说道：梅庄的膳食都是由我负责的哦，你要不要试试？。\n",
        }) );
        setup();
        carry_object("/clone/misc/cloth")->wear();
}
void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}
void greeting(object ob)
{
        object food;
        if( !ob || environment(ob)!=environment() )
                return;
        if ( ob->query_temp("meizhuang/饭") )
           say( "如花微笑着说： 这位" +
                RANK_D->query_respect(ob)+ "，你好！欢迎来到梅庄！\n");
        else
        {       
                tell_room(environment(this_object()),
                        "如花奉上梅花糕，微笑着说道：\n这位" +
                        RANK_D->query_respect(ob)
                        + "，你好！请用饭！\n");
                  food= new("/d/meizhuang/obj/gao");
                food->move(ob);
                
                command ("say 这是我亲手做的，请您品尝！\n");
                ob->set_temp("meizhuang/饭", 1); 
        }
}


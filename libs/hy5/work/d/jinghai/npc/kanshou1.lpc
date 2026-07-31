// kanshou1.c

inherit NPC;

void create()
{
        set_name("库房看守",({"kan shou","kan","shou"}));
        set("gender", "男性" );
        set("age", 25);
        set("long",
                "一看就是一个很有原则的人，整天一个苦瓜脸，冷冷的站在这里。\n");
        set("combat_exp",600000);
        set_temp("apply/defense",10);
        set_temp("apply/attack",5);
        set("attitude", "friendly");
        create_family("靖海派", 3, "弟子");
        setup();
        carry_object("/clone/weapon/gangdao")->wield();
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

        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
                case 0:
                        message_vision("看守打量了$N一会，说道：这位"+
                RANK_D->query_respect(ob)+"，有事吗？\n",ob);
                        break;
                case 1:
                        say( "看守说道：这位" + RANK_D->query_respect(ob)
                                + "，有令牌才可以进去。\n");
                        break;
                           }
}

int accept_object(object who, object ob)
{
	if(who->query("class") != "jinghai")
		return 0;

	if( base_name(ob) != __DIR__"obj/wuqiling" )
		return 0;

	if( ob->query("master") != who->query("id") )
	{
		write("你这是哪偷来的令牌，没收了。\n");
		call_out("dest",1,ob);
		return 1;
	}

	write(name()+"拿起令牌看了看说道：请进去吧。\n");

	who->delete_temp("jinghai_have_ling/wuqi");
	who->set_temp("can_enter_wuqi",1);

	call_out("dest",1,ob);
	return 1;
}

private void dest(object ob)
{
	if(objectp(ob))
		destruct(ob);
}

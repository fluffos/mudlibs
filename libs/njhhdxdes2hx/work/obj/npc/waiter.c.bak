inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("店小二", ({ "waiter" }) );
	set("gender", "男性" );
	set("age", 22);
	set("combat_exp", 5);
	set("attitude", "friendly");
	set("inquiry", ([
		"点菜" : "客官请看墙上的菜单。",
		"找钱" : "本店从不找零钱！",
		"还钱" : "您付过钱么？我不记得了。",
		]));
	setup();
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
        switch( random(3) ) {
                case 0:
                        say( "店小二笑咪咪地说道：这位" + RANK_D->query_respect(ob)
                                + "里面请，里面宽敞。\n");
                        break;
                case 1:
                        say( "店小二用脖子上的毛巾抹了抹手，说道：这位" + RANK_D->query_respect(ob)
                                + "，请进请进。\n");
                        break;
                case 2:
                        say( "店小二说道：这位" + RANK_D->query_respect(ob)
                                + "您要点什么菜? \n");
                        break;
        }
}

int accept_object(object who, object ob)
{
	int i;

	if ((i = who->query("marks/点菜"))) {
		if (ob->value() >= i*100) {
			command("nod");
			tell_object(who, "您可以走了。\n");
			who->delete("marks/点菜");
		}
		else {
			tell_object(who, "没钱你点那么多菜干什么? 到后面厨房里干活抵债吧! \n");
		}
	}
	else {
		command(":D");
		command("say 多谢您老赏钱!\n");
	}
	return 1;
}

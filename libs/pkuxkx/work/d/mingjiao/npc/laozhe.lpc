// laozhe.c
//by yuer

inherit NPC;
inherit F_DEALER;
int ask_me();


void create()
{
	set_name("老者", ({ "lao zhe", "lao" }));
	set("long", "这位老者满脸沧桑，看似常年在外奔波。显然是位见多识广的老人。\n");
	set("gender", "男性");
	set("age", 65);

	set_skill("fanwen", 200);

	set_skill("unarmed", 60);
	set_skill("dodge", 60);
	set_skill("parry", 60);
	set_temp("apply/attack", 60);
	set_temp("apply/defense", 60);
	set_temp("apply/damage", 20);

	set("combat_exp", 200000);
	set("shen_type", 1);
set("vendor_goods",({
__DIR__"obj/fanwen-book"
}));
 set("inquiry", ([
                "字画" : (: ask_me :),
                "picture" : (: ask_me :),

               ]) );
	setup();

}
void init()
       {
                 add_action("do_list", "list");
                 add_action("do_buy", "buy");
}
int ask_me()
{
        if ( this_player()->query_temp("marks/画") ) {
            say("老人说道：你还有完没完? 问话不要钱啊?\n");
	return 0;
        }
        else {
                say(
"这画是我从西方一个地方带回来的。\n"
" 画上的字只有我认识，你要想学，就得给我十两银子。\n"
                );
                this_player()->set_temp("marks/画", 1);
        }
        return 1;
}

int recognize_apprentice(object ob)
{
	if (!(int)ob->query_temp("mark/老"))
		return 0;
	ob->add_temp("mark/老", -1);
	return 1;
}

int accept_object(object who, object ob)
{
	            if (!(int)who->query_temp("mark/老"))
		who->set_temp("mark/老", 0);
	   if (ob->query("money_id") && ob->value() >= 1000) {
		message_vision("老人同意指点$N一些关于梵文的问题。\n", who);
		who->add_temp("mark/老", ob->value() / 50);
		return 1;
                       	}

	return 0;
}


// zhou.c



inherit NPC;
inherit F_DEALER;



void create()
{
        set_name("张老板", ({ "zhang boss","zhang" }) );
        set("gender", "男性" );
        	set_max_encumbrance(100000000);
        set("age", 42);
        set("long",
                "忠厚的脸上长着一双精明的小眼睛。\n");
        set("combat_exp", 2000);
        set("attitude", "friendly");
        setup();
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{       
        object ob;

        ::init();
	add_action("do_list", "list");
        add_action("do_buy", "buy");
	add_action("do_sell", "sell");
	add_action("do_value", "value");
	add_action("do_redeem", "redeem");

        if( interactive(ob = previous_object()) && !is_fighting() )
	{
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
	if( !ob
	|| (environment(ob) != environment())
	|| file_name(environment()) != this_object()->query("startroom"))
		return;
	command("say 当铺就是穷人的银号，本号全天营业，信誉卓著，欢迎惠顾。\n");
}

void die()
{
	message_vision("\n$N死了。\n", this_object());
	destruct(this_object());
}
// waiter.c

inherit NPC;

void create()
{
          set_name("浴室招待", ({ "zhaodai" }) );
         set("gender", "女性" );
	set("age", 19);
	set("long",
                 "她的脸上挂着典型的职业性的微笑，频频鞠躬向客人示意\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("shen_type",1);set("score",200);setup();
        set("chat_chance", 3); 
        set("chat_msg", ({
"招待说，累了就需要恢复体力，我们这里的水是特制的，可以帮你恢复疲劳。\n",
"招待自豪地说，我们贵妃浴在江南都是非常出名的，堪城扬州一绝！！\n",
        }));
        set("inquiry", ([
        ]) );
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
                          say( "招待向你鞠躬说道：这位" + RANK_D->query_respect(ob)
                                  + "，您累了吧，需不需要进来洗个澡呢。\n");
			break;
		case 1:
                          say( "招待微笑对你说" + RANK_D->query_respect(ob)
                                 + "，欢迎光临，本店提供最一流的沐浴。\n");
			break;
	}
}

int accept_object(object who, object ob)
{
	if (ob->query("money_id") && ob->value() >= 3000) 
	{
        	  if(who->query_temp("have_bath"))
                            {
	message_vision("招待摇头对$N说：抱歉，你刚洗过澡，老洗澡对皮肤不好的！”。\n"
, this_player());
                return notify_fail("您不是刚刚洗过澡了么?洗澡不能太频繁了。\n"); 
                             }
                 tell_object(who, "招待指着内室对你说，请进，温泉水已经为您准备好了。\n");

		who->set_temp("rent_paid",1);

		return 1;
	}

	return 0;
}

// By River 98/12
inherit NPC;

void create()
{
	set_name("彝族小伙", ({ "yizu xiaohuo", "yizu", "xiaohuo" }) );
	set("gender", "男性" );
	set("age", 22);
	set("long","这位彝族小伙正笑咪咪地看着你。\n");
	set("combat_exp", 2000);
	set("attitude", "friendly");
        set("inquiry",([
            "价钱" : "想看茶花园，您就付五两白银吧。",
            "price" : "想看茶花园，您就付五两白银吧。",
        ]));
	setup();
        carry_object("/clone/armor/cloth")->wear();
}

void init()
{	
	object ob;

	::init();	
	if( interactive(ob = this_player()) && visible(ob) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 0, ob);
	}
}

void greeting(object ob)
{        
	if (!ob || !present(ob)) return;
       say ("彝族小伙笑嘻嘻迎了上来，说道：这位" + RANK_D->query_respect(ob)+ "，请进请进。\n");
}

int accept_object(object who, object ob)
{
	
	if (ob->query("money_id") && ob->value() >= 500) 
	{
		tell_object(who, "彝族小伙一哈腰，说道：多谢您老，您可以参观一下茶花园了。\n");
		who->set_temp("flower_paid",1);
		return 1;
	}
	return 0;
}

void relay_emote(object me,string arg)
{
	command(arg+" "+me->query("id"));
}

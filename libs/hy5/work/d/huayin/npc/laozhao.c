// laozhao.c

inherit NPC;

void create()
{
	set_name("老赵", ({ "lao zhao" }) );

	set("title","木匠");
	set("gender", "男性" );
	set("age", 50);
	set("long",
		"这位店小二正笑咪咪地忙著，还不时拿起挂在脖子上的抹布擦脸。\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

int accept_object(object who, object ob)
{
	string weather;



	if(   (ob->value() < 100) )
	{
		tell_object(who,"老赵笑呵呵地说道：这世道好人还是多呀，谢谢啦。\n");
		return 1;
	}


	tell_object(who, "老赵笑呵呵地说道：又要作草鞋吧？你们穿鞋也太费啦。\n");
	who->set_temp("valid_enter_drying_room",1);
	return 1;
}

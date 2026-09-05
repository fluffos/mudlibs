// 牧人
// create by zine Aug 30 2010

inherit NPC;
int ask_bow();
void create()
{
	set_name("青年牧民", ({"qingnian mumin", "mumin", "min"}));
	set("gender", "男性");
	set("age", 20+random(5));
    set("combat_exp", 25000);
    set_skill("unarmed", 35);
    set_skill("force", 35);
    set_skill("dodge", 40);
    set_temp("apply/attack", 30);
    set_temp("apply/defense", 40);
	set("shen_type", 1);
	set("chat_chance", 10);
	set("chat_msg", ({
                "青年牧民说道: 我这猎弓也该紧紧弦了。\n",
                (: random_move :)
        }) );

	set("inquiry", ([
                "借弓":   (: ask_bow() :),
                "bow":   (: ask_bow() :),
           
       	]) );
	setup();
	carry_object(__DIR__"items/pixue")->wear();
	carry_object(__DIR__"items/cloth2")->wear();
	carry_object("/d/menggu/obj/hunterbow")->wield();
	
}
	
int ask_bow()
{
	object me=this_player();
	if (present("lie gong",this_object())&&random(10)>2)
	{
		command("say 好吧，猎弓借你也没问题，但你记得要还我哦。");
		command("give "+me->query("id")+" lie gong");
		return 1;
	}
	else
	{
		command("refuse");
		return 1;
	}
}

int accept_object(object me,object ob)
{
	if (!present("lie gong",this_object())&&ob->query("is_hunterbow"))
	{
		command("say 有借有还，再借不难。");
		return 1;
	}
	else
	return notify_fail(this_object()->query("name")+"似乎对"+ob->query("name")+"并不感兴趣。\n");
}
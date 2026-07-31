// xiaoer3.c 店小二

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("店小二", ({ "xiao er", "xiao", "waiter" }) );
	set("gender", "男性" );
	set("age", 22);
	set("long",
		"这位店小二正笑咪咪地忙著，还不时拿起挂在脖子上的抹布擦脸。\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("rank_info/respect", "小二哥");
	set("vendor_goods", ({
		__DIR__"obj/jiudai",
		__DIR__"obj/jiouhulu",
		__DIR__"obj/maoniurou",
		__DIR__"obj/gourou",
	}));

	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	object ob;
	
	::init();
	if (interactive(ob = this_player()) && !is_fighting()) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

void greeting(object ob)
{
	if (!ob || environment(ob) != environment())
		return;
	switch(random(2)) {
	case 0 :
		say("店小二笑眯眯地说道：这位" + RANK_D->query_respect(ob) +
			"，快请进来喝杯水酒吧。\n");
		break;
	case 1 :
		say("店小二说道：哟！这位" + RANK_D->query_respect(ob) + 
			"您来了啊！本店有百年陈酿女儿红出售。要品尝一下吗？\n");
		break;
	}
}

// design by 发现号(find) . all right reserved.

// sunzi.c

inherit NPC;

void create()
{
	set_name("小孙孙", ({ "child"}) );
	set("gender", "男性" );
	set("age", 4);
	set("long",
		"这是一个胖乎乎的小娃娃，大约也就四、五岁，粉嘟嘟的小脸非常可爱。\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("bird",0);
	setup();
	carry_object(__DIR__"obj/doudou")->wear();
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
	if(!query("bird")) {
	command("say 爷爷！刘家姐姐送我的小鸟跑了，爷爷再给我弄一只！");
	}
	else {
	command("say 小鸟真可爱。");
	}
}

int accept_object(object who, object ob)
{
	if(ob->query("name") == "小鸟" && ob->query("id") == "bird") {
	if(query("bird")) {
		command("say 我已经有小鸟了。谢谢。");
		return 1;
		}
	if(!who->query_temp("tao_bird")) {
		command("say 这就是我丢的那只小鸟，原来是你拿走了。");
		return 1;
		}
	who->delete_temp("tao_bird");
	who->set_temp("gongjiang/bird",1);
	command("say 哎呀，这真是一只小鸟呀！太好了！咯咯...");
	set("bird",1);
	return 1;
	}
	else return 0;
}
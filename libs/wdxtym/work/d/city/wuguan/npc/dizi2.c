 //dizi2.c 周圻 by river

#include <ansi.h>
inherit NPC;
int ask_xuexi2();

void create()
{
	set_name("周圻", ({ "zhou qi","zhou","qi", "man" }));
	set("title", "襄阳武馆二弟子");
	set("gender", "男性");
	set("age", 32);         
	set("long", "他是万震山的二弟子，经常闯荡江湖，一张脸晒的黝黑。\n");
	set("combat_exp", 8000);
	set("shen_type", 1);         

	set_skill("force", 60);
	set_skill("strike", 60);

	set("inquiry", ([
		"万震山" : "他老人家是我的恩师啊。",
		"学习" : (: ask_xuexi2 :),        
	]));

	setup();
}

void init()
{
	object ob;
	::init();
	if (interactive(ob = this_player()) && !is_fighting()) {
		remove_call_out("greeting");
		call_out("greeting", 0, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	if ( ob->query_temp("jobask") == 2){
		command("admire zhou");
		command("say 这位" + RANK_D->query_respect(ob) +",你可以 "HIY HBCYN"ask zhou about 学习"CYN" 来向我了解地理情况。"NOR);
	}
}

int ask_xuexi2()
{      
	object ob = this_player();
	if(ob->query_temp("jobask") ==2 ) {      
	command("say 这位" + RANK_D->query_respect(ob) +"也是刚到江湖吧，俺在江湖上可混了好几年了，想知道各派\n"+
		"的情况么？先看看我到过的地方 "HIY HBCYN"look tu"CYN" ，然后向我打听吧 "HIY HBCYN"ask zhou about ***"CYN" 。"NOR);
		ob->delete_temp("jobask");
		if(ob->query_temp("jobover") != 2) {
			ob->set_temp("jobover", 2);
			command("say 听说狄云兄弟还有点事情找你，你最好去看一下。"NOR);
			if ( ob->query("combat_exp") < 200) {
				ob->add("potential", 20);
				ob->add("combat_exp",100);
				tell_object(ob,HIW"你听了周圻的讲解，增加了一百点实战修为和二十点潜能，对江湖又多了一分了解。"NOR"\n");
			}
		}
		return 1;
	}
	if ( ob->query_temp("jobover") == 2) {
		command("say 我不是都和你说了么，狄云兄弟有事找你，快去看下吧。");
		return 1;
	}
}

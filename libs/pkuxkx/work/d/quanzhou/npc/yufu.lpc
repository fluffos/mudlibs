inherit NPC;

int ask_me();


void create()
{
        set_name("渔夫", ({ "yu fu", "fishman", "yu" }));
        set("gender", "男性");
        set("age", 60 + random(10));

        set("long", "一个打渔为生的老汉，正在编织着手里的渔网。\n");

        set("attitude", "friendly");

        set("combat_exp", 1000);
        set("shen_type", 1);

        set_skill("unarmed", 20);
        set_skill("dodge", 20);
        set_skill("parry", 20);
        set_skill("whip", 20);
    set_temp("apply/attack", 10);
        set_temp("apply/defense", 10);
        set("inquiry", ([
                "对岸" : "唉，我打了一辈子的渔了，什么人都见过，山上住了一个疯子
   ，真是疯子，吓死我了。",
                "疯子" : "有时候见他从对岸的洞里出来，其他的我就不知道了。\n",
                "过河" : (: ask_me :),
        ]) );

        setup();

        carry_object("/d/city/obj/cloth")->wear();
}

int ask_me()
{
        if ( this_player()->query_temp("marks/鱼") ) {
	    say("渔夫说道：你还有完没完? 问话不要钱啊?\n");
	}
	else {
		say("渔夫说道：呵呵，我正在忙着呢，老太婆还等我打了渔回去烧汤咧。您自
己想想办法吧. \n" );
		this_player()->set_temp("marks/鱼", 1);
	}
	return 1;
}
int accept_object(object who, object ob)
{
	object wateryi;
	object me=this_player();
	object obj=ob;
	wateryi = new(__DIR__"obj/wateryi");
        if (!userp(ob) && (string)ob->query("id")=="fish") {
              if((int)this_player()->query_temp("marks/鱼")) {
		say(
"渔夫说道：给你个水靠，可以游到对岸。\n"
"渔夫把" + wateryi->query("name") + "交给了" + who->query("name") + "。\n");
		wateryi->move(who);
              }
           else say("渔夫眼也不抬，说道：我忙着呢。\n");
                remove_call_out("destroying");
                call_out("destroying", 1, me, obj);
	return 1;
	}
	return 0;
}
void destroying(object me, object obj)
{
        destruct(obj);
        return;
}






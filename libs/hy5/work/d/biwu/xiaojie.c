// waiter.c

inherit NPC;
#include <ansi.h>;

void create()
{
	set_name("林水仙", ({ "lin shuixian", "lin" }) );
	set("gender", "女性" );
	set("age", 18);
	set("long",
		"这位并不漂亮的小姐吸引了不少目光，定力并不高深的你也不时望向......\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	setup();
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
        add_action("do_yao","want");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
tell_object(ob,"林水仙笑咪咪向你说道：
    从现在开始，你将要接受最大的考验。首先你要通过一个迷宫，然后你会到达风
雨楼或着混元塔，在一刻钟内击败里面的十大高手，最后向盟主挑战。在风雨楼或着
混元塔内没有回头的路，你只有等待一刻钟后自动送会广场中央。
    顺便问一下，您想要(want)馒头和水袋吗？\n\n");
        ob->set_temp("comehere",1);
}

int do_yao()
{
	object ob,kele,hbb;
	ob = this_player();

        if (ob || interactive(ob))
        if ( ob->query_temp("comehere") )
        {
        if (ob->query("gender")=="男性")
		tell_object(ob, "林水仙递给你馒头和水袋时乘机拧了你一把，悄声说道：待会楼上见。\n");
        if (ob->query("gender")=="女性")
		tell_object(ob, "林水仙白了你一眼，馒头和水袋飞了过来，'您老慢吃吧。'\n");
	kele = new(__DIR__"obj/kele");
	hbb = new(__DIR__"obj/hbb");
	kele->move(ob);
	hbb->move(ob);
        ob->delete_temp("comehere");
        return 1;
        }
        return 0;
}

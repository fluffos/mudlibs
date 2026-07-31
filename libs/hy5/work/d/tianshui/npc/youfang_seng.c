// design by 发现号(find) . all right reserved.

// youfang_seng.c

#include <ansi.h>

inherit NPC;

string *make_msg = ({
    HIC "游方喇嘛拿起带鞘的宝剑认真地看了起来。 \n" NOR,
    HIC "游方喇嘛说道：“这可是一件神物，曾被施过咒语，没有很高修行的人是拔(ba)不出来的。\n" NOR,
    HIC "上面说此剑和鞘是用采自深山的千年玄铁经过七七四十九天打造而成。 \n" NOR,
    HIC "剑刃锋利无比，剑鞘也有妙用，可以收(shou)对手的宝剑。\n" NOR,
    HIC "我试一试看能不能拔出来。”\n" NOR,
    HIC "游方喇嘛宣一声佛号，双目紧闭，口中念念有词，突然一声大喝。\n\n" NOR,
});

string ask_me(object who);

void create()
{
        set_name("游方喇嘛", ({ "youfang lama","lama"}) );
        set("gender", "男性" );
        set("age", 45);
        set("str", 20);
        set("long", @LONG
一位身披破旧僧袍的喇嘛。
LONG
);
        set("attitude", "friedly");
        set("score",-20);
        set("combat_exp", 600);
	set("inquiry",([
	"梵文" : (: ask_me :)
]));
        setup();

        carry_object(__DIR__"obj/sengpao")->wear();
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
	if(ob->query_temp("xia_killer")) {
	message_vision( "游方喇嘛对$N说道：多谢这位" + RANK_D->query_respect(ob)
				+ "仗义相救。\n",ob);
	return;
	}
	else return;
}

string ask_me(object who)
{
	object me = this_player();
	if(me->query_temp("xia_killer"))
		return "小僧修习佛法三十余载,不懂梵文哪行。\n";
	else return 0;
}

int accept_object(object me,object obj)
{
	if(!me->query_temp("xia_killer"))
		return 0;
	if(obj->query("id") != "qsword") return 0;
	me->start_busy(4);
	call_out( "make_stage", 1, me,0 );
	return 1;
}

void make_stage(object me, int stage)
{
	tell_object(me, make_msg[stage]);
	if( ++stage < sizeof(make_msg) )
	{
		call_out( "make_stage", 1, me, stage );
		return;
	}
	else
	{
		object ob;

		ob = present("qsword",this_object());
		if(!ob)
			return;
		ob->do_ba("qsword",this_object());
		command("give jian qiao to "+(string)me->query("id"));
		command("give jinghong sword to "+(string)me->query("id"));
		command("say 施主是有福有德之人，多自珍重，小僧告辞了。");
		me->delete_temp("xia_killer");
		destruct(this_object());
	}
	return;
}
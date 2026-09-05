inherit NPC;
#include <ansi.h>
void create()
{
	set_name("赵昀", ({ "zhao yun", "zhao","yun" }));
	set("age", 40);
	set("gender", "男性");
	set("title",HIY+"大宋皇帝"+NOR);
	set("long", "他就是大宋官家，史称宋理宗的赵昀了。\n");
	set("attitude", "peaceful");
//	set("vendetta_mark", "authority");
//      set("pursuer", 1);

	set("str", 30);
	set("dex", 30);
	set("combat_exp", 25000);
	set("shen_type", 1);

	set_skill("unarmed", 70);
	set_skill("dodge", 70);
	set_skill("parry", 70);
	set_skill("blade", 80);
	set_skill("force", 150);
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 40);
	set_temp("apply/damage", 50);
	set_temp("apply/armor", 40);
	set("per",25);
	setup();
	carry_object(__DIR__"obj/longfu")->wear();
}
int reward(object target)
{
	if (userp(target)&&target->query("song/pro"))
	{
		DASONG_D->task_finish(target,10);
		target->set_temp("songtasks/pass_palace",1);
	}
	else if (!userp(target))
	{
		target->leave();
	}
	return 1;
}
int check_juntou_task(object me)
{
	object target;
	if (!me||!living(me))
	return 1;
	if (environment(me)!=environment(this_object()))
	{
		tell_object(me,"竟敢乱走动，小心治你君前失仪。\n");
		return 1;
	}
	if (!objectp(me->query_temp("songtasks/juntou/target")))
	return 1;
	target=me->query_temp("songtasks/juntou/target");
	if (environment(target)!=environment(me)||environment(target)!=environment(this_object()))
	return 1;
	command("say "+target->query("name")+"爱卿，是朕的肱骨之臣啊。");
	me->set_temp("songtasks/juntou/1/finish",1);
	tell_object(me,"引见成功，你也可以回去复命了。\n");
	reward(target);
	return 1;
}
int finish_libu2_see(object me)
{
	command("say "+me->query("name")+"你很不错啊，下去吧。");
	if (userp(me)&&me->query("song/pro"))
	{
		DASONG_D->task_finish(me,6);
		me->set_temp("songtasks/pass_palace",1);
	}
	return 1;
}
void init()
{
	object me=this_player();
	if (me->query_temp("songtasks/juntou/task")==1&&me->query_temp("songtasks/juntou/target")&&!me->query_temp("songtasks/juntou/1/finish"))
	{
		call_out("check_juntou_task",2,me);
	}
	if (me->query_temp("songtasks/libu2_seeemperor"))
	{
		call_out("finish_libu2_see",2,me);
	}
	return;
}

int accept_object(object me,object ob)
{
	if (ob->query("SONG_PAINTING")&&ob->query("owner")==me->query("id")&&me->query_temp("songtasks/hanlin/task")==1)
	{
		me->set_temp("songtasks/hanlin/1/finish",1);
		message_vision("$N仔细地鉴赏着"+ob->query("name")+"。\n",this_object());
		tell_object(me,"你的任务完成了，回去复命吧。\n");
		ob->move(VOID_OB);
		destruct(ob);
		return 1;
	}
	if (ob->query("Strategy_Book_Series"))
	{
		if (me->query("class") != "officer")
		{
			command("say 你无缘无故给我这个干什么啊？");
			return 0;
		}

		if (me->query("pin") > 2)
		{
			command("say 既然找到这些兵书，还不仔细读读？");
			return 0;
		}
		if (me->query_temp("chaoting/strategy_book_quest/"+ob->query("Strategy_Book_Series")))
		{
			command("say 你怎么有两本"+ob->query("name")+"的？");
			return 1;
		}
		me->set_temp("chaoting/strategy_book_quest/"+ob->query("Strategy_Book_Series"),1);
		message_vision("$N接过$n呈上的"+ob->query("name")+"。\n",this_object(),me);
		ob->move(VOID_OB);
		destruct(ob);
		if (me->query_temp("chaoting/strategy_book_quest/1")&&
			me->query_temp("chaoting/strategy_book_quest/2")&&
			me->query_temp("chaoting/strategy_book_quest/3")&&
			me->query_temp("chaoting/strategy_book_quest/4")&&
			((me->query_temp("chaoting/strategy_book_quest/5")&&me->query_temp("chaoting/strategy_book_quest/6")&&me->query_temp("chaoting/strategy_book_quest/7"))||
			(me->query_temp("chaoting/strategy_book_quest/5")&&me->query_temp("chaoting/strategy_book_quest/6")&&me->query_temp("chaoting/strategy_book_quest/8"))||
			(me->query_temp("chaoting/strategy_book_quest/5")&&me->query_temp("chaoting/strategy_book_quest/7")&&me->query_temp("chaoting/strategy_book_quest/8"))||
			(me->query_temp("chaoting/strategy_book_quest/6")&&me->query_temp("chaoting/strategy_book_quest/7")&&me->query_temp("chaoting/strategy_book_quest/8"))))
		{
			if (me->query("score") < 1500)
			{
				me->add("score", 10);
				tell_object(me, "你对皇宋的贡献度增加了。\n");
			}
			me->delete_temp("chaoting/strategy_book_quest");
			me->add("chaoting/jing", 1);
			me->add("combat_exp", 10000);
			tell_object(me, "你的经验增加了。\n");
		}
		return 1;
	}
	return notify_fail(this_object()->name()+"不想要"+ob->query("name")+"。\n");
}
#include <ansi.h>
inherit NPC;
string ask_book();
void create()
{
	set_name("曾从龙", ({ "zeng conglong", "zeng", "conglong" }));
	set("title", MAG"状元公"NOR);
	set("shen_type", 1);

	set("str", 20);
	set("gender", "男性");
	set("age", 55);
	set("long",
		"曾从龙是庆元五年的状元。官至资政殿大学士兼知枢密院事，后进为\n参知政事，以枢密使身份督视江淮、荆州军马，积极主持江淮一带的\n防务。后在主和派人事要求下，理宗将其召回。\n");
	set("combat_exp", 60800);
	set("attitude", "friendly");
	set("inquiry", ([
				"武经总要" :(:ask_book:) ,
	]));
	set("uni_target",1);
	setup();
	carry_object("clone/cloth/cloth")->wear();
}
void unconcious()
{
	die();
}

void die()
{
	this_object()->fullme();
	return;
}
void init()
{
	object *all_ob,me=this_player();
	int count=0;
	if (me->query_temp("wjzy_obtain/step")!=1||!present("nai",me))
	return;
	all_ob=all_inventory(me);
	for (int i=0;i<sizeof(all_ob);i++)
	{
		if (all_ob[i]->query("long")=="这是一颗绿色透亮的柰。这个盛产于南方水果，吃了听说对身体特别好。\n")
		count+=1;
	}
	if (count!=10)
	return;
	command("say 水果买来了？快让我尝尝吧。");
	me->set_temp("wjzy_obtain/step",2);
}
string ask_book()
{
	object me=this_player(),ob;
	if (me->is_busy())
	return "你正忙着呢。\n";
	if (!me->query_temp("wjzy_obtain/step"))
	{
		if (present("nai",me))
		return "你先回去吧。\n";
		command("say 你去城中的陈小二那里买十颗柰过来。");
		me->set_temp("wjzy_obtain/step",1);
		return "";
	}
	if (me->query_temp("wjzy_obtain/step")==4)
	{
		if (me->query_temp("wjzy_obtain/copy_time"))
		{
			if (time()-me->query_temp("wjzy_obtain/copy_time")>7200+random(200))
			{
				ob=new("/d/hangzhou/obj/books/book_strategy_3");
				ob->move(this_object());
				command("give "+me->query("id")+" book");
				command("say 好好学习。");
				me->delete_temp("wjzy_obtain");
				return "";
			}
			else
			return "还没誊抄完呢。大约还需要"+CHINESE_D->chinese_period(7200+me->query_temp("wjzy_obtain/copy_time")-time())+"。";
		}
		command("say 既然袁大府同意了，我也没什么好说的，不过誊抄需要时间，你过一个时辰再来吧。");
		tell_object(me,"大约需要2小时，曾从龙才能誊抄完成。\n");
		me->set_temp("wjzy_obtain/copy_time",time());
		return "";
	}
	if (me->query_temp("wjzy_obtain/step")<3)
	return "快些把柰给我弄来，迟了就不新鲜了。\n";
	else
	return "都说了，要袁大府同意才行，你还纠缠什么？\n";
}
int accept_object(object me,object item)
{
	if (me->query_temp("wjzy_obtain/step")!=2||item->query("long")!="这是一颗绿色透亮的柰。这个盛产于南方水果，吃了听说对身体特别好。\n")
	return notify_fail("无缘无故的我怎么能接受你的东西呢？\n");
	command("say 那我就不客气了。");
	command("eat nai");
	me->add_temp("wjzy_obtain/give_nai",1);
	item->move(VOID_OB);
	destruct(item);
	if (me->query_temp("wjzy_obtain/give_nai")==10)
	{
		me->set_temp("wjzy_obtain/step",3);
		command("say 吃了你这么多东西，正所谓吃人嘴软，不过武经总要乃国之利器，虽然是家祖所著，我也不能随便予人。");
		command("tell "+me->query("id")+" 这样吧，如果你能得到临安府尹袁韶的同意，我就抄写一本给你。");
	}
	return 1;
}

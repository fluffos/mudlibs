// person used in quest shen
#include <ansi.h>
inherit CLASS_D("generate") + "/chinese";
void random_move();
void create()
{
	::create();
	set("name",HIG"G"+query("name")+NOR);
	set("gender", "女性" );
	set("age", 30 + random(30));
	set("long", "节日里携带神秘礼物出现在各地的神秘人物。");
	set("attitude", "friendly");
	set("chat_chance", 50);
	set("chat_msg", ({ (: random_move :) }));
	set("scale", 150);
	set_temp("apply/armor", 30);
	set_temp("apply/damage", 20);
	set_temp("born_time", time());
	NPC_D->init_npc_skill(this_object(), 1);
	setup();
}
int accept_fight(object ob)
{
	command("say 我没有兴趣和你较量，你快滚开。");
	return 0;
}
int accept_hit(object ob)
{
	message_vision("$N脸色一变，闪过一道杀气。喝道：“好一个" +
		       RANK_D->query_rude(ob) + "，来吧！”\n", this_object());
	kill_ob(ob);
	return 1;
}
int accept_kill(object ob)
{
	if (! living(this_object()))
		return 1;
	return accept_hit(ob);
}
int accept_ansuan(object ob)
{
	return notify_fail("那人警惕性好高，你难以下手。\n");
}
int accept_touxi(object ob)
{
	return notify_fail("那人警惕性好高，你难以下手。\n");
}
void random_move()
{
	NPC_D->random_move(this_object());
}
void remove()
{
	if (! environment() || query_temp("die"))
	{
		::remove();
		return;
	}
	if (! living(this_object()))
	{
		message_vision("路过两个人，看到昏迷不醒的$N，叹口气，把$P架走了。\n",this_object());
		return;
	}
	message_vision("$N看了看四周，急急忙忙的走了。\n",this_object());
	::remove();
}
void die(object killer)
{
	object me,obj,ob;
	int lv;

	me = this_object();

	if (objectp(ob = killer) || objectp(ob = query_last_damage_from()))
	{
		obj = new("/clone/money/gold");
		tell_object(ob,me->query("name")+"忽然叫道：咦！看金子！\n"
			"你猛地一愣神间，"+me->query("name")+"一溜烟的已经不见了，仔细一看你手中竟然竟然真的多了"+obj->short()+"\n");
//		obj = new("/clone/shizhe/baozhu");
//		tell_object(ob,me->query("name")+"忽然叫道：看宝贝！\n"
//			"你猛地一愣神间，"+me->query("name")+"一溜烟的已经不见了，仔细一看你手中竟然竟然多了"+obj->short()+"\n");
		obj->move(ob);

		if(random(4)==1)
		{
			obj = new("/clone/gift/fudai");
			tell_object(ob,"下面竟然还压着。。。。。。\n。。。。。。"+obj->short()+"\n");
			obj->move(ob);
			CHANNEL_D->do_channel(me, "rumor","听说" + ob->name(1) +"在" + environment()->short() + "偶遇" +name() + "，获得了一些神秘礼物。");
		}

	}
	destruct(me);
}

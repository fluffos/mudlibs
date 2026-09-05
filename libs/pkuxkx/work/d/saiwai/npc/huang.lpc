// Rewrote by iszt@pkuxkx, 2007-02-11

#include <ansi.h>
inherit NPC;
#include "/d/menggu/shediao_bonus.h"
void create()
{
	set_name("少年", ({"shao nian", "shaonian",}));
	set("long", "这是一个衣衫褴褛、身材瘦削的少年。\n");
	set("gender", "男性");
	set("attitude", "friendly");
	set("age", 15);
	set("shen_type",1);
	set("str", 20);
	set("int", 50);
	set("con", 20);
	set("dex", 20);
	set("uni_target",1);
	set("max_qi", 300);
	set("max_jing", 100);
	set("combat_exp", 200000);
	set_skill("dodge", 20);
	set_skill("parry", 20); 
	set_skill("cuff", 40);
	

	setup();
}

void init()
{
	add_action("do_invite","invite");
}
int leave(object me,object ob)
{
	int e_reward;
	if (!ob)
	{
		return 1;
	}
	message_vision("$N飘然离去。\n",ob);
	if (!me||!living(me))
	{
		return 1;
	}
	tell_object(me,MAG+"向南不远就是中都北京了。\n"+NOR);
	if (!me->query("shediaoquest/zjk_expbonus"))
	{
		me->set("shediaoquest/zjk_expbonus",1);
		e_reward=bonus(me,2200);
		me->add("combat_exp",e_reward);
		tell_object(me,HIC"完成射雕主线任务【初遇黄蓉】，你被奖励了"+chinese_number(e_reward)+"点经验！\n"NOR);
	}
	destruct(ob);
	return 1;
}
int true_leave(object me,object ob)
{
	if (!me||!ob||!living(me)||!living(ob))
	{
		return 1;
	}
	if (base_name(environment(me))!=base_name(environment(ob))||!environment(ob)->query("zjk_jiujia"))
	{
		return 1;
	}
	command("ask "+me->query("id")+" about name");
	message_vision("$N道：我叫"+me->name()+NOR+"。\n",me);
	command("say 我姓黄，单名一个蓉字。");
	ob->set_name("黄蓉",({"huang rong", "rong","huang"}));
	return 1;
}
int dest(object ob)
{
	if (ob)
	{
		destruct(ob);
	}
	return 1;
}
int accept_object(object me,object ob)
{
	if (me->query("shediaoquest/zjk")!=3)
	{
		return notify_fail(this_object()->name()+"不想要"+ob->query("name")+"。\n");
	}
	if (!me->query_temp("shediaoquest/zjk/diaoqiu"))
	{
		return notify_fail(this_object()->name()+"不想要"+ob->query("name")+"。\n");
	}
	if (!ob->query("is__diao__qiu"))
	{
		return notify_fail(this_object()->name()+"不想要"+ob->query("name")+"。\n");
	}
	message_vision("$N也不道谢，飘然离去。\n",this_object());
	me->delete_temp("shediaoquest/zjk");
	me->set("shediaoquest/zjk",4);
	call_out("dest",1,ob);
	me->add_busy(1);
	remove_call_out("true_leave");
	call_out("true_leave",2,me,this_object());
	return 1;
}
int appear5(object me,object ob)
{
	if (!me||!ob||!living(me)||!living(ob))
	{
		return 1;
	}
	if (base_name(environment(me))!=base_name(environment(ob))||!environment(ob)->query("zjk_jiujia"))
	{
		return 1;
	}
	message_vision("$N和$n两人酒足饭饱之后，准备离开酒店。\n",me,ob);
	message_vision("出得店来，朔风扑面。$N似觉寒冷，缩了缩头颈，道：“叨扰了，再见罢。”\n",ob);
	tell_object(me,HIG+"他衣衫单薄，也许可以把貂裘送给他。\n"+NOR);
	me->set_temp("shediaoquest/zjk/diaoqiu",1);
	return 1;
}
int appear4(object me,object ob)
{
	if (!me||!ob||!living(me)||!living(ob))
	{
		return 1;
	}
	if (base_name(environment(me))!=base_name(environment(ob))||!environment(ob)->query("zjk_jiujia"))
	{
		return 1;
	}
	message_vision("$N和$n互相攀谈其儿时的趣事。\n",me,ob);
	message_vision("$N说到忘形之处，一把抓住了$n的左手。一握之下，却觉得他手掌温软嫩滑，柔若无骨，不觉一怔。\n",me,ob);
	message_vision("$N两人继续聊着……\n",me);
	remove_call_out("appear5");
	call_out("appear5",3,me,ob);
	remove_call_out("leave");
	call_out("leave",10,me,ob);
	return 1;
}
int do_invite(string arg)
{
	object me=this_player();
	object ob=this_object();
	if (!arg||(arg!="shao nian"&&arg!="shaonian"))
	{
		tell_object(me,"你要邀请谁和你一起吃？\n");
		return 1;
	}
	if (me->query("shediaoquest/zjk")!=3||!me->query_temp("shediaoquest/zjk/huang_invite"))
	{
		return 0;
	}
	message_vision("$N给$n看得不好意思，只好决定邀请他入座。\n",me,ob);
	command("say 小二，先上四干果，四鲜果，两咸酸，四蜜饯。");
	command("say 八个酒菜是花炊鹌子、炒鸭掌、鸡舌羹、鹿肚酿江瑶、鸳鸯煎牛筋、菊花兔丝、爆獐腿、姜醋金银蹄子。");
	tell_object(me,"你每样一尝，只觉得件件是没吃过的美味。\n");
	me->set("food",(int)me->max_food_capacity()*3/2);
	me->set("water",(int)me->max_water_capacity()*3/2);
	remove_call_out("appear4");
	call_out("appear4",1,me,ob);
	return 1;
}
int appear_3(string arg,object me,object ob)
{
	int e_reward;
	if (!me||!ob||!living(me)||!living(ob))
	{
		return 1;
	}
	if (base_name(environment(me))!=base_name(environment(ob))||!environment(ob)->query("zjk_jiujia"))
	{
		return 1;
	}
	if (arg=="Yes"||arg=="YES"||arg=="yes"||arg=="y"||arg=="Y")
	{
		message_vision("$N赶忙上前拦住店伙：“别动粗，算在我账上。”\n",me);
		message_vision("$N回座又吃，$n却饶有兴趣地跟上来看着$N。\n",me,ob);
		command("look "+me->query("id"));
		tell_object(me,ob->name()+"似乎是想要你邀请(invite)他。\n");
		me->set_temp("shediaoquest/zjk/huang_invite",1);
		return 1;
	}
	else
	{
		message_vision(HIG+"$N把店伙戏耍一番后施施然地离开。\n"+NOR,ob);
		e_reward=bonus(me,1200);
		me->add("combat_exp",e_reward);
		tell_object(me,HIC"完成射雕主线任务【初遇黄蓉】，你被奖励了"+chinese_number(e_reward)+"点经验！\n"NOR);
		destruct(ob);
		return 1;
	}
}
int appear2(object me,object ob)
{
	if (!me||!ob||!living(me)||!living(ob))
	{
		return 1;
	}
	if (base_name(environment(me))!=base_name(environment(ob))||!environment(ob)->query("zjk_jiujia"))
	{
		return 1;
	}
	message_vision("店伙大怒：“你弄脏了我的馒头。”一拳向$N打去。\n",ob);
	message_vision("$N矮身躲过这一拳。\n",ob);
	write(ob->name()+"年纪轻轻，有点可怜。你要不要拦住？(Yes or No)\n");
	me->set("shediaoquest/zjk",3);
	input_to((:appear_3:),me,ob);
	return 1;
}
int appear(object me)
{
	object ob=this_object();
	message_vision("店伙对$N道：“干吗呀？还不给我走？”\n",ob);
	command("xixi");
	command("say 好，走就走。");
	remove_call_out("appear2");
	call_out("appear2",1,me,ob);
	return 1;
}
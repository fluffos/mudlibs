//玩家召唤保镖 zine 2014/8/13
#include <ansi.h>
#include "/clone/npc/bodyguard_config.h"
inherit F_DBASE;
int compare_partners(object ob,object me)
{
	int diff;
	if (!ob->query("potential_client/"+me->query("id")+"/chance"))
	ob->set("potential_client/"+me->query("id")+"/chance",1+random(99));
	if (!ob->query("chance")) 
	ob->set("chance",1+random(99));
	diff=ob->query("chance")-ob->query("potential_client/"+me->query("id")+"/chance");
	if (diff<0) diff=0-diff;
	return diff/10-ob->query_temp("friendship/"+me->query("id"));//差距比较结果0-9，0为最投契，9为差异最大。
}
void add_friendship(object ob,object me,int pts,int temp)
{
	if (temp)
	ob->add_temp("friendship/"+me->query("id"),pts);
	else
	ob->add("friendship/"+me->query("id"),pts);
}
int ask_topic(string topic,object me,object ob)
{
	int diff;
	message_vision(HIW"$N"+HIW+"看着$n"+HIW+"，靠近过去，似乎想随便聊点什么。\n"NOR,me,ob);
	if (ob->query("owner"))
	{
		ob->command("say 主人，我是一个沉默的"+ob->query("title")+"，在工作时间聊天这么不敬业的行为是不会发生在我身上的。");
	}
	else
	{
		diff=compare_partners(ob,me);
		if (ob->query_temp("bodyguard/chitchat/"+me->query("id"))!=topic)
		{
			if (diff>7)
			ob->command("say 你这人怎么这么不死心呢？我跟你无话可说");
			else if (diff>4)
			ob->command("say 我对聊这个不感兴趣。");
			else
			ob->command("whisper "+me->query("id")+" 咱哥俩以后有机会慢慢聊吧。");
			me->add_busy(3+random(3));
		}
		else
		{
			ob->delete_temp("bodyguard/chitchat/"+me->query("id"));
			me->set_temp("bodyguard/chitchat",time());
			ob->add_friendship(me,1,1);
			if (topic=="籍贯")
			ob->command("say 我从小没爹没娘，我师父说我是"+ob->query("birth_place")+"人。");
			else if (topic=="绰号")
			ob->command("say 我就是人称"+ob->query("nickname")+"的"+ob->query("name")+"了。");
			else if (topic=="年龄")
			if (ob->query("gender")!="男性")
			{
				ob->add_friendship(me,-2,1);
				ob->command("say 你觉得问一位女士年龄，合适吗？");
			}
			else
			ob->command("say "+chinese_number(ob->query("age"))+"，怎么啦？我是大宋历"+(2014-ob->query("age"))+"年生的。");
			else if (topic=="师承")
			ob->command("say 保密。");
			else if (topic=="喜好")
			{
				me->set_temp("give_bodyguard",this_object());
				ob->command("say 我喜欢钱，你给我啊？");
			}
			else
			ob->command("cant");
		}
	}
	return 1;
}
int hire(string arg,object ob,object me)
{
	if (member_array(arg,({"Yes","yes","y","Y","YES"}))!=-1)
	{
		message_vision("$N决定雇佣$n成为自己的保镖。\n",me,ob);
		ob->command("jump "+me->query("id"));
		ob->set("owner",me);
		ob->save_owner(me);
	}
	else
	{
		ob->command("disapp");
		ob->command("say 白费那么多口水啊。");
		ob->set_temp("friendship/"+me->query("id"),0);
	}
	return 1;
}
int do_dismiss(object me,object ob)
{
	object *inv=all_inventory(environment(me));
	if (!me->query("MyGuard"))
	return notify_fail("别瞎吹了，根本就没有一名保镖跟随你。\n");
	inv=filter_array(inv, (: $1->query($2) :), "VIP_BODYGUARD");
	if (sizeof(inv)>1)
	return notify_fail("当着众人的面解除雇佣关系太伤人了，做人留点余地吧。\n");
	if (ob->query("owner")!=me)
	{
		message_vision("$N看着$n，一本正经地说道：“可惜我们缘尽于此。”\n",me,ob);
		ob->command("say 你认错人了吧？");
		return 1;
	}
	ob->delete("owner");
	me->delete("MyGuard");
	message_vision(HBCYN+HIW+"$N"+HBCYN+HIW+"和$n"+HBCYN+HIW+"解除了保镖雇佣关系。\n"+NOR,me,ob);
	ob->command("sigh");
	message_vision("$N独自离开，只留下了一个凄凉的背影。\n",ob);
	destruct(ob);
	return 1;
}
int ask_me(object me,object ob)
{
	int chance,diff,num,cd;
	string *topics=({"籍贯","绰号","年龄","师承","喜好"});
	if (ob->query("owner"))
	{
		ob->command("say 主人，我是一个沉默的"+ob->query("title")+"，在工作时间聊天这么不敬业的行为是绝对不会发生在我身上的，这是对我的侮辱。");
		return 1;
	}
	else
	{
		diff=compare_partners(ob,me);
		if (me->query("MyGuard"))
		{
			write(RED+"每人只能雇佣一位保镖，如果想雇佣新保镖，请先在你保镖面前解除(dismiss)雇佣关系。\n"+NOR);
			return 1;
		}
		else if (diff>7)
		{
			ob->command("say 我看你怎么看都很不顺眼啊，我们没什么可谈的。");
			return 1;
		}
		else if (time()-me->query_temp("bodyguard/chitchat")<4)
		{
			cd=time()-me->query_temp("bodyguard/chitchat");
			switch (cd)
			{
				case 0:
				ob->command("say 什么？");
				case 1:
				ob->command("say 我尿急，现在不想说。");
				case 2:
				ob->command("say 有点口渴。");
				case 3:
				write(ob->query("name")+"显然没听到你在说什么。\n");
			}
		}
		else if (diff>4)
		{
			ob->command("say "+RANK_D->query_rude(me)+"，我看你还算顺眼，随便聊聊吧。");
			num=random(sizeof(topics));
			ob->set_temp("bodyguard/chitchat/"+me->query("id"),topics[num]);
			tell_object(me,"你发觉"+ob->query("name")+"似乎谈谈"+topics[num]+"的兴趣。\n");
			return 1;
		}
		else if (diff>1)
		{
			ob->command("say "+RANK_D->query_respect(me)+"，我俩一见如故。");
			num=random(sizeof(topics));
			ob->set_temp("bodyguard/chitchat/"+me->query("id"),topics[num]);
			tell_object(me,"你发觉"+ob->query("name")+"似乎谈谈"+topics[num]+"的兴趣。\n");
			return 1;
		}
		else
		{
			ob->command("say 我们都这么熟悉彼此了。直接了当点吧，我的佣金是每月"+ob->query("wage")+"两金，你愿意雇佣我吗？");
			write("Yes or No?");
			input_to((:hire:),ob,me);
			return 1;
		}
	}
}
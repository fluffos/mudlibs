// 小孩 Zine 9 Sep 2010
// 少年 zine 26 Sep 2010

inherit NPC;
#include <ansi.h>

int ask_huaquan();
void create()
{
        set_name("少年", ({"shao nian","boy" }));
        set("gender", "男性");
        set("age", 13);
        set("str", 1);
        set("dex", 1);
        set("long", "这是一个少年，略带稚气的脸上却有着狡黠的笑容。\n");
        set("combat_exp", 1);
        set("shen_type", 1);
        set("attitude", "peaceful");
		set("uni_target",1);
        set_skill("unarmed", 1);
        set_skill("force", 1);
        set_skill("dodge", 1);
        set_skill("parry", 1);
        set_temp("apply/attack", 5);
        set_temp("apply/defense", 5);
        set_temp("apply/armor", 5);
        set_temp("apply/damage", 1);
	    set("mingqi",1);
		set("qi", 100); 
		set("max_qi", 100); 
        set("neili", 1); 
        set("max_neili", 1);
        set("jiali", 1);
		set("win",1);
		set("lose",1);
		set("inquiry", ([
            "比赛" : (: ask_huaquan :),
            "划拳" : (: ask_huaquan :),
            
       	]) );

        setup();
        carry_object(__DIR__"items/dudou")->wear();
		
}

void init()
{
    add_action("do_show", "chu");
	add_action("do_kill", ({ "kill", "hit"}));
	add_action("do_yes", "yes");
	add_action("do_no", "no");
}

int object_back(object ob)
{
	ob->move("/d/city/xiaoqiao");
}

int object_leave()
{
	object ob=this_object();
	command( "go eastup");
	ob->move("/d/city/hideroom");
	call_out("object_back",60,ob);
}
int yes_no(string arg,object me,object ob)
{
	if (arg=="yes"||arg=="y"||arg=="Yes"||arg=="Y"||arg=="YES")
	{
		message_vision("$N道：“掩护此间难民过江后，你可到苏州去找老夫子，他会教你怎么做的。”\n",ob);
		message_vision("$N笑了笑：“后会有期。”\n",ob);
	}
	else
	{
		message_vision("$N道：“人各有志，也不能勉强，但绝不可帮助鞑子为害我百姓，否则天理难容。”\n",ob);
		message_vision("$N微微一笑：“相信你也不会把我的行踪透露给鞑子吧？”\n",ob);
		message_vision("$N转身离去。\n",ob);
	}
	object_leave();
	return 1;
}
int tell_truth(object me,object ob)
{
	tell_object(me,MAG"你猛然想起一个人来，这个少年似乎是先帝遗孤，大明嫡传的三太子。\n"NOR);
	message_vision(MAG"$N忙上前问道：“你莫非是。。。”\n"NOR,me);
	message_vision(MAG"$N点了点头，轻声道：“我一路观察你，忠肝义胆，不知可愿为我大明效力？(yes/no)”\n"NOR,ob);
	input_to((:yes_no:),me,ob);
	return 1;
}
int judge(object ob,object me)
{
    object rs;
	if (ob->query("lose")>=3)
	{
		message_vision("$N在三局两胜的划拳中输了两局，$n呵呵笑了起来。\n",me,ob);
		command( "say 不知道慈烺、慈灿他们现在可还安好？");
		command( "say 到了凤阳，我能像普通人一样地生活吗？");
		me->delete_temp("skf/huaquan");
		ob->set("win",1);
		ob->set("lose",1);
	}
	else if (ob->query("win")>=3)
	{
		command("say 你在三局两胜的划拳中赢了两局，愿赌服输，我这就给你让开过桥的路。");
		command( "say 耽误你这么多时间，真不好意思，我刚刚捡到一颗人参，我用不着，就送给你吧。");
		message_vision("$N一闪身，让开了路。\n",ob);
		command( "say 不知道慈烺、慈灿他们现在可还安好？");
		command( "say 到了凤阳，我能像普通人一样地生活吗？");
		me->delete_temp("skf/huaquan");
		me->add_temp("skf/credit",3);
		me->set_temp("skf/huaquanpass",1);
		ob->set("win",1);
		ob->set("lose",1);
		if (rs=new(__DIR__"obj/renshen3"))
		rs->move(me);
		if (!me->query("zhusan"))
		{
			if (me->query("ming/in_wait_list")&&me->query("zhusantimes")>=10)
			{
				me->add("zhusan",1);
				me->add("zhusantimes",-10);
				tell_truth(me,ob);
			}
			else if (me->query("zhusantimes")<29)
			{
				//me->add("zhusantimes",1);记号放到任务最后加
				message_vision("这时$N听见远处喊杀声四起，$n满脸歉意地说：“他们应该是来追杀我的，对不起，连累了你。”\n ",me,ob);
				message_vision("$N一闪身躲进前方的密林。\n",ob);
				tell_object(me,"你听得一头雾水，看着身边的难民，也不由不压下好奇心，清兵鞑子就快来了，还是快掩护难民过江为妙。\n");
				object_leave();
			}
			else
			{	
				me->add("zhusan",3);
				me->add("zhusantimes",-29);
				tell_truth(me,ob);
			}
		}
	}
	else
	{
		tell_object(me,"可以开始下一轮的划拳了。\n");
	}
	return 1;
}

int chuquan(object ob)
{
	int n=random(300);
	if (n>199)
	{
		message_vision("$N伸出了拳头，比出了个石头。\n",ob);
		return 1;
	}
	else if (n>99)
	{
		message_vision("$N伸出了两根手指，比了剪刀的造型。\n",ob);
		return 2;
	}
	else
	{
		message_vision("$N伸出了他的五根手指，比了个布。\n",ob);
		return 3;
	}
}
string win_or_lose(int me,int ob)
{
	if (me==ob)
	{
		return HIW+"平局！\n"+NOR;
	}
	if (me-ob==1||ob-me==2)
	{
		add("lose",1);
		return HIR+"少年赢了一局。\n"+NOR;
	}
	if (ob-me==1||me-ob==2)
	{
		add("win",1);
		return HIG+"你赢了一局。\n"+NOR;
	}
}
int do_show(string arg)
{
	object me=this_player();
	object ob=this_object();
	int win,lose,hq_shaonian,hq_me;
	if(!me->query_temp("skf/huaquan"))
	return 0;
	if(me->is_busy())
	return notify_fail("你正忙着呢。\n");
	if (!arg||member_array(arg,({"shitou","jiandao","bu"}))==-1)
	return notify_fail("你要出什么拳？\n");
	hq_shaonian=chuquan(ob);
	if (arg=="shitou")
	{
		message_vision("$N伸出了拳头，比出了个石头。\n",me);
		hq_me=1;
	}
	if (arg=="jiandao")
	{
		message_vision("$N伸出了两根手指，比了剪刀的造型。\n",me);
		hq_me=2;
	}
	if (arg=="bu")
	{
		message_vision("$N伸出了他的五根手指，比了个布。\n",me);
		hq_me=3;
	}
	write(win_or_lose(hq_me,hq_shaonian));
	judge(ob,me);
	return 1;
}

int ask_huaquan()
{
	object me=this_player();
	if (me->query_temp("skf/huaquan"))
	command( "say 你刚才不是要和我划拳吗，还问，要临阵投降吗？");
	else
	command( "say 我口渴了，你去帮我摘一个李子，我就跟你划拳。");
	return 1;
}

int dest(object lizi)
{
	if(lizi)
	destruct(lizi);
	return 1;
}

int accept_object(object me, object lizi)
{
	if( lizi->query("id") != "li zi")
	return notify_fail("少年说道，我只要李子，别拿乱七八糟东西来忽悠我。\n");
	if (me->query_temp("skf/huaquanpass"))
	return notify_fail("少年说道：你刚才不是要和我划拳赢了吗？我不过试试你，义士快去掩护这里的民众撤退吧。\n");
	else
	{
		message_vision("$N接过$s手里的李子，不紧不慢地吃了下去。\n",this_object(),me);
		command("tell "+me->query("id")+" 好吧，我现在不渴了，那让我们来划拳吧，你可以出(chu)石头(shitou)、剪刀(jiandao)和布(bu)，假如你能在三局里赢我两局，我就让你过去。\n");
		me->set_temp("skf/huaquan",1);
		me->add_temp("skf/credit",1);
		call_out("dest",1,lizi);
	}
	return 1;
}

int do_kill(string arg)
{
	object me=this_player();
	if(userp(me)&&(arg=="boy"||arg =="shao nian"))
	{
		message_vision("$N大声喊道：杀人啦，救命啊，大人欺负小孩啦，呸呸呸，真不要脸！\n", this_object());
		tell_object(me,"你心中羞愧，再不好意思向少年出手。\n");
		return 1;
	}
}
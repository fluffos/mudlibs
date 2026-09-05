// 难民 Zine 3 Sep 2010

#include <ansi.h>
inherit NPC;
int ask_escape();


void create()
{
	string * surname=({"赵","钱","孙","李","周","吴","郑","王","东方", "独孤", "慕容", "欧阳", "司马","西门", "尉迟", "长孙", "诸葛"});
	string * givenname=({"一","二","三","四","五","六","七","八","九",});
	int i= random(2);
	set_name(surname[random(sizeof(surname))]+givenname[random(sizeof(givenname))], ({ "nan min", "refugee"}));
	set("title", "扬州城难民");
	set("gender", i?"男性":"女性");
	set("age", 20+random(30));
	set("long",(i?"他":"她")+"是一个扬州的难民，名叫"+this_object()->query("name")+"。\n");
	set("attitude", "peaceful");
	set("combat_exp", 5000000);
	set("str", 20+random(5));
	set("int", 20+random(5));
	set("con", 20+random(5));
	set("dex", 20+random(5));
	set("skf_leader", "");
	set("max_qi", 20000);
	set("max_jing", 20000);
	set("qi",20000);
	set("max_neili", 20000);
	set("neili", 20000);
	set_temp("apply/armor", 100);
	set_temp("skf/huaquanpass",1);
	set_temp("skf/refugeeasked",1);
	set("eff_jing", 20000);
	set("eff_jingli", 20000);
	set("max_jingli", 20000);
	set_skill("dodge", 500);
	set_skill("parry", 500);
	set_skill("force", 500);
	set("uni_target",1);
	set("place",__DIR__"/xiaolu");
	set("no_get", 1);
	set("inquiry", ([
            "name" : "我叫"+this_object()->query("name")+"。",
            "扬州" : "扬州城就快被满族鞑子攻破了，赶紧往南逃啊。",
            "史可法" : "史督师爱民如子。",
			"here" : "这里就是扬州啊，你连这个都不知道？",
			"跟随" : (: ask_escape :),
            "掩护" : (: ask_escape :),
			"避难" : (: ask_escape :),
			"job" : (: ask_escape :),
			"follow" : (: ask_escape :),
			
		]) );
	setup();		
	carry_object(__DIR__"items/cloth1")->wear();
	call_out("dest2",660);

	
}

int dest2()
{
	if(this_object());
	destruct(this_object());
}

int copy(object me)
{
	object ob=this_object();
	int exp,lv,qi;
	qi=me->query("max_qi");
	if (me->query("max_qi")>=20000)
	qi=20000;
	exp = me->query("combat_exp");
	lv = to_int(pow(exp/100,0.333)*10);
	ob->set("combat_exp", exp);
	ob->set_skill("dodge",lv*2/3);
	ob->set_skill("parry",lv*2/3);
	ob->set_skill("force",lv*2/3);
	ob->set_skill("strike",lv*2/3);
	ob->set_skill("taiyi-you",lv*2/3);
	ob->set_skill("taiyi-shengong",lv*2/3);
	ob->set_skill("taiyi-zhang",lv*2/3);
	ob->map_skill("force", "taiyi-shengong");
	ob->map_skill("dodge", "taiyi-you");
	ob->map_skill("strike", "taiyi-zhang");
	ob->map_skill("parry", "taiyi-zhang");
	ob->prepare_skill("strike", "taiyi-zhang");
	ob->set("max_qi",qi);
	ob->set("qi", qi);
	ob->set("max_jing", qi);
	ob->set("jing", qi);
	ob->set("max_neili", me->query("max_neili"));
	ob->set("neili", ob->query("neili"));
	ob->set("max_jingli", me->query("max_jingli"));
	ob->set("jingli", ob->query("jingli"));
}

int removeqb()
{	
	delete_temp("qb");
}

void init()
{
	object me=this_player();
	add_action("do_kill", ({ "kill", "hit"}));
	if (this_object()->query("place")==file_name(environment()))
	{
		return;
	}
	else
	{
		this_object()->set("place",file_name(environment()));
		call_out("init2", 1, me);
		me->start_busy(1);
		return;
	}
}
int appear(object qb)
{
	qb->set("target",this_object()->query("skfleader"));
	qb->set("target_refugee",this_object());
	qb->move(environment(this_object()));
}
int reaction(object ob,object me)
{
	ob->set_temp("qb",1);
	me->start_busy(1);
	remove_call_out("removeqb");
	call_out("removeqb",6);
}
void init2(object me)
{
	object qb;
    int i;
	object ob=this_object();
	object here=environment();
	if (!here||!objectp(here))
	{
		return;
	}
	if (here->query("qinjun_place"))
	{
		return;
	}
	if (here->query("no_fight") || file_name(here)==__DIR__"/changjiang"||me->query_temp("skf/qingbing3"))
	{
		tell_object(me,"虽然一路并没有伏兵出现，你丝毫不敢放松。\n");
	}
	else
	{
		if (me->query_temp("skf/qingbing2") && (random(10)>4))
		{
			for(i = 0; i<10;i++)
			{
				qb = new(__DIR__"qingbing1");
				appear(qb);
			}
			for(i = 0; i<3;i++)
			{
				qb = new(__DIR__"qingbing2");
				appear(qb);
			}
			qb = new(__DIR__"qingbing3");
            appear(qb);
			reaction(ob,me);
			me->set_temp("skf/qingbing3",1);
			me->set_temp("skf/qingbing2",1);
			me->set_temp("skf/qingbing1",1);
		}
		else if (me->query_temp("skf/qingbing1") && (random(10)>4))
		{
			for(i = 0; i<3;i++)
			{
				qb = new(__DIR__"qingbing1");
                appear(qb);
			}
			for(i = 0; i<1;i++)
			{
				qb = new(__DIR__"qingbing2");
                appear(qb);
			}
			reaction(ob,me);
			if (random(100)>33)
			me->set_temp("skf/qingbing2",1);
			me->set_temp("skf/qingbing1",1);
		}
		else
		{
			if ((random(10)>4))
			{
				qb = new(__DIR__"qingbing1");
                appear(qb);
				reaction(ob,me);
				if (random(100)>49)
				me->set_temp("skf/qingbing1",1);
			}
			else
			tell_object(me,"虽然一路并没有伏兵出现，你丝毫不敢放松。\n");
		}
	}
	return;
}

void die()
{
	object pl=find_player(this_object()->query("skfleader"));
	if (pl)
	{
		tell_object(pl,"难民"+this_object()->query("name")+"阵亡，你深感自责，回到史督师处负荆领罪。\n");
		pl->delete_temp("skf");
		pl->set_temp("skf/canceltimeup2",1);
		pl->move("/d/city/junying");
	}
	::die();
}

int ask_escape()
{
	object ob=this_object();
	object me=this_player();
	if (ob->query("skfleader") == me->query("id")) 
	{
		command("say 这位大人，快带我们脱离险境吧" );
		command("beg " + me->query("id"));
		command("follow " + me->query("id"));
		me->set_temp("skf/refugeeasked",1);
		copy(me);
	}
	else
	{
		message_vision("$N疑惑地看着$n。\n",ob,me);
	}
	return 1;
	
}

int dest(object tudou)
{
	if(tudou)
	destruct(tudou);
	return 1;
}

int accept_object(object me, object tudou)
{
	if( tudou->query("id") != "tu dou")
	return notify_fail(this_object()->query("name")+"说道，你的好意我心领了，但我们还是先努力做好逃难这项有意义的事业吧。\n");
	else
	{
		message_vision("$N狼吞虎咽地吃下了土豆。\n",this_object());
		if (random(10)>5)
		{
			this_object()->add("qi",1000);
			message_vision("吃下土豆后，$N似乎体力恢复了很多。\n",this_object());
		}
		else if (this_object()->query("qi")<1000)
		{
			message_vision("吃下土豆后，$N脸色大变。\n",this_object());
			this_object()->unconcious();
		}
		else
		{
			this_object()->add("qi",-1000);
			message_vision("吃下土豆后，$N脸色惨白，可能是吃到变质的食物了。\n",this_object());
		}
		me->add_temp("skf/credit",1);
		call_out("dest",2,tudou);
		return 1;
	}
}

int do_kill(string arg)
{
	object me=this_player();
	object room=environment();
	if((arg=="nan min"||arg =="refugee")&&me->query("id")==this_object()->query("skfleader")&&userp(me))
	{
		message_vision("$N万万没想到$N竟对自己下手，真是死不瞑目。\n",this_object(),me);
		command("say "+me->query("name")+"心狠手辣地杀死了自己保护的难民"+this_object()->query("name")+"！他竟是女真鞑子派来的奸细。");
		die();
		return 1;
	}
	return 0;
}


// 难民 Zine 3 Sep 2010

#include <ansi.h>
inherit NPC;
int ask_escape();


void create()
{
	string * surname=({"赵","钱","孙","李","周","吴","郑","王",});
	string * givenname=({"一","二","三","四","五","六","七","八","九",});
	int i= random(2);
	set_name(surname[random(sizeof(surname))]+givenname[random(sizeof(givenname))], ({ "nan min", "refugee"}));
	set("title", "扬州城难民");
	set("gender", i?"男性":"女性");
	set("age", 20+random(30));
	set("long","他是一个扬州的难民"+this_object()->query("name")+"\n");
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
	set_temp("huaquanpass",1);
	set("eff_jing", 20000);
	set("eff_jingli", 20000);
	set("max_jingli", 20000);
	set_skill("dodge", 500);
	set_skill("parry", 500);
	set_skill("force", 500);
	set("place",__DIR__"xiaolu");
	set("no_get", 1);
	set("inquiry", ([
            "name" : "我叫"+this_object()->query("name")+"。",
            "扬州" : "扬州城就快被满族鞑子攻破了，赶紧往南逃啊。",
            "史可法" : "史督师爱民如子。",
			"here" : "这里就是扬州啊，你连这个都不知道？",
			"跟随" : (: ask_escape :),
            "掩护" : (: ask_escape :),
			"避难" : (: ask_escape :),
			
		]) );
	carry_object(__DIR__"items/xie")->wear();
	carry_object(__DIR__"items/cloth1")->wear();
	setup();
	call_out("jobfail",300);
}

int copy(object me)
{
	object ob=this_object();
	int i;
	int exp,exp2,lv;
	lv=300;
	exp = me->query("combat_exp");
	exp2=exp*10;
	while (lv*lv*lv<exp2)
	{
		lv=lv+10;
	}
	ob->set("combat_exp", exp);
	ob->set_skill("dodge",lv);
	ob->set_skill("parry",lv);
	ob->set_skill("force",lv);
	ob->set_skill("cuff",lv);
	ob->set_skill("taiji-quan",lv);
	
	ob->map_skill("cuff", "taiji-quan");
	ob->prepare_skill("cuff", "taiji-quan");
	ob->set("max_qi", me->query("max_qi")*2/3);
	ob->set("qi", ob->query("max_qi"));
	ob->set("max_jing", me->query("max_jing")*2/3);
	ob->set("jing", ob->query("max_jing"));
	ob->set("max_neili", me->query("max_neili")*2/3);
	ob->set("neili", ob->query("neili"));
}

int removeqb()
{	
	this_object()->delete_temp("qb");
}

void init()
{
	object me = this_player();
	add_action("do_kill", ({ "kill", "hit", "hitall", "killall", "perform"}));
	if (this_object()->query("place")==file_name(environment()))
		{
			return;
		}
	else
		{
			this_object()->set("place",file_name(environment()));
			call_out("init2", 1, me);
		}
}

void init2(object me)
{
	object qb21 = new(__DIR__"npc/qingbing2");
	object qb22 = new(__DIR__"npc/qingbing2");
	object qb23 = new(__DIR__"npc/qingbing2");
	object qb11 = new(__DIR__"npc/qingbing1");
	object qb12 = new(__DIR__"npc/qingbing1");
	object qb13 = new(__DIR__"npc/qingbing1");
	object qb14 = new(__DIR__"npc/qingbing1");
	object qb15 = new(__DIR__"npc/qingbing1");
	object qb16 = new(__DIR__"npc/qingbing1");
	object qb17 = new(__DIR__"npc/qingbing1");
	object qb18 = new(__DIR__"npc/qingbing1");
	object qb19 = new(__DIR__"npc/qingbing1");
	object qb3 = new(__DIR__"npc/qingbing3");
	object ob=this_object();
	object here=environment();
	if (!here)
		{
			return;
		}
	if (ob->query_temp("qb"))
		{
			return;
		}
	if (here->query("no_fight") || file_name(here)==__DIR__"changjiang")
		{
			tell_object(me,"虽然一路并没有伏兵出现，你丝毫不敢放松。\n");
		}
	else
		{
			if	(me->query_temp("qingbing3"))
				{tell_object(me,"虽然一路并没有伏兵出现，你丝毫不敢放松。\n");}
			else 
				{
					if (me->query_temp("qingbing2") && (random(10)>4))
						{
							qb11->set("target",me->query("id"));
							qb11->move(environment());
							qb12->set("target",me->query("id"));
							qb12->move(environment());
							qb13->set("target",me->query("id"));
							qb13->move(environment());
							qb14->set("target",me->query("id"));
							qb14->move(environment());
							qb15->set("target",me->query("id"));
							qb15->move(environment());
							qb16->set("target",me->query("id"));
							qb16->move(environment());
							qb17->set("target",me->query("id"));
							qb17->move(environment());
							qb18->set("target",me->query("id"));
							qb18->move(environment());
							qb19->set("target",me->query("id"));
							qb19->move(environment());
							qb21->set("target",me->query("id"));
							qb21->move(environment());
							qb22->set("target",me->query("id"));
							qb22->move(environment());
							qb23->set("target",me->query("id"));
							qb23->move(environment());
							qb3->set("target",me->query("id"));
							qb3->move(environment());
							ob->set_temp("qb",1);
							me->start_busy(1);
							me->set_temp("qingbing3",1);
							me->set_temp("qingbing2",1);
							me->set_temp("qingbing1",1);
							call_out("removeqb",6);
						}
				else
					{
						if (me->query_temp("qingbing1") && (random(10)>4))
							{
								qb11->set("target",me->query("id"));
								qb11->move(environment());
								qb12->set("target",me->query("id"));
								qb12->move(environment());
								qb13->set("target",me->query("id"));
								qb13->move(environment());
								qb21->set("target",me->query("id"));
								qb21->move(environment());
								ob->set_temp("qb",1);
								me->start_busy(1);
								if (random(100)>33)
									{
										me->set_temp("qingbing2",1);
									}
								else
									{
										me->set_temp("qingbing2",0);
									}
								me->set_temp("qingbing1",1);
								call_out("removeqb",6);
							}
						else
							{
								if ((random(10)>4))
									{
										qb11->set("target",me->query("id"));
										qb11->move(environment());
										ob->set_temp("qb",1);
										me->start_busy(1);
										if (random(100)>49)
											{
												me->set_temp("qingbing1",1);
											}
										else
											{ 
												me->set_temp("qingbing1",0);
											}
										call_out("removeqb",6);
									}
								else
									{
										tell_object(me,"虽然一路并没有伏兵出现，你丝毫不敢放松。\n");
									}
							}
					}
			}	
	}
	return;
}

	
void die()
{
	int i;
	object skf=load_object(__DIR__"npc/shikefa");
	object* all=all_inventory(environment());

			for (i=0;i<sizeof(all) ;i++)
				{
					if (all[i]->query("id")==this_object()->query("skfleader"))
						{
							tell_object(all[i],"难民"+this_object()->query("name")+"阵亡，你深感自责，回到史督师处负荆领罪。\n");
							all[i]->move(__DIR__"junying");
							all[i]->delete_temp("qjasked");
							all[i]->delete_temp("qingbing1");
							all[i]->delete_temp("qingbing2");
							all[i]->delete_temp("qingbing3");
							all[i]->delete_temp("migong");
							all[i]->delete_temp("rabbitfail");
							all[i]->delete_temp("rabbit");
							all[i]->delete_temp("djstart");
							all[i]->delete_temp("zhufapass");
							all[i]->delete_temp("huaquanpass");
							skf->set("deliver",0);
						}
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
			copy(me);
			return 1;
		}
	
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
			if (random(10)>5)
			{
				this_object()->add("qi",1000);
				message_vision(this_object()->query("name")+"狼吞虎咽地吃下了土豆。\n",me);
				message_vision("吃下土豆后，"+this_object()->query("name")+"似乎体力恢复了很多。\n",me);
			}
			else
			{
				if (this_object()->query("qi")<1000)
				{
					this_object()->unconcious();
				}
				else
				{
					this_object()->add("qi",-1000);
					message_vision(this_object()->query("name")+"狼吞虎咽地吃下了土豆。\n",me);
					message_vision("吃下土豆后，"+this_object()->query("name")+"脸色惨白，可能是吃到变质的食物了。\n",me);
				}
			}
			call_out("dest",2,tudou);
		}
	return 1;
}

int do_kill(string arg)
{
	object me=this_player();
	object room=environment();
	if(arg=="nan min"||arg =="refugee")
		{
			if (userp(me))
				{
					message_vision("难民万万没想到$N竟对自己下手，真是死不瞑目。\n", me);
					CHANNEL_D->do_channel(room, "rumor",sprintf("%s心狠手辣地杀死了自己保护的难民！他竟是女真鞑子派来的奸细。", me->query("name")));
					die();
					return 1;
				}
		}

	
}

int jobfail()
{
	int i;
	tell_room(environment(),HIR"突然间出现了大队女真骑兵！！！\n"NOR);
	destruct(this_object());
	return 1;
}
// File		: target.c
// Created By	: iszt@pkuxkx, 2007-03-28
// 萧峰杀手加入机器人鉴别计划

#include <ansi.h>

inherit QUEST_NPC;

varargs void wield_weapon(string weapon);
void die();
int ask_rumors();
int ask_fight();
string ask_surrender(string arg);

void create()
{
	set_name("蒙面杀手", ({ "mengmian shashou", "mengmian", "shashou", "killer" }));
	set("gender", "男性");
	set("age", 22);
	set("title", HIW"西夏" + HIB"一品堂"NOR);
	set("long", "这是一个全身黑衣的杀手，你看不清他的面目。\n");
	set("combat_exp", 10000000);
	set("attitude", "heroism");
	set("rank_info/respect", "大哥");
	add("inquiry", ([
		"name":"不该问的事情少问。",
		"here" : "不知道！",
		"rumors" : (: ask_rumors : ),
		"认输" : (: ask_surrender : ),
		"fight" : (:ask_fight : ),
	]));
	set("food", 500);
	set("water", 500);
	set_temp("canfaint", 0);
	set("is_xiaofeng_killer", 1);
	set("chat_chance", 20);
	set("chat_msg", ({
		(: random_move : ),
		(: random_move : ),
	}));
	set("uni_target", 1);
	set("xiaofeng", 1);
	set("env/wimpy", 35);
	set("jiali", 50);
	set("gem_level", ({ 0, 8334 }));
	setup();
	carry_object("/clone/armor/pifeng")->wear();

	if (random(5) == 0)
		add_money("gold", random(6));
	if (random(4) == 1)
		add_money("silver", 20 + random(8) * 10);
	call_out("do_leave", 1200);
}

void delete_init_num(object me)
{
	me->delete("init_num");
	return;
}

void init()
{
	add_action("do_perform", "perform");
	add_action("do_quan", "quan");
	add_action("do_halt", "halt");
	add_action("do_dian", "dian");
	add_action("do_jiao", "jiao");
	/*****************
			if (environment(this_object())->query("no_fight")||!random(4))
			::random_move();
			//以下有关random_move的修改为防止出现类似init(random_move(init(random_move(....类型的递归调用
			this_object()->add("init_num",1);
			//1秒钟内最多只能触发1次init
			if ( (environment(this_object())->query("no_fight")||!random(4)) && (this_object()->query("init_num")<2) )
			{
			::random_move();
			remove_call_out("delete_init_num");
			call_out("delete_init_num",1,this_object());
			}
			******************/
}

int do_dian()
{
	object me = this_player();
	object ob = this_object();
	if (me->query_temp("canfaint") && ob->query_temp("canfaint"))
	{
		ob->unconcious();
		me->delete_temp("canfaint");
		ob->delete_temp("canfaint");
		message_vision("$N点中$n昏穴，$n又昏迷了过去。\n", me, ob);
		return 1;
	}
	else
	{
		return 0;
	}
}

int do_copy(object me)
{
	int level;
	int job_level, skf;
	string job_type;

	if (!objectp(me))
		return 0;

	job_level = query("job_level");
	job_type = query("job_type");
	set("level", to_int(pow(me->query("combat_exp") / 400, 0.333)));
	level = pow(me->query("combat_exp") / 100, 0.333) * 9;
	level += level / 14 * job_level;
	skf = 115 - job_level * 2;
	if (job_type == "降")
	{
//		skf = skf * 9 / 10; //modified by whuan
		level = level * 9 / 10;
	}
	if (job_type == "教")
	{
		skf = skf * 11 / 10;
		level = level * 11 / 10;
	}
	if (me->query("hsz_auto"))
	{
		skf = skf * 3/2;
		level = level * 3/2;
	}

	es_copy1(me, "random", (job_level + 8) * 10, skf, 15);
	qx_copy2(level, 10, 15);
	if (query_temp("advanced_quest"))
		set("name", HIR + query("name") + NOR);
	set("chat_chance_combat", 150);
	set("neili", query("max_neili") * 2);

	set("uni_target", me);
	wield_weapon();
}

int do_copy_f(object me)
{
	int level;
	int job_level, skf;

	if (!objectp(me))
		return 0;

	job_level = query("job_level");
	set("level", me->query("level")+50);
	level = pow(me->query("combat_exp") / 100, 0.333) * 9;
	level += level / 14 * job_level;
	skf = 115 - job_level * 2;

	es_copy1(me, "random", (job_level + 8) * 10, skf, 15);
	qx_copy2(level, 10, 15);
	if (query_temp("advanced_quest"))
		set("name", HIR + query("name") + NOR);
	set("chat_chance_combat", 150);
	set("neili", query("max_neili") * 2);

	wield_weapon();
}

void start_busy(mixed new_busy, mixed new_interrupt)
{
	if (intp(new_busy) && new_busy > 15)
		::start_busy(15 + random(3));
	if (intp(new_busy) && new_busy > 8 && new_busy <= 15)

		::start_busy(7 + random(3));
}

int do_perform(string arg)
{
	object me = this_player();
	if (query("job_type") != "劝" || me->is_fighting())
		return 0;
	else
	{
		write("劝人走入正道，只有一招一式的打才能让人心服，你此时不便出手。\n");
		return 1;
	}
}

void unconcious()
{
	string *pinying;//姓名 by whuan
	object me = query("uni_target");
	object killer = get_damage_origin_object();
	object ob = this_object();
	if (ob->query_temp("faint"))
	{
		::unconcious();
		return;
	}
	if (query("qi") > 100)
		return;
	ob->delete_temp("faint");
	if (!me || !objectp(me))
	{
		die();
		return;
	}
	if (!me->query_temp("xiaofeng/target_id"))
	{
		::unconcious();
		return;
	}
	if (query("job_type") == "擒")
	{
		if (!ob->query("niming"))
		{
			message_vision(HIC"\n$N走近$n，只见$n衣领上几个蝇头小字，显是$n姓名。\n"NOR, me, this_object());
			pinying = explode(me->query_temp("xiaofeng/target_id"), " ");
			set_name(me->query_temp("xiaofeng/target_name"), ({ me->query_temp("xiaofeng/target_id"), pinying[0], pinying[1] }));
			ob->set("niming", 1);
			ob->set_temp("faint", 1);
			ob->set_temp("canfaint", 1);
			ob->set("chat_chance", 0);
			killer->set_temp("canfaint", 1);
		}

		if (!query_temp("droped"))
		{
			GEM_D->drop(this_object(), me);
			set_temp("droped", 1);
		}
		::unconcious();
		return;
	}
	if (query("call_die")) return;
	set("call_die", 1);
	if (get_damage_origin_object())
		message_vision(HIR"\n$N眼见今日就要死在$n手中，叹了口气，一咬衣领，便直挺挺的倒了下去！\n"NOR,
		this_object(), get_damage_origin_object());
	call_out("die", 1);
}

void die()
{
	object me = query("uni_target");
	object ob = this_object();
	object equip;
	if (!me || !objectp(me) || me->query_temp("xiaofeng/target_ob") != ob)
	{
		::die();
		return;
	}	//for test
	if (!objectp(get_damage_origin_object()) || get_damage_origin_object() != me)
	{
		::die();
		return;
	}
	if (query("job_type") == "杀")
	{
		me->set_temp("xiaofeng/hard", query_temp("advanced_quest"));
		me->set_temp("xiaofeng/finish", 1);
	}
	else
		me->set_temp("xiaofeng/fail", 1);
	message_vision(HIC"\n$N抢上一步，只见$n衣领上几个蝇头小字，显是$n姓名。\n"
		HIB"而此时$n嘴唇青黑，身中剧毒，眼见不活了。\n"NOR, me, this_object());
	set_name(me->query_temp("xiaofeng/target_name"), ({ me->query_temp("xiaofeng/target_id"), }));
	GEM_D->drop(ob, me);
	::die();
}

string ask_surrender(string arg)
{
	object me = this_player();
	object ob=this_object();
	
/*	if(arg && sscanf(arg, "%s", arg)==1)
	{	
         ob = present(arg, environment(me));
	}
*/

	if (ob->query("waiting_recover"))
		return "我还没恢复好，你想乘人之危么？\n";
	if (ob->query("qi") > ob->query("max_qi") / 2 || me->query("qi") < me->query("max_qi") / 2)
		return "认输？嘿嘿，我看该你认输才对！\n";
	if (me->query_temp("xiaofeng/finish"))
		return "老子已经认输了，你还讨什么口舌之利？！\n";
	if (ob->query("job_type") != "降" || ob->query("uni_target") != me)
		return "叫老子认输？嘿嘿，你别做梦了！\n";
	delete("waiting_recover");
	if (random(2 + query("job_level") / 2))
	{
		//声望最高的门派的额外优势
		if (FAMILY_D->get_repute_top1() == me->query("family/family_name") && (random(4)==0))
		{
			command("say 原来你是武林第一大派," + me->query("family/family_name") + "派来降我的。万万没有想到。");
		}
		else
		{
			ob->set("waiting_recover", 1);
			command("halt");
			return "我不服，等我休息一下，咱们再打过！\n";
		}
	}
	me->set_temp("xiaofeng/hard", ob->query_temp("advanced_quest"));
	me->set_temp("xiaofeng/finish", 1);
	me->set_temp("xiaofeng/bonus", 4000);
	command("halt");
	command("sigh");
	//remove_all_enemy();
	ob->remove_all_enemy();
//	GEM_D->drop(this_object(), me);
	GEM_D->drop(ob, me);

	call_out("do_leave", 1);
	return "算了，我认输啦，算你狠！\n";
}

//由COMBAT_D调用的战胜接口，负责在战斗胜利以后直接检查战胜任务判定，而不用等战斗结束以后再检查
//by seagate@pkuxkx
void winner_reward(object killer, object victim)
{
	int qipct;

	if (query("waiting_recover"))
	{
		tell_object(killer, "我还没恢复好，你想乘人之危么？\n");
		return;
	}

	if (killer->query_temp("xiaofeng/finish"))
	{
		tell_object(killer, "老子已经认输了，你还讨什么口舌之利？！\n");
		return;
	}

	qipct = query("winner_pct");
	qipct = qipct + (100 - qipct)*(query("max_qi") - query("qi")) / query("max_qi");
	set("winner_pct", qipct);

	if (query("job_type") == "劝" && query("uni_target") == killer)
	{
		if (random(100 + query("job_level") * 2) < qipct)
			set("quan_success", 1);
		tell_object(killer, "你一顿棍棒乱揍，看来杀手有点怕你了。\n");
		return;
	}

	if (query("job_type") != "降" || query("uni_target") != killer)
	{
		tell_object(killer, "叫老子认输？嘿嘿，你别做梦了！\n");
		return;
	}

	if (killer->query("qi") < killer->query("max_qi") / 2)
	{
		tell_object(killer, "认输？嘿嘿，我看该你认输才对！\n");
		return;
	}

	delete("waiting_recover");
	if (random(100 + query("job_level") * 2) >= qipct)
	{
		//声望最高的门派的额外优势
		if (FAMILY_D->get_repute_top1() == killer->query("family/family_name") && random(4)==0)
		{
			command("say 原来你是武林第一大派," + killer->query("family/family_name") + "派来降我的。万万没有想到。");
		}
		else
		{
			set("waiting_recover", 1);
			command("halt");
			tell_object(killer, "我不服，等我休息一下，咱们再打过！\n");
			return;
		}
	}

	killer->set_temp("xiaofeng/hard", query_temp("advanced_quest"));
	killer->set_temp("xiaofeng/finish", 1);
	killer->set_temp("xiaofeng/bonus", 4000);
	command("halt");
	command("sigh");
	remove_all_enemy();
	GEM_D->drop(this_object(), killer);
	call_out("do_leave", 1);
	tell_object(killer, "算了，我认输啦，算你狠！\n");
	return;
}

int accept_fight(object me)
{
	if (me != query("uni_target"))
		return 0;
	if (query("waiting_recover")
		&& (query("qi") < query("max_qi")
		|| query("jing") < query("max_jing")
		|| query("neili") < query("max_neili")))
	{
		command("say 我还没恢复好，你想乘人之危么？");
		return 0;
	}
	if (query("waiting_recover"))
		command("say 好好好，我们再来打过！");
	if (::accept_fight(me))
	{
		if (query("waiting_recover"))
			delete("waiting_recover");
		return 1;
	}
	else
		return 0;
}
int do_quan(string arg)
{
	object me = this_player();
	object target;
	if ((int)me->query("jing") - (int)me->query("max_jing") / 14 < 100) {
		tell_object(me, "你现在精神不佳，不宜劝导别人。\n");
		return 1;
	}
	if( !arg || sscanf(arg, "%s", arg)!=1 )
         return notify_fail("指令格式 : quan <某人>\n");
	else
	{	
         target = present(arg, environment(me));
	}
	if (!target)
	{
		return notify_fail("都没这个人，quan啥quan啊\n");
	}

	if (target->query("job_type") != "劝" || target->query("uni_target") != me)
	{
		if (random(2))
			command("trouble");
		else
			command("goaway " + me->query("id"));
		return 1;
	}
	if (me->is_busy() || me->is_fighting())
	{
		write("你现在没功夫规劝别人。\n");
		return 1;
	}
	me->receive_wound("jing", random(query("max_jing") / 14) + 100, "劝服" + query("name") + "被烦");
	target->receive_damage("qi", random(me->query("jing") / 4), me);
	me->start_busy(4 + random(4));
	if (target->query("qi") > random(target->query("max_qi") * 2 / 3) &&
		!target->query("quan_success"))
	{
		//message_vision(HIR"$N走上前去，试图劝服$n，但$n不耐烦的转了个身，不愿听$N说下去。\n"NOR, me, this_object());
		message_vision(HIR"$N走上前去，试图劝服$n，但$n不耐烦的转了个身，不愿听$N说下去。\n"NOR, me, target);

		write(HIG"看来教训教训他再试试，可能效果会更好。\n"NOR);
		return 1;
	}
//	message_vision(HIR"$N嘿嘿一笑：「$n，你都到了如此田地，怎地还是执迷不悟？」\n"NOR, me, this_object());
	message_vision(HIR"$N嘿嘿一笑：「$n，你都到了如此田地，怎地还是执迷不悟？」\n"NOR, me, target);

	me->set_temp("xiaofeng/hard", query_temp("advanced_quest"));
	me->set_temp("xiaofeng/finish", 1);
	me->set_temp("xiaofeng/bonus", 4000);
	command("halt");
	command("sigh");
//	remove_all_enemy();
	target->remove_all_enemy();

//	GEM_D->drop(this_object(), me);
	GEM_D->drop(target, me);
	call_out("do_leave", 1);
	return 1;
}

int do_jiao(string arg)
{
	object me = this_player();
	object ob;
	int job_cnt;
	int jiao_success=0;
	int jx_int1,jx_int2,jx_int3;
	if ((int)me->query("jing") - (int)me->query("max_jing") / 14 < 100) {
		tell_object(me, "你现在精神不济，不宜教训别人。\n");
		return 1;
	}
	if( !arg || sscanf(arg, "%s", arg)!=1 )
         return notify_fail("指令格式 : jiao <某人>\n");
	else
	{	
         ob = present(arg, environment(me));
	}
	if (ob)
	{
		job_cnt=ob->query("xiaofeng/jiao_cnt");
	}
	else return notify_fail("都没这个人，jiao啥jiao啊\n");

	if (ob->query("job_type") != "教" || ob->query("uni_target") != me)
	{
		if (random(2))
			command("trouble");
		else
			command("goaway " + me->query("id"));
		return 1;
	}
	if (me->is_busy() || me->is_fighting())
	{
		write("你现在没功夫教训别人。\n");
		return 1;
	}
	me->receive_wound("jing", random(query("max_jing") / 14) + 100, "教训" + query("name") + "被气");
	me->start_busy(4 + random(4));
	ob->add("xiaofeng/jiao_cishu",1);
	if (ob->query("xiaofeng/jiao_cishu")>5)
	{
		message_vision(HIR"$N一再打骂，$n不堪教训，忍无可忍，一咬衣领，便直挺挺的倒了下去！\n"NOR, me, ob);
		call_out("die", 1);
		return 1;
	}
	if (job_cnt>80)
	{
		job_cnt=80;
	}
	if (job_cnt<20)
	{
		job_cnt=20;
	}
	jx_int1=ob->query("qi");
	jx_int2=ob->query("eff_qi");
	jx_int3=ob->query("max_qi");
	if ((jx_int1 > jx_int3*(job_cnt-5)/100)&&(jx_int1 < jx_int3*(job_cnt+5)/100))
	{
		jiao_success=1;
	}
	else
	{
		if ((jx_int1 < jx_int3*(job_cnt-20)/100)||(jx_int1 > jx_int3*(job_cnt+20)/100))
		{
			jiao_success=0;
		}
		else
		{
			if ((jx_int1 < jx_int3*(job_cnt-15)/100)||(jx_int1 > jx_int3*(job_cnt+15)/100))
			{
				if (random(50)==0)
					{
						jiao_success=1;
					}
			}
			else
			{
				if ((jx_int1 < jx_int3*(job_cnt-10)/100)||(jx_int1 > jx_int3*(job_cnt+10)/100))
				{
					if (random(8)==0)
						{
							jiao_success=1;
						}
				}
				else
				{
					if ((jx_int1 < jx_int3*(job_cnt-5)/100)||(jx_int1 > jx_int3*(job_cnt+5)/100))
					{
						if (random(3)==0)
							{
								jiao_success=1;
							}
					}
				}

			}
		}
	}
	if ((jx_int2 > jx_int3*(job_cnt-5)/100)&&(jx_int2 < jx_int3*(job_cnt+5)/100))
	{
		jiao_success=1;
	}
	else
	{
		if ((jx_int2 < jx_int3*(job_cnt-20)/100)||(jx_int2 > jx_int3*(job_cnt+20)/100))
		{
			jiao_success=0;
		}
		else
		{
			if ((jx_int2 < jx_int3*(job_cnt-15)/100)||(jx_int2 > jx_int3*(job_cnt+15)/100))
			{
				if (random(50)==0)
					{
						jiao_success=1;
					}
			}
			else
			{
				if ((jx_int2 < jx_int3*(job_cnt-10)/100)||(jx_int2 > jx_int3*(job_cnt+10)/100))
				{
					if (random(8)==0)
						{
							jiao_success=1;
						}
				}
				else
				{
					if ((jx_int2 < jx_int3*(job_cnt-5)/100)||(jx_int2 > jx_int3*(job_cnt+5)/100))
					{
						if (random(3)==0)
							{
								jiao_success=1;
							}
					}
				}

			}
		}
	}
/*	if (wizardp(me))
	{
		jiao_success=1;
	}
*/
	if (!jiao_success)
	{
		message_vision(HIR"$N打了$n一通，试着教训$n，但$n仍然骂骂咧咧，不愿听$N说下去。\n"NOR, me, ob);
		write(HIG"看来还得教训教训他再试试，可能效果会更好。\n"NOR);
		return 1;
	}

	message_vision(HIR"$N将$n狠狠教训了一通后，说道：「$n，你都到了如此田地，怎么还如此不知羞耻？」\n$n掩面长叹,对自己所做所为似有后悔之意。\n"NOR, me, ob);

	me->set_temp("xiaofeng/hard", query_temp("advanced_quest"));
	me->set_temp("xiaofeng/finish", 1);
	me->set_temp("xiaofeng/bonus", 4000);
	command("halt");
	command("sigh");
	//remove_all_enemy();
	ob->remove_all_enemy();
//	GEM_D->drop(this_object(), me);
	GEM_D->drop(ob, me);

	call_out("do_leave", 1);
	return 1;
}

void do_leave()
{
	if (!this_object())
		return;
	message_vision("$N纵身远远的去了。\n", this_object());
	destruct(this_object());
}
int accept_object(object who, object ob)
{
	if (ob->query("id") == "jinchuang yao")
	{
		command("joythank " + who->query("id"));
		command("eat yao");
		receive_curing("qi", 400);
		return 1;
	}
	if (ob->query("id") == "yangjing dan")
	{
		command("joythank " + who->query("id"));
		command("eat dan");
		receive_curing("jing", 400);
		return 1;
	}
	if (ob->query("id") == "qiannian renshen")
	{
		command("joythank " + who->query("id"));
		command("eat shen");
		set("neili", query("max_neili") * 2);
		return 1;
	}
	return 0;
}
int do_halt()
{
	object me = this_player();
	if (me != this_object()->query("uni_target"))
	{
		return 0;
	}
	if (me->is_busy())
		return 1;
	if (random(5) || !me->is_fighting())
		return 0;
	write("你想停下来，可是" + this_object()->query("name") + "步步紧逼，直逼得你手忙脚乱！\n");
	me->start_busy(1 + random(4));
	return 1;
}
int ask_rumors()
{
	object player = this_object()->query("uni_target");
	if (!player)
	{
		command("say 嘿嘿，想知道你的祭日么？");
		return 1;
	}

	if (this_object()->is_fighting())
	{
		command("say 我现在忙着呢，没空理你！");
		return 1;
	}
	if (!objectp(player))
		command("say 听说有个人会来找我麻烦，你知道他在那里么？");
	else if (player != this_player())
		command("say 听说有个叫" + player->query("name") + "的会来找我麻烦，你知道他在那里么？");
	else
	{
		command("say 好小子，天堂有路你不走，地狱无门自来投。我正找你呢，看招！");
		fight_ob(this_player());
	}
	return 1;
}

int ask_fight()
{
	if (this_object()->query("uni_target") == this_player()) {
		if (environment(this_object())->query("no_fight"))
		{
			command("say 此处比武多有不便，你且随我来！");
			random_move();
		}
		else command("say 要打便打，不必多言！");
	}
	else command("say 就你也配跟我讨教功夫？！");
	return 1;
}

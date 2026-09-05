
#include <ansi.h>

inherit NPC;
void die();
void decide_pfm();
int kill_target();

void create()
{
	set_name("阿四", ({ "a si", "si"}) );
	set("gender", "男性" );
	set("age", 25);
	set("long", "这是一名身高八尺、膀大腰圆，满脸络腮胡子的大汉，俾睨之间眼神锐利如刀。\n");
	set("combat_exp", 1000000000); // 1000m
	set("attitude", "hateful");
	set("max_qi", 1000000);
	set("max_jing", 1000000);
	set("str", 50);
	set("int", 50);
	set("con", 50);
	set("dex", 50);
    set("lvliu_npc", 1);
	set("shen", -100000);
	set("zyhb", 1);
	set("safari_skill/xx_dushen",1);
	set("max_neili", 50000);
	set("neili", 100000);
	set("total_exp", 100000);
    set_skill("dodge", 3000);
    set_skill("strike", 3000);
    set_skill("force", 3000);
    set_skill("parry", 3000);
    set_skill("poison", 3000);
    set_skill("literate", 3000);
    set_skill("zhaixinggong", 3000);
    set_skill("xingxiu-duzhang", 3000);
	set_skill("huagong-dafa", 3000);
    set_skill("bingcan-duzhang", 3000);
    map_skill("parry", "xingxiu-duzhang");
    map_skill("dodge", "zhaixinggong");
    map_skill("strike", "bingcan-duzhang");
    map_skill("force", "huagong-dafa");
    prepare_skill("strike", "bingcan-duzhang");
	set_temp("apply/attack", 500);
	set_temp("apply/defense", 500);
	set_temp("apply/armor", 500);
	set_temp("apply/damage", 100);
	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: decide_pfm :),
	}) );
	set("family/family_name", "星宿派");
	set("purefamily/family_name", "星宿派");
	set("purefamily/level", 5);
	setup();
    carry_object("/clone/armor/cloth")->wear();
}

protected void reset_npc()
{
	object ob = this_object();
	ob->clear_condition();
	ob->set("eff_qi", ob->query("max_qi"));
	ob->set("qi", ob->query("max_qi"));
	ob->set("eff_jing", ob->query("max_jing"));
	ob->set("jing", ob->query("max_jing"));
	ob->set("neili", 2*ob->query("max_neili"));
	ob->map_skill("parry", "xingxiu-duzhang");
	ob->map_skill("dodge", "zhaixinggong");
	ob->map_skill("strike", "bingcan-duzhang");
	ob->map_skill("force", "huagong-dafa");
	ob->prepare_skill("strike", "bingcan-duzhang");
	ob->delete("dushen/init_time");
	ob->delete("threat");
	ob->delete("total_damage");
	ob->delete("combat_time");
	ob->delete("next_busy");
	ob->delete_temp("focus_target");
	ob->delete_temp("recover_time");
}

void init()
{
	object me, ob = this_object();
	me = this_player();
	add_action("do_halt", "halt");
	if (!ob->is_fighting())
	{
	//开启一场新的战斗
		reset_npc();
		message_vision(HIW"\n$N深深地长吸了一口气。\n\n"NOR, ob);
		CHANNEL_D->do_channel(this_object(), "rw", HIW + "哈哈哈！有人不自量力来挑战本大爷了！很好，去死吧！"NOR);
		remove_call_out("kill_target");
		call_out("kill_target", 5);
	}
	ob->kill_ob(me);
}

void decide_pfm()
{
	object *enemy,npc,target;
	string uid;
	int exp;
	npc = this_object();
	if(!npc->query_temp("powerup"))
	{
		command("exert powerup");
		return;
	}
	if(!npc->query_temp("bingcan-duzhang/tuxi"))
	{
		command("perform strike.tuxi");
		return;
	}
	if(npc->query("qi")<(npc->query("max_qi")/5) && !npc->query_temp("dushen") && !npc->query("dushen/init_time"))
	{	// 气血减少到20%以下时使用一次毒神
		npc->add("neili", 1500);
		map_skill("strike", "xingxiu-duzhang");
		prepare_skill("strike", "xingxiu-duzhang");
		command("perform strike.dushen");
		map_skill("strike", "bingcan-duzhang");
		prepare_skill("strike", "bingcan-duzhang");
	}
	if ( npc->query("qi")<(npc->query("eff_qi")-10000) && time()-npc->query_temp("recover_time")>= 10)
	{
		command("exert recover");
	}
	if ( npc->query("jing")<(npc->query("eff_jing")-50000) && time()-npc->query_temp("recover_time")>= 10)
	{
		command("exert regenerate");
	}
	enemy = query_enemy() - ({ 0 });
	target = enemy[random(sizeof(enemy))];
	exp = target->query("combat_exp");
	if ( !npc->is_busy() && 
		( !userp(target)    // NPC
		|| exp < 20000000 // 20m以下的直接咔嚓了
		|| (exp < 30000000 && random(3)) // 30m以下的 66%
		|| (exp < 40000000 && !random(3)))) // 40m以下的 33%
	{
		message_vision(HIM"\n$N对着$n" HIM "嘿嘿一笑，张开蒲扇般的大掌，随手一掌就拍了过去。\n"
			+HIR"这一掌似慢实快，$n" HIR "竟完全无法闪避，砰的一声，筋断骨折，软绵绵地倒了下去。\n\n",npc,target);
		target->receive_damage("qi", 0, npc);
		target->die();
		return;
	}
	if (random(2))
		return;
	uid = target->parse_command_id_list()[0];
	map_skill("strike", "xingxiu-duzhang");
    prepare_skill("strike", "xingxiu-duzhang");
	command("perform strike.sandu " + uid);
	map_skill("strike", "bingcan-duzhang");
    prepare_skill("strike", "bingcan-duzhang");
}

int do_halt()
{
	object me = this_player();
	if(!me->is_fighting())
	{
		return 0;
	}	
	message_vision(HIR"$N趁$n露怯之际猛攻几招，逼得你更加手忙脚乱！\n"NOR, this_object(), me);
	me->add_busy(1+random(2));
	return 1;
}

int kill_target()
{
	object ob, *eny;
	int c = 0;
	ob = this_object();
	eny = all_inventory(environment(ob));
	for (int i=0;i<sizeof(eny);i++)
	{
		if (eny[i] != ob && eny[i]->is_character()) {
			c++;
			ob->kill_ob(eny[i]);
		}
	}
	if (c>0)
	{
		ob->add("combat_time", 5);
		remove_call_out("kill_target");
		call_out("kill_target", 5);
	}
	else
	{
// 战斗结束，对手死光光
		reset_npc();
		CHANNEL_D->do_channel(this_object(), "rw", HIW + "一群无能之辈！还以为有人能接得下我三拳两脚呢！"NOR);
	}
	return 1;
}

protected void add_to_threat(object attacker, int damage)
{
	mapping threat;
	string aid;
	object ob = this_object();
	if (!mapp(threat = ob->query("threat")))
		threat = ([ ]);
	aid = attacker->query("id");
	if (undefinedp(threat[aid]))
	{
		threat[aid] = ([
			"object" : attacker,
			"damage" : damage,
			]);
	}
	else
	{
		threat[aid]["object"] = attacker;
		threat[aid]["damage"] += damage;
	}
	ob->add("total_damage", damage);
	ob->set("threat", threat);
	if (damage>5000 && !random(4))
	{
		message_vision(HIY"$N「哎呦」了一声，恨恨道：「" + attacker->query("name")+HIY"你个臭贼，大爷记住你了！」\n"NOR, ob);
		ob->set_temp("focus_target", attacker);
	}
}

varargs int receive_damage(string type, int damage, mixed who)
{
    object ob = this_object();
	int ret=0;
    ret=::receive_damage(type, damage, who);
	if(ob->query_busy()>10)
		ob->start_busy(10);
	if (type == "qi" && ret>0 && objectp(who) && userp(who))
	{
		add_to_threat(who, ret);			
	}
	return ret;
}

varargs void start_busy(mixed new_busy, mixed new_interrupt)
{
	object npc = this_object();
	if (npc->query("next_busy")>time())
	{
		message_vision(HIM"$N嘿嘿一笑：雕虫小技！\n"NOR, npc);
		return;
	}
	if (intp(new_busy) && new_busy>10)
	{
		new_busy = 10;
	}
	npc->set("next_busy", time()+30);
	message_vision(HIY"$N被这一击搞得有些狼狈，忍不住皱了皱眉头！\n"NOR, npc);
	::start_busy(new_busy, new_interrupt);
}

void unconcious()
{
	//拒绝一招晕
	if(query("qi") > 0 && query("jing") > 0 && query("eff_qi") > 0 && query("eff_jing") > 0)
		return;
	die();
}

void die()
{
	mapping threat;
	int i, exp, pot, rep, allexp, alldmg;
	string msg, time, *ids;
	object me, room, ob = this_object();
	threat = ob->query("threat");
	allexp = ob->query("total_exp"); 
	alldmg = ob->query("total_damage");
	if (alldmg < 10000)
	{
		CHANNEL_D->do_channel(ob, "rw", HIW + "这……这不公平！"NOR);
		return ::die();
	}
	if (alldmg < (ob->query("max_qi") * 95 / 100))
	{
		allexp = to_int((to_float(allexp)/ob->query("max_qi"))*alldmg);
	}
	ids = keys(threat);
	room = environment(ob);
	time = chinese_number(ob->query("combat_time"));
	for (i=0;i<sizeof(ids);i++)
	{
		me = threat[ids[i]]["object"];
		if (!objectp(me) || environment(me) != room) 
			continue;
		me = threat[ids[i]]["object"];
		exp = to_int((to_float(threat[ids[i]]["damage"])/alldmg)*allexp);
		pot = exp/10 + random(exp/10);
		rep = exp/2 + random(exp/10);
		msg = "你被奖励了：\n";
		exp = REWARD_D->add_exp(me, exp);
		msg += "\t"+chinese_number(exp)+"点经验；\n";
		pot = REWARD_D->add_pot(me, pot);
		msg += "\t"+chinese_number(pot)+"点潜能；\n";
		rep = REWARD_D->add_rep(me, rep);
		msg += "\t"+chinese_number(rep)+"点声望。\n\n";
		me->add("exp/lvliu_jtt", exp);
		me->add("jobs/completed/lvliu_jtt_asi", 1);
		tell_object( me, HIW + msg + NOR);	
		CHANNEL_D->do_channel(ob, "rumor", sprintf("听说%s击败绿柳山庄「阿四」，用时%s秒，获得了经验%s点、潜能%s点、声望%s点。", 
			me->query("name"), time, chinese_number(exp), chinese_number(pot), chinese_number(rep)));
		me->set("lvliu/jtt/next_asi", time()+ 60*60); // 任务CD 60分钟？
		COMBAT_D->add("task_stat/lvliu_asi/reputy",rep);
		COMBAT_D->add("task_stat/lvliu_asi/potential",pot);
		COMBAT_D->add("task_stat/lvliu_asi/exp",exp);
		COMBAT_D->add("task_stat/lvliu_asi/expratio", to_float(exp)/me->query("combat_exp"));
	}
	CHANNEL_D->do_channel(ob, "rw", HIW + "不！这不可能！我怎么可能被打败！"NOR);
	destruct(ob);
}


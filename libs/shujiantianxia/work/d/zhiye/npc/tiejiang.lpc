// tiejiang  铁匠
// by augx@sj  9/7/2001

#include <ansi.h>
#include <job_mul.h>
inherit NPC;
inherit F_VENDOR;

string ask_job();
string ask_fail();

void create()
{
	set_name("铁匠",({ "tiejiang","jiang" }) );
	set("gender", "男性" );
	set("age", 46);
	set("long","这是位孔武有力的打铁匠人，在这里从事矿石买卖多年了。\n");

	set("str", 55);
	set("dex", 55);
	set("con", 25);
	set("int", 25);
	set("shen_type", 1);
	set("move_seller", 1);
	set("shen", 100);
	set("attitude", "peaceful");
	set("combat_exp", 1000000);

	set_skill("dodge", 300);
	set_skill("force", 300);
	set_skill("parry", 300);
	set_skill("unarmed", 300);
	set_skill("literate", 150);

	set("max_qi", 99999);
	set("max_neili", 99999);
	set("max_jing", 99999);
	set("max_jingli", 99999);
	set("eff_jingli", 99999);

	set_temp("apply/dodge",888);
	set_temp("apply/force",888);
	set_temp("apply/attack",888);
	set_temp("apply/damage",333);
	set_temp("apply/armor",888);

	set("chat_chance", 1);
 	set("chat_msg", ({
 		CYN"铁匠高兴的说道：「最近做矿石买卖可赚钱啦。」\n"NOR,
 		CYN"铁匠说道：「有人要学采矿术吗？我收的学费最公道。」\n"NOR,
 		CYN"铁匠说道：「有人愿意帮我寻找一些特殊的矿石吗？报酬优厚噢！」\n"NOR,
 	}) );

	set("inquiry", ([
		"工作"		: (: ask_job :),
		"job"		: (: ask_job :),
		"寻找矿石"	: (: ask_job :),
		"放弃"		: (: ask_fail :),
		"abandon"	: (: ask_fail :),
	]));

	set("vendor_goods", ({
		(["name":"/d/zhiye/obj/kuangshi1","number":150]),
		(["name":"/d/zhiye/obj/kuangshi2","number":150]),
		(["name":"/d/zhiye/obj/kuangshi3","number":150]),
		(["name":"/d/zhiye/obj/kuangshi4","number":150]),
		//(["name":"/d/zhiye/obj/kuangshi1-2","number":150]),
		//(["name":"/d/zhiye/obj/kuangshi2-2","number":150]),
		//(["name":"/d/zhiye/obj/kuangshi3-2","number":150]),
		//(["name":"/d/zhiye/obj/kuangshi4-2","number":150]),
	}));

	setup();
	carry_object(ARMOR_D("cloth"))->wear();
	carry_object(__DIR__"../obj/tiechui")->wield();
	add_money("coin",99);
}

void kill_ob(object ob)
{
	object me = this_object();
	command("!!!");
	command("say 我是一个老实的铁匠，为什么要杀我呢？");
	me->remove_enemy(ob);
	ob->remove_killer(me);
	return;
}

int accept_fight(object ob)
{
	command("say 我是一个老实的铁匠，为什么要杀我呢？");
	return 0;
}

void init()
{
	::init();
	add_action("do_buy", "buy");
	add_action("do_list", "list");
	//add_action("do_sell", "sell");
}

int prevent_learn(object ob, string skill)
{
	if (skill == "caikuang")
		return 0;
	return 1;
}

int is_apprentice_of(object ob)
{	
	return 0;///cancel datie
}

int recognize_apprentice(object ob)
{
	int money = 125, level = ob->query_skill("caikuang", 1);

	if (level > 9) money = 250;
	if (level > 19) money = 500;
	if (level > 29) money = 1000;
	if (level > 49) money = 2000;
	if (level > 50) return 0;//实习结束了 

	switch (MONEY_D->player_pay(ob, money)) {
		case 0:
		case 2: tell_object(ob,"你现在的学费是每次"+MONEY_D->money_str(money)+"。你的钱不够！\n" ); return 0;
	}
	return 1;
}

////////////////////////////////////////////////////////////////////
int query_goods_value(string goods, int number)
{
	object me = this_player();
	int value, trade_level;
	int cur;

	value = ((object)goods)->query("value");
	trade_level = me->query_skill("trade", 1) / 10;
	if (trade_level > 15) trade_level = 15;
	value = value * (115 - trade_level) / 100;

	cur = query_temp("vendor_goods/"+goods);
	if( cur != number )
		value += value/6 * cur/number;

	return value;
}

int query_goods_value2(object goods)
{
	object me = this_player();
	int value, trade_level;

	value = goods->query("value");
	trade_level = me->query_skill("trade", 1) / 10;
	if (trade_level > 15) trade_level = 15;
	value = value * (85 + trade_level) / 100;

	return value;
}

/*
int do_sell(string arg)
{
	object ob;
	object me = this_player();
	int value, improve;

	if (!living(this_object()))
		return notify_fail("还是等对方醒来再说吧。\n");

	if (me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着呢。\n");

	if (!arg || !(ob = present(arg, me)))
		return notify_fail("你要卖什么？\n");

	if (query_temp("busy"))
		return notify_fail("哟，抱歉啊，我这儿正忙着呢……您请稍候。\n");

	if ( !(int)ob->query("kuangshi") && !(int)ob->query("kuangcai") )
		return notify_fail("我只收购矿石，和用矿石打出来的成品。\n");

	value = query_goods_value2(ob);
	message_vision("$N以"+MONEY_D->price_str(value)+"的价格卖掉了一"+ob->query("unit")+ob->name() + "给$n。\n", me, this_object());
	destruct(ob);
	MONEY_D->pay_player(me, value);
	improve = 40 - me->query("pur");
	me->improve_skill("trade", improve / 2 + random(improve));
	set_temp("busy", 1);
	call_out("delete_temp", 1, "busy");

	return 1;
}
*/

/////////////////////////// worker job ////////////////////////////
int check(object ob)
{
	object room;
	string room_name;

	if( !objectp(ob)
	 || !ob->query("startroom")      // add by Yuj@SJ to void job NPC
	 || ob->query("env/invisibility")
	 || ob->query("no_quest")
	 || userp(ob)
	 || ob->query("attitude")=="aggressive"
	 || !objectp(room=environment(ob))
	 || strsrch(room_name = file_name(room),"/d/") != 0
	 || strsrch(room_name, "/d/wizard/") == 0
	 || strsrch(room_name, "/d/wuguan/") == 0
	 || strsrch(room_name, "/d/death/") == 0
	 || strsrch(room_name, "/d/mingjiao/lsd/") == 0
	 || strsrch(room_name, "/d/mingjiao/bhd/") == 0
	 || strsrch(room_name, "/d/shaolin/fumoquan") == 0
	 || strsrch(room_name, "/d/baituo/") == 0
	 || strsrch(room_name, "/d/thd/") == 0
	 || strsrch(room_name, "/d/sld/") == 0)
		return 0;
	return 1;
}

#include <get_place.h>

string ask_job()
{
	object me = this_player() ,room ,oroom ,lastroom ,target, *living;
	int lvl = (int)me->query_skill("caikuang",1) , i,j,k,a,b;
	string * exits;

	if( lvl<10 )
		return "你的采矿技能太差了，我可不放心让你去办事。";
	if( (int)me->query_skill("datie",1)>=395 )
		return "您的打铁技能那么高了，我可不敢再差遣您了。";
	if( !wizardp(me) && me->query("worker/job1") && time()<(int)me->query("worker/job1_time") )
		return "我不是叫你到"+me->query("worker/job1_oroom")+"附近去寻找矿石了吗！";
	if( !wizardp(me) && time()<(int)me->query("worker/job1_time") )
		return "你太忙了吧，要注意休息啊。";

	living = livings();
	for (i=0;i<sizeof(living);i++){
		j = random(sizeof(living));
		if (j <= 1 || j == sizeof(living)-1) continue;
		if( check(living[j]) ){
			target = living[j];
			room = environment(target);
			if( !mapp(room->query("exits")) || sizeof(room->query("exits"))<1 ) continue;

			if( get_place(base_name(room))!="" ) {
				oroom = room;
				lastroom = room;
				j = 1+random(9);
				for(k=0;k<j;k++) {
					exits = values(room->query("exits"));
					b = sizeof(exits);
					while( (a=random(b))>=0 && b>1 ) {
						if (b==2)
							if ((exits[0]==base_name(lastroom) && exits[1]==base_name(oroom))
							 || (exits[1]==base_name(lastroom) && exits[0]==base_name(oroom)))
								break;
						if (exits[a]==base_name(lastroom) || exits[a]==base_name(oroom)) continue;
						break;
					}
					lastroom = room;
					if( !(room = find_object(exits[a])) )
						if( !(room = load_object(exits[a])) )
							break;
				}
				if(k<j) continue;
				break;
			}
		}
	}

	if( !target || !room )
		return "我最近没听说新发现了什么好的矿石，你过一会儿再来吧。";

	me->set("worker/job1",1);
	me->set("worker/job1_oroom",get_place(base_name(oroom))+oroom->query("short"));
	me->set("worker/job1_far",j);
	me->set("worker/job1_room",base_name(room));
	me->set("worker/job1_time",time()+20*60);
	if(wizardp(me) && me->query("env/test"))
		tell_object(me,base_name(oroom)+" -> "+base_name(room)+"\n");

	command("look "+me->query("id"));
	command("whisper "+me->query("id")+" 听说在"+me->query("worker/job1_oroom")+"周围方圆"
		+CHINESE_D->chinese_number(me->query("worker/job1_far"))+"里内发现了新奇的矿石，你去给我找来。" );
	return "我不会亏待你的。";
}

string ask_fail()
{
	object me = this_player();

	if( !me->query("worker/job1") || time()>=(int)me->query("worker/job1_time") )
		return "你要放弃什么？";

	me->delete("worker/job1");
	me->delete("worker/job1_oroom");
	me->delete("worker/job1_far");
	me->delete("worker/job1_room");
	me->set("worker/job1_time",time()+(2+random(3))*60);

	command("disapp " + me->query("id"));
	return "这么简单的事情都不能做，你真是没用！";
}

void destroying(object obj)
{
	if (!obj) return;
	if (userp(obj))
		command("drop "+obj->parse_command_id_list()[0]);
	else
		destruct(obj);
}

int accept_object(object me, object ob, object who)
{
	int improve,lvl,exp;

	if( !ob->query("job_kuangshi") ){
		command("? "+me->query("id"));
		command("say 你给我这个干什么？");
		return 0;
	}

	if( ob->query("findby") != me->query("id") ) {
		command("hmm "+me->query("id"));
		command("say 这块矿石是你发现的吗？我最不喜欢不诚实的人了！");
		me->add("combat_exp",-500-random(1000));
		if(me->query("combat_exp")<0) me->set("combat_exp",0);
		call_out("destroying", 1, ob);
		return 1;
	}

	command("applaud " + me->query("id"));
	command("say 好啊，我又收集到一块新奇的矿石，说不定哪天就能造出一把神兵利器！");
	call_out("destroying", 1, ob);

	me->delete("worker/job1");
	me->delete("worker/job1_oroom");
	me->delete("worker/job1_far");
	me->delete("worker/job1_room");
	me->set("worker/job1_time",time()+ 20 + random(30));

	lvl = (int)me->query_skill("caikuang",1) / 2;
	improve = (300 + lvl) * 6/5;
	improve = improve*2/3 + random(improve*2/3);
	//improve = improve*ZY_CAIKUANG_JOB_MUL/100;
	exp = improve/20;
	improve = WORKER_D->check_impove(me,"caikuang",improve,2);
	if(improve>0) tell_object(me, HIC"铁匠仔细传授你采矿的诀窍，你的采矿技术提升了"+CHINESE_D->chinese_number(improve)+"点技能点数，和"+CHINESE_D->chinese_number(exp)+"点经验！\n"NOR);
	else tell_object(me, HIC"你获得"+CHINESE_D->chinese_number(exp)+"点经验！\n"NOR);
	/*
	if(me->query_skill("caikuang",1)<220){
		me->improve_skill("caikuang", improve);
		tell_object(me, HIC"铁匠仔细传授你采矿的诀窍，你的采矿技术提升了"+CHINESE_D->chinese_number(improve)+"点技能点数，和"+CHINESE_D->chinese_number(exp)+"点经验！\n"NOR);
	}
	else {
		improve = 0;
		tell_object(me, HIC"你获得"+CHINESE_D->chinese_number(exp)+"点经验！\n"NOR);
	}	
	*/
	exp = me->add_exp_combat( exp ,this_object(),"采矿任务",1);
	//me->add("combat_exp", exp);
	log_file("job/wkuangshi", sprintf("%s(%s)：技能点数：%d，经验：%d；现exp：%d\n", me->name(), me->query("id"),improve,exp,me->query("combat_exp")), me);
	return 1;
}

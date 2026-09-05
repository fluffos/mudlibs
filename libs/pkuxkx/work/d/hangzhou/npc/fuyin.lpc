inherit NPC;
int ask_paper();
#include "/d/hangzhou/npc/job_info.h"
#include <title.h>
#include "ct_title.h"
#define TEST_PROCESS 0//1在test中，只有testers里的id才能使用test内容。0则正式开放。
string *testers=({"zine","mrding","jsstar","nov","attackluo","ctmmb","shaoqing","zmxncbv","kickfire","bgdxn","dodosheep"});
string give_reward(object,string);
string guard_door();
string ask_job();
string do_task();
string ask_leadership();
string ask_strategy();
void do_check(object ob);
string ask_feizei();
string ask_jianzhan();
string do_give();
string do_fail();
string ask_book();
void transfer_skill(object me);
int ask_compensate();
void create()
{
	set("title","临安府尹");
	set_name("袁韶", ({ "yuan shao", "yuan","shao" }));
	set("age", 48);
	set("gender", "男性");
	set("long", "他是临安府尹，长得非常威严。\n");
	set("attitude", "peaceful");
//	set("vendetta_mark", "authority");
//      set("pursuer", 1);
	set("inquiry", ([
	
     
	 "批文": (: ask_paper :),
     "piwen": (: ask_paper :),
     "飞贼" : (: ask_feizei :),
	"巡逻" : (: ask_job :),
	"完成" : (: do_task :),
	"五经" : (: ask_leadership :),
	"守门" : (: guard_door :),
	"监斩" : (: ask_jianzhan:),
	"奖励": (:do_give:),
	"失败": (:do_fail:),
	"补偿": (:ask_compensate:),
	"武经总要" :(:ask_book:) ,
	]));
	set("str", 30);
	set("dex", 30);
	set("combat_exp", 25000);
	set("shen_type", 1);

	set_skill("unarmed", 70);
	set_skill("dodge", 70);
	set_skill("parry", 70);
	set_skill("blade", 80);
	set_skill("force", 150);
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 40);
	set_temp("apply/damage", 50);
	set_temp("apply/armor", 40);
	set("uni_target",1);
	set("book_count",10);
	setup();
	carry_object(__DIR__"obj/guanfu")->wear();
}
void unconcious()
{
	die();
}

void die()
{
	message_vision("$N喝道：“大胆狂徒，还不退下。”\n",this_object());
	this_object()->fullme();
	return;
}
string ask_book()
{
	object me=this_player();
	if (me->is_busy())
	return "你正忙着呢。\n";
	if (me->query_temp("wjzy_obtain/step")!=3)
	return this_object()->name()+"对你不理不睬。\n";
	if (time()-query("wjzy_ask_time")<=3600)
	{
		command("say 这年头想借阅武经总要的人还真多，哼！");
		tell_object(me,"看来"+query("name")+"并不同意你的请求，这一趟算是白跑了。\n");
		me->delete_temp("wjzy_obtain");
		return "";
	}
	command("say 好吧，这个我可以同意，你回去就这样答复曾公吧。");
	me->set_temp("wjzy_obtain/step",4);
	return "";
}
int ask_paper()
{
    object me=this_player();
    object ob=this_object();
    object piwen;
    string* taskname=({"囚衣","囚粮","药品"});
    int n;
    if (me->query_temp("songtasks/xingbu/task")!=1)
    {
        command("say 没有刑部的照会，我不能给你批文。\n");
        return 1;
    }
    if (me->is_busy() || me->is_fighting())
    {
		return notify_fail("你正忙着哪！\n");
    }
    if (me->query_temp("songtasks/xingbu/task1no"))
    {
        tell_object(me,"你不是拿过批文了吗？\n");
        return 1;
    }
    else
    {
        n=random(sizeof(taskname));
        me->set_temp("songtasks/xingbu/task1no",n+1);
        piwen=new("/d/song/obj/piwen");
        piwen->set("owner",me->query("id"));
        piwen->move(me);
        
        message_vision("$N看着$n，道：“刑部尚书的手令，你去把"+taskname[n]+"送到城东外的刑部大牢吧。”\n",ob,me);
        tell_object(me,ob->name()+"给你一张批文。\n");
        tell_object(me,"药品在太医局领(ling)取，囚衣在刑部库房领取，囚粮暂时不足，需要去城北常平仓领取。\n");
        
        return 1;
    }
}
void init()
{
	object ob=this_player();
	if (!environment())
	return;
	if (TEST_PROCESS&&member_array(ob->query("id"),testers)==-1)
	return;
	transfer_skill(ob);
	if (TEST_PROCESS&&ob->query("class")=="officer")
	{
		add_action("do_setpin","set_pin");
		add_action("do_setscore","set_score");
	}
}
int do_setscore(string arg)
{
	int pin;
	object me=this_player();
	if (!arg||sscanf(arg, "%d", pin)!=1)
	return notify_fail("你要设置为多少贡献度？\n");
	if (pin<0||pin>200000)
	return notify_fail("贡献度不能为负。\n");
	me->set("score",pin);
	tell_object(me,"你的贡献度设定为"+pin+"。\n");
	return 1;
}
int do_setpin(string arg)
{
	int pin;
	object me=this_player();
	if (!arg||sscanf(arg, "%d", pin)!=1)
	return notify_fail("你要设置为几品？\n");
	if (pin<1||pin>9)
	return notify_fail("品级只能为1-9品之间。\n");
	me->set("pin",pin);
	tell_object(me,"你的官品设定为"+pin+"品。\n");
	return 1;
}
string guard_door()
{
	int i, pin;
	string gate;
	object ob = this_player();
	if (TEST_PROCESS&&member_array(ob->query("id"),testers)==-1)
	return "现在朝廷-大宋转换正在测试中，你可以找巫师报名参加。\n";
	if ( ob->query("class") != "officer" )
		return "你不是我大宋勋贵，先回去吧";
	if ( ob->query_temp("chaoting/newjob/guard/job"))
		return "我不是告诉你了吗？去" + ob->query_temp("chaoting/newjob/guard/job") + "守门吧。";

	pin = ob->query("pin");
	if (pin == 9)
		return RANK_D->query_respect(ob) + "勋职太低，至少要升迁至宣节、御武校尉方可领取此任务。";
	if (pin < 6)
		return RANK_D->query_respect(ob) + "位高权重，已经不用干这种活了。";
	if (ob->query("score") >= 1000)
		return RANK_D->query_respect(ob) + "已经可以升迁了，不必干这种活了。";
	if (ob->query("score") >= 400 && pin > 7)
		return RANK_D->query_respect(ob) + "需要升迁之后再继续作守门任务。";
	if (ob->query("score") >= 600 && pin > 6)
		return RANK_D->query_respect(ob) + "需要升迁之后再继续作守门任务。";
	if (ob->query("score") >= 800 && pin > 5)
		return RANK_D->query_respect(ob) + "需要升迁之后再继续作守门任务。";
	if (!wizardp(ob)&&NATURE_D->outdoor_room_event()!= "event_sunrise" && NATURE_D->outdoor_room_event()!= "event_evening" )
		return "守门只有早晚两班，你到时间再来吧。";

	i = random(sizeof(gate_name));
	gate = gate_name[i];

	if (member_array(NATURE_D->outdoor_room_event(),({"event_sunrise" ,"event_morning","event_noon","event_afternoon"}))==-1)
		ob->set_temp("chaoting/newjob/guard/night", 1);
	else
		ob->set_temp("chaoting/newjob/guard/day", 1);
	if (wizardp(ob)&&ob->query("test_gate"))
	gate="东青门";
	ob->set_temp("chaoting/newjob/guard/job", gate);
	tell_object(ob,"你的任务是去"+gate+"守门。\n");
	return "你快去" + gate + "守门 (guarding) 吧。";

}
string *place_list(int number)
{
	object ob;
	if (!ob=load_object("/d/hangzhou/obj/lingpai"))
	ob=new("/d/hangzhou/obj/lingpai");
	return ob->place_list(number);
}
string do_task()
{
	object ob,me;
	string *places;
	ob = this_player();
	me = this_object();

	if(!ob->query_temp("chaoting/newjob/xuncheng"))
		return ("你没巡逻跑来领什么功？");
	if (interactive(ob)
		&& time()-ob->query_temp("chaoting/newjob/xuncheng_start")<60+random(20))
	return (RED"你这么快回来了，是不是有些地方只是马马虎虎看看？"NOR);
	places=place_list(ob->query_temp("chaoting/newjob/xuncheng"));
	if (!ob->query_temp("chaoting/newjob/xuncheng_already")||!arrayp(ob->query_temp("chaoting/newjob/xuncheng_already")))
	return("你是不是偷懒，漏了些地方没巡？ \n");
	for (int i=0;i<sizeof(places);i++)
	{
		if (member_array(places[i],ob->query_temp("chaoting/newjob/xuncheng_already"))==-1)
		return("你是不是偷懒，漏了些地方没巡？ \n");
	}
	command("nod " + ob->query("id"));

	give_reward(ob,"xuncheng");
	return "哈哈，不错不错，" + RANK_D->query_respect(ob) + "做得好！";
}
string ask_job()
{
	object me;
	object ob,ling,*all_ob;
	int i;
	string *place = ({ "临安府东城", "临安府西城", "临安府南城","临安府北城"});
	ob = this_player();
	me = this_object();
	if (TEST_PROCESS&&member_array(ob->query("id"),testers)==-1)
	return "现在朝廷-大宋转换正在测试中，你可以找巫师报名参加。\n";
	if (ob->query("class") != "officer")
		return RANK_D->query_respect(ob) + "不是我大宋勋贵，此话从何说起？";
	if (ob->query_temp("chaoting/newjob/xuncheng"))
		return ("你不是已经领了巡城的任务吗？还不快去做。");
	if (ob->query("combat_exp") < 3000)
		return ("你武功太低，无法胜任。");
	if (ob->query("pin") < 8)
		return ("我看你的武功已有相当的功底了，就不用干这种事了。");
	if (ob->query("score") >= 400)
		return RANK_D->query_respect(ob) + "已经可以升迁了，不必干这种活了。";

	i = random(4);
	ob->set_temp("chaoting/newjob/xuncheng", i + 1);
	ob->set_temp("chaoting/newjob/xuncheng_start",time());
	all_ob=all_inventory(ob);
	for (int j=0;j<sizeof(all_ob);j++)
	{
		if (all_ob[j]->query("is_xc_ling"))
		destruct(all_ob[j]);
	}
	ling=new("/d/hangzhou/obj/lingpai");
	ling->move(ob);
	message_vision("$N给$n一块"+ling->query("name")+"。\n",me,ob);
	return "好吧，你带着这块令牌，去" + place[i] + "巡逻一下吧，巡逻时应当小心防范，防止外敌。";
}
int add_score(object ob)
{
	ob->add("score", 1);
	tell_object(ob,"你对"+HBGRN+HIR+"大宋朝廷"+NOR+"的贡献度提高了。\n");
	return 1;
}
int RECORD_TEST(object ob,int exp,int pot,string type)
{
	if (TEST_PROCESS)
	{
		if (type=="feizei")
		return 1;
		if (type=="xuncheng"&&ob->query("statistics/Q2S/test_xc_times")<=200)
		{
			ob->add("statistics/Q2S/test_xc_times",1);
			ob->add("statistics/Q2S/test_gain/exp",exp);
			ob->add("statistics/Q2S/test_gain/pot",pot);
		}
		if (type=="jianzhan"&&ob->query("statistics/Q2S/test_jz_times")<=100)
		{
			ob->add("statistics/Q2S/test_jz_times",1);
			ob->add("statistics/Q2S/test_gain/exp",exp);
			ob->add("statistics/Q2S/test_gain/pot",pot);
		}
		if (type=="shoumen"&&ob->query("statistics/Q2S/test_sm_times")<=100)
		{
			ob->add("statistics/Q2S/test_sm_times",1);
			ob->add("statistics/Q2S/test_gain/exp",exp);
			ob->add("statistics/Q2S/test_gain/pot",pot);
		}
		return 1;
	}
}
string give_reward(object ob,string type)
{
	int exp,sil,kar,pot,sc;

	if (type=="feizei")
	{
		if(ob->query("chaoting/newjob/feizei/catchfeizei") && ob->query("class") == "officer")
		{
			if(ob->query("score") < 1400)
			add_score(ob);
			ob->delete("chaoting/newjob/feizei/catchfeizei");
			ob->add("chaoting/feizei", 1);
		}
		kar = ob->query("kar") * (10 + random(40));
		exp = 2 * kar;
		pot = exp / 8;

		if (ob->query("combat_exp") < 1000000)
		{
			exp = exp / 3;
			pot = exp /8;
		}

		ob->add("combat_exp", exp);
		ob->add("exp/chaoting", exp);
		ob->add("potential", pot);
		ob->add("pot/chaoting", pot);
		ob->add("repute", 100);
		ob->add("shen", 1000);

		tell_object(ob,"你的经验增加了" + chinese_number(exp) + "点。\n");
		tell_object(ob,"你的潜能增加了" + chinese_number(pot) + "点。\n");
		tell_object(ob,"你的武林声望增加了。\n");
		tell_object(ob,"你的道德提高了。\n");
	}

	if (type=="xuncheng")
	{
		command("pat " + ob->query("id"));
		sil = (int)(ob->query_skill("force",1)/2) + random(5);
		pot = 5 + random(20);
		exp = 30 + random(70);
		this_object()->add_money("silver",sil);
		command("give "+ob->query("id")+" "+sil+" silver");
		ob->add("potential", pot);
		ob->add("pot/chaoting", pot);
		ob->add("combat_exp",exp);
		ob->add("exp/chaoting",exp);
		add_score(ob);
		ob->add("chaoting/xuncheng", 1);
		tell_object(ob,HIW"你被奖励了：\n" +
			chinese_number(exp) + "点实战经验\n" +
			chinese_number(pot) + "点潜能\n"+
			chinese_number(sil)+"两白银\n"+
			"你已为大宋朝廷做了"+ chinese_number(ob->query("chaoting/xuncheng")) + "次巡逻任务。\n"NOR);
		ob->delete_temp("chaoting/newjob/xuncheng");
		ob->delete_temp("chaoting/newjob/xuncheng_already");
		ob->delete_temp("xc");
	}
	if (type=="jianzhan")
	{
		add_score(ob);
		if (ob->query("combat_exp") < 1000000)
		exp = (random(70) + 30) * ob->query("chaoting/newjob/jianzhan/dart_value");
		else
		exp = ( random(80) + 40) * ob->query("chaoting/newjob/jianzhan/dart_value");
		pot = exp / 2;
		ob->add("combat_exp",exp);
		ob->add("exp/chaoting",exp);
		ob->add("potential",pot);
		ob->add("pot/chaoting",pot);;
		ob->add("chaoting/jianzhan", 1);
		ob->delete("chaoting/newjob/jianzhan");
		message("vision",HIW"你被奖励了"+chinese_number(exp)+"点经验，"+
		chinese_number(pot)+"点潜能！\n"+
		"你已为大宋朝廷做了"+ chinese_number(ob->query("chaoting/jianzhan")) + "次监斩任务。\n"NOR,ob);
		ob->delete("jianzhan_failnum");
	}
	RECORD_TEST(ob,exp,pot,type);
	return "哈哈，真难为你了，" + RANK_D->query_respect(ob) + "做得好！";
}
int accept_object(object me,object ob)
{
	//取消抓飞贼任务
	if(me->query("chaoting/newjob/feizei/catchfeizei"))
	{
		if(ob->query("money_id") && ob->value() >= 10000)
		{
			message_vision("$N叹道：罢了罢了，这么点小事都办不成！\n", this_object());
			me->delete("chaoting/newjob/feizei/catchfeizei");
			me->delete_temp("feizei");
			me->delete_temp("guanf_huida1");
			me->add("chaoting/job_fail", 1);
			me->set("last_feizei_time",time());
			tell_object(me, "到目前为止你总共任务失败" + ob->query("chaoting/job_fail") + "次。\n");
			return 1;
		}
		if(ob->query("money_id") && ob->value() < 10000)
		{
			message_vision("$N看了你一眼道：这也太少了吧！\n", this_object());
			return 0;
		}
	}
	//抓飞贼
	if(ob->query("id") == "cai bao")
	{
		if(ob->query("owner") == me)
		{
			give_reward(me,"feizei");
			if (ob)
			{
				ob->move(VOID_OB);
				destruct(ob);
			}
			return 1;
		}
		else
		{
			command( "?" );
			command( "say 这个东西是你找到的么？" );
			return 0;
		}
	}

	command( "hmm" );
	command( "say 你给我这东西做什麽？" );

	return 0;
}

string ask_jianzhan()
{
	int i;
	object ob, cart, bing,*bings=({});
	ob=this_player();
	if (TEST_PROCESS&&member_array(ob->query("id"),testers)==-1)
	return "现在朝廷-大宋转换正在测试中，你可以找巫师报名参加。\n";
	if (ob->query("class") != "officer")
		return RANK_D->query_respect(this_player()) + "不是我大宋勋贵，不知此话从何谈起？";

	if(stringp(ob->query("chaoting/newjob/badman")))
		return "你先把抓坏人的任务完成了再说吧。";

	if( ob->query("chaoting/newjob/catchfeizei"))
	{
		command("slap " + ob->query("id"));
		return "先把抓飞贼任务完成了再说吧。";
	}

	if ( ob->query("chaoting/newjob/jianzhan/in_dart"))
		return "你上一个任务还没结算呢？";

	if ( ob->query("pin") < 3)
		return "大人已经不用再作这种任务了。";

	if ( ob->query("score") >= 1400)
		return "你已经可以升迁了，没有必要再作这个任务。";

	if (ob->query("score") >= 800 && ob->query("pin") > 5)
		return RANK_D->query_respect(ob) + "需要升迁之后再继续作监斩任务。";

	if ( ob->is_busy() || ob->query_temp("pending/exercising"))
		return "你现在正忙着呢。";

	if ( (int)ob->query("combat_exp") < 100000 )
		return "护送囚车是件危险工作，我看"+RANK_D->query_respect(ob)+"似乎没有这能力！";


	if(time() - ob->query("chaoting/newjob/jianzhan/last_jianzhan_time") < 120)
		return "你上次监斩太辛苦了，下去休息休息吧。";

	ob->set("chaoting/newjob/jianzhan/in_dart",1);

	if (ob->query("pin") > 7)
		ob->set("chaoting/newjob/jianzhan/dart_value", 4);
	else if (ob->query("pin") > 5)
		ob->set("chaoting/newjob/jianzhan/dart_value", 6);
	else
		ob->set("chaoting/newjob/jianzhan/dart_value", 8);

	cart=new(__DIR__"obj/cart");
	cart->set("master", ob->query("name"));
	cart->set("masterid", ob->query("id"));
	cart->set("owner", ob);
	cart->move(environment(this_object()));
	command("nod");
	message_vision(CYN "几个官兵推出一辆囚车。" NOR,ob);
	ob->set("chaoting/newjob/jianzhan/can_go",1);
	ob->set("chaoting/newjob/jianzhan/last_jianzhan_time",time());
	if (arrayp(ob->query("chaoting/newjob/jianzhan/bings")))
	for (i=0;i<sizeof(ob->query("chaoting/newjob/jianzhan/bings"));i++)
	{
		if (objectp(ob->query("chaoting/newjob/jianzhan/bings")[i]))
		destruct(ob->query("chaoting/newjob/jianzhan/bings")[i]);
	}
	for (i = 1; i < 5; i++)
	{
		bing = new(__DIR__"jz_bing");
		bing->set_shiwei_status(30 + random(60));
		bing->move(environment(this_object()));
		bing->set_leader(ob);
		bings+=({bing});
	}
	ob->set("chaoting/newjob/jianzhan/bings",bings);
	return ob->query("name")+"把这辆囚车护送到东城门外的" + HIC"刑部大牢"NOR + "吧。";

}

string ask_feizei()
{
	object me, ob, feizei,where;
	mapping target, position;
	int exp;
	string name;

	me = this_player();
	if (TEST_PROCESS&&member_array(me->query("id"),testers)==-1)
	return "现在朝廷-大宋转换正在测试中，你可以找巫师报名参加。\n";
	exp = me->query("combat_exp");

	if (me->query("class") != "officer")
		return RANK_D->query_respect(this_player()) + "不是我大宋勋贵，不知此话从何谈起？";

	if(stringp(me->query("chaoting/newjob/badman")))
		return "你先把抓坏人的任务完成了再说吧。";

	if ( me->query("chaoting/newjob/jianzhan/in_dart"))
		return "你先把监斩任务完成了再说吧。";

	if( me->query("chaoting/newjob/feizei/catchfeizei"))
	{
		command("slap " + me->query("id"));
		return "先把上一个任务完成了再说，实在做不了就给钱取消吧。";
	}

	if(time() - me->query("chaoting/newjob/feizei/last_feizei_time") < 180)
	return "目前治安良好，没有发现飞贼。";

        feizei = new("/d/beijing/npc/feizei1");
	//只有要的人杀这个飞贼才有用
	feizei->set("catcher",me->query("id"));
        feizei->set("can_arrest",random(2));

	if (!feizei)
		return "BUG: 请通知巫师。";

	if (exp < 100000)
	{
		feizei->Set_Npcattrib(20, 10,
					500, 1000,
					1000, 1000,
					1000, 1000,
					1000, 1000,
					50000, 50000 );
		if (random(2) == 0)
		feizei->skills_setup_none(10, 90, "random_menpai");
		else
		feizei->skills_setup_weapon(10, 90, "random_menpai");
	}
	else if (exp < 500000)
	{
		feizei->Set_Npcattrib(20, 10,
					1000, 1000,
					1000, 1000,
					1000, 1000,
					1000, 1000,
					100000, 200000 );
		if (random(2) == 0)
		feizei->skills_setup_none(50, 100, "random_menpai");
		else
		feizei->skills_setup_weapon(50, 100, "random_menpai");
	}
	else if (exp < 1000000)
	{
		feizei->Set_Npcattrib(20, 10,
					1000, 2000,
					1000, 1000,
					1000, 1000,
					1000, 1000,
					200000, 500000 );
		if (random(2) == 0)
		feizei->skills_setup_none(80, 120, "random_menpai");
		else
		feizei->skills_setup_weapon(80, 120, "random_menpai");
	}
	else
	{
		feizei->Set_Npcattrib(20, 10,
					1500, 2500,
					1000, 1000,
					1000, 1000,
					1000, 1000,
					300000, 2000000 );
		if (random(2) == 0)
		feizei->skills_setup_none(100, 150, "random_menpai");
		else
		feizei->skills_setup_weapon(100, 150, "random_menpai");
	}
	//position = feizei->query_quest(); //用taskd统一分配任务，用各自的任务列表修改起来太麻烦了。
	while (!objectp(where) || 
               !where->isroom()||
               TASK_D->place_belong(where)=="不明区域"||
               base_name(where) == "/adm/daemons/taskd")
	{
		where = TASK_D->random_place();
	}
	if (feizei->move(where))
	{
		if (!living(feizei))
		{
			return "你迟些再来吧。\n";
			me->add_busy(5);
		}
		me->delete_temp("feizei");
		me->set("chaoting/newjob/feizei/catchfeizei", 1);
		me->set_temp("feizei/gkill1", 1);
		this_object()->set("last_feizei_time",time());
		return "飞贼" + feizei->short() + "在「" +TASK_D->place_belong(where)+"的"+where->query("short") + "」出现，请速去将他捉拿归案！";
	}
	else return "BUG: 请通知巫师。";
}
string do_give()
{
	int bonus;
	object ob;
//	int max_pot;

	ob=this_player();
//	max_pot=(int)this_player()->query("max_pot");

	if (ob->query("class") != "officer")
		return RANK_D->query_respect(this_player()) + "不是我大宋勋贵，不知此话从何谈起？";

	if ( !ob->query("chaoting/newjob/jianzhan/in_dart"))
		return "我没让你监斩啊？";

	if ( !ob->query("chaoting/newjob/jianzhan/over_dart") )
		return "囚车没有送到目的地，莫非你假公济私？！";

	give_reward(ob,"jianzhan");
	command("pat "+ob->query("id"));
	return RANK_D->query_respect(ob)+"果然是栋梁之才！";
}


string do_fail()
{
	int creward,preward,rreward,times;
	object ppl=this_player();
	if (ppl->query("class") != "officer")
		return RANK_D->query_respect(this_player()) + "不是我大宋勋贵，不知此话从何谈起？";
	if (ppl->query_temp("chaoting/newjob/xuncheng"))
	{
		ppl->delete_temp("chaoting/newjob/xuncheng");
		return "巡逻都做不好。";
	}
	if(!ppl->query("chaoting/newjob/jianzhan/in_dart"))
		return "你没有领过什么任务吧？";
	else
	{
		command("heng "+ppl->query("id",1));
		ppl->add("jianzhan_failnum",1);
		if (ppl->query("combat_exp") < 1000000)
		{
			creward = (random(40) + 20) * ppl->query("chaoting/newjob/jianzhan/dart_value");
			creward = creward * ppl->query("jianzhan_failnum")* ppl->query("jianzhan_failnum");
			preward = creward / 2;
			ppl->add("combat_exp", - creward);
			ppl->add("exp/chaoting", - creward);
			ppl->add("pot/chaoting", - preward);
			ppl->add("chaoting/job_fail", 1);

			message("vision",HIW"你被扣除了"+chinese_number(creward)+"点经验，"+
				chinese_number(preward)+"点潜能！\n"NOR,ppl);
		}
		else
		{
			creward = ( random(50) + 20) * ppl->query("chaoting/newjob/jianzhan/dart_value");
			creward = creward * ppl->query("jianzhan_failnum")* ppl->query("jianzhan_failnum");
			preward = creward / 2;
			ppl->add("combat_exp", - creward);
			ppl->add("exp/chaoting", - creward);
			ppl->add("pot/chaoting", - preward);
			ppl->add("chaoting/job_fail", 1);

			message("vision",HIW"你被扣除了"+chinese_number(creward)+"点经验，"+
				chinese_number(preward)+"点潜能！\n"NOR,ppl);
		}
		ppl->delete("chaoting/newjob/jianzhan");
	}
	if(ppl->query("combat_exp")<2000)
		ppl->set("combat_exp", 2000);
	return "这点小事你都办不好，还能指望你作些什么呢？";
}
void transfer_skill(object me)
{
	string title;
	mapping skl = me->query_skills();
	mapping skill_list=(["juemen-gun":"panlong-gun","kuihua-zhua":"taizu-changquan",
		"bainiao-qiangfa":"lihua-qiang","lujia-ji":"gehu-ji","kuangfeng-jian":"huqian-jianfa",
		"kuangfeng-dao":"pojun-daofa","huzhua-shou":"yuejia-sanshou","duanyun-bian":"menghu-bian"]);
	string *old_skills=({"juemen-gun","qingmang-jian","fenglei-dao","kuangfeng-dao","kuangfeng-jian","lujia-ji","bainiao-qiangfa","huzhua-shou",
		"juehu-zhang","kuihua-zhua","duanyun-bian","leiting-axe","taizu-quan"}),*sname=({}),*sname2=keys(skill_list);
	if (mapp(skl))
	sname=keys(skl);
	if (stringp(me->get_title(TITLE_QUEST1))&&strsrch(me->get_title(TITLE_QUEST1),"大清铁帽子王")>=0 )
	me->set_title(TITLE_QUEST1);
	if (stringp(me->get_title(TITLE_QUEST2))&&strsrch(me->get_title(TITLE_QUEST2),"大清铁帽子王")>=0 )
	me->set_title(TITLE_QUEST2);
	if (stringp(me->get_title(TITLE_QUEST3))&&strsrch(me->get_title(TITLE_QUEST3),"大清铁帽子王")>=0 )
	me->set_title(TITLE_QUEST3);
	if (sizeof(sname)>=1)
	for(int i=0; i<sizeof(sname); i++)
	for (int j=0;j<sizeof(skill_list) ;j++)
	{
		if (!intp(skl[sname[i]]))
		continue;
		if (skl[sname[i]]>0 &&member_array(sname[i],sname2)!=-1)
		me->set_skill(skill_list[sname[i]],skl[sname[i]]);
	}
	for (int k=0;k<sizeof(old_skills);k++)
	me->delete_skill(old_skills[k]);
	me->set("BACKUP_Chaoting",me->query("chaoting"));
	if (me->query("family/family_name")=="朝廷")
	{
		title=give_title(me);
		if (title!=""&&!me->query("chaoting/transfer_SONG"))
		{
			me->set("chaoting/transfer_SONG",1);
			me->set_title(TITLE_RANK,title);
			tell_object(me,"朝廷大宋技能或头衔转换完成。\n");
		}
		if (!me->query("chaoting/mandatory_check2"))
		{
			me->set("chaoting/mandatory_check2",1);
			me->set("multi_title", ({"rank"}));
		}
		if (!me->query("chaoting/mandatory_check3"))
		{
			me->set("chaoting/mandatory_check3",1);
			if (me->query_skill("huqian-jianfa"))
			me->map_skill("sword", "huqian-jianfa");
			if (me->query_skill("pozhen-daofa"))
			me->map_skill("blade", "pozhen-daofa");
			if (me->query_skill("yuejia-sanshou"))
			me->map_skill("hand", "yuejia-sanshou");
			if (me->query_skill("gehu-ji"))
			me->map_skill("halberd", "gehu-ji");
			if (me->query_skill("taizu-changquan"))
			me->map_skill("cuff", "taizu-changquan");
			if (me->query_skill("panlong-gun"))
			{
				me->map_skill("staff", "panlong-gun");
				me->map_skill("dodge", "panlong-gun");
				me->map_skill("parry", "panlong-gun");
			}
			me->reset_action();
		}
		if (title!=""&&!me->query("chaoting/transfer_SONG2"))
		{
			me->set("chaoting/transfer_SONG2",1);
			me->set_title(TITLE_RANK,title);
			//tell_object(me,"朝廷大宋技能或头衔转换完成。\n");
		}
	}
}

string ask_leadership()
{
	object ob;
	if (this_player()->query("class") != "officer")
		return RANK_D->query_respect(this_player()) +
		"没必要读这本书";
	if (query("book_count") < 1)
	{		
		if(!random(10)) 
			set("book_count",10);
		return "我收藏的「诗经」已经被人借走了。";
	}
	add("book_count", -1);

	ob = new("/d/hangzhou/obj/books/book_leadership_1");

	ob->move(this_player());

	return "五经是做官的基础，这本「诗经」你拿回去读读吧。";
}

int ask_compensate()
{
	int claw,cuff=0,tzq;
	object me=this_player();
	if (!claw=me->query_skill("claw",1)||!tzq=me->query_skill("taizu-changquan",1))
	{
		command("say 你没有爪法，或者没有太祖长拳，不符合补偿条件。");
		return 1;
	}
	if (me->query_skill("cuff",1))
	cuff=me->query_skill("cuff",1);
	if (cuff>claw)
	{
		command("say 你的cuff高于claw级别，无法补偿。");
		return 1;
	}
	if (!me->query_temp("chaoting/claw2hand"))
	{
		command("say 如继续补偿，你将失去"+claw+"级基本爪法，获得"+claw+"级基本拳法，如需继续，请再次ask yuan about 补偿。");
		me->set_temp("chaoting/claw2hand",1);
		return 1;
	}
	me->set_skill("cuff",claw);
	me->delete_skill("claw");
	command("say 你失去了"+claw+"级基本爪法，获得"+claw+"级基本拳法。");
	return 1;
}
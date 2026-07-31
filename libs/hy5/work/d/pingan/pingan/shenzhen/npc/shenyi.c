// sz,npc:shenyi
// 97.10.1 by Aug

inherit NPC;
inherit F_MASTER;

#include <ansi.h>

int give_zhen();
int heal_other();

int last_time=-100000;

void create()
{
	set_name("叶济世", ({ "ye yishi","ye" }) );
	set("title", "神针世家第七代传人");
	set("nickname","悬壶济世"); 
	set("gender", "男性");
	set("age", 61);

	set("long","叶济世是个形相清瘦，风姿隽爽，萧疏轩举，堪然若神的老人。\n");
	set("rank_info/respect", "神医");

	set("max_jing", 2000);
	set("max_qi", 1000);

	set("eff_neili", 3000);
	set("neili", 3000);

	set("str", 15);
	set("cor", 35);
	set("cps", 35);
	set("spi", 35);
	set("int", 100);
	set("con", 40);
	set("kar", 50);
	set("per", 35);

	set("combat_exp", 1000000);
	set("score",100000);

	set_skill("force", 200);
	set_skill("parry", 200);
	set_skill("dodge", 200);
	set_skill("throwing",200);
	set_skill("literate", 200);
	set_skill("unarmed", 200);

	set_skill("miaoshouhuichun",200);
	
	map_skill("throwing",  "miaoshouhuichun");

	set("inquiry", ([
		"银针" : (: give_zhen :),
		"疗伤" : (: heal_other :),
		"heal" : (: heal_other :),
		"针灸" : (: heal_other :),
		"zhenjiu" : (: heal_other :),
	]) );	

	
	

	setup();

	add_money("gold", 1);	
	carry_object(__DIR__"obj/changshan")->wear();
	carry_object(__DIR__"obj/yinzhen")->wield();
}

void init()
{       
	object ob;

	::init();
	if( interactive(ob = this_player()) ) 
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}

	add_action("do_xue","xue");
	add_action("do_xue","learn");
}

void greeting(object ob)
{
	if( living(this_object()) ==0 ) return;

	if( !ob || environment(ob) != environment() ) return;
	if( ob->query("shen")<-10000 )   
	{
		message_vision(
"叶神医说道:我神针世家世代以助人为乐为传家之道，恕我不能接待象$N这样名声不好之人。
叶神医把$N推到了门外。\n",ob);
		
		ob->move("/d/pingan/west2");
 	}  
	else 
	{ 
		command("say 请坐，请坐，贵客光临寒舍是不是要医治什么疾病啊？"); 
	}
}

int accept_fight(object ob)
{
	return notify_fail(CYN"叶神医说道：我老了，没精力和你玩了。\n"NOR);  
}

int give_zhen()
{
	object ob;

	ob=this_player();

// 一个pl每小时只能拿到一枚银针
	if (ob->query("last_getzhen")
		&& (ob->query("mud_age")-ob->query("last_getzhen"))<(1*60*60) )
	{
		command("say "+ob->query("name")+"，你不是刚来拿过银针吗？怎么又来了？");
		return 1;
	}

	if( ob->query("shen")<0 )
	{
		command("say 我叶家的银针是绝对不能落在恶人手里的！");
		command("say 你是怎么混进来的？给我滚！");
		ob->move("/d/pingan/west2");
		return 1;
	}

// 1 银针/ 3 min
	if( (time() - last_time) < (3*60) )
	{
		command("say 对不起，我的银针都给光了，你过一会儿再来看看吧。");
		return 1;
	}
	
	if ( ob->over_encumbranced() )   
	{
		write("你已经负荷过重了！\n");
		return 1;
	}

	if ( present( "yinzhen" , ob) ) 
	{
		command("say 你身上不是还有嘛！怎么又问我要了！\n");
		return 1;
	}

	last_time=time();	
	ob->set("last_getzhen",ob->query("mud_age"));

	new(__DIR__"obj/yinzhen")->move(ob);

	message_vision("叶神医给了$N一根银针，说道：你可要好好利用这枚救命的针啊。\n",ob);

	return 1;
}

int heal_other()
{
	object me,ob,ob2;

	ob=this_player();
	me=this_object();

	if(ob->query("shen")<0)
	{
		command("say 想要我给恶人疗伤，没门！\n");
		command("say 你是怎么混进来的？给我滚！");
		ob->move("/d/pingan/west2");
		return 1;
	}

	if(ob->query("eff_qi")==ob->query("max_qi"))
	{
		command("say 你没伤啊，消遣我呢？\n");
		return 1;
	}

	if(me->query("neili")<50 || me->query("jing")<30)
	{
		command("say 今天我累了，你明天早点来吧。\n");
		return 1;
	}

	if(!present( "yinzhen" , me))
	{
		ob2=new(__DIR__"obj/yinzhen");
		ob2->move(me);
		command("wield zhen");		
	}
	
	command("say 好，就给你疗疗伤吧。");
	command("zhenjiu "+ob->query("id"));

	return 1;
}

int accept_object(object who, object ob)
{
	int i;

	if (!(int)who->query_temp("learn_time"))      
		who->set_temp("learn_time", 0);

/*
	if( who->query("shen") < 0 ) 
	{
		command("say 恶人别想从我这里学到绝学！");
		command("say 你是怎么混进来的？给我滚！");
		who->move("/d/pingan/west2");
		return 1;		
	}

	if( !ob->query("money_id") )
	{
		command("say 这，这，老夫就不客气了。");
		return 1;		
	}
*/

	if( who->query("shen") < 0 ) 
		return 0;		

	if( !ob->query("money_id") )
		return 0;		


	if(who->query_skill("miaoshouhuichun",1)<30)
		i=ob->value() / 50;
	else
	{
		if(who->query_skill("miaoshouhuichun",1)<60)
			i=ob->value() / 100;
		else
		{
			if(who->query_skill("miaoshouhuichun",1)<100)
				i=ob->value() / 200;
			else
				i=ob->value() / 500;
		}
	}
	who->add_temp("learn_time",i);

      message_vision("叶神医对$N说道：既然你诚心想学医，我就成全成全你吧。\n",who);
	tell_object(who,"现在你可以向叶神医学习(xue|learn)了。\n");

	return 1;
}

int do_xue(string arg)
{
	object me,ob;
	string skill,teacher;
	int jing_cost,my_skill;

	me=this_player();
	ob=this_object();

	if( living(me) ==0 ) return 0;

	if (me->is_busy())
	{
		tell_object(me,"你现在正忙着呢。\n");
		return 1;
	}

	if(!arg || (sscanf(arg, "%s %s", teacher, skill)!=2 ))
	{
		tell_object(me,"指令格式：learn|xue <某人> <技能>\n");
		return 1;
	}

	if( ob != present(teacher, environment(me)) )
	{
		tell_object(me,"你要向谁请教？\n");
		return 1;
	}

	if( !living(ob) )
	{
		tell_object(me,"嗯....你得先把" + ob->name() + "弄醒再说。\n");
		return 1;
	}

	if( me->is_fighting() )
	{
		tell_object(me,"临阵磨枪？来不及啦。\n");
		return 1;
	}

//	if( skill!="miaoshouhuichun" )
//	{
//		tell_object(me,CYN"叶神医说道：这门功夫你恐怕要向别人去学了。\n"NOR);
//		return 1;
//	}

	message_vision("$N向$n请教有关「妙手回春」的疑问。\n",me,ob);

	if( me->query_temp("learn_time") <= 0)
	{
		command("say 妙手回春可不是那么容易学的，你可要有恒心啊！");
		return 1;
	}

	my_skill=me->query_skill("miaoshouhuichun",1);

	if(  my_skill>=200 )
	{
		command("say 你已经完全领悟了妙手回春的真谛，我也没什么可以再教给你了。");
		return 1;
	}

	if( (int)me->query("learned_points") >= (int)me->query("potential") )
	{
		tell_object(me,"你的潜能已经发挥到极限了，没有办法再成长了。\n");
		return 1;
	}

	jing_cost = 300 / (int)me->query("int");

	if(jing_cost > (int)me->query("jing") )
	{
		tell_object(me,"你太累了，结果什么也没学到。\n");
		me->set("jing",0);
		return 1;
	}

	me->add_temp("learn_time",-1);
	me->add("learned_points", 1);
	me->add("jing", -jing_cost);
	
	if( my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp") ) 
	{
		tell_object(me,"也许是缺乏实战经验，你对"+ob->name()+"的回答总是无法领会。\n");
		return 1;
	}

	if( !my_skill ) 
	{
		me->set_skill(skill,0);
	}

	message_vision("$N听了$n的指导，似乎有些心得。\n",me,ob);

	me->improve_skill(skill, random(me->query_int()));

	return 1;
}
	


	

      
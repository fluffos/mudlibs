// ping.c 平一指

inherit NPC;
inherit F_DEALER;
int give_zhen();
int heal_other();

int last_time=-100000;
int ask_wu();
int heal_other();

int last_time=-100000;

string ask_me();
void create()
{
	set_name("平一指", ({ "ping yizhi", "ping", "yizhi" }));
	set("title", "药铺老板");
	set("gender", "男性");
	set("long", "他就是医术高超的「杀人神医」平一指。可是他性格古怪，不是什么人都医的。\n");
	set("age", 65);

	set("int", 30);
	
	set("qi", 5000);
	set("max_qi", 5000);
	set("neili", 5000);
	set("max_neili", 5000);

	set("jing", 5000);
	set("max_jing", 5000);
	set("shen_type", 1);

	set("combat_exp", 500000);
	set("attitude", "heroism");
          set("chat_chance", 1);
             set("chat_msg", ({
(: command("say 这段时间总感觉自己老了，干活力不从心。看来要找人帮我磨药才行！\n") :),
(: command("say 请来的小伙子干活还挺卖力的，真是长江后浪推前浪,不认老都不行了！\n") :),
                 }) );

	set_skill("unarmed", 80);
	set_skill("dodge", 80);
	set_skill("parry", 60);
		set_skill("force", 400);
	set_skill("parry", 400);
	set_skill("dodge", 400);
	set_skill("throwing",400);
	set_skill("literate", 400);
	set_skill("unarmed", 400);
	set_skill("miaoshouhuichun",380);


	
	map_skill("throwing",  "miaoshouhuichun");
	set_temp("apply/attack", 70);
	set_temp("apply/defense", 70);
	set_temp("apply/damage", 50);
        set("inquiry", ([
                "何首乌" : (: ask_wu :),
                "job" : (: ask_me :),
             	"工作" : (: ask_me :),
		"银针" : (: give_zhen :),
		"疗伤" : (: heal_other :),
		"heal" : (: heal_other :),
		"针灸" : (: heal_other :),
		"zhenjiu" : (: heal_other :),
        ]));

	set("vendor_goods", ({
	}));

	setup();
	add_money("gold", 1);
	carry_object("/clone/misc/cloth")->wear();
	carry_object(__DIR__"yinzhen")->wield();
}

void init()
{
//	add_action("do_buy", "buy");
}
int ask_wu()
{
	object ob;
	ob = this_player ( ) ;
	if ( query_temp("he") < 1)
               {
                      message_vision("平一指对着$N说：何首乌早已卖给别人了。\n", ob);
                      return 1;
               }
message_vision("平一指上上下下打量了$N一下：什么！何首乌？拿三十两黄金来！\n",ob);
	ob->set_temp ("何首乌" , 1 );
	return 1;
}



string ask_me()
{
	object ob;
          ob=this_player();
         if (ob->query("combat_exp",1)<80000 && ob->query("nbjob")!=27)
                return "我的工作你现在还做不了吧！";
          if (ob->query("combat_exp",1)>180000 && ob->query("nbjob")!=27)
                return "以你的本事已经不用在我这工作了！";


       if (ob->query("job_moyao") >0)
		return "我交给你的事情你还没做呢！";
       ob->set("job_moyao",1);
        return "好吧，你就帮我磨药(moyao)吧！";
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

	new(__DIR__"yinzhen")->move(ob);

	message_vision("平一指给了$N一根银针，说道：你可要好好利用这枚救命的针啊。\n",ob);

	return 1;
}

int heal_other()
{
	object me,ob,ob2;

	ob=this_player();
	me=this_object();


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
		ob2=new(__DIR__"yinzhen");
		ob2->move(me);
		command("wield zhen");		
	}
	
	command("say 好，就给你疗疗伤吧。");
	command("zhenjiu "+ob->query("id"));
  if (ob->query_condition("snake_poison"))
        {          ob->clear_condition("snake_poison");}
        if (ob->query_condition("wugong_poison"))
        {          ob->clear_condition("wugong_poison");}
        if (ob->query_condition("zhizhu_poison"))
        {          ob->clear_condition("zhizhu_poison");}
        if (ob->query_condition("xiezi_poison"))
        {          ob->clear_condition("xiezi_poison");}
        if (ob->query_condition("chanchu_poison"))
        {          ob->clear_condition("chanchu_poison");}
        if (ob->query_condition("qishang_poison"))
        {          ob->clear_condition("qishang_poison");}
        if (ob->query_condition("jy-poison"))
        {          ob->clear_condition("jy-poison");}
        if (ob->query_condition("xx_poison"))
        {          ob->clear_condition("xx_poison");}
        if (ob->query_condition("cold_poison"))
        {          ob->clear_condition("cold_poison");}
        if (ob->query_condition("flower_poison"))
        {          ob->clear_condition("flower_poison");}
        if (ob->query_condition("yufeng_poison"))
        {          ob->clear_condition("yufeng_poison");}
        ob->start_busy(3);
	return 1;
}

int accept_object(object who, object ob)
{
	int i;
	object obj ;
	if (!(int)who->query_temp("何首乌"))
	{
        message_vision("平一指对$N说：医一人，杀一人，老夫不收钱！\n", who);
		return 0 ;
	}
	if (ob->query("money_id") && ob->value() >= 300000)
	{
		message_vision("平一指给了$N何首乌！\n" , who);
		this_player()->delete_temp("何首乌" );
		obj=new(__DIR__"obj/shouwu");
		obj->move(this_player());
	}

	if (!(int)who->query_temp("learn_time"))      
		who->set_temp("learn_time", 0);


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

      message_vision("平一指对$N说道：既然你诚心想学医，我就成全成全你吧。\n",who);
	tell_object(who,"现在你可以向平一指学习(xue|learn)了。\n");

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
	


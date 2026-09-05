// d/city/npc/lver.c
// By Eric 96.9.26

inherit NPC;

//void greeting();
void init();
//int accept_object();
//void serve_tea();
void delete_served();
string ask_yuebing();
int ask();

void create()
{
	set_name("绿萼", ({"lver"}) );
	set("gender", "女性" );
	set("age", 12+random(6));
	set("long",
	  "看什么看，有得吃就吃啦。\n");
	set("attitude", "friendly");
       set("shen_type", 1);
       set("shen",10000);

        set("str", 40);
        set("int", 48);
        set("con", 44);
        set("dex", 40);

        set("max_qi", 150);
        set("max_jing", 100);
        set("neili", 150);
    set("start_room","/d/city/shangyuetai");
        set("max_neili", 150);

        set("combat_exp", 10000+random(800));
        set("score", 10000);

        set_skill("force", 30);
        set_skill("dodge", 20);
        set_skill("unarmed", 15+random(10));
        set_skill("parry", 20);
        set_temp("apply/attack", 10);
        set_temp("apply/defense", 15);
        set_temp("apply/damage", 3);
	set("inquiry",([
	        "但愿人长久" : "千里共婵娟\n",
            "武功":(:ask:),
		"月饼":(:ask_yuebing:),
		]));

        

        setup();
        
	//	carry_object("/d/city/obj/changjian")->wield();
		carry_object("/d/city/obj/cloth")->wear();
}

void init()
{	
	object ob;

	::init();

	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
        add_action("do_answer","answer");      

}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
        if( !this_object()->visible(ob)) return;
	say("绿萼笑吟吟地说道：这位" + RANK_D->query_respect(ob)
//                           +"度每师傅给大家准备了中秋月饼,欢迎大家品尝。\n")
             + "请先入座，" + "我这就给您上茶。\n");
}

int accept_object(object who, object ob)
{
	object obn;
	
	if( !who || environment(who) != environment() ) return 0;
	if ( !objectp(ob) ) return 0; 
        if ( !present(ob, who) ) return notify_fail("你没有这件东西。\n");

	if (  (string)ob->query("name") == "茶叶"
		|| (string)ob->query("name") == "金项链"  ) 
	{
		if ( (string)ob->query("name") == "金项链" ) 
		{
			command("kiss " + (string)who->query("id")); 
			command("wear lace");
//			carry_object("/d/city/obj/necklace")->wear();
		}
		
		if ( who->query_temp("marks/sit") )
		{
			if ((int)who->query_temp("tea_cup") > 0)	
	   		{
				command("smile " + who->query("id"));
            } else 
			{
	    		say("绿萼作了个揖道：" + RANK_D->query_respect(who)
	       		+ "请稍候，我这就给您换香茶。\n");
			}

			who->set_temp("tea_cup", 5);
			remove_call_out("serve_tea");
			call_out("serve_tea", 1, who);

		} else 
		{
			who->set_temp("tea_cup", 5);
	    	say("绿萼作了揖：" + RANK_D->query_respect(who)
	       	+ "请先入上座，我这就给您去泡香茶。\n");
		}

		return 1;
	}

	if ((string)ob->query("name") == "「女儿香」茶叶") 
	{
		if ( who->query_temp("marks/sit") )
		{
			command("dance " + who->query("id"));
		} else 
		{
			message_vision("绿萼引$N到栏杆边风景最好的桌边坐下．\n", who);
		}
		
		who->set_temp("tea_cup", 10);
		who->set_temp("marks/sit", 1);
	 	obn = new(__DIR__"../obj/nuerxiang");
		obn->move(who);

		return 1;
	}


	command("? " + who->query("id"));
//	command("smile cui");
	return 1;
}


void serve_tea(object who)
{
	object obt, obc, obn;
	object room;

	if( !who || environment(who) != environment() ) return;

	if( !who->query_temp("marks/sit") ) return;
	
	if( !objectp(room = environment()) ) return;

         if( objectp(present("shangyueshipin", environment(who)) ))
         {
         tell_object(who,"你还是先把这里的东西吃完再说吧。\n");
         return;
         }
	if ( (int)who->query_temp("tea_cup") <= 0 )
	{
	 	obn = new("d/wudang/obj/dawancha");
		obn->move(room);
		message_vision("绿萼搬出个大茶壶来，将桌上的大碗茶倒满．\n",
			who);
	} else 
	{
		who->add_temp("tea_cup", -1);
	 	obn = new("d/wudang/obj/xiangcha");
		obn->move(room);
		message_vision("绿萼拿出个绍兴小茶壶，沏了杯香茶，放在桌上．\n",
			who);
	}

 	obn = new("/clone/food/15food");
	obn->move(room);
	message_vision("绿萼拿出"+obn->name()+"，放在桌上．\n", who);
	
	return;
}

string ask_yuebing()
{
object me=this_player();
        if (me->query("zhongqiu/gift_yuebing"))
                return "你已经吃过月饼了，为人不要贪得无厌！";
        if (me->query("zhongqiu/ask"))
                return "你刚才不是问过了吗，你烦不烦呀？";
me->set("zhongqiu/ask",1);
return "我们有甜月饼和咸月饼两种，请问你要吃哪种?(answer)";

}

int do_answer(string arg)          //回答要什么月饼
{
     object p;
     object me= this_player();
	if (!me->query("zhongqiu/ask")) return 0;
	
      if (!arg)  return notify_fail("你到底要吃什么？\n");
      if (me->query("zhongqiu/give")==1) 
{
  command("say 刚才已经给你月饼了，作人太贪了不是好事！\n");
return 1;
}
       if(arg=="甜月饼"){
   		   p = new("/clone/gift/yuebing1");
   		  p->move(me);
                 tell_object(me, "绿萼给了你一块甜月饼。\n");
		me->set("zhongqiu/give",1);
     		 return 1;
        }
         if(arg=="咸月饼"){
   		   p = new("/clone/gift/yuebing2");
   		  p->move(me);
                 tell_object(me,"绿萼给了你一块咸月饼。\n");
     	me->set("zhongqiu/give",1);
	     return 1;
        }
 		else {
        command("say 你说的什么乱七八糟的，算了，不想吃就算了！\n");
          return 1;
        }
        
}
int ask()
{
       object obj;
int tempskill,exp;
string id;
       object ob=this_player();
id = ob->query("id");
       exp = ob->query("combat_exp");
       tempskill = to_int(pow(exp*10,0.333333)+1);
         command("whisper " + id + " 阁下现在的武功上限可以达到：" + chinese_number(tempskill) + "级。\n");
       return 1;
}

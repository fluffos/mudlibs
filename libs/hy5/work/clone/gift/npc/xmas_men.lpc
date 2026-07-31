

#include <ansi.h>

inherit NPC;

string ask_for_yao();
string ask_for_present();

void create()
{
    set_name("礼物老人", ({ "liwu man", "man" }) );
	set("title", HIY"礼物"+HIW" 使者"NOR);
	set("gender", "男性" );

	set("age", 400);
	set("str", 100);
	set("con", 100);
	set("dex", 100);
	set("int", 100);
         
	set("long",
		"咦？这个礼物老人怎么和圣诞老人张得一模一样，呵呵...\n"
                "他正在那里发红包，看来你可以向他要。(ask men about 红包)\n" );

	set("combat_exp", 8000000);
	set("attitude", "friendly");
	
	set("inquiry", ([
		"申请"   : (: ask_for_yao :),		
		"礼物"   : (: ask_for_present :),
	]) );

	set_temp("no_kill", 1);
	set("qi", 5000);
	set("max_qi", 5000);
	set("jing", 5000);
	set("max_jing", 5000);
	set("neili", 5000);
	set("max_neili", 5000);
        set("jiali",300);

	set_skill("dodge", 500);
	set_skill("unarmed", 500);
	set_skill("parry", 500);
	set_skill("force",500);
        set_skill("literate",500);
        set_skill("cuff", 500);

        set_skill("qiankundanuoyi",500);
        set_skill("jingang-quan",500);
        set_skill("hunyuan-yiqi",500);
     
        map_skill("force", "hunyuan-yiqi");
	map_skill("parry", "qiankundanuoyi");
	map_skill("cuff", "jingang-quan");
        map_skill("dodge", "qiankundanuoyi");
        
        prepare_skill("cuff", "jingang-quan");
        set_temp("apply/attack", 500);
        set_temp("apply/defense", 200);


        set("chat_msg_combat", ({
		(: perform_action, "cuff.jingang" :),
		(: exert_function, "recover" :),
                (: exert_function, "powerup" :),
                
	}) );


	setup();
        carry_object(__DIR__"yuyi")->wear();
	
	
}

void init()
{
	object ob;

	::init();

	if( interactive(ob=this_player()) && !is_fighting())
	{
		remove_call_out("greeting");
		call_out("greeting",1,ob);
	}
}


void greeting(object ob)
{
	if(!ob || environment(ob)!=environment()) return;

      command("say 你是来拿礼物的吧？\n");
//      元旦,清明节,劳动节,青年节,儿童节,建党日,建军节,国庆节
//      情人节,愚人节,圣诞节,春节,元宵节,端午节,中秋节,重阳节,
}

string ask_for_present()
{ 
mapping *holiday= ({

	          ([
                      "name":             HIR"元旦"NOR,
                      "year":             "either",
                      "month":            "Jan",
                      "day":              "01",
                  ]),
  
                  ([
                      "name":             HIW"清明节"NOR,
                      "year":             "either",
                      "month":            "Apr",
                      "day":              "05",
                  ]),

                  ([
                      "name":             HIR"劳动节"NOR,
                      "year":             "either",
                      "month":            "May",
                      "day":              "01",
                  ]),

                  ([
                      "name":             HIW"青年节"NOR,
                      "year":             "either",
                      "month":            "May",
                      "day":              "04",
                  ]),

                  ([
                      "name":             HIR"儿童节"NOR,
                      "year":             "either",
                      "month":            "Jun",
                      "day":              "01",
                  ]),

                  ([
                      "name":             HIR"建党日"NOR,
                      "year":             "either",
                      "month":            "Jul",
                      "day":              "01",
                  ]),

                  ([
                      "name":             HIR"建军节"NOR,
                      "year":             "either",
                      "month":            "Aug",
                      "day":              "01",
                  ]),

                  ([
                      "name":             HIR"国庆节"NOR,
                      "year":             "either",
                      "month":            "Oct",
                      "day":              "01",
                  ]),

       		  ([
                      "name":             HIR"情人节"NOR,
                      "year":             "eihter",
                      "month":            "Feb",
                      "day":              "14",                    
                  ]),

                  ([
                      "name":             HIC"愚人节"NOR,
                      "year":             "either",
                      "month":            "Apr",
                      "day":              "01",
                  ]),

                  ([
                      "name":             HIW"圣诞节"NOR,
                      "year":             "either", 
                      "month":            "Dec",
                      "day":              "24",
                  ]),

                  ([
                      "name":             HIR"春"+HIC"节"NOR,
                      "year":             "2002",
                      "month":            "Feb",
                      "day":              "1",
                  ]),

                  ([
                      "name":             HIR"元宵"NOR+"节",
                      "year":             "2008",
                      "month":            "Feb",
                      "day":              "23",
                  ]),
               
                  ([
                      "name":             HIR"端午"NOR+"节",
                      "year":             "2008",
                      "month":            "Jun",
                      "day":              "22",
                  ]),
                      
       		  ([
                      "name":             HIY"中秋"NOR+"节",
                      "year":             "2008",
                      "month":            "Sep",
                      "day":              "14",                    
                  ]),

       		  ([
                      "name":             HIY"重阳"NOR+"节",
                      "year":             "2008",
                      "month":            "Oct",
                      "day":              "25",                    
                  ]),


       


                	
                  });
    object me,ob;
    mapping skl, today;
    string *sname;
    int i,how=0,what_day=100,neili,exp,pot;
    string week, month, year, day, time;
    string check;
    
    sscanf(ctime(time()), "%s %s %s %s %s", week, month, day, time, year);
   if(day=="")
    sscanf(ctime(time()), "%s %s  %s %s %s", week, month, day, time,year);



    for(i=0;i<sizeof(holiday);i++)
      {  today = holiday[i];
//         if(today["year"]!="either")
 if( month==today["month"]&&day==today["day"])
//year==today["year"]&&
               what_day=i;
            else if(month==today["month"]&&day==today["day"])
               what_day=i;
      }
    if(what_day==100)
{
    write("现在是:");
    write(month);
    write(day);
      return "今天好象不是什么节日耶！\n";
}    
    me = this_player();

    if ((int)me->query("combat_exp") <3000 || (int)me->query("mud_age")<18000)
        return "嘿嘿，想用新玩家来骗我，没门！。\n";
      
    if ((int)me->query("combat_exp") >=3000 ) 
         {
		
	    skl = me->query_skills();
      if(skl) sname  = keys(skl);
            for(i=0; i<sizeof(skl); i++)
                   if (skl[sname[i]] >= 10)how=how+1; 
                          if(how<3)
                            return "就你的水平？再去练一会儿！。\n";
	
          } 
     today = holiday[what_day];   

     check=year+today["name"];
     
     if(me->query("goodday_gift")==check)
       return "每个人一份，不要这么贪心好不好！\n";
neili=280+random(888);
exp=68000+random(88888);
pot=18000+random(88888);
me->add("max_neili",neili);
me->add("combat_exp",exp);
me->add("potential",pot);
//     ob = new(__DIR__"red");
//     ob->move(me);
     me->set("goodday_gift",check);
     return today["name"]+"快乐！\n"+"礼物老人把"+me->query("name")+"的"+HIR"能力加强了许多"NOR+"。内力"+neili+",经验"+exp+",潜能"+pot+"\n";
}

string ask_for_yao()
{ 
mapping *holiday= ({

	          ([
                      "name":             HIR"元旦"NOR,
                      "year":             "either",
                      "month":            "Jan",
                      "day":              "01",
                  ]),
  
                  ([
                      "name":             HIW"清明节"NOR,
                      "year":             "either",
                      "month":            "Apr",
                      "day":              "05",
                  ]),

                  ([
                      "name":             HIR"劳动节"NOR,
                      "year":             "either",
                      "month":            "May",
                      "day":              "01",
                  ]),

                  ([
                      "name":             HIW"青年节"NOR,
                      "year":             "either",
                      "month":            "May",
                      "day":              "04",
                  ]),

                  ([
                      "name":             HIR"儿童节"NOR,
                      "year":             "either",
                      "month":            "Jun",
                      "day":              "01",
                  ]),

                  ([
                      "name":             HIR"建党日"NOR,
                      "year":             "either",
                      "month":            "Jul",
                      "day":              "01",
                  ]),

                  ([
                      "name":             HIR"建军节"NOR,
                      "year":             "either",
                      "month":            "Aug",
                      "day":              "01",
                  ]),

                  ([
                      "name":             HIR"国庆节"NOR,
                      "year":             "either",
                      "month":            "Oct",
                      "day":              "01",
                  ]),

       		  ([
                      "name":             HIR"情人节"NOR,
                      "year":             "eihter",
                      "month":            "Feb",
                      "day":              "14",                    
                  ]),

                  ([
                      "name":             HIC"愚人节"NOR,
                      "year":             "either",
                      "month":            "Apr",
                      "day":              "01",
                  ]),

                  ([
                      "name":             HIW"圣诞节"NOR,
                      "year":             "either", 
                      "month":            "Dec",
                      "day":              "24",
                  ]),

                  ([
                      "name":             HIR"春"+HIC"节"NOR,
                      "year":             "2002",
                      "month":            "Feb",
                      "day":              "1",
                  ]),

                  ([
                      "name":             HIR"元宵"NOR+"节",
                      "year":             "2008",
                      "month":            "Feb",
                      "day":              "23",
                  ]),
               
                  ([
                      "name":             HIR"端午"NOR+"节",
                      "year":             "2008",
                      "month":            "Jun",
                      "day":              "22",
                  ]),
                      
       		  ([
                      "name":             HIY"中秋"NOR+"节",
                      "year":             "2008",
                      "month":            "Sep",
                      "day":              "14",                    
                  ]),

       		  ([
                      "name":             HIY"重阳"NOR+"节",
                      "year":             "2008",
                      "month":            "Oct",
                      "day":              "25",                    
                  ]),


       


                	
                  });
    object me,ob;
    mapping skl, today;
    string *sname;
    int i,how=0,what_day=100;
    string week, month, year, day, time;
    string check;
    
    sscanf(ctime(time()), "%s %s %s %s %s", week, month, day, time, year);
   if(day=="")
    sscanf(ctime(time()), "%s %s  %s %s %s", week, month, day, time,year);



    for(i=0;i<sizeof(holiday);i++)
      {  today = holiday[i];
//         if(today["year"]!="either")
 if(month==today["month"]&&day==today["day"])
//year==today["year"]&&
               what_day=i;
            else if(month==today["month"]&&day==today["day"])
               what_day=i;
      }
    me = this_player();
    
    if ((int)me->query("combat_exp") <3000 || (int)me->query("mud_age")<18000)
        return "嘿嘿，想用新玩家来骗我，没门！。\n";

    if ((int)me->query("combat_exp") >=3000 ) 
         {
		
	    skl = me->query_skills();
      if(skl) sname  = keys(skl);
            for(i=0; i<sizeof(skl); i++)
                   if (skl[sname[i]] >= 10)how=how+1; 
                          if(how<3)
                            return "就你的水平？再去练一会儿！。\n";
	
          } 

    if(what_day==100)
    {
     me->set("goodday_gift",0);
     return "申请完闭！\n";
    }
    write("现在是:");
    write(month);
    write(day);
      return "今天不提供申请服务！\n";
}

  

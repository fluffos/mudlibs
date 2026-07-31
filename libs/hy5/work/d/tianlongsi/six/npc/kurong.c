// kurong.c
inherit NPC;
inherit F_MASTER;
#include <ansi.h>;
string ask_liumai1();
string ask_liumai2();
int ask_dudan(object who);
void create()
{
	set_name("枯竹大师", ({ "ku zhu","ku"}) );
	set("gender", "男性" );
	set("title", "天龙寺第十五代僧人");
	set("class", "bonze");
	set("long", 
"他的面容奇特之极，左边的一半脸色红润，皮光肉滑，有如婴儿，
右边的一半却如枯骨，除了一张焦黄的面皮之外全无肌肉，骨头突
了出来，宛然便是半个骷髅骨头。这是他修习枯荣禅功所致。\n");
	set("age", 100);
	set("shen_type", 1);
	set("str", 50);
	set("int", 50);
	set("con", 50);
	set("dex", 50);

	set("qi", 34000);
	set("max_qi", 34000);
	set("jing", 31000);
	set("max_jing", 31000);
	set("neili", 50000);
	set("max_neili", 50000);
	set("jiali", 50);
	set("combat_exp", 5500000);
	set("score", 1000000);
	set("book_count", 1);

	set_skill("force", 300);
	set_skill("dodge", 300);
	set_skill("parry", 300);
	set_skill("finger", 380);
	set_skill("sword", 300);
	set_skill("tiannan-step", 350);
	set_skill("kurong-changong", 390);
	set_skill("duanjia-sword", 390);
	set_skill("six-finger", 390);
	set_skill("yiyang-zhi", 190);
	set_skill("sun-finger", 390);
	set_skill("buddhism", 390);
	set_skill("literate", 300);
	set("book_give", 1);
	map_skill("force", "kurong-changong");
	map_skill("dodge", "tiannan-step");
	map_skill("parry", "six-finger");
	map_skill("finger", "six-finger");
	map_skill("sword", "duanjia-sword");
	prepare_skill("finger","six-finger");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
(: perform_action, "unarmed.liumaijingshen" :),
	(: perform_action, "unarmed.qi" :),
		(: perform_action, "unarmed.zongheng" :),
                  (: exert_function, "powerup" :),
                (: exert_function, "ku" :),
                (: exert_function, "rong" :),
        }) );
        set("inquiry", ([
	"普云洞" : (: ask_liumai2 :),
	"段誉" : (: ask_liumai1 :),
        ]) );

	create_family("大理段家",15,"高僧");
        set_temp("apply/attack", 180);
        set_temp("apply/defense", 180);
        set_temp("apply/armor", 1200);
        set_temp("apply/damage", 1280);
	setup();
	carry_object("/d/shaolin/obj/cheng-cloth")->wear();
}


string ask_liumai1()
{
                object me,ob,obj;
        int i;
        ob=this_player();
        ob=this_player();


		if( ob->query_temp("killtlbb4"))
		   {
		    ob->set_temp("liumai/find1",1);   
if((int)ob->query("jinyong/book4")==2)
{
 	i = 900+random(900);
	ob->set("jinyong/book4",3);
	ob->add("combat_exp",i+12880);
	ob->add("potential",i*15);
	ob->add("mpgx",10);
	ob->add("expmax",2);

	tell_object (ob,"你赢得了"+chinese_number(i+12880)+"点经验"+
	           chinese_number(i*15)+"点潜能"+"十点门派贡献 二点成长上限！！\n");
 }

           return "唉，求佛祖保佑,誉儿前日被大雪山大轮明王鸠摩智给抓到苏州去了，
		   誉儿生性淳厚，定能逢凶化吉。阿弥陀佛! \n";
		      }
       
		if( ob->query("dali/meet_dy1")||ob->query("liumai_update"))
		   {
		    ob->set_temp("liumai/find1",1);   
           return "唉，求佛祖保佑,誉儿前日被大雪山大轮明王鸠摩智给抓走了，
		   誉儿生性淳厚，定能逢凶化吉。阿弥陀佛! \n";
		      } else
		if( ob->query("dali/meet_dy2"))
		   {  
		   return "听说誉儿已经被人搭救回来了，真是万幸啊！阿弥陀佛！ \n";
            } else {
		   return "你问誉儿啊，他是镇南王正淳的公子，听说天资聪明，生性淳厚。 \n";
           		   }
}

string ask_liumai2()  
{
        object me,ob,*thing;
	mapping myfam;
	int i;
	ob=this_player();
	me=this_object();
      
      
        myfam = (mapping)ob->query("family");
 
      if (myfam["family_name"] != "大理段家"||ob->query("class") != "bonze") 
         {
	 return "对不起，我不知道！\n";
        
	}
      if (ob->query("liumai_pass") && (ob->query_skill("six-finger",1)<200))
         {
         
          command ("nod" + ob->query("id"));
          message_vision("枯竹长老一掌向地拍去，身后轰然移开一扇石门，"+ob->query("name")+"看也不看，走了过去。\n",ob);
          thing = deep_inventory(ob);
	  i = sizeof(thing);
	    while (i--)
	       if (thing[i]->is_character()) {
		   message_vision("枯竹长老突然伸手一拦，道；你怎么带外人进洞？。\n", ob);
		   me->set_leader(ob);
                   remove_call_out("kill_ob");
                   call_out("kill_ob", 0, me); 
	           return " ";
		} 
	
	ob->move("/d/tianlongsi/six/pyd");
	return "";
	  }   	
      if( ob->query_skill("yiyang-zhi",1)<160 )
	 {
	 return "你的一阳指修炼的这么差，还不回去好好练功!!\n";
		}
      if (ob->query("max_neili")<2000)
      {
	 return "你的内力修炼的这么差，还不回去好好练功!!\n";
	
       }
       if (ob->query_temp("try_fight"))
           return "你不是正在接我的招吗？!\n";
       
       if (ob->query_temp("try"))
           return "如果你准备好了，请确定(try). \n";
           
       if (me->query_temp("try"))
           return "对不起，现在正有人在准备过招. \n";    
       
       if (me->query_temp("try_fight"))
           return "对不起，现在我正忙着，你有什么要求一会儿再说. \n";  
      	 
      if( ob->query_skill("six-finger",1)>200)
         {  
	 ob->set("liumai_update",1);
        
	 return "你的六脉神剑修为已经登峰造级，老衲这里也不能给你什么帮助了.
	               你去找镇南王世子段誉吧，也许他能给你些帮助。  \n";
	 
	   } else 
	   {
          command("say 依照天龙寺祖上传下规矩，" + RANK_D->query_respect(ob) + "你必须接下我十招不死不昏，才够资格进普云洞修习六脉神剑。");
          ob->set_temp("try",1);
          me->set_temp("try",1);
          call_out("wait", 1, me, 0);
          return "如果你准备好了接招，请确定（try)。\n";
		   }
}
void init()
{
	add_action("do_yes", "try");
}

  int do_yes()
{
        object me,ob,room;
        ob = this_player();
        me = this_object();

	if( !ob->query_temp("try") )
		return 0;
	message_vision("$N单掌一立，沉声说道：“请”。\n",ob );
        set("max_jing",58000);
        set("jing",58000);
        set("eff_jing",58000);
        set("eff_jingli",58000);
        set("max_qi",58000);
        set("qi",58000);
        set("eff_qi",58000);
        set("jiali",100);
        set("neili",56000);
        set("max_neili",56000); 
        command("yun rong");
        if(!( room = find_object("/d/tianlongsi/six/lsy" )) )
                room = load_object("/d/tianlongsi/six/lsy");
        room->delete("exits");
        ob->delete_temp("try");
        me->delete_temp("try");
        me->set_temp("try_fight",1);
        ob->set_temp("try_fight",1);        
        call_out("fighting",  3, me, ob, 0);
        message_vision("枯竹大师双掌合什，躬身一揖，恭恭敬敬的道：“请指教。”\n",ob);
        return 1;
        
        
}

void waiting(object me, int wait_time)
{
	object fighter;

        if( wait_time >= 150 )
	{
		say( "枯竹大师说道：看来你不打算接我十招了！\n\n");
		call_out("do_recover", 0, me);		
		return;
	}
	if( !objectp( fighter = present( me->query_temp("fight"), environment(me) ) ) )
	{
                call_out("waiting", 1, me, wait_time + 1);
		return;
	}
	
}
void fighting(object me, object fighter, int count)
{
	object room;	
	 
	if (!fighter || !living(fighter) || environment(fighter)!=environment(me)
	|| fighter->query("qi") < 1)
	{
		if(!( room = find_object("/d/tianlongsi/six/lsy" )) )
                room = load_object("/d/tianlongsi/six/lsy");
		if( objectp(fighter)) {
			fighter->delete_temp("try_fight");
			fighter->delete_temp("beat_count");
		}
		me->delete_temp("try_fight");
		room->set("exits/out","/d/tianlongsi/six/songlin-1");
                command("chat* 摇了摇头，说道：想不到... 唉！");
		command("sigh");
		return;
		
	} else if (count <10) {
	if (interactive(fighter) && fighter->query_temp("try_fight") && living(fighter))
	 COMBAT_D->do_attack(this_object(), fighter, query_temp("weapon"), 2);
	 count++;
	  call_out("fighting", 2, me, fighter, count);
	} else call_out("do_congra", 3, me, fighter);
	
}
void do_congra(object me, object fighter)
{
	int i;
	object room,*thing;
	 if(!( room = find_object("/d/tianlongsi/six/lsy" )) )
                room = load_object("/d/tianlongsi/six/lsy");
	fighter->delete_temp("try_fight");
	fighter->set("liumai_pass",1);
	me->delete_temp("try_fight");
	command("smile");
        command("say 恭喜，恭喜，你技艺青出于蓝胜于蓝，可以修习本寺神功六脉神剑,你去吧。\n");
	room->set("exits/out","/d/tianlongsi/six/songlin-1");
	message_vision("枯竹长老一掌向地拍去，身后轰然移开一扇石门，"+fighter->query("name")+"看也不看，走了过去。\n",fighter);
        thing = deep_inventory(fighter);
	  i = sizeof(thing);
	    while (i--)
	       if (thing[i]->is_character()) {
		   message_vision("枯竹长老突然伸手一拦，道；你怎么带外人进洞？。\n", fighter);
		   me->set_leader(fighter);
                   remove_call_out("kill_ob");
                   call_out("kill_ob", 0, me); 
	           return;
		} 
	 fighter->move("/d/tianlongsi/six/pyd");
         return;
	
}
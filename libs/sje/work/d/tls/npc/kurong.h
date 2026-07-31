void attempt_apprentice(object ob)
{
  string old_name,new_name;
  mapping myfam;
         
        myfam = (mapping)ob->query("family");
      if (!myfam) return;
      if (myfam["family_name"] != "天龙寺") 
         {
		 command ("say 你不是天龙寺弟子，这话从何说起！\n");
         return;
		 }
 if((int)ob->query_skill("buddhism",1)<140)
       {
         command("say 我段家武功与佛学息息相关，我看"+RANK_D->query_respect(ob)+"的禅宗修为似乎不够？");
          return;
        }
   if((int)ob->query_skill("yiyang-zhi",1)<160)
 {
          command("say 我天龙寺武功首推一阳指，我看"+RANK_D->query_respect(ob)+"似乎应在一阳指上多下点功夫。");
          return;
        }
    if((int)ob->query_skill("qiantian-yiyang",1)<160)
 {
          command("say 修练一阳指内功最为重要，我看"+RANK_D->query_respect(ob)+"似乎应在乾天一阳功上多下点功夫。");
          return;
        }
	if(!(ob->query("tls")) && !(ob->query_temp("tls_app")))
                 {
		 command("say 阿弥陀佛！请回吧，贫僧不轻易收出家弟子。");
                 return;
				 }
  if(ob->query("tls")&&((int)ob->query("shen") > 1000 || (int)ob->query("shen")+1000 <0 )){
          command("say 我天龙寺乃清修之地，依我看"+RANK_D->query_respect(ob)+"似乎红尘未了,不宜继续修行。");
          return;
          }

        command("smile");
        old_name = ob->query("name");
        if (ob->query("tls") && (string)ob->query("class") =="bonze")
		{new_name="本"+old_name[2..3]; } else
		{new_name="本"+old_name[0..1]; }


       if (!ob->query("tls") || (string)ob->query("class")!="bonze")
       {       
        command("say 贫僧只收出家弟子，今日老僧帮你剃度。");
         message_vision("枯荣禅师伸出一只皮包骨头的瘦手在"+ob->query("name")+"的头上一按，顿时头发尽落。\n",ob);
        }
        ob->set("name",new_name);
        ob->set("class","bonze");
        ob->set("tls",1);
        command("chat 入我门来法名"+new_name);
        command("recruit " + ob->query("id") );
        command("chat 哈哈哈哈!");
        command("chat 老衲终于找到一个可传衣钵之人,真是可喜可贺!");
        return;
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
        ob->set("class", "bonze");
}

int ask_dudan(object who)
{ object me,ob_dan;
  mapping myfam;
  me=this_player();
  myfam = (mapping)me->query("family");
 if (!myfam || myfam["family_name"] != "天龙寺") 
  { command("slap "+(string)me->query("id"));
    command("say 你非我派弟子，也敢来滥竽充数!\n");
    return 1;
}
 if (me->query_skill("kurong-changong", 1) < 20)
   {
    command("pat "+(string)me->query("id"));
    command("say 你的枯荣禅功根基不够，这毒丹我是不能给你吃的!\n");
    return 1;
   }
  if((int)me->query("dudan_given") < (int)(me->query_skill("kurong-changong", 1)/10)) 
  {
    command("nod "+(string)me->query("id"));
    me->set("dudan_given",(int)(me->query_skill("kurong-changong", 1)/10));
    ob_dan = new("/d/tls/npc/obj/dudan");
    ob_dan->move(me);
    message_vision("$N获得一颗毒丹。\n",this_player());
    command("say 这是一颗毒丹，可是对于修炼枯荣禅功，极为有益，你这么勤奋练功就赠给你吧!\n");
    return 1;
  }
  else
  {
  command("say 你现在还是好好修炼枯荣禅功，老想靠药物来增涨可是不行! \n");
   return 1;
   }
}
string ask_liumai1()
{
        object ob;
        ob=this_player();
       
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
 
      if (myfam["family_name"] != "天龙寺"||!ob->query("tls")||ob->query("class") != "bonze") 
         {
	 return "对不起，我不知道！\n";
        
	}
      if (ob->query("liumai_pass") && (ob->query_skill("liumai-shenjian",1)<160))
         {
         
          command ("nod" + ob->query("id"));
          message_vision("枯荣长老一掌向地拍去，身后轰然移开一扇石门，"+ob->query("name")+"看也不看，走了过去。\n",ob);
          thing = deep_inventory(ob);
	  i = sizeof(thing);
	    while (i--)
	       if (thing[i]->is_character()) {
		   message_vision("枯荣长老突然伸手一拦，道；你怎么带外人进洞？。\n", ob);
		   me->set_leader(ob);
                   remove_call_out("kill_ob");
                   call_out("kill_ob", 0, me); 
	           return " ";
		} 
	
	ob->move("/d/tls/pyd");
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
      	 
      if( ob->query_skill("liumai-shenjian",1)>160)
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
        set("max_jing",3000);
        set("jing",3000);
        set("eff_jingli",3000);
        set("max_qi",5000);
        set("qi",5000);
        set("jiali",100);
        set("neili",6000);
        set("max_neili",6000); 
        command("yun rong");
        if(!( room = find_object("/d/tls/lsy" )) )
                room = load_object("/d/tls/lsy");
        room->delete("exits");
        ob->delete_temp("try");
        me->delete_temp("try");
        me->set_temp("try_fight",1);
        ob->set_temp("try_fight",1);        
        call_out("fighting",  3, me, ob, 0);
        message_vision("枯荣大师双掌合什，躬身一揖，恭恭敬敬的道：“请指教。”\n",ob);
        return 1;
        
        
}

void waiting(object me, int wait_time)
{
	object fighter;

        if( wait_time >= 150 )
	{
		say( "枯荣大师说道：看来你不打算接我十招了！\n\n");
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
	 
	if (!fighter || !living(fighter) || environment(fighter)!=environment(me))
	{
		if(!( room = find_object("/d/tls/lsy" )) )
                room = load_object("/d/tls/lsy");
		if( objectp(fighter)) {
			fighter->delete_temp("try_fight");
			fighter->delete_temp("beat_count");
		}
		me->delete_temp("try_fight");
		room->set("exits/out","/d/tls/songlin-1");
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
	 if(!( room = find_object("/d/tls/lsy" )) )
                room = load_object("/d/tls/lsy");
	fighter->delete_temp("try_fight");
	fighter->set("liumai_pass",1);
	me->delete_temp("try_fight");
	command("smile");
        command("say 恭喜，恭喜，你技艺青出于蓝胜于蓝，可以修习本寺神功六脉神剑,你去吧。\n");
	room->set("exits/out","/d/tls/songlin-1");
	message_vision("枯荣长老一掌向地拍去，身后轰然移开一扇石门，"+fighter->query("name")+"看也不看，走了过去。\n",fighter);
        thing = deep_inventory(fighter);
	  i = sizeof(thing);
	    while (i--)
	       if (thing[i]->is_character()) {
		   message_vision("枯荣长老突然伸手一拦，道；你怎么带外人进洞？。\n", fighter);
		   me->set_leader(fighter);
                   remove_call_out("kill_ob");
                   call_out("kill_ob", 0, me); 
	           return;
		} 
	 fighter->move("/d/tls/pyd");
         return;
	
}

// robber.h

void start_attact(object me)
{
        me->delete("busy",1);
        return;
}
int no_heal(string arg)
{
        object ppl,me;
        ppl = this_player();
        me = this_object();
        if (!arg)
                        return 0;
        if (!me->query("uni_target"))
                return 0;
        if (!ppl) return 0;
        if ( (ppl == me->query("uni_target")) && ( (arg == "heal") || (arg == "lifeheal") ) )
        {
                write("战斗中不能疗伤！\n");
                return 1;
        }
        return 0;
}
int no_say(string arg)
{
        object ppl,me;
        int i;
        ppl = this_player();
        me = this_object();
        if (!objectp(ppl)) return 0;
        if (ppl == me->query("uni_target") && arg != "")
        {
                write("你说道：" + arg + "\n");
                write("劫匪怒道：嘴里不干不净地嘟囔什么！看招！\n");
                me->delete("busy",1);
                me->start_busy(0);
                for (i=0;i<random(5)+1;i++)
                        COMBAT_D->do_attack(me, ppl, me->query_temp("weapon"));
                return 1;
        }
        return 0;
}
void init()
{
        set("no_steal",1);
        set("chat_chance_combat", 40);
        add_action("no_heal","yun");
        add_action("no_heal","exert");
                add_action("no_say","say");
}
void destroying(object me)
{
        destruct(me);
        return;
}

int dest() //By Zine ，15分钟自毁，有些劫匪在街上一直存在 13 Nov 2010
{
    if (this_object())
    {
        message_vision(CYN"\n$N看看无镖可截，转身离开了。\n"NOR,this_object());
        destruct(this_object());
    }
    return 1;
}
int checking(object me, object ob)
{
        object obgem;
        int mf_rate,deactivity_rate;//限制全自动机器
        if(!ob||!me)
              	return 1;
        if (ob->query("antirobot/deactivity") < 2) deactivity_rate = 100;
  	      else deactivity_rate = 400/(ob->query("antirobot/deactivity")*ob->query("antirobot/deactivity")*ob->query("antirobot/deactivity"));
        mf_rate = 35*deactivity_rate;
        if (ob->query_temp("yb_addi")) //做完附加任务，加下来到下次附加之前掉宝率增加20%，Zine 26 Nov 2010
        {
            mf_rate=mf_rate*6/5;
        }
        if((int)me->query("qi")* 100 / (int)me->query("max_qi") <= 15){
                if (!living(me)) return 1;
                 else {
                 if (!me->query("rob_unique"))
                       ob->add_temp("yunbiao/bonus",me->query("bonus"));
                  if (random(ob->query_temp("yunbiao/lianxu"))>random(5) && random(10000) < mf_rate) GEM_D->drop(me,ob); //控制掉
                  message_vision(CYN"\n$N叫道：点子扎手，扯呼！\n\n$N个起纵遁入暗里不见了。\n\n"NOR,me);
                  destruct(this_object());
                  return 1;
                 }
        }
        if (me->is_fighting()) 
        {
                call_out("checking",1, me, ob);
                return 1;
        }
        if (!me->is_fighting() && living(ob) && objectp(present(ob->query("id"), environment())) )
        {
                me->fight_ob(ob);
                call_out("checking",1, me, ob);
                return 1;
        }
        if ( (!present(ob->query("id"), environment()) || !living(ob)) && present("biao che",environment()) )
           {  
                command("laugh");
                command("jie biao che");
                message_vision("$N推着镖车呼啸而去。\n", me);
                call_out("destroying",1,me);
                return 1;
        }
        if (!present(ob->query("id"), environment()))
          {
              message_vision("$N悻悻的说：“算你跑的快！”\n",me);
              command("sigh");
                command("jie biao che");
              message_vision("$N身行几起几纵消失在暗处\n",me);
              call_out("destroying",1,me);
              return 1;
          }
        if ( present(ob->query("id"), environment()) && !living(ob) && present("biao che",environment()) )
           {  
                command("laugh");
                command("jie biao che");
                message_vision("$N推着镖车呼啸而去。\n", me);
                call_out("destroying",1,me);
                return 1;
        }  
        if (me->query("rob_unique") && (!present(ob->query("id"), environment()) || !living(ob)) )
           {
                command("haha");
                command("get all from " + ob->query("id"));
              message_vision("$N身行几起几纵消失在暗处\n",me);
              call_out("destroying",1,me);
              return 1;
            }   
         if ( present(ob->query("id"), environment()) && !living(ob) && !present("biao che",environment()) )
           {  
                command("sigh");
              message_vision("$N身行几起几纵消失在暗处\n",me);
              call_out("destroying",1,me);
              return 1;
           }  
            
}
void unconcious()
{
        die();
}
void die()
{
	      int mf_rate,deactivity_rate;//限制全自动机器
	      object ob;
	      if (objectp(this_object()->query("uni_target")))
	      {
        	ob = this_object()->query("uni_target");
        	if (objectp(ob)) {
	        	if (ob->query("antirobot/deactivity") < 2) deactivity_rate = 100;
	  	      	else deactivity_rate = 400/(ob->query("antirobot/deactivity")*ob->query("antirobot/deactivity")*ob->query("antirobot/deactivity"));
	        	mf_rate = 35*deactivity_rate;
                if (ob->query_temp("yb_addi")) //做完附加任务，加下来到下次附加之前掉宝率增加20%，Zine 26 Nov 2010
                {
                    mf_rate=mf_rate*6/5;
                }
	        	if (objectp(ob) && !this_object()->query("rob_unique"))
	        	{
	                ob->add_temp("yunbiao/bonus",this_object()->query("bonus"));
	                ob->add_temp("yunbiao/killed_num",1);
	                if (random(ob->query_temp("yunbiao/lianxu"))>random(5) && random(10000)<mf_rate) 
	        	         GEM_D->drop(this_object(),ob); //控制掉落率             
	        	}
	        }
	    }
        message_vision(CYN"\n$N叫道：点子扎手，扯呼！\n\n$N个起纵遁入暗里不见了。\n\n"NOR,this_object());
        destruct(this_object());
}
void do_change(object ob)
{
      object me,robber;
      mapping skills, hp_status, skill_status;
      string *sname;
      int i, temp,factor,exp,count,tempskill,lianxu;
      me = this_object();
//      ob = this_player(); 
         temp = 0;
         tempskill = 0;
         lianxu = ob->query_temp("yunbiao/lianxunum");
        exp = ob->query("combat_exp");
        tempskill = to_int(pow(exp/100,0.333)*10);
        tempskill = to_int(tempskill * ( 50 + random(35) )/100);
        if (tempskill==0)
                 tempskill=10;
          skills = me->query_skills();
        for (i=0;i<sizeof(skills);i++)
                 skills[keys(skills)[i]] = tempskill;
/* copy hp */
        hp_status = ob->query_entire_dbase();
        me->set("str", hp_status["str"]+random(2));
        me->set("int", hp_status["int"]+random(2));
        me->set("con", hp_status["con"]+random(2));
        me->set("dex", hp_status["dex"]+random(2));
// me->set("combat_exp",to_int(hp_status["combat_exp"]*(random(5)+8)/10))
    me->set("combat_exp",to_int(hp_status["combat_exp"]/100*(80 + lianxu*3 + random(3))));
                if (random(60) == 0)
                me->set("combat_exp",to_int(hp_status["combat_exp"]*(random(6)+8)/10));
                if (me->query("combat_exp") < 500000)
                 me->set("combat_exp",500000);
        me->set("qi", hp_status["max_qi"]);
        me->set("eff_qi",hp_status["max_qi"]);
        me->set("max_qi",hp_status["max_qi"]);
        me->set("max_neili", hp_status["max_neili"]);
        me->set("neili", hp_status["max_neili"]);
        me->set("max_jingli", hp_status["max_jingli"]);
        me->set("jingli", hp_status["jingli"]);
                //icer added to avoid short jing damage bug
                if (me->query("jing") < 2000)
                {
                        me->set("eff_jing",2000);
                        me->set("max_jing",2000);
                        me->set("jing",2000);
                }
        count = 1;
        if (!me->query("sp"))
        {
                temp = hp_status["qi"] / 4000;
                factor = 10 + temp*10;
                if (factor == 10)
                        factor = 15;
                for (i=0;i<((ob->query_temp("yunbiao/killed_num")/factor)+temp);i++)
                {
                          if (count > 3)
                                break;
                          message_vision(HIR"劫匪大喊：点子爪子硬！赶紧来帮忙！\n"NOR,ob);
                          me->add("bonus",1);
                          switch(random(5))
                          {
                                case 0:
                                        robber=new("/d/city/npc/robber0");
                                        break;
                                case 1:
                                        robber=new("/d/city/npc/robber1");
                                        break;
                                case 2:
                                        robber=new("/d/city/npc/robber2");
                                        break;
                                case 3:
                                        robber=new("/d/city/npc/robber3");
                                        break;
                                case 4:
                                        robber=new("/d/city/npc/robber4");
                                        break;
                          }
                          count++;
                          robber->set("uni_target",ob);
                          robber->set("title", "拦路抢劫"+ob->query("name")+"的");
                          robber->set_name(robber->query("name"), ({ob->query("id")+"'s robber",ob->query("id")+" robber","robber"}));
                          robber->set("sp",1);
                          robber->do_change(ob);
                          robber->move(environment(ob));
                          robber->fight_ob(ob);
                          robber->checking(robber,ob);
                          robber->command("rob");
                }
        }
}

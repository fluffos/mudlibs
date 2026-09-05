#include <title.h>

int check_victim_value(object victim)
{
    object* inventory;
    int i,victim_value=0;

    inventory=all_inventory(victim);
    for (i=0;i<sizeof(inventory);i++)
    {
        victim_value+=inventory[i]->query("value");
        if (victim_value>=10000)   // 身上有总价值1gold的物品就算有钱的主
        {
            return 1;
        }
    }
    return 0;
}

void bijiao(object killer,object victim)
{
  int score,mp_num;
  object *user_list;
  string *killers;
  string allstr;
  string str,pai,pai2,pai3;
  int i,j,k;
  /*********该为直接进行门派追杀，不记录hate了，否则难以维护
  if (victim->query("family/family_name") == "杀手帮"
  || !userp(victim))
  return;
  //                       write("1");
  if(!(score=victim->query("score")))
     score=victim->query("combat_exp")/200+1;
     if(score<100)return;
     pai  = killer->query("family/family_name");
     pai2 = victim->query("family/family_name");
     if(!pai2) {pai2="普通百姓";}
     if(!pai) {pai="普通百姓";}
     str=read_file("/hate/mp_mun",1,1);
     sscanf(str,"%d",mp_num);
     str = "";
     for(i=0;i<mp_num-1;i++)
     { allstr = "";
        pai3 = "";
      allstr = read_file("/hate/"+pai2,i+1,1);
      sscanf(allstr,"%s %d",pai3,k);
      if ( pai3 == pai)
      {
      if(k>-1000)
      {if(score>5000)
      score=5000;
      k-=score/200+1;
      }
      allstr = "";
      allstr= pai3+" "+k+"\n";
      }
      str += allstr;
      }
      write_file("/hate/"+pai2, str, 1);
  ********/
  /*
  if (!victim->query("family"))
  return;
  if (victim->query("family/family_name") == killer->query("family/family_name"))
  return;
  if (killer->query_temp("zhuisha/" + victim->query("id")))  //追杀引起的pk不会引起连环追杀
  {
  killer->delete_temp("zhuisha/" + victim->query("id"));
  return;
  }
  pai = victim->query("family/family_name");
  user_list = users();
  for (i=0;i<sizeof(user_list);i++)
  {
  if ((user_list[i]->query("family/family_name") == pai)&&(user_list[i]->query("score")>500))
  {
  user_list[i]->kill_ob(killer);
  tell_object(user_list[i],HIR"你开始追杀杀害" + victim->query("name") + "的凶手" + killer->query("name") + "！\n"NOR);
  user_list[i]->set_temp("zhuisha/" + killer->query("id"),1);
  }
  }
    tell_object(killer,HIR"由于你残害"+victim->query("name")+
  "，"+victim->query("family/family_name")+"开始了对你的追杀！\n"NOR);
  */
  return;
}

void winner_reward(object killer, object victim)
{
  object owner;
  mapping your,wsquest;
  int exp,pot,bonus,score;
  your = victim->query_entire_dbase();
  
  if ( killer->query_temp("killing") != victim->query("id") )
  {
    killer->remove_enemy(victim);
    tell_object(killer,"\n你战胜了"+victim->query("name")+"!\n");
//门忠战胜任务完成标志
    if(killer->query("quest/type") == "win"
      && killer->query("quest/name") == victim->name(1)
      && !userp(victim))
      killer->set("quest/finish",1);
  }
  if(owner=killer->query_temp("owner")) killer = owner;
  killer->defeated_enemy(victim);
//通用的npc战胜判定，战胜判定建立在victim对象的winner_reward函数上
  if ( !userp(victim) )
  	victim->winner_reward(killer, victim);

//门派战胜任务完成标志  
  if( interactive(killer) && (wsquest = killer->query("wsquest"))
    && ( (int)killer->query("task_time") >= time())
    && (victim->name() == wsquest["quest"])
    && (wsquest["quest_type"] == "胜")
    && !userp(victim)
    && (!killer->query("over_time")))
  {
    //    tell_object(killer,"你战胜了"+victim->name()+"!\n");
    exp = wsquest["exp_bonus"] + random(wsquest["exp_bonus"]);
    pot = wsquest["pot_bonus"] + random(wsquest["pot_bonus"]);
    if (killer->query("wsquest_number")/4<5)
    {
      exp += exp*killer->query("wsquest_number")/2;
      pot += pot*killer->query("wsquest_number")/2;
    }
    else
    {
      exp += exp*10;
      pot += pot*10;
    }
    killer->set("task_time", (int) time());
    score = 1;
    tell_object(killer,"恭喜你！你又完成了一项任务！\n");
    bonus = (int) killer->query("combat_exp");
    bonus += exp;
    killer->set("combat_exp", bonus);
    killer->add("exp/menpai", exp);
    bonus = (int) killer->query("potential");
    bonus = bonus - (int) killer->query("learned_points");
    bonus = bonus + pot;
    //      if( bonus > 500) bonus = 500;
    bonus += (int) killer->query("learned_points");
    killer->set("potential", bonus );
    killer->set("pot/menpai", pot );
    bonus = (int) killer->query("score");
    bonus += score;
    killer->set("score", bonus);
    tell_object(killer,HIW"你被奖励了：\n" + chinese_number(exp) + "点实战经验\n"+chinese_number(pot) + "点潜能\n" NOR);
    killer->set("wsquest", 0 );
  }
}

void killer_reward(mixed killer, object victim)
{
    int bls,check,score,badscore;
    string vmark;
    string deathplace="未知地点";
    object killer_ob,victim_ob,where;//where计算当前地点
    object owner,jujing,feilong,mengzhu;
    int bonus, exp, i, msize, pot, shen, kill_ya;
    object *mem;
    mapping wsquest;
    int gain_shen;
    int real_die = 0;
	int zs_point,bs_point,rdm_point,dpot;
	int realpot, maxpot = 0;
    float shaqi;
  
    if(objectp(killer) && owner = killer->query_temp("owner"))
        killer = owner;
  
    if(objectp(killer) && userp(killer)) victim->add("fhost",1); // 被玩家杀死，fhost value加一
    if(objectp(killer) && !userp(killer)) victim->add("ghost",1); // 被NPC杀死，ghost value加一

    if(objectp(killer))
    {
        killer->set_temp("killer_ok",1);
        // Call the mudlib killer apply.
        killer->killed_enemy(victim);
            
//      if(userp(killer) && userp(victim) && !environment(victim)->query("no_die"))
//被动杀人5分钟之内不增加杀气， by all@2015/1/21
        if(userp(killer) && userp(victim) && !environment(victim)->query("no_die")
           && !(killer->query("attack_by_player/id")==victim->query("id") && time()-killer->query("attack_by_player/time")<300)
           && !(victim->query("attack_player/id")==killer->query("id") && time()-victim->query("attack_player/time")<300))
        {
            killer->add("killer/count",1);
            killer->set("killer/time",time());
            victim->delete("killer/time");
            if(objectp(environment(killer)) && (environment(killer)->query("no_fight") || environment(killer)->query("is_xinfang")))
            {
                //move it to luoyang center
                tell_object(killer,"你自以为杀了人谁也奈何不得你，谁知道眼前刀光一闪，立刻昏了过去，醒来时发现自己身在洛阳。\n");
                killer->move("/d/luoyang/center");
            }
        }
    }

  if( userp(victim) )
  {        
    if(objectp(killer))
      log_file("nosave/kill_player",sprintf("%s(%s) killed by %s(%s) on %s\n",
      victim->name(1), victim->query("id"),
      killer->name(1), killer->query("id"), ctime(time()) ));
    else if(stringp(killer))
      log_file("nosave/kill_player",sprintf("%s(%s) died because %s死了。 on %s\n",
      victim->name(1), victim->query("id"), killer, ctime(time()) ));
    else
      log_file("nosave/kill_player", sprintf("%s(%s) died at %s on %s\n",
      victim->name(1), victim->query("id"),
      file_name(environment(victim)), ctime(time()) ));

    if( objectp(killer) && killer->query("pker")
      && killer->query("deathname")==victim->query("id")
      && !killer->query("accomplish1")&&!killer->query("accomplish2")
      && !environment(killer)->query("no_die")
      && !environment(victim)->query("no_die")
      && !environment(killer)->query("no_death")
      && !environment(victim)->query("no_death"))
    {
      message("vision",HIR "看着"+victim->query("name")+"在你面前慢慢的倒下，慢慢的流血，慢慢的抽搐，\n"
        "慢慢的死去，你知道自己终于完成了楚帮主的任务！\n"
        "在这个弱肉强食的世界上，你成为了胜利者……\n" NOR,killer);
      victim->set("pked/be_pked","pker");
      if(killer->query("pk_level")==1)
        killer->set("accomplish1",1);
      else
        killer->set("accomplish2",1);
    }
    if( objectp(killer) && victim->query_leader() != killer )
      killer->add("PKS", 1);
    if (objectp(killer) && userp(killer)
      && (victim->query("startroom")||userp(victim))
      && (victim->query_leader() != killer) 
      && !(environment(killer)->query("no_die")))
    {
      killer->add_temp("kill_amount",1);
      shaqi = killer->query("combat_exp")/(victim->query("combat_exp") + 1);
      if( shaqi < 1.0 )
        shaqi = 1.0;
      shaqi = exp( log(shaqi*1.0) / 3 ) * 10;
      shaqi = shaqi * (killer->query_temp("kill_amount") + 5) / 5;
      if (shaqi > 100)
        shaqi = 100;
      if (shaqi < 10)
        shaqi = 10;
      //短时间内杀多个非任务npc杀气加倍涨
      if (( time()-killer->query_temp("last_add_shaqi"))<30)
        shaqi=shaqi*2;
      if (( time()-killer->query_temp("last_add_shaqi"))<10)
        shaqi=shaqi*2;      
//      if (userp(victim))
	if (userp(victim)&& time()-killer->query("killer/time")<10)//被动杀人5分钟之内不增加杀气， by all@2015/1/21
        shaqi=1000;  //PK一次杀气加200
      if (victim->query_leader() == killer)
        shaqi = 0;
      killer->add("shaqi", (int)(shaqi / 5));
      killer->set_temp("last_add_shaqi",time()); 
      killer->delete("attack_by_player");
      victim->delete("attack_player");           
    }
    
    if (!environment(victim)->query("no_die")
      && !environment(victim)->query("no_death")
      && !(objectp(killer) && killer->query("xiaofeng") && victim==killer->query("uni_target")) )
      //added by iszt@pkuxkx, 2007-04-08
      victim->clear_condition();
    // Give the death penalty to the dying user.
    if( objectp(where = environment(victim)) ) {
      if( where->is_character() )
        deathplace = where->query("name")+"("+where->query("id")+")";
      else
        deathplace = where->short() ? where->short() : where->query("short");
    }
    victim->set("last_killed/place", deathplace);
    //    victim->set("last_killed/killer", objectp(killer) ? killer->short(1) : "死因不明");
    if (objectp(killer) && victim->isvalid_death_reason()==1) 
    {
      if(killer->query("pk_level") >= 2 && killer->query("pker") && killer->query("deathname")==victim->query("id"))
      {
        //杀手帮杀人不留姓名
        victim->set("last_killed/killer","被"+killer->query("name")+"(...)杀死");
      }
      else
      {
        victim->set("last_killed/killer","被"+killer->query("name")+"("+killer->query("id")+")杀死");
      }
    }
    else if (victim->isvalid_death_reason()==2) victim->set("last_killed/killer",victim->query_temp("death_msg")+"死");
    else victim->set("last_killed/killer","不明");
    
    victim->set("last_killed/time",NATURE_D->game_time());
    //whuan，记录上次被杀

    victim->delete("vendetta");
    victim->set("eff_qi", victim->query("max_qi"));
    victim->set("qi", 1);
    victim->set("eff_jing", victim->query("max_jing"));
    victim->set("jing", 1);
    victim->set("neili", 0);

    //icer added to avoid killing in biwuchang adding PKS
    if(environment(victim)->query("no_die")
      || environment(victim)->query("no_death")
      || (objectp(killer) && !userp(killer) && killer->query("xiaofeng")) )
      //added by iszt@pkuxkx, 2007-04-08
    {
      if(objectp(killer)) killer->add("PKS",-1);
      if(objectp(killer) && userp(killer)) victim->add("fhost",-1);//被npc杀的假死
      if(objectp(killer) && !userp(killer)) victim->add("ghost",-1);//被npc杀的假死
    }
    else if( victim->query("mud_age") > 86400 )      

   /* {
        victim->delete("shaqi"); // 真死时才清零杀气
        real_die = 1;
      if(victim->query("combat_exp") < 1000000 && random(15))
      {
        //新手损失的概率很小。
      }
      //有athanasy特技的player只有一半的几率掉经验，潜能 -by whuan 2007-8-26
      else if (victim->query("special_skill/athanasy") && random(3))
        tell_object(victim, HIY"你福大命大，发现自己居然没有任何损失！\n"NOR);
        //万一乱pk就开这个----by whuan
        else if (userp(killer))
        {
        victim->add("combat_exp", -(int)victim->query("combat_exp") / 100);
        }
      
        else {
        if( (int)victim->query("combat_exp")>2000 )
                {
          victim->add("combat_exp", -(int)victim->query("combat_exp") / 50);
                }
        if( (int)victim->query("potential") > (int)victim->query("learned_points"))
          victim->add("potential",
          ((int)victim->query("learned_points") - (int)victim->query("potential"))/3 );
        if(random(4))
          victim->skill_death_penalty();
      }
    }*/
	{
        victim->delete("shaqi"); // 真死时才清零杀气
        real_die = 1;
      if(victim->query("combat_exp") < 1000000 && random(15))
      {
     	  tell_object(victim, HIY"你福大命大，发现自己居然没有任何损失！\n"NOR);
		//新手损失的概率很小。
      }
      //有athanasy特技的player只有一半的几率掉经验，潜能 -by whuan 2007-8-26
      //update by yhzzyahoo
      else 
	  {
		dpot = (int)victim->query("death_decrease");
		if (dpot>0) 
		{
			if (victim->query("combat_exp")< 200000000) // 0-200m
			{
				if (dpot>12) dpot=12;
			}
			else if (victim->query("combat_exp")< 400000000) // 200-400m
			{
				if (dpot>24) dpot=24;
			}
			else if (victim->query("combat_exp")< 600000000) // 400-600m
			{
				if (dpot>36) dpot=36;
			}
			else if (victim->query("combat_exp")< 800000000) // 600-800m
			{
				if (dpot>48) dpot=48;
			}
			else if (victim->query("combat_exp")< 1500000000) // 800-1500m
			{
				if (dpot>60) dpot=60;
			}
			else  // 1500m+
			{
				if (dpot>72) dpot=72;
			}
			dpot = 100 - dpot;
		}
		else dpot = 100;
		
		if (dpot<100)
			log_file("nosave/wuchang_zaohua", sprintf("%s:%s(%s)死亡触发无常造化丹，损失减少到原有的 %d％（药效%d）。\n",
				ctime(time()),victim->query("name"),victim->query("id"),dpot,(int)victim->query("death_decrease"))); 
				
		victim->delete("death_decrease");
		
		//天命真龙特技，限制死亡最大损失
		if (victim->query("special_skill/destiny")&&(victim->query("age")>=18))
			maxpot = 100000;
		
	  	if ((victim->query("special_skill/athanasy"))&&(victim->query("age")>=18))
	  	{
			// 把等级计算统一整合到special文件里去，便于修改
			switch (SPECIAL_D("athanasy")->active_level(victim))
			{
				case 3: zs_point=60;
						bs_point=100;
						break;
				case 2: zs_point=45;
						bs_point=80;
						break;
				default: zs_point=33;
						 bs_point=65;
			}
/*	  		
	  		if (victim->query("special_level/athanasy")>2)
			{
				if (victim->query("special_skill/constitution") && victim->query("special_skill/intellect"))
				{
					zs_point=60;
					bs_point=100;
				}
				else
				{
					if (victim->query("special_skill/intellect"))
					{
						zs_point=45;
						bs_point=80;
					}
				}		
			}
			else
			{
				if ((victim->query("special_level/athanasy")>1)&&(victim->query("special_skill/intellect")))
				{
					zs_point=45;
					bs_point=80;
				}
			}
*/			
			rdm_point=random(100);
			if(rdm_point<zs_point)
			{
				tell_object(victim, HIR"你耳边似乎听见一声嘹亮的凤鸣，浑身隐隐透出一股暗红色的光芒，犹如涅磐之火，抵消了所有损害！\n"NOR);
			}
			else
			{
				if( (int)victim->query("potential") > (int)victim->query("learned_points"))
				{
					realpot = (((int)victim->query("potential") - (int)victim->query("learned_points"))/3) *dpot/100 ;
					if ( maxpot>0 && realpot>maxpot ) realpot = maxpot;
					victim->add("potential", - realpot);
				}

				if(rdm_point<bs_point)
				{
					if( (int)victim->query("combat_exp")>2000 )
					{
						tell_object(victim, RED"一股暗红色的光芒从你周身一闪而过，犹如涅磐之火，帮助你抵消了一部分损害！\n"NOR);
			  			//真死代码，降低真死惩罚也在这里
						realpot = ((int)victim->query("combat_exp")/100)*dpot/100;
						if ( maxpot>0 && realpot>maxpot ) 
						{
							tell_object(victim, HIY"冥冥中似乎有一股超越生死的强大力量在庇护着你，为你抵挡死亡带来的伤害！\n"NOR);
							realpot = maxpot;
						}
						victim->add("combat_exp", - realpot );
					}
				}
				else
				{
					if( (int)victim->query("combat_exp")>2000 )
	                {
						realpot = ((int)victim->query("combat_exp")/50)*dpot/100;
						if ( maxpot>0 && realpot>maxpot ) 
						{
							tell_object(victim, HIY"冥冥中似乎有一股超越生死的强大力量在庇护着你，为你抵挡死亡带来的伤害！\n"NOR);
							realpot = maxpot;
						}
						victim->add("combat_exp", - realpot );
	                }
					victim->skill_death_penalty();
				}
				if (dpot<100)
					tell_object(victim, HIG"你感觉丹田深处涌出一股暖流护住心脉，抵消了一部分损失！\n"NOR);
			}
	  		
		}
	    else // 无凤凰的真死
		{
			if (dpot<100)
				tell_object(victim, HIG"你感觉丹田深处涌出一股暖流护住心脉，抵消了一部分损失！\n"NOR);
			//真死代码，降低真死惩罚也在这里
	        if( (int)victim->query("combat_exp")>2000 )
	        {
				realpot = ((int)victim->query("combat_exp")/50)*dpot/100;
				if ( maxpot>0 && realpot>maxpot ) 
				{
					tell_object(victim, HIY"冥冥中似乎有一股超越生死的强大力量在庇护着你，为你抵挡死亡带来的伤害！\n"NOR);
					realpot = maxpot;
				}
	         	victim->add("combat_exp", - realpot );
	        }
	        if( (int)victim->query("potential") > (int)victim->query("learned_points"))
			{
				realpot = (((int)victim->query("potential") - (int)victim->query("learned_points"))/3)*dpot/100;
				if ( maxpot>0 && realpot>maxpot ) realpot = maxpot;
				victim->add("potential", - realpot );
			}
	        victim->skill_death_penalty();
	    }
      }
    }
    else
    {
        victim->delete("shaqi"); // 真死时才清零杀气
        real_die = 1;
      if(victim->query("combat_exp")>1020)  //小于1000可能引起判师bug
        victim->add("combat_exp",-random(20));
      if( (int)victim->query("potential") > (int)victim->query("learned_points"))
        victim->add("potential",-random(6));
      if( (int)victim->query("potential") <=(int)victim->query("learned_points"))
        victim->set("potential",victim->query("learned_points"));
    }
    if( victim->query("thief") )
      victim->set("thief", (int)victim->query("thief") / 2);
    victim->delete_temp("pk_exp");
    bls = 10;
    if( objectp(killer) && userp(killer) && killer->query_temp("apply/name") )
    {
        if (victim->isvalid_death_reason()==2)
        {
            CHANNEL_D->do_channel(this_object(), "rumor",
              sprintf("有人看到害死%s的元凶是" + killer->query_temp("apply/name")[0] + "。",victim->name(1)));
        }
        else
        {
            CHANNEL_D->do_channel(this_object(), "rumor",
              sprintf("有人看到杀死%s的是" + killer->query_temp("apply/name")[0] + "。",victim->name(1)));
        }
        write_file("/log/nosave/player_dead",sprintf("%s(%s) killed by %s on %s\n",
        victim->name(1), victim->query("id"),
        killer->name(1),ctime(time()) ));
    }
    else if ( objectp(killer) && userp(killer))
    {
      write_file("/log/nosave/pk_log",sprintf("%s(%s) killed by %s(%s) on %s\n",
        victim->name(1), victim->query("id"),
        killer->name(1),killer->query("id"),ctime(time()) ));
      //加入门派追杀
      if (!environment(killer)->query("no_die") && !environment(killer)->query("no_death"))
        bijiao(killer,victim);
    }
    
    // End of apprendence
    if (objectp(killer) && victim->isvalid_death_reason()==1 && !killer->query_temp("apply/name"))
      CHANNEL_D->do_channel(this_object(), "rumor",
      sprintf("%s被%s杀死了"+(real_die?"！":"。"), victim->name(1), killer->name(1)));
    else if (objectp(killer) && victim->isvalid_death_reason()==1 && killer->query_temp("apply/name"))
      CHANNEL_D->do_channel(this_object(), "rumor",
      sprintf("%s被%s杀死了"+(real_die?"！":"。"), victim->name(1), killer->name()));
    else if(stringp(killer))
      CHANNEL_D->do_channel(this_object(), "rumor",
      sprintf("%s%s死了"+(real_die?"！":"。"), victim->name(1), killer));
    else if (victim->isvalid_death_reason()==2)
      CHANNEL_D->do_channel(this_object(), "rumor",
      sprintf("%s%s死了"+(real_die?"！":"。"), victim->name(1), victim->query_temp("death_msg")));
    else
      CHANNEL_D->do_channel(this_object(), "rumor",
      sprintf("%s莫名其妙的死了"+(real_die?"！":"。"), victim->name(1)));
    
    if( objectp(victim) && (victim->query_temp("apply/name")||victim->query_temp("apply/short")) )
    {
        //对于死亡的情况下清理面具信息，调用新的restore_face函数来统一初始化
        //by seagate@pkuxkx 2010/12/04
        victim->restore_face(FACE_FACT);
        if(objectp(killer) && userp(killer))
        {
            killer->add("shen",2000);
        }
        return;
    }
  } else {
    if(objectp(killer))
      killer->add("MKS", 1);

    if (objectp(killer) && userp(killer)
      && (victim->query("startroom"))
      && (victim->query_leader() != killer) 
      && !(environment(killer)->query("no_die")))
    {
      killer->add_temp("kill_amount",1);
      shaqi = killer->query("combat_exp")/(victim->query("combat_exp") + 1);
      if( shaqi < 1 )
        shaqi = 1;
      shaqi = exp( log(shaqi*1.0) / 3 ) * 10;
      shaqi = shaqi * (killer->query("shaqi")/10 + 5) / 10;
      if (shaqi > 50)
        shaqi = 50;
      if (shaqi < 3)
        shaqi = 3;
      //短时间内杀多个非任务npc杀气加倍涨，同一地点杀不算，防止killall十大高手等涨太多杀气
      if (ANTIROBOT_D->fullme_invalid() && function_exists("attempt_apprentice", victim, 1))
      {
          shaqi=shaqi+200;
          // tell_object(killer, HIW"杀死master，额外获得杀气200/10!\n"NOR);
      }
      else if (!ANTIROBOT_D->fullme_invalid() && ( check_victim_value(victim) || victim->query_temp("is_rich")))
      {
          shaqi=shaqi+200;
          // tell_object(killer, HIW"杀死有钱的主，额外获得杀气200/10!\n"NOR);
      }
      if ((time()-killer->query_temp("last_add_shaqi"))>600 && base_name(environment(killer))==killer->query_temp("last_killer_place"))
      {
          shaqi=shaqi*2;
      }
      if (!ANTIROBOT_D->fullme_invalid() && killer->query("antirobot/deactivity")>=6) shaqi=shaqi*2;
      if (victim->query_leader() == killer)
        shaqi = 0;
      killer->add("shaqi",(int)(shaqi/10));
      // tell_object(killer, HIW"杀气npc获得杀气"+(shaqi/10)+"\n"NOR);
      killer->set_temp("last_add_shaqi",time());

      if (killer->query("shaqi") < 400)
        tell_object(killer, HIR"你的杀气增加了！\n" NOR);
      if ((killer->query("shaqi") >= 400) && (killer->query("shaqi") < 500))
        tell_object(killer, HIR"你心中充满了杀气，只想再找几个人杀杀！\n"NOR);
      killer->set_temp("last_killer_place",base_name(environment(killer)));
      killer->set_temp("last_killer_exp",killer->query("combat_exp"));
    }
    if(objectp(killer))
      F_NEWQUEST->quest_kill(victim,killer);
    //write(killer->query("quest/name"));write(victim->query("name"));write(killer->query("quest/id"));write(victim->query("id"));
    if(objectp(killer) && victim->query("kill_id")==killer->query("id"))
      killer->delete_temp("pk_exp");
    bls = 1;
    if(objectp(killer) && killer->query("quest/type") == "kill"
      && killer->query("quest/name") == victim->name(1)
      && !userp(victim))
      killer->set("quest/finish",1);
  }
  
  if (objectp(killer) && userp(killer) && killer->query("combat_exp") < victim->query("combat_exp"))
    {
    if (!((environment(killer)->query("no_die")||environment(killer)->query("no_death")) && userp(victim)) )
        {
            //杀npc可以获得正负道德，但不超过1w
            gain_shen = -(int)victim->query("shen") / 10;
            if(gain_shen > 10000) gain_shen = 10000;
            else if(gain_shen < -10000) gain_shen = -10000;
            killer->add("shen", gain_shen);
        }
    }
  
  if( objectp(killer) && stringp(vmark = victim->query("vendetta_mark")) )
    killer->add("vendetta/" + vmark, 1);
  if (userp(victim))
  {
    victim->save();
  }
  
  // for quest --pal
  if( objectp(killer) && interactive(killer) && (wsquest = killer->query("wsquest")) && ( (int)killer->query("task_time") >= time()) && (victim->name() == wsquest["quest"]) && !userp(victim)&& (wsquest["quest_type"] == "杀"))
  {
    exp = wsquest["exp_bonus"] + random(wsquest["exp_bonus"]);
    pot = wsquest["pot_bonus"] + random(wsquest["pot_bonus"]);
    if (killer->query("wsquest_number")/4 < 5)
    {
      exp += exp*killer->query("wsquest_number")/2;
      pot += pot*killer->query("wsquest_number")/2;
    }
    else
    {
      exp += exp*10;
      pot += pot*10;
    }
    killer->set("wsquest", 0 );
    score = 1;
    killer->set("task_time", (int) time());
    tell_object(killer,"恭喜你！你又完成了一项任务！\n");
    bonus = (int) killer->query("combat_exp");
    bonus += exp;
    killer->set("combat_exp", bonus);
    bonus = (int) killer->query("potential");
    bonus = bonus - (int) killer->query("learned_points");
    bonus = bonus + pot;
    //    if( bonus > 1000) bonus = 1000;
    bonus += (int) killer->query("learned_points");
    killer->set("potential", bonus );
    bonus = (int) killer->query("score");
    bonus += score;
    killer->set("score", bonus);
    tell_object(killer,HIW"你被奖励了：\n" + chinese_number(exp) + "点实战经验\n"+chinese_number(pot) + "点潜能\n" NOR);
  }
  
}


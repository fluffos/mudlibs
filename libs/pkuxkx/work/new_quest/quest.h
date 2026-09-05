//xkx的任务系统
//write by cuer  1999.11.20

#ifndef __QUEST__
#define __QUEST__

#define MAXREWARD  40  //最大奖励

#define INDEXDELTA 20  //任务的随机范围

#define IDX_TYPE 0      //任务类型find,give,kill
#define IDX_NAME 1      //任务对象name
#define IDX_ID   2      //任务对象id
#define IDX_OBJNAME  3  //送的物件name
#define IDX_OBJID 4     //送的物件id
#define IDX_TIME 5      //任务的时限
#define IDX_Add_TIME 120      //任务的宽限时限

// the quest format is the following mapping:
// combat_exp :  type     name     id            objname  objid     time 
//-------------------------------------------------------------------------
//  1000   : ({ "find",  "秘笈",   "mi ji" ,     "",        ""      "300" }), 
//  5000   : ({ "give",  "灾民",   "zai min" ,   "白银"  "silver",  "600" }), 
// 12000   : ({ "kill",  "白骨精", "baigu jing", "",       ""       "900" });
//五分钟找一本秘笈，十分钟救济灾民五两银子，十五分钟三打白骨精．．．．．．

//以下程序是任务列表的按难度折半排序
int *order_list (int *list)
{
  int i, j;
  int size = sizeof(list);
        
  for (i = size-2; i >= 0; i--)
  {
    for (j = 0; j <= i; j++)
    {
      reset_eval_cost();
      if (list[j] > list[j+1])
      {
        int k = list[j];
        list[j] = list[j+1];
        list[j+1] = k;
      }
    }
  }
  return list;
}

// 人物第一次触发是调用
int *sort_quests (mapping quests)
{
  int *quest_keys = keys (quests);

  return order_list (quest_keys);
}

//根据玩家的经验找到对应的任务
int quest_accurate_index (int *quest_keys, int combat_exp)
{
  int i = 0;
  int j = 0;
  int k = sizeof(quest_keys)-1;

    //减小quest难度
      combat_exp = combat_exp * 2 / 3;
  while (i < k)
  {
    j = (k-i)/2+i;
    if (quest_keys[j] == combat_exp)
    {
      return j;
    }  
    else if (quest_keys[j] > combat_exp)
    {
      k = j - 1;
    }  
    else
    {
      i = j + 1;
    }  
  }
  return j;
}

//在对应的任务附近取随机的任务
int quest_random_index (int *quest_keys, int i, object who)
{
  int k;
  int lower;
  int upper;
  int size = sizeof (quest_keys);

  lower = i - INDEXDELTA;
  upper = i + INDEXDELTA/2;

  if (lower < 0)
  {
    lower = 0;
    upper = INDEXDELTA + INDEXDELTA;
  }

  if (upper >= size)
  {
    upper = size ;
  }

  if((random(3)==0)&&(lower>upper/4))
      lower=upper/4;
  if (upper - lower < INDEXDELTA)
    lower = 0;
  k = lower + random (upper-lower); 
  return k;
}

//取对数 
int log10 (int i)
{
  int j = 0;
  while (i = i/10)
    j++;
  return j;
}

//任务的奖励
int quest_reward (object who, mapping quests)
{
  int reward;
  int exp = who->query("combat_exp");
  int questexp = who->query("quest/combat_exp");
  int index = who->query("quest/index");

 reward = MAXREWARD*(1+index)/sizeof(quests_list); // normal value
 
 //奖励和现有exp无关，否则高exp的玩家没法做门忠
  //reward = reward*(1+log10(exp/40))*questexp/(exp+questexp)*exp/(exp+questexp);
 
  reward += (random(who->query_int())+random(who->query_kar()))/10; // base value
 
  if (reward >= MAXREWARD)
    reward = MAXREWARD + random(who->query("kar"))/2;
 

  return reward;
}
#endif

//给任务的NPC要继承的函数
int ask_quest()
{
  string str;
  object me = this_object();
  object who = this_player();
  int *quest_keys;
  int temp,donenumber;
  mapping quest;
  string *queststring;
  int i,j,k,score;   
  int day,hour,min,sec,t;
  int pot,exp;
  string time;
  string *find_strs = ({
    "$N想想对$n说道：你去给我找来",
    "$N细想了一下对$n说道：本派需要",
    "$N对$n点头说道：本派现在需要搜集",
    "$N对$n一点头说道：这里尚缺些",
    "$N想想对$n说道：你去帮本派找来",
  });    
  string *give_strs = ({
    "$N对$n说道：听说$w需要$o，你去给$w送去。\n",
    "$N对$n点点头说道：听说$w需要$o，你给送去吧。\n",
    "$N对$n说道：正好正好，$w现在急需要$o，你赶紧送过去。\n",
    "$N对$n说道：你马上去给$w送$o去。\n",
  });    
  string *kill_strs = ({
    "$N对$n说道：$w欺压我派中人，你去一趟了解了这事！\n",
    "$N怒发冲冠，对$n说道：$w散布我派谣言，你去解决了$w！\n",
    "$N回头对$n说道：我现在正需要你去将$w除掉！\n",
    "$N对$n说道：去把将$w杀掉！\n",
  });               
  string *win_strs = ({
    "$N对$n说道：$w在武林中耀武扬威，你去跟$w一比高下！\n",
    "$N气愤地说道：$w最近太驳我派面子，你去给我打败$w!\n",
    "$N对$n说道：$w最近有点不知天高地厚，你去给$w点颜色瞧瞧。\n",
    "$N对$n说道：$w正在比武，你去给我踢了$w的场子！\n",
  });
  if(who->query("family/family_name")!=me->query("family/family_name"))
          {command("? "+who->query("id"));
           command("say "+RANK_D->query_respect(who)+"与本派素无来往，此话从何说起？");
           return 1; 
           }         
           

  if (!who->query("quest")) who->set("quest/done_number",1);
  quest =  who->query("quest");
  if(quest&&quest["type"])
        {                                   
         if( who->query("quest/finish"))
            {
             if( quest["time"] <  (int)time() )
             {
             	tell_object(who,me->query("name")+"叹了口气：真可惜！你没有按时完成！\n");
	        who->delete("quest/type");
        	who->delete("quest/finish"); 
             	return 1;
             }
             tell_object(who,me->query("name")+"说道：恭喜你！你又完成了一项任务！\n");
             who->add("quest/done_number",1);
             donenumber = who->query("quest/done_number");
             if (donenumber > 6)
             	donenumber = 6;
             score=random(quest["reward"]);
             if(score==0) score = 1;
             if( who->query("score")>=0 &&
	               who->query("score")/10 * who->query("score") >= who->query("combat_exp")  )
	           {
	                command("sigh " + who->query("id"));
	                command("say " + RANK_D->query_respect(who) + 
	                        "经验最好再高些，否则没法体现你的忠诚。\n");
	           }
	           else
	           {
             	    tell_object(who,"你对"+who->query("family/family_name")+"的忠诚度提高了"+chinese_number(score)+"点。\n");  
             	    if(!who->query("score"))
               		    who->set("score",0);
                  score = score * SPEWEEK_D->query_menzhong_bonus()/100; //特殊周效果
             	    who->add("score",score); 
             }
             temp = score*donenumber*3/4 + random(score*donenumber*3/4);
             if (temp == 0) temp = 1;
             tell_object(who,"你的实战经验上升了"+chinese_number(12*temp)+"点。\n");   
             exp = REWARD_D->add_exp(who,12*temp,"newbie");
             who->add("exp/quest",exp); 
             temp = score*donenumber/4 + random(score*donenumber/4);
             if (temp == 0) temp = 1;
             tell_object(who,"你的潜能增加了"+chinese_number(6*temp)+"点。\n");      
             pot = REWARD_D->add_pot(who,12*temp);
             who->add("pot/quest",pot);  
             who->delete("quest/type");
             who->delete("quest/finish"); 
             return 1;
            }   
     	if( quest["time"] >  (int)time() )
             {               	
                if (quest["type"]=="kill")
                   message_vision ("$N对$n说道：这位"+RANK_D->query_respect(who)+
                    "，你还没有除掉"+quest["name"]+"呢。\n",me,who);           	
                else if (quest["type"]=="give")
                   message_vision ("$N对$n说道：这位"+RANK_D->query_respect(who)+
                    "，你还没给"+quest["name"]+"送去"+quest["objname"]+"呢。\n",me,who);           	
                else if (quest["type"]=="find")
                   message_vision ("$N对$n说道：这位"+RANK_D->query_respect(who)+
                    "，你还没有寻到"+quest["name"]+"呢。\n",me,who);
                else if (quest["type"]=="win")
                   message_vision ("$N对$n说道：这位"+RANK_D->query_respect(who)+
                    "，你还没有战胜"+quest["name"]+"呢。\n",me,who);
             	return 1;              
             }
	else {
                message_vision(me->query("name")+"向$N叹了口气，说道：算了，看来我不应该让你去做这件事。\n", who);
                score=1+random(quest["reward"]/2); 
                tell_object(who,"你对"+who->query("family/family_name")+"的忠诚度降低了。\n");     
                if(!who->query("score"))
              	  who->set("score",0);
        	who->add("score",-3+random(3)); 
        	who->delete("quest/type");
          who->delete("quest/finish"); 
	        who->set("quest/done_number",0);
                return 1;
             } 	
        }
  if( quest["type"]&&(quest["time"] > (int)time()) )
           {
            message_vision(me->query("name")+"向$N挥了挥手，说道：暂时没有什么事要做了，你先下去吧。\n", who);  
            return 1; 
           }      
           
  if(iszhengpai() == 1 && JIAOFEI_D->istaskstart() == 1 && random(who->query("kar")) > 50 && who->query("combat_exp") > 300000)
  {
    //副帮主的首级，剿匪期间正派的特别任务
    queststring = quests_list[390002];        
  	who->set("quest/index", 113);
   	who->set("quest/type","find");
   	who->set("quest/masterid",me->query("id"));
  	who->set("quest/combat_exp", 390002);
  	who->set("quest/name", queststring[IDX_NAME]);
  	who->set("quest/id", queststring[IDX_ID]);
    who->set("quest/time", (int)time()+atoi(queststring[IDX_TIME]) + IDX_Add_TIME);
  	who->set("quest/reward",5*quest_reward(who,quests_list));
  	
  	str = "听闻朝廷正在剿灭铁掌帮的土匪，我"+me->query("family/family_name")+"历来嫉恶如仇。你速速去取"HIY"铁掌帮副帮主"NOR"的首级来见我！\n";
      message_vision (str,me,who);
       t = atoi(queststring[IDX_TIME]) + IDX_Add_TIME;
       
      sec = t % 60;
      t /= 60;
      min = t % 60;
      t /= 60;
      hour = t % 24;
      t /= 24;
      day = t;
      if(day) time = chinese_number(day) + "天";
      else time = "";
      if(hour) time += chinese_number(hour) + "小时";
      if(min) time += chinese_number(min) + "分";
      time += chinese_number(sec) + "秒";
      tell_object(who,HIW"这项任务必须在" + time + "内完成。\n"NOR);
      return 1;              
  }
  else
  {
      quest_keys = me->query_temp("quest_keys");
      if (! quest_keys)
      {
        quest_keys = sort_quests(quests_list);
        me->set_temp("quest_keys",quest_keys);
      }
      i = quest_accurate_index (quest_keys, who->query("combat_exp"));  
      i = quest_random_index (quest_keys, i, who);
      queststring = quests_list[quest_keys[i]];
  }
  if(queststring[IDX_TYPE]=="find")
    {
    	who->set("quest/index", i);
    	who->set("quest/type","find");
    	who->set("quest/masterid",me->query("id"));
  	who->set("quest/combat_exp", quest_keys[i]);
  	who->set("quest/name", queststring[IDX_NAME]);
  	who->set("quest/id", queststring[IDX_ID]);
        who->set("quest/time", (int)time()+atoi(queststring[IDX_TIME]) + IDX_Add_TIME);
  	who->set("quest/reward",quest_reward(who,quests_list));
  	str = find_strs[random(sizeof(find_strs))]+queststring[IDX_NAME]+
        "，\n这位"+RANK_D->query_respect(who)+
        "能否帮本派做好这件事？\n";
    }   
  else if(queststring[IDX_TYPE]=="give")
    {
    	who->set("quest/index", i);
    	who->set("quest/type","give");
    	who->set("quest/masterid",me->query("id"));
  	who->set("quest/combat_exp", quest_keys[i]);
  	who->set("quest/name", queststring[IDX_NAME]);
  	who->set("quest/id", queststring[IDX_ID]);
  	who->set("quest/objname",queststring[IDX_OBJNAME]);
  	who->set("quest/objid",queststring[IDX_OBJID]);
       who->set("quest/time", (int)time()+atoi(queststring[IDX_TIME]) + IDX_Add_TIME);

  	who->set("quest/reward",quest_reward(who,quests_list));
  	str = give_strs[random(sizeof(give_strs))];
    }   
  else if(queststring[IDX_TYPE]=="kill")
    {
    	who->set("quest/index", i);
    	who->set("quest/type","kill");
    	who->set("quest/masterid",me->query("id"));
  	who->set("quest/combat_exp", quest_keys[i]);
  	who->set("quest/name", queststring[IDX_NAME]);
  	who->set("quest/id", queststring[IDX_ID]);
       who->set("quest/time", (int)time()+atoi(queststring[IDX_TIME]) + IDX_Add_TIME);
  	who->set("quest/reward",quest_reward(who,quests_list));
  	str = kill_strs[random(sizeof(kill_strs))];
    }   
  else if(queststring[IDX_TYPE]=="win")
    {
    	who->set("quest/index", i);
    	who->set("quest/type","win");
    	who->set("quest/masterid",me->query("id"));
  	who->set("quest/combat_exp", quest_keys[i]);
  	who->set("quest/name", queststring[IDX_NAME]);
  	who->set("quest/id", queststring[IDX_ID]);
       who->set("quest/time", (int)time()+atoi(queststring[IDX_TIME] )+ IDX_Add_TIME);
  	who->set("quest/reward",quest_reward(who,quests_list));
  	str = win_strs[random(sizeof(kill_strs))];
    }   
  str = replace_string (str, "$w", queststring[IDX_NAME]);
  str = replace_string (str, "$o", queststring[IDX_OBJNAME]);
  message_vision (str,me,who);
   t = atoi(queststring[IDX_TIME]) + IDX_Add_TIME;
  sec = t % 60;
  t /= 60;
  min = t % 60;
  t /= 60;
  hour = t % 24;
  t /= 24;
  day = t;
  if(day) time = chinese_number(day) + "天";
  else time = "";
  if(hour) time += chinese_number(hour) + "小时";
  if(min) time += chinese_number(min) + "分";
  time += chinese_number(sec) + "秒";
  tell_object(who,HIW"这项任务必须在" + time + "内完成。\n"NOR);
  return 1;
}


int accept_object(object who, object ob)
{
  object me = this_object();
  int t;
  int score;
  int temp,donenumber;
  int exp,pot;
  mapping quest;

  if (who->query("quest/masterid") != me->query("id") 
      || who->query("quest/type") != "find")
      return 0;               

  if (ob->is_character()) return 0;

  if (who->query("quest/name") != ob->query("name"))
  {
    message_vision ("$N对$n说道：这位"+RANK_D->query_respect(who)+
                    "，我需要"+who->query("quest/name")+
                    "，你倒却给我"+ob->query("name")+"，不对不对！\n",me,who);
    return 0;
  }

  if (who->query("quest/id") != ob->query("id"))
  {
    message_vision ("$N对$n说道：这位"+RANK_D->query_respect(who)+
                     "，我需要的是"+who->query("quest/name")+
                    "，东西倒挺象，但不是同一个货；我要的是("+
                    who->query("quest/id")+")，你给的是("+
                    ob->query("id")+")！\n",me,who);
    return 0;
  }
  who->start_busy(2);
  remove_call_out("dest");
  call_out("dest",1,ob);
  if( who->query("quest/time") <  (int)time() )
  {
      tell_object(who,me->query("name")+"叹了口气：真可惜！你没有按时完成！\n");
      who->delete("quest/type");
      who->delete("quest/finish"); 
      return 1;
  }
  tell_object(who,me->query("name")+"说道：恭喜你！你又完成了一项任务！\n");
  who->add("quest/done_number",1);
  
  donenumber = who->query("quest/done_number");
  if (donenumber > 6)
     donenumber = 6;
  quest =  who->query("quest");
  score=random(quest["reward"]);
  if(score==0) score = 1;
  if( who->query("score")>=0 &&
    who->query("score") * who->query("score")/10 >= who->query("combat_exp"))
    {
      command("sigh " + who->query("id"));
      command("say " + RANK_D->query_respect(who) + 
        "经验最好再高些，否则没法体现你的忠诚。\n");
    }
  else
  {
             	tell_object(who,"你对"+who->query("family/family_name")+"的忠诚度提高了"+chinese_number(score)+"点。\n");  
             	if(!who->query("score"))
               		who->set("score",0);
              score = score * SPEWEEK_D->query_menzhong_bonus()/100; //特殊周效果               		
             	who->add("score",score); 
  }
  temp = score*donenumber*3/4 + random(score*donenumber*3/4);
  if (temp == 0) temp = 1;
  tell_object(who,"你的实战经验上升了"+chinese_number(2*temp)+"点。\n");   
  exp = REWARD_D->add_exp(who, 2*temp,"newbie");
  who->add("exp/quest",exp); 
  temp = score*donenumber/4 + random(score*donenumber/4);
  if (temp == 0) temp = 1;
  tell_object(who,"你的潜能增加了"+chinese_number(temp)+"点。\n");      
  pot = REWARD_D->add_pot(who, 2*temp);
  who->add("pot/quest",pot);  
  who->delete("quest/type");
  who->delete("quest/finish"); 
  return 1;
}

void dest(object ob)
{
  destruct (ob);
} 

int ask_cancel()
{
	object me=this_object();
	object who=this_player();   
  if(who->query("family/family_name")!=me->query("family/family_name"))
          {command("? "+who->query("id"));
           command("say "+RANK_D->query_respect(who)+"与本派素无来往，此话从何说起？");
           return 1; 
           }  
  if(!who->query("quest/type")){
  tell_object(who,me->query("name")+"对你说：“你现在没有任务啊？”\n");
  return 1;}  	
  if(!who->query("score"))
  who->set("score",0);
  who->add("score",-3+random(3)); 
  who->delete("quest/type");
  who->delete("quest/finish"); 
  who->delete("quest/time");
	who->set("quest/done_number",0);
	message_vision(me->query("name")+"向$N叹了口气，说道：算了，看来我不应该让你去做这件事。\n", who);
  tell_object(who,"你对"+who->query("family/family_name")+"的忠诚度降低了。\n");  
  return 1;
}


//Created by whuan@pkuxkx
//投名状任务：玩家加入土匪集团，如需取得信任，需要纳投名状
//升级为主流任务 -- jason
/*=======================================================
1. 杀人（北侠现有正派npc）
2. 寻物（系统分配一个物品到一个区域例如扬州，不指定地方，玩家可能要找遍全城方能找到，可能在地上，也可能在npc身上）
3. 劫色（系统分配一个美女，玩家需要去劫色，美女会有保镖随行）
4. 劫镖（系统分配一个镖，到指定地点等候1分钟，会出现镖队，有镖师随行）
=======================================================*/
#define RW_RATE 120 //整体调整奖励比例

inherit NPC;

#include <ansi.h>

#include "allgoodnpc.h"

mixed* npclist_sorted = ({});

int ask_job();  //投名状
int ask_join(); //加入
int ask_fail(); //失败 
int ask_score();//查询
int ask_quit();//退出
int give_reward(object me); //奖励
int chat_for_ad();
mapping find_kill_task(object me);

void create()
{
        set_name("裘千丈", ({ "qiu qianzhang", "qiu","zhang"}) ); //名字可以再改
        set("gender", "男性" );
        set("nickname", "肉掌水底钻");
        set("age", 31);
        set("long", "他有个弟弟叫裘千仞，他还有个妹妹叫裘千尺。他自己，虽然比弟弟\n
多了三千尺，比妹妹更是多了九千尺，手上的功夫呢却比他们稀松至\n
少九万尺。他当然没办法称铁掌水上漂啦，只能算得上是的上是肉掌水底钻。\n");
        set("attitude", "peaceful");
                     
        set("str", 29);
        set("dex", 26);
        set("con", 24);
        set("int", 22);
        set("per", 18);

        set("combat_exp", 20000000);
        set("score", 50000);

        set("shen", -100000);
        set("max_qi", 5000);
        set("max_jing", 2000);
        set("neili",2000);
        set("max_neili",3000);
        set("max_jingli", 1800);

        set_skill("blade",200);
        set_skill("dodge",200);
        set_skill("force",200);
        set_skill("parry",200);
        set_skill("strike",200);
        set_skill("tiezhang-zhangfa",100);
        set_skill("shuishangpiao",200);
        set_skill("huntian-qigong",200);
        map_skill("strike","cuixinzhang");
        map_skill("force","huntian-qigong");
        map_skill("parry","tiezhang-zhangfa");		
        map_skill("strike","tiezhang-zhangfa");	
        map_skill("dodge","shuishangpiao");			     
        prepare_skill("strike", "tiezhang-zhangfa");
        set("inquiry", ([
                "加入" : (: ask_join :),
                "join" : (: ask_join :),
                "投名状" : (: ask_job :),
                "失败" : (: ask_fail :),	   
                "信任度" : (: ask_score :),	             
                "退出" : (: ask_quit :),	                                                    
        ]));
        set("chat_chance",1);
        set("chat_msg",
            ({
            (:chat_for_ad:),
            "不知道这样能不能骗到人来干活哦。。。\n",
            "唉，抓来这么多美女，要哪个呢？\n",
            "听说宝库里有无价之宝，可惜二弟从来不让我进去，嘿嘿。。。\n"
            })
            );
        setup();
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver", 10);
}

int ask_quit()
{
	int exp,pot;
    object me=this_player();
    if(undefinedp(me->query("jiaofei/tmz/xinren")) || me->query("jiaofei/tmz/xinren") <= 0)
    {
        write("裘千丈疑惑的看着你：你小子本来就不是我们一伙的，退出个屁啊！？\n");
    }
    else
    {
        write("裘千丈大笑，想走了？那就滚吧，铺盖卷留下！\n");
		exp = -me->query("jiaofei/tmz/xinren")*100;
		pot = -me->query("jiaofei/tmz/xinren")*50;

        exp = REWARD_D->add_exp(me,exp);
		pot = REWARD_D->add_exp(me,pot);
        write(sprintf("你的经验减少了%d,潜能减少了%d！\n",-exp,-pot));
        me->delete("jiaofei/tmz/xinren");
        me->delete("jiaofei/tmz/join");        
        me->set("jiaofei/tmz/last_quit_time",time());
    }
    return 1;    
}

int ask_score()
{
    object me=this_player();
    if(!undefinedp(me->query("jiaofei/tmz/xinren")) && me->query("jiaofei/tmz/xinren") > 0)
    {
        write(sprintf("你目前对本帮的贡献是:%d\n",me->query("jiaofei/tmz/xinren")));
    }
    else
    {        
        write(sprintf("你屁贡献都没有！\n"));
    }
    return 1;
}

int ask_join()
{
        object ob=this_player(), me=this_object();
        if ((int)ob->query("jiaofei/tmz/join")>0)
        {
            message_vision(HIR"$N怒道：$n你是来消遣老子的么，该干啥干啥去。滚！\n"NOR,me,ob);
            return 1;
        }        

        message_vision(HIR"$N上下左右打量了$n几眼道：想在咋们这里混饭吃，可不容易。\n"+
        "为了显示你的诚意，你必须纳投名状。\n"NOR,me,ob);       		
        ob->set("jiaofei/tmz/join",1); //加入成功，设置标志
        //可以设置改变nick，job_title和title，暂时未加入
        return 1;
}

int ask_job()
{
        object ob=this_player(), me=this_object();
        int jobscore=(int)ob->query("jiaofei/tmz/xinren"); //信任度
        int jobtype;//任务类型，由jobscore决定
        mapping quest1,quest2;//取物和杀人的列表
        object where,box,meinv,biaoche,baobiao,biaoshi,tanzi,*inv;
        string msg,place;
		object npc;

        if (!(int)ob->query("jiaofei/tmz/join"))
        {
            message_vision(HIR"$N瞪大了眼睛喝道：无关人等，给我滚开！投名状是你能问的吗？\n"NOR,me,ob);
            return 1;
        } 
        if ((int)ob->query("jiaofei/tmz/on_job"))
        {
            message_vision(HIR"$N大声骂道：你是在消遣老子吗？上次的投名状你还没有完成呢！\n"NOR,me,ob);
            return 1;
        }        
        
        if(!undefinedp(ob->query("jiaofei/tmz/last_quit_time")) && ob->query("jiaofei/tmz/last_quit_time") + 86400 > time())
        {
            message_vision(HIR"$N破口大骂：你个混球不是刚刚退出本帮了吗？还好意思来找我？比老夫脸皮都厚！ \n"NOR,me,ob);
            return 1;
        }
        
//如果连续问，random(180)没意义，总能刷到很小的数，改成任务完成或失败后加上随机cd，by all@pkuxkx
//      if(!wizardp(ob) && !ob->query_temp("testforwiz") && (int)ob->query("jiaofei/tmz/last_time")+60+random(180)>time())
        if(!wizardp(ob) && !ob->query_temp("testforwiz") && (int)ob->query("jiaofei/tmz/last_time")>time())
        {
            message_vision(HIR"$N摇头道：目前没什么任务可以吩咐你的，你休息一下吧! \n"NOR,me,ob);
            return 1;
        }	
        
        if(jobscore > 10000)
        {
            message_vision(HIR"$N哈哈一笑：好孩子，你做的已经够多了，老夫很喜欢你!下去吧！ \n"NOR,me,ob);
            return 1;
        }

				if(ob->query("combat_exp") < 10000)
				{
            message_vision(HIR"$N把脑袋摇的像拨浪鼓一样：你太弱了，会被人打劫的。\n"NOR,me,ob);
						return 1;
				}

		if(JIAOFEI_D->istaskstart() == 1)
		{
	        message_vision(HIR"$N东张西望了一下：现在朝廷正在攻我铁掌帮，我看要完蛋，趁早逃命吧。 \n"NOR,me,ob);
			return 1;
		}

        
        //分配任务,可以随时调整
        if(random(3) == 0 || random(ob->query("combat_exp")) < 50000 )//1/3概率杀人
        {
            quest2 = find_kill_task(ob);
            if(mapp(quest2) && sizeof(quest2) > 0)
            {
        		ob->set("jiaofei/tmz/jobtype","kill");      
        		ob->set("jiaofei/tmz/name",quest2["name"]);
        		ob->set("jiaofei/tmz/id",quest2["id"]);
	       		ob->set("jiaofei/tmz/exp",quest2["exp"]);
		        ob->set("jiaofei/tmz/on_job",1); //设置一个已经在做任务的mark

        		message_vision("$N沉思了一下对$n说道：你去把"
        		+quest2["name"]+"("+quest2["id"]+")给我干掉，提他的脑袋来见我。\n",me,ob);    

				if(ob->query("combat_exp") < 30000)
				{
					npc = find_living(quest2["id"]);

					if(objectp(npc) && environment(npc) && environment(npc)->isroom() == 1 && npc->query("name") == quest2["name"])
					{
						write("他可能正在"+environment(npc)->query("short")+"一带活动\n");
					}
				}

        		ob->set_temp("jiaofei/tmz/questmsg","你的投名状任务是杀了"+quest2["name"]+"。\n");    		  		
                return 1;        		                
            }
        }
        
        //取物，劫色，劫镖
        jobtype = random(10);
		if(ob->query("combat_exp") > 20000000)
		{
			jobtype = 0;
		}
        //根据分配的结果发放任务
        switch (jobtype)
        {
        	case 0: //劫镖任务
    			case 1:
        		ob->set("jiaofei/tmz/jobtype","jiebiao");
//过滤非法任务地点和不明区域 by segate@pkuxkx
        while (!objectp(where) || 
               !where->isroom()||
               MAP_D->place_belong(where)=="不明区域"||
               base_name(where) == "/adm/daemons/taskd")
        {
          where=MAP_D->random_place_ex(ob); 
        }
//        		where=MAP_D->random_place_ex(ob); 
        		msg=MAP_D->place_belong(where);
        		place=where->query("short");
        		tanzi=new(__DIR__"tanzi");
        		tanzi->set("master",ob->query("id")); //在探子身上设置mark
        		tanzi->start_leave(); //3分钟内产生镖车，如果主人没赶到就会消失
        		if( !tanzi->move(where))
        			{
        				tanzi->move("/d/luoyang/center");
        				msg="洛阳";
        				place="中央广场";
        			}	
        		message_vision("$N对$n道：近期福威镖局生意极好，但是对寨中没什么表示，你去杀他们的威风。\n"
        		+"我已经派了一个探子名叫"+tanzi->name()+"在"+msg+"的"+place+"附近接应，你赶快过去吧。\n",me,ob);	
        		ob->set_temp("jiaofei/tmz/questmsg","你的投名状任务是劫回在"+msg+"出现的镖车。\n");
        		break;
        	case 2: //劫色任务
        	case 3: //劫色任务
        	case 4: //劫色任务
        	case 5: //劫色任务
        		ob->set("jiaofei/tmz/jobtype","jiese");  
//过滤非法任务地点和不明区域 by segate@pkuxkx
        while (!objectp(where) || 
               !where->isroom()||
               MAP_D->place_belong(where)=="不明区域"||
               base_name(where) == "/adm/daemons/taskd")
        {
          where=MAP_D->random_place_ex(ob); 
        }     		
//        		where=MAP_D->random_place_ex(ob); 
        		place=where->query("short");
        		msg=MAP_D->place_belong(where);
        		meinv=new(__DIR__"meinv");
        		meinv->set("master",ob->query("id")); //美女带个保镖玩13分钟，然后消失
        		meinv->destme();
        		if( !meinv->move(where))
        			{
        				tanzi->move("/d/suzhou/canlangting");
        				place="沧浪亭";
        				msg="苏州";
        			}	
        		message_vision("$N奸笑了几声对$n道：我们当家的想找一位压寨夫人。\n有探子探到最近经常有美女在"
        		+msg+"的"+place+"附近游玩，你赶快去把她抢回来。\n",me,ob);	
        		ob->set_temp("jiaofei/tmz/questmsg","你的投名状任务是抢到在"+msg+"游玩的美女。\n");
        		break;      
        	case 6: //寻物任务
        	case 7: //寻物任务
        	case 8: //寻物任务
        	case 9: //寻物任务
        		ob->set("jiaofei/tmz/jobtype","quwu");  
        		box=new(__DIR__"box");
        		box->set("owner",ob->query("id")); //宝物设置一个标记
        		box->set_temp("owner/id",ob->query("id")); //另外一个标记，防止别人乱拿
        		box->destme(); //自动消失
//过滤非法任务地点和不明区域 by segate@pkuxkx
        while (!objectp(where) || 
               !where->isroom()||
               MAP_D->place_belong(where)=="不明区域"||
               base_name(where) == "/adm/daemons/taskd")
        {
          where=MAP_D->random_place_ex(ob); 
        }
//        		where=MAP_D->random_place_ex(ob); 
						if(!MAP_D->place_belong(where))
							{
								box->move("/d/city/bingqiku");//藏在扬州的兵器库，嘿嘿
								msg="扬州";								
							} 
						else
							{
								msg=MAP_D->place_belong(where);
								place=where->query("short");
								if(random(4)) msg=msg+"的"+place; //有一定的几率不知道具体位置
								inv = all_inventory(where);
								if (sizeof(inv) > 0)
								if(random(2))
								{
									if (!box->move(inv[random(sizeof(inv))]))
									{
									box->move(where);			
							  	}
								}
								box->move(where);	
						  }
						 message_vision("$N拍了拍脑袋，说道：对了，前些日子有奸细混入寨中，偷走了一个宝箱，经过"+
						 "\n寨中兄弟多方打探，探到宝箱最近在"+msg+"出现，你去帮忙找回来吧。\n",me,ob);
						 message_vision("$N又补充道：宝箱就不需要了，你把宝箱里面的东西拿回来就可以了。\n"
						 +"$N在$n耳边告诉了开宝箱的方法(unseal box)。\n",me,ob); 	
						 ob->set_temp("jiaofei/tmz/questmsg","你的投名状任务是找回在"+msg+"出现的宝物。\n");
        		break;
        	default: //取物任务
				break;

        }
        ob->set("jiaofei/tmz/on_job",1); //设置一个已经在做任务的mark
        return 1;                	
}

int accept_object(object who, object ob)
{
		object me;				
		string jobtype=who->query("jiaofei/tmz/jobtype");
		me=this_object();

        if (!(int)who->query("jiaofei/tmz/join"))
        {
            message_vision(HIR"$N疑惑道：我跟你非亲非故，你给我这个是干什么？\n"NOR,me,who);
            return 0;
        } 
        if (!(int)who->query("jiaofei/tmz/on_job"))
        {
            message_vision(HIR"$N大声道：老子什么都不缺，谁要你的破烂 ！\n"NOR,me,who);
            return 0;
        }

      	switch (jobtype)
      	{
				case "kill":
      			if (ob->query("id")=="shou ji")
      				{
      					if (ob->query("victim_id")==who->query("jiaofei/tmz/id") && ob->query("kill_by")==who->query("id"))
      					{
      						command("nod "+who->query("id"));
      						give_reward(who);
      						call_out("do_dest", 1, ob);
      				  	return 1;
      				  }
      				  message_vision("$N怒道：你以为胡乱杀个人就能欺骗我吗？\n",me,who);
      				  return 0;
      			  }
      			else
      				message_vision("$N怒道：我让你提他的人头来见我，你给的是什么？\n",me,who);
      				return 0;
      			break; 
      	case "quwu":
      			if (ob->query("id")=="zhenshan zhibao")
      				{
      					if (ob->query("owner")==who->query("id"))
      					{
      						command("thank "+who->query("id"));
      						give_reward(who);
      						call_out("do_dest", 1, ob);
      				  	return 1;
      				  }
      				  message_vision("$N怒道：这又不是你找回来的，你想蒙骗我么？\n",me,who);
      				  return 0;
      			  }
      			else
      				message_vision("$N怒道：什么乱七八糟的东西都给我，你当我这里是捡垃圾的啊？\n",me,who);
      				return 0;
      			break;      				
      	case "jiese":
      			if (ob->is_character())
      				{
      					if (ob->query("id")=="beauty girl" && ob->query("owner")==who->query("id"))
      					{
      						command("wa "+who->query("id"));
      						give_reward(who);
      						call_out("do_dest", 1, ob);
      				  	return 1;
      				  }
      				  message_vision("$N怒道：这是什么乱七八糟的，你想蒙骗我么？\n",me,who);
      				  return 0;
      			  }
      			else
      				message_vision("$N怒道：我让你抢美女，不是让你抢东西？\n",me,who);
      				return 0;
      			break;      		
      	case "jiebiao":
      			if (ob->query("id")=="hong huo")
      				{
      					if (ob->query("owner")==who->query("id"))
      					{
      						command("mobai "+who->query("id"));
      						give_reward(who);
      						call_out("do_dest", 1, ob);
      				  	return 1;
      				  }
      				  message_vision("$N怒道：这又不是你找回来的，你想蒙骗我么？\n",me,who);
      				  return 0;
      			  }
      			else
      				message_vision("$N怒道：什么乱七八糟的东西都给我，你当我这里是捡垃圾的啊？\n",me,who);
      				return 0;
      			break;      		     		      		     			
      	default:
        		tell_object(who,"你的任务好像出错了，请通知巫师。\n");
        		return 0;      		
      		break;
      	}

        return 0;
}
int give_reward(object ob)
{
    object wanzi;
		int reward;//奖励
  	int rexp,rpot,rrep;
   	int rxinren;

		string jobtype = ob->query("jiaofei/tmz/jobtype");
	if (!ob->query("biography/jobs/tmz"))
	{
		ob->set("biography/jobs/tmz",time());//个人传记记录第一次完成任务时间ZINE
	}
	ob->add("newjobs/completed/tmz",1);
		if(jobtype == "kill")
		{
			reward = ob->query("jiaofei/tmz/exp")/10000+random(500)+ob->query("kar")*50;
			if(ob->query("combat_exp") < 100000)
			{
				reward *= 1.5;
			}
		}
		else
		{
			reward=1000;
			reward=reward*ob->query("int")/10;
			reward=reward/2+random(reward/2);
			if(jobtype == "jiebiao")
			{
				reward = reward * 1.3;
			}
		}
		reward=reward*RW_RATE/100;
				
      	if(ob->query("combat_exp")>50000000)	
      		reward= reward/2;
        
        reward = reward + query("jiaofei/tmz/lianxu")*500;
        ob->add("jiaofei/tmz/lianxu",1);
        if(ob->query("jiaofei/tmz/lianxu") >= 9) 
        {
            ob->set("jiaofei/tmz/lianxu",5);
            command("haha");
            command("say "+ob->query("name")+" 你这个小子有两下子啊！");
            reward *= 2;
        }
      	
      	rexp=reward;
      	rpot=reward/3+random(reward/5);
      	rrep=50+random(100); //少量的声望
      	//增加奖励
      	ob->add("combat_exp",rexp);
      	ob->add("potential",rpot);
      	ob->add("repute",rrep);

		ob->add("shen",-random(100));

      	//记录上一次的奖励
      	ob->set("jiaofei/tmz/last_exp",rexp);
      	ob->set("jiaofei/tmz/last_pot",rpot);
      	ob->set("jiaofei/tmz/last_rep",rrep);   
      	   	
        
      	//增加信任度      	
      	if (jobtype == "kill")      //杀人
      	{
            ob->add("shen",-random(10));
      	    rxinren = 2+random(5);      		
      	}
      	else if (jobtype == "quwu") //寻宝
      	{
      	    rxinren = 10+random(10);      	    
      	}
      	else if (jobtype == "jiese") //劫色
      	{
            ob->add("shen",-random(20));
      	    rxinren = 30+random(30);      	    
      	}
        else//劫镖
        {
            ob->add("shen",-random(5));
            rxinren = 60+random(60);            
        }
        
        ob->add("jiaofei/tmz/xinren",rxinren);
      	//记录exp和pot来源
      	ob->add("exp/jiaofei",rexp);
      	ob->add("pot/jiaofei",rpot);
      	//消除mark
      	ob->delete("jiaofei/tmz/on_job");
      	ob->delete("jiaofei/tmz/jobtype");
//     	ob->set("jiaofei/tmz/last_time",time()+30);
      	ob->set("jiaofei/tmz/last_time",time()+90+random(180));      	
		//执行动作
		command("admire "+ob->query("id"));
		write(HIW"你被奖励了"+chinese_number(rexp)+"点经验，"+chinese_number(rpot)+"点潜能，" +chinese_number(rrep)+"点声望。\n"NOR);
        ob->add("balance",15000+random(10000));		
        command("whisper "+ob->query("id")+" 属于你的那份花红，我已经吩咐人存在你户头。");
        command("heihei");
        write(sprintf("你小子还是值得老夫信任的。(+%d)\n",rxinren));

        if(random(ob->query("kar") > 20 && random(6) == 5))
        {
            //有一定几率给一个丸子
            tell_object(ob,query("name")+"对你眨眨眼：我看你小子挺对我胃口的，这个东西给你！\n");
            wanzi = new("/d/xiangyang/npc/obj/shanlw");
            wanzi->move(ob);
        }
        
      	return 1;
}
int ask_fail()
{
				object ob=this_player();
				object me=this_object();
        if (!(int)ob->query("jiaofei/tmz/on_job"))
        {
            message_vision(HIR"$N大声骂道：你是在消遣老子吗？你又没什么任务！\n"NOR,me,ob);
            return 1;
        }        
				message_vision(HIY"$N怒道：我看错你了，原来你这么不中用。\n"NOR,me,ob);

				//损失上次奖励的一半
				if(ob->query("combat_exp") > 2000)
				{
					ob->add("combat_exp",-ob->query("jiaofei/tmz/last_exp")/2);
					//防止判师的bug，有些bt会这么干
					if(ob->query("combat_exp") < 2000) ob->set("combat_exp",2001);

					ob->add("potential", -ob->query("jiaofei/tmz/last_pot")/2);
					ob->add("repute",    -ob->query("jiaofei/tmz/last_rep")/2);
				}

      	//减少5点信任度
      	ob->add("jiaofei/tmz/xinren",-5);
      	//删除标记
      	ob->delete("jiaofei/tmz/on_job");       
      	ob->delete("jiaofei/tmz/jobtype");      
      	//加入等待时间
//     	ob->set("jiaofei/tmz/last_time",time());
      	ob->set("jiaofei/tmz/last_time",time()+60+random(180));      	
      	write(HIW"你的信任度降低了，你受到了惩罚。\n");				
      	write("你的经验降低了"+chinese_number(ob->query("jiaofei/tmz/last_exp")/2)+"点\n");
      	write("你的潜能降低了"+chinese_number(ob->query("jiaofei/tmz/last_pot")/2)+"点\n");
      	write("你的声望降低了"+chinese_number(ob->query("jiaofei/tmz/last_rep")/2)+"点\n");
      	ob->set("jiaofei/tmz/lianxu",0);
				return 1;
}
void do_dest(object ob)
{
        if(!objectp(ob)) return;
        ob->move("/clone/misc/void");
        destruct(ob);
}

int chat_for_ad()
{
    switch(random(200))
    {
    case 1:
        CHANNEL_D->do_channel(this_object(), "bd", "我堂堂当大哥的，却给帮里做这些杂事！哼！");
        break;
    case 2:    
        CHANNEL_D->do_channel(this_object(), "bd", "还好手里钱多，找人帮忙做，嘿嘿！");
        break;
    case 3:
        CHANNEL_D->do_channel(this_object(), "qy", "江湖上的小辈们，来给大爷出力吧，大爷亏待不了你们！");
        break;    
    }
    return 1;
}

int sort_npclist(mapping npc1,mapping npc2)
{
	reset_eval_cost();
	if(!mapp(npc1) || !mapp(npc2)) return 0;
	if(npc1["exp"] > npc2["exp"]) return 1;
	if(npc1["exp"] < npc2["exp"]) return -1;
	return 0;
}
//寻找一个合适的npc去杀
mapping find_kill_task(object me)
{
    mapping quest=([]);
	mapping npc;
	int i;
	int i2=-1;
	int start,end;
	int j =0;

	if(!objectp(me)) return quest;

	if(sizeof(npclist_sorted) == 0)
	{
		npclist_sorted = sort_array(npclist,"sort_npclist");
	}	
	
	start = 0;
	end = sizeof(npclist_sorted)-1;
	i = (end - start)/2;

	while(1)
	{
		//printf("end:%d,start:%d,i:%d\n",end,start,i);
		npc = npclist_sorted[i];

		//printf("%s,%d\n",npc["name"],npc["exp"]);

		i2 = i;
		if(npc["exp"] > me->query("combat_exp") * 2)
		{
			end = i;
			i =  start + (end - start)/2;
		}
		else if(npc["exp"] * 2 < me->query("combat_exp") )
		{
			start = i;
			i = start + (end - start)/2;
		}
		else//ok!
		{
			j = i+(random(2) > 0?1:-1)*random(10);
			if (j >= sizeof(npclist_sorted)) j = sizeof(npclist_sorted) - 1;
			if (j < 0) j = 0;
			quest = npclist_sorted[j];
			//printf("%d %s,%d\n",j,quest["name"],quest["exp"]);
			break;
		}
		if(i2 == i) break;
	}
	return quest;    
}

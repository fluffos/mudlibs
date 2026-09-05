//冰冰 levelup升级npc     
//可以存潜能                                                                                           
//by kiden@pkuxkx                                                                                                
#include <ansi.h>
inherit NPC;                                                                                           

string* gifts =({"str","int","dex","con","kar","per","spi",	}); 
void depositing(string arg,object who);
void withdrawing(string arg,object who);

void create()                                                                                          
{  
                set_name(HIW"冰 冰"NOR, ({ "icer npc"}) ); 
          set("title",HIY"北侠"+HIG"爱心天使"NOR);
	        set("gender","女性");   
	        set("age",25);
	        set("per",40); 
	        set("str",40); 
	        set("int",40); 
	        set("dex",40); 
	        set("con",40); 
	        set("kar",40);
	        set("attitude", "friendly");
	        set("combat_exp", 2000000000);
	        set("apply/attack",  300000); 
	        set("apply/defense", 30000);
	        set("inquiry",([
                "升级":"自己看help kungfu-level",
                "level":"自己看help kungfu-level",
	           ]));
	        set("shen_type",1);set("score",500000);setup();
	        carry_object("/d/huashan/obj/greenrobe")->wear();
}

void init()
{
	        add_action("level_up","levelup"); 
	        add_action("level_query","levelquery"); 
	        add_action("do_deposit","deposit"); 
	        add_action("do_deposit","cun"); 
	        add_action("do_withdraw","withdraw"); 
	        add_action("do_withdraw","qu"); 
	        add_action("do_account","check");
	        add_action("do_account","chaxun"); 
}
int level_query(string arg)
{
        	object me=this_player();
        	int level,exp,gold,repute;
        	string str;
        	if(!arg)
        		{
        		tell_object(me,HIY"请输入一个数字!\n"NOR);
        		return 1;
        		}
        	sscanf(arg,"%d",level);
/*        	if (level>100) 
        	{
        			tell_object(me,HIY"北大侠客行最多支持100级!\n"NOR);
        			return 1;
        	}*/
        	if (level>0 && level<=100 ) 
        	{
        			exp=level*level*level*400;
        			repute=level*20000;
        			gold=level*10;
        			tell_object(me,HIY"升级到"+HIC+level+NOR+HIY"级，需要经验值达到"+HIC+exp+NOR+
        			               HIY",需要声望达到"+HIC+repute+NOR+HIY"，需要缴纳存款"+HIC+gold+HIY"两黄金!\n"NOR);
              tell_object(me,HIY"同时，此次升级需要消耗经验"HIC+level*level*120+
                             HIY"点，声望"HIC+level*200+HIY"点，存款"HIC+level*10+HIY"两黄金。\n"NOR);
        	}
        	else if ( level>100 )
        	{
        			exp=400+(level-100)*(level-100)+10;
        			repute=level*200000;
        			tell_object(me,HIY"升级到"+HIC+level+NOR+HIY"级，需要经验值达到"+HIC+exp+NOR+"M"
        			               HIY",需要声望达到"+HIC+repute+NOR+HIY"，需要缴纳存款"+HIC+level+HIY"块金块!\n"NOR);
              tell_object(me,HIY"同时，此次升级需要消耗经验"HIC+level*level*2000+
                             HIY"点，声望"HIC+level*5000+HIY"点，存款"HIC+level+HIY"块金块。\n"NOR);
          }
        	return 1;	
}

int level_up()
{
	        object me=this_player();
	        int level=(int)me->query("level")+1;
	        int exp,repute,gold;
	        string gift, *tgift;
	        string cgift;
/*	        if (me->query("level")>=100)
	        {
	        		tell_object(me,HIY"对不起，你已经是最高的级别了！\n"NOR);
	        		return 1;
	        }*/
	        if ( level>0 && level <= 100 && me->query("combat_exp")<level*level*level*400 )
	        {
	        	  tell_object(me,HIY"你的经验不够升到下一级，至少需要"+level*level*level*400+"点经验！\n"NOR);	
	        	  return 1;
	        }

	        if ( level>100 && me->query("combat_exp")/1000000<400+(level-100)*(level-100)+10 )
	        {
	        	  tell_object(me,HIY"你的经验不够升到下一级，至少需要"+chinese_number(400+(level-100)*(level-100)+10)+"兆经验！\n"NOR);	
	        	  return 1;
	        }
	        
	        if ( level>0 && level <= 100 && me->query("repute")<level*20000)
	        {
	        	tell_object(me,HIY"你的声望太低了，至少需要"+level*20000+"点声望！\n"NOR);
	        	return 1;	
	        }

	        if ( level > 100 && me->query("repute")<level*200000)
	        {
	        	tell_object(me,HIY"你的声望太低了，至少需要"+level*200000+"点声望！\n"NOR);
	        	return 1;	
	        }
	        
	        if ( level>0 && level <= 100 && me->query("balance")<level*10*10000)
	        {
	        	tell_object(me,HIY"你的存款不够，至少需要"+level*10+"gold的存款！\n"NOR);
	        	return 1;	
	        }

	        if ( level > 100 && me->query("advance_balance")<level)
	        {
	        	tell_object(me,HIY"你的存款不够，至少需要"+level+"块金块的存款！\n"NOR);
	        	return 1;	
	        }
	        
	        
	        if ( level>0 && level <= 100 )
	        {
	          exp=level*level*120;
	          repute=level*200;
	          gold=level*10*10000;
	          me->add("balance",-gold);
	        }
	        else if ( level>100 )
	        {
	          exp=level*level*2000;
	          repute=level*5000;
	          me->add("advance_balance",-level);
	        }
	        
	        me->add("combat_exp",-exp);
			    if(me->query("combat_exp") < 1100)
			    {
				    me->set("combat_exp",1100);
			    }
			
	        me->add("repute",-repute);
	        me->add("level",1);
	        tell_object(me,HIY"恭喜你，你升到了"+level+"级！\n"NOR);
	        if ( (level>me->query("upgrade_no_reward") && level <= 100 && random(5)==3) ||
	        	   level>100 )
	        {
	        	gift=gifts[random(sizeof(gifts))];
	        	if ( me->query(gift)>=50 )
	        	{
	        		tgift=gifts-({gift});
	        		gift=gifts[random(sizeof(gifts))];
	        	}	
	        	if ( level > 100 )
	        	{
	        		me->add(gift,2);
	        		me->add("xiantian/"+gift+"/level",2);
	        	}
	        	else
	        	{
	        	  me->add(gift,1);
	        	  me->add("xiantian/"+gift+"/level",1);
	        	}
	        	if (gift=="str") cgift="膂力";
	        	if (gift=="int") cgift="悟性";
	        	if (gift=="con") cgift="根骨";
	        	if (gift=="dex") cgift="身法";
	        	if (gift=="per") cgift="容貌";
	        	if (gift=="kar") cgift="福缘";
	        	if (gift=="spi") cgift="灵性";
	        	tell_object(me,HIY"你的先天"+cgift+"增加了！\n"NOR);
	        }
	        return 1;
}
int do_deposit(string arg)
{
          int num,gold;
          object who = this_player();
          if(time() <  who->query_temp("deposit_qn_time")+180)
                  return notify_fail("冰冰说道：我刚刚处理过你的业务，你等等再来吧。\n");               
          if(!arg) 
                  return notify_fail("冰冰说道：正确的指令格式是deposit <howmany> pot\n");   
          if(sscanf(arg,"%d pot",num)!=1)  
                  return notify_fail("冰冰说道：正确的指令格式是deposit <howmany> pot\n");   
          if(num >(int)who->query("potential") - (int)who->query("learned_points"))                       
                  return notify_fail("冰冰说道：你没那么多潜能，再拿我冰冰开玩笑小心你屁股开花！\n");       
          //至少保留3000点pot不能存
          if(num >(int)who->query("potential") - (int)who->query("learned_points") - 3000)                       
                  return notify_fail("冰冰说道：你至少保留3000点潜能，我冰冰可不是万能保险箱！\n");       
          if(num < 10000) 
                  return notify_fail("冰冰说道：这么点儿潜能你还是留着自个慢慢花吧！\n");       
          gold = num;
          if(who->query("balance") < gold)        
                  return notify_fail("冰冰打开电脑查了查说：你银行的存款不足以支付保管费吧！\n");         
          tell_object(who,"你确实要存储"+num+"点潜能吗？(yes/no)\n");
          who->set_temp("deposit_qn_num",num);
          input_to( (: depositing :), who);  
          return 1;               
}
void depositing(string arg,object who)
{
          int num;
          if(arg!="y"&&arg!="yes")
          return ;
          num = who->query_temp("deposit_qn_num");
          who->add("deposit_qn_num",num);
          who->add("balance",-num);
          who->add("potential",-num);
          this_object()->command("interest icer npc");
          tell_object(who,"你将"+num+"点潜能让冰冰保管，同时缴纳了保管费。\n");
          who->delete_temp("deposit_qn_num");
          who->set_temp("deposit_qn_time",time());
          who->save();
}
int do_withdraw(string arg)
{
          int num,gold;
          object who = this_player();
          if(time() <  who->query_temp("deposit_qn_time")+180)
                  return notify_fail("冰冰说道：我正在处理业务，你等等再来吧。\n");       
          if(!arg) 
                  return notify_fail("冰冰说道：正确的指令格式是withdraw <howmany> pot\n");  
          if(sscanf(arg,"%d qn",num)!=1)  
                  return notify_fail("冰冰说道：正确的指令格式是withdraw <howmany> pot\n");  
          if(!who->query("deposit_qn_num"))
                  return notify_fail("冰冰疑惑地说道：你有存过潜能吗？\n");   
          if(num >(int)who->query("deposit_qn_num"))                      
                  return notify_fail("冰冰说：你目前只有"+who->query("deposit_qn_num")+"点潜能存着！\n"); 
          if(num<0)
                  return notify_fail("冰冰说道：你吃饭没？没吃回家吃去吧！\n");       
          who->set_temp("deposit_qn_num",num);
          tell_object(who,"你确实要提取"+num+"点潜能吗？(yes/no)\n");
          input_to( (: withdrawing :),who);
          
          return 1;               
}
void withdrawing(string arg,object who)
{
          int num;
          if(arg!="y"&&arg!="yes")
          return ;
          num =   who->query_temp("deposit_qn_num");
          who->add("deposit_qn_num",-num);
          if(who->query("deposit_qn_num")==0)
                  who->delete("deposit_qn_num");
          who->set("potential",who->query("potential") + num);
          this_object()->command("poor1 zong guan");
          tell_object(who,"你提取出"+num+"点潜能。\n");
          who->delete_temp("deposit_qn_num");
          who->set_temp("deposit_qn_time",time());
          who->save();  
}
int do_account()
{
           object who = this_player();
           message_vision(this_object()->name()+"告诉$N：你目前有"+who->query("deposit_qn_num")+"点潜能存在此处。\n",who);
           return 1;
}

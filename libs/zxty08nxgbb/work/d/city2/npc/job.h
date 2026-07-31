#include <ansi.h>
#include <localtime.h>

int get_mission();
int get_jiangli(object who,int i);
void set_fail_data(object who);
void set_succ_data(object who);
string time_period(int timep, object me);

//#define MISSION_D "/adm/daemons/missiondkqw"

//#ifdef debug_lj

#define MISSION_TIME 3*60

//#else

//#define MISSION_TIME 6*60

//#endif


int get_mission()
{
	object me,killer;
	int combatexp, timep;
	string missiondata;
	string filename,cname,id,party;
	string time;
	int level;
	mapping quest = (__DIR__"where")->query_quest();

	me = this_player();
	combatexp = (int)me->query("combat_exp");

// Let's see if this player still carries an un-expired task
	if( me->query("mission/kangqw"))
	{
		timep = me->query("mission/kangqw_time")-time();
		if ( timep<10 )
			message_vision("康亲王对$N怒道：时间紧迫，你还在这里磨蹭个什么！\n", me);
		else	
			message_vision("康亲王对$N不耐烦地说: 你已经领取了任务，抓紧在"+time_period(timep, me)+"内办好吧！\n", me);
		return 1;
	}
	
	if ( me->query("mission/kangqw_time")>time() )
	{
		message_vision("康亲王对$N淡淡地道：阁下一路辛苦了，还是先去歇息一会罢！\n", me);
		return 1;
	}
	/*
	missiondata = MISSION_D->Get_a_char_mission(combatexp,"all");

	if ( !stringp(missiondata))
	{
		message_vision("康亲王对$N冷冷地道: 朝廷暂时没什么任务给你，你先退下罢！\n", me);
		return 1;
	}
	
	if ( sscanf(missiondata,"%s@@%s(%s)@@%s@@%d",filename,cname,id,party,level) != 5 )
	{
		write(RED"对不起，任务系统数据库有问题，请向巫师质询！\n"NOR);
		command("sorry "+me->query("id"));
		return 1;
	}*/
	
	killer=new(__DIR__"kang_killer");
	killer->set("id",killer->query("id")+"["+me->query("id")+"]");
  killer->move(quest["place"]);

	timep = random(MISSION_TIME)+MISSION_TIME/2;
	//for test
	/*tell_object(me, "test start\n");
	command("say "+filename);
	command("say "+cname);<input type="image" src="">
	command("say "+party);
	command("say "+level);*/
	//test over
	time = time_period(timep, me); 
	tell_object(me, "康亲王想了想道：听说有个叫『" + sprintf("%s(%s)",killer->query("name"),killer->query("id"))+ "』的人蓄谋已久，欲对我大清不利，
那你就在" + time + "内干掉此人，提头来见吧！\n" NOR);
/*	
#ifdef debug lj
	tell_object(me, "That is test version time , the real run time is 2 times of now!\n");
#endif	*/
	command("whisper "+me->query("id")+" 听说他出没在"+quest["short"]+"附近，你可以去那里寻找！");
	command("push "+me->query("id"));

	me->set("mission/kangqw", 1);
	me->set("mission/kangqw_time", (int)time() + timep);
	return 1;
}

string time_period(int timep, object me)
{
	int t, d, h, m, s;
	string time;
	t = timep;
	s = t % 60;             t /= 60;
	m = t % 60;             t /= 60;
	h = t % 24;             t /= 24;
	d = t;

	if(d)
		time = chinese_number(d) + "天";
	else
		time = "";

	if(h)
		time += chinese_number(h) + "小时";
	if(m)
		time += chinese_number(m) + "分";
	time += chinese_number(s) + "秒";
	
	return time;
}

int accept_object(object who, object ob)
{
	int exp, pot, shen,factor,money,gongji,gongji2;		
	string missiondata;
	object mm,killer;
	//mapping mbonus;
	string filename,cname,id,party;
	string temp;
	int level,i,miss_count;
	int jd=0,no_getdrop=0,bought=0,unique=0;
	gongji = (int)who->query("mark/achievement");
	
	//who=this_player();
	
	//if(!(missiondata =  who->query("mission/kangqw")))
	if (!who->query("mission/kangqw"))
	{
		message_vision("康亲王喝道：你竟然想行贿本王？真是岂有此理！\n", who);
		command("die "+who->query("id"));
		return 0;
	}

	who->delete("mission/kangqw");

	if ((int) who->query("mission/kangqw_time") < time() )
	{
		message_vision("康亲王冷冷地道：你动作如此之慢，实在让我失望！\n", who);
		//set_fail_data(who);
		return 1;
	}
	/*
	if ( sscanf(missiondata,"%s@@%s(%s)@@%s@@%d",filename,cname,id,party,level) != 5 )
	{
		write(RED"对不起，您的任务数据有问题，请向巫师质询！\n"NOR);
		command("sorry "+who->query("id"));
		return 1;
	}*/

	if (ob->query("owner_id")!=id)
	{
		message_vision("康亲王怒道：这是我想要的吗？！\n", who);
		//set_fail_data(who);
		return 0;
	}
	
	if (ob->query("killedby")!=who->query("id"))
	{
		message_vision("康亲王瞪了$N一眼：这是你自己杀的？！\n", who);
		//set_fail_data(who);
		return 0;
	}
	
	/*mbonus = MISSION_D->Finish_char_Mission(filename,party,level);

	if ( !mapp(mbonus) )
	{
		write(RED"对不起，任务系统数据库有问题，请向巫师质询！\n"NOR);
		command("sorry "+who->query("id"));
		return 1;
	}*/

	command("haha "+who->query("id"));
	command("say 干的不错，果然没有让本王失望，朝廷绝不会亏待你的！\n你想要功绩(1)、神(2)还是潜能(3)呢？想好了就告诉本王。");
	//command("say 你想要功绩(1)、神(2)还是潜能(3)呢？想好了就告诉本王。");

	input_to("select_gift",who);
	call_out("destory", 1,ob);
	return 1;
}

void select_gift(string arg,object who)
{
        int i;

        if (!sscanf(arg,"%d", i) || i < 1 || i > 3) 
        {
                write("\n输入错误，请输入（1~3）：");
                //input_to("select_gift", who,mbonus);
                input_to("select_gift", who);
                return;
        }
       
        else get_jiangli(who, i);
}

//int get_jiangli(object who,int i,mapping mbonus)
int get_jiangli(object who,int i)
{
	mixed *local = localtime(time());
	int exp, shen,factor,money,gongji,gongji2,pot;		
	string missiondata;
	object mm;
	//mapping mbonus;
	string filename,cname,id,party;
	int level,miss_count;
	int no_getdrop=0,bought=0;
	gongji = (int)who->query("mark/achievement");
	
	//  计算附加奖励值
	//mbonus = MISSION_D->Finish_char_Mission(filename,party,level);
	/*if ( !mapp(mbonus) )
	{
		write(RED"对不起，任务系统数据库有问题，请向巫师质询！\n"NOR);
		command("sorry "+who->query("id"));
		return 1;
	}*/
	/*factor = mbonus["bonus"];

#ifdef debug lj
	printf("%O\n",mbonus);
#endif
	miss_count = (int)who->query("mission/miss_count");
	if ( miss_count < 0 )
		factor -= sqrt(-1*miss_count)*5>20?20:sqrt(-1*miss_count)*5;
	else 
		factor += sqrt(miss_count)*10>50?50:sqrt(miss_count)*10;
	
	if (no_getdrop) factor+=10;
	if (bought) factor-=10;

#ifdef debug lj
	printf("%O\n",factor);
#endif


	exp = factor*mbonus["exp"]/100;
	shen= factor*mbonus["shen"]/20;
	money= factor*mbonus["money"]/100;
	*/
	exp = (who->query("int") + who->query("kar"))*(5+random(5));
	shen = (int)(who->query("shen")/10);
	money = 100+random((int)(who->query("kar")));
	pot = (int)(who->query("potential")/100)+random((int)(who->query("kar")));
	
	
		// 每晚 19:00 到 22:00 VIP用户有双倍奖励 by Amis@xajh2 
        if( local[LT_HOUR] > 19 && local[LT_HOUR] < 22 ) 	
				{
                                        if (who->query("vip/vip")==1) {
					exp = exp * 2;
					shen = shen *2;
					pot = pot * 2;
					money = money * 2;
					}
				}
				
	//强制增加exp
	who->set("combat_exp",who->query("combat_exp")+exp);

//#ifndef debug lj

	if (i==1)
	{	
		if ( gongji < 1000 )
		gongji2 = 3 + random(5);
		else gongji2 = (int)exp/200;
	
		if ( gongji2 < 1) gongji2=1;
			
		who->set("mark/achievement",gongji+gongji2);
		
		tell_object(who,HIW"恭喜，你被奖励了：" + 
			HIM+chinese_number(exp) + "点实战经验!\n"NOR);
			
		tell_object(who,HIY"\n你的功绩提升了！\n"NOR);
	}
	
	if (i==2)
	{
	if(who->query("shen")>=0)
		who->set("shen",who->query("shen")+shen);
	else
		who->set("shen",who->query("shen")-shen);
		tell_object(who,HIW"恭喜，你被奖励了：" + HIM+chinese_number(exp) + "点实战经验，"+
			HIM+chinese_number(shen)+"点神!\n"NOR);
	}
	
	if (i==3)
	{
	/*mm=new("/clone/money/gold");
	mm->set_amount(money);
	mm->move(who);*/
	who->add("potential",pot);
	tell_object(who,HIW"恭喜，你被奖励了：" + HIM+chinese_number(exp) + "点实战经验，"+
			HIM+chinese_number(pot)+"点潜能！\n"NOR);
	}
	
        //set_succ_data(who);

/*#endif
	
#ifdef debug lj
	tell_object(who,HIR"But i am very sorry to say that that is a test version.\nSo you got nothing indeed!\n"NOR);
#endif*/
	return 1;

}
/*
void set_fail_data(object who)
{
	int c;

#ifdef debug lj
        return ;
#endif

	if (!intp(c=who->query("mission/miss_count")))
		c=0;
	if ( c > 0 ) c=-1;
	else c--;
	who->set("mission/miss_count",c);
	return;
}

void set_succ_data(object who)
{
	int c;

#ifdef debug lj
        return ;
#endif

	if (!intp(c=who->query("mission/miss_count")))
		c=0;
	if ( c < 0 ) c=1;
	else c++;
	who->set("mission/miss_count",c);
	return;
}*/

void destory(object ob)
{
     destruct(ob);
}	
	

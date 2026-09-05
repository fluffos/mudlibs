//newbiequest.h
//seagate@pkuxkx 2010/10/15
//bug修正：2010/11/01 seagate@pkuxkx 
//  修正时辰限制类任务发布的时候任务会出现间隔过短的情况，要保证时辰类任务在一次天气变换中只能接受一次。

//从继承文件修改成头文件，将和新手任务分配，初始化，奖励，失败相关的处理集成在本头文件中
//本头文件一共提供7个函数，其中
//newbie_quest()函数是新手任务的分配函数，是接任务的入口函数，只要你实现newbie_list对象就能自动分配任务
//cancel_newbie()函数是新手任务的取消函数，是取消任务的入口函数，负责公共资格检核和调度具体失败任务函数指针
//over_newbie()函数是新手任务的成功函数，是任务成功的入口函数，负责任务成功的公共资格检核和调度具体任务成功奖励函数指针
//newbieDesc()函数是更新新手任务特定任务的任务提示信息，主要是为quest等第三方命令显示任务提示信息使用
//newbieStart()函数是任务信息初始化函数，接到具体任务以后先调用此函数初始化公共新手任务属性，然后再自己具体初始化特色属性
//newbieFail()函数是任务取消的时候清理公共新手任务属性
//newbieEnd()函数是任务成功的时候新手任务奖励函数和处理公共新手任务属性
//新手任务必须自己设置newbie_list变量设置自己的具体任务信息方便公共函数自动调度分配具体任务
//newbie_list的key值是唯一的questid，value是一个映射，包含下列属性：
//start,fail,end,name,weight,reward,explimit,shichen。
//其中start，fail，end分别对应任务发起，任务失败，任务结束的函数指针，
//系统会自动根据函数指针调度特定任务的任务处理函数，weight是任务权重，权重值越高的任务出现的频率越高，
//任务分配的时候根据不同任务的权重比值来确定各个任务的出现频率，reward是奖励系数，决定具体任务在结束时候奖励经验和潜能的
//系统，100是基准系数，explimit是可选参数，表示从多少经验开始可以接这个任务，经验不到任务分配的时候会自动过滤该任务。
//shichen是关于时间限制方面的设定，值为整数array，存放任务在游戏里面那个时辰发布，采用24小时制，1-24小时分别对应到
//NATURE_D里面的对应时辰。

/*新手任务开始的时候初始化玩家属性的函数，输入参数为任务名称和任务ID*/
void newbieStart(string name,string id)
{
	mapping newbie;
	object me,ob;
	
	me=this_player();
	ob=this_object();
	
	if(mapp(me->query_temp("newbie_quest")))
		newbie=me->query_temp("newbie_quest");
	else
		newbie=([]);
	
	newbie["promoter"]=ob->query("name");
	newbie["promid"]=ob->query("id");
	newbie["name"]=name;
	newbie["time"]=time();
	if(!intp(newbie["times"]))
		newbie["times"]=0;
	newbie["success"]=0;
	newbie["id"]=id;
	
	me->set_temp("newbie_quest",newbie);
//增加常驻属性newbietime存放任务时间
	me->set("newbie_quest/time",time());
}

//将新手任务的任务提示描述写入临时数据区方便quest查询
void newbieDesc(string desc)
{
	object me;
	
	me=this_player();
	me->set_temp("newbie_quest/desc",desc);
}

/*新手任务结束的时候清理玩家属性的函数，并给予玩家一定奖励。肯定奖励经验和潜能，每5次奖励一定门忠。
  随机奖励一定量的金钱。*/
void newbieEnd(int reward)
{
	mapping newbie;
	object me,ob;
	int exp,pot,score;
	float batExp;
	
	me=this_player();
	ob=this_object();
	newbie=me->query_temp("newbie_quest");
	
	newbie["times"]=newbie["times"]+1;
	newbie["success"]=1;
	
	batExp=to_float(me->query("combat_exp"));
	if(batExp<1000)
		exp=150+random(100);
	else if(batExp<100000)
		exp=200+random(to_int(50*(log(batExp)-3)));
	else if(batExp<5000000)
		exp=600+random(to_int(100*(log(batExp/1000)-3)));
	else
		exp=800+random(to_int(100*(log(batExp/10000)-5)));

//接受任务奖励系数的调节
  exp=exp*reward/100;
	pot=exp/3;

//每五轮奖励一次门忠，门忠基本上在1-10之间分布，具体由自然对数决定。门忠奖励不受调节系数约束
	if(newbie["times"]%5==0)
		score=random(to_int(log(to_float(me->query("combat_exp")))/2))+1;
	else
		score=0;
	
//	me->add("combat_exp", exp);
	exp = REWARD_D->add_exp(me,exp);
//	me->add("potential", pot);
	pot = REWARD_D->add_pot(me,pot);
	me->add("score", score);
//	ob=new("/clone/money/silver");
//  ob->set_amount(50+random(25)*(random(newbie["times"]%5)+1));
//  ob->move(me);
//只奖励1M以下玩家金钱奖励
  if ( batExp<=1000000 )
    REWARD_D->add_money(me,5000+random(2500)*(newbie["times"]%5+1));
  
	tell_object(me, ob->query("name")+"对"+RANK_D->query_respect(this_player())+"拱了拱手，由于你在"+newbie["name"]+"中的表现特奖励：\n");
	tell_object(me, "      "+chinese_number(exp)+"点经验。\n");
	tell_object(me, "      "+chinese_number(pot)+"点潜能。\n");
	if(score)
		tell_object(me, "      "+chinese_number(score)+"点门忠。\n");

  CHANNEL_D->do_channel(this_object(), "sys_misc",sprintf("%s%s入门任务中获得经验%d，潜能%d，门忠%d。", me->name(),me->query("family/family_name"),exp, pot, score));
/*加入任务统计系统
  COMBAT_D->add("task_stat/newbie/complete_times",1);
  COMBAT_D->add("task_stat/newbie/cost_time",time()-newbie["time"]);
  COMBAT_D->add("task_stat/newbie/exp",exp);
  COMBAT_D->add("task_stat/newbie/pot",pot);
  COMBAT_D->add("task_stat/newbie/repute",0);
	COMBAT_D->add("task_stat/newbie/expratio",to_float(exp)/me->query("combat_exp"));*/
	me->add("jobs/completed/newbie",1);
  
	me->delete("newbie_quest/fail/"+newbie["id"]);
	map_delete(newbie,"name");
	map_delete(newbie,"id");
	me->delete("newbietime");
	me->set_temp("newbie_quest",newbie);
//减少物品掉率几率，并且只奖励1m以下玩家物品奖励
	if ( batExp<=1000000 && random(2) )
	  GEM_D->drop(this_object(),me);
}

/*新手任务失败，相关临时状态清零。*/
void newbieFail()
{
	mapping newbie;
	object me,ob;
	
	me=this_player();
	ob=this_object();
	newbie=me->query_temp("newbie_quest");
	me->add("newbie_quest/fail/"+newbie["id"],1);
	newbie=(["time":newbie["time"]]);
	
	me->set_temp("newbie_quest",newbie);
}

//本函数只负责任务调配，具体的任务产生由相应任务的头文件决定
//新手任务公共信息写作newbie_quest下面，具体任务的信息写入方式由具体任务掌管。
//newbie_quest正常包含任务名称、起始任务时间、发布人名称、发布人id、已完成任务数。
//newbie_quest属性由具体任务初始化函数调用公共新手任务初始化函数newbieStart()更新
//每个任务对应的接任务函数调用的时候都要有参数1：任务名称和参数2：任务id
string newbie_quest()
{
	string questid,*qlist,*aNature;
	int weight,randQuest,lp,*newbie,exp,*aHour,hh24;
	mapping fam;

//时辰设置，将24小时对应游戏里面NATURE_D的实际时间
	string *shichen=({
		"event_midnight", "event_midnight", "event_dawn", "event_dawn",
		"event_dawn", "event_dawn", "event_sunrise", "event_sunrise",
		"event_morning", "event_morning", "event_morning", "event_noon",
		"event_noon", "event_noon", "event_afternoon", "event_afternoon",
		"event_afternoon", "event_evening", "event_evening", "event_evening",
	  "event_night", "event_night", "event_midnight", "event_midnight"});
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != query("family/family_name"))
		return RANK_D->query_respect(this_player()) + 
		"与本派素无来往，不知此话从何谈起？";
	else if(stringp(this_player()->query_temp("newbie_quest/name")))
		return RANK_D->query_respect(this_player()) + "还有任务在身，请完成以后再领新任务。";
	else if(time()-this_player()->query("newbie_quest/time")<160+(this_player()->query("jobs/complete/newbie")-400)/10)
		return "现在还没有新的工作可以分配给你，请稍等。";
	else if(this_player()->is_busy())
		return "你现在正忙着呢。\n";
	else if(this_player()->is_fighting())
		return "请在战斗结束后再找我要任务吧！\n";
	
	weight=0;
	newbie=allocate(sizeof(keys(newbie_list)));
	qlist=allocate(sizeof(keys(newbie_list)));
	lp=0;
	exp=this_player()->query("combat_exp");

	foreach(questid in keys(newbie_list)) {
//加入对时间限制的支持，可以限制1天中那个时辰发布任务
		if((aHour=newbie_list[questid]["shichen"])&&arrayp(aHour)) {
			aNature=({});
			foreach(hh24 in aHour) {
			  if(hh24>24||hh24<1)
			  	error("任务"+questid+"的时间设置有问题，时间只能选择1点到24点。\n");
			  if(member_array(shichen[hh24-1], aNature)==-1)
			  	aNature+=shichen[hh24-1..hh24-1];
			}
			if(member_array(NATURE_D->outdoor_room_event(),aNature)==-1)
				continue;
			if(time()-this_player()->query_temp("newbie_quest/shichen_time")<=300)
				continue;
		}
		
//加入对经验限制的支持，当newbie_list里面具体任务设置中包含explimit	属性的时候
//进行经验检核，只要当经验超过explimit属性值的时候才将该任务加入分配列表		
		if(!newbie_list[questid]["explimit"]||
			 (intp(newbie_list[questid]["explimit"])&&
			  exp>=newbie_list[questid]["explimit"])) {
//失败一次增加该任务10%权重
			newbie[lp]=newbie_list[questid]["weight"]*(100+this_player()->query("newbie_quest/fail/"+questid)*10)/100;
			qlist[lp]=questid;
			weight=weight+newbie[lp];
			lp++;
	  }
	}
	
	if(!lp)
		return "目前没有任务可以分配给你。";
	
	randQuest=random(weight);
	for(lp=0;lp<sizeof(newbie);lp++) {
		if(randQuest<newbie[lp]) {
			questid=qlist[lp];
			break;
		}
		else
			randQuest=randQuest-newbie[lp];
	}
//记录时辰类任务的时间，防止时辰限制类任务在一个时辰内被多次接到。
	if(newbie_list[questid]["shichen"])
		this_player()->set_temp("newbie_quest/shichen_time",time());

//修改start属性里面函数指针定义，包含入口参数，evalute调度的时候就不需要考虑参数问题	
	return evaluate(newbie_list[questid]["start"]);//,newbie_list[questid]["name"],questid);
}

//本任务是任务取消的时候资格审核和调度具体任务的取消函数指针
string cancel_newbie()
{
	mapping fam;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != query("family/family_name"))
		return RANK_D->query_respect(this_player()) + 
		"与本派素无来往，不知此话从何谈起？";
	else if(!mapp(this_player()->query_temp("newbie_quest"))||!stringp(this_player()->query_temp("newbie_quest/id")))
		return "你没有领任何新手任务。";
	
	return evaluate(newbie_list[this_player()->query_temp("newbie_quest/id")]["fail"]);
}

//本函数负责调度对应任务的奖励函数，入口参数为奖励系数，奖励系数高于100表示获得比基数更高的超额奖励。
string over_newbie()
{
	string questid;
	mapping fam;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != query("family/family_name"))
		return RANK_D->query_respect(this_player()) + 
		"与本派素无来往，不知此话从何谈起？";
	else if(!mapp(this_player()->query_temp("newbie_quest"))||!stringp(this_player()->query_temp("newbie_quest/id")))
		return "你没有领任何新手任务。";
	else if(this_player()->query_temp("newbie_quest/success"))
		return "你已经领完奖了！";

	questid=this_player()->query_temp("newbie_quest/id");
	return evaluate(newbie_list[questid]["end"],newbie_list[questid]["reward"]);
}
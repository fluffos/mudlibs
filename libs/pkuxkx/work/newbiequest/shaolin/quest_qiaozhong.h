//qiaozhong.h
//敲钟任务的特殊函数库。（实际上包括钟楼的敲钟和鼓楼的击鼓两种，不过流程一样而已）
//seagate@pkuxkx 2010/10/09

void in_xuqi(object,int,int);

//敲钟任务的实际执行过程，正常包括蓄气和敲钟两个部分，需要你根据蓄气的提示来执行
//选择是否敲钟，蓄气分三种阶段：蓄气初期，蓄气中期和蓄气后期，分别对应50%，80%和
//100%的成功率，出现几率分别是70%，20%和10%。敲钟一般要求连续九次成功才行，所以
//正确选择对应的蓄气提示非常重要。
//敲钟失败会伤内力，成功没有任何消耗，并且增加一定小点的基本内功（最高150级）。
//敲钟的临时状态写在set_temp("quest_qiaozhong")下面，正常有如下标志
//start                                       1或者没有表示任务起始
//room                                        敲钟地点
//name                                        敲钟还是击鼓
//xuqi                                        1或者没有，表示是否处于蓄气状态
//xuqival                                     蓄气值，0到1000之间
//knocked                                     1或者没有，表示当次蓄气状态是否敲过钟了。
//knocks                                      连续敲钟的次数
//times                                       需要敲钟的次数，默认值是9次
//promoter                                    任务发起人
int do_qiaozhong()
{
	object me,ob;
	mapping knock;
	int rand,neili;
	
	me=this_player();
	ob=this_object();
	neili=me->query("max_neili");

	if(!me->query_temp("quest_qiaozhong")||!me->query_temp("quest_qiaozhong/start"))
		return -1;
	
	knock=me->query_temp("quest_qiaozhong");
	if(knock["room"]!=ob->query("short")) {
		message_vision(HIG"$N的入门任务-"+knock["name"]+"任务要求$N去"+knock["room"]+"！\n"NOR, me);
		return -1;
	}
	else if(!knock["xuqi"]) {
		message_vision("$N没有蓄气(xuqi)就开始"+knock["name"]+"，软绵绵地估计连$N自己都听不见。\n", me);
		return 0;
	}
	else if(knock["knocked"]) {
		message_vision("$N一口气下想多做几次"+knock["name"]+"，导致气息混乱看来又要重新开始了。\n", me);
		knock["knocks"]=0;
		knock["xuqi"]=0;
		me->set_temp("quest_qiaozhong/xuqi_end",1);
//		remove_call_out("in_xuqi");
		me->set_temp("quest_qiaozhong",knock);
		if(neili>=100)
			me->add("neili",(-1)*(20+random(10)));
		return 0;
	}
	else if(knock["knocks"]>=knock["times"]) {
		message_vision("$N已经做了"+chinese_number(knock["knocks"])+"次"+knock["name"]+"，现在全寺的僧众应该都听见了。\n", me);
		me->set_temp("quest_qiaozhong/success",1);
		return 1;
	}
	else if(neili>=100&&me->query("neili")<100) {
		tell_object(me, "你的真气不足，先恢复恢复真气再说吧。\n");
		return 1;
	}
	
	rand=random(1000);
	if((knock["xuqival"]<=700&&rand<=500)||
		 (knock["xuqival"]>700&&knock["xuqival"]<=900&&rand<=800)||
		 (knock["xuqival"]>900)) {
		knock["knocks"]++;
		if(knock["name"]=="敲钟")
			message_vision("咣的一声巨响差点把$N自己都吓坏了，$N已经连续敲了"+chinese_number(knock["knocks"])+"次钟了。\n", me);
		else
			message_vision("咚的一声巨响差点把$N自己都吓坏了，$N已经连续击了"+chinese_number(knock["knocks"])+"次鼓了。\n", me);

		knock["knocked"]=1;
		if(knock["knocks"]>=knock["times"]) {
			message_vision("$N已经完成"+knock["promoter"]+"交待的任务了，可以回去领赏了。\n", me);
			knock["success"]=1;
		}
		
		if(me->query_skill("force", 1)<=150) {
			message_vision("$N在蓄气的过程中对真气的运用又有了更深的领悟。\n", me);
			me->improve_skill("force", 10+me->query_skill("force", 1)/(random(3)+1));
		}
	}
	else if(knock["xuqival"]<=700&&rand>500) {
		knock["knocks"]=0;
		knock["xuqi"]=0;
		me->set_temp("quest_qiaozhong/xuqi_end",1);
//		remove_call_out("in_xuqi");
		if(neili>=100)
			me->add("neili",(-1)*(20+random(10)));
		message_vision("$N还没有蓄足气就开始用力，气息已经混乱，还是休息休息再来吧。\n", me);
	}
	else if(knock["xuqival"]>700&&knock["xuqival"]<=900&&rand>800) {
		knock["knocks"]=0;
		knock["xuqi"]=0;
		me->set_temp("quest_qiaozhong/xuqi_end",1);
//		remove_call_out("in_xuqi");
		if(neili>=100)
			me->add("neili",(-1)*(20+random(10)));
		message_vision("$N蓄气过猛，气息已经混乱，还是休息休息再来吧。\n", me);
	}
	me->set_temp("quest_qiaozhong",knock);
	return 1;
}

//蓄气开始函数，作用是置蓄气标志，并且进行蓄气轮询
//蓄气结束会伤内力！
int do_xuqi(string arg)
{
	object me;
	me=this_player();
	
	if(!me->query_temp("quest_qiaozhong")||!me->query_temp("quest_qiaozhong/start"))
		return notify_fail("你还没有领敲钟任务，不能蓄气敲钟。\n");
	else if(!arg||(arg!="start"&&arg!="end"))
		return notify_fail("命令格式：xuqi start|end，来表示蓄气开始和蓄气结束。\n");
	else if(me->is_busy()&&arg=="start")
		return notify_fail("你现在正忙着呢。\n");
	else if (me->is_fighting())
		return notify_fail("你无法在战斗中进行蓄气！\n");
  else if (!me->query_temp("quest_qiaozhong/xuqi")&&arg=="end")
  	return notify_fail("你没有处于蓄气状态，也不用结束蓄气状态。\n");
	
	if(arg=="start") {
		me->set_temp("quest_qiaozhong/xuqi",1);
		me->delete_temp("quest_qiaozhong/xuqi_end");
		me->set_temp("quest_qiaozhong/xuqi_room", environment(me));
		me->start_busy(10);
		in_xuqi(me,0,0);
  }
  else {
  	me->set_temp("quest_qiaozhong/xuqi", 0);
		me->set_temp("quest_qiaozhong/knocks", 0);
  	me->start_busy(1);
  	me->set_temp("quest_qiaozhong/xuqi_end",1);
//  	remove_call_out("in_xuqi");
  	message_vision("$N站起来，缓缓地收回全身真气，结束了这一轮蓄气。\n", me);
  }
  
	return 1;
}

//蓄气第一轮将按照颜色和蓄气显示一一匹配的规则来完成蓄气，但是从
//第二轮蓄气开始将从任意一点开始进行蓄气文字显示，但是颜色还是按照
//从0-9循环显示。
void in_xuqi(object me,int step,int dups)
{
	string *color=({ HBBLU+WHT, HBBLU+HIW, HBBLU+GRN, HBBLU+HIG, HBBLU+YEL, HBBLU+HIY, HBBLU+MAG, HBWHT+HIM, HBWHT+RED, BLINK+HBWHT+HIR});
	string *display=({
		"你活动活动身体，蹲下马步。\n",
		"挥舞着手臂，吸了一口气，开始做蓄气前的准备工作。\n",
		"你运起全身的真气，慢慢向丹田积累真气。\n",
		"你运起真气从丹田循着督脉往上冲......\n",
		"你将真气从任脉往丹田里缓慢归拢......\n",
		"你运气于奇经八脉，感觉真气正缓缓收拢回来......\n",
		"你转动大周天，将全身的真气缓慢归于一点......\n",
		"你感觉到丹田里的真气正在慢慢充盈起来。\n",
		"再深吸了一口气，举起了大槌，似乎全身的真气快蓄到顶点了。\n",
		"隐隐中你觉察到似乎已经无法再维持住全身真气了，也许现在正是最合适的机会！\n"
	});
	
	if(!step) {
		tell_object(me,HIM"蓄气马上就要开始了，请注意蓄气过程中的提示和颜色显示。蓄气程度越高"+me->query_temp("quest_qiaozhong/name")+"的成功率也就越高。\n");
		tell_object(me,"第一轮蓄气中颜色和提示一一对应的，第二轮及以后请注意观察颜色，每轮最后一个蓄气阶段的成功率是最高的。\n"NOR);
	}
	else if(step>0&&!(step%10))
		dups=random(10);
	else if(!me->query_temp("quest_qiaozhong/xuqi")) {
		tell_object(me,"你现在没有处于蓄气状态，蓄气结束了！\n");
		me->start_busy(1);
//		remove_call_out("in_xuqi");
		return;
	}
	else if(me->query_temp("quest_qiaozhong/xuqi_end"))
		return;
	else if(me->query_temp("quest_qiaozhong/xuqi_room")!=environment(me)) {
		me->start_busy(1);
		return;
	}
	
	tell_object(me,"\n"+color[step%10]+display[(step-dups)%10]+NOR);
	
	me->start_busy(4);
	me->set_temp("quest_qiaozhong/xuqival",(step%10+1)*100);
	me->set_temp("quest_qiaozhong/knocked",0);
//	remove_call_out("in_xuqi");
	if((step%10+1)==sizeof(display))
		call_out("in_xuqi",5,me,step+1,dups);
	else
		call_out("in_xuqi",1+random(3),me,step+1,dups);
}

string start_knockbell(string name,string questid)
{
	object me;
	string randDone;
	mapping locate=([
	 "敲钟": "钟楼七层",
	 "击鼓": "鼓楼七层"]);
	
	me=this_player();
	this_object()->newbieStart(name,questid);
	randDone=keys(locate)[random(2)];
	me->set_temp("quest_qiaozhong/promoter",this_object()->query("name"));
	me->set_temp("quest_qiaozhong/start",1);
	me->set_temp("quest_qiaozhong/name",randDone);
	me->set_temp("quest_qiaozhong/room",locate[randDone]);
	me->set_temp("quest_qiaozhong/times", 4+random(3));
	
	this_object()->newbieDesc("到"+YEL+locate[randDone]+GRN+randDone+NOR+"提醒大家练武。\n");
	return "又到练武的时候了，请"+me->query("name")+NOR"到"+YEL+locate[randDone]+GRN+randDone+NOR+"提醒大家一下。";
}

string fail_knockbell()
{
	if(!mapp(this_player()->query_temp("quest_qiaozhong")))
		return "你没有领敲钟任务。\n";

	this_object()->newbieFail();
	this_player()->delete_temp("quest_qiaozhong");
	return "你连这点小事也干不好！\n";
}

string end_knockbell(int reward)
{
	if(!mapp(this_player()->query_temp("quest_qiaozhong")))
		return "你没有领敲钟任务。\n";
	else if(!this_player()->query_temp("quest_qiaozhong/success"))
		return "你还没有去啊！全寺武僧都等着你提醒呢！\n";

	this_object()->newbieEnd(reward);
	this_player()->delete_temp("quest_qiaozhong");
	return "做的非常棒，连山下的登封都能听见少林的钟声。\n";
}
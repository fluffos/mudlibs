// the job of visit a certain officer to increase his loyalty
// by row on Dec 1999
nosave private string *sug=({
"$N对$T笑道：$m$R有万夫不当之勇，$s我真是佩服，佩服。",
"$N对$T笑道：$m$R的智慧如大海一般深不可测，能和$R同朝为官，乃是$s的幸运。",
"$N对$T笑道：$m$R有大将风范，同时又治国有方，何时能指点$s一二？",
"$N对$T笑道：$m$R平素淡泊名利，令人钦佩，只是这些银两乃$s的一点小意思，还望$R笑纳。",
"$N对$T笑道：$s本欲带些宝物来与$R共赏，只是现在神仙太忙。。。",
"$N对$T一拱手，道：以$m$R高见，当今天下，可成大业者为谁？",
"$N对$T笑道：以$m$R之大器，在我国为官，定能平步青云。",
"$N对$T笑道：我国兵强马壮，国力富足，它日必可一统天下。",
"$N对$T笑道：$m$R高风亮节，本地官民爱戴久矣，$s也钦佩不已。",
"$N对$T一抱拳，道：今日能与$R一叙，实乃生平快事。只是时辰不早，$s先行告辞。",
});
void judge_select(mixed obs);
void input_way(mixed obs,string str);
void no_answer_way(mixed obs);
void select_way(mixed obs);
void talk_over(mixed obs);

mixed job(string m_id,string officer_id)
{
   string m_area=CHAR_D->get_char(officer_id,"area");
   string *mlist,target,m_nation;
   object o=find_body(m_id);
	m_nation=AREA_D->get_area(m_area,"nation");
   if(!objectp(o)) return 0; // string

   mlist=CHAR_D->check_char_area("type",TYPE_NPC,m_area);
   mlist=filter_array(mlist,
           (: ((CHAR_D->get_char($1,"loyalty")!=100 ) &&
              (CHAR_D->get_char($1,"nation")==$(m_nation ))  ) :) );
   if(!mlist) mlist=({});
//	tell_user("row","it is "+m_nation+".\n");
   if(!sizeof(mlist)){
		o->add_job("visitofficer");
		o->finish_job("visitofficer");
		return "$N对$T摇摇头：看来看去，好象没有什么官员需要探访。\n";
	}
   target=mlist[random(sizeof(mlist))];
   o->set_asklist("talk","target",target);
   o->set_asklist("talk","filename","/sgdomain/job/visitofficer/visitofficer");
   o->set_asklist("talk","funname","ask_talk");

  o->add_job("visitofficer");
  o->set_job("visitofficer","status","begin");
  o->set_job("visitofficer","memo","安抚"+CHAR_D->get_char(target,"name")+"("+target+")");
   
   return "$N对$T道：最近听说"+CHAR_D->get_char(target,"name")+"("+target+")"+
	   "心怀不满，麻烦$R去安抚一下。\n见面就说ask "+target+" about talk 。\n";
}
void ask_talk(object me, object target)
{
	string m_area,m_id;
    string m_title;
	m_id=me->query_id()[0];
	m_area=CHAR_D->get_char(m_id,"area");
    m_title=OFFICER_D->query_rank_name(
        (OFFICER_D->query_area_officer_title(
         AREA_D->get_area(m_area,"level"),0,0))[0]);
	me->targetted_action(
      "$N对$T笑道：本地"+m_title+"常与$s提起$m$R，今日有幸能求一见。\n",target);
	DELAY_D->delay_targetted_action(
		target,me,"$N对$T笑道：哪里，哪里，你我同朝为官，何必过谦。\n",1);
	me->clear_asklist("talk");
	me->set_job("visitofficer","status","done");
	target->special_heart(600); // will now go around or do semote
	me->set_job("visitofficer","topics",({})); //haven't talk yet	                            
	                             // within 10 minute
	me->set_job("visitofficer","score",10); // meet is 10
	                                      // succ is 50
	call_out("select_way",2,({ me, target}));
	return;
}

void judge_select(mixed obs)
{
    object me=obs[0],tar=obs[1];
	int ladd=1,lsub=1;
	string p_id,t_id,mnation,marea;
	mixed gift;
	int loyalty,score,p_select;
	if(!objectp(me)) return;
	if(!objectp(tar)) {talk_over(obs); return;}
	p_id=me->query_id()[0];
	marea=CHAR_D->get_char(p_id,"area");
	t_id=tar->query_id()[0];
	gift=CHAR_D->get_char(t_id,"gift");
	mnation=CHAR_D->get_char(p_id,"nation");
	loyalty=CHAR_D->get_char_loyalty(t_id,mnation);
	score=me->query_job("visitofficer","score");
	p_select=me->query_job("visitofficer","select");
	switch(p_select)
	{
	case 1:
	if(random(30)>gift["wuli"])
	{
	if(random(3)>1)
	{
	tar->simple_action("$N漫不经心地道：是吗？\n");
	me->simple_action("$N不知道自己到底是说对了，还是说错了，暗自琢磨不定。\n");
	}
	else
	{
	tar->simple_action("$N一瞪眼，道：你不是在讽刺我吧？\n");
	tar->responda("heng"); score-=1;loyalty-=lsub;
	}
	}
	else
	{
	tar->targetted_action("$N哈哈大笑道：$m$R过奖了。\n",me);
	score+=2; loyalty+=ladd+random(1);
      }
	break;
	case 2:
	if(random(30)>gift["zhimou"])
	{
	if(random(3)>1)
	{
	tar->simple_action("$N好象没睡醒的样子：哦？这个，那个。。。\n");
	me->simple_action("$N只觉得手痒痒：要不要我给你来一下，让你清醒清醒？\n");
	}
	else
	{
	tar->simple_action("$N冷笑一声，道：多谢，$s尚有自知之明。\n");
	tar->responda("angry"); score-=1;loyalty-=lsub;
	}
      }
	else
	{
	tar->targetted_action("$N微微一笑，道：哪里，哪里，$m$R太高抬我了。\n",me);
	score+=2; loyalty+=ladd+random(1);
	}
	break;
	case 3:
	if(random(30)>gift["meili"])
	{
     	if(random(3)>1)
	{
	tar->simple_action("$N仔细地数着地上的蚂蚁，头也不抬地道：那是，那是。。。\n");
	me->simple_action("$N也低头看去：地上有宝吗？哎？那黄黄的一坨是什嘛东东？！\n");
	}
	else
	{
      tar->simple_action("$N「哼」了一声，道：是吗？！我看还是算了吧。\n");
	tar->responda("puke"); score-=1;loyalty-=lsub;
	}
      }
	else {  tar->targetted_action("$N笑着连连摆手道：$s的这些本事，不值$R一提，咱们共同探讨，共同探讨。\n",me);
	score+=2; loyalty+=ladd+random(1);
	}
	break;
	case 4:
	if(me->query_all_con_money()<20000) {
	tell_user(p_id,"你身上没带够钱。\n");
	tar->simple_action("$N摇头道：搞什么名堂？！\n");
	tar->responda("angry"); score-=2;loyalty-=lsub;
	}
	else
	{
	if(random(3)>1)
	{
	tar->simple_action("$N好象没听见的样子：啊？哦？是这样子的吗？\n");
	me->simple_action("$N一乐，悄悄地把钱收了回去：给你，我还心疼呢！\n");
	}
	else
	{
	me->set_all_con_money( me->query_all_con_money() -20000 );
	me->targetted_action("$N塞给$T二两金子。\n",tar);
	tar->targetted_action("$N笑呵呵地道：既然是$m$R一番美意，$s就不推辞了。\n",me);
	score+=2; loyalty+=ladd+random(1);
	}
	}
	break;
	case 5:
	tar->simple_action("$N笑道：宝物既然还没有好，那就回头再说吧。\n");
	break;
	case 6:
	if(random(80)>loyalty)
	{
	tar->simple_action("$N「哈」地一声，道：我哪里有什么高见？笑话。\n");
	score--;loyalty-=lsub;
	}
	else
	{
	if(random(3)>1)
	{
	tar->simple_action("$N并不搭茬，只是自言自语：甲、乙、丙、丁、子、丑、寅、卯。。。\n");
	me->simple_action("$N也不由自主地接上：戊、己、庚、辛。。。\n");
	}
	else
	{
	tar->simple_action("$N摇头晃脑一番，道：以$s之见，当今可称英雄者，乃。。。\n");
	score+=2;loyalty+=ladd+random(1);
	}
	}
	break;
	case 7:
	if(random(80)>loyalty)
	{
	tar->simple_action("$N一皱眉：哼，$s何德何能，本也没指望高官厚禄。\n");
	score--;loyalty-=lsub;
	}
	else
	{
	if(random(3)>1)
	{
	tar->simple_action("$N侧耳倾听：刚才是谁叫我的名字来着？\n");
	me->simple_action("$N差点没晕过去：这家伙到底在没在听我说话啊？\n");
	}
	else
	{
	tar->simple_action("$N一拱手，道：$s当鞠躬尽瘁，报效主公。\n");
	score+=2;loyalty+=ladd+random(1);
	}
	}
	break;
	case 8:
	if(random(80)>loyalty)
	{
	tar->simple_action("$N「嘿嘿嘿」干笑几声：当真如此？\n");
	score--;loyalty-=lsub;
	}
	else
	{
	if(random(3)>1)
	{
	tar->simple_action("$N「呃」地打了一个饱嗝：唉呀，刚才吃太多了。\n");
	me->simple_action("$N气不打一处来，暗道：看我不回去让太守扣你的薪水。吃！吃空气去吧你！\n");
	}
	else
	{
	tar->simple_action("$N神情激昂：那是自然！$s愿献一己之力，辅佐主公，以成大业。\n");
	score+=2;loyalty+=ladd+random(1);
	}
	}
	break;
	case 9:
	if(random(80)>loyalty)
	{
	tar->targetted_action("$N阴笑道：是吗？我看他们是巴不得我下台。。。\n",me);
	}
	else
	{
	if(random(3)>1)
	{
	tar->simple_action("$N突然一拍脑袋：啊呀，昨个儿谁谁约我看戏去来着。。。\n");
	me->simple_action("$N脸色一阵红一阵白：好家伙，耍我哪？尽打岔！\n");
	}
	else
	{
	tar->targetted_action("$N对$T笑道：哎，若不是平时主公的爱护，$m$R的关怀，$s哪有今天？\n",me);
	score+=2;loyalty+=ladd+random(1);
	}
	}
	break;
	case 10:
	tar->simple_action("$N一拱手，道：恕不远送，告辞。\n");
	talk_over(obs);
	default:
	return;
	}      
	CHAR_D->set_char_loyalty(t_id,mnation,loyalty);
	me->set_job("visitofficer","score",score);
	call_out("select_way",1,obs);
}
void input_way(mixed obs,string str)
{	int p_select;
    object me=obs[0],usr,tar;
	string p_id;
	int *topics;
    remove_call_out("no_answer_way");
	p_select=to_int(str);
	if(!objectp(me)) return;
	p_id=me->query_id()[0];
	usr=find_user(p_id);
    if(!objectp(usr)) return;

    if((p_select<1)||(p_select>10)) return;
 	topics=me->query_job("visitofficer","topics");
    if(member_array(p_select,topics)!=-1)
    {  tell_user(p_id,"这个话题已经谈过了，得换一个。\n");
       call_out("no_answer_way",30,obs);
       return;
    }
    usr->modal_pop();
	tar=obs[1];
	if(!objectp(tar)) {talk_over(obs); return;}
    me->targetted_action(sug[p_select-1]+"\n",tar);
	me->set_job("visitofficer","select",p_select);
	topics+=({p_select});
	me->set_job("visitofficer","topics",topics);
    call_out("judge_select",1,obs );
}

void no_answer_way(mixed obs)
{ input_way(obs,"10");
}

void select_way(mixed obs)
{
   object me=obs[0],usr;
   string p_id;
   if(!objectp(me)) return;
   p_id=me->query_id()[0];
   usr=find_user(p_id);
   if(!objectp(usr)) return;
   tell_user(p_id,"你的目的就是尽量哄他高兴。\n"+
"〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n"+
" 1 恭维勇猛  2 恭维智慧  3 恭维魅力  4 赠送银两  5 赠送宝物 \n"+
" 6 请教忠告  7 高官诱惑  8 自夸国力  9 诚心夸奖 10 告辞     \n"+
"〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n"+
"请输入你的话题(1--10)：\n");
   call_out("no_answer_way",30,obs);
   usr->modal_push((: input_way,obs:),
        "请输入你的话题(1--10)：");

}
void talk_over(mixed obs)
{
    object me=obs[0],tar;
	string p_id,t_id;
	if(!objectp(me)) return;
	p_id=me->query_id()[0];
	tar=obs[1];
	if(objectp(tar)) {
		t_id=tar->query_id()[0];
		tar->responda("wave");
		tar->simple_action("$N离开了。\n");
		CHAR_D->remove_npc_char(t_id);
	}
	tell_user(p_id,"%^H_GREEN%^任务完成得不错，快去太守处领赏吧。\n%^RESET%^");
}

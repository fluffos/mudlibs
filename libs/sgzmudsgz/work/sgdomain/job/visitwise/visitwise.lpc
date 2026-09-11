// the job of visit a certain wise people
// by fire on Jan 1999
nosave private string *sug=({
"$N对$T笑道：$m$R有万夫不挡之勇，$s我真是佩服，佩服。",
"$N对$T笑道：$m$R的智慧如大海一般深不可测，$s我早就听说了。",
"$N对$T笑道：$m$R有大将风范，同时又治国有方，$s我倾心已久。",
"$N对$T笑道：$m$R淡泊名利，令人钦佩，只是这些银两还望$R笑纳。",
"$N对$T笑道：本欲带些宝物来，只是现在还没有。。。",
"$N对$T一拱手，道：以$m$R高见，可否指点$s一二？",
"$N对$T笑道：以$m$R之大器，若谋仕途之路，必有大成。",
"$N对$T笑道：我国兵强马壮，国力富足，它日必可一统天下。",
"$N对$T笑道：本地官民对$m$R仰慕已久，$R何不在此谋一官职，以成大业？",
"$N对$T一抱拳，道：今日得见$R一面，果然名不虚传。时辰不早，$s先行告辞。",
});
void judge_select(mixed obs);
void input_way(mixed obs,string str);
void no_answer_way(mixed obs);
void select_way(mixed obs);
void talk_over(mixed obs);
void big_success(mixed obs,mixed vac);

mixed job(string m_id,string officer_id)
{
   string m_area=CHAR_D->get_char(officer_id,"area");
   string *mlist,target;
   object o=find_body(m_id);
   if(!objectp(o)) return 0; // string

   mlist=CHAR_D->check_char_area("type",TYPE_NPC,m_area);
   mlist=filter_array(mlist,
	   (: ((!CHAR_D->get_char($1,"is_tmp") ) &&
	      (!CHAR_D->get_char($1,"nation") )  ) :) );
   if(!mlist) mlist=({});
   if(!sizeof(mlist)){
		o->add_job("visitwise");
		o->finish_job("visitwise");
		return "$N对$T摇摇头，道：最近本地区没听说有大贤出现。\n";
	}
   target=mlist[random(sizeof(mlist))];
   o->set_asklist("visit","target",target);
   o->set_asklist("visit","filename",PJOB+"visitwise/visitwise");
   o->set_asklist("visit","funname","ask_visit");

  o->add_job("visitwise");
  o->set_job("visitwise","status","begin");
  o->set_job("visitwise","memo","拜访"+CHAR_D->get_char(target,"name")+"("+target+")");
   
   return "$N对$T道：最近听说本地区有一大贤名曰"+CHAR_D->get_char(target,"name")+"("+target+")。\n"+
	   "就麻烦$R去探访一下，见面就说ask "+target+" about visit 。\n"+
	   "如果可能，最好能请来当官。\n";
}
void ask_visit(object me, object target)
{
	string m_area,m_id;
    string m_title;
	m_id=me->query_id()[0];
	m_area=CHAR_D->get_char(m_id,"area");
    m_title=OFFICER_D->query_rank_name(
        (OFFICER_D->query_area_officer_title(
         AREA_D->get_area(m_area,"level"),0,0))[0]);
	me->targetted_action(
      "$N对$T笑着说道：本地"+m_title+"与$s久仰$m$R大名，\n"
	  +"今日有幸能求一见。\n",target);
	DELAY_D->delay_targetted_action(
		target,me,"$N对$T笑道：哪里，哪里，$m$R何必过谦。\n",1);
	me->clear_asklist("visit");
	me->set_job("visitwise","status","done");
	target->special_heart(600); // will now go around or do semote
	me->set_job("visitwise","topics",({})); //haven't talk yet	                            
	                             // within 10 minute
	me->set_job("visitwise","score",10); // meet is 10
	                                      // succ is 50
	call_out("select_way",2,({ me, target}));
	return;
}

void judge_select(mixed obs)
{
    object me=obs[0],tar=obs[1];
	int ladd=3,lsub=2;
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
	score=me->query_job("visitwise","score");
	p_select=me->query_job("visitwise","select");
    switch(p_select)
    {    case 1:
         if(random(30)>gift["wuli"])  {
            tar->simple_action("$N一瞪眼，道：你不是在讽刺我吧？\n");
			tar->responda("heng"); score-=1;loyalty-=lsub;
         }
         else {  tar->simple_action("$N哈哈大笑道：过奖，过奖。\n");
			score+=2; loyalty+=ladd;
         }
         break;
       case 2:
         if(random(30)>gift["zhimou"])  {
            tar->simple_action("$N冷笑一声，道：多谢，$s还有自知之明。\n");
			tar->responda("angry"); score-=1;loyalty-=lsub;
         }
         else {  tar->simple_action("$N哈哈大笑道：过奖，过奖。\n");
			score+=2; loyalty+=ladd;
         }
         break;
       case 3:
         if(random(30)>gift["meili"])  {
            tar->simple_action("$N「哼」了一声，道：你可当真？\n");
			tar->responda("puke"); score-=1;loyalty-=lsub;
         }
         else {  tar->simple_action("$N哈哈大笑道：过奖，过奖。\n");
			score+=2; loyalty+=ladd;
         }
         break;
	   case 4:
         if(me->query_all_con_money()<10000) {
			tell_user(p_id,"你身上没带够钱。\n");
			 tar->simple_action("$N摇头道：真是胡闹。\n");
			tar->responda("angry"); score-=2;loyalty-=lsub;
         }
         else
         {  me->set_all_con_money( me->query_all_con_money() -10000 );
			me->targetted_action("$N塞给$T一两金子。\n",tar);
		    tar->simple_action("$N面上不住推辞，一边却悄悄把金子揣到怀里。\n");
			score+=4; loyalty+=ladd;
         }
         break;
	   case 5:
		    tar->simple_action("$N笑道：宝物既然还没有好，那就回头再说吧。\n");
		 break;
	   case 6:
		   if(random(60)>loyalty) {
			   tar->simple_action("$N「哈」地一声，道：我哪里有什么高见？笑话。\n");
			   score--;loyalty-=lsub;
		   }
		   else {
			   tar->simple_action("$N摇头晃脑一番，道：以$s之见，当今可称英雄者，乃。。。\n");
			   score+=2;loyalty+=ladd;
		   }
		   break;
	   case 7:
		   if(random(60)>loyalty) {
			   tar->simple_action("$N一摆手，道：$s何德何能，怎敢从官？\n");
			   score--;loyalty-=lsub;
		   }
		   else {
			   tar->simple_action("$N一拱手，道：如真有那一日，定当鞠躬尽瘁。。。\n");
			   score+=2;loyalty+=ladd;
		   }
		   break;
	   case 8:
		   if(random(60)>loyalty) {
			   tar->simple_action("$N「嘿嘿嘿」干笑几声：当真如此？\n");
			   score--;loyalty-=lsub;
		   }
		   else {
			   tar->simple_action("$N不住点头：有道理，有道理。\n");
			   score+=2;loyalty+=ladd;
		   }
		   break;
	   case 9:
		   if(random(50)+50>loyalty) {
			   tar->targetted_action("$N笑道：$s生性疏懒，不仕久已，$R请见谅。\n",me);
		   }
		   else {
				int* vac;
			   vac=(EV_POSITION)->get_area_vacancy(marea);
			   if(sizeof(vac)){
				if((stringp(CHAR_D->get_char(t_id,"nation")))||(CHAR_D->get_char(t_id,"retire")>time()))
				{
					tar->simple_action("$N叹道：$s俗务缠身，实在是身不由己呀。\n");
					break;
				}
				else
				{
					CHAR_D->set_char(t_id,"retire",0);
				   tar->targetted_action("$N对$T一躬身：$R知遇之恩，$s没齿不忘，$m$R请先行一步，我随后就到。\n",me);
				   big_success(obs,vac);
					return;
				}

				   
			   }
			   else {
					tar->simple_action("$N道：本地官职根本没有空缺，拿我开什么心呀？\n");
					score--;loyalty-=lsub;
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
	me->set_job("visitwise","score",score);

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
 	topics=me->query_job("visitwise","topics");
    if(member_array(p_select,topics)!=-1)
    {  tell_user(p_id,"这个话题已经谈过了，得换一个。\n");
       call_out("no_answer_way",30,obs);
       return;
    }

    usr->modal_pop();
	tar=obs[1];
	if(!objectp(tar)) {talk_over(obs); return;}

    me->targetted_action(sug[p_select-1]+"\n",tar);
	me->set_job("visitwise","select",p_select);
	topics+=({p_select});
	me->set_job("visitwise","topics",topics);
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
" 6 请教忠告  7 高官诱惑  8 自夸国力  9 诚心邀请 10 告辞     \n"+
"〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n"+
"请输入你的话题(1--10)：\n");
   call_out("no_answer_way",30,obs);
   usr->modal_push((: input_way,obs:),
        "请输入你的话题(1--10)：");

}
void big_success(mixed obs,mixed vac)
{
    object me=obs[0],tar;
	string p_id,t_id,p_area;
	if(!objectp(me)) return;
	p_id=me->query_id()[0];
	tar=obs[1];
	p_area=CHAR_D->get_char(p_id,"area");
	if(objectp(tar)) {
		t_id=tar->query_id()[0];
		tar->responda("wave");
		tar->simple_action("$N离开了。\n");
		CHAR_D->remove_npc_char(t_id);
        (EV_POSITION)->give_position(t_id,vac[random(sizeof(vac))],p_area);
	}
	me->set_job("visitwise","score",50);
	tell_user(p_id,"%^H_BLUE%^任务完全成功，快去太守处领赏吧。\n%^RESET%^");
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
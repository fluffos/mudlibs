// the job of whisper a certain wise general
// by group on Mar 1999
nosave private string *sug=({
"$N对$T道：$m$R有千军不挡之勇，只可惜功高难免震主啊！",
"$N对$T道：$m$R的智慧如大海一般深不可测，就该看出此地不是可居之地。",
"$N对$T道：$m$R有大将风范，只是你君上却不是用才之人哪！",
"$N对$T道：$m$R淡泊名利，令人钦佩，只是这些银两还忘$R笑纳。",
"$N对$T道：本欲带些宝物来，只是现在还没有. . . ",
"$N对$T道：以$m$R之大材，如谋他国仕途之路，必有大成。",
"$N对$T道：$m$R如不早早回头，他日只恐身首易处呀！",
"$N对$T道：我国兵强马壮，国力富足，它日必可一统天下。",
"$N对$T道：小地官民对$m$R敬仰已久，何不良禽择木而栖，以成大业。",
"$N对$T道，今日得见$R一面，果然名不虚传。时辰不早，$s先行告辞。",
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
   string m_nation=CHAR_D->get_char(officer_id,"nation");	
   string *mlist,target;
   object o=find_body(m_id);
   if(!objectp(o)) return 0; // string

   mlist=CHAR_D->check_char("type",TYPE_NPC);
   mlist=filter_array(mlist,
	   (: ((!CHAR_D->get_char($1,"is_tmp") ) &&
	      (CHAR_D->get_char($1,"nation") ) &&
(CHAR_D->get_char($1,"nation")!=$(m_nation))) :) );
   if(!mlist) mlist=({});
   if(!sizeof(mlist))
		return "$N对$T道：最近没什么人好策反的\n";
  
   target=mlist[random(sizeof(mlist))];   	   
o->set_asklist("whisper","target",target);
   o->set_asklist("whisper","filename",PJOB+"whisper/whisper");
   o->set_asklist("whisper","funname","ask_whisper");

  o->add_job("whisper");
  o->set_job("whisper","status","begin");

o->set_job("whisper","memo","策反"+CHAR_D->get_char(target,"area")+CHAR_D->get_char(target,"name")+"("+target+")");
   
   return "$N对$T道：最近听说"+CHAR_D->get_char(target,"area")+"有一大贤名曰"+CHAR_D->get_char(target,"name")+"("+target+")。\n"+
	   "就麻烦$R去探访一下，见面就说ask "+target+" about whisper。\n"+
	   "如果可能，最好能请来当官。\n";
}

void ask_whisper(object me, object target)
{
	string t_area,t_id;
    string m_title;
	t_id=target->query_id()[0];
	t_area=CHAR_D->get_char(t_id,"area");
    m_title=OFFICER_D->query_rank_name(
        (OFFICER_D->query_area_officer_title(
         AREA_D->get_area(t_area,"level"),0,0))[0]);
	me->targetted_action(
      "$N对$T笑着说道：本地"+m_title+"与$s久仰$m$R大名，\n"
	  +"今日有幸能求一见。\n",target);
	DELAY_D->delay_targetted_action(
		target,me,"$N对$T道：你我各为其主，不必客气\n",1);
	me->clear_asklist("whisper");
	me->set_job("whisper","status","done");
	target->special_heart(600); // will now go around or do semote
	me->set_job("whisper","topics",({})); //haven't talk yet	                            
	                             // within 10 minute
	me->set_job("whisper","score",10); // meet is 10
	                                      // succ is 50
	call_out("select_way",2,({ me, target}));
	return;
}

void judge_select(mixed obs)
{
    object me=obs[0],tar=obs[1];
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
	score=me->query_job("whisper","score");
	p_select=me->query_job("whisper","select");
    switch(p_select)
    {    case 1:
         if(random(30)>gift["wuli"])  {
            tar->simple_action("$N道：你好像在信口开河\n");
			tar->responda("heng"); score-=1;
         }
         else { if(random(loyalty)<30){ 
          tar->simple_action("$N自言自语道：”此话有理。”\n");
			score+=2; loyalty-=3;}
         }
         break;
       case 2:
         if(random(30)>gift["zhimou"])  {
            tar->simple_action("$N道：你好像在信口开河\n");
			tar->responda("angry"); score-=1;
         }
         else {  if(random(60)>loyalty){
	tar->simple_action("$N自言自语道：”此话有理。”\n");
			score+=2; loyalty-=2;
         }}
         break;
       case 3:
         if(random(30)>gift["meili"])  {
            tar->simple_action("$N道：你好像在信口开河\n");
			tar->responda("puke"); score-=1;
         }
         else {if(random(loyalty)<30){  
	tar->simple_action("$N自言自语道：”此话有理。”\n");
			score+=2; loyalty-=2;
         }}
         break;
	   case 4:
         if(me->query_all_con_money()<10000) {
			tell_user(p_id,"你身上没带够钱。\n");
			 tar->simple_action("$N道：真是胡闹。\n");
			tar->responda("angry"); score-=2;
         }
         else
         {  me->set_all_con_money( me->query_all_con_money() -10000 );
			me->targetted_action("$N塞给$T一两金子。\n",tar);
		    tar->simple_action("$N一边说不能要，不能要，一边悄悄把金子揣到怀里。\n");
			score+=4; loyalty-=1;
         }
         break;
	   case 5:
		    tar->simple_action("$N道：宝物既然还没有好，那就回头再说吧。\n");
		 break;
	   case 6:
		   if(random(60)>loyalty) {
tar->simple_action("$N自言自语道：”此话有理。”\n");
			   score+=2;loyalty-=3;
		   }
		   else {
tar->simple_action("$N道：$s平生不喜名利，只为报知己之恩。\n");
			   score--;loyalty+=2;
		   }
		   break;
	   case 7:
		   if(random(60)>loyalty) {
tar->simple_action("$N自言自语道：”此话有理。”\n");
			   score+=2;loyalty-=2;
		   }
		   else {
tar->simple_action("$N道：$s马革裹尸，死而后已。\n");
			   score--;loyalty+=2;
		   }
		   break;
	   case 8:
		   if(random(60)>loyalty) {
tar->simple_action("$N摇头道：吾意已决，勿须多言。\n");
			   score--;loyalty+=2;
		   }
		   else {
			   tar->simple_action("$N道：有道理，有道理。\n");
			   score+=2;loyalty-=2;
		   }
		   break;
	   case 9:
		   if(random(50)+50>loyalty) {
tar->targetted_action("$N道：吾意已决，$R请见谅。\n",me);
		   }
		   else
{tar->targetted_action("$N道：果是如此？说罢暗自思量\n");
		score+=2; loyalty-=3;

			   }
		   
		   break;
	   case 10:
		   tar->simple_action("$N道：恕不远送，告辞。\n");
		   talk_over(obs);
	   default:
			return;
    }      

	CHAR_D->set_char_loyalty(t_id,mnation,loyalty);
	me->set_job("whisper","score",score);

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
 	topics=me->query_job("whisper","topics");
    if(member_array(p_select,topics)!=-1)
    {  tell_user(p_id,"这个话题已经谈过了，得换一个话题。\n");
       call_out("no_answer_way",30,obs);
       return;
    }

    usr->modal_pop();
	tar=obs[1];
	if(!objectp(tar)) {talk_over(obs); return;}

    me->targetted_action(sug[p_select-1]+"\n",tar);
	me->set_job("whisper","select",p_select);
	topics+=({p_select});
	me->set_job("visitwise","topics",topics);
    call_out("judge_select",1,obs );
}

void no_answer_way(mixed obs)
{ input_way("10",obs);
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
" 6 高官诱惑  7 死亡威胁  8 自夸国力  9 良言相劝 10 告辞     \n"+
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
	}
	tell_user(p_id,"%^H_BLUE%^任务成功，快去太守处领赏吧。\n%^RESET%^");
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
	tell_user(p_id,"%^H_GREEN%^任务完成不错，快去太守处领赏吧。\n%^RESET%^");
}

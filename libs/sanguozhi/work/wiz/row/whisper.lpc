// the job of whisper a certain wise general
// by group on Mar 1999
nosave private string *sug=({
"$N对$T笑道：$m$R有万夫不当之勇，怕只怕功高难免震主啊！",
"$N对$T笑道：$m$R的智慧如大海一般深不可测，早该看出此地不可久留呀。",
"$N对$T笑道：$m$R有大将风范，只是你的主公非用才之人哪！",
"$N对$T笑道：$m$R淡泊名利，令人钦佩，只是这些银两还望$R笑纳。",
"$N对$T道：本欲带些宝物来，只是现在还没有。。。",
"$N对$T笑道：以$m$R之大器，若往他国谋职，必有大成。",
"$N对$T道：$m$R如不早早回头，他日只恐身首异处呀！",
"$N对$T笑道：我国兵强马壮，国力富足，他日必可一统天下。",
"$N对$T道：$m$R于此地不得重用，何不弃官出走，择良木而栖，以成大业？",
"$N对$T一拱手，道，今日得见$R一面，果然名不虚传。时辰不早，$s先行告辞。",});
void judge_select(mixed obs);
void input_way(mixed obs,string str);
void no_answer_way(mixed obs);
void select_way(mixed obs);
void talk_over(mixed obs);
void big_success(mixed obs);
mixed job(string m_id,string officer_id)
{
	string m_nation=CHAR_D->get_char(officer_id,"nation");
	string *mlist,target;
	object o=find_body(m_id);
	if(!objectp(o)) return 0;
//	string   
	mlist=CHAR_D->check_char("type",TYPE_NPC);
	mlist=filter_array(mlist,(: ((!CHAR_D->get_char($1,"is_tmp") )&&(CHAR_D->get_char($1,"nation") )&&(CHAR_D->get_char($1,"nation")!=$(m_nation))&&(CHAR_D->get_char($1,"nation")!="group")&&(CHAR_D->get_char($1,"ranknation")!= R_KING))  // king cant be whisperd
	:) );
	if(!mlist) mlist=({});
	if(!sizeof(mlist))
	return "$N对$T道：最近没什么人好策反的。\n";
	target=mlist[random(sizeof(mlist))];
	o->set_asklist("whisper","target",target);
	o->set_asklist("whisper","filename",PJOB+"whisper/whisper");
	o->set_asklist("whisper","funname","ask_whisper");
	o->add_job("whisper");
	o->set_job("whisper","status","begin");
	o->set_job("whisper","memo","策反"+CHAR_D->get_char(target,"name")+"("+target+")");
	return "$N对$T道：最近听说"+COUNTRY_D->get_country(CHAR_D->get_char(target,"nation"),"name")+"的"+
	CHAR_D->get_char(target,"name")+"心存不满。\n"+
	"就麻烦$R去探访一下，见面就说ask "+target+" about whisper。\n"+
	"如果可能，最好煽动他弃官。\n";
}
void ask_whisper(object me, object target)
{
	string t_area,t_id;
    	string m_title,p_id;
	string nat;
	int loy;
	p_id=me->query_id()[0];
	t_id=target->query_id()[0];
	t_area=CHAR_D->get_char(t_id,"area");
	m_title=OFFICER_D->query_rank_name((OFFICER_D->query_area_officer_title(AREA_D->get_area(t_area,"level"),0,0))[0]);
	me->targetted_action(
	"$N对$T笑道：本地"+m_title+"与$s久仰$m$R大名，\n"+
	"今日有幸能求一见。\n",target);
	DELAY_D->delay_targetted_action(
	target,me,"$N对$T一拱手，道：你我各为其主，不必客气。\n",1);
	me->clear_asklist("whisper");
	me->set_job("whisper","status","done");
	target->special_heart(600);
//will now go around or do semote	
	me->set_job("whisper","topics",({}));
//haven't talk yet	
//within 10 minute	
	me->set_job("whisper","score",20);
//meet is 20 	     
//because in other country	
//succ is 100	
	CHANNEL_D->deliver_tell("rumor","system",	
	COUNTRY_D->get_country(CHAR_D->get_char(p_id,"nation"),"name")+	
	"的"+CHAR_D->get_char(p_id,"name")+"在与"+	
	COUNTRY_D->get_country(CHAR_D->get_char(t_id,"nation"),"name")+	
	"的"+CHAR_D->get_char(t_id,"name")+"密谈。");
	call_out("select_way",2,({ me, target}));
	CHAR_D->set_char(p_id,"catch_time",time()+600);
	CHAR_D->set_char(p_id,"catch_file",PJOB+"whisper/whisper");
	CHAR_D->set_char(p_id,"catch_function","whisper_catch");
	CHAR_D->set_char(p_id,"catch_para",target);
	CHAR_D->set_char(p_id,"catch_area",t_area);
	nat=AREA_D->get_area(t_area,"nation");
	loy=CHAR_D->get_char_loyalty(p_id,nat);
	loy--; loy=bmax(1,loy);
	CHAR_D->set_char_loyalty(p_id,nat,loy);
	return;
}
void whisper_catch(string o_id,string p_id,object o_general)
{
	object o_o,o_p;
	if(objectp(o_general))
	{
	string pep_id;
	o_general->simple_action("$N突然神色紧张，道：捉你的人来了，还不快跑？\n");
	pep_id=o_general->query_id()[0];
	CHAR_D->remove_npc_char(pep_id);
	}
	o_p=find_user(p_id);
	if(objectp(o_p))
	o_p->modal_pop();
	o_o=find_body(o_id);
	if(!objectp(o_o)) return;
	o_p=find_body(p_id);
	if(!objectp(o_p))
	{
	tell_user(o_id,"晚了一步，"+
	CHAR_D->get_char(o_id,"name")+"跑了。\n你的工作成绩下降了。\n");
	o_o->set_job("partol","score",
	o_o->query_job("partol","score")-1);
	return;
	}
	o_o->targetted_action("$N对$T大喝一声：大胆$r，竟敢在此煽动，给我拿下！\n",o_p);
	o_p->simple_action(
	"众官兵一拥而上，把$N捆得结结实实。\n");
	o_o->simple_action(
	"$N一挥手道：给我带走。\n");
	o_p->simple_action(
	"众官兵把$N押了下去。\n");
	CHANNEL_D->deliver_tell("rumor","system",
	CHAR_D->get_char(p_id,"name")+
	"在"+AREA_D->get_area(CHAR_D->get_char(o_id,"area"),"name")+
	"策反敌将，被正在巡逻的"+CHAR_D->get_char(o_id,"name")+             
	"当场抓获。");
	(PCMD+"catch")->catch_award(o_id,p_id);
}
void judge_select(mixed obs)
{
	object me=obs[0],tar=obs[1];
	string p_id,t_id,marea;
	mixed gift;
	int loyalty,score,p_select;
	int l_d=3,maxloyalty=90;
//if higher then 90 hard to convince
	if(!objectp(me)) return;
	if(!objectp(tar))
	{
	talk_over(obs);
	return;
	}
	p_id=me->query_id()[0];
	marea=CHAR_D->get_char(p_id,"area");
	t_id=tar->query_id()[0];
	gift=CHAR_D->get_char(t_id,"gift");
	loyalty=CHAR_D->get_char(t_id,"loyalty");
	score=me->query_job("whisper","score");
	p_select=me->query_job("whisper","select");
	switch(p_select)
	{
	case 1:
	if((random(30)>gift["wuli"])&&(random(maxloyalty)>loyalty))
	{
	tar->simple_action("$N摇头道：你好像在信口开河。\n");
	tar->responda("heng");
	score-=1;
	}
	else
	{
	tar->simple_action("$N自言自语道：嗯，此话有理。\n");
	score+=2;
	loyalty-=random(l_d);
	}
	break;
	case 2:
	if((random(30)>gift["zhimou"])&&(random(maxloyalty)>loyalty))
	{
	tar->simple_action("$N冷笑一声：真的吗？\n");
	tar->responda("angry");
	score-=1;
	}
	else
	{
	tar->simple_action("$N低头想了一会儿，道：好象没错。\n");
	score+=2;
	loyalty-=l_d;
	}
	break;
	case 3:
	if((random(30)>gift["meili"])&&(random(maxloyalty)>loyalty))
	{
	tar->simple_action("$N一摆手：哎，休得胡言！\n");
	tar->responda("puke");
	score-=1;
	}
	else
	{
	tar->simple_action("$N摸了摸下巴：对，$s早就看出来了。\n");
	score+=2;
	loyalty-=l_d;
	}
	break;
	case 4:
	if(me->query_all_con_money()<10000)
	{
	tell_user(p_id,"你身上没带够钱。\n");
	tar->simple_action("$N怒道：真是胡闹。\n");
	tar->responda("angry");
	score-=2;
	}
	else
	{
	me->set_all_con_money( me->query_all_con_money() -10000 );
	me->targetted_action("$N塞给$T一两金子。\n",tar);
	tar->simple_action("$N面上不住推辞，一边却悄悄把金子揣到怀里。\n");
	score+=4;
	loyalty-=random(2);
	}
	break;
	case 5:
	tar->simple_action("$N道：宝物既然还没有好，那就回头再说吧。\n");
	break;
	case 6:
	if(random(maxloyalty)>loyalty)
	{
	tar->simple_action("$N不住点头：对，对。\n");
	score+=2;
	loyalty-=l_d;
	}
	else
	{
	tar->simple_action("$N摇头道：$s平生淡薄名利，只为报主公知遇之恩。\n");
	score--;
	loyalty+=2;
	}
	break;
	case 7:
	if(random(maxloyalty)>loyalty)
	{
	tar->simple_action("$N好象有些担心：这。。。如何是好？\n");
	score+=2;
	loyalty-=l_d;
	}
	else {tar->simple_action("$N凛然道：$s马革裹尸，死而后已。\n");
	score--;
	loyalty+=2;
	}
	break;
	case 8:
	if(random(maxloyalty)>loyalty) {
	tar->simple_action("$N笑道：贵国富强，$s仰慕已久。\n");
	score+=2;
	loyalty-=l_d;
	}	
	else
	{	
	tar->simple_action("$N冷笑道：就算如此，也未必能成霸业。\n");
	score--;
	loyalty+=2;
	}		   
	break;
	case 9:		   
	if(random(maxloyalty/2)>loyalty)
	{
	tar->simple_action("$N沉吟道：果真如此？说罢暗自思量。\n");
	big_success(obs);
	return;
	}
	else
	tar->targetted_action("$N正色道：吾意已决，$R请见谅。\n",me);
	break;
	case 10:
	tar->simple_action("$N一拱手，道：恕不远送，告辞。\n");
	talk_over(obs);
	default:
	return;
	}
	CHAR_D->set_char(t_id,"loyalty",loyalty);
	me->set_job("whisper","score",score);
	call_out("select_way",1,obs);
	}
	void input_way(mixed obs,string str)
	{
	int p_select;
	object me=obs[0],usr,tar;
	string p_id;
	int *topics;
	p_select=to_int(str);
	if((p_select<1)||(p_select>10))
	return;
	remove_call_out("no_answer_way");
	if(!objectp(me))
	return;
	p_id=me->query_id()[0];
	usr=find_user(p_id);
	if(!objectp(usr))
	return;
 	topics=me->query_job("whisper","topics");
 	if(member_array(p_select,topics)!=-1)
	{
	tell_user(p_id,"这个话题已经谈过了，得换一个话题。\n");
	call_out("no_answer_way",30,obs);
	return;
	}
	usr->modal_pop();
	tar=obs[1];
	if(!objectp(tar))
	{
	talk_over(obs);
	return;
	}
	me->targetted_action(sug[p_select-1]+"\n",tar);
	me->set_job("whisper","select",p_select);
	topics+=({p_select});
	me->set_job("whisper","topics",topics);
	call_out("judge_select",1,obs );
}
void no_answer_way(mixed obs)
{
	input_way(obs,"10");
}
void select_way(mixed obs)
{
	object me=obs[0],usr;
	string p_id;
	if(!objectp(me)) return;
	p_id=me->query_id()[0];
	usr=find_user(p_id);
	if(!objectp(usr)) return;
	tell_user(p_id,"你的目的就是尽量激他不满。\n"+"〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n"+" 1 恭维勇猛  2 恭维智慧  3 恭维魅力  4 赠送银两  5 赠送宝物 \n"+" 6 高官诱惑  7 死亡威胁  8 自夸国力  9 良言相劝 10 告辞     \n"+"〓〓〓〓〓
〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n"+"请输入你的话题(1--10)：\n");
	call_out("no_answer_way",30,obs);
	usr->modal_push((: input_way,obs:),"请输入你的话题(1--10)：");
}
void big_success(mixed obs)
{
	object me=obs[0],tar;
	string p_id,t_id;
	if(!objectp(me)) return;
	p_id=me->query_id()[0];
	tar=obs[1];
	if(objectp(tar))
	{
	t_id=tar->query_id()[0];
	tar->responda("wave");
	tar->simple_action("$N离开了。\n");
	CHAR_D->remove_npc_char(t_id);
	}
	(EV_LEAVE)->leave(t_id);
	me->set_job("whisper","score",50);
	tell_user(p_id,"%^H_BLUE%^任务完全成功，快去太守处领赏吧。\n%^RESET%^");
}
void talk_over(mixed obs)
{
	object me=obs[0],tar;
	string p_id,t_id;
	if(!objectp(me)) return;
	p_id=me->query_id()[0];
	tar=obs[1];
	if(objectp(tar))
	{
	t_id=tar->query_id()[0];
	tar->responda("wave");
	tar->simple_action("$N离开了。\n");
	CHAR_D->remove_npc_char(t_id);
	}
	CHAR_D->set_char(p_id,"catch_time",0);
	CHAR_D->set_char(p_id,"catch_file",0);
	CHAR_D->set_char(p_id,"catch_function",0);
	CHAR_D->set_char(p_id,"catch_para",0);
	tell_user(p_id,"%^H_GREEN%^任务完成不错，快去太守处领赏吧。\n%^RESET%^");
}
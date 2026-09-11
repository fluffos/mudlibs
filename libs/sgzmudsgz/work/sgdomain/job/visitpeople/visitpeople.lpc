// the job of visit  people
// by fire on March 1999

nosave private string *sug=({
"$N自豪地对众$T道：我们的民众，是世界上最勤劳的人。",
"$N亲切地对众$T道：$s知道你们都是忠厚老实的人，绝不会一点歪门邪道。",
"$N感叹地对众$T道：你们的聪明才智远近闻名，没有你们，哪有我国今天的强盛？",
"$N关怀地对众$T道：战争时期，生活清贫，这些钱，大家拿去买点肉吧。",
"$N关怀地对众$T道：$s知大家辛苦，我家正好有点粮食，大家就拿去了吧。",
"$N微笑着对众$T道：你们最近生活可好呀？",
"$N激昂地对众$T道：$s知你们生活艰难，下次我一定力柬太守免赋减税。",
"$N诚恳地对众$T道：我国主公当真是体恤百姓的明君呀。",
"$N笑嘻嘻地对众$T道：本地太守政绩突出，百姓的日子当真是越来越好了。",
"$N一抱拳，对众$T道，时辰不早，$s事务繁忙，先行告辞。",
});

nosave private string *good_answer=({
"众$N纷纷点头答道：可不是吗！",
"众$N纷纷点头答道：对呀！",
"众$N纷纷点头答道：那当然啦！",
"$T从钱袋里拿出一两金子交给$N们。\n众$N高兴地跳了起来。",
"$T通知家丁为$N们取一百粮食。\n众$N高兴地跳了起来。",
"众$N笑着道：最近生活过得还不赖。",
"众$N忙不迭地点头道：那太好了！",
"众$N纷纷点头答道：是呀，我们也是这么想的。",
"众$N纷纷点头答道：对，我们一定拥护他。",
"众$N纷纷点头答道：谢谢$R的关怀。",
});

nosave private string *bad_answer=({
"一个$N翻着白眼，答道：勤劳管什么用，还不是给别人白干？！",
"一个$N「呸」了一声，答道：越老实越受欺负，哼。",
"一个$N盯着$T，答道：可还不是只有当官的才能享受？！",
"$T摸了半天口袋，突然道：啊，不好意思，身上没带钱。\n众$N哈哈大笑起来：你蒙谁呀？当官的身上会没钱？",
"$T算计了半天，突然道：啊，不好意思，家里也没有多少粮食了。\n众$N哈哈大笑起来：笑话！当官的家里会没有粮吃？",
"一个$N冷笑道：就差没饿死了。",
"一个$N不屑地道，别信他的。\n众$N纷纷附合道：吹牛，吹牛。",
"一个$N挖苦道：真的吗？\n众$N都「哼哼」冷笑起来。",
"一个$N恨恨地道：是吗？看看我们的样子就知道了。\n众$N都「哼哼」冷笑起来。",
"众$N纷纷答道：早就不想听你的废话，快走，快走。",
});


void judge_select(mixed obs);
void input_way(mixed obs,string str);
void no_answer_way(mixed obs);
void select_way(mixed obs);
void talk_over(mixed obs);
void big_success(mixed obs,mixed vac);
string m_area;

mixed job(string m_id,string officer_id)
{
	object *mlist,ot;
	string target;
	object o=find_body(m_id);
	if(!objectp(o)) return 0; // string
	m_area=CHAR_D->get_char(officer_id,"area");
	target=m_area+" guy";
	ot=CHAR_D->find_npc_char(target);

//Modified By listen to avoid visit fake people
   if(!objectp(ot) || ot->query("is_fake")) 
   {
		target=m_area+" resident";
		ot=CHAR_D->find_npc_char(target);
		if(!objectp(ot) || ot->query("is_fake"))
		{
			target=m_area+" idler";
			ot=CHAR_D->find_npc_char(target);
			if(!objectp(ot) || ot->query("is_fake")){
				o->add_job("visitpeople");	
				o->finish_job("visitpeople");
				return "$N对$T摇摇头，叹道：兵荒马乱，民不聊生，百姓都不知躲哪里去了。\n";
			}
		}
	}
/*
   mlist=children("/sgdomain/modules/m_charnpc/guy");
   if(sizeof(mlist)) {
      mlist=filter_array(mlist,(:$1->get_area()==$(m_area) :));
   }
   if(!sizeof(mlist))
	   return "$N对$T摇摇头，叹道：兵荒马乱，民不聊生，百姓都不知躲哪里去了。\n";

*/

//   ot=mlist[random(sizeof(mlist))];
//   target=ot->query_id()[0];
	ot->set("is_locked",1);
	o->set_asklist("hi","target",target);
	o->set_asklist("hi","filename",PJOB+"visitpeople/visitpeople");
	o->set_asklist("hi","funname","ask_hi");

	o->add_job("visitpeople");
	o->set_job("visitpeople","status","begin");
	o->set_job("visitpeople","memo","探访"+ot->short());
   
   return "$N对$T笑道：国以民为本，就麻烦$R去探访一下"+
	   ot->short()+
	   "，\n见面就说ask "+target+" about hi 。\n";
}
void ask_hi(object me, object target)
{
	mixed ret;
	string m_id;
    string m_title;
	m_id=me->query_id()[0];
	m_area=me->query_room()->get_area();
    m_title=OFFICER_D->query_rank_name(
        (OFFICER_D->query_area_officer_title(
         AREA_D->get_area(m_area,"level"),0,0))[0]);
	me->targetted_action(
      "$N对众$T笑道：过来，过来，本地"+m_title+"特地派$s来探访你们。\n"
	  ,target);

//	ret=target->can_ask_for_join(m_id);
//        if(stringp(ret)) {
//		target->targetted_action(ret,me);
//		return;
//	}

	me->clear_asklist("hi");
	me->set_job("visitpeople","status","done");
	me->set_job("visitpeople","score",10); // meet is 10
	                                      // succ is 50


    if(sizeof(target->query_pure_leader())) {
		target->targetted_action("$N对$T道：我们正忙呢。\n",me);
	   tell_user(m_id,"%^H_GREEN%^反正已经见到面了，应该可以去交差了。\n%^RESET%^");
		target->check_leader();

		return;
	}
	
	DELAY_D->delay_targetted_action(
		target,me,"一个$N道：别不是来抓我们吧。\n"+
		"另一个$N道：不会，$m$R不象是坏人。\n",1);
	
	target->set_leader(m_id); // target will not do nonsence

	me->set_job("visitpeople","topics",({})); //haven't talk yet	                            
	                             // within 10 minute
	call_out("select_way",2,({ me, target}));
	return;
}

void judge_select(mixed obs)
{
    object me=obs[0],tar=obs[1];
	string p_id,t_id,mnation,marea;
	mixed gift;
	int ans=0;
	int safe,score,p_select,meili;

	if(!objectp(me)) {talk_over(obs); return;}
	if(!objectp(tar)) {talk_over(obs); return;}

	p_id=me->query_id()[0];
	marea=me->query_room()->get_area();

	t_id=tar->query_id()[0];
	
	gift=CHAR_D->get_char(p_id,"gift");
	meili=gift["meili"];

	mnation=CHAR_D->get_char(p_id,"nation");
	safe=AREA_D->get_area(marea,"safe");

	score=me->query_job("visitpeople","score");

	p_select=me->query_job("visitpeople","select");

    switch(p_select)
    {
	case 1:
	case 2:
	case 3:
	case 7:
	case 8:
	case 9:
         if(random(30)>meili) 
			 ans=-1;
		 else
			 ans=1;
		 break;
	case 6:
		if(random(100)>safe)
			ans=-1;
		else
			ans=1;
		break;
	case 4:
         if(me->query_all_con_money()<10000) 
			 ans=-1;
		 else
		 {
			 ans=1;
			me->set_all_con_money(
				me->query_all_con_money() -10000 );
		 }
		 break;
	case 5:
		{
		   mixed my_army;
		   my_army=CHAR_D->get_char(p_id,"myarmy");
		   if(!my_army)
		   {   ans=-1;
		   }
		   else
		   {   if((!my_army["food"])||(my_army["food"]<100))
				   ans=-1;
			   else
			   {
				   ans=1;
				   my_army["food"]-=100;
				   CHAR_D->set_char(p_id,"myarmy",my_army);
			   }
		   }
		}
		break;
	case 10:
		ans=-1;
		if(score>10)
			ans=1;
		break;
	default:

		ans=1;
	}
	if(ans==1)
	{
		safe++;
		score+=2;
		tar->targetted_action(good_answer[p_select-1]+"\n",me);
	}
	else
	{
		safe--;
		score-=1;
		tar->targetted_action(bad_answer[p_select-1]+"\n",me);
	}
	AREA_D->set_area(marea,"safe",safe);
	me->set_job("visitpeople","score",score);
	if(p_select==10) // leave;
	{
		call_out("talk_over",1, obs);
		return;
	}
	call_out("select_way",1,obs);
}
void input_way(mixed obs,string str)
{	int p_select;
    object me=obs[0],usr,tar;
	string p_id;
	int *topics;
    remove_call_out("no_answer_way");


	tar=obs[1];
	if(!objectp(tar)) {talk_over(obs); return;}
	if(!tar->check_leader()) {talk_over(obs); return;}

	p_select=to_int(str);
	if(!objectp(me)) { talk_over(obs); return; }


    if((p_select<1)||(p_select>10)) return;
 	topics=me->query_job("visitpeople","topics");

    if(member_array(p_select,topics)!=-1)
    {  tell(me,"这个话题已经谈过了，得换一个。\n");
       call_out("no_answer_way",30,obs);

       return;
    }

	p_id=me->query_primary_id();
	usr=find_user(p_id);
    if(objectp(usr)) 
	    usr->modal_pop();


    me->targetted_action(sug[p_select-1]+"\n",tar);
	me->set_job("visitpeople","select",p_select);
	topics+=({p_select});
	me->set_job("visitpeople","topics",topics);
    call_out("judge_select",1,obs );
}

void no_answer_way(mixed obs)
{ input_way(obs,"10");
}

void select_way(mixed obs)
{
   object me=obs[0],usr;
   string p_id;
   if(!objectp(me)) {talk_over(obs); return; }
   p_id=me->query_id()[0];
   usr=find_user(p_id);
   if(!objectp(usr)) return;
   tell_user(p_id,"你的工作就是哄他们开心。\n"+
"〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n"+
" 1 称赞勤劳  2 称赞忠厚  3 称赞能干  4 赠送黄金  5 赠送粮食 \n"+
" 6 体察民心  7 答应减税  8 夸奖国君  9 夸奖太守 10 告辞     \n"+
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
        tar=obs[1];
        if(objectp(tar)) {
                t_id=tar->query_id()[0];
                tar->responda("wave");
                tar->simple_action("$N离开了。\n");
			    tar->do_my_dispear();

        }
        if(!objectp(me)) return;
        p_id=me->query_id()[0];

	tell_user(p_id,"%^H_GREEN%^任务完成得不错，快去太守处领赏吧。\n%^RESET%^");
}

// the job of some body in this area
// by fire on Jan 1999
mixed job(string m_id,string officer_id)
{
   string m_area=CHAR_D->get_char(officer_id,"area");
   string *mlist,target;
   object o=find_body(m_id);
   object env,*obs;
   printf("jin le job() m_id = %s officer_id = %s m_area = %s\n",m_id,officer_id,m_area);
   mlist=CHAR_D->check_char("area",m_area);
   	printf("mlist = ");
	foreach(string temp in mlist)
		printf("%s ", temp);
	printf("\n");
   
   if(!mlist) mlist=({});
   mlist-=({m_id});
   mlist-=({officer_id});
    printf("mlist = ");
	foreach(string temp1 in mlist)
		printf("%s ", temp1);
	printf("\n");

   if(!objectp(o)) return 0; // string
   env=environment(o);
   obs=all_inventory(env);
   if(sizeof(obs))
   {
	   foreach(object p_o in obs)
	   {
			if(p_o->is_living())
				mlist-=({p_o->query_id()[0]});
	   }
   }

   if(!sizeof(mlist)){
		o->add_job("findbody");
		o->finish_job("findbody");
		return "$N对$T道：现在没谁好找呀。\n";
	}
   target=mlist[random(sizeof(mlist))];
   o->set_asklist("come","target",target);
   o->set_asklist("come","filename",PJOB+"findbody/findbody");
   o->set_asklist("come","funname","ask_come");

  o->add_job("findbody");
  o->set_job("findbody","status","begin");
  o->set_job("findbody","memo","找"+CHAR_D->get_char(target,"name")+"("+target+")");
   
   return "$N对$T道：那就麻烦$R去帮我找一下"+
	   CHAR_D->get_char(target,"name")+"("+target+")"+
	   "，\n见面就说ask "+target+" about come 。\n";
}
void ask_come(object me, object target)
{
	string m_area,m_id;
    string m_title;
	m_id=me->query_id()[0];
	m_area=CHAR_D->get_char(m_id,"area");
    m_title=OFFICER_D->query_rank_name(
        (OFFICER_D->query_area_officer_title(
         AREA_D->get_area(m_area,"level"),0,0))[0]);
	me->targetted_action(
      "$N对$T笑着说道：本地"+m_title+"有请$R\n",target);
	DELAY_D->delay_targetted_action(
		target,me,"$N对$T道：知道了，随后就去，谢谢$R。\n",1);
	me->clear_asklist("come");
	me->set_job("findbody","status","done");
	tell_user(m_id,"%^H_GREEN%^任务完成，快去太守处领赏吧。\n%^RESET%^");
	return;
}

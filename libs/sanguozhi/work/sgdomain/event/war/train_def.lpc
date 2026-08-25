// train_def.c
// by fire on Dec 17
string auto_start_point(string p_area,string p_side);
void train_arrange_defence(int task_id)
{
    int m_num=0,*m_troops,troop_id;
	int morale,train;
    mixed att_party=({}),att_army=({});
    object o_troop;
    string p_area,l_id,p_baseroom;
    p_area=TASK_D->get_task(task_id,"def_area");
    p_baseroom=AREA_D->get_area(p_area,"path")+"warroom/";
    m_troops = TASK_D->get_task(task_id,"def_army");
    if ( sizeof( m_troops ) > 0 )
    {
        foreach(int t in m_troops)
           m_num+=TROOP_D->get_troops(t,"total_num");
    }
    
	morale=AREA_D->get_area(p_area,"morale");
	train=AREA_D->get_area(p_area,"train");
    l_id=p_area+" trainee";
    att_party+=({l_id});
    CHAR_D->add_char(l_id);
    CHAR_D->set_char(l_id,"wuli",1);
    CHAR_D->set_char(l_id,"zhimou",1);
    CHAR_D->set_char(l_id,"meili",1);

    CHAR_D->set_char(l_id,"name","假设敌将");

    TASK_D->set_task(task_id,"att_leader",l_id);
    TASK_D->add_char(task_id,l_id,0);
    CHAR_D->set_char(l_id,"is_tmp",1);
    o_troop=TROOP_D->new_troop("假设敌军",({l_id}),0
      ,p_baseroom+auto_start_point( p_area,"a"));
   troop_id=o_troop->get_id();
   TROOP_D->set_troops(troop_id,"task_id",task_id);
   att_army+=({troop_id});
   TROOP_D->add_soldier(troop_id,"infantry",
       m_num/10,morale/2,train/2,0);
   TROOP_D->set_troops(troop_id,"side","a");
   TASK_D->set_task(task_id,"att_army",att_army);
   TASK_D->set_task(task_id,"att_party",att_party);
}
void train_arrange_attack(int task_id)
{
    int m_num=0,*m_troops,troop_id,i;
    mixed att_party,att_army;
    object o_troop;
    string p_area,l_id,p_baseroom;
	int morale,train;
   p_area=TASK_D->get_task(task_id,"def_area");

   morale=AREA_D->get_area(p_area,"morale");
	train=AREA_D->get_area(p_area,"train");

   p_baseroom=AREA_D->get_area(p_area,"path")+"warroom/";
    m_troops=TASK_D->get_task(task_id,"def_army");
    if ( sizeof( m_troops ) > 0 )
    {
        foreach(int t in m_troops)
            m_num+=TROOP_D->get_troops(t,"total_num");
    }
    
    att_party=TASK_D->get_task(task_id,"att_party");
    att_army=TASK_D->get_task(task_id,"att_army");
    for(i=1;i<4;++i)
    {
      l_id=p_area+" trainee"+i;
      att_party+=({l_id});
      CHAR_D->add_char(l_id);
      CHAR_D->set_char(l_id,"name","假设敌将");
      CHAR_D->set_char(l_id,"wuli",1);
      CHAR_D->set_char(l_id,"zhimou",1);
      CHAR_D->set_char(l_id,"meili",1);

      TASK_D->add_char(task_id,l_id,0);
      CHAR_D->set_char(l_id,"is_tmp",1);
      o_troop=TROOP_D->new_troop("假设敌军",({l_id}),0
         ,p_baseroom+auto_start_point( p_area,"a"));
      troop_id=o_troop->get_id();
      TROOP_D->set_troops(troop_id,"task_id",task_id);
      att_army+=({troop_id});
      TROOP_D->add_soldier(troop_id,"infantry",
         m_num/20,morale/2,train/2,0);
      TROOP_D->set_troops(troop_id,"side","a");
    }
    TASK_D->set_task(task_id,"att_army",att_army);
    TASK_D->set_task(task_id,"att_party",att_party);
}

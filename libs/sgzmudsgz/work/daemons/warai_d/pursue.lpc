// pursue.c by fire on Dec 1998
// this is inherited by warai_d.c used to control a troop to pursue enemy
string point_tostring(mixed point);
mixed point_toint(string point);
mixed get_neighbor_troops(int t_id,string direction);
mixed find_path(int t_id,string p_targetpoint);
mixed check_move(object troop, object target);
mixed attack_target(int p_id, string direction, string method);
mixed find_attack_target(int p_id);
mixed find_special_attack_target(int t_me,int t_en)
{
   mixed tar=({});     
   mixed mtmp;
   int i,sum;
   mtmp=find_attack_target(t_me);
   sum=sizeof(mtmp);
   if(!sum) return 0;
   for(i=0;i<sum;++i)
   {
      int *t;
      t=get_neighbor_troops(t_me,mtmp[i]["target"]);
      if(member_array(t_en,t)!=-1)
        tar+=({ mtmp[i] });
   }
   if(sizeof(tar)) return tar;
   return 0;
}
void do_command_pursue(int t_id,mixed para)
{
   string p_area,p_side;
   int act=0,test=0;
   string p_target;
   object o_troop,env;
   mixed path,mtmp;
   o_troop=TROOP_D->find_troop(t_id);
   if(!objectp(o_troop)) return;
   p_area=TROOP_D->get_troops(t_id,"area");
   p_side=TROOP_D->get_troops(t_id,"side");
   if(TROOP_D->get_troops(para["aim"],"area")!=p_area)
   {  // no aim to follow
      TROOP_D->set_troops(t_id,"command",0); // now task
   }
   p_target=point_tostring(
       TROOP_D->get_troops(para["aim"],"position"));

   path=para["path"];
   if(!sizeof(path)||(random(5)==0))
	   path=find_path(t_id,p_target);
   while(sizeof(path)&&(test<3))
   {
       string s_tp,arg="";
       int *p_tp,*p_cp;
       int x0,y0,x1,y1;
        p_cp=TROOP_D->get_troops(t_id,"position");
        s_tp=path[0];
        p_tp=point_toint(s_tp);
        x0=p_cp[0];y0=p_cp[1];x1=p_tp[0];y1=p_tp[1];
        if(x1-x0==1) arg+="east";
        if(x1-x0==-1) arg+="west";
        if(y1-y0==1) arg+="south";
        if(y1-y0==-1) arg+="north";
        env=environment(o_troop);
        if(check_move(o_troop, env->query_exit_value(arg))==1)
        {
            o_troop->go_somewhere(arg);
            path-=({s_tp});
            act++;
        }
        test++;
   }
   test=0;
   if(TROOP_D->get_troops(para["aim"],"side")!=p_side) // enemy
   {
      while((act<3)&&(test<3))
      {
         mtmp=find_special_attack_target(t_id,para["aim"]);
         if(mtmp)
         {
            int r=random(sizeof(mtmp));
            attack_target(t_id,mtmp[r]["target"],mtmp[r]["method"]);
            act++;
         }
         test++;
      }
   }
   test=0;
   while((test<3)&&(act<3))
   {
      mtmp=find_attack_target(t_id);
      if(mtmp)
      {
            int r=random(sizeof(mtmp));
            attack_target(t_id,mtmp[r]["target"],mtmp[r]["method"]);
            act++;
      }
      test++;
   }
   para["path"]=path;
   TROOP_D->set_troops(t_id,"command",para);

}

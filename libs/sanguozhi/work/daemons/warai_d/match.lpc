// match.c
// this is inherited by warai_d.c
// this program is used to control a troop's match
string point_tostring(mixed point);
mixed point_toint(string point);
mixed expand_path_r(mapping p_path,string p_target,string p_area,
string p_side);
mixed check_move(object troop, object target);
mixed attack_target(int p_id, string direction, string method);
mixed find_attack_target(int p_id);
int distance(int x,int y,int x1,int y1);
mixed find_path(int t_id,string p_targetpoint)
{
   string p_curpoint;

   string p_area;
   string p_side;
   int *beg,*end;
   mixed p_path=([]);
   p_area=TROOP_D->get_troops(t_id,"area");
   p_curpoint=point_tostring(TROOP_D->get_troops(t_id,"position"));
   if(p_curpoint==p_targetpoint) return 1; //get the point
   beg=point_toint(p_curpoint);
   if(!strlen(p_targetpoint)) return 0;
   end=point_toint(p_targetpoint);

   if(((beg[0]-end[0])>8)||((beg[0]-end[0])<-8)||((beg[1]-end[1])>8)||((beg[1]-end[1])<-8))
	return 0;
//   if(distance(beg[0],beg[1],end[0],end[1])>10) return 0; // if bigger than 0 refuse to search
   p_side=TROOP_D->get_troops(t_id,"side");
   p_path[p_curpoint]=([]);
   p_path[p_curpoint]["step"]=0; // zero fron the source
   p_path[p_curpoint]["leave"]=1; // this is the leave
   p_path[p_curpoint]["pre"]="";
   p_path=expand_path_r(p_path,p_targetpoint,p_area,p_side);
   return p_path;
}
int do_command_match(int t_id,mixed para)
{
   int *p_cp,*p_tp;
   int x0,y0,x1,y1;
   int act=0,test=0;
   string s_tp;
   string arg="";
   object o_troop,env;
   mixed mtmp;
   p_cp=TROOP_D->get_troops(t_id,"position");
   if((!para["path"])||(random(5)==0))
      para["path"]=find_path(t_id,para["target"]);
   if(intp(para["path"])&&(para["path"]==1)) // get the target change to guard
   {
         para["action"]="guard";
         para["position"]=para["target"];
         if(!para["range"]) para["range"]=0;
         map_delete(para,"path");
         map_delete(para,"target");
   } 
   while(sizeof(para["path"])&&(test<3)&&(act<3))
   {      
        s_tp=para["path"][0];
        p_tp=point_toint(s_tp);
        x0=p_cp[0];y0=p_cp[1];x1=p_tp[0];y1=p_tp[1];
        if(x1-x0==1) arg+="east";
        if(x1-x0==-1) arg+="west";
        if(y1-y0==1) arg+="south";
        if(y1-y0==-1) arg+="north";
        o_troop=TROOP_D->find_troop(t_id);
        env=environment(o_troop);
        if(check_move(o_troop, env->query_exit_value(arg))==1)
        {
                o_troop->go_somewhere(arg);
                para["path"]-=({s_tp});
                if(!sizeof(para["path"]))
                        para["path"]=0;
                act++;
        }
        test++;
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
     TROOP_D->set_troops(t_id,"command",para);
}

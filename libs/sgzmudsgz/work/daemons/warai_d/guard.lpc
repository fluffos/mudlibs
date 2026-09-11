// guard.c by fire
// inherited by warai_d.c
// used to control troops auto guard action
int distance(int x,int y,int x1,int y1);
mixed point_toint(string point);
mixed check_move(object troop, object target);
mixed attack_target(int p_id, string direction, string method);
mixed find_attack_target(int p_id);
void do_command_guard(int t_id,mixed para)
{
     int *pos,*tar;
     int d,act=0,test=0;
     mixed mtmp;
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
     if((act<2)&&(para["range"]>0)) // still want to move
     {
        string arg;
        object o_troop,env;
        switch(random(4))
        {     case 0: arg="east";break;
              case 1: arg="west";break;
              case 2: arg="south";break;
              default: arg="north";break;
        }
              
        o_troop=TROOP_D->find_troop(t_id);
        if(!objectp(o_troop)) return;
        env=environment(o_troop);
        if(!objectp(env)) return;
        if(check_move(o_troop, env->query_exit_value(arg))==1)
            o_troop->go_somewhere(arg);
     }
     pos=TROOP_D->get_troops(t_id,"position");
     if(!sizeof(pos)) {SGSYS(sprintf("troop %d 没有位置。",t_id)); return;}
     tar=point_toint(para["position"]);
	 if(!sizeof(tar)) {
		SGSYS(sprintf("tar is %O\n",tar));
		tar=pos;
	 }
     d=distance(pos[0],pos[1],tar[0],tar[1]);
     if(d>para["range"])
     {
         para["action"]="match";
         para["target"]=para["position"];
         map_delete(para,"path");
         TROOP_D->set_troops(t_id,"command",para);
     }
}

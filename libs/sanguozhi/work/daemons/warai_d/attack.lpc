// attack.c
// this is part of warai_d.c
#include <train.h>
void general_attack_kill(int p_id, string dir);
mixed get_neighbor_side(int t_id,string direction);
string get_generl_infomation(int p_id,string dir);
void war_inf(int t_id,string mess,string side);
int get_neighbor_distance(int t_id,string direction);
mixed do_array_attack(int p_id,string direction);
mixed can_array_attack(int p_id,string direction);
mixed do_horse_attack(int p_id,string direction);
mixed can_horse_attack(int p_id,string direction);
mixed do_siege_attack(int p_id,string direction);
mixed can_siege_attack(int p_id,string direction);
void general_attack_kill_back(int p_id,string dir);

mixed can_general_attack(int p_id,string direction)
{
        int *pos;
        int x,y;
        string p_side;
        mixed p_otherside;
        int dis;
        if (TROOP_D->get_troops(p_id,"qibing") )
        TROOP_D->set_troops(p_id,"qibing",0);

        if (TROOP_D->get_troops(p_id,"maifu") )
         TROOP_D->set_troops(p_id,"maifu",0);	

	dis=get_neighbor_distance(p_id,direction);
        if(dis!=1)
                return "攻不到那儿。";
        p_side=TROOP_D->get_troops(p_id,"side");
        p_otherside=get_neighbor_side(p_id, direction);
        if(!p_otherside)
                return "此向没有敌军．\n";
        if(p_side==p_otherside)
                return "怎么能向友军进攻？\n";
        if(TROOP_D->get_soldier_kills(p_id)==-1)
                return "士兵太累了，无法进攻。\n";
        if (TROOP_D->get_troops(p_id, "conds"))
        { if (TROOP_D->get_troops(p_id, "conds")["confuse"])
        return "混乱中，无法攻击。\n";
        }
	return 1;
}
mixed do_general_attack(int p_id,string dir)
{
    string gernal_inf;
    int t_id;
    gernal_inf=get_generl_infomation(p_id,dir); // the attack message
    t_id=TROOP_D->get_troops(p_id,"task_id");   
    war_inf(t_id,gernal_inf,"b"); // both side
    general_attack_kill(p_id, dir);
    TROOP_D->general_attack_consume(p_id);
     general_attack_kill_back(p_id,dir);
}
mixed attack_target(int p_id, string direction, string method)
{
    switch(method)
    {
        case "general attack":
           do_general_attack(p_id,direction);
		   troop_busy( p_id,ATTACK_BUSY_TIME,"部队正在进攻。\n") ;
           return 1;
        case "mixed * attack":
			do_array_attack(p_id,direction);
// edc 08/15/2001  add more busy time to array
/*		   troop_busy( p_id,ARRAY_BUSY_TIME,"部队正在弓箭进攻。\n") ;  */
		   troop_busy( p_id, 5,"部队正在弓箭进攻。\n") ;
////		   
           return 1;
        case "horse attack":
           do_horse_attack(p_id,direction);
		   troop_busy( p_id,HORSE_BUSY_TIME,"部队正在冲锋。\n") ;
           return 1;
        case "siege attack":
           do_siege_attack(p_id,direction);
		   troop_busy( p_id,SIEGE_BUSY_TIME,"部队正在围攻。\n") ;
	   return 1;
    }
    SGSYS("没有"+method+"这种进攻方式。");
	return 0;
}
// to find all the attack target and the way to attack
mixed find_attack_target(int p_id)
{
   mixed * ret=({});
   mixed * dir=({"e","w","s","n"});
   mixed res;
   int tmp;
   foreach(string d in dir)
   {
      mapping mtmp=([]);
      res=can_general_attack(p_id,d);
      if(res==1)
      {
        mtmp["target"]=d;
        mtmp["method"]="general attack";
        ret+=({mtmp});
      }
      res=can_horse_attack(p_id,d);
      if(res==1)
      {
        mtmp["target"]=d;
        mtmp["method"]="horse attack";
        ret+=({mtmp});
      }
      res=can_siege_attack(p_id,d);
      if(res==1)
      {
        mtmp["target"]=d;
        mtmp["method"]="siege attack";
        ret+=({mtmp});
      }
    }
    tmp=TROOP_D->get_array_kills(p_id);
    if(tmp>0)
    {
// edc cancel array e,w,s,n attack  purpose: to discrease bowman power
/*        dir=({"e","w","s","n","e 2","w 2","s 2","n 2","nw","ne","sw","se",});
*/
	dir=({"e 2","w 2","s 2","n 2","nw","ne","sw","se",});
////
        foreach(string d in dir)
        {
           mapping mtmp=([]);
           res=can_array_attack(p_id,d);
           if(res==1)
           {
              mtmp["target"]=d;
              mtmp["method"]="mixed * attack";
              ret+=({mtmp});
           }
         }
      }
    if(sizeof(ret))
        return ret;
    return 0; 
}

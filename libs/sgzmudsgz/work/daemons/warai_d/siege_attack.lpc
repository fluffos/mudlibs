// siege_attack.c by fire on Nov 1998
// this is inherited by warai_d.c
void siege_attack_kill(int p_id, string dir);
string get_siege_attack_infomation_b(int p_id,string dir,mixed seg);
string get_siege_attack_infomation(int p_id,string dir,mixed seg);
int kill_troops(mixed t,int p_kill);
void clear_empty_troop(int* t);
mixed get_neighbor_side(int t_id,string direction);
void war_inf(int t_id,string mess,string side);
void info_troop(int p_id,string mess);
mixed get_neighbor_defence_rate(int t_id,string direction);
mixed get_neighbor_troops(int t_id,string direction);
mixed can_general_attack(int p_id,string direction);
void general_attack_kill_back(int p_id,string dir);
// this function can only called after can_seige_attack is right
mixed get_siege_attack(int p_id,string direction)
{
     int e_id=get_neighbor_troops(p_id,direction)[0];
     string e_side=TROOP_D->get_troops(e_id,"side");
     mixed * dir=({"e","w","s","n"});
     mixed * bdir=({"w","e","n","s"});
     mixed ret=([]);
     int i;
     for(i=0;i<4;++i)
     {
         mixed * t=get_neighbor_troops(e_id,dir[i]);
         if(!sizeof(t)) continue;
         if((TROOP_D->get_troops(t[0],"side"))==e_side)
	    continue;
         foreach(int m_t in t)
         {  
            int p_kill;
	    if(can_general_attack(m_t,bdir[i])!=1)
		continue;
            if(!ret[dir[i]])
           {
               ret[dir[i]]=([]);
               ret[dir[i]]["kill"]=0;
               ret[dir[i]]["troop"]=({});
	    }
//            p_kill=TROOP_D->get_troop_attack_kills(m_t);
			p_kill=TROOP_D->get_attack_rate(p_id,"general");
            ret[dir[i]]["kill"]+=p_kill;
            ret[dir[i]]["troop"]+=({m_t});
         }     
     }
     return ret;    
}
mixed can_siege_attack(int p_id,string direction)
{
        int *pos;
        int x,y;
        string p_side;
        mixed p_otherside;
        int dis;
        int tmp;

        if (TROOP_D->get_troops(p_id,"qibing") )
        TROOP_D->set_troops(p_id,"qibing",0);

        if (TROOP_D->get_troops(p_id,"maifu") )
         TROOP_D->set_troops(p_id,"maifu",0);

	tmp=can_general_attack( p_id, direction);
        if(tmp!=1) return tmp;
	tmp=get_siege_attack( p_id, direction);
        if(sizeof(tmp)<=1) return "没有足够的部队围攻敌方。\n";
        if (TROOP_D->get_troops(p_id, "conds"))
        { if (TROOP_D->get_troops(p_id, "conds")["confuse"])
        return "混乱中，无法攻击。\n";
        }
	return 1;
}
mixed do_siege_attack(int p_id,string dir)
{
    string gernal_inf;
    int t_id;
    mixed seg;
    int p_kill=0,p_defrate;
    int p_dir,i;
    string *p_dirs;
    mixed t; 
    t_id=TROOP_D->get_troops(p_id,"task_id"); 
    seg=get_siege_attack( p_id, dir);
    gernal_inf=get_siege_attack_infomation(p_id,dir,seg);
    war_inf(t_id,gernal_inf,"b"); // both side
    p_dir=sizeof(seg);
    p_dirs=keys(seg);
    for(i=0;i<p_dir;++i)
    {  p_kill+=seg[p_dirs[i]]["kill"];
       foreach(int m_t in seg[p_dirs[i]]["troop"])
           TROOP_D->general_attack_consume(m_t);	
    }
    
    t=get_neighbor_troops(p_id,dir);
    p_kill*=(p_dir+1);
    p_kill/=3; // cut down the power of siege
    
    p_kill=TROOP_D->attack_troops(t,p_kill,"array");

    for(i=0;i<p_dir;++i)
    {
      info_troop(seg[p_dirs[i]]["troop"][0],gernal_inf);
      info_troop(seg[p_dirs[i]]["troop"][0],"%^H_GREEN%^歼灭敌军"+
      CHINESE_D->chinese_number(p_kill)+"人．%^RESET%^\n");
    }
    gernal_inf=get_siege_attack_infomation(p_id,dir,seg);
    info_troop(t[0],gernal_inf);
    info_troop(t[0],"%^H_RED%^我方损失"+
      CHINESE_D->chinese_number(p_kill)+"人．%^RESET%^\n");
    clear_empty_troop(t);
	general_attack_kill_back(p_id,dir);
}

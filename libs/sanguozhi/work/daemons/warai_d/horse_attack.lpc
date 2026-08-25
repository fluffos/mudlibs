// horse_attack.c by fire on Nov 1998
// this is inherited by warai_d.c
void horse_attack_kill(int p_id, string dir);
string get_horse_attack_infomation_b(int p_id,string dir);
string get_horse_attack_infomation(int p_id,string dir);
int kill_troops(mixed t,int p_kill);
void clear_empty_troop(int* t);
int get_neighbor_distance(int p_id,string direction);
mixed get_neighbor_side(int t_id,string direction);
void war_inf(int t_id,string mess,string side);
void info_troop(int p_id,string mess);
void add_war_lose(int t_id,string p_side,string wat,int num);
mixed get_neighbor_defence_rate(int t_id,string direction);
mixed get_neighbor_troops(int t_id,string direction);
void general_attack_kill_back(int p_id,string dir);

mixed can_horse_attack(int p_id,string direction)
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
	
	tmp=TROOP_D->get_horse_kills(p_id);
        if(tmp==0) // no bowman
            return "你没有骑兵。\n";
        if(tmp==-1) // two tired
            return "骑兵太累了。\n";
        if((!direction)||(direction==""))
            return "向哪冲锋\n";
        dis=get_neighbor_distance(p_id,direction);
        if(dis>1)
                return "冲锋不到那儿。";
        p_side=TROOP_D->get_troops(p_id,"side");
        p_otherside=get_neighbor_side(p_id, direction);
        if(!p_otherside)
                return "此向没有敌军．\n";
        if(p_side==p_otherside)
                return "怎么能向友军冲锋？\n";
        if (TROOP_D->get_troops(p_id, "conds"))
        { if (TROOP_D->get_troops(p_id, "conds")["confuse"])
        return "混乱中，无法攻击。\n";
        }
	return 1;
}
mixed do_horse_attack(int p_id,string dir)
{
    string gernal_inf;
    int t_id;
    gernal_inf=get_horse_attack_infomation(p_id,dir);
    t_id=TROOP_D->get_troops(p_id,"task_id");   
    war_inf(t_id,gernal_inf,"b"); // both side
    horse_attack_kill(p_id, dir);
    TROOP_D->horse_attack_consume(p_id);
	general_attack_kill_back(p_id,dir);

}
void horse_attack_kill(int p_id, string dir)
{
    string mess;
    int p_kill,p_defrate;
    int *t;
	p_kill=TROOP_D->get_attack_rate(p_id,"horse");
    t=get_neighbor_troops(p_id,dir);
    
    // xiaobai: increase the horse power
//    p_kill *= 1.1;
    
	p_kill=TROOP_D->attack_troops(t,p_kill,"horse");

    mess=get_horse_attack_infomation(p_id,dir);
    info_troop(p_id,mess);
        info_troop(p_id,"%^H_GREEN%^歼灭敌军"+
    CHINESE_D->chinese_number(p_kill)+"人．%^RESET%^\n");
    mess=get_horse_attack_infomation_b(p_id,dir);
    info_troop(t[0],mess);
    info_troop(t[0],"%^H_RED%^我方损失"+
      CHINESE_D->chinese_number(p_kill)+"人．%^RESET%^\n");
    clear_empty_troop(t);

}

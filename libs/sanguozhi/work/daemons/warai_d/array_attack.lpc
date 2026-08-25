// array_attack.c by fire on Nov 1998
// this is inherited by warai_d.c
int kill_troops(mixed t,int p_kill);
void clear_empty_troop(int* t);
void array_attack_kill(int p_id, string dir);
int get_neighbor_distance(int p_id,string direction);
string get_array_attack_infomation_b(int p_id,string dir);
string get_array_attack_infomation(int p_id,string dir);
mixed get_neighbor_side(int t_id,string direction);
void war_inf(int t_id,string mess,string side);
void info_troop(int p_id,string mess);
string get_generl_infomation(int p_id,string dir);
string get_generl_infomation_b(int p_id,string dir);
void add_war_lose(int t_id,string p_side,string wat,int num);
mixed get_neighbor_defence_rate(int t_id,string direction);
mixed get_neighbor_troops(int t_id,string direction);
void general_attack_kill_back(int p_id,string dir);

mixed can_array_attack(int p_id,string direction)
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

	tmp=TROOP_D->get_array_kills(p_id);
        if(tmp==0) // no bowman
            return "你没有弓兵。\n";
        if(tmp==-1) // two tired
            return "弓兵太累了。\n";
        if((!direction)||(direction==""))
            return "射哪? \n";
        dis=get_neighbor_distance(p_id,direction);
// edc change bowman attack distance from {1,2} to 2 only.
/*        if(dis>2)
*/
	if (dis != 2)
////	
                return "射不到那儿。";
        p_side=TROOP_D->get_troops(p_id,"side");
        p_otherside=get_neighbor_side(p_id, direction);
        if(!p_otherside)
                return "此向没有敌军．\n";
        if(p_side==p_otherside)
                return "怎么能射友军？\n";
        if (TROOP_D->get_troops(p_id, "conds"))
        { if (TROOP_D->get_troops(p_id, "conds")["confuse"])
        return "混乱中，无法攻击。\n";
        }
	return 1;
}
mixed do_array_attack(int p_id,string dir)
{
    string gernal_inf;
    int t_id;
    string p_strDefLeader;  // 防守方主帅 id
    int is_PureNpc = 0;

    gernal_inf=get_array_attack_infomation(p_id,dir);
    t_id=TROOP_D->get_troops(p_id,"task_id");   
    war_inf(t_id,gernal_inf,"b"); // both side
    array_attack_kill(p_id, dir);
    TROOP_D->array_attack_consume(p_id);
// edc 08/04/2001
    // add 自动反射击 for npc or offline char defending
    p_strDefLeader = TASK_D->get_task(TROOP_D->get_troops(p_id, "task_id"), "def_leader");
    is_PureNpc = ( CHAR_D->get_char_status( p_strDefLeader ) != STATUS_ONLINE );
    
    if ( is_PureNpc && ( TROOP_D->get_troops(p_id,"side")=="a" ) )
    // defending leader is offline
    {
    	general_attack_kill_back( p_id, dir );
    }
////    
}
void array_attack_kill(int p_id, string dir)
{
    string mess;
    int p_kill,p_defrate;
    int *t;
    p_kill=TROOP_D->get_array_attack_kills(p_id);
    p_defrate=get_neighbor_defence_rate(p_id,dir)+1;
// edc 08/15/2001 array too powerful
/*    p_kill=p_kill*10/p_defrate; */
/*    p_kill=p_kill*2/p_defrate; */
    // xiaobai: after adjusting the soldier number, let kill be about 2 of the kill_back
    p_kill = p_kill*16/p_defrate;
////    
    if(TROOP_D->get_troops(p_id,"side")=="d")
       p_kill*=DEF_KILL_MORE;
    t=get_neighbor_troops(p_id,dir);
    p_kill=kill_troops(t,p_kill);
    mess=get_array_attack_infomation(p_id,dir);
    info_troop(p_id,mess);
        info_troop(p_id,"%^H_GREEN%^歼灭敌军"+
    CHINESE_D->chinese_number(p_kill)+"人．%^RESET%^\n");
    mess=get_array_attack_infomation_b(p_id,dir);
    info_troop(t[0],mess);
    info_troop(t[0],"%^H_RED%^我方损失"+
      CHINESE_D->chinese_number(p_kill)+"人．%^RESET%^\n");
    clear_empty_troop(t);
}

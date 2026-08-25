// horse.c by fire on Nov 1998
// inherited by troop_d.c
// this is used to handle array part of an armyint get_troop_attack_area_rate(int p_id);
int get_troop_attack_area_rate(int p_id);
int get_general_kills(int p_id);
int get_leadrate(int p_id);
int get_horse_kills(int p_id) // not real number
{
    mixed p_soldiers;
    int p_kills;
    int p_m,p_t,p_n;
    int p_r,p_k;
    p_soldiers=TROOP_D->get_soldier(p_id,"cavalry");
    if(!p_soldiers) // no cavalry
        return 0;  
    if(p_soldiers["energy"]<HORSE_ATTACK_CONSUME)
        return -1; // two tired to attack
    p_r=WARAI_D->get_horse_attack_rate();
    p_n=TROOP_D->adj_num( p_soldiers["number"] );  // xiaobai: adjust the soldier number
    p_m=p_soldiers["morale"];
    p_t=p_soldiers["train"];
    p_k=p_n*p_r*(p_m+p_t)/200/10/10;
    p_kills+=p_k+1;
    return p_kills;
}
int get_horse_attack_kills(int p_id) // real number of one array attack
{
   int p_area_rate;
   int p_kills,p_leadrate;
   int p_general_kills;
   p_area_rate=get_troop_attack_area_rate( p_id);
   p_kills=get_horse_kills(p_id);
   p_leadrate=get_leadrate(p_id);
   p_kills=p_kills*p_leadrate/200; 
   p_general_kills=get_general_kills(p_id); 
   p_kills+=p_general_kills;
   p_kills=p_kills*p_area_rate/5;
   return p_kills;
}

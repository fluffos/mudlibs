// consume.c
// this is consume energy
void general_attack_consume(int p_id)
{
   mixed p_soldier;
   p_soldier=TROOP_D->get_troops(p_id,"soldier");
   if(sizeof(p_soldier))
   {
      int i=0,sum=sizeof(p_soldier);
      string *s_typ;
      s_typ=keys(p_soldier);
      for(i=0;i<sum;++i)
      {
         if(p_soldier[s_typ[i]]["energy"]>=GENERAL_ATTACK_CONSUME)
             p_soldier[s_typ[i]]["energy"]-=GENERAL_ATTACK_CONSUME;
      }
      TROOP_D->set_troops(p_id,"soldier",p_soldier);
  }
}
void array_attack_consume(int p_id)
{
   mixed p_soldier;
   p_soldier=TROOP_D->get_troops(p_id,"soldier");
   if(p_soldier["bowman"])
   {
        p_soldier["bowman"]["energy"]-=ARRAY_ATTACK_CONSUME;
   }
   TROOP_D->set_troops(p_id,"soldier",p_soldier);
}
void horse_attack_consume(int p_id)
{
   mixed p_soldier;
   p_soldier=TROOP_D->get_troops(p_id,"soldier");
   if(p_soldier["cavalry"])
   {
        p_soldier["cavalry"]["energy"]-=HORSE_ATTACK_CONSUME;
   }
   TROOP_D->set_troops(p_id,"soldier",p_soldier);
}

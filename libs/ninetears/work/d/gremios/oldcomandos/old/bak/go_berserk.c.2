#include "tweaks.h"
int BOVINES;
int TIME;
int save_hb;

int go_berserk()
{
 
  int BONUS, i;
   if((this_player()->query_gp() < 2)||(this_player()->query_con() < 6))
   {
   write("You are too tired to go berserk.\n");
   return 1;
   }
 
  BOVINES=this_player()->query_wimpy();
    BONUS=((int)this_player()->query_level()/3)+2;
  TIME=1+(int)(this_player()->query_gp())/2;
   if(this_player()->query_hb_diff(save_hb) < ((TIME * 5)+ BERSERK_LOCKOUT) )
   {
      write("You can't seem to get really annoyed just yet.\n");
      return 1;
   }
   save_hb = this_player()->query_hb_counter();
  this_player()->set_gp(0);
   this_player()->adjust_tmp_damage_bon(BONUS);
   this_player()->adjust_tmp_tohit_bon(BONUS);
   this_player()->adjust_tmp_ac_bon(-4);
   for(i=0;i<TIME;i++)
   call_out("attack_all",i*5,this_player(),(TIME-i));
   call_out("end_berserk",TIME*5,this_player());
  return 1;
 
}
 
attack_all(object ob, int NOW)
{
 object *cows;
 int x;
   int attacked;
  ob->set_wimpy(0);
 
   ob->add_property("flipped",NOW);
  if(ob->query_gp()) { ob->set_gp(0); }
 cows=all_inventory(environment(ob));
  if(!(ob->query_property("dead")))
  for(x=0; x<sizeof(cows); x++)
 {
      if(!(cows[x]->query_property("dead")))
    {
      ob->attack_ob(cows[x]);
      attacked = 1;
  }
 }
 attacked = 0;
  if(ob->query_attacker_list())
 {
  say(ob->query_cap_name()+" screams in Berserk rage!\n");
 }
// just in case the call outs get screwed up, we'll try to kill it here
}
 
end_berserk(object ob)
{
 int BONUS;
// in case this call_out arrived late :)
// and the others over-ran
   if(!(this_player()->query_property_exists("flipped")))    return;
 
  ob->set_wimpy(BOVINES);
   write("You become exhausted and are no longer berserk.\n");
    BONUS=((int)this_player()->query_level()/3)+2;
 ob->adjust_tmp_ac_bon(4);
   /* Making sure we DON'T kill them here */
   if(ob->query_con() > 3)
       ob->adjust_tmp_con(-2);
 ob->adjust_tmp_damage_bon(-(BONUS));
 ob->adjust_tmp_tohit_bon(-(BONUS));
    ob->remove_property("flipped");
}
 

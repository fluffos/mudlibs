#include <security.h>
#include <ansi.h>

#include "/obj/player/nrpoints.h"

void check_for_update(string name, object player)
{
  return;
}

/* Make sure to add a check to this part for calling object */
void add_party_points(object* party, object leader)
{
  int i, amount, bonus;

  i = sizeof(party);
  if (i < 2) return;
  if (object_name(previous_object()) != "obj/partymaster")
  {
    log_file("NP_VIOLATIONS", ctime() +
             ": " + (string)this_player()->query_real_name() +
             " tried to add points using party method.\n");
    return;
  }
  amount = i * (10 + random(21));
  bonus = 10 + random(i * 4);

  while (i--)
  {
    if (!objectp(party[i])) continue;
    tell_object(party[i], HIG +
                "\nNirvana Rewards Points given for partying: " + amount +
                "!\n");
    if (party[i] == leader) 
      tell_object(leader, HIG + "You receive a bonus of " + bonus +
                  " points!\n\n"+NORM);
    else
      tell_object(party[i], "\n"+NORM);

    party[i]->add_nrpoints(amount);
    leader->add_nrpoints(bonus);
  }
}

/******************************************************************************
 * Procedure: get_exp_required
 *
 * Purpose: Calculates the required exp for the current level and takes a 
 *          percentage of it. This is the exp required in order to gain the
 *          weekly login reward.
 * History:
 *          08/04/2016 - Dragnar
 *            Created
 ******************************************************************************/
int get_exp_required( object player ) {
  int  ret, lev, xlev;
  string where;
  
  if( !player )
    return 0;
  
  lev = (int) player->query_level();
  
  if(lev == 19) {
    xlev=(int) player->query_extra_level();
    if( xlev == 100 )
      xlev--;
    where = EXLV_GUILD;
  }
  else
    where = ADV_GUILD;
  
  /** Level 19, no extra levels **/
  if(lev == 19 && xlev == 0) {
    ret=( (int) EXLV_GUILD->get_next_exp( xlev ) - (int) ADV_GUILD->get_next_exp(lev-1) );
  }
  else if(lev == 19 && xlev > 0) {
    ret=( (int) where->get_next_exp(xlev) - (int) where->get_next_exp(xlev - 1) );
  }
  else {
    ret=( (int) where->get_next_exp(lev) - (int) where->get_next_exp(lev - 1) );
  }
  
  ret /= 2;
  
  if( ret > WEEKLY_MAX )
    ret = WEEKLY_MAX;
  
  if( ret < 0 ) 
    ret = 0;
  
  return ret;
}

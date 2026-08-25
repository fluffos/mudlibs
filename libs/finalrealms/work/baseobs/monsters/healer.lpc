/* James, a high priest for the raiseroom.
 * will be on of a staff of two in the collect / raise dead hospitals.
 * this will be the guy that conducts the raising.
 * Maybe make it a girl. 
 */

#define SPELL "/std/spells/cleric/raise_dead"

inherit "/obj/monster";

void setup()
  {
set_name("james");
  set_short("james");
  set_long("James is an elder man. He is wearing a stylish white " 
           "ceremonial dress.\n");
  //set_race("human");
  set_gender(1);
  //set_class("taniwha");
  set_race_ob("/std/races/human");
  //set_guild_ob("/std/guilds/priests/taniwha");
  set_guild_ob("/std/guilds/cleric");
  set_level(15);
  set_max_gp(100);
  adjust_gp(100);
  /* This won't work right now, I have to find out why!
   * Baldrick.*/
  //this_object()->add_spell("raise dead", "raise_dead");
} /* setup */

int do_raising(object player)
  {
  if(player->query_property("noregen")) {
  tell_object(player,"Death is not finished with you.  Wait for "
              "a time.\n");
  return 0;
  }
//  say("James raises his hands.\n");
   tell_room(environment(this_object()),"The healer raises his hands, summons the powers of the gods, and you appear again in mortal form!\n");
  /* This won't work even If I manage to give James the spell! */
  //command ("cast raise dead " + player->query_name());

  /* The 'hack': 
   * ARGH!!!!!!!!!!!  Not this one either!
   */
  //SPELL->cast_spell(player->query_name());
   player->remove_ghost();
/* Removed to player.c Taniwha 1995
   player->remove_property("dead");
   player->adjust_max_lives(1);
   player->adjust_con(-1);
*/
return 1; // you forgot this.. -randor, 19-mar-98
} /* int do raising. */

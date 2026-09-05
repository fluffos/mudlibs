/*  an example for a simple npc who is able to react on feelings and
 *  gives a good instance for the most-used event, the move event.
 */

#include <message.h>  // macros for messages in set_feeling_reaction
#include <event.h>    // macros for events

inherit "complex/npc";  // a normal obj/monster with some specials

void handle_move(mapping event) {
  if (event[E_AGENT] == this_object())
    return;  // if this object moves, don't react;

  if (interactive(event[E_AGENT]) &&
      event[E_TO] != environment(this_object()))
    if (member(explode(program_name(event[E_TO], "/")), "example") >-1 ) 
      this_object()->move_living(event[E_DIR], event[E_TO]);
/*  if moving object is a player and the goal of the move isn't the 
 *  of this_object(): check the goal of the move, if the name example
 *  is in the name of the file, then move this_object() into direction
 *  to the goal... short: the cat follows every player in each of my
 *  rooms.
 */
  
}

void reset(status arg) {
  if (!clonep())
    return;  // we only want clones
  ::reset(arg);
  if (arg)
    return;
  set_name("cat");
  set_short("a little cat");
  set_long("This is a cute little cat. She looks young and fresh.\n");
  set_female();   // set the stats
  set_level(3);
  set_str(4);
  set_dex(5);
  set_int(6);
  set_con(2);
  set_hp(58);
  set_sp(90);
  set_al(150);
  set_ep(5000);
  set_aggressive(0);
  set_property("msgin", "walks in");  // messages for the review of the cat
  set_property("msgout", "walks");
  set_property("mmsgin", "jumps in");
  set_property("mmsgout", "jumps");
  set_feeling_reaction(
    ({ "stroke", "caress", "hug", "cuddle", "ruffle", "snuggle" }),
    ({ ({ "The cat purrs contently." }) }));
/*  on stroke, caress, hug, etc. the cat will react with purring */
  set_feeling_prevention(
    ({ "kick", "slap", "strangle", "hit", "knee" }),
    ({ ({ "The cat avoids ", M_PLAYER_S, " try to ", #'query_verb, " her."}) })
  );
/* noone is able to kick, slap, strangle, the cat due to this prevention */
  set_feeling_reaction(
    ({ "kiss", "lick" }),
    ({ ({ "The cat looks surprised at ",M_PLAYER," and licks ",
          M_PL_OBJECTIVE," surprisingly, too." }) })
  );
  set_feeling_reaction(
    ({ "giggle", "tickle", "laugh", "fall", "rotfl", "snicker", "smile" }),
    ({ ({ "The cat purrs at ",M_PLAYER,"." }) })
  );
  load_chat(4,
    ({ "The cat rolls around, playing with something invisible.\n",
       "You are surprised as the cat jumps up and lands silently again.\n",
       "The cat walks between your feet.\n",
       "A loud purring can be heard from the little cat.\n",
       "The cat snuggles up to you.\n" })
  );
  listen_event("move",0,#'handle_move);  
/* check the move-event in the function handle_move with priority 0
 * that means, we react after the move, priority 100 would check before the
 * move (if you want to prevent moves for instance)
 */
}


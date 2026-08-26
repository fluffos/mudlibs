/**
 * This is the effect skelton docs.  This effect
 * has a classification of "object.stardust".
 * <p>
 * Describe the arguments in here.
 * @classification object.stardust
 * @see help::effects
 */
#include <effect.h>

void merge_effect(object player, mixed old_arg, mixed new_arg)
{
   int tt;

   tt = (int)player->expected_tt();
    /* changed to 'player->submit_ee() - Manshoon */
   player->submit_ee(0, new_arg * 2 / 3 + tt, EE_REMOVE);
}

/** @ignore yes */
void beginning( object player, int time, int id ) {
   if (time == 0) {
      /* Make up our own time... */
      time = 30*60;
   }

   /* about every 7 minutes... */
   player->submit_ee( "create_shimmer", ({ 2*60, 2*60 }), EE_CONTINUOUS );
   player->submit_ee( 0, time, EE_REMOVE );
   player->add_extra_look(this_object());
} /* beginning() */

/** @ignore yes */
void end( object player, int time, int id ) {
   object room;
   string env_string;
   object *ignore;

   room = environment(player);
   env_string = player->the_short();
   ignore = ({ });

   player->remove_extra_look(this_object());
   if (room == environment(player) && living(player)) {
         tell_object(player, env_string+" have the last shimmering "
                             "stardust fall off your face, sparkle for "
                             "an instant and disappear.\n");
         ignore += ({ player });
         tell_room(room, env_string+" has the last shimmering stardust "
                         "fall off "+player->query_possessive()+
                         " face, sparkle for an instant and disappear.\n", ignore);
      } else if (living(player)) {
         tell_room(room, env_string+" has the last shimmering stardust "
                         " fall off "+player->query_possessive()+
                         " face, sparkle for an instant and disappear.\n", ignore);
      } else {
         tell_room(room, env_string+" has the last shimmering stardust "
                         "fall off it, sparkle for an instant and disappear.\n", ignore);
      }
} /* end() */
 
void create_shimmer( object player, int time, int id ) {
   object room;
   string env_string;
   object *ignore;

   room = environment(player);
   env_string = player->the_short();
   ignore = ({ });
      if (room == environment(player) && living(player)) {
         tell_object(player, env_string+" have some bits of shimmering "
                             "stardust fall off your face, sparkle for "
                             "an instant and disappear.\n");
         ignore += ({ player });
         tell_room(room, env_string+" has some bits of shimmering stardust "
                         "fall off "+player->query_possessive()+
                         " face, sparkle for an instant and disappear.\n", ignore);
      } else if (living(player)) {
         tell_room(room, env_string+" has some bits of shimmering stardust "
                         " fall off "+player->query_possessive()+
                         " face, sparkle for an instant and disappear.\n", ignore);
      } else {
         tell_room(room, env_string+" has some shimmering stardust "
                         "fall off it, sparkle for an instant and disappear.\n", ignore);
      }
      if (living(room))
        ignore += ({ room });
      env_string = env_string + " in " + room->the_short();
      if (!environment(room))
      room = environment(room);
} /* create_shimmer() */

string extra_look() {
  return capitalize(previous_object()->query_pronoun()+
         " shimmers and sparkles beautifully.\n");
} /* extra_look() */

/** @ignore yes */
string query_classification() { return "object.stardust"; }

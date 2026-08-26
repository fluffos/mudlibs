/**
 * Effect to hold you in thrall while death is delivering his
 * speech.
 * This effect has the classification "mudlib.death.message".
 * This effect has a shadow associated with it.
 * Shiannar, 02/10/01.
 */

#include "path.h"
#include <effect.h>

void setup_death_shadow(object);

/** @ignore yes */
string query_classification() { return "mudlib.death.message"; }

/** @ignore yes */
string query_shadow_ob() { return SHADOWS "death_message"; }

/** @ignore yes */
void beginning(object player, object death) {
  if(!death) {  //What the?
    player->release_from_death_effect();
    return;
  }
  tell_object(player, death->short()+"'s steely gaze catches your eyes, "
      "and holds you in thrall.\n");
  call_out((:setup_death_shadow:), 0, player);
} /* beginning() */

/** @ignore yes */
void end(object player, object death) {
  player->remove_property("death_rolling");
  if(!death) {
    return;
  }
  tell_object(player, death->short()+"'s eyes lose their lustre, "
      "and you find yourself free to move once more.\n");
} /* end() */

/** @ignore yes */
void restart(object player, object death) {
  if(!death) {
    return;
  }
  call_out((:setup_death_shadow:), 0, player);
  tell_object(player, death->short()+" glares sharply at you, "
      "ensuring your attention.\n");
} /* restart() */

/**
 * Ensures that player input is caught by the shadow.
 */
void setup_death_shadow(object player) {
  player->setup_death_shadow();
} /* setup_death_shadow() */
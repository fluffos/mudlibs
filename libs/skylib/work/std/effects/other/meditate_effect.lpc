/**
 * This is the effect skelton docs.  This effect
 * has a classification of "body.meditation".
 * <p>
 * There is only one argument, this is how long to meditate 
 * for.
 * <p>
 * This effect has a shadow associated with it.
 * @classification body.meditation
 * @see help::effects
 */

#include <effect.h>
#include "path.h"

/** @ignore yes */
void beginning(object player, mixed args, int id) {    
    tell_object(player, "You start to meditate, and enter a deep trance.\n");
    player->submit_ee("meditate", ({ 15, 30 }), EE_CONTINUOUS);
    player->add_extra_look(this_object());    
} /* beginning() */

/** @ignore yes */
void merge_effect(object player, mixed args, int id) {
    tell_object(player, "You are already meditating.\n");
} /* merge_effect() */

/** @ignore yes */
void restart(object player, mixed args, int id) {
    player->add_extra_look(this_object());
} /* restart() */

/** @ignore yes */
void end(object player, mixed args, int id) {
    tell_object(player, "You come out of the trance feeling a lot "
        "healthier, although extremely weak.\n");
    player->set_gp(0);
    player->set_sp(0);
    player->set_hp(player->query_max_hp());   
    player->remove_extra_look(this_object());
} /* end() */

/** @ignore yes */
string query_classification() { 
    return "body.meditation";
} /* query_classification() */

/** @ignore yes */
string query_shadow_ob() {
    return SHADOWS + "meditate_shadow";
} /* query_shadow_ob() */

/** @ignore yes */
string extra_look(object who) {
    return capitalize(who->query_pronoun()) + " is in a deep trance.\n";    
} /* extra_look() */

/** @ignore yes */
void meditate(object player, mixed args, int id) {
    tell_object(player, "Ommmmm....\n");

    args -= (2 + random(8));
    
    if (args <= 0) {
        player->submit_ee(0, 0, EE_REMOVE);
        return;
    }    
    
    player->set_arg_of(player->sid_to_enum(id), args);    
} /* meditate() */

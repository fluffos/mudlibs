
#define CLASSIFICATION "covert.lpick"
#define LOCKPICKING    "covert.lockpick.doors"

#include <effect.h>
#include <tasks.h>
#include <thief.h>
#include "path.h"

class lockpick_data {
    object door;
    object pick;
    int diff;
    int delay;
    int stage;
}

/** @ignore yes */
string query_classification() { return CLASSIFICATION; }

/** @ignore yes */
string query_shadow_ob() { return SHADOWS+"lockpicking"; }

int do_checks( object player, class lockpick_data data ) {
    if( !objectp(data->door) ) {
        tell_object( player, "Where did the door go?\n");
        tell_room( player, player->the_short()+" suddenly $V$0=looks,look$V$ "
            "confused.\n", player );
        player->submit_ee( 0, 0, EE_REMOVE );
        return 0;
    }

    if( !data->pick || !data->pick->query_wielded() ||
        data->pick->query_wielded() != player ) {
        tell_object( player, "What happened to your lockpick?\n");
        tell_room( player, player->the_short()+" looks at "+
            player->HIS+" hands with a stunned expression and stops picking "
            "the lock on "+data->door->the_short()+".\n", player );
        data->door->remove_property("lockpicked");
        player->submit_ee( 0, 0, EE_REMOVE );
        return 0;
    }

    if( player->query_fighting() ) {
        player->interrupt_lockpicking();
        return 0;
    }

    return 1;

} /* do_checks() */

/** @ignore yes */
void do_fiddle( object player, class lockpick_data data, int id ) {
    if( do_checks( player, data ) ) {
        class task_class_result result;

        switch( data->stage++ ) {
          case 0:
            // A certain fail anyway.
            if( data->diff > player->query_skill_bonus(LOCKPICKING) ) {
                tell_object( player, "Stupefied by the complexity of the "
                    "device and secure in the knowledge that your hands and "
                    "tools are nowhere near sensitive enough, you give up "
                    "even before attempting to pick the lock on "+
                    data->door->the_short()+".\n");
                tell_room( ENV(player), player->the_short()+" looks "
                    "stupefied as "+player->HE+" stops scrutinizing the lock "
                    "on "+data->door->the_short()+".\n", player );
                data->door->remove_property("lockpicked");
                player->submit_ee( 0, 0, EE_REMOVE );
                return;
            }
            event( ENV(player), "lockpick", player, data->door, 0, 0 );
            tell_object( player, "You insert "+data->pick->the_short()+" into "
                "the lock on "+data->door->the_short()+".\n");
            tell_room( ENV(player), player->the_short()+" inserts "+
                data->pick->poss_short()+" into the lock on "+
                data->door->the_short()+".\n", player );
            player->set_arg_of( player->sid_to_enum(id), data );
            player->submit_ee("do_fiddle", data->delay, EE_ONCE );
            return;
          case 1:
            tell_object( player, "You start to sweat as you continue to work on "
                "the lock on "+data->door->the_short()+".\n");
            tell_room( ENV(player), player->the_short()+ " starts to sweat as "+
                player->HE+" works on the lock on "+data->door->the_short()+".\n",
                player );
            player->set_arg_of( player->sid_to_enum(id), data );
            player->submit_ee("do_fiddle", data->delay, EE_ONCE );
            return;
          default:
            result = new( class task_class_result );
            result = TASKER->perform_task( player, LOCKPICKING,
                                           data->diff, TM_COMMAND, 1 );
            switch( result->result ) {
              case AWARD:
                tell_object( player, "%^YELLOW%^You "+({
                    "realize that the internals of the lock on "+
                    data->door->the_short()+" start to make more sense to "
                    "you.",
                    "feel more confident in your ability as you move "+
                    data->pick->poss_short()+" in the lock on "+
                    data->door->the_short()+".",
                    "become more skilled in manipulating the mechanism of "
                    "the lock on "+data->door->the_short()+"."})[random(3)]+
                    "%^RESET%^\n");
              case SUCCEED:
                XP_H->handle_xp( player, LPICK_COST, 1 );

                if( data->door->query_locked() ){
                    data->door->pick_unlock();
                    tell_object( player, "You jiggle "+
                        data->pick->the_short()+" and the lock on "+
                        data->door->the_short()+" pops open with a "
                        "satisfying click, after which you pull "+
                        data->pick->the_short()+" out of the lock.\n");
                } else {
                    data->door->pick_lock();
                    tell_object( player, "You jiggle "+
                        data->pick->the_short()+" and the lock on "+
                        data->door->the_short()+" pops shut with a "
                        "satisfying click, after which you pull "+
                        data->pick->the_short()+" out of the lock.\n");
                }

                tell_room( ENV(player), player->the_short()+" jiggles "+
                    data->pick->the_short()+" in the lock on "+
                    data->door->the_short()+" and makes it produce a small "
                    "click, after which "+player->HE+" pulls "+
                    data->pick->the_short()+" out of the lock.\n", player );

                result->degree = ( 100 - result->degree ) / 10;
                result->degree += data->diff / 50;
                data->pick->do_damage("blunt", result->degree );

                event( ENV(player), "lockpick", player, data->door, 1, 1 );

              break;
              default:
                XP_H->handle_xp( player, LPICK_COST, 0 );

                tell_object( player, "You frantically jiggle "+
                    data->pick->the_short()+" in the lock on "+
                    data->door->the_short()+", but pull it out after "
                    "realizing you are not making any progress.\n");

                tell_room( ENV(player), player->the_short()+" frantically "
                    "jiggles "+data->pick->the_short()+" in the lock on "+
                    data->door->the_short()+", but pulls it out after a "
                    "while with a disappointed expression.\n", player );

                // result->degree is negative here.
                result->degree = -result->degree / 5 + data->diff / 10;
                data->pick->do_damage("blunt", result->degree );

                event( ENV(player), "lockpick", player, data->door, 1, 0 );
            }
            data->door->remove_property("lockpicked");
            player->submit_ee( 0, 0, EE_REMOVE );
        }
    }

} /* do_fiddle() */

/** @ignore yes */
class lockpick_data beginning( object player, mixed arg, int id ) {
    class lockpick_data data;

    data = new( class lockpick_data, door  : arg[0],
                                     pick  : arg[1],
                                     diff  : arg[2],
                                     delay : arg[3],
                                     stage : 0 );

    player->add_extra_look( file_name(TO) );
    player->submit_ee("do_fiddle", data->delay, EE_ONCE );

    return data;

} /* beginning() */

/** @ignore yes */
void restart( object player, class lockpick_data data, int id ) {
    player->submit_ee( 0, 0, EE_REMOVE );
} /* beginning() */

/** @ignore yes */
void merge_effect( object player, mixed new_arg, mixed arg, int id ) {
    error("merge_effect() called!\n");
} /* beginning() */

/** @ignore yes */
void end( object player, class lockpick_data data, int id ) {
    player->remove_extra_look( file_name(TO) );
} /* beginning() */

/** @ignore yes */
string extra_look( object player ) {
    int *enums;
    class lockpick_data data;

    if( sizeof( enums = player->effects_matching( CLASSIFICATION ) ) &&
        classp( data = player->arg_of( enums[ 0 ] ) ) )
        return CAP( player->HE )+" is busy "+( data->stage ? "picking" :
               "peering at")+" the lock on "+data->door->the_short()+".\n";

    return "";

} /* extra_look() */

/* use <thing> to cast <ritual> [on <target>] -*- LPC -*-
 * coded by Olorin
 */

#include <tasks.h>
#include <rituals.h>
#include <move_failures.h>
#include "path.h"

#define SKILL "faith.items.scroll"
#define DROPOFF 40
#define RITUAL_NAME arg()[ 0 ]
#define RITUAL      arg()[ 1 ]
#define BONUS_STORED arg()[ 2 ]
#define COST ( RITUAL->query_point_cost() / 2 )

#define CONSUME_CHANCE 50

inherit "/std/effect_shadow";

int disabled = 0;

int do_use( object *, string, string, mixed *, string );

void init() {
    int directed;

    directed = RITUAL->query_directed();
    if ( directed & NOTARGET )
        this_player()->add_command( "use", player,
          "<direct:object:me-here> to cast "+
          RITUAL_NAME );
    if ( directed & NONLIVING )
        this_player()->add_command( "use", player,
          "<direct:object:me-here> to cast "+
          RITUAL_NAME +" [on|at] <indirect:object>");
    else if ( directed & LIVING || directed & SELF)
        /* only needs special treatment
         * if not also non-living
         */
        this_player()->add_command( "use", player,
          "<direct:object:me-here> to cast "+
          RITUAL_NAME +" [on|at] <indirect:living>");
    player->init();
} /* init() */

string query_ritual_name() {
    return RITUAL_NAME;
} /* query_ritual_name() */

string query_ritual_object() {
    return RITUAL;
} /* query_ritual_object() */

int query_imbued() {
    return 1;
} /* query_imbued() */

mixed query_arg() {
    return arg();
} /* query_arg() */

mixed query_player() {
    return player;
} /* query_player() */

int do_use( object *targets, string dir_match,
  string indir_match, mixed *args, string pattern ) {
    object caster;
    string bit;
    int diff, explode;

    foreach(bit in explode( RITUAL_NAME, " ")) {
        if(member_array(bit, explode(pattern, " ")) == -1) {
            return 0;
        }
    }

    if ( disabled )
        return 0;
    /*   if ( creatorp(this_player()) )
          tell_object( this_player(),
                      sprintf( "$I$2=do_use called:\nindir=%O\n"
                              "dir_match=%O\nindir_match=%O\nargs=%O\n"
                              "pattern=%O$I$0=\n",
                              targets, dir_match,
                              indir_match, args, pattern ) );
     */
    caster = this_player();
    if ( !(targets = RITUAL->check_target( caster, targets ) ) ) {
        this_player()->add_failed_mess( player, "", ({ }) );
        return 0;
    }
    if ( (int)caster->query_specific_gp( "faith" ) < COST ) {
        this_player()->add_failed_mess( player, "You do not have enough guild "
          "points to use $D to cast " + RITUAL_NAME
          +"; it will cost you "+ COST
          +".\n", ({ }) );
        return 0;
    }

    // there's a chance the item will be destroyed in the casting.
    // the chance is dependant on the difference between the power of the
    // ritual and the value of the item.
    diff = player->query_value() -
      (RITUAL->query_power_level() * RITUAL->query_power_level());

    // This gives us a non-linear (x2?) relationship.
    if(diff < 1 || random(random(diff)) < CONSUME_CHANCE) {
      explode = 1;
    } else {
      explode = 0;
    }

    switch ( (int)TASKER->perform_task(caster, SKILL,
                                       RITUAL->query_power_level(),
                                       TM_RITUAL) ) {
    case AWARD :
      if(!explode)
        tell_object( caster,
              ({ "%^YELLOW%^You manage to grasp one of the principles "
                "behind using religious items more firmly.%^RESET%^\n",
                "%^YELLOW%^You feel better at using religious "
                "items.%^RESET%^\n",
                "%^YELLOW%^You seem to be a step closer to mastering the "
                "use of religious items.%^RESET%^\n" })[ random( 3 ) ]
                     );
      else // take it away again since it exploded.
        caster->add_skill_level(SKILL, -1);

    case SUCCEED :
      if(explode) {
        tell_object(caster, "Trying to cast " + RITUAL_NAME + " consumes " +
                    player->the_short()+ " and it crumbles to dust.\n");

        this_player()->add_succeeded( targets );
        this_player()->add_succeeded_mess( player, "", ({ }) );
        if(player->move("/room/rubbish") != MOVE_OK) {
          log_file("IMBUES", "%s had to dest %s, move returned: %d\n",
                   ctime(time()), file_name(player), player->move("/room/rubbish"));
          player->dest_me();
        }
        return 1;
      }

      if (RITUAL->item_spell( caster, targets, "", BONUS_STORED ) ) {
        caster->adjust_gp( - COST );
        tell_object( caster, "You use "+ (string)player->the_short()
                     +" to cast "+ RITUAL_NAME +".\n" );
        call_out( "delete_effect", 0, (int)player->sid_to_enum( id ) );
        disabled = 1;
      }
    break;
    default :
      if (!random(2)) {
        tell_object( caster, "You fail to use "+ (string)player->the_short()+
                     " to cast "+ RITUAL_NAME +" and it crumbles to dust.\n" );
        if(player->move("/room/rubbish") != MOVE_OK) {
          log_file("IMBUES", "%s had to dest %s, move returned: %d\n",
                   ctime(time()), file_name(player), player->move("/room/rubbish"));
          player->dest_me();
        }
        return 1;
      } else {
        tell_object( caster, "You fail to use "+ (string)player->the_short()
                     +" to cast "+ RITUAL_NAME +".\n" );
      }
    }
    this_player()->add_succeeded( targets );
    this_player()->add_succeeded_mess( player, "", ({ }) );
    return 1;
} /* do_use */

mixed stats() {
    return ({
      ({ "ritual name", RITUAL_NAME }),
      ({ "ritual object", RITUAL }),
      ({ "stored bonus", BONUS_STORED }),
    }) + player->stats();
} /* stats() */

#include "path.h"
#include <tasks.h>
#include <dirs.h>
#include <player.h>

inherit "/std/effect_shadow";

#define COST   5
#define SKILL  "covert.stealth"
#define HSKILL "covert.hiding.person"
#define PSKILL "general.perception"

int level, out_of_hiding, moving, sneak_removed, dont_unsneak;
string skill, oldskill;

void set_sneak();
void set_hide();

/**
 * This method returns the current sneaking level for the person.
 */
int query_sneak_level() {
    return level;
} /* query_sneak_level() */

/**
 * This method is called when the person starts sneaking.
 */
void start_sneaking(int lev) {
    level = lev;
    dont_unsneak = 1;
    set_hide();
    dont_unsneak = 0;
} /* start_sneaking() */

/**
 * This method makes us stop sneaking.
 */
void stop_sneaking() { remove_this_effect(); }

/** @ignore yes */
varargs void hide_callback( int quiet ) {
    // Don't do anything if we are already out of hiding.
    // - Sandoz.
    if( out_of_hiding )
        return;

    out_of_hiding = 1;

    if( !moving ) {
        if( query_verb() != "sneak" && query_verb() != "hide" ) {
            if( player == PO ) {
                if( !quiet )
                    tell_object( player, "You temporarily stop trying to be "
                        "inconspicuous.\n" );
            } else {
                tell_object( player, "You have been noticed.\n" );
            }
        }

        if( query_verb() == "hide")
            tell_object( player, "Trying to remain hidden you stop sneaking.\n");

        if( !quiet )
            tell_room( ENV(player), "You notice $a_short:"+file_name(player)+
                "$ nearby.\n", player );

        remove_this_effect();

    }

} /* hide_callback() */

/** @ignore yes */
void sneak_callback() {
    if( !dont_unsneak )
        sneak_removed++;
} /* sneak_callback() */

/** @ignore yes */
string calc_skill( object who ) {
    return SKILL+"."+( ENV(who)->query_property("location") || "outside");
} /* calc_skill() */

/** @ignore yes */
void set_sneak() {
    int bonus, mod;

    bonus = ( player->query_skill_bonus( calc_skill(player) ) * level) / 3;
    bonus += (int)ENV(player)->query_property("hide bonus");

    // mod is the %age of light in the room coming from TP.
    mod = ( TP->query_light() * 100) / (ENV(TP)->query_light() + 1 );

    // Divide their current bonus by 1/10th the %age of light in the room coming
    // from the player. (ie. if you're carrying a bright light source you're
    // gonna stand out like a beacon.
    if( mod > 0)
        mod /= 10;

    if( mod > 0 )
        bonus /=  mod;

#ifdef DEBUG
  log_file("SNEAK_LIGHT", "%s: SB %d, My light %d, room %d, mod %d, final %d\n",
           player->query_name(),
           ((player->query_skill_bonus(calc_skill(player)) * level) / 3) +
           (int)ENV(player)->query_property("hide bonus"),
           TP->query_light(),
           ENV(TP)->query_light(), mod,
           bonus);
#endif

    player->add_hide_invis("sneaking", 0, bonus, ({ TO, "sneak_callback"}) );

} /* set_sneak() */

/** @ignore yes */
void set_hide() {
    int bonus, mod;

    bonus = (player->query_skill_bonus(HSKILL) * level) / 3;
    bonus += (int)ENV(player)->query_property("hide bonus");
    /* check light on the player, apply modifier if we have a beacon */
    if( ( mod = ( 100 * TP->query_light() ) / ( ENV(TP)->query_my_light() + 1 ) ) ) {
        bonus -= mod;
        if( bonus < 20 )
            bonus = 20;
    }

    player->add_hide_invis("hiding", 0, bonus, ({ TO, "hide_callback"}) );

} /* set_hide() */

/**
 * @ignore yes
 * This method is used to charge people for sneaking.
 * the out_of_hiding and moving variables are needed coz exit_command
 * a. gets called a lot even when not moving
 * b. automatically takes you out of hiding even though you haven't been
 *    spotted in this case.
 */
varargs int exit_command( string word, mixed verb, object thing ) {
    int retval;

    if( !player )
        player = TP;

    set_sneak();

    moving = 1;
    retval = player->exit_command( word, verb, thing );
    moving = 0;

    if( retval ) {
        // Reduce their gps.
        if( !TASKER->point_tasker( player, "covert", COST * level ) ) {
            tell_object( player, "You can't concentrate sufficiently to sneak "
                                 "anymore.\n");
            remove_this_effect();
            return 1;
        } else if( sneak_removed ) {
            remove_this_effect();
            return 1;
        }
        if( LENGTHEN[ word ] )
            word = LENGTHEN[ word ];
        tell_object( player, "You sneak "+word+".\n");
        player->adjust_time_left( -( ROUND_TIME * level) / 2 );
        out_of_hiding = 0;
    }

    dont_unsneak = 1;
    player->remove_hide_invis("sneaking");
    dont_unsneak = 0;

    if( !out_of_hiding )
        set_hide();

    return retval;

} /* exit_command() */

/**
 * This method is called by "/global/player/events"->event_enter() to perform
 * a taskmaster test for the sneaker.
 * @param who the person sneaking
 */
void sneak_task( object who ) {
    mapping hide_invis;
    int perception;

    hide_invis = player->query_hide_invis();

    if( hide_invis["sneaking"] ) {
        // get their perception
        perception = who->query_skill_bonus(PSKILL);

        // multiply this by the level of sneak they're at.
        // At high sneak their perception is multiplied by 1,
        // at low it's multiplied by 3 etc.
        perception *= ( 4 - query_sneak_level() );
        switch( who->check_dark( (int)ENV(who)->query_light() ) ) {
          case -2:
          case 2:
            perception /= 4;
          break;
          case -1:
          case 1:
            perception /= 2;
          break;
          default:
        }

        if( TASKER->perform_task( player, calc_skill(player), perception,
            TM_CONTINUOUS ) == AWARD )
            tell_object( player, "%^YELLOW%^You "+({
                "understand", "comprehend", "realise", "appreciate"})
                [ random( 4 ) ]+" the methods of sneaking "+
                ( ENV(player)->query_property("location") || "outside")+
                " more fully.%^RESET%^\n");
    }
} /* sneak_task() */

/**
 * This method is called by "/global/player/events"->event_enter() to perform
 * a perception taskmaster test for the person entering.
 * @param who the person whose perception to test
 */
void perception_task(object who) {
    mapping hide_invis;
    int difficulty;

    if( player->query_visible(who) )
        return;

    hide_invis = player->query_hide_invis();

    if( !hide_invis || !hide_invis["hiding"] || sizeof( hide_invis["hiding"] ) < 2 )
        return;

    difficulty = hide_invis["hiding"][1];

    if( difficulty ) {
        switch( who->check_dark( (int)ENV(who)->query_light() ) ) {
          case -2:
          case 2:
            difficulty *= 4;
          break;
          case -1:
          case 1:
            difficulty *= 2;
          break;
          default:
      }
      if( TASKER->perform_task( who, PSKILL, difficulty, TM_FREE ) == AWARD )
          tell_object( who, "%^YELLOW%^You feel very alert.%^RESET%^\n");
    }

} /* perception_task() */

/**
 * @ignore yes
 * This method makes us stop sneaking when being attacked.
 */
int attack_by( object ob ) {
    call_out( "stop_sneaking", 1 );
    return player->attack_by(ob);
} /* attack_by */

/**
 * @ignore yes
 * This method makes us stop sneaking when attacking someone.
 */
int attack_ob( object ob ) {
    call_out( "stop_sneaking", 1 );
    return player->attack_ob(ob);
} /* attack_ob() */

/**
 * This is the kirikaeshi command.  Thank you, Kendo. :)
 * Initiates combat and makes a number of quick attacks on the target.
 * @author Sandoz, 2002.
 * @changed Rewrote completely for the new combat system.
 * - Sandoz, June 2003.
 */

#define __ATTACK_DATA_CLASS__
#include <combat.h>
#include <player.h>
#include <tasks.h>
#include <weapon.h>

#define GP_COST     50
#define LEARN_LEVEL 50
#define MAX_HITS    5
#define OFF_SKILL   "fighting.combat.special.tactics"
#define WEP_SKILL   "fighting.combat.special.weapon"
#define DEF_SKILL   "general.perception"

inherit COMMAND_BASE;

private void execute_attack( object off, object def, object wep,
                             string *names, mixed data, string *areas );

/**
 * This method returns whether or not the specified player
 * can learn this command.
 * @param ob the player to test
 * @return 1 if they can learn it, 0 if not
 */
int query_learnable_by( object ob ) {
    return ob->query_skill(OFF_SKILL) >= LEARN_LEVEL &&
           ob->query_skill(WEP_SKILL) >= LEARN_LEVEL;
} /* query_learnable_by() */

/** @ignore yes */
int cmd( object *targets, object *weapons ) {
    string *names, *areas;
    object target, weapon;
    int mod, i, off, def;
    mapping map;
    mixed data;
    mapping hiding;
    
    if( TP->query_fighting() ) {
        add_failed_mess("You cannot use a kirikaeshi attack while already "
            "in combat with someone.\n");
        return 0;
    }

    if( sizeof( targets ) > 1 ) {
        add_failed_mess("You can only make a kirikaeshi attack on one "
            "target at a time.\n");
        return 0;
    }

    targets = HEALTH_H->do_attack_checks( targets, 0 );

    if( !targets )
        return 0;

    if( !sizeof(targets) )
        return 1;

    target = targets[ 0 ];

    if( mapp( map = target->query_attackable_areas() ) ) {
        areas = ({ });
        if( !undefinedp( map["head"] ) )
            areas += ({"head"});
        if( !undefinedp( map["neck"] ) )
            areas += ({"neck"});
    }

    if( !sizeof(areas) ) {
        add_failed_mess("Oh dear, $I seems to have no head or neck to "
            "pummel at.  Puzzling, no?\n");
        return 0;
    }

    if( sizeof( weapons ) > 1 ) {
        add_failed_mess("You can only use one weapon for the kirikaeshi "
            "attack.\n");
        return 0;
    }

    if( !sizeof(weapons) ) {
        add_failed_mess("You need a weapon for the kirikaeshi "
            "attack.\n");
        return 0;
    }

    weapon = weapons[ 0 ];

    if( !weapon->query_weapon() || weapon->query_no_limbs() != 2 ) {
        add_failed_mess("You need a two-handed weapon to use the kirikaeshi "
            "attack.\n");
        return 0;
    }

    i = sizeof( names = weapon->query_attack_names() );
    data = weapon->query_attack_data();

    // Weed out unappropriate attacks.
    while( i-- ) {
        int j = i * W_ARRAY_SIZE;

        switch( data[j+W_SKILL] ) {
          case "sharp" :
          case "blunt" :
          continue;
          default:
            names = delete( names, i, 1 );
            data = delete( data, j, W_ARRAY_SIZE );
        }
    }

    if( !sizeof(names) ) {
        add_failed_mess("$I doesn't appear to be a suitable weapon to "
            "execute a kirikaeshi attack with, because it is not meant "
            "for swinging motions.\n");
        return 0;
    }

    if( target->is_fighting(TP) ) {
        add_failed_mess("$I appears to be fighting you already.\n", targets );
        return 0;
    }

    if( ENV(TP)->query_transport() ) {
        add_failed_mess("You cannot execute a kirikaeshi attack while you "
            "are mounted.\n");
        return 0;
    }

    if( ENV(target)->query_transport() ) {
        add_failed_mess("You cannot execute a kirikaeshi attack on mounted "
            "opponents.\n");
        return 0;
    }

    if( weapon->query_wielded() != TP ) {
        add_failed_mess("You are not holding $I.\n", weapons );
        return 0;
    }

    if( !TASKER->point_tasker( TP, "fighting", GP_COST ) ) {
        add_failed_mess("You do not have enough energy to execute a "
            "kirikaeshi attack on $I.\n", targets );
        return 0;
    }

    hiding = (mapping)TP->query_hide_invis();

    if( hiding["hiding"] ) {
        TP->remove_hide_invis("hiding");
    }

    // Start out with a 25% bonus.
    mod = 25;

    // Impose a lower limit to it, just in case.
    if( ( i = weapon->query_weight() ) < 10 )
        i = 10;

    // Increase the modifier by a weighted average of our
    // special.weapon skill and the weight of the weapon used.
    mod += TP->query_skill_bonus(WEP_SKILL) / i;

    off = TP->query_skill_bonus(OFF_SKILL);
    def = target->query_skill_bonus(DEF_SKILL);

    event( TP, "inform", sprintf("kirikaeshi: tactics %i vs perception %i, "
        "modifier: %i", off, def, mod ), "debug");

    mod = TASKER->compare_skills( TP, OFF_SKILL, target, DEF_SKILL,
                                  mod, TM_COMMAND, TM_FREE );

    switch( mod ) {
      case OFFAWARD :
        tell_object( TP, "%^YELLOW%^"+({
            "You feel more skilled at making surprise attacks",
            "You discover a new aspect of tactical fighting",
            "You realize something new about surprise attacks"})
            [ random( 3 ) ]+" as you execute the kirikaeshi attack on "+
            target->the_short()+"%^RESET%^\n" );
      case OFFWIN :
        XP_H->handle_xp( TP, GP_COST, 1 );
        call_out( (: execute_attack :), 0, TP, target, weapon,
            names, data, areas );
      break;
      case DEFAWARD :
        tell_object( def, "%^YELLOW%^You feel more perceptive as you "+
            choice( ({"foil ", "thwart "}) )+TP->poss_short()+" attempt "
            "to launch at you with "+weapon->poss_short()+".\n%^RESET%^");
      case DEFWIN :
        XP_H->handle_xp( TP, GP_COST, 0 );

        // Let's attack normally if we are good enough.
        // Otherwise let the target attack us instead.
        if( random(off) > def / 3 ) {
            tell_object( TP, "You attempt to launch at "+
                target->the_short()+" with "+weapon->poss_short()+", but "+
                target->HE+" turns to face you just in time, although you "
                "keep going, albeit with less vigour.\n");
            tell_object( target, TP->one_short()+" attempts to launch at you "
                "with "+weapon->poss_short()+", but you turn to face "+
                TP->HIM+" just in time, thwarting "+TP->HIS+" enthusiasm.\n");
            tell_room( ENV(TP), TP->one_short()+" attempts to launch at "+
                target->one_short()+" with "+weapon->poss_short()+", but "+
                target->HE+" turns to face "+TP->HIM+" just in time, "
                "thwarting "+TP->HIS+" enthusiasm.\n", ({ TP, target }) );
            TP->attack_ob(target);
        } else {
            tell_object( TP, "You attempt to launch at "+
                target->the_short()+" with "+weapon->poss_short()+", but "+
                target->HE+" turns to face you just in time and you lose your "
                "concentration.\n");
            tell_object( target, TP->one_short()+" attempts to launch at you "
                "with "+weapon->poss_short()+", but you turn to face "+
                TP->HIM+" just in time, foiling "+TP->HIS+" plans.\n");
            tell_room( ENV(TP), TP->one_short()+" attempts to launch at "+
                target->one_short()+" with "+weapon->poss_short()+", but "+
                target->HE+" turns to face "+TP->HIM+" just in time, "
                "foiling "+TP->HIS+" plans.\n", ({ TP, target }) );
            TP->adjust_time_left( -ROUND_TIME );
            target->attack_ob(TP);
        }
    }

    return 1;

} /* cmd() */

/** @ignore yes */
private void finish_attack( object off, object def ) {
    off->attack_ob(def);
    tell_object( off, "You run out of breath and proceed to attack "+
        def->the_short()+" normally.\n");
    tell_room( ENV(off), off->the_short()+" seems to have run "
        "out of breath and proceeds to attack "+
        def->the_short()+" normally.\n", off );
} /* finish_attack() */

/** @ignore yes */
private void execute_attack( object off, object def, object wep,
                             string *names, mixed data, string *areas ) {
    int i, j, dif, weight, perc, bon;

    if( !wep ) {
        tell_object( off, "Bereft of all hope, you abort your attack when "
            "you realize you are not in possession of the weapon anymore.\n");
        return 0;
    }

    if( wep->query_wielded() != off ) {
        tell_object( off, "Bereft of all hope, you abort your attack when "
            "you realize you are not holding "+wep->the_short()+" anymore.\n");
        return 0;
    }

    if( wep->query_no_limbs() != 2 ) {
        tell_object( off, "Bereft of all hope, you abort your attack when "
            "you realize "+wep->the_short()+" is not a two-handed weapon.\n");
        return 0;
    }

    if( ENV(off) != ENV(def) ) {
        tell_object( off, "Bereft of all hope, you abort your attack when "
            "you realize "+def->the_short()+" is not here anymore.\n");
        return 0;
    }

    tell_object( off, "You raise "+wep->poss_short()+" high above your "
        "head and launch at "+def->the_short()+" with a terrible cry, "
        "starting to hew at alternate sides of "+def->HIS+" "+
        query_multiple_short(areas)+".\n");
    tell_object( def, off->one_short()+" suddenly raises "+off->HIS+" "+
        wep->short()+" high above "+off->HIS+" head and launches at you "
        "with a terrible cry, starting to hew at alternate sides of your "+
        query_multiple_short(areas)+".\n");
    tell_room( ENV(off), off->one_short()+" suddenly raises "+off->HIS+" "+
        wep->short()+" high above "+off->HIS+" head and launches at "+
        def->one_short()+" with a terrible cry, starting to hew at "
        "alternate sides of "+def->HIS+" "+query_multiple_short(areas)+".\n",
        ({ off, def }) );

    // Impose a lower limit on the weight again.
    if( ( weight = wep->query_weight() ) < 10 )
        weight = 10;

    weight = 25 + ( 4 * weight ) / ( off->query_str() / 2 );

    perc = 50;
    perc += COMBAT_H->calc_attack_percentage( off, ({ wep }), ({ }) );

    // Start with a random attack to a random area, then alternate.
    j = random( sizeof(names) );

    bon = off->query_skill_bonus(WEP_SKILL);

    event( off, "inform", sprintf("Kirikaeshi base difficulty: %i, attack "
        "percentage: %i, sp.we: %i", weight, perc, bon ), "debug");

    for( i = 0; i < MAX_HITS; i++ ) {
        int a_dif, damage, k, a_bonus;
        class attack_data att;

        if( j == sizeof(names) )
            j = 0;

        damage = wep->calc_attack( j, perc );

        a_dif = damage / 5;

        k = j * W_ARRAY_SIZE;

        if( data[ k + W_CHANCE ] < 100 )
            a_dif += a_dif * ( 100 - data[ k + W_CHANCE ] ) / 100;

        a_dif += weight;

        dif += a_dif;

        a_bonus = to_int( bon / 50.0 + ( bon / 30.0 * ( MAX_HITS - 1 - i ) ) );

        event( off, "inform", sprintf("Attack no. %i - weapon damage: %i, att "
            "diff: %i, total diff: %i, att bonus: %i", i + 1, damage, a_dif,
            dif, a_bonus ), "debug");

        switch( TASKER->perform_task( off, WEP_SKILL, dif, TM_CONTINUOUS ) ) {
          case AWARD:
            tell_object( off, "%^YELLOW%^"+({
                "You feel more confident in handling "+wep->the_short()+".",
                "You realize you are more capable of quick movements with "+
                wep->the_short()+" than before."})[random(2)]+"%^RESET%^\n");
          case SUCCEED:
            att = new( class attack_data );
            att->attacker = off;
            att->target = def;
            att->weapon = wep;
            att->damage = damage;
            att->skill  = data[ k + W_SKILL ];
            att->type = data[ k + W_TYPE ];
            att->name = names[j++];
            att->focus = choice(areas);
            att->final_damage = damage;
            att->attack_bonus = a_bonus;
            att->unprotectable = 1;

            COMBAT_H->attack_round( off, !i, att );

            // We have ran out of time.
            if( !COMBAT_H->check_time_left( off, 1 ) ) {
                event( off, "inform", "We have ran out of time!", "debug");
                return finish_attack( off, def );
            }
          break;
          default :
            return finish_attack( off, def );
        }
    }

    return finish_attack( off, def );

} /* execute_attack() */

/** @ignore yes */
mixed query_patterns() {
    return ({
        "<indirect:living:here'target'> [with] <indirect:object:me'weapon'>",
        (: cmd( $1[0], $1[1] ) :),
        "<indirect:living:here'target'>",
        (: cmd( $1, TP->query_weapons() ) :),
    });
} /* query_patterns() */

/**
 * This file contains all the methods and fun things to handle combat
 * from the living object side of things.
 * @author Pinkfish
 * @changed Added the combat code with some tweaks - Sandoz, May 2003.
 */

#define __SPECIAL_ATTACK_DATA__
#define __ATTACK_DATA_CLASS__
#include <combat.h>
#include <player.h>
#include <tasks.h>

/** This defines after how long we will give up hunting someone. */
#define HUNTING_TIME 1200

/** @ignore yes */
#define AREAS        ({"feet", "legs", "abdomen", "chest", "back", \
                       "arms", "hands", "neck", "head"})

/** @ignore yes */
#define ATTITUDES    ({"utterly defensive", "defensive", "neutral", \
                       "offensive", "utterly offensive"})

/** @ignore yes */
#define PERC_SKILL   "general.perception"

#undef DEBUG

inherit "/std/weapon_logic";
inherit "/std/living/corpse";

class combat_tactics {
    int attitude;
    string response;
    string parry;
    int unarmed_parry;
    string focus;
}

class attacker_data {
    object ob;
    string name;
    int time;
}

class combat_data {
    class attacker_data *attackers;
    class attacker_data concentrating;
    object *protectors;
    object *defenders;
    object attacker;
    object target;
    object weapon;
    int special_manoeuvre;
    int in_combat;
    class special_attack_data *sp_queue;
}

private class combat_tactics _combat_tactics;
private nosave class combat_data _combat;

protected void start_combat( object thing );
void stop_all_fight();
private void announce_intent( object thing );

/** @ignore yes */
class combat_data query_combat_data() { return copy( _combat ); }

void create() {
    _combat_tactics = new( class combat_tactics );
    _combat_tactics->attitude = 0;
    _combat_tactics->response = "neutral";
    _combat_tactics->parry = "both";

    _combat = new( class combat_data );
    _combat->attackers = ({ });
    _combat->protectors = ({ });
    _combat->defenders = ({ });

    ::create();

} /* create() */

/**
 * This method returns whether or not we are in combat.
 * This is only to be used internally by the combat engine.
 * @return 1 if we are in combat, 0 if not
 */
int query_in_combat() { return _combat->in_combat; }

/**
 * This method returns the array of creatures we are fighting.
 * It lists all those who are not currently in the room with us as well.
 * @return the attacker list
 * @see query_concentrating()
 * @see query_fighting()
 */
object *query_attacker_list() {
    object ob, *ret;
    string str;
    int i;

    ret = ({ });
    i = sizeof( _combat->attackers );

    while( i-- ) {
        // No object.
        if( !ob = _combat->attackers[i]->ob ) {
            // We are dealing with a player.
            // This is needed so that players would still be
            // on the attacker list after su'ing.
            if( stringp( str = _combat->attackers[i]->name ) ) {
                if( ( ob = _combat->attackers[i]->ob = find_player( str ) ) &&
                    ob->query_property("dead") ) {
                    _combat->attackers = delete( _combat->attackers, i, 1 );
                    if( _combat->concentrating &&
                        _combat->concentrating->name == str )
                        _combat->concentrating = 0;
                    continue;
                }
            } else {
                _combat->attackers = delete( _combat->attackers, i, 1 );
                continue;
            }
        } else if( ob->query_property("dead") ) {
            if( _combat->concentrating &&
                _combat->concentrating->ob == ob )
                _combat->concentrating = 0;
            _combat->attackers = delete( _combat->attackers, i, 1 );
            continue;
        }

        // We have a valid attacker.
        if( ob )
            ret += ({ ob });
    }

    return ret;

} /* query_attacker_list() */

/**
 * This method determines whether or not the object is fighting another
 * object.
 * @param ob the object being tested
 * @return 1 if it is in combat, 0 if it is not.
 * @see query_attacker_list()
 * @see query_concentrating()
 */
int is_fighting( object ob ) {
    if( !objectp( ob ) )
        return 0;
    return member_array( ob, query_attacker_list() ) != -1;
} /* is_fighting() */

/**
 * This method returns true if the object is fighting
 * someone in the room.
 * @param return 1 if the creature is fighting someone
 * in the room, 0 if not
 * @see query_attacker_list()
 */
int query_fighting() {
    string str;
    object ob;
    int i;

    i = sizeof( _combat->attackers );

    while( i-- ) {
        if( !( ob = _combat->attackers[ i ]->ob ) &&
            stringp( str = _combat->attackers[ i ]->name ) )
            ob = _combat->attackers[ i ]->ob = find_player( str );

        if( ob && ENV(ob) == ENV(TO) )
            return 1;
    }

    return 0;

} /* query_fighting() */

object query_attacker() { return _combat->attacker; }
void set_attacker( object thing ) { _combat->attacker = thing; }

object query_target() { return _combat->target; }
void set_target( object thing ) { _combat->target = thing; }

object query_weapon() { return _combat->weapon; }
void set_weapon( object thing ) { _combat->weapon = thing; }

/** @ignore yes */
int concentrate( object *things ) {
    object thing;

    if( !sizeof( query_attacker_list() ) ) {
        add_failed_mess("You are not fighting anyone at the moment.\n");
        return 0;
    }

    if( !things ) {
        if( !_combat->concentrating || !_combat->concentrating->ob ) {
            add_succeeded_mess( ({"You are not currently concentrating on "
                "any particular opponent.\n", ""}) );
        } else {
            add_succeeded_mess( ({"You are currently concentrating on $I.\n",
                ""}), ({ _combat->concentrating->ob }) );
        }
        return 1;
    }

    if( sizeof(things) > 1 ) {
        add_failed_mess("You can only concentrate on one thing at once.\n");
        return 0;
    }

    thing = things[ 0 ];

    if( thing == TO ) {
        add_failed_mess("You cannot concentrate on yourself.\n");
        return 0;
    }

    if( !is_fighting( thing ) ) {
        add_failed_mess("You can only concentrate on people you are "
            "fighting.\n");
        return 0;
    }

    _combat->concentrating = new( class attacker_data );
    _combat->concentrating->ob = thing;

    if( userp(thing) )
        _combat->concentrating->name = thing->query_name();

    add_succeeded_mess( ({"You are now concentrating on $I.\n", ""}),
        things );
    return 1;

} /* concentrate() */

/**
 * This method returns the creature we are currently concentrating on.
 * @return the creature that is being concentrated on
 * @see query_attacker_list()
 */
object query_concentrating() {
   object ob, *attacking;
   string str;

   if( classp( _combat->concentrating ) ) {
       if( !_combat->concentrating->ob ) {
           _combat->concentrating = 0;
       } else if( _combat->concentrating->ob &&
           _combat->concentrating->ob->query_property("dead") ) {
           _combat->concentrating = 0;
       } else if( stringp( str = _combat->concentrating->name ) ) {
           if( !_combat->concentrating->ob = find_player( str ) ||
               _combat->concentrating->ob->query_property("dead") )
               _combat->concentrating = 0;
        }
   }

   attacking = filter( query_attacker_list(), (: ENV($1) == $2 :), ENV(TO) );

   if( !_combat->concentrating ) {
       if( sizeof( attacking ) != 1 )
           return 0;
       if( objectp( attacking[ 0 ] ) )
           return attacking[ 0 ];
       return 0;
   }

   ob = _combat->concentrating->ob;

   if( ENV(ob) != ENV(TO) && sizeof(attacking) == 1 ) {
       if( userp( ob = _combat->concentrating->ob = attacking[ 0 ] ) )
           _combat->concentrating->name = ob->query_name();
       else
           _combat->concentrating->name = 0;
       tell_object( TO, "You start concentrating on "+ob->the_short()+".\n");
   }

   return ob;

} /* query_concentrating() */

/**
 * This method returns the current tactics set.
 * This method will return a class with four elements in it:
 * <pre>
 * ({
 *    attitude,
 *    response,
 *    parry,
 *    unarmed_parry,
 * })
 * </pre>
 * The first element is an int, signifying the attitude of the player,
 * the secon two are strings, which correspond to the
 * values as set in the tactics player help file.
 * @return the current tactics array set
 * @see query_combat_attitude()
 * @see query_combat_response()
 * @see query_combat_parry()
 * @see query_combat_unarmed_parry()
 * @index tactics
 */
class combat_tactics query_tactics() { return _combat_tactics ; }

/**
 * This returns the current attitude to use in combat.
 * @return the current combat attitude
 * @see query_tactics()
 */
string query_combat_attitude() {
    return ATTITUDES[ _combat_tactics->attitude + 2 ];
} /* query_combat_attitude() */

/**
 * This returns the current attitude to use in combat as a raw int.
 * -2 and -1 for defensive, 0 for neutral and 1 and 2 for offensive attitudes.
 * @return the current combat attitude
 * @see query_tactics()
 */
int query_raw_combat_attitude() { return _combat_tactics->attitude; }

/**
 * This returns the current reponse to use in combat.
 * @return the current combat response
 * @see query_tactics()
 */
string query_combat_response() { return _combat_tactics ->response; }

/**
 * This returns the current parry to use in combat.
 * @return the current combat parry
 * @see query_tactics()
 */
string query_combat_parry() { return _combat_tactics ->parry; }

/**
 * This returns the current unarmed parry to use in combat.
 * @return the current combat unarmed parry
 * @see query_tactics()
 */
int query_unarmed_parry() { return _combat_tactics ->unarmed_parry; }

/**
 * This returns the bodypart we are currently focusing on.
 * @return the bodypart we are currently focusing on
 * @see query_tactics()
 */
string query_combat_focus() { return _combat_tactics->focus; }

/**
 * This sets the current attitude to use in combat.
 * @param attitude the new combat attitude
 * @see query_tactics()
 */
void set_combat_attitude( string attitude ) {
    int i;

    if( ( i = member_array( attitude, ATTITUDES ) ) == -1 )
        error("Trying to set an invalid combat attitude - "+attitude+".\n");

    _combat_tactics->attitude = i - 2;

} /* set_combat_attitude() */

/**
 * This sets the current reponse to use in combat.
 * @param response the new combat response
 * @see query_tactics()
 */
void set_combat_response( string response ) {
    _combat_tactics ->response = response;
} /* set_combat_response() */

/**
 * This sets the current parry to use in combat.
 * @param parry the new combat parry
 * @see query_tactics()
 */
void set_combat_parry( string parry ) {
    _combat_tactics ->parry = parry;
} /* set_combat_parry() */

/**
 * This sets the current unarmed parry to use in combat.
 * @param parry the new unarmed parry flag
 * @see query_tactics()
 */
void set_unarmed_parry( int parry ) {
    _combat_tactics ->unarmed_parry = parry;
} /* set_unarmed_parry() */

/**
 * This sets the bodypart to focus on in combat.
 * @param str the new bodypart to focus on
 * @see query_tactics()
 */
void set_combat_focus( string str ) {
    _combat_tactics->focus = str;
} /* set_combat_focus() */

/** @ignore yes */
varargs int tactics( string what, string words ) {
    if( !words && !what ) {
        tell_object( TO,
            "Your combat options are:\n\n"
            "   Attitude - "+query_combat_attitude()+".\n"
            "   Response - "+query_combat_response()+".\n"
            "   Focus    - "+( query_combat_focus() || "none")+".\n"
            "\nYou will use "+( _combat_tactics->parry == "both" ?
            "both hands" : "your "+_combat_tactics->parry+" hand" )+" to "
            "parry.\n"
            "You will "+( _combat_tactics->unarmed_parry ? "" : "not ")+
            "attempt to parry unarmed.\n");
        return 1;
    }

    if( what && !words )
        error( sprintf("%O called tactics() in %O with invalid args.\n",
            PO, TO ) );

    switch( what ) {
      case "attitude" :
        if( member_array( words, ATTITUDES ) == -1 )
            return notify_fail("Syntax: tactics attitude "+
                "<"+implode( ATTITUDES, "|")+">\n");

        if( query_combat_attitude() != words ) {
            set_combat_attitude( words );
            tell_object( TO, "Your attitude is now "+words+".\n");
            return 1;
        }

        tell_object( TO, "Your attitude is already "+words+".\n");
        return 1;
      case "response" :
        if( member_array( words, ({"dodge", "neutral", "parry"}) ) == -1 )
            return notify_fail("Syntax: tactics response "+
                "<dodge|neutral|parry>\n");

        if( _combat_tactics->response != words ) {
            _combat_tactics->response = words;
            tell_object( TO, "Your response is now "+words+".\n");
            return 1;
        }

        tell_object( TO, "Your response is already "+words+".\n");
        return 1;
      case "parry" :
        if( words == "unarmed" ) {
            _combat_tactics->unarmed_parry = !_combat_tactics->unarmed_parry;

            if( _combat_tactics->unarmed_parry ) {
                tell_object( TO, "You will now attempt to parry unarmed.\n");
                return 1;
            }

            tell_object( TO, "You will not attempt to parry unarmed "
                "anymore.\n");
            return 1;
        }

        if( member_array( words, ({"left", "right", "both"}) ) == -1 )
            return notify_fail(
                "Syntax: tactics parry <left|right|both|unarmed>\n");

        if( _combat_tactics->parry != words ) {
            _combat_tactics->parry = words;
            tell_object( TO, "You will now use "+( words == "both" ?
                "both hands" : "your "+words+" hand")+" to parry.\n");
            return 1;
        }

        tell_object( TO, "You are already using "+( words == "both" ?
            "both hands" : "your "+words+" hand")+" to parry.\n");
        return 1;
      case "focus" :
        if( words == "none") {
            if( !query_combat_focus() )
                return notify_fail("You are already not focusing on any "
                    "particular area when attacking.\n");
            set_combat_focus( 0 );
            tell_object( TO, "You will no longer focus on any particular "
                "area when attacking.\n");
            return 1;
        }

        if( member_array( words, AREAS ) == -1 && words != "none")
            return notify_fail("Sorry, you cannot focus on "+words+".\n");

        if( query_combat_focus() == words )
            return notify_fail("You are already focusing on your opponents' "+
                words+" when attacking.\n");

        set_combat_focus( words );
        tell_object( TO, "You will now focus on your opponents' "+
            words+" when attacking.\n");
        return 1;
    }

    return notify_fail("Something has gone wrong, please file a bug report "
        "describing exactly what you did.\n");

} /* tactics() */

/** @ignore yes */
protected void combat_commands() {
    add_command("concentrate", "", (: concentrate( 0 ) :) );
    add_command("concentrate", "[on] <indirect:living:here'opponent'>",
        (: concentrate($1) :) );

    add_command("tactics", "", (: tactics( 0, 0 ) :) );
    add_command("tactics", "attitude <string'"+implode(ATTITUDES, "|")+"'>",
        (: tactics("attitude", $4[0] ) :) );
    add_command("tactics", "response <string'dodge|neutral|parry'>",
        (: tactics("response", $4[0] ) :) );
    add_command("tactics", "parry <string'left|right|both|unarmed'>",
        (: tactics("parry", $4[0] ) :) );
    add_command("tactics", "focus <string'"+implode(AREAS, "|")+"'>",
        (: tactics("focus", $4[0] ) :) );

} /* combat_commands() */

/**
 * This method returns the current array of protectors on the living
 * object.  This is the people who are protecting us, so if we are hit
 * make them attack the hitter.
 * @return the current protectors array
 * @see add_protector()
 * @see remove_protector()
 */
object *query_protectors() { return _combat->protectors -= ({ 0 }); }

/**
 * This method will add a protector to the current list of protectors
 * for this living object.
 * @param thing the protector to add
 * @see remove_protector()
 * @see query_protectors()
 */
int add_protector( object thing ) {
    if( thing == TO || thing->query_property("dead") )
        return 0;

    if( member_array( thing, _combat->protectors ) == -1 )
        _combat->protectors += ({ thing });

    return 1;

} /* add_protector() */

/**
 * This method will remove a protector from the current list of protectors
 * for this living object.
 * @param thing the protector to remove
 * @see add_protector()
 * @see query_protectors()
 */
int remove_protector( object thing ) {
    if( member_array( thing, _combat->protectors ) == -1 )
        return 0;

    _combat->protectors -= ({ thing });
    return 1;

} /* remove_protector() */

/**
 * This method resets the protector array back to being nothing.
 */
void reset_protectors() { _combat->protectors = ({ }); }

/**
 * This method returns the current array of defenders on the living
 * object.  This is the people who are defending us, so if we are hit
 * make them attack the hitter and parry for us.
 * @return the current defenders array
 * @see add_defender()
 * @see remove_defender()
 */
object *query_defenders() { return _combat->defenders -= ({ 0 }); }

/**
 * This method will add a defender to the current list of defenders
 * for this living object.
 * @param thing the defender to add
 * @see remove_defender()
 * @see query_defenders()
 */
int add_defender( object thing ) {
    if( thing == TO || thing->query_property("dead") )
        return 0;

    if( member_array( thing, _combat->defenders ) == -1 )
        _combat->defenders += ({ thing });

    return 1;

} /* add_defender() */

/**
 * This method will remove a defender from the current list of defenders
 * for this living object.
 * @param thing the defender to remove
 * @see add_defender()
 * @see query_defenders()
 */
int remove_defender( object thing ) {
    if( member_array( thing, _combat->defenders ) == -1 )
        return 0;

    _combat->defenders -= ({ thing });
    return 1;

} /* remove_protector() */

/**
 * This method resets the defenders array back to being nothing.
 */
void reset_defenders() { _combat->defenders = ({ }); }

/**
 * This method will create a corpse for the living object when it
 * eventually dies.  Of old age of course, no one would die of having
 * a sword rammed through them.
 * @return the created corpse object
 */
object make_corpse() {
    object corpse, *armour, *weapons;
    int i;

    corpse = clone_object( CORPSE_OBJ );
    corpse->set_owner( 0, TO );
    corpse->set_ownership( TO->query_name() );

    if( TO->query_property("player") )
        corpse->add_property("player", 1 );

    corpse->set_race_name( TO->query_race() );
    corpse->set_race_ob( TO->query_race_ob() || "/std/races/unknown");

    corpse->set_gender( TO->query_gender() );

    corpse->add_adjective( TO->query_adjectives() );
    corpse->add_adjective( TO->query_name() );
    corpse->add_adjective( TO->query_gender_string() );

    corpse->start_decay();

    armour = TO->query_armours();
    TO->clear_armours();
    weapons = TO->query_weapons();

    INV(TO)->set_tracked_item_status_reason("DIED");
    INV(TO)->move(corpse);

    armour -= ({ 0 });

    for( i = 0; i < sizeof( armour ); i++ ) {
        if( ENV( armour[ i ] ) != corpse ) {
            armour = delete( armour, i, 1 );
            i--;
        }
    }

    corpse->set_armours( armour );
    armour->set_worn_by( corpse );

    weapons -= ({ 0 });

    for( i = 0; i < sizeof( weapons ); i++ ) {
        if( ENV( weapons[ i ] ) != corpse ) {
            weapons = delete( weapons, i, 1 );
            i--;
        }
    }

    corpse->set_holding( weapons );
    weapons->set_holder( corpse );

    return corpse;

} /* make_corpse() */

/**
 * This method deals with any cute messages you want to print when
 * something dies or, cute things you want to do (like not dieng
 * at all).  It handles the alignment shift due to the killing of
 * this npc as well.
 * @param thing the thing which killed us
 * @param death
 * @see make_corpse()
 */
mixed *death_helper( object thing, int death ) {
    int shift, my_level, att_level;
    string *messages;
    object *things, tmp;
    mixed *retval;

    retval = ({ });

    TO->remove_property(PASSED_OUT);
    TO->remove_hide_invis("hiding");

    // Make sure only living things are left in the attacker list or
    // xp will be decreased for kills with e.g. spells, rituals or
    // special weapons.
    things = filter( query_attacker_list(), (: living( $1 ) :) );

    if( environment() ) {
        if( death ) {
            if( !messages = TO->query_property("death messages") ) {
                messages = ({"$K dealt the death blow to $D.\n",
                    "You killed $D.\n", "$D dies.\n"});
            }
        }

        event( ({ environment() }) + deep_inventory( environment() ), "death",
            things, thing, ( thing ? messages[ 0 ] : messages[ 2 ] ),
            messages[ 1 ] );
    }

    if( sizeof( things ) ) {
        // Deal with alignment shifts.
        foreach( tmp in things ) {
#ifdef DEBUG
            int x, y;
            x = tmp->query_al();
#endif

            shift = TO->query_al() ;

            if( !death )
                shift -= shift / 10;

            tmp->adjust_alignment( shift );

#ifdef DEBUG
            y = tmp->query_al();
            if( interactive( tmp ) )
                log_file("DEATH_ALIGN",
                    "%s %s adjusted from %d to %d by %s [%d]\n",
                    ctime(time()), tmp->query_name(), x, y,
                    TO->query_name(), shift );
#endif

        }

        shift = 50 + TO->query_death_xp() / sizeof( things );

        // XP given to each player depends on their level.
        my_level = TO->query_level();
        foreach( tmp in things ) {
            att_level = tmp->query_level();
            if( att_level <= my_level )
                tmp->adjust_xp( shift / 2, 1 );
            else
                tmp->adjust_xp( shift / 4 + ( (shift/4) * my_level ) /
                    att_level, 1 );
        }

        return ({ ({ things }), shift / 2 });
    }

    return ({ });

} /* death_helper() */

/**
 * This does the actual death and co ordinates the death into a well
 * ordered feeding frenzy.  This method creates the actual corpse itself.
 * If the property "dead" is set on the object no corpse will be
 * created, or if the second_life() function called on the object
 * returns a non-zero value the corpse will not be created.
 * <p>
 * This method calls the second_life() function on the current object,
 * if this returns 1 it must handle all the the death code itself.
 * This is used in the player code to override the death code.
 * @param thing the thing which killed us
 * @param weapon the weapon (sword,claw,etc) object that attacked and killed us
 * @param attack the actual attack that killed us
 * @return the corpse, or 0 if no more action is to be taken
 * @index second_life
 * @see death_helper()
 * @see make_corpse()
 * @see alter_corpse()
 */
varargs object do_death( object thing, object weapon, string attack ) {
    object corpse, ob;
    mixed xp_leftover, sec_life;

    if( TO->query_property("dead") && !interactive(TO) ) {
        if( file_name(environment()) != "/room/rubbish")
            TO->move("/room/rubbish");
        return 0;
    }

    // Do this via a callout so that we would have our attacker
    // list intact until this thread is finished.
    call_out( (: stop_all_fight :), 0 );

    reset_protectors();
    reset_defenders();

    TO->add_property("xp before death", TO->query_xp() );

    xp_leftover = death_helper( thing, 1 );

    // This is usually done to players only.
    if( sec_life = TO->second_life() ) {
        // Hand out leftover XP since we're not doing a corpse.
        if( xp_leftover && sizeof( xp_leftover ) == 2 ) {
            foreach( ob in xp_leftover[0] )
                ob->adjust_xp( xp_leftover[1], 1 );
        }

        if( objectp( sec_life ) )
            return sec_life;
        else
            return 0;
    }

    TO->add_property("dead", time() );

    catch( DEATH->someone_died(TO) );
    catch( TO->effects_thru_death() );

    if( environment() ) {
        if( corpse = TO->make_corpse() ) {
            corpse->move( environment() );
            corpse->add_property("XP", xp_leftover, time() + 300 );
            if( !alter_corpse( corpse, weapon, attack ) ) {
                log_file("alter_corpse",
                    "%s: corpse: %O, weapon: %O, attack: %s.\n",
                    ctime(time()), corpse, weapon, attack );
            }
        }
    }

    TO->move("/room/rubbish");

    return corpse;

} /* do_death() */

/**
 * This function is to be shadowed, if you want
 * the creature to be unattackable.
 */
int dont_attack_me() { return 0; }

/**
 * This methid is called when the living object is attacked by something.
 * @param thing the thing we are attacked by
 * @return 0 if we cannot attack them, 1 if we can
 * @see query_attacker_list()
 * @see attack_ob()
 */
int attack_by( object thing ) {
    if( !objectp( thing ) || thing == TO )
        return 0;

    if( thing->query_property("dead") || TO->query_property("dead") )
        return 0;

    if( pk_check( TO, thing ) || TO->query_property( PASSED_OUT ) )
        return 0;

    start_combat(thing);
    TO->set_attacker( thing );

    return 1;

} /* attack_by() */

/**
 * This method is called to make us attack someone else.
 * @param thing the person to attack
 * @return 0 if we cannot attack them, 1 if we can
 * @see query_attacker_list()
 * @see attack_by()
 */
int attack_ob( object thing ) {
    if( !objectp( thing ) || thing == TO )
        return 0;
    if( thing->query_property("dead") || TO->query_property("dead") )
        return 0;
    if( pk_check( thing, TO ) || TO->no_offense() || thing->no_offense() )
        return 0;
    TO->remove_hide_invis("hiding");
    start_combat(thing);
    return 1;

} /* attack_ob() */

/**
 * This method stops the creature from attacking everyone
 * on its attacker list.
 * @see stop_fight()
 */
void stop_all_fight() {
    _combat->attackers = ({ });
    _combat->concentrating = 0;
    _combat->attacker = 0;
    _combat->target = 0;
    _combat->weapon = 0;
    _combat->in_combat = 0;
    _combat->sp_queue = 0;
} /* stop_all_fight() */

/**
 * This method stops the creature from attacking another creature.
 * @param thing the creature to stop attacking
 * @see stop_all_fight()
 */
void stop_fight( object thing ) {
    int i;

    i = sizeof( _combat->attackers );

    if( userp(thing) ) {
        string me;

        me = thing->query_name();

        while( i-- ) {
            if( stringp( _combat->attackers[ i ]->name ) &&
                me == _combat->attackers[ i ]->name ) {
                _combat->attackers = delete( _combat->attackers, i, 1 );
                break;
            }
        }
    } else {
        while( i-- ) {
            if( _combat->attackers[ i ]->ob &&
                _combat->attackers[ i ]->ob == thing ) {
                _combat->attackers = delete( _combat->attackers, i, 1 );
                break;
            }
        }
    }

    if( !sizeof( _combat->attackers ) )
        stop_all_fight();

} /* stop_fight() */

/**
 * This method is called when there is a fight in progress.  It will
 * propogate the event onto all the objects in the room.
 * @param thing the person fighting
 */
void fight_in_progress( object thing ) {
    event( environment(), "fight_in_progress", thing );
} /* fight_in_progress() */

void set_special_manoeuvre() { _combat->special_manoeuvre = 1; }
void reset_special_manoeuvre() { _combat->special_manoeuvre = 0; }
int query_special_manoeuvre() { return _combat->special_manoeuvre; }

/**
 * This method makes us actually attack someone.
 * @param thing the creature we want to attack
 */
protected void start_combat( object thing ) {
    int i;

    set_special_manoeuvre();

    set_heart_beat( _combat->in_combat = 1 );

    i = sizeof( _combat->attackers );

    if( userp(thing) ) {
        string me, you;

        me = thing->query_name();

        while( i-- ) {
            if( stringp( you = _combat->attackers[i]->name ) && me == you  )
                break;
        }
    } else {
        while( i-- ) {
            if( _combat->attackers[i]->ob == thing )
                break;
        }
    }

    // Not on our attacker list already.
    if( i == -1 ) {
        class attacker_data data;

        data = new( class attacker_data );
        data->ob = thing;
        data->time = time() + HUNTING_TIME;

        if( userp(thing) )
            data->name = thing->query_name();

        _combat->attackers += ({ data });
        call_out( (: announce_intent :), 0, thing );
    }

} /* start_combat() */

/**
 * This method notifies the people in the room about us
 * starting to attack someone.
 * @param thing the person we started to attack
 */
private void announce_intent( object thing ) {
    object *obs, env;
    int diff;

    if( !thing || TO->query_property("dead") || !( env = ENV(TO) ) ){
        return;
    }
    if( env != ENV(thing) ){
        return;
    }
    obs = thing->query_attacker_list();

    // Let's not give a message if we are already on their attacker list.
    if( sizeof(obs) &&  member_array( TO, obs ) != -1 ){
        return;
    }
    diff = 50;

    switch( TO->check_dark( env->query_light() ) ) {
      case -2:
      case 2:
        diff *= 4;
      break;
      case -1:
      case 1:
        diff *= 2;
    }

    obs = ({ });

    foreach( object ob in INV(env) ) {
        if( living(ob) ) {
            switch( TASKER->perform_task( ob, PERC_SKILL, diff, TM_FREE ) ) {
              case AWARD:
                tell_object( ob, "%^YELLOW%^You feel very perceptive.%^RESET%^\n");
              case SUCCEED:
                if( interactive(ob) && !ob->query_verbose("combat") )
                    obs += ({ ob });
              break;
              case FAIL:
                obs += ({ ob });
            }
        }
    }

    tell_object( thing, TO->one_short()+" $V$0=moves,move$V$ aggressively "
        "towards you!\n");

    event( env, "see", TO->one_short()+" $V$0=moves,move$V$ aggressively "
        "towards "+thing->one_short()+"!\n", TO, ({ thing, TO }) + obs );

} /* announce_intent() */

/**
 * This method adds a special attack callback into our special attack queue.
 * @param type the type of the special attack
 * @param flags the stage flags for the special attack
 * @param ob the name of the callback object
 * @param fun the name of the callback function
 * @param data any data specific to the special attack
 * @param expire the time after which this special should expire
 */
void register_special_attack( int type, int flags, string ob, string fun,
                              mixed data, int expire ) {
    class special_attack_data sp;

    if( expire > 60 )
        expire = 60;

    sp = new( class special_attack_data,
              type  : type,
              flags : flags,
              ob    : ob,
              fun   : fun,
              data  : data,
              time  : time() + expire );

    if( pointerp( _combat->sp_queue ) )
        _combat->sp_queue += ({ sp });
    else
        _combat->sp_queue = ({ sp });

} /* register_special_attack() */

/**
 * This method is used by the combat handler and returns a class with
 * special attack data, if there is one in the queue that fits the
 * specified arguments.
 * @param type the type of the special attack
 * @param att the attack class
 * @return a class with special attack data or 0
 */
class special_attack_data special_attack( int type, class attack_data att ) {
    class special_attack_data data;
    int i;

    if( !att )
        return 0;

    for( i = 0; i < sizeof(_combat->sp_queue); i++ ) {
        data = _combat->sp_queue[ i ];

        if( data->time < time() ) {
            _combat->sp_queue = delete( _combat->sp_queue, i--, 1 );
            continue;
        }

        if( data->type == type ) {
            att->data = data->data;
            if( call_other( data->ob, data->fun, att ) ) {
                _combat->sp_queue = delete( _combat->sp_queue, i, 1 );
                return data;
            }
        }
    }

    return 0;

} /* special_attack() */

/**
 * This method recalculates the hunting structure, and returns an array
 * of people we are in the same room with, and who we can attack.
 * If we are on a horse in a room with someone, we start attacking them
 * as well.
 * @return returns an array of people on our attacker list that are in
 * the room with us
 */
object *query_attackables() {
    int i;
    string str;
    object ob, env, ob_env, *ret;
    class attacker_data attacker;

    if( !i = sizeof( _combat->attackers ) ) {
        stop_all_fight();
        return 0;
    }

    ret = ({ });

    // Handle mounts...
    env = ENV(TO);
    if( env && env->query_transport() && ENV(env) )
        env = ENV(env);

    // Clean the attackers array, and find valid targets for this attack round.
    while( i-- ) {
        attacker = _combat->attackers[i];

        if( ob = attacker->ob ) {
            if( ob->query_property("dead") ) {
                _combat->attackers = delete( _combat->attackers, i, 1 );
                continue;
            }
        } else if( stringp( str = attacker->name ) ) {
            if( !ob = _combat->attackers[i]->ob = find_player(str) )
                continue;

            if( ob->query_property("dead") ) {
                _combat->attackers = delete( _combat->attackers, i, 1 );
                continue;
            }
        } else {
            // No object nor player name.
            _combat->attackers = delete( _combat->attackers, i, 1 );
            continue;
        }

        if( ob->dont_attack_me() )
            continue;

        // We now have a valid object to work with.
        if( ( ob_env = ENV(ob) ) && ob_env->query_transport() && ENV(ob_env) )
            ob_env = ENV(ob_env);

        if( ob_env == env && ( !userp(ob) || interactive(ob) ) &&
            ob->query_visible(TO) ) {
            ret += ({ ob });
            attacker->time = time() + HUNTING_TIME;
        }
    }

    return ret;

} /* query_attackables() */

/**
 * This method stops us hunting people on our hunting list.
 */
void stop_hunting() {
    int i;
    string str;
    object ob, *stopped;

    // If the player is not hunting anything, don't go any further.
    if( !i = sizeof( _combat->attackers ) )
        return;

    // Work out who the player has stopped hunting.
    stopped = ({ });

    while( i-- ) {
        if( !( ob = _combat->attackers[ i ]->ob ) &&
            stringp( str = _combat->attackers[ i ]->name ) )
            ob = _combat->attackers[ i ]->ob = find_player( str );

        if( !ob && !stringp(str) ) {
            _combat->attackers = delete( _combat->attackers, i, 1 );
            continue;
        }

        if( time() > _combat->attackers[ i ]->time ) {
            if( ob && living( ob ) )
                stopped += ({ ob });
            _combat->attackers = delete( _combat->attackers, i, 1 );
        }
    }

    // Stop the player fighting them too.
    if( sizeof(stopped) )
        tell_object( TO, "You stop hunting "+
            query_multiple_short(stopped)+".\n");

    if( !sizeof( _combat->attackers ) )
        stop_all_fight();

} /* stop_hunting() */

/** @ignore yes */
void heart_beat() {
    if( _combat->in_combat )
        COMBAT_H->attack_round(TO);
} /* heart_beat() */

/** @ignore yes */
mixed stats() {
    int i, j;
    object *weapons;
    mixed ret;

    ret = ({
        ({"attitude", ATTITUDES[ _combat_tactics->attitude + 2 ] }),
        ({"response", _combat_tactics->response }),
        ({"parry", _combat_tactics->parry }),
        ({"unarmed parry", _combat_tactics->unarmed_parry ? "yes" : "no"}),
        ({"focus", _combat_tactics->focus || "none"}),
    });

    if( !sizeof( weapons = TO->query_weapons() ) )
        return ret + ::stats();

    for( i = 0; i < sizeof( weapons ); i++ ) {
        ret += ({ ({"weapon #"+ i, weapons[ i ]->short() }) })+
            weapons[ j ]->weapon_stats();
    }

    return ret;

} /* stats() */

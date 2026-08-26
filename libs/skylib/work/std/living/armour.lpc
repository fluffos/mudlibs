/**
 * This file contains all the armour related code for the living
 * objects.
 * @author Pinkfish
 */

inherit "/std/armour_logic";

#define IMMUNE_TYPES ({"sharp", "blunt", "pierce", "magic", "fire", \
                       "ice", "self"})

nosave string skin;
nosave object *wearing;
nosave mixed stopped;
private string *_immuneto;

void create() {
    skin = "morphological field";
    wearing = ({ });
    ::create();
} /* create() */

/**
 * This method returns the types of attacks that this thing is immune to.
 * @return the list of attacks this thing is immune to
 * @see add_immune(), remove_immune()
 */
string *query_immune() { return _immuneto || ({ }); }

/**
 * This method removes an immune type from the list of damage types
 * this creature is immune to.
 * @param str the damage type to remove from the immunity list
 * @see query_immune(), add_immune()
 */
void remove_immune( string str ) {
    if( !sizeof(_immuneto) )
        return;
    _immuneto -= ({ str });
} /* remove_immune() */

/**
 * This method adds a type of attack to the list of things this
 * object is immune to.
 * @param type the type or array of types of damage to add to
 * the immune list
 * @see query_immune(), remove_immune()
 */
void add_immune( mixed type ) {
    if( !pointerp( _immuneto ) )
        _immuneto = ({ });

    if( pointerp( type ) )
        foreach( string str in type )
            add_immune( str );

    if( stringp( type ) && member_array( type, IMMUNE_TYPES ) != -1 &&
        member_array( type, _immuneto ) == -1 )
        _immuneto += ({ type });

} /* add_immune() */

/**
 * This method returns the current skin of the living object.
 * @return the skin of the object
 * @see set_skin()
 */
string query_skin() { return skin; }

/**
 * This method sets the current skin of the living object.  This can
 * be done by the race object and by specific spells or effects.
 * @param word the new skin type
 * @see query_skin()
 */
void set_skin( string word ) { skin = word; }

/**
 * This method returns all the objects you are currently wearing.
 * @return the current array of worn objects
 * @return the array of worn stuff
 * @see query_armours()
 */
object *query_wearing() { return copy( wearing -= ({ 0 }) ); }

/**
 * This method returns all the armours that the is currently being
 * worn.  This will always return the same value as query_wearing()
 * @see query_wearing()
 * @return the array of armours
 */
object *query_armours() { return query_wearing(); }

/**
 * This method will make sure all the armours are unworn by the living
 * object.
 * @see query_wearing()
 */
void clear_armours() {
    wearing->set_worn_by( 0 );
    wearing = ({ });
} /* clear_armours() */

/**
 * This returns the object which stopped the blow.  This is only valid
 * inside and after a query_ac() call.
 * @return the object which stopped the call
 */
mixed query_stopped() {
    return stopped;
} /* query_stopped() */

/**
 * This method sets the object which stops the call.  This should be
 * used to do weird stuff.  I have no idea what it should be used for
 * at all and I am just rambling.
 * @param arg the new value of the stopped object
 */
void set_stopped( mixed arg ) { stopped = arg; }

/**
 * This method checks to see if the two armour types are
 * equivilant or not.
 * @param comp the first type
 * @param type the second type
 */
protected int equivalent_armour_types( mixed comp, string type ) {
    string word;

    if( stringp( comp ) ) {
        if( CLOTHING_H->query_equivilant_type( comp ) )
            return CLOTHING_H->query_equivilant_type( comp ) == type;
        return comp == type;
    }

    foreach( word in comp ) {
        if( equivalent_armour_types( word, type ) )
            return 1;
    }

    return 0;

} /* equivalent_armour_types() */

/**
 * This is the method used to get the living object to wear a piece of
 * armour or clothing.  This is called from inside the armour or clothing
 * code itself.  It will call the function set_worn_by() on the
 * armour or clothing and if this returns a non-zero result then it
 * will add it into the current list of worn types.  Assuming the
 * type of the armour fits into the allowed list.  It will also
 * call the functon hold_item on the object if it is required to be
 * held as well (ie: shield).
 * @param armour the armour to wear
 * @param doing_hold if this is called by the hold command
 * @return the failure message, or 0 if ok
 * @see remove_armour()
 * @see query_armours()
 * @see query_wearing()
 */
string wear_armour( object armour, int doing_hold ) {
    string type, word;
    mapping things;
    object thing;
    int no_limbs;
    mixed types;

    wearing -= ({ 0 });
    types = armour->query_type();

    if( word = TO->not_allowed_to_wear( types ) )
        return word;

    if( member_array( armour, wearing ) != -1 )
        return "already wearing";

    if( stringp(types) )
        types = ({ types });

    if( !pointerp( types ) )
        return "oh dear";

    things = ([ ]);

    foreach( type in types ) {
        if( CLOTHING_H->query_equivilant_type( type ) )
            type = CLOTHING_H->query_equivilant_type( type );

        things[ type ] = ({ });

        foreach( thing in wearing ) {
            if( equivalent_armour_types( (mixed)thing->query_type(), type ) )
                things[ type ] += ({ thing });
        }
    }

    word = TO->query_race_ob();

    foreach( type in keys( things ) ) {
        if( word->query_number_worn(type) <= sizeof( things[type] ) ) {
            return "since you are already wearing "+
                    query_multiple_short( things[ type ] );
        }
    }

    if( ( no_limbs = armour->query_no_limbs() ) && !doing_hold ) {
        if( member_array( armour, (object *)TO->query_holding() ) != -1 )
            return "already wearing";
        if( sizeof( (int *)armour->hold_item( TO, -1 ) ) )
            return 0;
        else
            return "already holding";
    }

    if( !armour->set_worn_by( TO ) )
        return "oh dear";

    wearing += ({ armour });
    call_out("calc_burden", 1 );

    return 0;

} /* wear_armour() */

/**
 * This method will remove the armour from the living object.
 * @param thing the armour to remove
 * @return 1 if was unsuccessful and 0 if it was successful
 * @see wear_armour()
 * @see query_armours()
 * @see query_wearing()
 */
int remove_armour( object thing ) {
    int i;

    wearing -= ({ 0 });

    if( ( i = member_array( thing, wearing ) ) == -1 )
        return 1;

    if( !thing->set_worn_by( 0 ) )
        return 1;

    if( member_array( thing, TO->query_holding() ) != -1 )
        if( !sizeof( TO->set_unhold(thing) ) )
            return 1;

    wearing = delete( wearing, i, 1 );
    call_out("calc_burden", 1 );
    return 0;

} /* remove_armour() */

/**
 * This function returns the amount of damage that is blocked
 * my the armour on a specified zone.  It automatically
 * damages the armour, and sets the stopped object to be the
 * the object (piece of armour) that stopped the blow.
 *
 * @param type the type of damage, eg: "sharp", "blunt", "pierce"
 * @param amount the amount of damage that is being done
 * @param zone the zone which the damage is being done through, eg: "head"
 * @return the amount of damage that will be blocked
 * @see query_wearing()
 */
varargs int query_ac( string type, int amount, string zone ) {
    object thing, *defenses;
    int part, total;
    string word;

    stopped = 0;

    if( sizeof(_immuneto) && member_array( type, _immuneto ) != -1 ) {
        stopped = skin;
        return amount;
    }

    // This is used by magic and poisons, etc. so the identity of
    // "stopped" is irrelevant, since it bypasses all armour.
    if( zone == "self")
        return ::query_ac( type, amount, zone );

    if( !zone ) {
        switch( random(20) ) {
          case 0..1:   zone = "head";    break;
          case 2:      zone = "neck";    break;
          case 3..6:   zone = "chest";   break;
          case 7..9:   zone = "abdomen"; break;
          case 10..12: zone = "arms";    break;
          case 13..14: zone = "hands";   break;
          case 15..18: zone = "legs";    break;
          case 19:     zone = "feet";    break;
        }
    }

    if(CLOTHING_H->query_clothing_zone( zone )){
    foreach ( word in CLOTHING_H->query_clothing_zone( zone ) ) {
        defenses = wearing -= ({ 0 });
        defenses += uniq_array( filter( TO->query_holding(),
                             (: $1 && $1->query_armour() :) ) );

        foreach( thing in defenses ) {
            if( equivalent_armour_types( thing->query_type(), word ) ) {
                part = thing->query_ac( type, amount, zone );
                if( !stopped && part )
                    stopped = thing;
                total += part;
                amount -= part;
            }
            if( amount < 1 )
                break;
        }
        if( amount < 1 )
            break;
    }
   }

    if( amount > 0 ) {
        if( !stopped )
            stopped = skin;

        if( type == "fire" && TO->effects_matching("body.wetness") &&
            sizeof( TO->effects_matching("body.wetness") ) )
            TO->add_effect("/std/effects/other/wetness", -amount );

        part = ::query_ac( type, amount, zone );
        total += part;
        amount -= part;
    }

    // This is to not let the AC become higher than the amount.
    if( amount < 0 )
        total += amount;

    return total;

} /* query_ac() */

/** @ignore yes */
mixed stats() {
    return ::stats() + ({ ({"skin", skin }) });
} /* stats() */

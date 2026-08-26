/**
 * This is the effect skelton docs.  This effect
 * has a classification of "body.tattoo".
 * <p>
 * This effect takes an array of two members as the argument,
 * the first member of which is the name of the bodypart onto which
 * to add the tattoo, and the second member is the message to add.
 * @classification body.tattoo
 * @see help::effects
 * @author Aksu in July 1997
 * @changed Rewritten partly - Sandoz, 18/10/2002.
 */

#include <effect.h>

private mapping tattooables, tattoo_areas;

class tattoo_area {
    string full;
    string area;
}

/** @ignore yes */
string query_classification() { return "body.tattoo"; }

/** @ignore yes */
int survive_death() { return 1; }

/** @ignore yes */
int query_indefinite() { return 1; }

/**
 * @ignore yes
 * $p in the full name of the area will be converted to
 * player->query_possessive() when used in extra looks,
 * or poss_short() or "the" in other types of messages.
 */
private void add_bodypart( string name, string full, string area ) {
    if( !undefinedp( tattooables[name] ) )
        error("Bodypart '"+name+"' has already been added.\n");

    tattooables[name] = new( class tattoo_area, full : full, area : area );

    if( area ) {
        if( undefinedp( tattoo_areas[area] ) )
            tattoo_areas[area] = ({ name });
        else
            tattoo_areas[area] += ({ name });
    }

} /* add_bodypart() */

// The following were legal clothing areas when this effect was written.
// abdomen, arms, back, chest, feet, hands, head, legs, neck
private void create() {
    tattooables = ([ ]);
    tattoo_areas = ([ ]);

    // Wrists would probably be covered by gloves.
    add_bodypart("left wrist", "on $p left wrist", "hands");
    add_bodypart("right wrist", "on $p right wrist", "hands");
    add_bodypart("left hand", "on $p left hand", "hands");
    add_bodypart("right hand", "on $p right hand", "hands");

    add_bodypart("left arm", "on $p left arm", "arms");
    add_bodypart("right arm", "on $p right arm", "arms");
    add_bodypart("left forearm", "on $p left forearm", "arms");
    add_bodypart("right forearm", "on $p right forearm", "arms");

    add_bodypart("chest", "on $p chest", "chest");
    add_bodypart("left breast", "on $p left breast", "chest");
    add_bodypart("right breast", "on $p right breast", "chest");

    add_bodypart("back", "on $p back", "back");
    add_bodypart("left shoulder blade", "on $p left shoulder blade", "back");
    add_bodypart("right shoulder blade", "on $p right shoulder blade", "back");
    add_bodypart("between shoulder blades", "between $p shoulder blades", "back");
    add_bodypart("base of spine", "at the base of $p spine", "back");

    // Let's all agree that most headgear leaves the face visible.
    add_bodypart("left cheek", "on $p left cheek", 0 );
    add_bodypart("right cheek", "on $p right cheek", 0 );
    add_bodypart("forehead", "on $p forehead", 0 );

    add_bodypart("throat", "on $p throat", "neck");
    add_bodypart("neck", "on $p neck", "neck");
    add_bodypart("back of neck", "at the back of $p neck", "neck");

    add_bodypart("abdomen", "on $p abdomen", "abdomen");
    add_bodypart("above belly button", "above $p belly button", "abdomen");
    add_bodypart("below belly button", "below $p belly button", "abdomen");
    add_bodypart("beside belly button", "beside $p belly button", "abdomen");
    add_bodypart("left hip", "on $p left hip", "abdomen");
    add_bodypart("right hip", "on $p right hip", "abdomen");
    add_bodypart("left buttock", "on $p left buttock", "abdomen");
    add_bodypart("right buttock", "on $p right buttock", "abdomen");

    add_bodypart("left calf", "on $p left calf", "legs");
    add_bodypart("right calf", "on $p right calf", "legs");
    add_bodypart("left knee", "on $p left knee", "legs");
    add_bodypart("right knee", "on $p right knee", "legs");
    add_bodypart("left thigh", "on $p left thigh", "legs");
    add_bodypart("right thigh", "on $p right thigh", "legs");

    add_bodypart("left foot", "on $p left foot", "feet");
    add_bodypart("right foot", "on $p right foot", "feet");
    add_bodypart("left ankle", "on $p left ankle", "feet");
    add_bodypart("right ankle", "on $p right ankle", "feet");

    // Spanning areas.
    add_bodypart("across legs", "across $p legs", "legs");
    add_bodypart("around arms", "around $p arms", "arms");

} /* create() */

/**
 * This method returns an array of all tattooable bodyparts.
 * @return an array of all tattooable bodyparts
 */
string *query_tattooables() { return sort_array( keys(tattooables), 1 ); }

/**
 * This method queries whether or not the specified bodypart is
 * tattooable or not.
 * @param part the name of the bodypart
 * @return 1 if the bodypart is tattooable, 0 if not
 */
int query_tattooable( string part ) {
    return !undefinedp( tattooables[part] );
} /* query_tattooable() */

/**
 * This method returns the full tattoo area description and does the $p
 * expansion on it.
 * @param bodypart the bodypart to get the full description for
 * @param replace what to expand the $p to
 */
string expand_tattooable( string bodypart, string replace ) {
    return replace( tattooables[bodypart]->full, "$p", replace );
} /* expand_tattooable() */

/**
 * This method scans through a player's clothes/armour and checks
 * whether or not a tattoo area is visible.
 * @param player the player to check
 * @param part the bodypart to check
 * @return the objects covering the tattoo, or 0 if visible
 */
object *query_tattoo_covered( object player, string part ) {
    string area;

    if( !undefinedp( tattooables[part] ) ) {
        if( area = tattooables[part]->area ) {
            object ob, *obs, *worn;
            string type;
            mixed types;

            if( !sizeof( worn = player->query_wearing() ) )
                return 0;

            obs = ({ });

            foreach( ob in worn ) {
                if( !pointerp( types = ob->query_type() ) )
                    types = ({ types });

                foreach( type in types ) {
                    if( CLOTHING_H->query_equivilant_type( type ) )
                        type = CLOTHING_H->query_equivilant_type( type );

                    // These don't cover anything.
                    if( member_array( type, ({"ring", "necklace", "belt",
                        "sash", "box", "small scabbard"}) ) != -1 )
                        continue;

                    // Special case - bras don't cover anything but breasts,
                    // despite their clothing area being chest.
                    // Unless someone wants to prove me wrong...
                    // - Sandoz.
                    if( type == "bra") {
                        if( sscanf( part, "%*s breast") == 1 )
                            obs += ({ ob });
                    } else {
                        if( member_array( area,
                            CLOTHING_H->query_zone_names(type) ) != -1 )
                            obs += ({ ob });
                    }
                }
            }
            if( sizeof(obs) )
                return obs;
        }

        return 0;

    }

    error("No such tattoo area.\n");

} /* query_tattoo_covered() */

/** @ignore yes */
mapping query_tattoo_areas() { return copy(tattoo_areas); }

private int test_arg( object player, mixed arg ) {
    if( !pointerp(arg) || sizeof(arg) != 2 )
        error("Bad argument to the tattoo effect; must be an array of two "
            "elements.\n");

    if( !query_tattooable( arg[0] ) ) {
        tell_object( player, "The bodypart you were trying to get a tattoo "
            "on is invalid.  Please file a bug report or contact a "
            "creator.\n");
        return 0;
    }

    if( !stringp( arg[1] ) || arg[1] == "") {
        tell_object( player, "Tried to add an empty tattoo.  Please file a "
            "bug report or contact a creator.\n");
        return 0;
    }

    return 1;

} /* test_arg() */

/** @ignore yes */
mapping beginning( object player, string *arg ) {
    if( !test_arg( player, arg ) )
        return ([ ]);

    player->add_extra_look( TO );

    return ([ arg[ 0 ] : ({ arg[ 1 ] }) ]);

} /* beginning() */

/** @ignore yes */
mapping merge_effect( object player, mapping arg, string *new_arg ) {
    if( !test_arg( player, new_arg ) )
        return arg;

    if( !arg[ new_arg[ 0 ] ] )
        arg[ new_arg[ 0 ] ] = ({ new_arg[ 1 ] });
    else
        arg[ new_arg[ 0 ] ] += ({ new_arg[ 1 ] });

    return arg;

} /* merge_effect() */

/** @ignore yes */
void restart( object player ) {
    player->add_extra_look( TO );
} /* restart() */

/** @ignore yes */
void end( object player ) {
    player->remove_extra_look( TO );
} /* end() */

/** @ignore yes */
string extra_look( object player ) {
    string type, *visible, *covered_areas;
    mapping tattoos;
    mixed types;
    object ob, *worn;
    int i, plural;

    if( player->query_property("dead") )
        return "";

    tattoos = player->arg_of( player->effects_matching("body.tattoo")[ 0 ] );

    if( !sizeof(tattoos) )
        return "";

    visible = keys(tattoos);
    covered_areas = ({ });

    if( sizeof( worn = player->query_wearing() ) ) {
        foreach( ob in worn ) {
            if( !pointerp( types = ob->query_type() ) )
                types = ({ types });

            foreach( type in types ) {
                if( CLOTHING_H->query_equivilant_type( type ) )
                    type = CLOTHING_H->query_equivilant_type( type );

                // These don't cover anything.
                if( member_array( type, ({"ring", "necklace", "belt", "sash",
                    "box", "small scabbard"}) ) != -1 )
                    continue;

                // Special case - bras don't cover anything but breasts,
                // despite their clothing area being chest.
                // Unless someone wants to prove me wrong...
                // - Sandoz.
                if( type == "bra")
                    visible -= ({"left breast", "right breast"});
                else
                    covered_areas |= CLOTHING_H->query_zone_names(type);
            }
        }
    }

    foreach( type in covered_areas )
        if( !undefinedp( tattoo_areas[type] ) )
            visible -= tattoo_areas[type];

    if( !( i = sizeof(visible) ) )
        return "";

    type = player->HIS;

    while( i-- ) {
        plural += sizeof( tattoos[ visible[i] ] );
        visible[i] = query_multiple_short( tattoos[ visible[i] ] )+" "+
                     expand_tattooable( visible[i], type );
    }

    return CAP( player->HE )+" bears "+( plural > 1 ? "tattoos" :
           "a tattoo")+" of "+query_multiple_short(visible)+".\n";

} /* extra_look() */

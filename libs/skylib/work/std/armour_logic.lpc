/**
 * This is the main armour inheritable.
 * This will be nasty...
 * @changed Changed to use a mapping for armour_types, and added docs
 * - Sandoz, July 2003.
 */

#define F_FIXED      0
#define F_NUM        1
#define F_DIE        2
#define F_RAND       1

#define A_ARRAY_SIZE 2
#define A_NAME       0
#define A_TYPE       1
#define A_AC         0

nosave mapping ac, armour_types;

void create() {
    ac = ([ ]);
    armour_types = ([ ]);
} /* create() */

/**
 * This method makes an object to have an armour class against a
 * certain type of damage.  It is used when you want to give an object
 * (usually armour) the ability to protect against a specific type of
 * damage.
 * The first of the three arguments to the function is the name of
 * the armour class to add.  This can be anything, but please use
 * something meaningful.
 * The second argument is the attack type to protect against,
 * usually "sharp", "blunt", "pierce" or similar.
 * The third argument is the actual armour class.  The higher this is,
 * the better protection the armour will provide.  If the argument is
 * a number, the AC will be random( number ).  In case of a 1 element
 * array, the AC will be that element.  With a 2 element array, the AC
 * will be the 1st element + random( 2nd element ).  With a 3 element
 * array, it will be 1st + 2nd D 3rd.
 * @example add_ac("standard_blunt", "blunt", 50 );
 * @example add_ac("standard_pierce", "pierce", ({ 50 }) );
 * @example add_ac("standard_sharp", "sharp", ({ 25, 50 }) );
 * @example add_ac("fire", "fire", ({ 20, 4, 10 }) );
 * @param name the name of the armour class to add
 * @param type the type of damage to protect against
 * @param a_c the actual armour class
 * @return 1 if the new armour class was successfully added, 0 if not
 */
int add_ac( string name, string type, mixed a_c ) {
    if( !stringp(name) || !stringp(type) || !a_c )
        return 0;

    if( !mapp(ac) )
        ac = ([ ]);

    if( ac[name] )
        return 0;

    ac[name] = ({ a_c, type });

    if( armour_types[type] )
        armour_types[type] += ({ name });
    else
        armour_types[type] = ({ name });

    return 1;

} /* add_ac() */

/**
 * This method removes an armour class with the specified name from an object.
 * @param name the name of the armour class to remove
 * @return 1 upon success, 0 upon failure
 */
int remove_ac( string name ) {
    string type;

    if( !mapp(ac) || undefinedp( ac[name] ) )
        return 0;

    type = ac[name][A_TYPE];

    if( !sizeof( armour_types[type] -= ({ name }) ) )
        map_delete( armour_types, type );

    map_delete( ac, name );
    return 1;

} /* remove_ac() */

/** @ignore yes */
int calc_value( mixed arr ) {
    if( intp(arr) ) {
        if( !random(10) )
            return random(arr);
        else
            return arr;
    }

    if( !pointerp(arr) )
        return 0;

    switch( sizeof(arr) ) {
      case 1 :
        return arr[F_FIXED];
      case 2 :
        return arr[F_FIXED] + random( arr[F_RAND] );
      case 3 :
        return arr[F_FIXED] + roll_MdN( arr[F_NUM], arr[F_DIE] );
      default :
        return 0;
    }

} /* calc_value() */

/**
 * This method returns the armour class rating the object has
 * against the specified type of damage.
 * @param type the type of damage to get the AC for
 * @param damage the damage done
 * @param zone the body area being hit
 * @return the armour class rating
 */
varargs int query_ac( string type, int damage, string zone ) {
    if( armour_types && armour_types[type] ) {
        string name;
        int ret;

        foreach( name in armour_types[type] )
            ret += calc_value( ac[name][A_AC] );

        return ret - ret / 4;

    }

    return 0;

} /* query_ac() */

/**
 * This method returns the whole armour class mapping.
 * @return the whole armour class mapping
 */
mapping query_armour_class() { return copy(ac); }

/**
 * This method returns the whole armour class types mapping.
 * @return the whole armour class types mapping
 */
mapping query_armour_types() { return copy(armour_types); }

/** @ignore yes */
private string calc_string( mixed arr ) {
    if( intp(arr) )
        return "rand("+arr+")";

    if( !pointerp(arr) )
        return "broken";

    switch( sizeof(arr) ) {
      case 1 :
        return ""+arr[0];
      case 2 :
        return ""+arr[0]+"+rand("+arr[1]+")";
      case 3 :
        return ""+arr[0]+"+"+arr[1]+"d"+arr[2];
      default :
        return "invalid";
    }

} /* calc_string() */

/** @ignore yes */
mixed stats() {
    if( sizeof(ac) ) {
        string name, *names;
        mixed *ret;
        int i;

        ret = ({ });
        names = keys(ac);

        for( i = 0; i < sizeof(names); i++ ) {
            name = names[i];

            ret += ({
                ({"ARM"+i+" name", name, }),
                ({"     type", ac[name][A_TYPE], }),
                ({"    class", calc_string( ac[name][A_AC] ) }),
            });
        }

        return ret;
    }

    return ({ });

} /* stats() */

/** @ignore yes */
void set_ac( mixed bing ) {
    int i;

    for( i = 0; i < sizeof(ac); i += A_ARRAY_SIZE )
        add_ac( ac[i], ac[i+1][A_TYPE], ac[i+1][A_AC] );

} /* set_ac() */

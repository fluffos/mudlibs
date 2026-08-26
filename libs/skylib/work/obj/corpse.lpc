
#include <bit.h>
#include <corpse.h>
#include <move_failures.h>
#include <weapon.h>

// 200/5*30 seconds == 20 minutes
#define DECAY_BASE        200
#define PLAYER_DECAY_BASE 600

inherit "/std/container";
inherit "/std/living/carrying";

int decay, gender;
string owner, race_ob, race_name, *bits_gone, *permitted;
object weapon, *armours, *holding;

/**
 * This method queries whether or not we are a corpse.
 * @return always returns 1
 */
int query_corpse() { return 1; }

/**
 * This method returns our decay value.
 * @return the decay value
 */
int query_decay() { return decay; }

/**
 * This method sets the decay value for the corpse.
 * @param dec the decay value to set
 */
void set_decay( int dec ) { decay = dec; }

/**
 * This returns the short desc or name of the owner of the corpse.
 * @return the short desc or name of the owner of the corpse
 */
string query_owner() { return owner; }

/**
 * This method returns the array of people who are
 * permitted to take things from our corpse.
 * @return people permitted to take things from our corpse
 */
string *query_permitted() { return permitted; }

/**
 * This method sets the race object of the corpse.
 * @param str the race object to set
 */
void set_race_ob( string str ) { race_ob = str; }

/**
 * This method returns the corpse's race object.
 * @return the race object
 */
string query_race_ob() { return race_ob; }

/**
 * This method sets the race name of the corpse.
 * @param str the race name to set
 */
void set_race_name( string str ) { race_name = str; }

/**
 * This method returns the corpse's race name.
 * @return the race name
 */
string query_race_name() { return race_name; }

/**
 * This method sets the gender of the corpse.
 * @param i the gender of the corpse
 */
void set_gender( int i ) { gender = i; }

/**
 * This method returns the gender of the corpse.
 * @return the gender of the corpse
 */
int query_gender() { return gender; }

/**
 * This method returns a descriptive string of the
 * gender of the corpse.
 * @return a string describing the gender of the corpse
 */
string query_gender_string() {
    switch( gender ) {
      case 1 :
        return "male";
      case 2 :
        return "female";
      default :
        return "neuter";
    }
} /* query_gender_string() */

void setup() {
    bits_gone = ({ });
    owner = "noone";
    race_name = "womble";
    gender = 0;
    decay = DECAY_BASE;

    add_property("cureable", 1 );
    add_property("determinate", "the ");

    set_name("corpse");
    set_short("corpse");
    add_alias( ({"corpse", "body", "carcass"}) );

    set_long("This is a corpse.  It looks dead.\n");

    set_weight( STD_CORPSE_WEIGHT );
    set_race_ob("/std/races/unknown");

    permitted = ({ });
    armours = ({ });
    holding = ({ });

} /* setup() */

/**
 * This method adds a person to the array of people we are
 * allowing to take things from our corpse.
 * @param who the name of the person to permit
 */
void give_permission( string who ) { permitted += ({ who }); }

/** @ignore yes */
int get( mixed dest ) {
    if( query_property("player") && dest && TP ) {
        if( TP->query_name() != query_ownership() &&
            member_array( TP->query_name(), permitted ) == -1 )
            return MOVE_INVALID_DEST;
    }

    return ::get(dest);

} /* get() */

/** @ignore yes */
int test_remove( object thing, int flag, mixed dest ) {
    if( thing->query_property("my corpse") == TO )
        return 1;

    if( query_property("player") ) {
        if( !sizeof( permitted ) || !TP )
            return ::test_remove( thing, flag, dest );
        if( member_array( TP->query_name(), permitted ) == -1 )
            return ::test_remove( thing, flag, dest );
        // Use add_message here so that verb expansion would work.
        TP->add_message( thing->the_short()+" $V$0=buzzes,buzz$V$ for a "
            "moment.\n");
    }

    return 1;

} /* test_remove() */

/**
 * This method sets the owner of the corpse.
 * It will also set up various other things such as adjectives, etc.
 * @param who the name or short desc of the owner
 * @param thing the object of the owner
 */
void set_owner( string who, object thing ) {
    string str;

    if( stringp( who ) ) {
        owner = who;
    } else {
        if( stringp( str = thing->query_property("determinate") ) )
            owner = str + thing->short();
        else
            owner = add_a( thing->short() );
    }

    if( thing && thing->query_property("player") )
        set_decay(PLAYER_DECAY_BASE);

    set_short("corpse of "+owner );

    if( thing ) {
        if( thing->query_property("player") ) {
            set_main_plural("corpses of "+owner );
        } else if( thing->query_main_plural() ) {
            set_main_plural("corpses of "+thing->query_main_plural() );
        } else {
            set_main_plural("corpses of "+ pluralize( thing->short() ) );
        }
    } else {
        set_main_plural("corpses");
    }

    set_long("This is the dead body of "+owner+".\n");

    if( thing && thing->query_actual_weight() )
        set_weight( thing->query_actual_weight() );
    else
        set_weight( STD_CORPSE_WEIGHT );

    BITS_H->add_bit(TO);

} /* set_owner() */

/** @ignore yes */
void set_decay_messages() {
    if( !race_name )
        race_name = race_ob->query_name();

    switch( decay ) {
      case 101 .. PLAYER_DECAY_BASE :
      break;
      case 51..100:
        if( !query_property("player") ) {
            set_short("somewhat decayed remains of a corpse");
            set_short("somewhat decayed remains of "+( gender ? "a "+
                query_gender_string()+" "+race_name : add_a(race_name) ) );
            set_main_plural("somewhat decayed remains of "+
                pluralize(race_name) );
        }
      break;
      case 1..50:
        set_short("decayed remains of "+( gender ? "a "+
            query_gender_string()+" "+race_name : add_a(race_name) ) );
        set_main_plural("decayed remains of "+pluralize(race_name) );
        set_long("This is the dead body of "+( gender ? "a "+
            query_gender_string()+" "+race_name : add_a(race_name) )+".\n");
      break;
      default :
        set_ownership( 0 );
        all_inventory()->move( ENV(TO) );
        move("/room/rubbish");
    }
} /* set_decay_messages() */

/** @ignore yes */
void do_decay() {
    int rate;

    if( !ENV(TO) )
        return;

    rate = 5 + ENV(TO)->query_property("decay rate");

    if( rate > 0 )
        decay -= rate;

    set_decay_messages();

} /* do_decay() */

/** @ignore yes */
string *remove_array_parts( string *a1, string *a2 ) {
    if( sizeof(a2) ) {
        foreach( string a in a2 ) {
            for( int i = 0; i < sizeof(a1); i++ ) {
                if( a == a1[i] ) {
                    a1 = delete( a1, i, 1 );
                    break;
                }
            }
        }
    }

    return a1;

} /* remove_array_parts() */

/**
 * This method queries whether or not a specific bit is left in the corpse.
 * @param str the bit to check for
 * @return the bit
 */
string query_bit_left( string str ) {
    string *bits;

    bits = race_ob->query_possible_bits(str);

    if( !bits || !sizeof(bits) )
        return 0;

    bits = remove_array_parts( bits, bits_gone );

    if( !sizeof(bits) )
        return 0;

    return bits[0];

} /* query_bit_left() */

/**
 * This method queries whether or not specific bits are left in the corpse.
 * This checks for the plural bits.
 * @param str the bit to check for
 * @return an array of bits
 */
string *query_bit_left_pl( string str ) {
    string *bits;

    bits = race_ob->query_possible_plural_bits(str);

    if( !bits || !sizeof(bits) )
        return 0;

    bits = remove_array_parts( bits, bits_gone );

    if( !sizeof(bits) )
        return 0;

    return bits;

} /* query_bit_left() */

/**
 * This method returns the edible bits that are still in the corpse.
 * @return the edible bits still in the corpse
 */
string *query_edible_bits_left() {
    string *bits, *inedible;

    if( !( bits = race_ob->query_possible_bits() ) ||
        !( inedible = race_ob->query_all_inedible() ) )
        return ({ });

    return remove_array_parts( bits, bits_gone ) - inedible;

} /* query_edible_bits_left() */

/**
 * This object creates a bit and returns its object,
 * if one is present in the corpse.
 * @param which_bit the name of the bit to create
 * @return the new bit
 */
object make_bit( string which_bit ) {
    object bitobj;
    mixed bit;
    int i, j;
    string *bits_rem;

    bit = race_ob->query_bit(which_bit);

    if( sizeof( bit[2][2] ) > 1 && stringp( bit[2][2][0] ) ) {
        bitobj = clone_object( bit[2][2][0] );
    } else {
        bitobj = clone_object("/std/bit");
    }

    bitobj->set_race_ob(race_ob);

    if( race_name ) {
        bitobj->set_race_name(race_name);
    } else {
        bitobj->set_race_name(race_ob->query_name());
    }

    bitobj->set_corpse_weight(query_weight());

    if( !race_ob->query_eat( bit[BIT_NAME] ) ) {
        bitobj->set_bit( bit[0], 0 );
    } else {
        bitobj->set_bit( bit[0], decay * 2 / 3 );
    }

    for( i = 0; i < sizeof(bits_gone); i++ ) {
        j = member_array( bits_gone[i], bit[BIT_EXTRA] );
        if( j != -1 )
            bitobj->add_bit_gone( bits_gone[i] );
    }

/*    bits_gone += ({ bit[ BIT_NAME ] });

    foreach( tmp in bit[ BIT_EXTRA ][ 3 .. sizeof(bit[BIT_EXTRA]) ]) {
        if( arrayp( race_ob->query_bit( tmp )[2][2] ) &&
            intp( race_ob->query_bit( tmp )[2][2][1] ) ) {
            for( i = 0; i < race_ob->query_bit( tmp )[2][2][1]; i++ )
                bits_gone += ({ tmp });
        }
    }*/

    bits_rem = ({ bit[ BIT_NAME ] });

    for( i = 0; i < sizeof(bits_rem); i++ ) {
        if((sizeof(race_ob->query_bit(bits_rem[i])) > 2) && (sizeof(race_ob->query_bit(bits_rem[i])[2]) > 3)) {
            bits_rem += race_ob->query_bit(bits_rem[i])[2][3..];
        }
    }
    
    bits_gone = uniq_array(bits_gone + bits_rem);

    if( which_bit == "head") {
        set_long( query_long()+"It is decapitated.\n");
        set_short("decapitated corpse of "+owner );
    }

    if( bitobj->move(TO) && ENV(TO) )
        bitobj->move(ENV(TO));

    bitobj->add_property("my corpse", TO );

    return bitobj;

} /* make_bit() */

/**
 * This method creates actual object from the required bits.
 * @param what_bits the bits to create objects from
 * @return an array of newly created bit objects
 */
object *make_bits( string *what_bits ) {
    string bit;
    object *bits;

    bits = ({ });

    foreach( bit in what_bits )
        bits += ({ make_bit(bit) });

    return bits;

} /* make_bits() */

/** @ignore yes */
varargs object *find_inv_match( string str, object looker ) {
    string bit, *bits;
    object *weps;
    mixed data;
    int cut;

    if( undefinedp( str ) )
        return all_inventory();

    bit = query_bit_left(str);
    bits = query_bit_left_pl(str);

    if( !bit && !sizeof(bits) )
        return all_inventory();

    if( looker )
        weps = looker->query_weapons();

    if( sizeof(weps) ) {
        foreach( object wep in weps ) {
            data = wep->query_attack_data();
            for( int i = 0; i < sizeof(data); i += W_ARRAY_SIZE ) {
                if( data[i+W_TYPE] == "sharp") {
                    cut = 1;
                    break;
                }
            }
            // Break out of the foreach loop as well.
            if( cut )
                break;
        }
    }

    if( bit ) {
        if( cut || race_ob->query_pluckable(bit) )
            return ({ make_bit(bit) });
        tell_object( looker, "You need a sharp implement to cut things from "+
            the_short()+".\n");
        return ({ });
    }

    if( sizeof(bits) ) {
        if( cut ) {
            if( sizeof(bits) > 5 )
                return make_bits( bits[0..4] );
            else
                return make_bits( bits );
        }

        foreach( bit in bits )
            if( !race_ob->query_pluckable(bit) )
                bits -= ({ bit });

        if( sizeof(bits) ) {
            if( sizeof(bits) > 5 )
                return make_bits( bits[0..4] );
            else
                return make_bits( bits );
        }

        tell_object( looker, "You need a sharp implement to cut things from "+
            the_short()+".\n");
        return ({ });
    }

}  /* find_inv_match() */

/**
 * This method returns the array of bits that have been
 * removed from the corpse.
 * @return the array of bits gone
 */
string *query_bits_gone() { return bits_gone; }

/**
 * This method adds a bit to the array of bits gone in the corpse.
 * @param bit the bit to remove
 * @return the data of the newly removed bit
 */
mixed *add_bit_gone( string bit ) {
    string *poss_bits, tmp;
    mixed details;
    int i;

    if( !poss_bits = race_ob->query_possible_bits(bit) )
        return 0;

    poss_bits = remove_array_parts( poss_bits, bits_gone );

    if( !sizeof(poss_bits) )
        return 0;

    details = race_ob->query_bit( poss_bits[ 0 ] );
    bits_gone += ({ details[ BIT_NAME ] });

    foreach( tmp in details[ BIT_EXTRA ][3..sizeof(details[BIT_EXTRA]) ] ) {
        if( arrayp( race_ob->query_bit( tmp )[2][2] ) &&
            intp( race_ob->query_bit( tmp )[2][2][1] ) )
            for( i = 0; i < race_ob->query_bit( tmp )[2][2][1]; i++ )
                bits_gone += ({ tmp });
    }

    return details;

} /* add_bit_gone() */

/** @ignore yes */
void set_bits_gone( string *bits ) {
    int i;

    bits_gone = ({ });

    for( i = 0; i < sizeof( bits ); i++ )
        add_bit_gone( bits[ i ] );

} /* set_bits_gone() */

/**
 * This method returns all the bits left in the corpse.
 * @return all bits left in the corpse
 */
string *query_bits_left() {
    string *all_bits;
    mixed *bits;
    int i, j;

    bits = race_ob->query_bits();
    all_bits = ({ });

    for( i = 0; i < sizeof(bits); i += 3 ) {
        if( bits[i+2][2] ) {
            for( j = 0; j < bits[i+2][2][1]; j++ )
                all_bits += ({ bits[ i ] });
        }
    }

    return remove_array_parts( all_bits, bits_gone );

} /* query_bits_left */

/** @ignore yes */
object *query_armours() {
    int i;

    armours -= ({ 0 });

    for( i = 0; i < sizeof(armours); i++ ) {
        if( armours[ i ]->query_worn_by() != TO ) {
            armours = delete( armours, i, 1 );
            i--;
        }
    }

    return copy(armours);

} /* query_armours() */

/** @ignore yes */
object *query_wearing() { return query_armours(); }

/** @ignore yes */
void set_armours( object *things ) {
    int i;

    armours = ({ });

    for( i = 0; i < sizeof(things); i++ ) {
        if( things[ i ]->query_no_limbs() )
            holding += ({ things[ i ] });
        else
            armours += ({ things[ i ] });
    }

} /* set_armours() */

/** @ignore yes */
void remove_armour( object arm ) { armours -= ({ arm }); }

/** @ignore yes */
void set_weapon( object wep ) { weapon = wep; }
/** @ignore yes */
object query_weapon() { return weapon; }

/** @ignore yes */
void set_holding( object *hold ) { holding += hold; }
/** @ignore yes */
object *query_holding() { return holding; }

/** @ignore yes */
int *set_unhold( object ob ) {
    int pos;

    if( ( pos = member_array( ob, holding ) ) == -1 )
        return ({ });

    if( !ob->set_holder( 0 ) )
        return ({ });

    holding -= ({ ob });

    return ({ pos });

} /* set_hold() */

/** @ignore yes */
int *set_hold( object ob, int pos ) {
    if( member_array( ob, holding ) != -1 )
        return ({ });

    holding += ({ ob });

    return ({ pos });

} /* set_hold() */

/** @ignore yes */
private string pluralize_bit( string *arr ) {
    if( sizeof(arr) == 1 )
        return add_a( arr[0] );
    return query_num( sizeof(arr) )+" "+pluralize( arr[0] );
} /* do_plural_bit() */

/** @ignore yes */
string long( string str, int dark ) {
    str = ::long( str, dark );

    if( sizeof( query_bits_gone() ) ) {
        string *arr;

        arr = map( unique_array( query_bits_gone(), (: $1 :) ),
            (: pluralize_bit($1) :) );

        str += "It appears to be missing "+query_multiple_short(arr)+".\n";
    }

    if( dark == 2 || dark == -2 ) {
        if( query_living_contents( 0 ) != "")
            return str + "Carrying, wearing or holding some things you "
                "cannot make out.\n";
    }

    return str + query_living_contents( 0 );

} /* long() */

/** @ignore yes */
void dest_me() {
    object ob;
    mixed xp;

    // This hands out the rest of the death Xp when the object is destructed.
    // Hopefully by burial or ventisepelating or whatever.
    xp = query_property("XP");
    if( xp && sizeof(xp) == 2 ) {
        foreach( ob in xp[0] ) {
            if( ob )
                ob->adjust_xp( xp[1], 1 );
        }
    }

    BIT_CONTROLLER->remove_bit(TO);

    if( ENV(TO) )
        all_inventory()->move( ENV(TO) );

    ::dest_me();

} /* dest_me() */

mapping query_static_auto_load() {
    return int_query_static_auto_load();
} /* query_static_auto_load() */

/** @ignore yes */
mapping query_dynamic_auto_load() {
    mapping map;

    map = ([
        "::"        : ::query_dynamic_auto_load(),
        "decay"     : decay,
        "owner"     : owner,
        "race ob"   : race_ob,
        "race name" : race_name,
    ]);

    if( gender )
        map["gender"] = gender;
    if( sizeof(bits_gone) )
        map["bits gone"] = bits_gone;
    if( query_ownership() )
        map["ownership"] = query_ownership();

    return map;

} /* query_dynamic_auto_load() */

/** @ignore yes */
void init_dynamic_arg( mapping map ) {
    if( map["ownership"] )
        set_ownership( map["ownership"] );

    if( map["::"] )
        ::init_dynamic_arg( map["::"] );

    if( map["decay"] )
        decay = map["decay"];
    if( map["owner"] )
        owner = map["owner"];
    if( map["race ob"] )
        race_ob = map["race ob"];
    if( map["race name"] )
        race_name = map["race name"];
    if( map["gender"] )
        gender = map["gender"];
    if( map["bits gone"] )
        bits_gone = map["bits gone"];

    set_decay_messages();

} /* init_dynamic_arg() */

/** @ignore yes */
mixed *stats() {
    return ::stats() + ({
        ({"decay", decay }),
        ({"owner", owner }),
        ({"ownership", query_ownership() }),
        ({"race ob", race_ob }),
        ({"race name", race_name }),
        ({"gender", query_gender_string() }),
    });
} /* stat() */

/**
 * @ignore yes
 * This is added so that it acts like a living object and
 * things like non-movable signs cannot be added to it.
 */
int test_add( object ob, int flag ) {
    if( !ENV(ob) )
        return 1;
    return !flag;
} /* test_add() */

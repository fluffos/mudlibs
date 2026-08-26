/**
 * This object handles all the different types of clothing, their
 * locations etc.
 * @author Pinkfish
 */

#include <clothing.h>

mapping _types;
mapping _equivilants;
mapping _zones;
string *_zone_level;

protected void add_clothing_type( string name, string *not_remove,
                                  string *hiding );
protected void add_clothing_zone( string zone, string *types );
private int fixup_types( string type, string *types );
protected void add_equivilant_type( string name, string equiv );
private void check_clothing_types();
string *query_clothing_zone( string zone );
string *query_clothing_cannot_remove( string type );
varargs mixed can_wear_or_remove( object thing, object player, int flag );

void create() {
    _types = ([ ]);
    _equivilants = ([ ]);
    _zones = ([ ]);
    _zone_level = ({ });
    call_out( (: check_clothing_types() :), 2 );

    // Do not reorder this next section, it is in a nice order.
    add_clothing_type("wig", ({ "hood", "helmet", "coif", "hat", "all covering" }), ({ "hood", "helmet", "coif", "hat", "all covering" }));
    add_clothing_type("hat", ({ "hood", "helmet", "coif", "all covering" }), ({ "hood", "helmet", "coif", "all covering" }));
    add_clothing_type("helmet", ({ "hood", "all covering" }), ({ "hood", "all covering" }));
    add_clothing_type("hood", ({"all covering" }), ({ "all covering" }));
    add_clothing_type("earring", ({"coif", "all covering" }), ({ "hood", "coif", "all covering" }));
    add_clothing_type("moustache", ({"all covering" }), ({ "all covering" }));
    add_clothing_type("glasses", ({ "all covering" }), ({ "all covering" }));
    add_clothing_type("mask", ({ "all covering" }), ({ "all covering" }));
    add_clothing_type("headband", ({"hood", "helmet", "coif", "all covering" }), ({ "hood", "helmet", "coif", "all covering" }));
    add_clothing_type("scarf", ({ "hood", "all covering" }), ({"hood", "all covering"}));
    add_clothing_type("necklace", ({"coif", "all covering" }), ({"coif", "all covering" }));
    add_clothing_type("collar", ({ "hood", "all covering" }), ({"hood", "all covering"}));
    add_clothing_type("bra", ({ "cape", "sash", "robe",  "tabard", "breastplate", "hauberk", "haubergon", "byrnie", "jacket", "jumper", "shirt", "undershirt", "all covering" }), ({ "robe", "tabard", "breastplate", "hauberk", "haubergon", "byrnie", "jacket", "jumper", "shirt", "undershirt","all covering" }));
    add_clothing_type("undershirt", ({ "cape", "sash", "robe", "tabard", "breastplate", "haubergon", "hauberk", "byrnie", "jacket", "jumper", "shirt", "harness", "all covering" }), ({ "robe", "tabard", "breastplate", "haubergon", "hauberk", "byrnie", "jacket", "jumper", "shirt", "all covering" }));
    add_clothing_type("shirt", ({ "cape", "sash", "robe", "tabard", "breastplate", "haubergon", "hauberk", "byrnie", "jacket",  "jumper", "harness", "all covering" }), ({ "robe", "haubergon", "hauberk", "byrnie", "jacket", "jumper", "all covering" }));
    add_clothing_type("harness", ({ "all covering" }), ({ "all covering" }));
    add_clothing_type("jumper", ({ "cape", "sash", "robe", "breastplate", "haubergon", "hauberk", "byrnie", "tabard", "jacket",  "all covering" }), ({ "robe", "haubergon", "hauberk", "jacket", "all covering" }));
    add_clothing_type("jacket", ({ "cape", "sash", "robe", "tabard", "breastplate", "haubergon", "hauberk", "byrnie", "all covering" }), ({ "robe", "hauberk", "all covering" }));
    add_clothing_type("tabard", ({ "cape", "sash", "robe", "all covering" }), ({ "robe", "all covering" }));
    add_clothing_type("robe", ({ "cape", "sash", "all covering" }), ({"all covering" }));
    add_clothing_type("sash", ({ "cape", "all covering" }), ({"all covering" }));
    add_clothing_type("cape", ({ "all covering" }), ({ "all covering" }));
    add_clothing_type("armband", ({ "all covering" }), ({ "robe", "all covering" }));
    add_clothing_type("glove", ({ "gauntlet", "all covering" }), ({ "gauntlet", "all covering" }));
    add_clothing_type("gauntlet", ({ "all covering" }), ({ "all covering" }));
    add_clothing_type("bracelet", ({ "gauntlet", "glove", "all covering" }), ({ "gauntlet", "glove", "all covering" }));
    add_clothing_type("ring", ({ "gauntlet", "glove", "all covering" }), ({ "gauntlet", "glove", "all covering" }));
    add_clothing_type("box", ({ "robe", "all covering" }), ({ "robe", "skirt", "all covering" }));
    add_clothing_type("apron", ({ "all covering" }), ({ "all covering" }));
    add_clothing_type("underwear", ({ "harness", "trousers", "greave", "hauberk", "haubergon", "byrnie", "belt", "trousers", "all covering" }), ({ "robe", "skirt", "trousers", "all covering" }));
    add_clothing_type("garter", ({ "greave", "hauberk", "trousers", "all covering" }), ({ "robe", "greave", "hauberk", "trousers", "skirt", "all covering" }));
    add_clothing_type("skirt", ({ "belt", "all covering" }), ({ "robe", "all covering" }));
    add_clothing_type("trousers", ({ "greave", "hauberk", "belt" }), ({ "skirt", "hauberk", "robe", "all covering" }));
    add_clothing_type("belt", ({"hauberk", "haubergon", "byrnie", "all covering" }), ({ "robe", "hauberk", "haubergon", "byrnie", "all covering" }));
    add_clothing_type("sock", ({ "overshoe", "boot", "chausse", "sandal", "all covering" }), ({ "overshoe", "boot", "chausse", "all covering" }));
    add_clothing_type("boot", ({ "overshoe" }), ({ "overshoe", "all covering" }));
    add_clothing_type("sandal", ({ "overshoe" }), ({ "overshoe", "all covering" }));
    add_clothing_type("overshoe", ({ }), ({ "all covering" }));

    // Shields and scabbards.
    add_clothing_type("small shield", ({"all covering" }), ({ "all covering" }));
    add_clothing_type("shield", ({"all covering" }), ({ "all covering" }));
    add_clothing_type("large shield", ({"all covering" }), ({ "all covering" }));
    add_clothing_type("badge", ({ "all covering" }), ({ "all covering" }));
    add_clothing_type("scabbard", ({ "all covering" }), ({ "all covering" }));
    add_clothing_type("small scabbard", ({ "all covering" }), ({"robe", "all covering" }));
    add_clothing_type("belt scabbard", ({ "all covering" }), ({"robe", "all covering" }));

    // Mail armour.
    add_clothing_type("coif", ({"hood", "scarf", "helmet", "all covering"}), ({"hood", "all covering"}));
    add_clothing_type("byrnie", ({"breastplate", "backplate", "tabard", "small scabbard", "belt scabbard", "robe", "cape", "sash", "all covering" }), ({ "robe", "all covering" }));
    add_clothing_type("haubergon", ({"breastplate", "backplate", "tabard", "vambrace", "small scabbard", "belt scabbard", "robe", "cape", "sash", "all covering"}), ({ "robe", "all covering"}));
    add_clothing_type("hauberk", ({"tabard", "vambrace", "greave", "breastplate", "backplate", "small scabbard", "belt scabbard", "robe", "cape", "sash", "all covering"}), ({ "robe", "all covering" }));
    add_clothing_type("chausse", ({"boot", "overshoe", "all covering"}), ({ "boot", "overshoe", "all covering"}));

    // Plate armour.
    add_clothing_type("breastplate", ({"small scabbard", "belt scabbard", "robe", "tabard", "cape", "sash", "all covering" }), ({"robe", "all covering" }));
    add_clothing_type("backplate", ({ "cape", "sash", "robe", "tabard", "all covering"}), ({ "cape", "sash", "robe", "all covering"}));
    add_clothing_type("vambrace", ({ "gauntlet", "all covering" }), ({ "robe", "all covering" }));
    add_clothing_type("greave", ({ "all covering" }), ({ "robe", "all covering" }));

    add_clothing_type("all covering", ({ }), ({ }) );

    // The clothing zones.
    add_clothing_zone("head", ({"hood", "helmet", "coif", "hat", "wig", "headband", "moustache", "glasses", "mask"}) );
    add_clothing_zone("neck", ({"hood", "coif", "cape", "scarf", "collar", "necklace"}) );
    add_clothing_zone("chest", ({"sash", "robe", "breastplate", "haubergon", "hauberk", "byrnie", "tabard", "jacket","jumper", "shirt", "undershirt", "bra", "shield", "large shield"}) );
    add_clothing_zone("back", ({"scabbard", "cape", "sash", "robe", "breastplate", "hauberk", "haubergon", "byrnie", "jacket", "jumper", "shirt", "undershirt"}) );
    add_clothing_zone("abdomen", ({"large shield", "robe", "belt scabbard", "breastplate", "byrnie", "hauberk", "belt", "skirt", "box", "trousers", "underwear"}) );
    add_clothing_zone("arms", ({"small shield", "shield", "large shield", "robe", "vambrace", "hauberk", "haubergon", "jacket", "armband", "jumper", "shirt"}) );
    add_clothing_zone("hands", ({"glove", "gauntlet", "small shield", "shield", "large shield", "ring"}) );
    add_clothing_zone("legs", ({"robe", "small scabbard", "greave", "hauberk", "skirt", "trousers"}) );
    add_clothing_zone("feet", ({"overshoe", "boot", "sandal", "chausse", "sock"}) );

    // The equivilant types.
    add_equivilant_type("shoe", "boot");
    add_equivilant_type("clog", "sandal");
    add_equivilant_type("turban", "helmet");
    add_equivilant_type("gorget", "collar");
    add_equivilant_type("sabaton", "boot");
    add_equivilant_type("stocking", "sock");
    add_equivilant_type("cloak", "robe");

} /* create() */

/**
 * This method returns whether or not a player can wear or remove a given item.
 * @param thing the item to be worn or removed.
 * @param player the person doing the wearing or removing.
 * @param flag if the flag is 1, the objects that won't allow
 * to remove the item are returned instead of a string.
 * @return the reason why the item can't be removed, if there is one,
 * or the objects that aren't allowing to remove the item,
 * if the flag is true
 */
varargs mixed can_wear_or_remove( object thing, object player, int flag ) {
    string *stuff, type, tmp;
    object *blocking, *wearing, ob;
    mixed junk, main_types;

    if( stringp( main_types = thing->query_type() ) )
        main_types = ({ main_types });

    if( !sizeof( wearing = player->query_wearing() ) )
        return 0;

    foreach( type in main_types ) {
        if( !stuff = query_clothing_cannot_remove( type ) )
            return 0;
        blocking = ({ });
        foreach( ob in wearing ) {
            junk = ob->query_type();
            if( stringp(junk) )
                junk = ({ junk });
            foreach( tmp in junk ) {
                if( member_array( tmp, stuff ) != -1 &&
                    member_array( ob, blocking ) == -1 )
                    blocking += ({ ob });
            }
        }
    }

    if( sizeof(blocking) ) {
        if( flag )
            return blocking;
        return "when you are wearing "+query_multiple_short(blocking);
    }

    return 0;

} /* can_wear_or_remove() */

/**
 * This method adds a new clothing type into the existing clothing
 * type mapping.
 * @param name the name of the clothing type
 * @param not_remove the types which if worn you cannot remove this item
 * @param hiding the types which hides this clothing
 */
protected void add_clothing_type( string name, string *not_remove,
                                  string *hiding ) {
    _types[name] = new( class clothing_type, _hiding : hiding,
                  _not_remove : not_remove );
} /* add_clothing_type() */

/**
 * This method returns the information associated with the clothing
 * of a particular type.
 * <p>
 * This will returns a class containing the clothing type information
 * in it.
 * @param type the type to lookup
 * @return the clothing type array, 0 if not found
 * @see query_clothing_cannot_remove()
 * @see query_clothing_cannot_remove()
 */
class clothing_type query_clothing_type( string type ) {
    if( _equivilants[type] )
        type = _equivilants[type];
    return _types[type];
} /* query_clothing_type() */

/**
 * This method returns the items you would be unable to remove the
 * type with.
 * @param type the type of clothing to check
 * @return array of types you would be unable to remove, 0 if invalid type
 * @see query_clothing_hiding()
 * @see query_clothing_depth()
 */
string *query_clothing_cannot_remove( string type ) {
    class clothing_type bing;

    if( _equivilants[type] )
        type = _equivilants[type];

    if( bing = _types[type] )
        return bing->_not_remove;

    return 0;

} /* query_clothing_not_remove() */

/**
 * This method returns the types which hide this type of thingy.
 * @param type the type of clothing to check
 * @return array of types which would hide this type, 0 if invalid type
 * @see query_clothing_cannot_remove()
 * @see query_clothing_depth()
 */
string *query_clothing_hiding( string type ) {
    class clothing_type bing;

    if( _equivilants[type] )
        type = _equivilants[type];

    if( bing = _types[type] )
        return bing->_hiding;

    return 0;

} /* query_clothing_hiding() */

/**
 * This method returns the depth of the clothing type.  The parament
 * can also be an array, in which case it will return the minimum
 * non-zero depth.
 * @param type the type of clothing to check
 * @return the depth rating of the type
 * @see query_clothing_cannot_remove()
 * @see query_clothing_hiding()
 */
int query_clothing_depth( mixed type ) {
    class clothing_type bing;
    int depth, min_depth;
    string str;

    if( _equivilants[type] )
        type = _equivilants[type];

    if( stringp(type) ) {
        if( bing = _types[type] )
            return bing->_depth;
    } else if( pointerp(type) ) {
        min_depth = 100000;
        foreach( str in type ) {
            depth = query_clothing_depth(str);
            if( depth < min_depth && depth > 0 )
                min_depth = depth;
        }
        return min_depth;
    }

    return 0;

} /* query_clothing_depth() */

/**
 * This method returns the depth of the clothing type.  The parament
 * can also be an array, in which case it will return the maximum
 * non-zero depth.
 * @param type the type of clothing to check
 * @return the depth rating of the type
 * @see query_clothing_cannot_remove()
 * @see query_clothing_hiding()
 */
int query_clothing_maximum_depth( mixed type ) {
    class clothing_type bing;
    int depth, max_depth;
    string str;

    if( _equivilants[type] )
        type = _equivilants[type];

    if( stringp(type) ) {
        if( bing = _types[type] )
            return bing->_depth;
    } else if( pointerp(type) ) {
        max_depth = 0;
        foreach( str in type ) {
            depth = query_clothing_depth(str);
            if( depth > max_depth )
                max_depth = depth;
        }
        return max_depth;
    }

    return 0;

} /* query_clothing_depth() */

/**
 * This method returns a mapping of the current clothing types.
 * <p>
 * The make up of this array is:<br>
 * <dl>
 * <dh>first element
 * <dd> is the items which if you're wearing this
 * one cannot be removed.
 * <dh>second element
 * <dd>is the items which hide the given item.
 * </dl>
 * i.e. The wig type cannot be removed if types hood, helmet
 * or hat are also worn, also the wig type is not visible
 * if the types hood, helmet or hat are worn.
 * @return the mapping of clothing types
 * @see add_clothing_type()
 */
mapping query_all_clothing_types() {
    return _types;
} /* query_clothing_types() */

/**
 * This method will go through all the current types and make sure the
 * hidden and the cannot remove types are valid.  It will also figure
 * out depth numbers for all the types.
 */
private void check_clothing_types() {
    class clothing_type bits;
    string *stuff, bing, type, ty;
    int rank;

    foreach( ty, bits in _types ) {
        foreach( bing in bits->_not_remove ) {
            if( !query_clothing_type(bing) )
                write("Unknown clothing type "+bing+" in the not remove "
                      "for "+ty+".\n");
        }
        foreach( bing in bits->_hiding ) {
            if( !query_clothing_type(bing) )
                write("Unknown clothing type "+bing+" in the hiding "
                      "for "+ty+".\n");
        }
    }

    // Go through each zone and assign levels to them.
    rank = 1;
    foreach( bing in _zone_level ) {
        stuff = query_clothing_zone(bing);
        // Set the top levels.
        foreach( type in stuff ) {
            bits = _types[type];
            if( !bits->_depth && !sizeof( bits->_not_remove ) ) {
                bits->_depth = rank;
                rank = fixup_types( type, stuff );
            }
        }
        foreach( type in stuff ) {
            bits = _types[type];
            if( !bits->_depth )
                bits->_depth = rank++;
        }
    }

} /* check_clothing_types() */

private int fixup_types( string type, string *types ) {
    string bing;
    class clothing_type base;
    class clothing_type bits;
    int depth;

    base = _types[type];
    depth = base->_depth + 1;

    foreach( bing in types ) {
        bits = _types[bing];
        // Gravitate it upwards.
        if( !bits->_depth && member_array( type, bits->_not_remove ) != -1 ) {
            bits->_depth = depth;
            depth = fixup_types( bing, types );
        }
    }

    return depth;

} /* fixup_types() */

/**
 * This method adds a clothing zone.
 * @param zone the zone name
 * @param types the types to add to the zone
 */
protected void add_clothing_zone( string zone, string *types ) {
    string ty;

    // Check to make sure each type exists.
    foreach( ty in types ) {
        if( !query_clothing_type(ty) )
            write("Incorrect clothing type "+ty+" in zone "+zone+".\n");
    }

    _zones[zone] = types;
    _zone_level += ({ zone });

} /* add_clothing_zone() */

/**
 * This method sets the zones that a particular clothing type covers
 * @param type the clothing type
 * @zones the zones covered.
 */
protected void add_zone_coverage( string type, string *zones ) {
    string zone;

    if( !query_clothing_type(type) )
        write("Incorrect clothing type "+type+".\n");

    foreach( zone in zones )
        if( member_array( type, zones ) != -1 )
            _zones[zone] += ({ type });

} /* add_zone_coverage() */

/**
 * This method returns the clothing zones.  The mapping consists of
 * arrays of types which are in the particular zones.
 * @return the clothing zones
 */
mapping query_all_clothing_zones() { return _zones; }

/**
 * This method returns the array of clothing types in the particular
 * zone.
 * @param zone the zone to get the types for
 * @return the clothing in the current zone
 */
string *query_clothing_zone( string zone ) { return _zones[zone]; }

/**
 * This method finds the zone for the specific type.
 * @param type the type to find in the zones
 * @return the zone name, 0 if not found
 */
string query_zone_name( string type ) {
    string zone, *stuff;

    if( _equivilants[type] )
        type = _equivilants[type];

    foreach( zone, stuff in _zones )
        if( member_array( type, stuff ) != -1 )
            return zone;

    return 0;

} /* query_zone_name() */

/**
 * This method finds all the zones for the specific type.
 * @param type the type to find in the zones
 * @return the zone names, 0 if not found
 */
string *query_zone_names( string type ) {
    if( _equivilants[type] )
        type = _equivilants[type];

    return keys( filter( _zones, (: member_array( $3, $2 ) != -1 :), type ) );

} /* query_zone_names() */

/**
 * This method returns the level for the specified zone.
 * @param zone the zone to check
 * @return the level of the zone
 */
int query_zone_level( string zone ) {
    return member_array( zone, _zone_level ) * 100;
} /* query_zone_level() */

/**
 * This method adds an equivilant type.
 * @param name the name of the type
 * @param equiv what it is equivilant to
 */
protected void add_equivilant_type( string name, string equiv ) {
    if( !query_clothing_type(equiv) )
        error("Incorrect clothing type "+equiv+" in equivilant listing.\n");

    if( _equivilants[name] )
        error("Equivalent type "+name+" already added.\n");

    _equivilants[name] = equiv;

    foreach( class clothing_type type in values(_types) ) {
        if( member_array( equiv, type->_hiding ) != -1 )
            type->_hiding += ({ name });
        if( member_array( equiv, type->_not_remove ) != -1 )
            type->_not_remove += ({ name });
    }

} /*  add_equivilant_type() */

/**
 * This method returns all the equivilant types.
 * @return the equivilant types
 */
mapping query_all_equivilant_types() { return _equivilants; }

/**
 * This method returns the equivilant type for the given type.
 * @param type the type to get the equivilant fo
 * @return the equivilant type
 */
string query_equivilant_type( string type ) { return _equivilants[type]; }

/**
 * This method tells us if the type is valid.  It checks both normal
 * types and equivilant types.
 * @param type the type to check
 * @return 1 if it is valid, 0 if not
 * @query_equivilant_type()
 * @query_clothing_type()
 */
int query_valid_type(string type) {
    return !undefinedp( query_clothing_type(type) );
} /* query_valid_type() */

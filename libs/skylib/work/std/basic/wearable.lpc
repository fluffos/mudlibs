/**
 * This file contains all the methods needed to make an object wearable
 * by a player or an npc.
 * @author Pinkfish
 * @see /obj/armour.c
 * @see /obj/clothing.c
 */

inherit "/std/basic/condition";

#include <clothing.h>

string *immune_to, *wear_effects;
mixed type, *wear_remove_func;
nosave object worn_by;

void create() {
   condition::create();
   set_damage_chance(25);
   immune_to = ({"cold", "sound", "gas", "mental"});
   wear_effects = ({ });
} /* create() */

/**
 * This method tells us if the object is wearable.
 * In the case of a wearable object it will always return 1.
 * @return always returns 1
 */
int query_wearable() { return 1; }

/** @ignore yes */
string long( string word, int dark ) {
    if( !dark )
        return cond_string();
    return "";
} /* long() */

/**
 * This method returns the current function associated with
 * wearing and removing the item.
 * @return the current function for wearing and removing the clothing
 * @see set_wear_remove_func()
 */
mixed *query_wear_remove_func() { return wear_remove_func || ({ }); }

/**
 * This method sets the current function associated with wearing and
 * removing the item.  The value of this function should be choosen
 * carefully, using an object reference for the name will work but
 * it will not then be able to restored from the save file.  The same
 * goes for using function pointers.  It is better to use a real
 * file name and a string function name.
 * <p>
 * The function will be called with two arguments:
 * If the second argument is 0, then the item is being worn,
 * and the first argument will be the person about to wear the item.
 * If the second argument is 1, then the item is being removed,
 * and the first argument will be the person about to remove the item.
 * <p>
 * NOTE: Do NOT use this_player() in this function, because it is not
 * correct sometimes.
 * @example
 * inherit "/std/basic/wearable";
 *
 * void setup() {
 *    ...
 *    set_wear_remove_func( base_name(TO), "do_fluff");
 *    ...
 * } /\* setup() *\/
 *
 * void do_fluff( object ob, int removed ) {
 *     if( removed ) {
 *         tell_object( ob, the_short()+" is being removed.\n");
 *     } else {
 *         tell_object( ob, the_short()+" is being worn.\n");
 *     }
 * } /\* do_fluff() *\/
 * @param file the file to call the function on
 * @param func the function to call
 * @see query_wear_remove_func()
 */
void set_wear_remove_func( mixed file, string func ) {
    wear_remove_func = ({ file, func });
} /* set_wear_remove_func() */

/**
 * This method returns the list of effects to be added to the wearer when
 * it is worn.  These effects will automaticly be added when worn and
 * removed when taken off.
 * @return the list of effects to be added to the wearer when worn
 * @see set_wear_effects()
 * @see add_wear_effect()
 */
string *query_wear_effects() { return wear_effects; }

/**
 * This method sets the list of effects to be added to the wearer when it
 * is worn.  These effects will automaticly be added when worn and
 * removed when taken off.
 * @param effects the array of effects to be added to the wearer when worn
 * @see query_wear_effects()
 * @see add_wear_effect()
 */
void set_wear_effects( string *effects ) { wear_effects = effects; }

/**
 * This method adds a new wear effect to the current wear effect array.
 * These effects will automaticly be added when worn and removed when
 * taken off.
 * They will only be removed if the effect has the
 * person_removing_item() function in it.
 * @param effect the effect to add
 * @see query_wear_effects()
 * @see set_wear_effects()
 * @see person_removing_item()
 */
void add_wear_effect( string effect ) {
    if( member_array( effect, wear_effects ) == -1 )
        wear_effects += ({ effect });
} /* add_wear_effect() */

/** @ignore yes */
void do_damage( string type, int amount ) {
    if( member_array( type, immune_to ) == -1 )
        condition::do_damage( type, amount );
} /* do_damage() */

/**
 * This method returns the person who is currently wearing the object.
 * @return the current wearer of the object
 * @see set_worn_by()
 */
object query_worn_by() { return worn_by; }

/**
 * This method sets the object as being worn by the passed in object.
 * It calls all the various worn functions and sets up or removes
 * all the effects associated with the object.
 * <p>
 * If the object is alreadying being worn the wear_remove_function will
 * be called with an argument of 0.  The method taken_off will be
 * called on the object wearing the object for all the effects associated
 * with this object.
 * <p>
 * If the object is being set to be worn by someone the the wear_remove
 * function will be called with an argument being the person who is to
 * wear the object.   All of the effects associated with the
 * object will be added to the wearer.
 * <p>
 * This calls the method 'person_removing_item' on the effect when some
 * one removes the item.  This can be used to make sure the effects are
 * taken off when the item is removed.
 * @param thing the new person to wear the object (0 for worn by no one)
 * @return 1 if successful, 0 on failure
 * @see set_wear_remove_func()
 * @see add_wear_effect()
 */
int set_worn_by( object thing ) {
    string wear_eff;

    /* Do nothing if we are already worn by them. */
    if( thing == worn_by )
        return 1;

    /* First remove any possible concealment off us */
    TO->remove_hide_invis("concealed");

    /* If there is a move function, then call it. */
    if( wear_remove_func ) {
        if( worn_by )
            call_other( wear_remove_func[0], wear_remove_func[1],
                worn_by, 1 );
        if( thing )
            call_other( wear_remove_func[0], wear_remove_func[1],
                thing, 0 );
    }

    /* If there are some wear effects, set them up or remove them. */
    if( sizeof( wear_effects ) ) {
        foreach( wear_eff in wear_effects ) {
          if( worn_by )
              worn_by->taken_off( TO, wear_eff );
          if( thing )
              thing->add_effect( wear_eff, TO );
          else
              wear_eff->person_removing_item( TO, worn_by );
       }
    }

    /*
     * Call the functions on the object doing the wearing to remove or add
     * the item.
     */
    if( worn_by )
        worn_by->now_removed( TO );

    if( thing )
        thing->now_worn( TO );

    worn_by = thing;

    return 1;

} /* set_worn_by() */

/**
 * This returns the list of types of damage that the object is immune to.
 * @return the list of damage we are immune to
 * @see /std/basic/condition.c
 * @see add_immune_to()
 * @see remove_immune_to()
 */
string *query_immune_to() { return immune_to; }

/**
 * This adds a new type of damage that the object is immune to.
 * The parameter can either be a string or an array of strings
 * being the types of damage to be immune to.
 * @param args the type of damage to be immune to
 * @example
 * inherit "/std/basic/wearable";
 *
 * void setup() {
 *    ...
 *    add_immune_to("sharp");
 *    ...
 * } /\* setup() *\/
 * @example
 * inherit "/std/basic/wearable";
 *
 * void setup() {
 *    ...
 *    add_immune_to("sharp");
 *    ...
 * } /\* setup() *\/
 * @see remove_immune_to()
 * @see query_immune_to()
 */
void add_immune_to( mixed args ) {
    string tmp;

    if( pointerp( args ) )
        foreach( tmp in args )
            add_immune_to( tmp );
    else if( stringp( args ) && member_array( args, immune_to ) == -1 )
        immune_to += ({ args });

} /* add_immune_to() */

/**
 * This method removes a type of damage that the weapon is immune
 * to.
 * @param args the type(s) of damage to remove immunity too
 * @see add_immune_to()
 * @see query_immune_to()
 */
void remove_immune_to( mixed args ) {
    string tmp;

    if( pointerp( args ) )
        foreach( tmp in args )
            remove_immune_to( tmp );
    else if( stringp( args ) )
        immune_to -= ({ args });

} /* remove_immune_to() */

/**
 * This method returns the current type(s) associated with the object.
 * If this method returns a string then there is only one type for this
 * object.  If it returns a string then there is more than one
 * type associated with an object.  An example of something with more
 * than one type is a skirt, which is a dress and a shirt at the
 * same time.
 * @return the current type of the item
 * @see set_type()
 */
mixed query_type() { return type; }

/** @ignore yes */
private void log_bad_type( mixed bad_type ) {
    string str;

    if( !clonep(TO) )
        return;

    str = sprintf("BAD_TYPE %s (%s) = %O\n", file_name(),
        TO->short(), bad_type );

    log_file("BAD_TYPE", "%s", str );

     /*
      * This is *not* a spam.  If you are creating a piece of
      * clothing/armour I want it to tell you immediately that you have
      * a bad type instead of it ending up in the game and then being
      * logged a lot.
      */
    if( TP && creatorp(TP) )
        write(str);

} /* log_bad_type() */

/**
 * This method sets the type(s) which are associated with the
 * item.  If the parameter is a string then a single type is associated
 * with the item, if the parameter is an array then a list of types
 * is associated with the object.  If any of these types are not
 * legal and error message will be produced.
 * @param word the new type(s) to set for the object
 * @see query_type()
 */
void set_type( mixed word ) {
    if( !stringp( word ) && !pointerp( word ) )
        return log_bad_type( word );

    type = word;

    if( stringp( word ) ) {
        if( !CLOTHING_HANDLER->query_valid_type(word) )
            log_bad_type( word );
        return;
    }

    foreach( word in word ) {
        if( !CLOTHING_HANDLER->query_valid_type(word) )
            log_bad_type( word );
        return;
    }

} /* set_type() */

/** @ignore yes */
int modify_value( int amount ) {
    return ( amount * ( 10 + ( 90 * query_cond() ) /
             query_max_cond() ) ) / 100;
} /* modify_value() */

/** @ignore yes */
void player_wear() {
    if( ENV(TO) )
        ENV(TO)->wear_armour(TO);
} /* player_wear() */

/** @ignore yes */
void break_me() {
    object env;

    env = ENV(TO);

    if( living(env) ) {
        if( ENV(env) ) {
            tell_room( ENV(env), env->poss_short()+" "+
                TO->short()+" $V$0=breaks,break$V$!\n");
        } else {
            tell_object( env, env->poss_short()+" "+
                TO->short()+" $V$0=breaks,break$V$!\n");
        }
    } else {
        tell_room( env, TO->the_short()+" $V$0=breaks,break$V$!\n");
    }

    if( worn_by )
        worn_by->remove_armour( TO );

    condition::break_me();

} /* break_me() */

/** @ignore yes */
mixed stats() {
    string *stuff, tmp;

    stuff = condition::stats() +
        ({ ({ "type", ( pointerp(type) ? implode( type, ", ") : type ) }), });

    foreach( tmp in wear_effects )
        stuff += ({ ({"wear effect", tmp }) });

    foreach( tmp in immune_to )
        stuff += ({ ({"immune to", tmp }) });

    return stuff;

} /* stats() */

/** @ignore yes */
mapping query_static_auto_load() {
    mapping map;

    map = ([
        "condition" : condition::query_static_auto_load(),
        "type" : type,
        ]);

    if( sizeof(wear_remove_func) )
        map["wear remove func"] = wear_remove_func;

    return map;

} /* query_static_auto_load() */

/** @ignore yes */
mapping query_dynamic_auto_load() {
    mapping map;

    map = ([
        "condition" : condition::query_dynamic_auto_load(),
        "immune" : immune_to,
        ]);

    if( worn_by )
        map["worn"] = 1;

    if( sizeof(wear_effects) )
        map["wear effects"] = wear_effects;

    return map;

} /* query_dynamic_auto_load() */

/** @ignore yes */
void init_static_arg( mapping map ) {
    if( map["type"] )
        type = map["type"];

    if( pointerp( map["wear remove func"] ) &&
        sizeof( map["wear remove func"] ) )
        wear_remove_func = map["wear remove func"];

    if( !undefinedp( map[ "condition" ] ) )
        condition::init_static_arg( map["condition"] );

} /* init_static_arg() */

/** @ignore yes */
void init_dynamic_arg( mapping map ) {
    if( pointerp( map["wear effects"] ) )
        wear_effects = map["wear effects"];

    if( map["immune"] )
        immune_to = map["immune"];

    if( map["worn"] )
        call_out("player_wear", 0 );

    if( !undefinedp( map["condition"] ) )
        condition::init_dynamic_arg( map["condition"] );

} /* init_dynamic_arg() */

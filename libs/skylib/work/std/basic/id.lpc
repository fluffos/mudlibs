/**
 * This class keepos track of all the aliases, names and adjectives
 * which are used to match the object.
 * @see /global/player->add_command()
 * @see /std/basic/desc.c
 */
#include <parse_command.h>

inherit "/std/basic/id_match";

private nosave string _name;
private nosave string *_alias;
private nosave string *_adjectives;
private nosave string *_plurals;

/* name handleing stuff */
/**
 * This method sets the name of the object.   The name is the basic handle
 * used to reference the object.   It should not have any spaces
 * in it.
 * @example
 * set_name("rabbit");
 * @param str the name
 * @see query_name()
 * @see add_alias()
 * @see add_adjective()
 */
void set_name(string str) { _name = str; }
/**
 * This method returns the name of the object.
 * @return the name of the object
 * @see set_name()
 * @see add_alias()
 * @see add_adjective()
 */
string query_name() { return _name; }

/**
 * This method returns the capitalized name.   It calls the function
 * capitalize() on the name
 * @see query_name()
 * @see set_name()
 * @see efun::capitalize()
 */
string query_cap_name() {
    return ( !_name ? "Someone" : CAP(_name) );
} /* query_cap_name() */

void create() {
   _alias = ({ });
   _plurals = ({ });
   _adjectives = ({ });
   _name = "object";
} /* create() */

/* alias stuff */
/**
 * This method sets the entire alias array.   It overrides any current alias
 * definitions and sets the alias arry.   This should be used carefully
 * if at all.   Use add_alias instead.
 * @param str the new alias array
 */
void set_aliases(string *str) {
   _alias = str;
} /* set_aliases() */

/**
 * This method adds an alias to the object.   An alias for the object is the
 * part used as the main noun for the object. ie in the case of a "green
 * bath tub", "bathtub" might be an alias for the object. and "green"
 * and "bath" would be adjectives. The value set with add_alias is also
 * used with present. This means you can make up an alias for an object
 * that players cannot normaly access but you can
 * get a handle on with present. For an exmple of this look at the money
 * object.
 * <p>
 * The function takes an array or a string as an argument.   If an array
 * is passed in each element of the array is added to the alias
 * array, if it is a string then the string elemnt is added to the
 * array.
 * @param str the alias(s) to add
 * @see set_name()
 * @see remove_alias()
 * @see set_aliases()
 * @see query_alias()
 * @example
 * set_name("tub");
 * set_short("green bath tub");
 * add_alias("bathtub");
 * add_adjective("green");
 * add_adjective("bath");
 */
void add_alias( mixed str ) {
   string tmp;

   if( pointerp( str ) ) {
       foreach( tmp in str )
         add_alias( tmp );
   } else if( member_array( str, _alias ) == -1 )
       _alias += ({ str });
} /* add_alias() */

/**
 * This method removes an alias from the object.
 * @see add_alias()
 * @see query_alias()
 * @param str the alias to remove
 * @return 1 if the alias is found, 0 if not
 */
int remove_alias(string str) {
   int i;

   if( ( i = member_array(str, _alias) ) == -1 )
       return 0;
   _alias = delete( _alias, i, 1 );
   return 1;
} /* remove_alias() */

/**
 * This method returns the current list of aliases.
 * @see add_alias()
 * @see remove_alias()
 * @return the array of aliases (array of strings)
 */
string *query_alias() { return _alias; }

/**
 * This method is used by the present efun.   It determines if the
 * passed in string is an alias or the name of the object.
 * @param str the value to check
 * @return 1 if the name matches
 */
int id( string str ) {
   if( !pointerp(_alias) )
       _alias = ({ });
   return ( str == _name ) || ( member_array( str, _alias ) != -1 );
} /* id() */

/**
 * This method sets the compete array of plurals.   This shod
 * not be used, use add_plural and remove_plural instead.
 * @see add_plural()
 * @see remove_plural()
 * @see query_plurals()
 */
void set_plurals(string *str) {
   _plurals = str;
} /* set_plurals() */

/**
 * This method adds a plural onto the object.   The plurals will be
 * used in plural name matching by thje find_match simul_efun
 * @see /secure/simul_efun->find_match()
 * @see set_plurals()
 * @see remove_plural()
 * @see query_plurals()
 * @see add_plurals()
 */
void add_plural( mixed str ) {
    string tmp;

    if( pointerp( str ) ) {
        foreach( tmp in str )
          add_plural( tmp );
    } else if( member_array( str, _plurals ) == -1 )
        _plurals += ({ str });

} /* add_plural() */

/**
 * This method removes a plural from the object.
 * @param str the plural to remove
 * @see add_plural()
 * @see query_plurals()
 * @see set_plurals()
 */
void remove_plural(string str) {
   int i;

   if( ( i = member_array( str, _plurals ) ) != -1 )
       _plurals = delete( _plurals, i, 1 );
} /* remove_plurals() */

/**
 * This method adds multiple plurals to the object.
 * @param str the array of plurals to add
 * @see add_plural()
 * @see remove_plural()
 * @see query_plurals()
 */
void add_plurals( string *str ) {
    string tmp;

    foreach( tmp in str )
      add_plural( tmp );
} /* add_plurals() */

/**
 * This method returns the complete list of plurals for the
 * object.
 * @return the complete array of plurals
 */
string *query_plurals() { return _plurals; }

/**
 * This method is similar to the id function, except this will check the
 * plural names instead of the aliases and the name.
 * @param str the name to check
 * @return 1 if the name matches one of the plurals, 0 otherwise
 * @see id()
 * @see id_adjective()
 */
int id_plural(string str) {
   return ( member_array( str, _plurals ) != -1 );
} /* id_plural() */

/**
 * This method sets all the adjectives for the object.   This method
 * should not be used, please use add_adjective instead.
 * @see add_adjective()
 * @see remove_adjective()
 * @see query_adjectives()
 * @param str the array of adjectives
 */
void set_adjectives(string *str) {
   _adjectives = str;
} /* set_adjectives() */

/**
 * This method adds an adjective to the object.   The adjectives are used for the
 * object matching routines.    Fort example, if you have a "green
 * bath tun" then "green" and "bath" are adjectives.
 * @see add_alias()
 * @see remove_adjective()
 * @see query_adjectives()
 * @see set_adjectives()
 */
void add_adjective( mixed str ) {
   string tmp;

   if( pointerp(str) ) {
       foreach( tmp in str )
         add_adjective( tmp );
       return;
   }

   if( stringp(str) )
       str = explode( str, " " );

   foreach( tmp in str )
     if( member_array( tmp, _adjectives ) == -1 )
         _adjectives += ({ tmp });

} /* add_adjective() */

/**
 * This method will remove an adjective from the object.
 * @see add_alias()
 * @see add_adjective()
 * @see query_adjectives()
 * @param str the adective(s) to remove
 */
void remove_adjective(mixed str) {
   string tmp;
   int i;

   if( pointerp(str) ) {
       foreach( tmp in str )
         remove_adjective( tmp );
   } else if( ( i = member_array( str, _adjectives ) ) != -1 ) {
         _adjectives = delete( _adjectives, i, 1 );
   }
} /* remove_adjective() */

/**
 * This method returns the current list of adjectives associated with
 * this object.
 * @return the complete list of adjectives
 */
string *query_adjectives() { return _adjectives; }

/**
 * This method is similar to the id function, except this will check the
 * adjectives instead of the aliases and the name.
 * @param word the word to check
 * @return 1 if the word matches one of the adjectives, 0 otherwise
 * @see id()
 * @see id_plural()
 */
int id_adjective( string word ) {
   return ( member_array( word, _adjectives ) != -1 );
} /* id_adjective() */

/** @ignore yes */
string *parse_command_id_list() {
    return ({ _name, file_name(TO) }) + query_alias();
} /* parse_command_id_list() */

/** @ignore yes */
string *parse_command_plural_id_list() { return query_plurals(); }
/** @ignore yes */
string *parse_command_adjectiv_id_list() { return query_adjectives(); }

/** @ignore yes */
object query_parse_id( mixed *arr ) {
   if( arr[P_THING] == 0 )
       return TO;
   if( arr[P_THING] < 0 ) { /* specific object case */
       arr[P_THING]++;
       if( arr[P_THING] != 0 )
           return 0;
       arr[P_THING] = -10321;
       return TO;
   }
   arr[P_THING]--; /* lots of objects case */
   if( arr[P_THING] != 0 )
       return TO;
   arr[P_THING] = -10101;
   return TO;
} /* query_parse_id() */

/** @ignore yes */
object query_frac_parse_id( mixed *arr ) {
   if( arr[P_THING] < 0 ) {
       arr[P_THING]++;
       if( arr[P_THING] != 0 )
           return 0;
       arr[P_THING] = -10235;
       return 0; /* it refered to me and I am pretty depressed about it.
                  * I want to break free! */
   }
   if( arr[P_THING] == 0 ) {
       if( ( arr[P_MAX_NUM]*arr[P_TOP])/arr[P_BOT] > arr[P_CUR_NUM]++ )
           return TO;
       else
           return 0;
   }
   if( ( arr[P_THING]*arr[P_TOP])/arr[P_BOT] > arr[P_CUR_NUM]++ )
       return TO;
   return 0;
} /* query_frac_parse_id() */

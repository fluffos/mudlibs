/**
 * This is the object matching code.
 * It is based on some code by Scatter at Dawn Whispers, although this is
 * both cut down and extended from what scatter had written.
 * @changes 2000-04-20   Scatter    File created.
 * @changes 2000-05-20   Pinkfish   Adapted to Discworld
 */

/**** This documentation should go into a man page? ****

Object matching
---------------

Singular objects are matched if the text is a combination of an optional
ordinal, zero or more adjectives and a noun (e.g. 1st red womble.)

Plural objects are matched if the text is a combination of an optional
counter, zero or more adjectives and a plural noun (4 red wombles.) Plural
object tokens can also match combinations of singular and plural object
matches seperated by " & " or ", " or " and " strings. For example,
red womble, 3 purple wombles and the second green cabbage.

Possesives (his/her/its) are handled as if they were adjectives, since
their use matches adjectives. Objectives (him/her/it) are handled as
if they were nouns. A parsing context is used to maintain information
about which object these should apply to.

Matching specific objects to a text string is carried out using the
parse_match() apply with the objects, rather than within this parser -
the above behaviour is the intended one. It is down to the parse_match()
apply to carry out the above requirements (see below for apply details.)

*/

#include <obj_parser.h>

#ifdef DEBUG
#define TRACE(ARG) tell_creator("shaydz", ARG + "\n")
#else
#define TRACE(ARG)
#endif

private nosave mapping _ordinals;
private nosave mapping _counters;
private nosave mapping _fractions;

// These are defines from elesewhere in the simul_efun inherit tree.
// don't remove the living() stuff, it's needed on the clone!
void tell_creator(string player, string text, mixed arg ...);
#if !efun_defined(living)
int living (object);
#endif

class obj_match match_objects_in_environments( string input, mixed env_list,
                                      int singular, object player);

void create() {
   _ordinals = ([
      "any" : 1,
      "1st" : 1, "first" : 1,
      "2nd" : 2, "second" : 2,
      "3rd" : 3, "third" : 3,
      "4th" : 4, "fourth" : 4,
      "5th" : 5, "fifth" : 5,
      "6th" : 6, "sixth" : 6,
      "7th" : 7, "seventh" : 7,
      "8th" : 8, "eighth" : 8,
      "9th" : 9, "ninth" : 9,
      "10th" : 10, "tenth" : 10
   ]);

   _counters = ([
      "1" : 1, "one" : 1,
      "2" : 2, "two" : 2,
      "3" : 3, "three" : 3,
      "4" : 4, "four" : 4,
      "5" : 5, "five" : 5,
      "6" : 6, "six" : 6,
      "7" : 7, "seven" : 7,
      "8" : 8, "eight" : 8,
      "9" : 9, "nine" : 9,
      "10" : 10, "ten" : 10,
      "11" : 11, "eleven" : 11,
      "12" : 12, "twelve" : 12,
      "13" : 13, "thirteen" : 13,
      "14" : 14, "fourteen" : 14,
      "15" : 15, "fifteen" : 15,
      "16" : 16, "sixteen" : 16,
      "17" : 17, "seventeen" : 17,
      "18" : 18, "eighteen" : 18,
      "19" : 19, "nineteen" : 19,
      "20" : 20, "twenty" : 20,
      "many" : 20,
      "every" : EVERY_NUM,
   ]);

   _fractions = ([
      "half" : ({ 1, 2 }),
      "quarter" : ({ 1, 4 }),
      "some" : ({ 1, 50 })
   ]);

} /* create() */

#if !efun_defined(query_multiple_short)
/**
 * Returns a nice string which looks like "Frog, fish and chicken".  This
 * takes in an array of objects and or strings and returns a message
 * like that shown above.  It also does things like adding the number of
 * each type at the start of the function.
 * <p>
 This function has two main uses: to produce the control codes for a
     set of objects and to produce a nice list from a set of strings.
     The "type" argument is optional and may be "a", "the", "one" or
     "poss", defaulting to "a": it determines which of a_short,
     the_short, one_short or poss_short will be used to make the control
     code sequence for the objects in "args".  If all of the elements of
     "args" are objects, it simply returns the block control code for
     the relevant shorts of the objects.  Otherwise, it looks through
     the elements one at a time, replacing objects by the result of
     calling the relevant short function on them; finally it
     concatenates the elements with commas between each pair, except
     between the last pair which have " and " between them.  Since the
     output will contain processing codes if there are any objects in
     "args", it should be passed through convert_message before being
     stored.
 *
 * @param args the array to do the processing on
 * @param type the type of short to use "a", "the", "one", "poss"
 * @param no_dollars this forces the output to be a real string
 * @return the processed string
 */
varargs string query_multiple_short( mixed args, string type,
                                     int no_dollars, int flag ) {
    int i, j;
    string func;
    string ret;

    args = copy(args);

    if( !type )
        type = "a";

    func = type + "_short";
    i = j = sizeof(args);

    while( i-- ) {
        if( !objectp( args[ i ] ) )
            break;
    }

    if( i == -1 ) {
        for( i = 0; i < j; i++ )
            args[ i ] = call_other( args[ i ], func, flag );
        if( !no_dollars )
            return "$M$"+implode( args, "")+"$M$";
    } else {
        for( i = 0; i < j; i++ ) {
            if( objectp( args[ i ] ) )
                args[ i ] = call_other( args[ i ], func, flag );
        }
    }

    switch( j ) {
      case 0 :
        return "";
      case 1 :
        ret = args[ 0 ];
      break;
      default :
        ret = implode( args[0..<2], ", ")+" and "+args[<1];

    }

    if( no_dollars ) {
        if( TP )
            return TP->convert_message(ret);
        else
            return PLAYER_OBJ->convert_message(ret);
    }

    return ret;

} /* query_multiple_short() */
#endif

/**
 * This method checks to see if the specified object is in the player
 * or the environment.  If it has no environment it is considered to
 * be here.
 * @param ob the object to test
 * @param player the player to check against
 * @return 1 if it is, 0 if not
 */
int is_in_me_or_environment( object ob, object player ) {
    object env;

    env = ob;

    do {
        env = ENV(env);
    } while( env && !living(env) && !ENV(env) );

    if( !env || env == player || env == ENV(player) )
        return 1;

    return 0;

} /* is_in_me_or_environment() */

/**
 * This method returns the array of objects that are only inside the
 * player in question, or in their environment.  It excludes any items
 * in other peoples inventorys.
 * @param obs the objects to filer
 * @param player the player to check
 * @return the filtered objects
 */
object *filter_in_me_or_environment( object* obs, object player ) {
    return filter( obs, (: is_in_me_or_environment( $1, $2 ) :), player );
} /* filter_in_me_or_environment() */

private void fixup_context( object player, object* objects,
                            class obj_match_context context ) {

   if( !sizeof(objects) )
       return;

   if( objectp(player) ) {
       // Whoo!  Successful, setup the new context.
       if( sizeof(objects) > 1 )
           context->plural = objects;
       else if( living(objects[0]) ) {
           if( objects[0]->query_gender() == 1 )
               context->him = objects[0];
           else if( objects[0]->query_gender() == 2 )
               context->her = objects[0];
           else
               context->it = objects[0];
       } else
           context->it = objects[0];
       player->set_it_them( context );
   }
} /* fixup_context() */

/*
 * Match objects to words...
 */
/**
 * Find an object in the given array that matches the given words.
 * This will only return a correct match if the entire string
 * matches.  If it gets a partial match then nothing will be
 * returned.  The return array is of the format:<br>
 * <pre>({ flag, class obj_match info })
 * </pre>
 * The flag can be one of:
 * <dd>
 * <dt>OBJ_PARSER_SUCCESS
 * <dd>Successfuly matched the objects.  the objects part of the class will
 * contain the matched objects.
 * <dt>OBJ_PARSER_NO_MATCH
 * <dd>No successful match.  The text bit of the omatch class will contain
 * the text that didn't match
 * <dt>OBJ_PARSER_AMBIGUOUS
 * <dd>An ambigous match is returned, this means 'frog' was referenced
 * when there was more than one frog.  The objects part of the class
 * has all the objects there were matched
 * <dt>OBJ_PARSER_BAD_FRACTION
 * <dd>The specified fracition was bad, the text bit of the class contains
 * the bad fraction.
 * <dt>OBJ_PARSER_FRACTION
 * <dd>Means that a fraction was attempted to be applied to multiple
 * objects.
 * <dt>OBJ_PARSER_TOO_DARK
 * <dd>Unable to match the specified object because it is too dark.
 * </dl>
 * @param input the input string to match
 * @param ob_list the object to list to match in
 * @param singular force a singular match
 * @param player the person doing the lookup
 * @return an array of the format ({ flag, class obj_match info })
 */
class obj_match match_object_in_array( string input, object *ob_list,
                                       int singular, object player ) {
   object ob;
   object *singular_objects;
   object *plural_objects;
   object thing;
   string first_word;
   string rest;
   string *bits;
   string bit;
   string inside_match;
   string nick;
   int n;
   int ord;
   int count;
   int *fraction;
   mixed obj_info;
   class obj_match result;
   class obj_match omatch;
   class obj_match_context context;

   if( !player )
       player = TP;

   // This is used for determining things like 'it', 'them' and 'him'
   // etc. references.
   if( player )
       obj_info = player->query_it_them();

   if( !classp(obj_info) || sizeof(obj_info) != 9 ) {
       context = new( class obj_match_context );
       context->plural = ({ });
   } else {
       context = obj_info;
   }

   if( singular != OBJ_PARSER_SINGULAR ) {
       /* if we are working on a plural, then all the various ways of
        * combining things (e.g. "1st red womble and 4 elephants, 3 tins & pot" )
        * have to be standardised and then split and matched seperately.
        */

       //if( strsrch( input, " and " ) != -1 ) {
       //   input = replace_string( input, " and ", ", " );
       //}

       TRACE( "            Processed input: " + input );

       omatch = new( class obj_match );
       omatch->text = input;
       omatch->objects = ({ });

       if( strsrch( input, "&" ) != -1 ) {
           // This allows one, the other or both to match.
           TRACE( "            Splitting input" );
           foreach( bit in explode( input, "&" ) ) {
              result = match_object_in_array( bit, ob_list, singular, player );
              if( result->result == OBJ_PARSER_SUCCESS )
                  omatch->objects += result->objects;
           }
           if( !sizeof(omatch->objects) ) {
               omatch->text = input;
               omatch->result = OBJ_PARSER_NO_MATCH;
               return omatch;
           }
           fixup_context( player, omatch->objects, context );
           omatch->result = OBJ_PARSER_SUCCESS;
           return omatch;
       }

       if( strsrch( input, "," ) != -1 ) {
           TRACE( "            Splitting input" );
           foreach( bit in explode( input, "," ) ) {
              result = match_object_in_array( bit, ob_list, singular, player);
              if( result->result == OBJ_PARSER_SUCCESS )
                  omatch->objects += result->objects;
              else if( singular != OBJ_PARSER_EXISTENCE )
                  return result;
           }
           fixup_context( player, omatch->objects, context );
           omatch->result = OBJ_PARSER_SUCCESS;
           return omatch;
       }
   }

   // Do a nickname lookup.
   if( player ) {
       nick = player->expand_nickname(input);
       if( nick && nick!="" )
           input = nick;
   }

   // xx in yy syntax.
   n = strsrch( input, " in ", -1 );
   if( n == -1 )
       n = strsrch( input, " on ", -1 );
   if( n != -1 ) {
      inside_match = input[0..n];
      input = input[n + 4..];
   } else
      inside_match = 0;

   /* if we got to here, input is already split as necessary and
    * we are working on a fragment
    */
   n = strsrch( input, " " );
   ord = 0;

   if( n != -1 ) {
       first_word = input[ 0 .. n - 1 ];
       rest = input[ n + 1 .. ];

       // check for fractions.
       fraction = _fractions[ first_word ];
       if( !fraction ) {
           if( sscanf( first_word, "%d/%d", n, count ) == 2 ) {
               if( n > count || n < 0 || count <= 0 ) {
                   omatch = new( class obj_match );
                   omatch->text = input;
                   omatch->objects = ({ });
                   omatch->result = OBJ_PARSER_BAD_FRACTION;
                   return omatch;
               }
               fraction = ({ n, count });
           }
           count = 0;
       }
       if( fraction ) {
           input = rest;
           if( input[0..2] == "of ")
               input = input[3..];
       }
       n = strsrch(input, " ");
   }

   if( n != -1 ) {
       /* we have more than one word to match. The first word could be an ordinal
        * or a counter depending whether we are looking for a plural or a singular.
        * This must be converted to a number to use later, and the word stripped
        * from the text to match. Example counter: "four coins", example ordinal:
        * "2nd coin"
        */

       first_word = input[ 0 .. n - 1 ];
       rest = input[ n + 1 .. ];

       ord = _ordinals[ first_word ];
       if( ord > 0 )
           input = rest;

       if( !ord ) {
           count = _counters[ first_word ];
           if( !count )
               sscanf( first_word, "%d", count );
           if( count > 0 )
               input = rest;
           if( !count) {
               // Check for a number at the end...
               n = strsrch( input, " ", -1 );
               if( n != -1 && sscanf( input[n + 1..], "%d", ord ) == 1 )
                   input = input[0..n-1];
           }
       }
   }

   context->ordinal = ord;
   context->number_included = count;
   context->ignore_rest = 0;
   context->fraction = fraction;

   /* if we are looking for a plural, try to match the segment to a
    * plural id first (even if we are looking for a plural, the
    * particular segment may be singular, consider "blue flowers and 1st ball")
    */

   omatch = new( class obj_match );
   omatch->text = input;
   omatch->objects = ({ });
   singular_objects = ({ });
   plural_objects = ({ });

   /* check each object in the list, asking it how it matches the
    * text segment.
    * The parse_match method is assumed to handle noting the ordinal
    * and count stuff.
    */
   bits = explode(input, " ");
   if( sizeof(bits) > 1 )
       bits = bits[0..<2] - ({ "a", "an", "the" }) + ({ bits[<1] });
   foreach( ob in ob_list ) {
      obj_info = ob->parse_match_object( bits, player, context );
      if( obj_info ) {
          if( obj_info[OBJ_PARSER_MATCH_TYPE] & OBJ_PARSER_MATCH_PLURAL )
              plural_objects += obj_info[OBJ_PARSER_OBJECTS];
          if( obj_info[OBJ_PARSER_MATCH_TYPE] & OBJ_PARSER_MATCH_SINGULAR )
              singular_objects += obj_info[OBJ_PARSER_OBJECTS];
      }
      if( context->ignore_rest )
          break;
   }

   // If we are looking for a singular, or we matched multiple singulars
   // and we did not specify which one.
   if( sizeof(singular_objects) > 1 &&
       ( singular == OBJ_PARSER_SINGULAR || ( !ord && !count ) ) ) {
       if( player && !player->query_property(OBJ_PARSER_AMBIGUOUS_PROP) ) {
           omatch->objects = singular_objects;
           omatch->result = OBJ_PARSER_AMBIGUOUS;
           return omatch;
       }
       // Strip it back to just one object.
       singular_objects = singular_objects[0..0];
   }

   if( !sizeof( singular_objects ) && !sizeof( plural_objects) ) {
       /* nothing has matched the text. */
       TRACE( "            No matches" );
       omatch->result = OBJ_PARSER_NO_MATCH;
       return omatch;
   }

   if( ord || count == 1 || count == EVERY_NUM )
       omatch->objects = singular_objects;
   else if( count )
       omatch->objects = plural_objects;
   else
       omatch->objects = ( sizeof(singular_objects) ?
                           singular_objects : plural_objects );

   if( sizeof(omatch->objects) > 1 && fraction ) {
       omatch->result = OBJ_PARSER_FRACTION;
       return omatch;
   }

   // Check and see if we didn't match enough objects.
   if( context->number_included && count != EVERY_NUM ) {
       omatch->result = OBJ_PARSER_NOT_ENOUGH;
       return omatch;
   }

   // If we are doing inside matches...  Try it here...
   if( inside_match ) {
       foreach( thing in omatch->objects ) {
         if( !thing->can_find_match_recurse_into(player) )
             omatch->objects -= ({ thing });
       }
       if( sizeof(omatch->objects) ) {
           result = match_objects_in_environments( inside_match,
                                     omatch->objects, singular, player);
           omatch->objects = ({ });
           if( result->result == OBJ_PARSER_SUCCESS ) {
               foreach( thing in result->objects ) {
                 if( environment(thing) &&
                     environment(thing)->can_find_match_reference_inside_object(thing, player) )
                     omatch->objects += ({ thing });
               }
           } else {
               result->text += " in " + input;
               return result;
           }
       }
   }


   if( sizeof( omatch->objects ) == 0 ) {
       /* matches have been removed */
       TRACE( "            No matches (living/visible elimination)" );
       omatch->result = OBJ_PARSER_NO_MATCH;
       return omatch;
   }

   fixup_context( player, omatch->objects, context );
   omatch->result = OBJ_PARSER_SUCCESS;
   return omatch;
} /* match_object_in_array() */

/**
 * Find an object in the given environments that match the given words.
 * This will only return a correct match if the entire string
 * matches.  If it gets a partial match then nothing will be
 * returned.  The return array is of the format:<br>
 * <pre>({ flag, class obj_match info })
 * </pre>
 * The flag can be one of:
 * <dd>
 * <dt>OBJ_PARSER_SUCCESS
 * <dd>Successfuly matched the objects.  the objects part of the class will
 * contain the matched objects.
 * <dt>OBJ_PARSER_NO_MATCH
 * <dd>No successful match.  The text bit of the omatch class will contain
 * the text that didn't match
 * <dt>OBJ_PARSER_AMBIGUOUS
 * <dd>An ambigous match is returned, this means 'frog' was referenced
 * when there was more than one frog.  The objects part of the class
 * has all the objects there were matched
 * <dt>OBJ_PARSER_BAD_FRACTION
 * <dd>The specified fracition was bad, the text bit of the class contains
 * the bad fraction.
 * <dt>OBJ_PARSER_FRACTION
 * <dd>Means that a fraction was attempted to be applied to multiple
 * objects.
 * <dt>OBJ_PARSER_TOO_DARK
 * <dd>Unable to match the specified object because it is too dark.
 * </dl>
 * @param input the input string to match
 * @param env_list the environments to get the objects from
 * @param singular force a singular match
 * @param player the person doing the lookup
 * @return an array of the format ({ flag, class obj_match info })
 */
class obj_match match_objects_in_environments( string input, mixed env_list,
                                               int singular, object player) {
   object* tmp_expanded;
   object* stuff;
   object ob;
   class obj_match omatch;

   if( !player )
       player = this_player();

   if( !pointerp(env_list) ) {
       if( input == "all" && env_list->query_is_room() &&
           player->check_dark( env_list->query_light() ) ) {
           omatch = new( class obj_match );
           omatch->text = input;
           omatch->objects = ({ });
           omatch->result = OBJ_PARSER_TOO_DARK;
           return omatch;
       }

       tmp_expanded = env_list->find_inv_match( input, player );
   } else {
       tmp_expanded = ({ });
       foreach( ob in env_list ) {
         if( !ob )
             continue;
         if( input == "all" && ob->query_is_room() &&
             player->check_dark( ob->query_light() ) )
             continue;
         stuff = ob->find_inv_match(input,player);
         if( stuff && sizeof(stuff) )
             tmp_expanded += stuff;
       }
   }

   if( !sizeof(tmp_expanded) ) {
       omatch = new( class obj_match );
       omatch->text = input;
       omatch->objects = ({ });
       omatch->result = OBJ_PARSER_NO_MATCH;
       return omatch;
   }
   return match_object_in_array( input, tmp_expanded, singular, player );
} /* match_objects_in_environment() */

/**
 * This method checks for existance of the specified objects.  It will
 * return any ambiguous matches as well as real matches.  This should only
 * be used in cases in the code where it is not nessessary to distinguish
 * between different objects of the same type.
 * @param input the input string to check
 * @param env_list the environments to check in
 * @param player the player to check with
 * @return the array of objects
 */
object* match_objects_for_existence( string input, object* env_list,
                                     object player ) {
   class obj_match stuff;

   stuff = match_objects_in_environments( input, env_list,
                                          OBJ_PARSER_EXISTENCE, player );
   switch( stuff->result ) {
     case OBJ_PARSER_SUCCESS :
     case OBJ_PARSER_AMBIGUOUS :
       return stuff->objects;
     default :
       return ({ });
   }
} /* match_objects_for_existence() */

/**
 * This method returns the failed message for the specified
 * failed match string.
 * @param failed_match the return result from match_objects_*
 * @return the message to print when it gets an error
 */
string match_objects_failed_mess( class obj_match failed_match ) {
   switch( failed_match->result ) {
     case OBJ_PARSER_BAD_ENVIRONMENT :
       return "Cannot find \""+ failed_match->text +
              "\" here, access is not allowed.\n";
     case OBJ_PARSER_NOT_LIVING :
       return "The objects \""+ query_multiple_short(failed_match->objects) +
              "\" are not living.\n";
     case OBJ_PARSER_TOO_DARK :
       return "Cannot find \""+ failed_match->text + "\", it is too dark.\n";
     case OBJ_PARSER_NO_MATCH :
       return "Cannot find \""+ failed_match->text + "\", no match.\n";
     case OBJ_PARSER_BAD_FRACTION :
       return "The fraction \""+ failed_match->text + "\" is incorrectly "
              "specified.\n";
     case OBJ_PARSER_FRACTION :
       return "You can only reference a single object with a fraction, "
              "matched " + query_multiple_short(failed_match->objects) +
              ", please be more specific.\n";
     case OBJ_PARSER_AMBIGUOUS :
       return "There are more than one of \""+ failed_match->text + "\": " +
              query_multiple_short(failed_match->objects) + ", see "
              "'help parser' for information on how to be more specific.\n";
     case OBJ_PARSER_NOT_ENOUGH :
       return "There are not enough \"" + failed_match->text +
              "\" to match as specified.\n";
     default :
       return "Unknow parser error " + failed_match->result + ".\n";
   }
} /* setup_failed_mess() */

/**
 * This file contains the methods to make the npcs in game respond
 * to soul and says.  Allows for a level of NPC interation.
 * <p>
 * Code originaly by nimmox@igor.  Modified for discworld by Pinkfish.
 * <p>
 * @change Olorin Sep 97
 * event_soul does a convert_message on the mess first,
 * to avoid spurious matches caused by a message like eg.
 * "$the_short:/global/lord#64387$ $V$0=smiles,smile$V$ .... in soul
 * @change who knows when
 * changed to stop the responses when the npc is in /room/rubbish
 * @author Pinkfish
 * @see /std/npc.c
 */

#include <soul.h>
#include <language.h>

#define SPECIAL_DAY "/handlers/special_day"

mixed respond_to_with;
int stop_responding;
int use_regexp;

int match( string str, mixed str2 );
void event_soul( object per, string mess, object *avoid, string verb,
                 string last, mixed at );

void create() {
} /* create() */

/**
 * This method sets or clears the flag to use regular expressions instead of
 * the traditional arrays of words.  In addition, this flag inhibits
 * the usual stripping of non-alphanumerics from the input strings.
 * @param flag the new value of the flag: 1 says to use regular expressions,
 * 0 to not use them
 */
void set_response_mon_regexp( int flag ) { use_regexp = flag; }

/**
 * This method returns the current state of the flag that indicates whether
 * to use regular expressions instead of the traditional array of words.
 * @return 1 if using regular expressions, 0 if not
 */
int query_response_mon_regexp() { return use_regexp; }

/**
 * This method checks to see if the response monster code is in
 * debug mode.
 * @return 1 if in debug mode, 0 if not
 * @see set_response_mon_debug_mode()
 */
int query_response_mon_debug_mode() {
    return TO->query_property("respon mon debug");
} /* query_response_mon_debug_mode() */

/**
 * This method sets the current debug flag for the response monster
 * code.
 * @param flag the new value of the flag, 1 on, 0 off
 * @see query_response_mon_debug_mode()
 */
void set_response_mon_debug_mode( int flag ) {
   TO->add_property("respon mon debug", flag );
} /* set_response_mon_debug_mode() */

/**
 * This method allows the toggling of the responses of the npc.
 * If this is set to 1, then the npc will stop responding to
 * messages.
 * @param i 1 to make the npc not respond, 0 to make it respond again
 * @see query_stop_responding()
 */
void set_stop_responding( int i ) { stop_responding = i; }
/**
 * This method returns the flag determining the toggling of the
 * responses of the npc.
 * If this is set to 1, then the npc will stop responding to
 * messages.
 * @return 1 to the npc will not respond, 0 it is responding
 * @see query_stop_responding()
 */
int query_stop_responding() { return stop_responding; }

/**
 * This method sets whether or not we should respond to
 * non-interactives (ie. other NPCs).
 * @param i 1 if we should respond to other NPCs, 0 if not
 */
void set_respond_non_interactive( int i ) {
    if( i )
        TO->add_property("RNI", 1 );
    else
        TO->remove_property("RNI");
} /* set_respond_non_interactive() */

/**
 * This method returns whether or not we should respond to other NPCs.
 * @return 1 if we should respond to other NPCs, 0 if not
 */
int query_respond_non_interactive() { return TO->query_property("RNI"); }

/**
 * This method checks to see if the response is allowed for this object.
 * @param ob the object to check
 * @param response the response that is matched
 * @return 1 if the object is allowed, 0 if it is not
 */
int query_response_allowed( object ob, string *response ) {
    return 1;
} /* query_response_allowed() */

/**
 * This method sets the current responses for the npc.
 * This will overwrite the current responses in the npc.
 * Please use add_respond_to_with in your NPC's instead of
 * this function call, as it requires prior knowledge as to
 * the internal structure of the respond_to_with code that
 * add_respond_to_with handles nicely.
 * The array is of the formant:<pre>
 *   ({
 *      trigger1,
 *      response1,
 *      trigger2,
 *      response2,
 *      ...
 *    })
 * </pre>
 * @see add_respond_to_with()
 * @see query_respond_to_with()
 */
void set_respond_to_with( mixed map ) {
   mixed old_keys;
   int i;

   if( mapp( map ) ) {
       log_file("BAD_RESPONSE", "set_respond_to_with() called by %O (%s)\n",
                 PO, PO->query_name() );
       old_keys = keys(map);
       respond_to_with = allocate(sizeof(old_keys) * 2);
       for( i = sizeof(old_keys); i--; ) {
           respond_to_with[2*i] = old_keys[i];
           respond_to_with[2*i+1] = map[old_keys[i]];
       }
       return;
   }

   respond_to_with = map;

} /* set_respond_to_with() */

/**
 * This method returns the current responding to with array.
 * The array is of the formant:<pre>
 *   ({
 *      trigger1,
 *      response1,
 *      trigger2,
 *      response2,
 *      ...
 *    })
 * </pre>
 * @see add_respond_to_with()
 */
mixed query_respond_to_with() { return respond_to_with || ({ }); }

/**
 * This method adds a respond message to respond to into the
 * current array of responses.
 * <p>
 * If response_mon_regexp is not set, the trigger consists of an
 * array of words to be matched (in order) in the string.
 * If there is an array instead of a single word at one point
 * then any of the words in the array will be matched.
 * If response_mon_regexp is set, the trigger is a single string,
 * representing the regular expression to be matched in the string.
 * <p>
 * The response is either an array of things to execute
 * (in which case a random one will be chosen each time) or
 * a function pointer or a string.  If it is a string then
 * the command of that name will be executed, if the
 * string starts with a '#' then the function named after that
 * will be called on the npc.  That was exciting wasn't it?
 * If the string has a $hname$ name in it and it is not a
 * function call (starts with a #) then the $hname$ will be replaced
 * with the name of the triggering object.
 * <p>
 * In the case of a function call, two arguments are passed into
 * the function: the first is the person which triggered the effect
 * and the second in the message which triggered the effect.
 * <p>
 * Also possible with a format of "#filename:function" is calling
 * functions on other objects.  Those functions will be called
 * with the NPC (object) as the first argument, and the person
 * triggering the event as the second (object) argument.
 * <p>
 * NOTE: The NPC must explicitly know the language being spoken, even
 * if it's "common".  I don't know why.  That's just the way it is.  See
 * add_language().
 * @example
 * // Simple response
 * add_respond_to_with(({ "@say", "bing" }), "'Yes!  Bing bing bing!");
 * @example
 * // respond to someone saying 'frog' or 'toad'
 * add_respond_to_with(({ "@say", ({ "frog", "toad" }) }),
 *                     "'Frogs and toads are nice.");
 * @example
 * // Randomly say something or bing back at them
 * add_respond_to_with(({ "@say", "bing" }),
 *                     ({ "'Yes!  Bing bing bing!", "bing $hname$" }));
 * @example
 * // Call the function 'rabbit' on the npc.
 * add_respond_to_with(({ "@say", "bing" }), "#rabbit");
 * @example
 * // Do something cute with a function pointer
 * add_respond_to_with(({ "@bing" }),
 *                  (: do_command("'something wild for " + $1->a_short()) :));
 * @example
 * // Calling a function on a room for example
 * add_respond_to_with(({ "@bing" }), "#"+PUB+"pub:do_bing_response");
 * @param trigger the trigger to trigger the action on
 * @param response the response to the action
 * @see query_respond_to_with()
 * @see query_response_allowed()
 * @see set_response_mon_regexp()
 * @see query_response_mon_regexp()
 * @see regexp()
 * @see add_language()
 */
void add_respond_to_with( mixed trigger, mixed response ) {
   if( !pointerp(respond_to_with) )
       respond_to_with = ({ });
   respond_to_with += ({ trigger, response });
} /* add_response() */

/**
 * This method checks the subsequence of words to see if it matches
 * any of our current response sets.
 * @param words the words which are to be tested
 * @return the response to be executed
 * @see add_respond_to_with()
 */
protected mixed check_sub_sequence( string *words ) {
    int word_index;
    int format_index;
    int format_size;
    int word_size;
    int match_counter;
    int cu_format_size;
    string word_str;

    format_index = 0;
    word_size = sizeof( words );
    word_str = implode( words, " ");
    format_size = sizeof( respond_to_with );

    while( format_index < format_size ) {
        if( use_regexp ) {
            if( regexp( word_str, respond_to_with[format_index]) )
                return respond_to_with[format_index+1];
        } else {
            word_index = 0;
            match_counter = 0;
            cu_format_size = sizeof( respond_to_with[format_index] );
            while( word_index < word_size && match_counter < cu_format_size ) {
                match_counter += match( words[word_index],
                    respond_to_with[format_index][match_counter] );
                word_index++;
            }
            if( match_counter == (cu_format_size) )
                return respond_to_with[format_index+1];
        }
        format_index += 2;
    }

    return 0;

} /* check_sub_sequence() */

/**
 * @ignore yes
 * This method returns 1 if str matches the format...
 * see also the definitions in the example file...
 */
protected int match( string str, mixed format ) {
   if( pointerp(format) )
       return member_array( str, format ) != -1;
   if( str == format )
       return 1;
   return 0;
} /* match() */

/**
 * This method removes annoying read marks to make the string easier to
 * parse.  Basically it strips punctuation.
 * @param str the string to remove the punctuation from
 * @return the string without any punctuation
 */
protected string remove_read_marks( string str ) {
   int i, size;
   string result, temp;

   size = strlen(str);
   result = "";
   while( i < size ) {
     temp = str[i..i];
     if( ( temp >= "A" && temp <= "Z" ) ||
         ( temp >= "a" && temp <= "z" ) ||
         ( temp >= "0" && temp <= "9" ) || temp == " " ) {
         result += temp;
     } else {
         result += " ";
     }
     i++;
   }
   return result;
} /* remove_read_marks() */

/**
 * This method runs the command passed in, doing some substitution.
 * @param str the string to execute
 * @param per the person who triggered the command
 */
protected void senddstr( string str, object per ) {
   if( ENV(TO) ) {
       command( !per ? str : replace( str, ({
                             "$hname$", per->query_name(),
                             "$hcname$", per->query_cap_name()
                             }) ) );
   }
} /* sendstr() */

/*
 * Take care not to send to other monsters...
 * Infinite recursion problem...
 * Imagine two monsters chatting with each other...
 */
/**
 * This method executes the response to the matched string.
 * @param rep the response to execute
 * @param per the person who initiated the event
 * @param mess the message that was matched
 * @see add_respond_to_with()
 */
protected void exec_response( mixed rep, object per, string mess ) {
   string *rabbit;

   if( !per || ( !interactive(per) && !query_respond_non_interactive() ) )
       return 0;

   if( !TO->query_visible(per) )
       return 0;

   if( pointerp(rep) )
       return exec_response( rep[random(sizeof(rep))], per, mess );

   if( functionp(rep) ) {
       evaluate( rep, per, mess );
   } else if( stringp(rep) ) {
       if( rep[0..0] == "#" ) {
           if( sizeof( rabbit = explode( rep[1..], ":") ) == 2 ) {
               call_out( (: call_other( $1, $2, $3, $4 ) :), 0,
                            rabbit[0], rabbit[1], TO, per );
               return;
           }
           rabbit = explode(rep[1..], "#");
           if( sizeof(rabbit) > 1 ) {
               call_out( (: call_other( $1, $2, $3, $4 ) :), 0,
                            rabbit[0], rabbit[1], per, mess );
           } else {
               call_out( rabbit[0], 0, per, mess );
           }
       } else {
           call_out("senddstr", 0, rep, per );
       }
   }
} /* exec_response() */

/** @ignore yes */
private void do_delay_thingy( string *extra, string mess, object per ) {
   mixed response;

   mess = lower_case(mess);

   if( !use_regexp )
       mess = remove_read_marks(mess);

   if( query_response_mon_debug_mode() )
       tell_object( per, "Parsing the text: "+
           implode( extra, " ")+" "+mess+"\n");

   response = check_sub_sequence( extra + explode( mess, " ") );
   if( query_response_mon_debug_mode() )
       tell_object( per, sprintf("Responding with %O\n", response ) );

   if( response && query_response_allowed( per, response ) )
       exec_response( response, per, mess );

} /* do_delay_thingy() */

/** @ignore yes */
private void do_response( string *extra, string mess, object per ) {
   call_out( (: do_delay_thingy( $1, $2, $3 ) :), 2, extra, mess, per );
} /* do_response() */

/** @ignore yes */
void event_person_say( object per, string start, string mess, string lang ) {
  string skill;

  if( !per || per == TO || stop_responding || !sizeof(respond_to_with) ||
      ( !interactive(per) && !query_respond_non_interactive() ) )
      return;

  if( ENV(TO) == find_object("/room/rubbish") ||
      ENV(TO) == find_object("/room/void") )
      return;

  /*
   * I know this is a hack, if you can do better, do so,
   * don't just take it out or things will break come womans day.
   */
  skill = LANGUAGES->query_language_spoken_skill(lang);
  if( TO->query_skill(skill) < 90 || per->query_skill(skill) < 60 )
      return;

  do_response( ({"@say"}), mess, per );

} /* event_person_say() */

/** @ignore yes */
varargs void event_soul( object per, string mess, object *avoid, string verb,
                         string last, mixed at ) {

   if( per == find_object(SOUL_OBJECT) )
       per = previous_object(2);

  if( !per || per == TO || stop_responding || !sizeof(respond_to_with) ||
      ( !interactive(per) && !query_respond_non_interactive() ) )
      return;

  if( ENV(TO) == find_object("/room/rubbish") ||
      ENV(TO) == find_object("/room/void") ||
      member_array( TO, avoid ) != -1 )
      return;

   if( ( !objectp(at) || ( objectp(at) && at != TO ) ) &&
       ENV(per) != ENV(TO) )
       return;

   mess = TO->convert_message( mess );
   do_response( ( objectp(at) ? ({ "@" + verb, "#"+last, at->query_name() }) :
               ({ "@" + verb, "#"+last }) ), mess, per );

} /* event_soul() */

/** @ignore yes */
varargs void event_whisper( object per, string mess, object *obs, string lang,
                            object me ) {

  if( !per || per == TO || stop_responding || !sizeof(respond_to_with) ||
      ( !interactive(per) && !query_respond_non_interactive() ) )
      return;

  if( ENV(TO) == find_object("/room/rubbish") ||
      ENV(TO) == find_object("/room/void") )
      return;

   // Don't let them see the message unless it is actually directed at them.
   if( member_array( TO, obs ) == -1 ) {
       do_response( ({"@whisper"}) + map( obs, (: $1->query_name() :) ),
                      "", per );
   } else {
       mess = TO->convert_message( mess );
       do_response( ({"@whisper"}) + map( obs, (: $1->query_name() :) ),
                      mess, per );
   }
} /* event_whisper() */

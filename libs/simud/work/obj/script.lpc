#include <object.h>
#include <saveload.h>

/** \todo Describe the purpose of this object.
 */

string *events;
mapping commands;
nosave int jump_pos;

void create();
void set_events( string *e );
string *query_events();
void init();
int command_exec( string comm );
void script_event( int seq );
void command_event( string comm, int seq );
int command_trigger();

/// Constructor for this object.
void create() {
/* OBJEDIT { */
/* } OBJEDIT */
}

/// \return this_object() if val == "Scriptobj", for convenience of present() function.
object id( string val ) {
   return val == "Scriptobj"?this_object():0;
}

/// \return The string "Scriptobj"
string query_name() {
   return "Scriptobj";
}

/// Allows you to set the array of script events directly
void set_events( string *e ) {
   events = e;
}

/// \return The array of script events
string *query_events() {
   return events;
}

/// Allows you to set the commands mapping directly.
void set_commands( mapping m ) {
   commands = m;
}

/// \return The mapping of verbs (commands) provided by this script object
mapping query_commands() {
   return commands;
}

/** The init() function, called whenever a player encounters this
 * script object. This is used to trigger the event sequence and
 * to initialize all the verbs for the players.
 */
void init() {
   string comm;

   if( mappingp(commands) )
   foreach( comm : commands )
   if( stringp(comm) )
      add_action( "command_trigger", comm );

   script_event( 0 );
   ::init();
}

/** This function is called on a timer to execute script events. The
 * script events are stored, in order, in the events array. The first
 * instruction in the script is always executed immediately when the
 * player enters the room. Every command has a delay, so the remaining
 * commands are specified after that.
 *
 * The format of a script command is:
 *
 * func[,delay]:param
 *
 * \a func is the name of the LPC function in this_object() which will
 * be called. \a delay is the time, in seconds, to pause script execution
 * until the next command is executed. Note that it is only accurate
 * to within 2 seconds (although 0 seconds will execute the next
 * command immediately). \a param is any string, and will be passed to
 * the function as a parameter.
 *
 * Note that you can use a non-existent function name as a simple delay
 * function, such as
 *
 * do_nothing,10:Does nothing
 *
 * Using a do_nothing function with a 0 delay is the same as a comment.
 * You can omit the ",delay" from any command, and it will be assumed to
 * be 0.
 */
void script_event( int seq ) {
   int delay;

   if( !this_player() ) return;
   if( !present(this_player(), environment(this_object())) ) return;
   if( !pointerp(events) || seq >= sizeof(events) ) return;

   jump_pos = seq + 1;

   delay = 0;
   if( stringp(events[seq]) )
      delay = command_exec( events[seq] );

   if( delay )
      call_out( "script_event", delay, jump_pos );
   else
      script_event( jump_pos );
}

/** The function called by script_event and command_event to
 * execute a line of the script. This function decodes the
 * command and calls the function it references.
 *
 * A brief explanation of script command syntax is found in
 * script_event().
 */
int command_exec( string comm ) {
   string func, param;
   int delay;

   func = param = 0;
   delay = 0;
   if( sscanf(comm, "%s:%s", func, param) != 2 ) func = comm;
   sscanf( func, "%s,%d", func, delay );
   call_other( this_object(), func, param );

   return delay;
}

/** Whenever the player types in a command occurring in the
 * commands mapping, this function will be called. It queries
 * the verb and dispatches the relevant script.
 */
int command_trigger() {
   if( !mappingp(commands) || !member(commands, query_verb()) )
      return 0;

   command_event( query_verb(), 0 );
   return 1;
}

/** The same as script_event(), except that this one is used for
 * decoding commands, not the main script.
 */
void command_event( string comm, int seq ) {
   int delay;

   if( !pointerp(commands[comm]) || seq >= sizeof(commands[comm]) )
      return;

   jump_pos = seq + 1;

   delay = 0;
   if( stringp(commands[comm][seq]) )
      delay = command_exec( commands[comm][seq] );

   if( delay )
      call_out( "command_event", delay, comm, jump_pos );
   else
      command_event( comm, jump_pos );
}

/** Script command: Uses msg_object() to send the message \a str
 * to this_player().
 */
void do_msg( string str ) {
   set_listener( this_player() );
   msg_object( this_player(), str );
}

/** Sets a variable in the player to some value. This will work with
 * ints and strings, but not other types. For example:
 *
 * set_player,0:hp=20
 *
 * would call this_player()->set_hp(20); The "set_" is assumed, and always
 * prepended. For a string, you could do:
 *
 * set_player,0:distant=a foolish child
 */
void set_player( string str ) {
   string var;
   mixed newval;

   if( sscanf(str, "%s=%d", var, newval) != 2 && sscanf(str, "%s=%s", var, newval) != 2 )
      debug("set_player in "+object_name(this_object())+" did not get a valid input: "+str);

   else
      call_other( this_player(), "set_" + var, newval );
}

/** Similar in spirit to set_player(), except that the "add_" function is
 * called. The syntax is also a little different. For example:
 *
 * add_player,2:hp-=5
 *
 * You may use -= or +=. As always, the delay is optional.
 */
void add_player( string str ) {
   string var;
   int newval;

   if( sscanf(str, "%s+=%d", var, newval) == 2)
      call_other( this_player(), "add_" + var, newval );
   else if( sscanf(str, "%s-=%d", var, newval) == 2 )
      call_other( this_player(), "add_" + var, -newval );
   else
      debug("add_player in "+object_name(this_object())+" did not get a valid input: "+str);
}

/** Moves the player to the world reference given in /a str. Although we
 * do not force you to, you really should give the player a message (do_msg)
 * to warn them that they have been moved; otherwise, they will be confused!.
 */
void silent_move( string str ) {
   object dest;

   dest = find_room( str, this_object() );
   if( dest )
      this_player()->move( dest );
   else
      debug("Error in script at "+object_name(environment(this_object()))+": room "+str+" not found.");
}

/** Makes a function call in the player object. This allows for a single parameter, which
 * may be string or integer. The function name is seperated from the parameter by a colon,
 * thus:
 *
 * call:set_distant:a not-overly-bright gnome
 *
 * The parameter is optional, so you could do this too:
 *
 * call:reroll
 */
void call( string str ) {
   string func;
   mixed param;

   if( sscanf(str, "%s:%d", func, param) == 2 ||
       sscanf(str, "%s:%s", func, param) == 2 )
      call_other( this_player(), func, param );
   else
      call_other( this_player(), str );
}

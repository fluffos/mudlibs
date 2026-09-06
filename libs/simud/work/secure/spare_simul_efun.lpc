#define MAX_LOG_SIZE 50000

#include "wizlist.h"
#include "/include/const.h"

#pragma strong_types
#pragma save_types
#define MASTER "/secure/master"

/**
 * The simul_efun file defines functions that may be used anywhere.
 * It is not a normal object and, as such, shouldn't be cloned or
 * inherited. You may use these functions directly, as if they were
 * built into the MUDlib. This allows the MUDs functionality to be
 * extended easily.
 *
 * This is a mudlib file. It belongs in /secure/simul_efun.c. The master
 * object (generally /secure/master.c) will load it as one of its
 * first actions.
 *
 * Note: Originally this was a simul_efun from some lib included with
 * Amylaar's 3.2.1 driver. However, to my knowledge, not a single
 * line of code remains from that original file; it's all been either
 * rewritten or pruned.
 *
 * You may destruct/reload the simul_efun object without harmful
 * effects -- upon destruction, it stores its most important variables
 * (the living mappings) on the master object, and upon reloading,
 * it retrieves them.
 */
/// Defines "simulated external functions" which may be called from any object.

// Prototypes
string file_name( object ob );
varargs void debug( string words, string channel );
varargs void msg_object( object ob, string words, int indent );
varargs string eval_exp( string exp, object env );
string as_string( mixed var );
int valid_manipulate( object actor, object env );
string tab( string tabstr, int count );
string stime( int time );
int is_clone(mixed ob);
varargs object single_present( string str, object env, mixed obj_filter );
varargs mixed as_lpc( mixed var, int simple );
varargs string process_ansi(string fmt, object dest);

/// A mapping keyed by name to find living objects.
mapping name_living_m=([]);
/// A mapping keyed by object pointer to find living objects' names.
mapping living_name_m=([]);

/** Initialized to contain the escape character. */
string ESCAPE;

/// Holds description variables (for conditional descriptions)
mapping desc_vars;

/** A 256-character-long string that is used as a table
 * for getting rid of control characters from strings in cleanup_string()
 */
string valid_chars;

/** A list of valid pronouns for objects: him, her, it, them.
 */
mapping pronouns;

/** A list of the most common ANSI codes used.
 */
mapping ansitab, noansitab;

/// A long string of spaces, usable by pad().
string space_pad;

/** Not callable externally. This function is used to build some useful
 * global variables used in simul_efun.
 *
 * WARNING! This is a highly sensitive function! You cannot put very much
 * in here, and that includes call_other functions. Be very careful!
 */
void create() {
   int i;
   mixed old_vars;

   ESCAPE = " ";
   ESCAPE[0] = 0x1B;

   valid_chars = "12345678911234567892123456789312";
   for( i = 0; i < 3; i++ )
   valid_chars = valid_chars + valid_chars;
   // Make valid_chars a 256 char long string...

   for( i = 0; i < 256; i++ )
   if( i < 32 && i != '\n' && i != '\r' && i != '\b' && i != '\t' )
      valid_chars[i] = '_';
   else valid_chars[i] = i;

   desc_vars = ([ ]);

   space_pad = this_object()->tab( " ", 512 );

   pronouns = ([ "it": 0, "him": 1, "her": 2, "them": 3 ]);

   // Used for after a simul_efun update to avoid state loss
   if( old_vars = "/secure/master"->query_hold_var() )
   if( pointerp(old_vars) && sizeof(old_vars) == 3 ) {
      name_living_m = old_vars[0];
      living_name_m = old_vars[1];
      desc_vars = old_vars[2];
   }
   "/secure/master"->set_hold_var( 0 );

   ansitab = ([ ]);
   noansitab = ([ ]);
   call_out("build_ansitab", 0);
}

void build_ansitab() {
   int i;

   for( i = 0; i < 16; i++ ) {
      int iback;
      string code;

      for( iback = 0; iback < 8; iback++ ) {
         code = "[" + (i / 10) + (i % 10) + (iback);
         ansitab[code] = "/daemon/ansi"->get_code( code );
         noansitab[code] = "/daemon/ansi"->get_code_noansi( code );
      }
   }
}

mapping query_ansi_tab() {
   return ansitab;
}

string destructor() {
   "/secure/master"->set_hold_var( ({ name_living_m, living_name_m, desc_vars }) );
   return 0;
}

/** Finds the player whose query_name() function
 * returns \a name. If no such player can be found, returns
 * 0. The player need not be present.
 */
object find_player( string name ) {
   if( !stringp(name) )
      return 0;
   object *user_list;
   int i;
   name = lower_case( name );

   user_list = users();
   for( i = 0; i < sizeof(user_list); i++ )
      if( user_list[i]->query_name() == name ) return user_list[i];
   return 0;
}

/// \return True if \a ob is a living object.
int is_living( object ob ) {
   if( objectp(ob) && ob->query_is_living() ) return 1;
   return 0;
}

/** Adds a living object to the mapping of living objects.
 * Similar to set_living_name, except that you may specify
 * which object is to be added as the second parameter.
 * \param name The name of the living object.
 * \param ob A pointer to the living object whose name is being added.
 */
void insert_living(string name, object ob) {
    string old;
    mixed a;
    int i;

    if( !is_clone(ob) ) return;
    if (old = living_name_m[ob]) {
        if (pointerp(a = name_living_m[old])) {
            a[member(a, ob)] = 0;
        } else {
            efun::m_delete(name_living_m, old);
        }
    }
    living_name_m[ob] = name;
    if (a = name_living_m[name]) {
        if (!pointerp(a)) {
            name_living_m[name] = ({a, ob});
            return;
        }
        /* Try to reallocate entry from destructed object */
        if ((i = member(a, 0)) >= 0) {
            a[i] = ob;
            return;
        }
        name_living_m[name] = a + ({ob});
        return;
    }
    name_living_m[name] = ob;
}

/** Call this function from your living objects in their
 * initialization code to add them to the searchable
 * database of living objects.
 * \param name The name by which the object should be referenced
 */
varargs void set_living_name(string name) {
    insert_living(name, previous_object());
}

/** Finds a living object whose living name is
 * \a name. If passed only one parameter, it will first search
 * environment(this_player()) for a living matching 'name', and
 * if no such living is found, it will select one of the living
 * objects in the world with that name, and return a pointer to it,
 * or 0 if there is no such living anywhere. If passed two
 * parameters, it will choose one of the living objects inside
 * of \a env named \a name, and return a pointer to it. Again, it
 * returns 0 on failure.
 *
 * See also set_living_name(). Note that living searches done
 * in the local room need only match the id() function, but
 * global searches must match the living name exactly.
 */
nomask varargs object find_living(string name, object env) {
   mixed *a, r;
   object ob;
   int i;

   if( !name ) return 0;

   if( env ) {
      foreach( ob: all_inventory(env) )
         if( is_living(ob) && ob->id(name) ) return ob;
      return 0;
   }

   if( this_player() && environment(this_player()) )
   foreach( ob: all_inventory(environment(this_player())) )
      if( is_living(ob) && ob->id(name) ) return ob;

   if (pointerp(r = name_living_m[name]) && sizeof(r) > 0) {
      if( !is_living(r = (a = r)[0]) ) {
         for (i = sizeof(a); --i;) {
            if( is_living(a[<i]) ) {
               r = a[<i];
               a[<i] = a[0];
               return a[0] = r;
            }
         }
      }
      return r;
   }
   return is_living(r) && r;
}

/** \return An array of all living objects whose living_name is
 * \a name. If there are no living objects with that name, 0 is
 * returned.
 */
nomask object *all_living( string name ) {
   mixed x;
   x = name_living_m[name];
   if( pointerp(x) ) {
      name_living_m[name] -= ({ 0 });
      return x;
   }
   if( objectp(x) ) return ({ x });
   m_delete(name_living_m, name);
   return ({ });
}

/** \return An array of all the names of all the living objects
 * in the world. To get more information on them, use find_living()
 * or all_living(), passing in the name.
 */
nomask string *all_living_names() {
   return m_indices( name_living_m );
}

/** Gets the modification time for a file. If the file
 * does not exist, -1 is returned. The time is given
 * as an integer -- use ctime() or stime() on the
 * integer to make it human readable.
 */
int file_time(string path ///< The full path of the file.
   ) {
   mixed *v;

   set_this_object(previous_object());
   if (sizeof(v=get_dir(path,4))) return v[0];
   else return -1;
}

/** Adds a string onto the end of a log file. The logs are
 * kept in LOG_DIR, defined in const.h. This function does
 * not allow you to pass in an absolute path (although subpaths
 * off the log directory, like sys/syslog, would be allowed).
 */
void log_file(string file, ///< The file you wish to add a log entry to.
              string str   ///< The string to be added to the log file.
              ) {
    string file_name;
    int *st, fnum;

    file_name = LOG_DIR + file;
    if ( sizeof(st = get_dir(file_name,2) ) && st[0] > MAX_LOG_SIZE) {
        for( fnum = 1; file_size(file_name + "." + fnum) >= 0; fnum++ );
   catch(rename(file_name, file_name + "." + fnum)); // No panic if failure
    }
    str = stime(time()) + " from " + object_name(previous_object()) +
       (this_player() && this_player()->query_name() ? " (" + capitalize(this_player()->query_name()) + "): " : ": ") +
       str;
    write_file(file_name, str);
}

/** \return the location of an object in the world as a semicolon delimited
 * object reference. find_room(get_location(obj)) returns obj. If the \a fromme
 * parameter is given, the reference will be relative to fromme.
 * \param whome The object whose location you wish to find.
 * \param fromme (Object) The object to start looking from; if it isn't specified, the world is used.
 */
varargs string get_location(object whome, object fromme)
{
   string ret;

   if(!whome) return 0;

   ret = 0;
   while(whome && whome != fromme) {
      if(ret) ret = whome->query_name() + ";" + ret;
      else ret = whome->query_name();
      whome=environment(whome);
   }
   return ret;
}

/** Returns the current version of the MUDlib driver. */
string version() {
    return __VERSION__;
}

/** Gives an array of all containers which an object is in, i.e.
 * match in matchbox in bigbox in chest in room, would for the
 * match give: matchbox, bigbox, chest, room
 * \param ob The object
 * \return The array of containers.
 */
public varargs object *
all_environment(object ob)
{
  object *r;

  if( !ob ) ob = previous_object();
  if( !environment(ob) ) return 0;
  if( !environment(environment(ob)) )
      return ({ environment(ob) });
  r = ({ ob = environment(ob) });
  while (environment(ob))
      r = r + ({ ob = environment(ob) });
  return r;
}

/** Wordwraps a string. Allows hanging indentation (with the indent
 * parameter) and variable width (number of characters width on the
 * terminal).
 * \param str Original message
 * \param width The total maximum width of each line.
 * \param indent (optional) How many spaces to indent with. Maximum 80 characters.
 * \returns A string with newline separated strings
 * \note Ignores ANSI codes for counting characters.. Clear-screen codes and
 * similar will still have odd effects, of course.
 */

public varargs string
break_string(string str, int width, int indent)
{
   string indstr, ifrag;
   string *fragments, out, spaces;
   int curr_line_len;

   if( !stringp(str) ) return "";
   if( width - indent < 15 ) {
      indent = width - 15;
      if( indent < 0 ) {
         indent = 0;
         width = 15;
      }
   }
   indstr = "\n" + sprintf( "%" + (indent) + "' 's", "" );

   out = "";
   spaces = "";
   fragments = regexplode( str, "(\27\\[[^a-zA-Z]*[a-zA-Z])| |\n" ) - ({ "" });
   // ... In-order traversal...
   curr_line_len = 0;
   foreach( ifrag : fragments ) {
      // Spaces are a very common case :-).
      if( ifrag == " " ) {
         // We don't use spaces if they happen to occur right where
         // we're breaking a line, so I save them here until I'm sure
         // these spaces are not at EOL.
         spaces += " ";
         continue;
      }
      // Allow newlines in text; start wrapping loop over.
      if( ifrag == "\n" ) {
         out += indstr;
         curr_line_len = indent;
         spaces = "";
         continue;
      }
      // Skip ANSI
      if( ifrag[0] == 27 ) {
         out += spaces;
         spaces = "";
         out += ifrag;
         continue;
      }
      // Break very long strings
      if( strlen(ifrag) >= width - indent ) {
         // If there's room for them, put the spaces in...
         if( strlen(spaces) + 1 < width - curr_line_len ) {
            out += spaces;
            curr_line_len += strlen(spaces);
         }
         // Otherwise, linewrap before starting.
         else {
            out += indstr;
            curr_line_len = indent;
         }
         spaces = "";
         do {
            out += ifrag[..(width-curr_line_len)-1] + indstr;
            ifrag = ifrag[(width-curr_line_len)..];
            curr_line_len = indent;
         } while( strlen(ifrag) >= width - indent );
      }
      // Is there room on current line?
      if( strlen(ifrag) + strlen(spaces) < width - curr_line_len ) {
         out += spaces + ifrag;
         curr_line_len += strlen(spaces) + strlen(ifrag);
         spaces = "";
      }
      // Linewrap...
      else {
         out += indstr + ifrag;
         curr_line_len = strlen(ifrag) + indent;
         // Discard spaces when linewrapping
         spaces = "";
      }
   }
   return out;
}


/** \return True if ob is an object pointer and a clone. This
 * is done by checking the file name for a #.
 * \param ob The object.
 */
int is_clone(mixed ob) {
    return objectp(ob) && member(object_name(ob), '#') >= 0;
}

/**
 * Sends a message on the debug channel. Messages are delayed by about
 * two seconds (to avoid certain kinds of recursion). You must have
 * the debug channel enabled to hear debug messages.
 *
 * Debug has been altered to bypass the mudwide chat system. As a result,
 * I don't know if problems of aforementioned recursion might present
 * themselves - Al [6/26/03]
 */
varargs void debug( string words, string channel ) {
   object who;
   string buf;
   int indent;

   if (!channel)
      channel = "debug";
   else
      channel = "debug:"+channel;

   if( !stringp(words) ) words = to_string(words);

   indent = strlen(channel) + 3;
   if (previous_object())
      buf = "~[040[~[120"+capitalize(channel)+"~[040]~CDEF " + to_string(previous_object()) + ": " + words;
   else
      buf = "~[040[~[120"+capitalize(channel)+"~[040]~CDEF <no object>: "+words;

   foreach( who : users() ) {
      string *chanlist;

      chanlist = who->query_env_var("channels");
      if( pointerp(chanlist) && member(chanlist, channel) != -1 ) {
         if( find_object("/daemon/ansi") )
            tell_object(who, break_string(process_ansi(buf), who->query_term_width(), indent)+"\n");
         else
            tell_object(who, buf + "\n");
      }
   }
}

/// Deprecated function detector :-)
string file_name( object ob ) {
   debug("Warning, file_name called in "+object_name(previous_object())+", is deprecated; please change to object_name().");
   return object_name(ob);
}

/** Used by stime() to convert month names to numbers */
mapping _months;

/** Generates timestamps of the form:
 * dd.mm.yy hh:mm
 */
string stime( int time ) {
   string fulldate;

   if( !_months )
   _months = ([ "Jan":"01", "Feb":"02", "Mar":"03",
                "Apr":"04", "May":"05", "Jun":"06",
                "Jul":"07", "Aug":"08", "Sep":"09",
                "Oct":"10", "Nov":"11", "Dec":"12" ]);

   fulldate = ctime( time );
   if( fulldate[8] == ' ' ) fulldate[8] = '0';
   return fulldate[8..9] + "." + _months[fulldate[4..6]] + "." +
          fulldate[22..23] + " " + fulldate[11..18];
}

/** Converts an integer number of seconds to a string giving the
 * length of the time period in days, hours, minutes and seconds.
 */
string int_to_time(int x) {
  string buf="";
  int y;

  y = x/(60*60*24);   // days
  x -= y*60*60*24;
  if (y > 0)
    buf += (string)y+" day"+(y==1?"":"s")+", ";

  y = x/(60*60);   // hours
  x -= y*60*60;
  if (y > 0)
    buf += (string)y+" hour"+(y==1?"":"s")+", ";

  y = x/(60);      // minutes
  x -= y*60;
  if( y > 0 )
  buf += (string)y+" minute"+(y==1?"":"s")+" and ";

  buf += (string)x+" second"+(x==1?"":"s");
  return buf;
}

/** Returns \a arr with the ith element deleted.
 * Unlike exclude_element, this leaves the remaining
 * elements unshuffled (they are scooted down).
 */
mixed *array_delete(mixed *arr, int i) {
   int s;
   s = sizeof(arr) - 1;

   if(i < 0 || i > s) return arr;
   if(s == 0) return ({});
   if(i==0) return arr[1..s];
   if(i==s) return arr[0..s-1];
   return arr[0..i-1] + arr[i+1..s];
}

/* Some of the escape codes, like ~targ, require that a "target" variable
 * be set. Use these set_ functions to set those codes
 */

/** Used by set_target() */
object _target;
/** Used by set_actor() */
object _actor;

/** Sets the target which the ~targ escape codes refer to.
 * \param ob An object pointer for the target (not the name).
 */
void set_target(object ob) {
   _target = ob;
}

/** Sets the actor which the ~name escape codes refer to.
 * \param ob An object pointer for the actor; usually this_player(). This is not the name.
 */
void set_actor(object ob) {
   _actor = ob;
}

/** \return The value most recently passed to set_target().
 */
object query_target() {
   return _target;
}

/** \return The value most recently passed to set_actor().
 */
object query_actor() {
   return _actor;
}

/** Used by set_direction() */
string _direction;
/** Pass in any string. The ~dirc code will be replaced
 * by the string which you pass in in subsequent calls to
 * msg functions or process_string. This is typically used
 * for directions, i.e. Bob leaves ~dirc -> Bob leaves north.
 */
void set_direction(string str) {
   _direction = str;
}

/// \return The most recently set direction from set_direction().
string query_direction() {
   return _direction;
}

string _adverb;

/** Allows you to set the current adverb. If players give an
 * adverb before their verbs, this will be called; you can
 * use query_adverb() to fetch it.
 */
void set_adverb(string x) {
   _adverb = x;
}

/// \return The currently set adverb.
string query_adverb() {
   return _adverb;
}

/** Used by set_listener() */
object _listener;
/** The listener is a variable you should set whenever using
 * formatted strings. The listener tells who is "listening" to
 * this text, so that the verb conjugation and name/pronoun
 * codes can be interpreted correctly. Send in an *object pointer*
 * for whoever is listening.
 */
void set_listener(object who) {
   _listener = who;
}

object query_listener() {
   return _listener;
}

/** process_grammar is used locally by all msg class functions.  It
 * scans a string and converts formatted text (all ~xxxx material) into
 * the correct format (i.e. ~name is this player's name). You should usually
 * call set_actor(), set_target(), and set_listener() before you call this
 * function -- these set up the messaging environment for handling grammar.
 * If the messager you're processing doesn't need grammar, you don't have a
 * problem.
 *
 * See verb.c for how to use verb conjugations.
 * \param fmt The string (with ~ codes in it)
 * \param dest (Optional) The person who will actually receive this string.
 * If necessary, this may be someone other than the listener
 * (see set_listener). This is not really significant grammatically, it
 * is mainly used to decide whether to use ANSI colors or not.
 * \note This function should be called before break_string, otherwise
 * the linewrapping will have errors.
 */
varargs string process_grammar(string fmt, object dest) {
   string flag, res, tverb;
   string *split_fmt;
   int i, j, n, len;

   if( !_actor ) _actor = this_player();
   if( !dest ) dest = _listener;
   if( !dest ) dest = this_player();
   if( !_target ) _target = this_player();
   if( !_direction ) _direction = "nowhere";

   if( !_actor || !dest || !_target )
      return fmt;

   if(!stringp(fmt)) return fmt;
   split_fmt = explode( fmt, "~" );
   n = sizeof( split_fmt );
   // Item 0 can't start with a ~ code; even if the first char in the string is ~, item
   // 0 will be "".
   for( i = 1; i < n; i++ ) {
      flag = split_fmt[i][..3];

      res = "~" + flag;
      if( strlen(flag) == 4 )
      switch(flag) {

// List of TAGS starts here. Unindented for logistics.
case "name":
if(_listener != _actor) {
   res = eval_exp( _actor->query_specific(), _actor );
}
else res = "you";
break;

case "Name":
if(_listener != _actor) {
   res = capitalize( eval_exp(_actor->query_specific(), _actor) );
}
else res = "You";
break;

case "anam":
if(_listener != _actor) {
   res = eval_exp( _actor->query_distant(), _actor );
}
else res = "you";
break;

case "Anam":
if(_listener != _actor) {
   res = capitalize( eval_exp(_actor->query_distant(), _actor) );
}
else res = "You";
break;

case "noun":
   res = _actor->query_name();
break;

case "nout":
   res = _target->query_name();
break;

case "Noun":
   res = capitalize( "" + _actor->query_name() );
break;

case "Nout":
   res = capitalize( "" + _target->query_name() );
break;

case "dirc":
res = _direction;
break;

case "Dirc":
res = capitalize("" + _direction);
break;

case "targ":
if( _target == _actor ) {
   res = call_other("daemon/dictionary", "reflexive_for", _target, _listener == _target);
}
else {
   if( _listener != _target ) {
      res = eval_exp( _target->query_specific(), _target );
   }
   else
      res = "you";
}
break;

case "Targ":
if( _target == _actor ) {
   res = capitalize("" + call_other("daemon/dictionary", "reflexive_for", _target, _listener == _target));
}
else {
   if( _listener != _target ) {
      res = capitalize("" + eval_exp(_target->query_specific(), _target) );
   }
   else
      res = "You";
}
break;

case "atar":
if( _target == _actor ) {
   res = call_other("daemon/dictionary", "reflexive_for", _target, _listener == _target);
}
else {
   if( _listener != _target ) {
      res = eval_exp( _target->query_distant(), _target );
   }
   else
      res = "you";
}
break;

case "Atar":
if( _target == _actor ) {
   res = capitalize("" + call_other("daemon/dictionary", "reflexive_for", _target, _listener == _target));
}
else {
   if( _listener != _target ) {
      res = capitalize( eval_exp(_target->query_distant(), _target) );
   }
   else
      res = "You";
}
break;

case "subt":
if( _listener != _target )
   res = eval_exp(_target->query_specific(), _target);
else
   res = "you";
break;

case "Subt":
if( _listener != _target )
   res = capitalize( eval_exp(_target->query_specific(), _target) );
else
   res = "You";
break;

case "verb":
case "Verb":
case "vert":
case "Vert":
j = 4;
len = strlen( split_fmt[i] );
while( j < len && (split_fmt[i][j] == '\'' || (split_fmt[i][j] >= 'a' && split_fmt[i][j] <= 'z')) ) j++;
tverb = split_fmt[i][4..j-1];

if((_listener == _actor && flag[3] == 'b') || (_listener == _target && flag[3] == 't'))
   tverb = "/daemon/dictionary"->conjugate_verb(tverb, 1);
else tverb = "/daemon/dictionary"->conjugate_verb(tverb, 0);
if(fmt[0] == 'V')
res = capitalize("" + tverb);
else res = tverb;
split_fmt[i] = "VERB" + split_fmt[i][j..];
break;

case "Pron":
case "pron":
tverb = call_other("/daemon/dictionary", "pronoun_for", _actor, _listener == _actor);
if(flag[0] == 'P') res = capitalize("" + tverb);
else res = tverb;
break;

case "Prot":
case "prot":
tverb = call_other("/daemon/dictionary", "pronoun_for", _target, _listener == _target);
if(flag[0] == 'P') res = capitalize("" + tverb);
else res = tverb;
break;

case "Poss":
case "poss":
tverb = call_other("/daemon/dictionary", "possessive_for", _actor, _listener == _actor);
if(flag[0] == 'P') res = capitalize("" + tverb);
else res = tverb;
break;

case "Refl":
case "refl":
tverb = call_other("/daemon/dictionary", "reflexive_for", _actor, _listener == _actor);
if(flag[0] == 'R') res = capitalize("" + tverb);
else res = tverb;
break;

case "Reft":
case "reft":
tverb = call_other("/daemon/dictionary", "reflexive_for", _target, _listener == _target);
if(flag[0] == 'R') res = capitalize("" + tverb);
else res = tverb;
break;

case "Obje":
case "obje":
tverb = call_other("/daemon/dictionary", "object_pronoun_for", _actor, _listener == _actor);
if(flag[0] == 'R') res = capitalize("" + tverb);
else res = tverb;
break;


case "Objt":
case "objt":
tverb = call_other("/daemon/dictionary", "object_pronoun_for", _target, _listener == _target, _actor);
if(flag[0] == 'R') res = capitalize("" + tverb);
else res = tverb;
break;


case "Npos":
if( _listener != _actor )
   res = capitalize( eval_exp(_actor->query_specific(), _actor) + "'s" );
else res = "Your";
break;

case "npos":
if(_listener != _actor)
   res = eval_exp(_actor->query_specific(), _actor) + "'s";
else res = "your";
break;

case "Npot":
if(_listener != _target)
   res = capitalize( eval_exp(_target->query_specific(), _target) ) + "'s";
else res = "Your";
break;

case "npot":
if(_listener != _target)
   res = eval_exp(_target->query_specific(), _target) + "'s";
else res = "your";
break;

case "Post":
case "post":
tverb = call_other("/daemon/dictionary", "possessive_for", _target, _listener == _target);
if(flag[0] == 'P') res = capitalize("" + tverb);
else res = tverb;
break;
      }
      split_fmt[i] = res + split_fmt[i][4..];
   }// End of for loop (through array).

   return implode( split_fmt, "" );
}

/** process_ansi is used locally by all msg class functions.  It
 * is used to process ANSI codes *only*. This function should only
 * be called ONCE per string, otherwise escaped tildes (the ~TILD code)
 * will be treated as normal tildes, which will give wrong results occasionally.
 * \param fmt The string (with ~ codes in it)
 * \param dest (Optional) The person who will actually receive this string.
 * If necessary, this may be someone other than the listener
 * (see set_listener). This is not really significant grammatically, it
 * is mainly used to decide whether to use ANSI colors or not.
 * \note This function should be called before break_string, otherwise
 * the linewrapping will have errors.
 */
varargs string process_ansi(string fmt, object dest) {
   string flag, res, tverb;
   string *split_fmt;
   int i, j, n, len;
   mapping tab_used;

   if( !objectp(dest) ) dest = this_player();

   if(!stringp(fmt)) return fmt;
   split_fmt = explode( fmt, "~" );
   n = sizeof( split_fmt );
   // Item 0 can't start with a ~ code, even if it's ""
   if( dest && objectp(dest) && dest->query_ansi() ) {
      for( i = 1; i < n; i++ ) {
         flag = split_fmt[i][..3];

         res = ansitab[flag];
         if( !res ) {
            if( strlen(flag) != 4 ) res = flag;
            else {
               flag = "/daemon/ansi"->get_code( flag );
               res = flag;
            }
         }
         split_fmt[i] = res + split_fmt[i][4..];
      }// End of for loop (through array).
   }
   else {
      for( i = 1; i < n; i++ ) {
         flag = split_fmt[i][..3];

         res = noansitab[flag];
         if( !res ) {
            if( strlen(flag) != 4 ) res = flag;
            else {
               flag = "/daemon/ansi"->get_code_noansi( flag );
               res = flag;
            }
         }
         split_fmt[i] = res + split_fmt[i][4..];
      }// End of for loop (through array).
   }

   return implode( split_fmt, "" );
}

varargs string process_string(string fmt, object dest, int skip_ansi) {
   if( skip_ansi )
      return process_grammar(fmt, dest);
   else
      return process_ansi(process_grammar(fmt, dest), dest);
}


/** Used by query_messenger() */
object _messenger;

/** An implementation of tell_room() (which is not an efun)
 */
varargs void tell_room( object ob, string str ) {
   object *inv;

   inv = all_inventory(ob);
   if( inv )
   foreach( ob : inv )
      tell_object( ob, str );
}


/// Internally used to give the screen width to wrap for.
int wrap_width;

/** Returns the last object to execute a write or msg function. */
object query_messenger() {
   return _messenger;
}

/* Pseudocode:
 * If this_player() is invalid, set terminal width to 0, else use their width (note: might be 0).
 * If terminal width is 0, set it to 80.
 * eval_exp the text. This should also handle grammar codes.
 * process_ansi the text.
 * break_string it.
 * Set previous_object() to this_object(), to avoid the need for query_messenger()
 * Add a "\n" and use the write() *efun* to print the string.
 */
/** The msg class of functions are used as a replacement where possible of
 * write and tell_object. This function sends the string in "words" to
 * this_player() (typically the player who is currently performing an action).
 * A \\n is automatically added on the end, and prompt handling is done
 * according to set_message_mode() in player. If you don't want the
 * prompt handling and the automatic \\n, use msg_bare().
 * \param words A string containing the message you wish to display.
 * \param indent (optional) the number of spaces for a hanging indent.
 * All lines are indented after the first one (if you wish to indent
 * the first line, add some spaces of your own! See tab()).
 */
varargs void msg(string words, int indent ) {
   if( !this_player() )
      wrap_width = 0;
   else
      wrap_width = this_player()->query_term_width();
   if( !wrap_width )
      wrap_width = 80;

   words = break_string(process_ansi(eval_exp(process_grammar(words), previous_object())), wrap_width - 1, indent) + "\n";

//   set_this_object(previous_object());
//   efun::write(words);
   if( this_player() )
      this_player()->catch_tell( words, previous_object(), 1 );
   else
      write( words );
}

/** Processes expressions, ANSI codes, and grammar in \a words, and returns
 * the processed result. Do this, then linewrap, and you get the same result
 * as one of the msg() functions.
 */
varargs string process_codes( string words ) {
   return process_ansi( eval_exp(process_grammar(words), previous_object()) );
}

/**
 * Writes a message to this_player(). No \\n is added to the end,
 * and prompt handling is ignored. All of the usual processing is
 * still performed, however. If you don't want processing, use write().
 * \param words A string containing the message you wish to display.
 */
varargs void msg_bare( string words ) {
   words = process_ansi(eval_exp(process_grammar(words), previous_object()));

   this_player()->catch_tell(words, previous_object());
}

/**
 * Writes a message to ob. Automatically adds a \\n and
 * does message handling according to set_message_mode()
 * in player. If you don't want message handling or
 * process_string(), use tell_object().
 * \param ob An object pointer -- the person who is to receive this message.
 * \param words A string containing the message you wish to display.
 * \param indent (optional) the number of spaces for a hanging indent.
 * All lines are indented after the first one (if you wish to indent
 * the first line, add some spaces of your own! See tab())
 */
varargs void msg_object( object ob, string words, int indent ) {
//   object sefun;

   if( !(wrap_width = ob->query_term_width())) wrap_width = 80;

   //msg(words); // deleteme
   words = break_string(process_ansi(eval_exp(process_grammar(words), previous_object()), ob), wrap_width - 1, indent) + "\n";

   ob->catch_tell( words, previous_object(), 1 );
}

/** Sends a message to ALL players using msg_object.
 * \param words A string containing the message you wish to display.
 * \param indent (optional) the number of spaces for a hanging indent.
 * All lines are indented after the first one (if you wish to indent
 * the first line, add some spaces of your own! See tab())
 */
varargs void msg_all(string words, int indent) {
   int i;
   object *ob;

   ob = users();
   if(ob)
      for(i=0; i<sizeof(ob); i++) if( ob[i]->query_is_player() ) msg_object(ob[i], words, indent);
}

/** Sends a message to all objects inside of ob using msg_object.
 * This is mainly appropriate for broadcasting into a room from
 * elsewhere. Actions performed by living objects within the room are usually
 * best done using msg_local in the performer.
 * \param ob The room in which to broadcast the message.
 * \param words A string containing the message you wish to display.
 * \param indent (optional) the number of spaces for a hanging indent.
 * All lines are indented after the first one (if you wish to indent
 * the first line, add some spaces of your own! See tab())
 */
varargs void msg_room( object ob, string words, int indent ) {
   object *inv;

   msg_object( ob, words, indent );
   inv = all_inventory(ob);
   if( inv )
   foreach( ob : inv ) {
      set_listener( ob );
      msg_object( ob, words, indent );
   }
}

/** Sends a message to everyone listening to the "announce" channel.
 * The standard [Announce] prefix is NOT added.
 */
void announce(string words) {
   call_other("obj/chat", "do_msg", words, "announce");
}

/** \return \a tabstr, concatenated with itself \a count times. For
 * example, if you need a string of 80 spaces, call tab( " ", 80 );
 */
string tab( string tabstr, int count ) {
   return sprintf( "%" + (count * strlen(tabstr)) + "'" + tabstr + "'s", "" );
}

/** \return strlen(str) after stripping out color codes (~CXYZ and ~[###).
 */
int cstrlen( string str ) {
   return strlen( regreplace(regreplace(str, "(~C[A-Z][A-Z][A-Z])|(~([\[])[01][0-9][0-9])", "", 1), "~TILD", "~", 1) );
}

/** Pads or truncates a string to be exactly \a count characters long.
 * Your string should not contain tilde or ANSI codes, or you will have
 * strange side effects.
 * \param str The string to pad.
 * \param count The desired length of the string. Note that this function
 * has problems if the number of spaces to add is greater than 512 (if you
 * need more than this, modify the simul_efun create()).
 * \param just Justification for the string. If \a just == JUST_LEFT, then
 * padding will be added to the right of the string, if just == JUST_RIGHT
 * then padding is added on the left (right justify), and if just == JUST_CENTER
 * the string will be centered. The constants for justification are in const.h
 * \note The latest sprintf functions are more powerful than this function
 * is by a long shot; if you want real string processing power, go look it
 * up; this one is simpler to use, however.
 * \return The padded string.
 */
string pad(string str, int count, int just) {
   int len;

   str = "" + str;
   len = cstrlen(str);
   if( len >= count ) return str[..count-1];
   switch( just ) {
      case JUST_CENTER:
         str = space_pad[..(count-len)/2-1] + str;
         return str + space_pad[..(count-cstrlen(str))-1];
         break;
      case JUST_RIGHT:
         return space_pad[..count-len-1] + str;
      // Invalid values are JUST_LEFT
      default:
         return str + space_pad[..count-len-1];
   }
   return "";
}

#ifndef PREP_EXP
#define PREP_EXP "\\<on top of\\>|\\<on\\>|\\<under\\>|\\<in\\>|\\<inside of\\>|\\<inside\\>|\\<behind\\>"
#endif

/** Passed either an array of strings or a "\n" delimited list
 * of strings, this function will return the list separated
 * by commas with the conjunction "and" separating the last
 * two items.
 *
 * For example, comma_list("one\ntwo\nthree"); would return
 * "one, two and three"
 *
 * \param in The list you wish to be converted to a comma-
 * separated list. Either a string * or a string.
 */
string comma_list(mixed in)
{
   string out;
   int i, n;

   if( !pointerp(in) ) in = explode( in, "\n" );
   in -= ({ "", 0 });
   n = sizeof( in );
   if( !n ) return "";

   out = as_string(in[0]);

   if (n == 2)
      out += " and " + as_string(in[1]);
   else
      for( i = 1; i < n; i++ )
         out += (i == n - 1 ? ", and " : ", ") + as_string(in[i]);

   return out;
}

/** Returns a commified list, capitalized. */
string cap_comma_list( string *in ) {
   return comma_list( map(in, (: capitalize($1) :)) );
}

/** Returns a list of objects identified by the string id.
 * The types of descriptors that can be recognized are defined as
 * follows:
 *
 * <simple> -- A simple object reference.
 *   - Example: table
 *
 * <location> -- A locational object reference. Uses PREP_EXP to get a list of valid
 * prepositions for object locations. The format is <simple> [<preposition> <location>].
 * Note that evaluation of environment <simple>'s doesn't currently handle plural objects, only
 * singular ones (so "get all the fish from the bags on the table" would only look in the
 * first bag on the table).
 *   - Example: the bag on the table
 *
 * <numobj> -- [all [of]] [the|The] [<num>] [nearest|furthest|farthest] <location>
 *   - Example: the second dog --- third fish --- all five potions --- the three nearest potions
 *
 * <objlist> -- <numobj> | <numobj>, <objlist> | <numobj> and <objlist> | <numobj>, and <objlist>
 *   - Example: table, dog, and cat --- table and dog, cat --- table, dog and cat
 *
 * Evaluation:
 *
 * <simple> -- Find the first object whose id() returns true. If the query_is_plural()
 * doesn't match the search string, stop looking, otherwise keep going and
 * grab all the rest of the objects whose id() strings match. Plural evaluation
 * may be forced.
 *
 * <location> -- Search through the word list looking for any prepositions. If any
 * are found, search for the surrounding halves as if they were simple expressions.
 * Plural evaluation may be forced if a query_is_plural() matches.
 *
 * <numobj> -- If "all" or "all of" occur as a prefix they force a plural evaluation
 * of the <location> object reference. Numeric references may be of these types:
 *    - #.<location>
 *    - <numword> <location> where numword is any of "first, second, third..." etc.
 *    - <num> <location> where num is any of "1st, 2nd, 3rd, 4th..." etc.
 *    - <count> <location> where num is any of "one, two, three..." or "1, 2, 3...".
 *      In this case, you should count off however many objects before stopping evaluation.
 * If a direct article occurs before the "number word" it is simply stripped.
 *
 * <objlist> -- A list of object references. The <numobj> grammar is used for
 * evaluating individual objects in a list. These should be split before
 * being passed on, using "," ", and" and "and" as delimiters.
 *
 * \param id The string to be checked for, i.e. "all the apples on the table"
 * \param env (Optional) The object in which you wish the search to begin. Usually the
 * room the player is in, or the player himself. If omitted,
 * defaults to the player himself (inventory).
 * \param obj_filter (Optional) An array of objects which will be quietly
 * ignored. Alternately, a closure to be called on every object processed;
 * only objects which return true will be considered. The closure is passed
 * the object under consideration as a parameter.
 *
 * \note This function doesn't solve all your problems, it is just a tool. For
 * example, a "get" function would still need to implement "from" as a keyword
 * for getting objects from inside other objects; however, it could parse the
 * remainder of the expression by passing the phrases on either side of from
 * to this function. In addition, since this function looks for objects that
 * are already present, a "put" expression would need to find a preposition
 * and parse to either side of it, since the object is not yet present in
 * the place specified.
 */
varargs object *all_present( string id, object env, mixed obj_filter ) {
   string *phrase_list; // List of <numobj> phrases for the objlist rule.
   object *ob_list;     // List of objects that match the expression
   object *env_objs;    // List of objects in the environment.
   object ob;           // A "looper" object for going through candidate objects.
   object ind;          // A variable for objects that make use of id() indirection.
   int ioblist;         // Loop through an objlist.
   int plural;          // A flag that decides whether plural evaluation will be used.
   int tcount, ccount;  // Total and current count, for references to a certain number of objects.
                        // If plural is OFF during a ccount/tcount loop, then only the ccount'th object
                        // will match.
   mapping num_map;     // temp
   int near_flag;       // 0 for no sort, 1 for "nearest" sort, -1 for "furthest" sort.
                        // Will not work if this_player() isn't valid.
   object *ignored_obs; // Used if obj_filter is an array.
   num_map = NUMBERS_MAP;

   if( !env )
      if( this_player() )
         env = this_player();
      else
         return 0;

   if( id == "me" || id == "myself" || id == "self" ) return ({ this_player() });

   if( !pointerp(obj_filter) ) ignored_obs = ({ });
   else ignored_obs = obj_filter;

   if( !closurep(obj_filter) ) obj_filter = (:1:); // Accept everything.

   if( !id ) return 0;

   id = lower_case( id );

   id = regreplace( id, "([0-9]+)[.]", "\\1st ", 1 );
   phrase_list = explode( regreplace( id, ", and | and |, ", "\n", 1 ), "\n" );

   ob_list = ({ });

   for( ioblist = 0; ioblist < sizeof(phrase_list); ioblist++ ) {
      string curr_phrase, *prep_phrase;
      int wpos; // Word position for getting numeric information.
      int iprep; // Loop through prepositions
      object curr_env;

      curr_phrase = phrase_list[ioblist];

      // Look for <numobj> type expressions.
      if( sscanf(curr_phrase, "all %s", curr_phrase) ) {
         // Force plural evaluation
         plural = 1;
         // Remove optional "of"
         sscanf( curr_phrase, "of %s", curr_phrase );
      }
      // Check for shortcuts, whether they used him/her/it/them.
      if( member(pronouns, curr_phrase) && this_player() ) {
         mixed pron_list;
         pron_list = this_player()->query_pronoun();
         if( pointerp(pron_list) )
            ob_list += pron_list[pronouns[curr_phrase]];
         continue;
      }
      // "all" or "all of" is now stripped. Check for numeric phrases.
      wpos = member( curr_phrase, ' ' );
      // If there are at least two words, there may be a number giving
      // that we only want the nth object, or that we want n objects.
      // Check for either case.
      if( wpos >= 0 ) {
         string numstr;
         int numval;

         // If I have a direct article, use the word after it.
         if( lower_case(curr_phrase[..wpos-1]) == "the" ) {
            numstr = curr_phrase[wpos+1..member(curr_phrase[wpos+1..], ' ')+wpos];
            wpos += strlen(numstr) + 1;
         }
         else
         // Otherwise, use the first word in the phrase.
            numstr = curr_phrase[..wpos-1];

         // Now try to translate our numstr; if we succeed, set up flags.
         if( sscanf(numstr, "%d%s", numval, numstr) == 2 ) {
            if( numstr == "" )
               plural = 1;
            if( numstr == "st" || numstr == "nd" || numstr == "th" )
               plural = 0;
         }
         else if( numval = num_map[numstr] ) {
            if( numval > 0 ) plural = 1;
            else {
               numval = -numval;
               plural = 0;
            }
         }
         // If a valid numeric phrase was found,
         if( tcount = numval )
            curr_phrase = curr_phrase[wpos+1..];
      }
      else
         tcount = 0;

      ccount = 0;

      // Figure out if we have a [nearest|furthest|farthest] expression, and set the flag.
      near_flag = 0;
      if( sscanf(curr_phrase, "nearest %s", curr_phrase) == 1 ||
          sscanf(curr_phrase, "closest %s", curr_phrase) == 1 )
         near_flag = 1;
      else if( sscanf(curr_phrase, "furthest %s", curr_phrase) == 1 ||
         sscanf(curr_phrase, "farthest %s", curr_phrase) == 1 )
         near_flag = -1;

      // Ok, now we need to evaluate the <location> expression...

      curr_env = env;
      prep_phrase = regexplode( curr_phrase, PREP_EXP );
      for( iprep = sizeof(prep_phrase) - 1; curr_env && iprep > 1; iprep -= 2 ) {
         // Allow searches to jump to player environment
         if( this_player() && member(([ "ground", "the ground", "floor", "the floor" ]), trim(prep_phrase[iprep])) )
            curr_env = environment(this_player());
         else
            // Doesn't handle plural environments, btw (put two eggs in two bags doesn't work as expected)
            curr_env = single_present( trim(prep_phrase[iprep]), curr_env );
         // May wish to check that preposition relations match.
         // This is ignored atm, since no good mechanism exists
         // for this as I write this code...
      }
      if( curr_env ) curr_phrase = trim(prep_phrase[0]);
      else continue; // Object reference was invalid, throw it out.

      // If the phrase is 'all' or 'everything', use it! Since all was
      // stripped earlier, check in case there were side effects.
      if( curr_phrase == "everything" || curr_phrase == "all" || (curr_phrase == "" && plural && !tcount) )
         ob_list += filter(all_inventory(curr_env), obj_filter);
      ob_list -= ignored_obs;

      env_objs = filter(all_inventory(curr_env), obj_filter) - ignored_obs;

      // If we had a nearest/furthest expression, sort the objects by distance.
      if( near_flag && this_player() ) {
         int player_pos, ob_pos1, ob_pos2;
         player_pos = this_player()->query_coord();
         env_objs = sort_array( env_objs,
            (: ob_pos1 = $1->query_coord();
               ob_pos2 = $2->query_coord();
               if( $1->query_host() ) ob_pos1 += $1->query_host()->query_coord();
               if( $2->query_host() ) ob_pos2 += $2->query_host()->query_coord();
               ob_pos1 = abs(CX(ob_pos1) - CX(player_pos)) +
                  abs(CY(ob_pos1) - CY(player_pos)) +
                  abs(CZ(ob_pos1) - CZ(player_pos));
               ob_pos2 = abs(CX(ob_pos2) - CX(player_pos)) +
                  abs(CY(ob_pos2) - CY(player_pos)) +
                  abs(CZ(ob_pos2) - CZ(player_pos));
               return near_flag==1?(ob_pos1 > ob_pos2):(ob_pos1 < ob_pos2);
            :) );
      }

      // Now loop through all objects in env and try to find ones that match.
      // This has to take numbering into account (bleagh!)
      foreach( ob : env_objs )
      if( ind = ob->id(curr_phrase) ) {
         int q; // Object quantity

         // Counting rules
         if( objectp(ind) ) ob = ind;
         if( tcount ) {
            if( !(q = ob->query_quantity()) ) q = 1;
            if( ccount + q <= tcount && plural )
               ccount += q;
            else {
               if( !plural ) {
                  if( ccount + q < tcount )
                     ccount += q; // Counting through objects
                  else {
                     // Count lands in the middle of a plural object,
                     // or exactly on a single object.
                     ob->split_quantity( 1 );
                     ccount = tcount;
                  }
               }
               else {
                  // Plural quantity used
                  ob->split_quantity( tcount-ccount );
                  ccount = tcount;
               }
            }
            // Get n objects
            if( plural ) {
               ob_list += ({ ob });
               if( ccount >= tcount ) break;
            }
            else if( ccount == tcount ) {
               ob_list += ({ ob }) ;
               break;
            }
         }
         // Non-counting rules
         else {
            ob_list += ({ ob });
            if( !plural ) {
               if( ob->query_is_plural(curr_phrase) ) plural = 1;
               else {
                  if( ob->query_quantity() > 1 )
                     ob->split_quantity(1);
                  break;
               }
            }
         }
      }
   }

   if( !sizeof(ob_list) && this_player() && member(([ "ground", "the ground", "floor", "the floor" ]), trim(id)) ) {
      return ({ environment(this_player()) });
   }

   if( sizeof(ob_list) )
      return ob_list;
   return 0;
}

/** Return an english word approximating the number x
 */
string rough_amount( int x ) {
   string amount;

   switch( x ) {
   case 5..6:
      amount = "a few";
      break;
   case 7..11:
      amount = "several";
      break;
   case 12..22:
      amount = "a bunch of";
      break;
   case 23..39:
      amount = "plenty of";
      break;
   case 40..89:
      amount = "lots of";
      break;
   case 90..299:
      amount = "scores of";
      break;
   case 300..949:
      amount = "heaps of";
      break;
   case 950..3999:
      amount = "loads of";
      break;
   case 4000..9999:
      amount = "a staggering amount of";
      break;
   default:
      amount = "/daemon/dictionary"->get_string_from_number(x);
   }
   if ( x > 9999 )
      amount = "a ridiculous amount of";

   return amount;
}

/** Returns a prettified string giving the array of objects passed
 * in as a comma seperated list. This checks for both recognition
 * (using name instead of distant) and duplicates (three wolves
 * instead of a wolf, a wolf, and a wolf).
 */
string inventory_string( object *oblist ) {
   string *namelist;
   int iname, idups, ibase, ndups, k;

//   namelist = map( oblist,
//   (:
//      string n;
//      n = $1->query_name();
//      if( $1->query_is_living() && this_player()->query_recognize(n) ) return capitalize(n);
//      else return $1->query_distant();
//   :) );
   namelist = map( oblist, (: $1->query_distant() :) );

   // Remove duplicates, replace with plural notation.
   for( iname = 0; iname < sizeof(namelist); iname++ ) {
      //if( oblist[iname]->query_quantity() > 1 || !stringp(namelist[iname]) )
      if( !stringp(namelist[iname]) )
         continue;
      ibase = idups = iname;
      ndups = 1;
      while( (k = member(namelist[idups+1..], namelist[ibase]) + idups + 1) > idups ) {
         idups = k;
         namelist[idups] = 0;
         ndups++;
      }
      // give rough amounts
      if( ndups > 1 && oblist[iname]->query_quantity() <= 1 )
         namelist[iname] = rough_amount( ndups ) + " " + oblist[iname]->query_plural();
      else if( ndups > 1 && oblist[iname]->query_quantity() > 1 )
         namelist[iname] = rough_amount( ndups ) + " piles of " + oblist[iname]->query_distant();
   }
   namelist -= ({ 0 });

   return comma_list(namelist);
}



/****************************************************************************
 *                               INTERFACES                                 *
 ****************************************************************************/

/** Adds an interface to this_player().
 * \param name The function used for the interface. Prefix "@" to
 * the function name if you want a character-by-character interface.
 * \param prompt (Not needed for char-by-char) The prompt printed
 * to the player.
 */
varargs void add_interface(string name, string prompt) {
   object player;

   player = this_player()->query_possessor();
   if( !player ) player = this_player();

   if( name[0] != '@' )
      player->_interface_add(name, prompt, previous_object());
   else
      player->_interface_single_char(name[1..strlen(name)-1], previous_object());
}

/** Shifts this_player()'s interface to an alternative handler. This
 * is used to transfer control from one interface to another. It is
 * the same as drop_interface() followed by an add_interface(), except
 * that the prompts will be handled correctly (if you do a drop
 * followed immediately by an add, you get strange prompt spam).
 */
varargs void shift_interface(string name, string prompt) {
   object player;

   player = this_player()->query_possessor();
   if( !player ) player = this_player();

   if( name[0] != '@' )
      player->_interface_shift(name, prompt, previous_object());
   else
      player->_interface_shift_single_char(name[1..strlen(name)-1], previous_object());
}

/** Drops this_player()'s current interface, reverting to the previous one.
 * Interfaces are stackable.
 */
void drop_interface() {
   object player;

   player = this_player()->query_possessor();
   if( !player ) player = this_player();

   player->_interface_drop();
}

/** Designates a function to handle text received by this_player() while the
 * current interface is active. This does not effect text printed by the
 * interface object itself. Be warned, this is a little difficult to
 * do well. See Textdraw for useful functions for handling catch terminals,
 * and Fulledit for an example.
 */
void set_interface_catch( int enable ) {
   object player;

   player = this_player()->query_possessor();
   if( !player ) player = this_player();

   player->_interface_set_catch( enable );
}

/****************************************************************************
 *                              STRING TYPING                               *
 ****************************************************************************/

/*
 * The functions here are used to simplify some of the problems of data
 * typing. Basically it allows you to enter a data constant the same way
 * you would in LPC, but on the command line. These functions will let you
 * take whatever was entered on the command line and convert it to the
 * correct data type. The to_xxx functions take a string as a parameter
 * and return the correct value. They return 0 if the conversion fails
 * (see special note for to_int) The from_xxx functions take the data type
 * in question and convert it to a string representation. In most cases,
 * the two are interchangable ... i.e. to_xxx(from_xxx(x)) returns x.
 */

/** Used by query_to_int_fail() */
nosave private int int_fail_flag;

/** Returns true if the previous call to to_int failed. */
int query_to_int_fail() {
   return int_fail_flag;
}

/** Converts an integer or a string to an integer.
 * \return The integer extracted from "num."
 * \note This function does return 0 on failure, but if you pass it
 * "0" then it will return 0 even if it is a success. The only way to
 * be sure is to call the query_to_int_fail() function, which will return 1
 * if the previous call to to_int failed.
 */
int to_int(mixed num) {
   int i;

   int_fail_flag = 0;
   if( stringp(num) ) {
      if(sscanf(num, "%d", i) == 1)
         return i;
      else
         int_fail_flag = 1;
   }
   else return efun::to_int(num);
}

/** Converts any data type to a string. Even works
 * for arrays and mappings!
 */
string as_string(mixed s) {
   if( stringp(s) ) return s;
   if( intp(s) || floatp(s)) return "" + s;
   if( objectp(s) ) return object_name(s);
   if( mappingp(s) || pointerp(s) ) return sprintf("%O", s);
   if( symbolp(s) ) return to_string(s);
   if( closurep(s) ) return to_string(s);
   return "<unsupported data-type>";
}

/** Removes control codes from a string, excepting \\n and \\r. This function is
 * optimized quite heavily, so may be used on larger strings. The purpose of this
 * function is to take a string containing unknown characters (such as the contents
 * of a file) and allow you to send it to a terminal without side effects. I created
 * this function when I found out certain of the codes stored in player files were
 * attempting to trigger my terminal's ZModem download capabilities.
 */
string cleanup_string(string str) {
   int i, n;

   n = strlen(str);
   for( i = 0; i < n; i++ )
      str[i] = valid_chars[str[i] & 0xFF];

   return str;
}

/** Returns true if \a fname is a legal filename. This does not imply
 * that the file exists, only that the filename being requested is
 * syntactically legal. Not all possible UNIX-legal filenames will be
 * considered legal by this function, but every filename considered legal
 * by this function is legal in UNIX as well. Note that ".." is not allowed --
 * You may wish to call /obj/player->make_path_absolute() first if you
 * want to support relative paths like that.
 */
int legal_filename(string fname) {
   if( !stringp(fname) || strlen(fname) == 0 ) return 0;
   // Only legal characters ... there are probably others, but these will do most of the time.
   if( sizeof(regexplode(fname, "[^-A-Za-z0-9_./~{}%;]")) > 1 ) return 0;
   // Modify the string slightly to make parsing a little easier.
   fname = fname + "\n";
   if( fname[0] != '/' ) fname = "/" + fname;
   // A few possibilities for an illegal string.
   // I think this covers all cases?
   if( strstr(fname, "//") >= 0 ||
       strstr(fname, "/./") >= 0 ||
       strstr(fname, "/.\n") >= 0 ||
       strstr(fname, "..") >= 0 ) return 0;

   // All tests pass.
   return 1;
}

/* A bugfix for strstr, on some version of the dev driver.
 * Should no longer be necessary...
 */
//varargs int strstr( string str1, string str2, int pos ) {
//   int i;
//
//   i = efun::strstr( str1, str2, pos );
//   if( i < strlen(str1) ) return i;
//   else return -1;
//}

/** Determines whether there is a living object blocking \a actor
 * from manipulating \a env. For example, this will return true for
 * a player who wants to get an apple from a box, but false for a player
 * who wants to get an apple from someone else's inventory. It will
 * also return false for an object in another room, or inside a
 * closed container (query_closed() returns true).
 */
int valid_manipulate( object actor, object env ) {
   object actenv;

   actenv = environment(actor);
   if( !env ) return 0;
   while( env = environment(env) ) {
      if( env == actor || env == actenv ) return 1;
      if( env->query_is_living() || env->query_closed() ) return 0;
   }
   return 0;
}


/** \return True if the file given by 'path' exists. This function
 * will return false if \a path represents a directory.
 * \param path The name of the file whose existence you wish to check.
 */
int file_exists( string path ) {
   if( (legal_filename(path)) &&
       (sizeof(get_dir(path)) > 0) &&
       (file_size(path)) >= 0 )
      return 1;
   return 0;
}

/****************************************************************************
 *                             ACCESSING FILES                              *
 ****************************************************************************/

/** Queries whether an object has access to read a file/directory.
 * Returns true if access is allowed. See also query_write_access.
 * Does not check for file existence.
 * \param file Full path to the file/directory to read.
 * \param whose Which object will perform the read. this_object() if not
 * specified.
 */
varargs int query_read_access( string file, object whose ) {
   if( !whose ) whose = previous_object();
   if( !legal_filename(file) ) return 0;
   if( file_size(file) == -2 && file[<1] != '/' ) file += "/";
   return MASTER->valid_read(file, getuid(whose), "read_file", whose);
}

/** Queries whether an object has write access to a file/directory.
 * Returns true if access would be allowed. If you do not have access,
 * then attempting access generates an error. This allows you to
 * check for the error conditions before they happen. If the file/directory
 * does not exist, returns true if you would be allowed to create it.
 * \param file Full path to the file/directory you want to write.
 * \param whose Which object will be writing to the file. If not
 * specified, this_object() is assumed.
 */
varargs int query_write_access( string file, object whose ) {
   if( !whose ) whose = previous_object();
   if( !legal_filename(file) ) return 0;
   if( file_size(file) == -2 && file[<1] != '/' ) file += "/";
   return MASTER->valid_write(file, getuid(whose), "write_file", whose);
}

/** This function uses this_player()'s editor (a clone of the object
 * given as a filename in the editor environment variable) to edit the
 * string passed in as data (editors should handle being passed a 0
 * for data, in which case they should start with a blank string).
 * As soon as the editor has finished editing the string in question,
 * it will be passed back as a parameter to \a func in the calling
 * object.
 * \param func The function in your object that will be called when
 * editing is finished.
 * \param data The initial value for the variable being edited.
 * \todo Not implemented yet.
 */
void string_edit( string func, string data ) {

}

/** Allows you to set a description variable. By convention,
 * description variables are all UPPER CASE, but this is
 * not enforced. See eval_desc_var() for possible things
 * you can set them to. You may delete variables from the
 * desc_vars mapping by setting them to 0.
 * \param var The name of the description variable
 * \param val The value for the description variable -- int, string, array, or closure.
 */
void set_global_desc_var( string var, mixed val ) {
   if( val == 0 )
      m_delete( desc_vars, var );
   else
      desc_vars[var] = val;
}

/// A debugging function.
mixed query_global_desc_var( string var ) {
   return desc_vars[var];
}

/** Looks up the description variable recorded for \a var.
 * If \a var does not exist, false (0) will be returned.
 * Otherwise, the behavior will depend on the datatype of \a var:
 *  - int: The integer will be converted to a string and returned.
 *  - string: The string is returned.
 *  - closure: The closure is evaluated, and its value is returned.
 *    You may pass a single string parameter to the closure by including it
 *    in parentheses as part of \a var, i.e. "OBJECT(small dog)". If you
 *    pass arguments to any other datatype, it will be ignored.
 *  - array of strings: A random string from the array is returned.
 * Invalid datatypes will return the string "<inval:varname>"
 * with varname giving the value of \a var.
 */
protected string eval_desc_var( string var, object env ) {
   mixed val;
   string param = 0;

   // Check for parameters.
   sscanf( var, "%s(%s)%~s", var, param );
   val = desc_vars[var];
   if( !val && env ) val = env->query_desc_var( var );

   if( !val ) return 0;
   if( stringp(val) ) return val;
   if( intp(val) ) return "" + val;
   if( closurep(val) ) return funcall( val, env, param );
   if( pointerp(val) ) return val[random(sizeof(val))];
   return "<inval:"+var+">";
}

/** Used by eval_exp() and others to find matching
 * parentheses -- a simple sscanf is insufficient,
 * since it doesn't handle nesting properly.
 */
protected string *split_exp( string exp ) {
   int i, n, iopen, iclose, par_count;

   n = strlen(exp);
   // Loop until we find the first open parenthesis.
   for( i = 0; i < n && exp[i] != '('; i++ );
   iopen = i;
   par_count = 0;
   for( ; i < n; i++ ) {
      if( exp[i] == '(' ) par_count++;
      if( exp[i] == ')' ) par_count--;
      if( !par_count ) break;
   }
   iclose = i;
   return ({ exp[..iopen - 2], exp[iopen - 1..iclose], exp[iclose+1..] });
}


/** Used by eval_exp() to evaluate conditional expressions
 * of the form ?(...), with the ? and () already stripped.
 */
protected string eval_cond_exp( string exp, object env ) {
   string statement, *slist, result;
   mixed var;
   int use_or, hit;

   desc_vars["_LASTCOND"] = 0;
//   write("eval_cond_exp("+exp+")\n");
   if( sscanf(exp, "%s:%s", statement, result) != 2 ) return "?<missing colon>";
   slist = explode( statement, "," );
   foreach( statement: slist ) {
      statement = trim(statement);
      if( statement[0] == '|' ) {
         statement = statement[1..];
         use_or = 1;
      }
      else use_or = 0;
      if( statement[0] == '!' ) {
         if( eval_desc_var(statement[1..], env) ) { if( !use_or ) return ""; }
         else { hit = 1; if( use_or ) break; }
      }
      else {
         if( !eval_desc_var(statement, env) ) { if( !use_or ) return ""; }
         else { hit = 1; if( use_or ) break; }
      }
   }
   if( !hit ) return "";

   statement = eval_exp( result, env );
   desc_vars["_LASTCOND"] = 1;
   return statement;
}

/** Evaluates a conditional description. This is a recursive
 * descent parser, so statements may be embedded within other
 * statements. This is a (simple) sample statement:
 *
 * The weather is ?(SUNNY:sunny)?(!SUNNY:not sunny).
 *
 * This reads the value of SUNNY (a description variable,
 * see set_global_desc_var()); if it is true (set), then the
 * statement evalutes to "sunny", otherwise it evaluates
 * to "not sunny". Here is a quick syntax rundown:
 *
 * ?(CONDITON_LIST:true result) -- where
 * CONDITION_LIST is a comma separated list of conditions which
 * are evaluated using a short-circuit boolean AND. If all the
 * conditions are true, then the "true result" string is returned,
 * otherwise the empy string is returned. Conditions
 * are of the form [!]COND[(args)], where args is any string (though
 * it may not have parentheses () or commas , in it).
 * Note that the true_result and false_result strings will
 * also be run through eval_exp, so they may contain
 * nested expressions.
 *
 * There is a shorthand for 'else' statements. Whenever an expression
 * is evaluated, it sets the _LASTCOND variable to 1 (if the evaluation
 * succeeded) or 0 (if it did not). You can enter
 *
 * :(any expression here)
 *
 * as a shorthand for
 *
 * ?(!_LASTCOND:any expression here)
 *
 * This is generally faster than re-evaluating the expression, and is
 * a huge help if the original expression is complex and hard to invert.
 *
 * Another useful addition is the possibility of using an "OR" marker.
 * To do this, simply prefix a '|' (pipe character) to the front of
 * your expression, like this:
 *
 * ?(|SUNNY, |!RAINY:exp)
 *
 * exp is used if SUNNY is true *or* if RAINY is false. Note that the
 * OR '|' symbol must appear before the NOT '!' symbol. Mixing normal and
 * OR variables is pointless; the OR variables will be ignored.
 *
 * ,(item1[\nitem2[\nitem3..]]) -- returns a comma-separated
 * list. See comma_list().
 *
 * $(VAR) -- returns the evaluated value (see eval_desc_var())
 */
varargs string eval_exp( string exp, object env ) {
   string *split;

   if( !stringp(exp) || strlen(exp) < 3 ) return exp;
   // Clip and evaluate
   split = split_exp( exp );
   if( strlen(split[1]) > 3 ) {
      // This is a clipped expression. See if it is valid.
      switch( split[1][0] ) {
         case '?': return split[0] + eval_cond_exp( split[1][2..<2], env ) + eval_exp( split[2], env );
         case ':': if( !desc_vars["_LASTCOND"] )
                      return split[0] + eval_exp( split[1][2..<2], env ) + eval_exp( split[2], env );
                   else
                      return split[0] + eval_exp( split[2], env );
         case ',': return split[0] + comma_list( split[1][2..<2] ) + eval_exp( split[2], env );
         case '$': return split[0] + eval_exp( eval_desc_var(split[1][2..<2], env), env ) + eval_exp( split[2], env );
         default: return split[0] + split[1][0..1] + eval_exp( split[1][2..] + split[2], env );
      }
   }
   else {
      return split[0] + split[1] + eval_exp( split[2], env );
   }
}

/** A simple function to send an instant message to a wizard. An instant
 * message will reach the wizard either immediately (if they are logged
 * on) or as soon as they log on again. The message is sent from
 * this_player().
 *
 * \param name The name of the recipient. If they are not online, it will
 * be sent to the mailbox of the same name.
 *
 * \return True on success. Currently always returns true, as the instant
 * messenger functions have no fail conditions.
 */
int send_im( string name, string message ) {
   "/secure/mail_daemon"->mail_send_im( name, this_player()->query_name(), message );
   return 1;
}

/** Similar to the as_string function, with the difference that this
 * one's strings can be converted back into code when you're done.
 * For example, if you have this string:
 *
 * "The clown looks at you closely.\n\"Can you see me?\" says the clown."
 *
 * ... then the as_string will actually have a newline and quotes
 * in the string, which would cause code errors if you tried to compile.
 * This function will convert any datatype into a string constant that,
 * if inserted in LP/C code, will give back *the same value as the
 * original datatype* and not cause errors. The other difference between
 * this and as_string is that this one is MUCH slower.
 *
 * Note that this function does not work with closures.
 *
 * \todo This function will currently recurse forever if passed a
 * recursive array or mapping (a fool thing to do in any case). I'd
 * rather it did something intelligent, such as fill in recursing
 * arrays or mappings with "<RECURSE>" or something.
 *
 * If you pass in true for the optional \a simple flag, it will give
 * you a less decorated display of arrays and mappings (unindented,
 * no comments).
 */
varargs mixed as_lpc( mixed var, int simple ) {
   int i;

   if( stringp(var) ) {
      var = implode( explode( var, "\n" ), "\\n" );
      var = implode( explode( var, "\"" ), "\\\"" );
      for( i = 0; i < strlen(var); i++ ) {
         if( var[i] < 32 || var[i] > 126 ) {
            if( i < strlen(var) - 1 && var[i+1] >= '0' && var[i+1] <= '9' )
               var[i..i] = "\\" + var[i] + "\"+\"";
            else
               var[i..i] = "\\" + ((var[i] + 256) % 256);
         }
      }
      return "\"" + var + "\"";
   }
   else if( pointerp(var) ) {
      string arr_val;

      if( simple )
         arr_val = "({ ";
      else
         arr_val = "({ /* Converted Array, Length = " + sizeof(var) + " */\n";

      if( simple ) {
         for( i = 0; i < sizeof(var); i++ )
            arr_val += (i==0?"":", ") + as_lpc(var[i], 1);
         arr_val += " })";
      }
      else {
         for( i = 0; i < sizeof(var); i++ )
            arr_val += "  " + implode( explode(as_lpc(var[i]), "\n"), "\n  ") + (i!=sizeof(var)-1?",":"") + "\n";
         arr_val += "})";
      }
      return arr_val;
   }
   if( mappingp(var) ) {
      int w, first;
      string map_val, key;

      w = widthof(var);

      if( simple )
         map_val = "([ ";
      else
         map_val = "([ /* Converted Mapping, Length = " + sizeof(var) + ", Width = " + w + " */\n";
      first = 1;
      foreach( key : var ) {
         if( first )
            first = 0;
         else
            map_val += "," + (simple?" ":"\n");
         if( simple )
            map_val += as_lpc(key, 1);
         else
            map_val += "  " + implode( explode(as_lpc(key), "\n"), "\n  ");
         if( w ) {
            map_val += ": ";
            for( i = 0; i < w; i++ )
            if( simple )
               map_val += as_lpc(var[key,i], 1) + (i!=w-1?"; ":"");
            else
               map_val += implode( explode(as_lpc(var[key,i]), "\n"), "\n  ") + (i!=w-1?"; ":"");
         }
      }
      map_val += simple?" ])":"])";
      return map_val;
   }
   if( objectp(var) ) {
      return "find_object( \"" + object_name( var ) + "\" )";
   }
   if( symbolp(var) ) {
      return "quote(\"" + as_string(var) + "\")";
   }
   if( floatp(var) ) {
      var = sprintf( "%O", var );
      if( member(var, '.') < 0 ) return var + ".0";
      return var;
   }

   return as_string(var);
}

mixed reversible_to_string( mixed var ) {
   debug("reversible_to_string called, should be as_lpc (just rename the function). In "+as_string(previous_object()));
   return as_lpc(var);
}

/** Returns an object pointer for the room/object referenced
 * by addr. The room references are in a semicolon
 * separated format, such as ;reality;westcontinent;castle;room92;sword.
 * This also recognizes the keywords "world" and "env", and
 * can handle relative references when \a startpoint is
 * specified.
 *
 * \param addr The semicolon delimited list for the object
 * you are referencing.
 * \param startpoint (Optional) An object pointer from which
 * to start relative references. For players, the startpoint
 * is themself. For rooms, the startpoint is the room itself.
 */
varargs object find_room(string addr, object startpoint) {
   object container, newcon;
   string currname;

   container = find_object("world/world");
   if(!container || !addr) return 0;

   if(addr == "world") return container;
   if(startpoint) container = startpoint;
   if(addr[0] == ';') {
      addr = addr[1..];
      container = find_object("world/world");
   }

   while(addr) {
      if(sscanf(addr, "%s;%s", currname, addr) != 2) {
         currname = addr;
         addr = 0;
      }

      newcon = container->get_room_ob( currname );
      if( !newcon ) newcon = present( currname, container );
      if(!newcon && currname == "env") newcon=environment( container );
//      if(!newcon && environment(container)) newcon = present( currname, environment(container) );
      if(!newcon && currname == "world") newcon=find_object( "world/world" );
      container = newcon;
      if(!container) return 0;
   }

   return container;
}

object *all_clones( mixed base ) {
   object master, *clist;
   mapping orphans;
   string mname;

   if( objectp(base) ) master = base;
   else if( stringp(base) ) master = find_object(base);
   else raise_error( "Invalid data-type for base in all_clones() -- expected object/string" );
   if( master ) {
      clist = clones(master);
      mname = load_name(master);
   }
   else {
      clist = ({ });
      mname = base;
   }
   if( find_object("/daemon/uptodate") ) {
      orphans = "/daemon/uptodate"->query_orphans();
      if( mappingp(orphans) && member(orphans, mname) )
         clist += orphans[mname];
   }
   return clist;
}

object find_objectref( symbol ref ) {
   string obname;
   int obid;
   object ob, iob;
   mapping vartab, obtab = ([ ]);

   if( stringp(ref) ) ref = quote(ref);
   if( !symbolp(ref) ) return 0;

   if( sscanf(unquote(ref), "%s|%d", obname, obid) != 2 ) return 0;
   ob = find_object( obname );
   if( ob ) {
      vartab = ob->query_vars();
      if( !vartab ) return 0; // Should never happen, but...
      if( mappingp(obtab = vartab["_obtab"]) ) {
         if( iob = obtab[obid] ) return iob; // Fastest possible lookup: O(1) to here.
         else m_delete( obtab, obid ); // Cleanup if object was destructed...
      }
      else {
         ob->set_var( "_obtab", obtab = ([ ]) );
      }
   }

   // Slow lookup: O(n) on # of clones; result is cached.
   foreach( iob : all_clones(obname) )
   if( iob->query_unique_id() == obid ) {
      obtab[obid] = iob;
      return iob;
   }
   // Failed to find that object reference.
   return 0;
}

symbol to_objectref( object ob ) {
   if( !objectp(ob) ) return 0;
   return quote(load_name(ob) + "|" + ob->query_unique_id());
}

/** Hopefully patch the hole left by the command() efun.
 */
varargs nomask int command( string comm, object dest ) {
   if( !dest ) dest = previous_object();
   if( !dest ) return 0;
   if( load_name(dest) == "/obj/player" && getuid(previous_object()) != "root" && previous_object() != dest && dest != this_player() )
      return 0;
   return efun::command( comm, dest );
}

/** A replacement for the present() efun. The primary difference
 * is that this one respects the returning of an object from id()
 * as a method of redirection.
 */
varargs object present( mixed str, object env ) {
   object ob;
   mixed ret;

   if( !objectp(env) ) return 0;

   if( objectp(str) )
   if( env )
      return efun::present( str, env );
   else
      return efun::present( str );

   foreach( ob : all_inventory(env) )
      if( ret = ob->id(str) ) {
         if( objectp(ret) ) return ret;
         return ob;
      }
   return 0;
}

/** Allows you to get a *single* object, but with all the parsing
 * that all_present allows. In essence, it uses all_present, then
 * gives back the first thing.
 *
 * The \a env parameter is required, and specifies which object
 * should be searched.
 */
varargs object single_present( string str, object env, mixed obj_filter ) {
   object *list;

   list = all_present( str, env, obj_filter );
   if( !list ) return 0;
   return list[0];
}

#define PATH_GIVEUP 800

/** Returns the shortest path from point (startx,starty) to point
 * (goalx,goaly) in wswwnwwwsse form. The A* algorithm is used
 * with Manhattan distance used as a minimum cost heuristic.
 * This code is fairly efficient.
 *
 * \param map The map, as a \\n delimited string. The map will be
 * processed into lines, and each line will be made the same width
 * by adding \\27 (escape) characters onto the end of each line --
 * it would therefore be ideal if you did not use escapes as a
 * walkable character. Note that the format is a little different
 * if you specify \a map_width -- it will then assume that the map
 * is an even, square grid.
 * \param startx The x coordinate at which you begin searching.
 * \param starty The y coordinate at which you begin searching.
 * \param goalx The x coordinate you wish to reach
 * \param goaly The y coordinate you wish to reach
 * \param costs A mapping of character to cost. Characters
 * not appearing in the mapping are presumed solid.
 * \param map_width (Optional) The width of the grid given in
 * \a map. If not given, then a \\n delimited map is assumed.
 * If the grid isn't a perfect rectangle, the short line
 * at the end is thrown away.
 *
 * Allaryin wishes it to be abundantly clear that he had nothing to do with
 * this code, and wants you to blame me (Acius) instead.
 */
varargs string find_path( string map, int startx, int starty, int goalx, int goaly, mapping costs, int map_width ) {
   // Count towards giving up.
   int cycles = 0;

   // split_map will be an array of equal-length
   //strings (will pad spaces to assure this)
   string *split_map;

   // i is for generic loops, map_width is width
   // of split_map, goal is the destination point
   // (All coordinates are stored as x + y *
   // width). currpos is where the algorithm is
   // looking, currcost is cost at currpos, newx,
   // newy, newpos, and newcost are temps for
   // figuring out where to look next.
   int i, start, goal, currpos, currcost, newx, newy, newpos, newcost;

   int ineighbor, iparent, iheap;

   // closed is mapping from (int)coordinate:
   // (int) cost & direction. Note that costs
   // > 2^28 will cause undetected overflow
   // problems -- if you keep costs reasonable,
   // you shouldn't have a problem.
   mapping closed;

   // The open list, stored as a heap.
   // Even-numbered elements hold coordinate information,
   // odd-numbered ones give the cost for the previous
   // even numbered coordinate. Kind of a squinky heap
   // hack, and the indexing is a nightmare, but LPC
   // doesn't have a structure type, and I don't want
   // the overhead of using a mapping or array for
   // individual elements.
   int *open;
   string path;

   mixed tmp;

   // Assume a \n delimited map.
   if( map_width == 0 ) {
      // Process the map into an easier-to-use format.
      split_map = explode( map, "\n" );
      map_width = 0;

      // Find the length of the longest line in the "map"
      for( i = sizeof(split_map); i-- ; )
         if( map_width < strlen(split_map[i]) ) map_width = strlen(split_map[i]);

      // Make all the lines that length by padding with escape characters.
      // (Note: I use escapes because they are an unlikely character to be
      // chosen for walking over, and unused characters are 'walls'). This uses
      // a rather odd technique involving sprintf, similar to the way tab()
      // works.
      for( i = sizeof(split_map); i-- ; )
         split_map[i] += sprintf( "%" + (map_width-strlen(split_map[i])) + "'\27's", "" );
   }
   // Split the map on even grid lines.
   else {
      split_map = allocate( strlen(map) / map_width );
      for( i = 0; i < sizeof(split_map); i ++ )
         split_map[i] = map[i*map_width..(i+1)*map_width-1];
   }

   // Sanity check
   if( goalx < 0  || goalx >= map_width || goaly < 0 || goaly >= sizeof(split_map) )
      return 0;
   // Setup initial state.
   start = startx + starty * map_width;
   goal = goalx + goaly * map_width;
   open = ({ (abs(startx-goalx) + abs(starty-goaly)) << 2, start });
   closed = ([ start:0 ]);

   while( sizeof(open) && !member(closed, goal) ) {
      cycles++;
      if( cycles >= PATH_GIVEUP )
         return 0;
      currcost = open[0];
      currpos = open[1];
      // Check if done.
      if( currpos == goal ) {
         closed[currpos] = currcost;
         break;
      }

      // Pop the top cell off the heap.
      // Copy the final element over the top one...
      open[0] = open[<2];
      open[1] = open[<1];
      // Clip off the final element...
      open = open[0..<3];
      // Set an index at the top for bubble down
      iparent = 0;
      iheap = 2;
      // Bubble down. iparent is the parent node, iheap
      // is the left of the two child nodes.
      while( iheap < sizeof(open) ) {
         // If left child should be bubbled up
         if( open[iparent] > open[iheap] && (iheap + 2 >= sizeof(open) || open[iheap] < open[iheap + 2]) ) {
            tmp = open[iparent..iparent+1];
            open[iparent..iparent + 1] = open[iheap..iheap + 1];
            open[iheap..iheap + 1] = tmp;
         }
         // else if right child should be bubbled up
         else {
            iheap += 2;
            if( iheap < sizeof(open) && open[iparent] > open[iheap] ) {
               tmp = open[iparent..iparent+1];
               open[iparent..iparent + 1] = open[iheap..iheap + 1];
               open[iheap..iheap + 1] = tmp;
            }
            // Didn't need to bubble either child, quit looping.
            else break;
         }
         // Slide 'em down the heap.
         iparent = iheap;
         iheap = (iparent + 1) << 1;
      }

      // Add the neighbors of the popped cell to the heap
      // 0 = east, 1 = north, 2 = west, 3 = south
      for( ineighbor = 0; ineighbor < 4; ineighbor++ ) {
         // Calculate x, y coords of the about-to-be-considered cell.
         newx = (currpos % map_width) + ({ 1, 0, -1, 0 })[ineighbor];
         newy = (currpos / map_width) + ({ 0, -1, 0, 1 })[ineighbor];
         // Costs encode the direction into the least significant bits.
         newcost = ({ 0x0, 0x1, 0x2, 0x3 })[ineighbor];
         // Out of bounds, ignore it.
         if( newx < 0 || newx >= map_width || newy < 0 || newy >= sizeof(split_map) )
            continue;
         newpos = newx + newy * map_width;
         // Solid wall, ignore it. Make an exception for the goal (which may be solid).
         if( !member(costs, split_map[newy][newx]) && newpos != goal ) continue;
         // Already checked, ignore it.
         if( member(closed, newpos) ) continue;
         // Ok, it's legit. Add it to the heap:
         // The new cost is the old cost, plus the current tile cost. The Manhattan
         // distance to the goal is also included, by subtracting the old distance
         // (the -=) and adding the new distance (the +=).
         newcost |= (currcost & 0xFFFC) + (costs[split_map[newy][newx]] << 2);
         newcost -= (abs(goalx - currpos % map_width) + abs(goaly - currpos / map_width)) << 2;
         newcost += (abs(goalx - newx) + abs(goaly - newy)) << 2;
         // Mark this cell as 'considered'
         closed[newpos] = newcost;
         iheap = sizeof(open);
         // Tack it on the end, and prepare to bubble up.
         open += ({ newcost, newpos });
         if( iheap > 0 )
         // While iheap's parent is greater than the child, bubble up.
         // Note: &-2 drops odd numbers to the next lowest even number.
         while( iheap > 0 && open[iparent = ((iheap >> 1) - 1) & -2] > open[iheap] ) {
            // Set iheap to left child
            iheap = (iparent + 1) << 1;
            // If there is a right child, and if the right child is
            // the smaller of the two, shift iheap to the right child.
            if( iheap + 2 < sizeof(open) && open[iheap + 2] < open[iheap] )
               iheap += 2;
            // iheap now points to the smaller of the two children. Move it
            // up.
            tmp = open[iparent..iparent+1];
            open[iparent..iparent+1] = open[iheap..iheap+1];
            open[iheap..iheap+1] = tmp;
            iheap = iparent;
         }
      }
   }
   i = goal;
   if( !member(closed, i) ) return 0;
   path = "";
   while( i != start ) {
      path = ({ "e", "n", "w", "s" })[closed[i]&0x3] + path;
      i += ({ -1, map_width, 1, -map_width })[closed[i]&0x3];
   }
   return path;
}

/** \return If the total weight of all the objects in \a oblist
 * is less than weight, it will return a copy of \a oblist.
 * Otherwise, it will return as many of the objects as will fit
 * within the weight limit given. If no objects fit, an empty
 * array is returned (Not a perfect 0:1 knapsack solution, btw,
 * just a useful approximation). Note that it will also attempt
 * to split quantity objects.
 */
object *limit_weight( object *oblist, int weight ) {
   object ob;
   object *new_list;
   int tot, curr;

   new_list = ({ });
   tot = 0;
   foreach( ob : oblist ) {
      curr = ob->query_total_weight();
      if( curr + tot <= weight ) {
         new_list += ({ ob });
         tot += curr;
         continue;
      }
      if( ob->query_quantity() > 1 ) {
         int allowed_quantity;
         // Overflow compensation
         if( ob->query_weight() > 1000000 )
            allowed_quantity = weight / (ob->query_weight() / ob->query_quantity());
         else
            allowed_quantity = (weight * 1000) / (ob->query_weight() * 1000 / ob->query_quantity());

         if( allowed_quantity <= 0 ) continue;
         ob->split_quantity( allowed_quantity );
         new_list += ({ ob });
         tot += ob->query_weight();
      }
   }

   if( !sizeof(new_list) ) return 0;
   return new_list;
}

/** See limit_weight(). Does the same thing for bulk.
 */
object *limit_bulk( object *oblist, int bulk ) {
   object ob;
   object *new_list;
   int tot, curr;

   new_list = ({ });
   tot = 0;
   foreach( ob : oblist ) {
      curr = ob->query_bulk();
      if( curr + tot <= bulk ) {
         new_list += ({ ob });
         tot += curr;
         continue;
      }
      if( ob->query_quantity() > 1 ) {
         int allowed_quantity;

         // Overflow compensation
         if( ob->query_bulk() > 1000000 )
            allowed_quantity = bulk / (ob->query_bulk() / ob->query_quantity());
         else
            allowed_quantity = (bulk * 1000) / (ob->query_bulk() * 1000 / ob->query_quantity());

         if( allowed_quantity <= 0 ) continue;
         ob->split_quantity( allowed_quantity );
         new_list += ({ ob });
         tot += ob->query_bulk();
      }
   }

   if( !sizeof(new_list) ) return 0;
   return new_list;
}

/** Call this to completely refresh display state for
 * ob; does nothing if ob is not using the wclient.
 * Updates map and objects on the map for ob. Useful if
 * ob moves to a new room, for example.
 */
void refresh_full( object ob ) {
   if( ob->query_client_code() == "wclient" ) {
      efun::command( "_wmap", ob );
   }
}

/** Call this to completely refresh object overlays for
 * ob; does nothing if ob is not using the wclient.
 * Updates object overlay for ob. Useful if ob has
 * done something to itself and wishes to see the results,
 * but doesn't need a full refresh.
 */
void refresh_overlay( object ob ) {
   if( ob->query_client_code() == "wclient" ) {
      efun::command( "_wfovr", ob );
   }
}

/** Use this to inform all the objects inside room that
 * the object 'actor' has changed. If actor is null (or
 * not specified) then a full object refresh is done for
 * all of the room's occupants. Only actually effects
 * objects in the room with a wclient. The object actor itself
 * will NOT be refreshed, so use a different refresh
 * call to handle that if necessary.
 */
varargs void refresh_room( object room, object actor ) {
   object ob;
   if( !objectp(room) ) return;
   foreach( ob : filter(all_inventory(room), (: $1->query_client_code() == "wclient" :)) )
      efun::command( "_wfovr", ob );
}

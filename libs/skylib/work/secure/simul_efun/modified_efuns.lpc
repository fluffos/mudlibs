
#define MAX_SIZE 50000
#define LOG_NAME(X) ((X[0] == '/') ? X : "/log/"+X)
// This define figures out the filename to log to.

#include <config.h>
#include <type.h>

#if !efun_defined(base_name)
inherit "/secure/simul_efun/base_name";
#endif
#if !efun_defined(reference_allowed)
inherit "/secure/simul_efun/reference_allowed";
#endif

string back_trace();

#if !efun_defined(event)
void event(mixed,string,mixed ...);
#endif

#if !efun_defined(add_action)
int _notify_fail(string);
int living(object ob);
object find_player(string);
#endif

private nosave int _callouttime;
private nosave mapping _calloutfunc = ([]);
private nosave mapping _log_file_info = ([ ]);
private nosave mapping _db_fds = ([ ]);
private nosave mapping _db_obs = ([ ]);
private nosave int _log_file_flush_id;

// Every 5 seconds.
#define DELAY_LOG_FLUSH 5

/**
 * Contains some simul_efuns.
 * @author Pinkfish
 */
/** @ignore yes */
varargs void say( string str, mixed avoid ) {
    if( !pointerp(avoid) ) {
        avoid = ({ TP, PO }) + ({ avoid });
    } else {
        avoid += ({ TP, PO });
    }

    if( !ENV(PO) ) {
        event( ( TP && ENV(TP) ? ENV(TP) : PO ), "say", str, avoid );
    } else {
        event( ( ENV(ENV(PO)) ? ENV(ENV(PO)) : ENV(PO) ), "say", str, avoid );
    }
} /* say()*/

/** @ignore yes */
varargs void tell_room( object ob, string str, mixed avoid ) {
    if( objectp(ob) ) {
        event( ob, "say", str, avoid );
        return;
    }

    if( PO && !ENV(PO) )
        return; // most likely an inherit, don't error.

    error("Specified room doesn't exist, or isn't an object.\n");

} /* tell_room() */

/** @ignore yes */
void tell_object( object ob, string str ) {
    if( objectp(ob) ) {
        ob->do_efun_write( str );
        return;
    }

    error("Specified object doesn't exist, or isn't an object.\n");

} /* tell_object() */

/** @ignore yes */
object find_living( string word ) {
    object thing;

    if( !word )
        return 0;

#if efun_defined(find_living)
    thing = efun::find_living( word );
#else
    thing = LIVING_H->find_living( word );
#endif

    if( !thing || !TP )
        return thing;

    if( reference_allowed( thing, TP ) )
        return thing;

    return 0;

} /* find_living() */

/** @ignore yes */
object find_player( string word ) {
    object thing;

    if( !word )
        return 0;

#if efun_defined(find_player)
    thing = efun::find_player( word );
#else
    thing = LIVING_H->find_player( word );
#endif

    if( !thing || !TP )
        return thing;

    if( reference_allowed( thing, TP ) )
        return thing;

    return 0;

} /* find_player() */

/** @ignore yes */
object *users() {
    if( !TP || PO == master() )
        return efun::users();

    return filter( efun::users(), (: reference_allowed( $1, $2 ) :), TP );

} /* users() */

/** @ignore yes */
object *named_livings() {
#if efun_defined(named_livings)
    if( !TP )
        return efun::named_livings();
    return filter( efun::named_livings(),
        (: reference_allowed( $1, $2 ) :), TP );
#else
    if( !TP )
        return LIVING_H->named_livings();
    return filter( LIVING_H->named_livings(),
        (: reference_allowed( $1, $2 ) :), TP );
#endif
} /* named_livings() */

/** @ignore yes */
object *livings() {
#if efun_defined(livings)
    if( !TP )
        return efun::livings();
    return filter( efun::livings(), (: reference_allowed( $1, $2 ) :), TP );
#else
    if( !TP )
        return efun::objects( (: living($1) :) );
    return efun::objects( (: living($1) && reference_allowed( $1, $(TP)) :) );
#endif
} /* named_livings() */

/** @ignore yes */
object *children( string name ) {
    if( strsrch( name, "global/creator") != -1 && TP )
        return filter( efun::children(name),
            (: reference_allowed( $1, $2 ) :), TP );

    return efun::children(name);

} /* children() */

/**
 * This method calls an event on all the users online.
 * It does not do any filtering, so it will send messages to people who
 * are earmuffed and ignoring or lord invisible or whatever.
 *
 * @param from the person it is from
 * @param name the name of the event
 * @param args the arguments to the event
 */
void user_event( mixed from, mixed first, mixed args ... ) {
    if( stringp( from ) )
        call_other( efun::users(), "event_"+from, PO, first, args ... );
    else if( objectp( from ) && stringp( first ) )
        call_other( efun::users(), "event_"+first, from, args ... );
} /* user_event() */

mixed unguarded( function f );

/**
 * This method flushes out all the buffered stuff for the log files.
 */
private void flush_log_files() {
    string fname, data;

    _log_file_flush_id = 0;
    foreach( fname, data in _log_file_info ) {
        if( file_size( LOG_NAME(fname) ) > MAX_SIZE ) {
            unguarded( (: rm, LOG_NAME(fname)+".old" :) );
            unguarded( (: rename, LOG_NAME(fname), LOG_NAME(fname)+".old" :) );
        }
        map_delete( _log_file_info, fname );
        unguarded( (: write_file, LOG_NAME(fname), data :) );
    }

    _log_file_info = ([ ]);

} /* flush_log_files() */

/**
 * This method writes a message out to a log file.  The log files are
 * normally in "/log".  If a file doesn't start with '/ then "/log/" will be
 * prepended to it.
 * This does automatic removal of the log files after they get over
 * a certain length.  The fmt and args parameters are used to print the
 * actual message.
 * <p>
 * If more than one argument is passed to this function, then sprintf will
 * be used to print out the results.
 * <p>
 * ie: log_file("ROGER", "%s: frog and %s\n", ctime(time()), query_gumboot());
 *
 * @param name the name of the log file
 * @param fmt the format string
 * @param args the arguments to the sprintf
 */
varargs void log_file(string name, string fmt, mixed *args ...) {
    /* five screens */
    if( strlen( fmt ) > 8000 )
        fmt = fmt[ 0 .. 7999 ] +"\n\nPlus more...\n\n";

    fmt = terminal_colour( fmt, ([ ]) );

    if( !_log_file_flush_id )
        _log_file_flush_id = call_out((: flush_log_files :), DELAY_LOG_FLUSH);

    if( !_log_file_info[name] )
        _log_file_info[name] = "";

    _log_file_info[name] += ( sizeof(args) ? sprintf( fmt, args ... ) : fmt );

} /* log_file() */

#if !efun_defined(mud_name)
#ifndef MUD_NAME
#define MUD_NAME "Broken Mud Name"
#endif
/**
 * This method returns the name of the mud.
 * @return the name of the mud
 */
string mud_name() { return MUD_NAME; }
#endif

/**
 * Write the file out to the screen.  This should  not be used if possible.
 * It is an interface to read_file and other things.  You should perhaps
 * look at using more_string ort more_file.
 *
 * @param file the file name to cat
 * @param start_line the line to start on
 * @param number the number of lines to print
 *
 * @see /global/more_string->more_string()
 * @see /global/more_file->more_file()
 */
void cat( string file, int start_line, int number ) {
    string bing;

    if( bing = read_file( file, start_line, number ) )
        printf("%s", bing );

//        printf("%s", bing[0..5000] );

} /* cat() */

#ifdef NEW_DRIVER
/**
 * This method tells us if the object is a wizard.
 * @return is the object a wizard
 */
int wizardp(mixed arg) {
    if( !objectp(arg) )
        return 0;

    return interactive(arg) && TO->creatorp(arg);

} /* wizardp() */
#endif

/** @ignore yes */
int exec( object to, object from ) {
    string s;
    object prev;

    if( file_name(PO)[0..12] == "/secure/login")
        return efun::exec( to, from );

    s = "";

    if( prev = TP )
        s += "TP:"+ sprintf("%8s ", prev->query_name() );

    if( prev = this_player(1) )
        s += "TP1:"+ sprintf("%8s ", prev->query_name() );

    s += "PO:"+ sprintf("%8s ", file_name( PO ) );

    log_file("ILLEGAL", "Exec: %-40s : %s\n", s, ctime( time() ) );
    return 0;

} /* exec() */

/** @ignore yes */
varargs int call_out( mixed fun, int delay, mixed *args ... ) {
    string func;

    if( _callouttime != time() ) {
        _callouttime = time();
        _calloutfunc = ([ ]);
    }

    if( delay == 0 ) {
        func = functionp(fun) ? "" + functionp(fun) : fun + file_name( PO );
        if( ++_calloutfunc[func] > 100 ) {
            delay = 2;
            log_file("CALL_OUT_LOG", ctime(time())+": Object %O (%s) seems "
                "to loop in function %O.\n", PO, ( stringp(PO->query_name()) ?
                PO->query_name() : file_name(PO) ), fun );
        }
    }

    return evaluate( bind(
        (: efun::call_out( $(fun), $(delay), $(args) ... ) :), PO ) );

} /* call_out() */

/**
 * This returns the current verb name.  This works if the verb ius used
 * through add_command or through add_action.
 * @return the name of the verb
 */
string query_verb() {
    string verb;

#if efun_defined(query_verb)
    verb = efun::query_verb();
#else
    verb = "";
#endif

    return ( verb != "" || !objectp( TP ) ? verb :
            (string)TP->query_current_verb() );

} /* query_verb() */

/**
 * Does a string compare...  But case insensitive...
 * @param str1 the string to compare
 * @param str2 the other string to compare
 * @return 0 if they are the same, <0 if they are less than each other, >0 if not
 * @see efun::strcmp()
 */
int strcasecmp( string str1, string str2 ) {
    return strcmp( lower_case(str1), lower_case(str2) );
} /* strcasecmp() */

#define COMPAT_TAIL
#ifdef COMPAT_TAIL
/* This version is strictly compatible with the old version */
/**
 * This will print the last bit of a file.
 * @param fname the file to read
 * @return 1 if it succeeded, 0 if it failed
 */
int tail(string fname) {
    int offset;
    string str;

    offset = file_size(fname);

    if( offset < 0 )
        return 0;

    offset -= 54 * 20;

    if( offset < 0 )
        offset = 0;

    if( !str = read_bytes( fname, offset, 1080 ) )
        return 0;

    if( offset )
        str = str[strsrch( str, "\n")+1..];

    write(str);
    return 1;

} /* tail() */
#else
/* This version is slightly extended and compatible in spirit, but doesn't
 * reproduce the oddities of the original tail() efun.  Note that it also
 * returns the string, so write(tail(fname)) is needed for strict
 * compatibility.
 */
/**
 * This will print the last bit of a file.
 * @param fname the file to read
 * @return 1 if it succeeded, 0 if it failed
 */
varargs string tail( string fname, int nlines ) {
    int chunk, offset, num_nl, p, skip;
    string str;

    chunk = nlines * 80;
    offset = file_size(fname);
    str = "";

    reset_eval_cost();

    while( offset > 0 && num_nl <= nlines ) {
        num_nl = 0;
        offset -= chunk;

        /* negative */
        if( offset < 0 ) {
            chunk += offset;
            offset = 0;
        }
        str = read_bytes( fname, offset, chunk ) + str;
        p = -1;
        while( p < sizeof(str)-1 && p = member_array('\n', str, p+1 ) )
            num_nl++;
    }

    skip = num_nl - nlines;
    p = -1;

    while( skip-- )
        p = member_array('\n', str, p+1 );

    return str[p..];

} /* tail() */
#endif

/** @ignore yes */
void write( mixed str ) {
    if( !TP )
        return;

    if( intp(str) )
        str = "" + str;

    TP->do_efun_write(str);

} /* write() */

/** @ignore yes */
int notify_fail( mixed stuff ) {
    if( functionp( stuff ) )
        stuff = evaluate( stuff );

    if( !stringp( stuff ) )
        return 0;

    TP->print_messages();

    /* for observer-dependent shorts */
    stuff = (string)TP->convert_message( stuff );
    /* for capitalisation and indentation */
    stuff = (string)TP->fit_message( stuff );
    /* for colour */
    stuff = (string)TP->fix_string( stuff );

#if efun_defined(notify_fail)
    return efun::notify_fail( stuff );
#else
    return _notify_fail( stuff );
#endif

} /* notify_fail() */

/**
 * Replaces all occurances of a set of strings in the input string.  Replaces
 * an individual or an array of strings with new values.  If the second
 * argument is an array of strings, then the 1st, 3rd, 5th...  elements will
 * be the strings to search for and the 2nd, 4th, 6th etc will be the strings
 * to replace with.  If three arguments are specified then the second is the string
 * to search for, the third the one to replace.
 * <p>
 * Eg:<br>
 * str = replace(str, ({ "search", "replace", "orange", "apple" });<p>
 * That will replace all occurances of "search" with "replace" and "orange"
 * with "apple".
 *
 * @param str the string to do the replacement in
 * @param bing the search or array argument
 * @param rep the replacement string, or null
 *
 * @return the string with all the replacements done
 */
varargs string replace( string str, mixed bing, string rep ) {
    int i;

    if( pointerp(bing) ) {
        for( i = 0; i < sizeof(bing); i += 2 ) {
            if( stringp(bing[i]) && stringp(bing[i+1]) )
                str = replace_string( str, bing[i], bing[i+1] );
        }
        return str;
    }

    return ( !stringp(str) || !stringp(rep) ? str :
             replace_string( str, bing, rep ) );

} /* replace() */

#if !efun_defined(uniq_array)
/**
 * This method will return an array that contains no duplicates.
 * Written by: Wodan
 * <p>
 * This function will return an array that contains no duplicates.
 * Gotta love them mappings. :)
 * @param arr the array to convert
 * @return an array with no duplicates
 */
mixed uniq_array( mixed arr ) { return keys( allocate_mapping( arr, 1 ) ); }
#endif

#if !efun_defined(distinct_array)
/**
 * This method removes any duplicates from an array while keeping
 * the order intact, this is more costly than uniq_array, so if the
 * order isn't important to you, don't use it, use uniq_array instead.
 * @param arr the array to remove duplicates from
 * @return the new array with no duplicates
 */
mixed distinct_array( mixed arr ) {
    mixed new_arr, tmp;

    new_arr = ({ });

    foreach( tmp in arr )
      if( member_array( tmp, new_arr ) == -1 )
          new_arr += ({ tmp });

    return new_arr;

} /* distinct_array() */
#endif

/**
 * This method sends a polite shout to everyone on line.  It checks
 * for earmuffs and all that sort of stuff.
 * @param words the message to shout
 * @param avoid who not to tell the message to
 */
varargs void shout( string words, object avoid ) {
    object thing, *things;

    things = efun::users();

    foreach( thing in things ) {
        if( thing && thing != avoid && thing != TP &&
            !thing->check_earmuffs("shout") )
            thing->event_say( PO, words, ({ }) );
    }

} /* shout() */

/** @ignore yes */
int reset_eval_cost() { return efun::reset_eval_cost(); }

/** @ignore yes */
int eval_cost() { return efun::eval_cost(); }

/** @ignore yes */
int set_eval_limit() { return efun::set_eval_limit(0); }

#if !efun_defined(event)
/** @ignore yes */
varargs int member_array( mixed item, mixed arr, int start, int flag ) {
    if( !flag )
        return efun::member_array( item, arr, start );

    if( stringp(item) )
        return efun::member_array( item, map( arr,
            (: $1[0..$(strlen(item)-1)] :) ), start );

} /* member_array() */

/** @ignore yes */
void event( mixed ob, string func, mixed rest ... ) {
    string name = "event_"+func;
    object origin = PO;

    if( arrayp(ob) ) {
        call_other( ob - ({ 0 }), name, origin, rest ... );
        return;
    }

    if( objectp(ob) ) {
        call_other( ob, name, origin, rest ... );
        call_other( INV(ob) - ({ 0, origin }), name, origin, rest ... );
    }

} /* event() */
#endif

#if !efun_defined(add_action)
/** @ignore yes */
void move_object( mixed dest ) {
    object tp, *obs, ob;

    if( stringp(dest) )
        dest = find_object(dest);

    evaluate( bind( (: efun::move_object( $(dest) ) :), PO ) );

    if( dest->no_init() )
        return;

    tp = TP;
    obs = INV(dest) - ({ PO });

    if( living(PO) ) {
        set_this_player(PO);
        dest->init();
        foreach( ob in obs )
            ob->init();
    }

    obs = filter( obs, (: living($1) :) );

    foreach( ob in obs ) {
        set_this_player(ob);
        PO->init();
    }

    if( living(dest) ) {
        set_this_player(dest);
        PO->init();
    }

    set_this_player(tp);

} /* move_object() */
#endif

#if efun_defined(db_exec)
/** @ignore yes */
varargs mixed db_exec( int fd, string fmt, mixed *args ... ) {
    _db_fds[fd] = time();
    if( !sizeof(args) )
        return efun::db_exec( fd, fmt );
    else
        return efun::db_exec( fd, sprintf( fmt, args ... ) );
} /* db_exec() */

/** @ignore yes */
varargs int db_connect( mixed args ... ) {
    int fd, i;
    string ob;

    ob = file_name(PO);

    switch( sizeof(args) ) {
      case 0..1:
        error("Not enough arguments to db_connect.");
      case 2:
        fd = efun::db_connect( args[0], args[1], CONFIG_DB_USER );
      break;
      case 3:
        fd = efun::db_connect( args[0], args[1], args[2] );
      break;
      default:
        error("Too many arguments to db_connect.");
    }

    _db_fds[fd] = time();
    _db_obs[fd] = ob;

    i = sizeof( keys( filter( _db_obs, (: $2 == $3 :), ob ) ) );

    if( i > 3 )
        log_file("FDS", "%s - %s: %i fds.\n", ctime(time()), ob, i );

    return fd;

} /* db_connect() */

/** @ignore yes */
mixed db_fetch( int fd, int row ) {
    _db_fds[fd] = time();
    return efun::db_fetch( fd, row );
} /* db_fetch() */

/** @ignore yes */
void db_close( int fd ) {
    map_delete( _db_fds, fd );
    map_delete( _db_obs, fd );
    efun::db_close(fd);
} /* db_close() */

/** @ignore yes */
string db_fds() {
    int *fds;

    fds = keys(_db_fds);

    return implode( fds, (: $1 + sprintf("FD: %d   Time: %s   Object: %s%s\n",
        $2, ctime( $(_db_fds)[$2] ), $(_db_obs)[$2],
        ( find_object($(_db_obs)[$2]) ? "" : "(destructed)" ) ) :), "");

} /* db_fds() */

#else
/** @ignore yes */
varargs int db_connect( mixed *args ... ) {
    error("No database installed.");
} /* db_connect() */

/** @ignore yes */
varargs string db_exec( int fd, string fmt, mixed *args ... ) {
    return "No database installed";
} /* db_exec() */

/** @ignore yes */
mixed db_fetch( int fd, int row ) {
    error("No database installed.");
} /* db_fetch() */

/** @ignore yes */
void db_close( int fd ) { }
#endif

/** @ignore yes */
void shutdown( int bing ) {
    if( PO != find_object(SHUTDOWN_H) && !TO->adminp(PO) ) {
        unguarded( (: write_file, "/secure/log/SHUTDOWN",
            sprintf("value %d\n%s", bing, back_trace() ) :) );
    }

    efun::shutdown(bing);

} /* shutdown() */

/** @ignore yes */
#if !efun_defined(real_time)
int real_time() { return time(); }
#endif

#if !efun_defined(choice)
/**
 * This method returns a random member of the specified array.
 * @param options the array to return a random member from
 * @return a random member of the specified array
 */
mixed choice( mixed options ) {
    mixed k;

    switch( typeof(options) ) {
      case STRING:
        return options[random(strlen(options))];
      case ARRAY:
        return options[random(sizeof(options))];
      case MAPPING:
        k = keys(options);
        return options[k[random(sizeof(k))]];
      default:
        error("Cannot use choice() on that type of input.");
      return 0;
    }
} /* choice() */
#endif

/** @ignore yes */
mixed asort( mixed strlist ) {
    return sort_array( strlist, (: strcmp( $1, $2 ) :) );
} /* asort() */

/** @ignore yes */
int interactive( object ob ) {
    if( objectp(ob) )
        return efun::interactive(ob);
    return 0;
} /* interactive() */

/** @ignore yes */
string pluralize( string str ) {
    mapping exceptions;

    exceptions = (["lotus"  : "lotuses",
                   "coif"   : "coifs",
                   "roof"   : "roofs",
                   "cliff"  : "cliffs",
                   "bacterium" : "bacteria",
                   "plus"   : "pluses",
                   "memo"   : "memos",
                   "studio" : "studios",
                   "folio"  : "folios",
                   ]);

    return exceptions[str] || efun::pluralize(str);

} /* pluralize() */

#if !efun_defined(verbalize)
/**
 * This method does $V$0=verbs,verb$V$ expansion on a word.
 * It does this by pluralizing the verb used.
 * If the optional single person argument is supplied,
 * then that is used for the single person version of the
 * word, and the verb argument is used for multiple people.
 * @param verb the verb to do the expansion on
 * @param single the optional singular argument
 * @return $V$0=verbs,verb$V$ expanded verb
 * @example verbalize("their", "his") returns $V$0=his,their+"$V$
 * @example verbalize("run") returns $V$0=runs,run+"$V$
 */
varargs string verbalize( string verb, string single ) {
    return "$V$0="+( single ? single : pluralize(verb) )+","+verb+"$V$";
} /* verbalize() */
#endif

#if !efun_defined(query_shadows)
/**
 * This method returns all the objects that are shadowing the input object.
 * @param ob the object to get the shadows list for
 * @return the objects shadowing us, or 0 if none are found
 * @author Sandoz
 */
object *query_shadows( object ob ) {
    object *obs, tmp;

    if( tmp = shadow( ob, 0 ) ) {
        obs = ({ ob = tmp });

        while( tmp = shadow( ob, 0 ) )
            obs += ({ ob = tmp });

        return obs;
    }

    return 0;

} /* query_shadows() */
#endif

#if !efun_defined(query_prime)
/**
 * This method queries whether the input number is a prime.
 * @param num the number to test for primeness
 * @return 1 if the number is a prime, 0 if not
 * @author Sandoz & Windy
 */
int query_prime( int num  ) {
    for( int div = 2; div <= num / 2; div++ )
        if( !( num % div ) )
            return 0;

    return 1;

} /* f_query_prime() */
#endif

/** @ignore yes */
string debug_info( int flag, object ob ) {
    if( flag == 2 && !TO->adminp( previous_object(-1) ) ) {
        write("Sorry, that is an admin only option.\n");
        return 0;
    }

    return efun::debug_info( flag, ob );

} /* debug_info() */

/** @ignore yes */
int memory_summary() { return 0; }

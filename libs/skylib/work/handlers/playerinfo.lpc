/**
 * Playerinfo database handler.
 *
 * This handler collects all the fascinating information about players and
 * their sins. At the moment, the following events are supported:
 * replace (all replacements, added by Presto's wand),
 * gag (gagging and ungagging, added by the gagger),
 * suspend (player suspension, added by the "suspend" command),
 * meteor (meteoring a player, added by the "meteor" command),
 * multiplay (various events added by the multiplayer handler),
 * harassment (comments about cases of harassment, added via 'addevent'),
 * misc (misc. comments, added via 'addevent'),
 * cheat (currently unused)
 *
 * The "replace" and "multiplay" events are debounced (merged). In addition,
 * the "replace" events expire in 30 days.
 *
 * @author Fiona
 */
#include <playerinfo.h>

// This is where our save files go
#define PLAYERINFO_SAVE_DIR         "/save/playerinfo"
#define SAVE_FILE                   PLAYERINFO_SAVE_DIR "/handler_data"

// Originators of function calls. Checked for security reasons
#define WAND               "/obj/misc/wand"
#define MULTIPLAY          "/handlers/multiplayer"
#define GAGGER             "/obj/misc/gagger"
#define GAG                "/cmds/creator/gag"
#define UNGAG              "/cmds/creator/ungag"
#define METEOR             "/cmds/creator/meteor"
#define FRY                "/cmds/admin/fry"
#define SKULLWARN          "/cmds/admin/skullwarn"
#define WHOOP              "/cmds/admin/whoop"
#define SWAT               "/cmds/admin/swat"
#define HAMMER             "/cmds/admin/hammer"
#define REPORT_COMMAND     "/cmds/creator/playerinfo"
#define ADD_COMMAND        "/cmds/creator/addevent"
#define DELETE_COMMAND     "/cmds/creator/delevent"
#define ADDALT_COMMAND     "/cmds/creator/addalt"
#define DELALT_COMMAND     "/cmds/creator/delalt"
#define FAMILY_COMMAND     "/cmds/creator/family"
#define SUSPENDER          "/secure/bastards"
#define SHOWHELP_COMMAND   "/cmds/creator/show_help"
#define PATRICIAN_PALACE   "/obj/misc/pk_token"
#define REFRESH_HANDLER    "/handlers/refresh"
#define PRISON             "/d/sur/beta/prison/dungeon"
#define FETCH_COMMAND      "/cmds/creator/fetch"
#define REARRANGE_COMMAND  "/cmds/guild-race/rearrange"

// These don't really belong here... and we have /include/colour.h...
// ...oh well.
#define CL_CREATOR      "%^CYAN%^"
#define CL_EVENT        "%^RED%^"
#define CL_RESET        "%^RESET%^"
#define CL_HEADER       "%^RED%^"

// This is the interval at which debounced events are saved.
#define DEBOUNCE_PERIOD (60*10)

// This is the interval between consecutive checks for timeouts.
// One day is suffucuent.
#define TIMEOUT_PERIOD  (60*60*24)

// Function prototypes
mapping          query_timeouts();
protected string filename(string name);
string *         query_events();
protected int    query_debounced(string event);
protected int    query_lord_only(string event);
int              query_source_ok(string event, string source);
protected int    query_deleter_ok(string event, object deleter);
protected int    query_can_add(string e, object p);
protected int    query_can_delete(string e, object p);
protected int    query_can_handle_alts(object p);
protected void   do_debouncing(string player, class dbentry entry);
protected void   do_timeout();
protected void   load_player(string player);
protected void   save_player(string player);
void             player_remove(string player);
int              add_entry(object creator, string player, string event,
                   string comment, mixed *extra);
int              delete_entry(object creator, string player, string event,
                   int n);
protected void   print_header(object source, string player);
protected void   print_entry(object source, int idx, class dbentry e);
void             print_dossier(object source, string player);
void             print_event(object source, string player, string event);
string           add_alts(object creator, string player, string *alts);
string           delete_alts(object creator, string player, string* alts);
mapping          query_alerts();
int              query_alerts_for( string player );
int              is_alert( string player, int idx );
int              acknowledge_alert( object creator, string player,
                   string event, int idx, string update, mixed * extra );
void             clear_alerts_for( string player );
int              increment_alerts_for( string player );
int              decrement_alerts_for( string player );


class source {
   string *add;
   string *delete;
}

// This is where the current player's info resides.
private class playerinfo    dossier;
// Event timeout information (in seconds)
private nosave mapping      timeouts    = ([ "replace" : (60*60*24*30) ]);

// Ok guys, NEVER do things like this, it is highly poisonous...
private int local_time;
private nosave mapping _sources;

nosave mapping _alerts; // format: ([ "playername1":n, "playername2":n ... ])
                 // where n is the number of alerts in their dossier.
nosave string * _lordonly;

void save_handler_data() {
   mapping vars = ([ ]);
   string tmp;

   vars["alerts"] = _alerts;

   tmp = save_variable( vars );
   unguarded( (: write_file, SAVE_FILE, tmp, 1 :) );

} /* save_handler_data() */

void load_handler_data() {
   mapping vars;
   string tmp;

   if( file_size( SAVE_FILE ) <= 0 )
      return;

   tmp = unguarded( (: read_file, SAVE_FILE :) );
   vars = restore_variable( tmp );

   _alerts = vars["alerts"];

} /* load_handler_data() */

void create() {
    _sources = ([
        "cheat":        new(class source,
                            add : ({ }),
                            delete : ({ DELETE_COMMAND })),
        "discipline":   new(class source,
                            add : ({ ADD_COMMAND, PRISON }),
                            delete : ({ DELETE_COMMAND })),
        "email":        new(class source,
                            add : ({ }),
                            delete : ({ DELETE_COMMAND })),
        "family":       new(class source,
                            add : ({ FAMILY_COMMAND }),
                            delete : ({ DELETE_COMMAND })),
        "gag":          new(class source,
                            add : ({ GAGGER, GAG, UNGAG }),
                            delete : ({ DELETE_COMMAND })),
        "harassment":   new(class source,
                            add : ({ ADD_COMMAND }),
                            delete : ({ DELETE_COMMAND })),
        "meteor":       new(class source,
                            add : ({ METEOR}),
                            delete : ({ DELETE_COMMAND })),
        "fry":          new(class source,
                            add : ({ FRY}),
                            delete : ({ DELETE_COMMAND })),
        "skullwarn":    new(class source,
                            add : ({ SKULLWARN}),
                            delete : ({ DELETE_COMMAND })),
        "whoop":        new(class source,
                            add : ({ WHOOP}),
                            delete : ({ DELETE_COMMAND })),
        "swat":         new(class source,
                            add : ({ SWAT}),
                            delete : ({ DELETE_COMMAND })),
        "misc":         new(class source,
                            add : ({ ADD_COMMAND, PATRICIAN_PALACE,
                                     REARRANGE_COMMAND }),
                            delete : ({ DELETE_COMMAND })),
        "multiplay":    new(class source,
                            add : ({ MULTIPLAY }),
                            delete : ({ DELETE_COMMAND })),
        "replace":      new(class source,
                            add : ({ WAND, ADD_COMMAND, FETCH_COMMAND }),
                            delete : ({ DELETE_COMMAND })),
        "showhelp":     new(class source,
                            add : ({ SHOWHELP_COMMAND }),
                            delete : ({ DELETE_COMMAND })),
        "suspend":      new(class source,
                            add : ({ SUSPENDER }),
                            delete : ({ })),
        "alert":        new(class source,
                            add : ({ ADD_COMMAND, REPORT_COMMAND }),
                            delete : ({ DELETE_COMMAND })),
        "refresh":      new(class source,
                            add : ({ REFRESH_HANDLER }),
                            delete : ({ DELETE_COMMAND }))
    ]);

    _alerts = ([ ]);
    _lordonly = ({ });

    seteuid("Room");
    load_handler_data();

} /* create() */

// Return the mapping of event timeouts
mapping query_timeouts() {
    return timeouts;
} /* query_timeouts() */

/**
 * Give the filename for the player's savefile.
 * @param name the name of the player
 * @return the name of the playerinfo file
 * @ignore
 */
protected string filename(string name) {
    string p = lower_case(name);
    return sprintf("%s/%c/%s.o",PLAYERINFO_SAVE_DIR,p[0],p);
}

/**
 * Answer the list of all possible events.
 * @return array of all event types recognized by the playerinfo handler
 */
string *query_events() {
    return keys(_sources);
} /* query_events() */

/**
 * Check if the event should be debounced.
 * @param event the name of the event
 * @return nonzero if the given event is to be debounced
 * @ignore
 */
protected int query_debounced(string event) {
    return (event == "replace" || event == "multiplay");
} /* query_debounced() */

/**
 * Check if the event is lords-only.
 * @param event the name of the event
 * @return nonzero if the event can only be added by lords
 * @ignore
 */
protected int query_lord_only(string event) {
    return ( member_array( event, _lordonly ) >= 0 ) ? 1 : 0;
}

/**
 * Check if the event has come from the valid source.
 * @param event the name of the event
 * @param source the object trying to add the event
 * @return nonzero if the event can be added by the given source
 */
int query_source_ok(string event, string source) {
    // 0 means no check should be done; ({ }) means nobody can add it
    string *reqd;

    reqd = _sources[event]->add;

    if(reqd == 0) {
        return 1;
    }
    if(sizeof(reqd) == 0) {
        return 0;
    }
    return member_array(source,reqd) >= 0;
}

/**
 * Check if the request to delete an event came from the valid source.
 * @param event the name of the event
 * @param remover the object that tries to remove the event
 */
protected int query_deleter_ok(string event, object deleter) {
    // 0 means no check should be done; ({ }) means nobody can delete it
    string *reqd;

    // for testing purposes only. remember to remove this later!!
    if( creatorp(deleter))
        return 1;

    reqd = _sources[event]->delete;

    if (reqd == 0) {
        return 1;
    }
    if (sizeof(reqd) == 0) {
        return 0;
    }
    return member_array(base_name(deleter),reqd) >= 0;
}

/**
 * Check if the player is allowed to add the event.
 * @param e the name of the event
 * @param p the player who is trying to add it
 * @return nonzero of the player is allowed to add the event
 * @ignore
 */
protected int query_can_add(string e, object p) {
    if(member_array(e,query_events()) < 0)
        return 0;
    if(!interactive(p))
        return 1;
    return !(query_lord_only(e) && !lordp(p));
}

/**
 * Check if the player is allowed to perform delete operations.
 * @param p the player who is trying to delete something
 * @ignore
 */
protected int query_can_delete(string e, object p) {
    if(!interactive(p))
        return 1;
    // for testing purposes only. remember to remove this later!!
    if( creatorp(p))
        return 1;
    if(e == "misc" || e == "replace")
        return seniorp(p->query_name());
    return lordp(p);
}

/**
 * Check if the player is allowed to add and delete alt characters.
 * @param p the player who is trying to add or delete alt(s)
 * @ignore
 */
protected int query_can_handle_alts(object p) {
    if(!interactive(p))
        return 1;
    return seniorp(p->query_name());
}

/**
 * Check if we can debounce the event. Add a new event or modify
 * the last event depending on whether it's debounceable or not.
 * @param player the name of the player for which the database entry is added
 * @param entry the database entry to be added
 * @ignore
 */
protected void do_debouncing(string player, class dbentry entry) {
    int             n;
    class dbentry   last;

    if (query_debounced(entry->event)) {
      //tell_creator("pinkfish", "[playerinfo] Debouncing: %O.\n",entry);
        n = sizeof(dossier->data);
        if(n != 0) {
            last = dossier->data[n-1];
            //tell_creator("pinkfish", "[playerinfo] Last: %O.\n",last);
            if(entry->event == last->event &&
              entry->creator == last->creator &&
              entry->time - last->time <= DEBOUNCE_PERIOD) {
                // Merge the two events
              //tell_creator("pinkfish", "[playerinfo] Merging events.\n");
                last->comment += entry->comment;
                last->time = entry->time;
                if(last->extra != 0) {
                    if(entry->extra == 0)
                        entry->extra = ({ });
                    last->extra += entry->extra;
                }
                //tell_creator("pinkfish", "[playerinfo] Result: %O.\n",last);
                return;
            }
        }
    }
    //tell_creator("pinkfish", "[playerinfo] Not merging events.\n");
    dossier->data += ({ entry });
    return;
}

/**
 * Check the currently loaded data for timed out entries and remove them.
 * @ignore
 */
protected void do_timeout() {
    function not_timed_out = function(class dbentry p)
    {
        int life = timeouts[p->event];

        if(life == 0)          // This event cannot be timed out
            return 1;
        // Time it out if its life period has expired
        return local_time <= (p->time + life);
    };

    local_time = time();

    dossier->data = filter(dossier->data, not_timed_out);
    dossier->last_check = time();
}

/**
 * Load the data of the playerinfo object from its save file. If there's no
 * file, create an empty dossier. Don't load anything if the data is
 * already loaded.
 * @param player the name of the player whose data is to be loaded
 * @ignore
 */
protected void load_player(string player) {
    string  p = lower_case(player);
    string  fn = filename(p);

    if(dossier != 0 && dossier->name == p)
        return;                // Already have it here

    if(file_size(fn) > 0) {
        unguarded( (: restore_object, fn :) );
    } else {
        dossier = new(class playerinfo,
            name:       p,
            last_check: time(),
            alts:       ({ }),
            data:       ({ }));
    }
}

/**
 * Save the data of the playerinfo object to its save file.
 * @param player the name of the player whose data is to be saved
 * @ignore
 */
protected void save_player(string player) {
    if(time() - dossier->last_check >= TIMEOUT_PERIOD)
        do_timeout();
    unguarded( (: save_object, filename(player) :) );
}

/**
 * Remove the player's data file.
 * @param player the name of the player
 */
void player_remove(string player) {
   unguarded( (: rm, filename(player) :) );
   clear_alerts_for(player);
}

/**
 * Add a new entry to the player's database.
 * @param source the creator or another object trying to add the event
 * @param player the name of the player
 * @param event event the name of the event to be added
 * @param comment arbitrary comment text (more than one line is OK)
 * @param extra arbitrary array of arbitrary objects (can be 0)
 * @return nonzero if the entry was successfully added to the database
 */
int add_entry( object creator, string player, string event, string comment,
               mixed *extra ) {
    class dbentry   new_entry;

    if( !query_can_add( event, creator ) )
        return 0;              // No permission to add this event
    if( !query_source_ok( event, base_name(PO) ) )
        return 0;              // Wrong object trying to add this event
    if( !PLAYER_H->test_user( lower_case(player) ) )
        return 0;              // No such player

    load_player(player);

    new_entry = new(class dbentry,
            time:       time(),
            creator:    capitalize(creator->query_name()),
            event:      event,
            comment:    (comment == 0 ? "" : comment),
            extra:      extra);

    do_debouncing(player, new_entry);
    save_player(player);

    // Add the player to the alerts mapping (to be checked by the login
    // handler which will dispatch warnings to currently online creators
    // the next time the player logs in, until the event is acknowledged)
    if( event == "alert" )
        increment_alerts_for(player);
    return 1;
} /* add_entry() */

/**
 * Delete an entry from the playerinfo database.
 * @param source the creator or another object trying to add the event
 * @param player the name of the player
 * @param event the name of the event of the entry being deleted
 * @param n the index of the entry being deleted
 * @return nonzero if the entry was successfully deleted
 */
int delete_entry(object creator, string player, string event, int n) {
   int idx = n - 1;
   class dbentry * data;

   if( !query_can_delete( event, creator ) )
      return 0;
   if( !query_deleter_ok( event, previous_object() ) )
      return 0;      // Wrong object trying to delete this event
   load_player(player);
   if( ( idx < 0 ) || ( idx >= sizeof( dossier->data ) ) )
      return 0;
   if( dossier->data[idx]->event != event )
      return 0;

   data = copy( dossier->data );
   data = data[0 .. (idx - 1)] + data[(idx + 1) .. <1];
   dossier->data = data;
   save_player(player);
   if( event == "alert" )
      decrement_alerts_for(player);

   return 1;
}

/**
 * Print the header of of the database report.
 * @param source the creator who requested the report
 * @param player the name of the player
 * @ignore
 */
protected void print_header(object source, string player) {
    string  alt, aka = "", alts = "";
    int     first = 1;

    if(sizeof(dossier->alts) > 0) {
        foreach(alt in dossier->alts) {
            if(first) first = 0; else alts = alts + ", ";
            alts = alts + CL_HEADER + capitalize(alt) + CL_RESET;
        }
        alts = " aka " + alts;
    }
    if(dossier->main_alt != 0)
        aka = " (alt of " + CL_HEADER + capitalize(dossier->main_alt) +
            CL_RESET + ")";
    tell_object(source,sprintf("Report for: %s%s%s\n\n",
        CL_HEADER+capitalize(player)+CL_RESET,alts,aka));
}

/**
 * Print one entry of the dossier.
 * @param source the creator who requested the report
 * @param idx the index of the database entry to print
 * @param e the database entry to print
 * @ignore
 */
protected void print_entry(object source, int idx, class dbentry e) {
    string  date        = ctime(e->time);
    string  creator     = e->creator;
    string  event       = e->event;
    string  *comments   = explode(e->comment,"\n");
    string  line;
    int     lines = 0;
    int     cols;

    tell_object( source, sprintf("%d. %-26s %s%|20s%s (added by %s%s%s)\n",
        idx+1,date, CL_EVENT, event, CL_RESET, CL_CREATOR, creator,
        CL_RESET ) );

    cols = (int)source->query_cols() || 79;

    foreach( line in comments ) {
        if( sizeof(line) ) {
            tell_object( source, indent( line+"\n", 4, cols ) );
            lines++;
        }
    }

    if( !lines )
        tell_object( source, sprintf("    (no comments)\n") );

} /* print_entry() */

/**
 * Print all entries from the given player's dossier.
 * @param source the creator who requested the report
 * @param player the name of the player
 */
void print_dossier(object source, string player) {
    int             i;
    class dbentry   *list;
//  class playerinfo migrated;

    load_player(player);
/*
    migrated = new(class playerinfo,
        name:       dossier->name,
        last_check: dossier->last_check,
        alts:       dossier->alts,
        data:       dossier->data,
        main_alt:   0);
    dossier = migrated;
    save_player(player);
*/
    print_header(source,player);
    list = dossier->data;
    for ( i = 0; i < sizeof( list ); i++ ) {
        print_entry(source,i,list[i]);
    }
}

/**
 * Print all entries from the given player's dossier with the given event
 * type.
 * @param source the creator who requested the report
 * @param player the name of the player
 * @param event the name of the event
 */
void print_event(object source, string player, string event) {
    int             i;
    class dbentry   *list;

    load_player(player);
    print_header(source,player);
    list = dossier->data;
    for (i = sizeof(list)-1; i >= 0; i--) {
      if (list[i]->event == event) {
        print_entry(source,i,list[i]);
      }
    }
}

/**
 * Add an alt character name to this player's dossier. This function succeeds
 * if both characters are not "main", or only one if them is "main". Both
 * players will have their dossiers modified.
 * @param player the name of the player
 * @param alts the names of the alt characters to add
 * @return a string describing the outcome of the function call
 */
string add_alts(object creator, string player, string *alts) {
    string  p1 = lower_case(player);
    string  *p2 = uniq_array(map(alts, (: lower_case($1) :)));
    string  alt, *to_add, result;

    if(!query_can_handle_alts(this_player()))
        return "You are not allowed to add players' alts.  \n";
    if( !PLAYER_H->test_user(p1) )
        return "No such player: "+p1+".  \n";   // No such player
    foreach(alt in p2) {
        if( !PLAYER_H->test_user(alt) )
            return "No such player: "+alt+".  \n";  // No such player
    }

    load_player(p1);
    if(dossier->main_alt != 0) {
        return capitalize(p1)+" is already an alt of "+
            capitalize(dossier->main_alt);
    }

    p2 -= dossier->alts;
    p2 -= ({ p1 });
    to_add = ({ });

    foreach(alt in p2) {
        load_player(alt);
        if(dossier->main_alt == 0 && sizeof(dossier->alts) == 0) {
            dossier->main_alt = p1;
            dossier->alts = ({ });
            save_player(alt);
            to_add += ({ alt });
        }
    }

    if(sizeof(to_add) == 0)
        return "Couldn't add any alts.  \n";

    load_player(p1);
    if(dossier->alts == 0)
        dossier->alts = ({ });  // We are lazy...
    dossier->alts = uniq_array(dossier->alts + to_add);  // I LOVE MAPPINGS!
    save_player(p1);

    // Get ready for an example of a REALLY crazy code!
    // (just for reference, all it does is formatting a list of names
    // in a nice capitalized, comma-separated way :) ).
    result = "Added "+
        implode(map(to_add, (: capitalize($1) :)),", ")+
        " to "+capitalize(p1)+"'s list of alts.  \n";
    if(sizeof(p2) != sizeof(to_add))
        result += "Couldn't add: "+
            implode(map(p2-to_add, (: capitalize($1) :)),", ")+".  \n";

    return result;
}

/**
 * Delete an alt character name from this player's dossier. Note that both
 * players have their dossier modified.
 * @param player the name of the player
 * @param alts the name of the alt characters to delete
 * @return a string describing the outcome of the function call
 */
string delete_alts(object creator, string player, string* alts) {
    string  p1 = lower_case(player);
    string  *p2 = map(alts, (: lower_case($1) :));
    string  alt, *to_delete, result;

    if( !query_can_handle_alts( TP ) )
        return "You are not allowed to delete players' alts.  \n";
    if( !PLAYER_H->test_user(p1) )
        return "No such player: "+p1+".  \n";   // No such player
    foreach( alt in p2 ) {
        if( !PLAYER_H->test_user(alt) )
            return "No such player: "+alt+".  \n";  // No such player
    }

    load_player(p1);
    if(sizeof(dossier->alts) == 0)
        return capitalize(p1)+" doesn't have any alts.  \n";

    to_delete = ({ });
    foreach(alt in p2) {
        load_player(alt);
        if(dossier->main_alt == p1) {
            dossier->main_alt = 0;
            dossier->alts = ({ });
            save_player(alt);
            to_delete += ({ alt });
        }
    }

    if(sizeof(to_delete) == 0)
        return "Couldn't delete any alts.  \n";

    load_player(p1);
    if(dossier->alts == 0)
        dossier->alts = ({ });
    dossier->alts = uniq_array(dossier->alts - to_delete);  // (see above)
    save_player(p1);

    // Same crazy code as above.
    result = "Deleted "+
        implode(map(to_delete, (: capitalize($1) :)),", ")+
        " from "+capitalize(p1)+"'s list of alts.  \n";
    if(sizeof(p2) != sizeof(to_delete))
        result += "Couldn't delete: "+
            implode(map(p2-to_delete, (: capitalize($1) :)),", ")+".  \n";

    return result;
}
/**
 *  @return The alerts mapping.
 */
mapping query_alerts() {
   if( !_alerts )
      _alerts = ([ ]);

   return _alerts;
} /* query_alerts() */

/**
 * @param player Name of the player to query
 * @return The number of alerts for that player
 */
int query_alerts_for( string player ) {
   player = lower_case(player);

   if( !_alerts )
      _alerts = ([ ]);

   return _alerts[player];
} /* query_alerts_for() */

/**
 * @param player The name of the player
 * @param idx The number of the event to check for alert status.
 * @return 0 if the event is not an alert, 1 if it is.
 */
int is_alert( string player, int idx ) {
   if( !PLAYER_H->test_user( lower_case( player ) ) )
       return 0;

   load_player( player );

   return idx > 1 && sizeof(dossier->data) > --idx &&
        (dossier->data[idx])->event == "alert";

} /* is_alert() */

/*
 * @param player The name of the player.
 * @param event The type of event to change the alert to.
 * @param idx The number of the event to acknowledge.
 * @param update The event description
 * @return 1 for success or 0 for failure.
 */
int acknowledge_alert( object creator, string player, string event,
   int idx, string update, mixed * extra ) {
   class dbentry entry;
   string previnfo;

   player = lower_case(player);

   if( !query_can_add( event, creator ) )
       return 0;              // No permission to add this event
   if( !query_source_ok( "alert", base_name( previous_object() ) ) )
       return 0;              // Wrong object trying to add this event
   if( !PLAYER_H->test_user(player) )
       return 0;              // No such player
   if( member_array( event, keys(_sources) ) < 0 )
       return 0;              // No such event type

   // Update the entry
   idx--;
   load_player( player );
   entry = dossier->data[idx];

   previnfo = sprintf( "Originally added by %s%s%s at %s:\n%s\n---\n",
     CL_CREATOR, entry->creator, CL_RESET, ctime( entry->time ),
     entry->comment );

   entry->time    = time();
   entry->creator = capitalize( creator->query_name() );
   entry->event   = lower_case( event );
   entry->comment = previnfo + update;

   dossier->data[idx] = entry;
   decrement_alerts_for(player);

   save_player( player );
   return 1;

} /* acknowledge_alert() */

/**
 * @param player The name of the player.
 */
void clear_alerts_for( string player ) {
   player = lower_case(player);

   if( !_alerts )
       _alerts = ([ ]);

   map_delete( _alerts, player );
   save_handler_data();

} /* clear_alerts_for() */

/**
 * @param player The name of the player.
 * @return The updated number of alerts for that player.
 */
int increment_alerts_for( string player ) {
   player = lower_case(player);

   if( !_alerts )
       _alerts = ([ ]);

   if( !PLAYER_H->test_user(player) )
       return 0;

    _alerts[player]++;

   save_handler_data();
   return _alerts[player];

} /* increment_alerts_for() */

/**
 * @param player The name of the player.
 * @return The updated number of alerts for that player.
 */
int decrement_alerts_for( string player ) {
   player = lower_case(player);

   if( !_alerts )
       _alerts = ([ ]);

   if( undefinedp( _alerts[player] ) )
       return 0;

   if( --_alerts[player] <= 0 ) {
       map_delete( _alerts, player );
       save_handler_data();
       return 0;
   }

   save_handler_data();
   return _alerts[player];

} /* int decrement_alerts_for() */

/**
 * @return list of the currently-online players who have unacknowledged alerts
 */
string *query_online_alerts() {
   return filter( keys( query_alerts() ),
     (: member_array( $1, users()->query_name() ) !=-1 :) );
} /* query_online_alerts() */

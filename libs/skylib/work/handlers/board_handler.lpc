/**
 * Keeps track of all the bulletin board notes and related information.
 * @index bulletin
 * @author Pinkfish
 */

#include <board.h>

#define T_MIN                0
#define T_MAX                1
#define T_TIMEOUT            2
#define DEFAULT_MIN          10
#define DEFAULT_MAX          80
#define DEFAULT_TIMEOUT      14

#define WWW_POST_INTERVAL    86400
#define WWW_POST_MAX         5

#define ARCHIVE_DIR          "/save/oldboards/"
#define MAX_ARCHIVE_SIZE     1048576

#define BACKUPS_DIR          "/save/board_backups/"
#define NEWSRC_SAVE_DIR      "/save/newsrc/"

#define BACKUP_TIME_OUT      (7*24*60*60)
#define BOARD_HANDLE_VERSION 1

#define CACHE_SIZE           100
#define CACHE_TIMEOUT        1800
#define NEWSRC_SAVE_DELAY    300

class newsrc {
    int cached;
    int changed;
    mapping newsrc;
    string *kill;
    string *board_order;
}

class cached_mess {
    int last;
    string mess;
}

class posted_information {
    int time_first_posted;
    int count;
}

private int num;
private int board_version;
private mapping archives;
private mapping boards;
private mapping close;
private mapping priv;
private mapping security;
private mapping timeouts;

private mapping posted_stuff;

private nosave string *_allowed_objects;
private nosave mapping message_cache;
private nosave mapping _newsrc_cache;
private nosave int total_reads, cache_hits;
private nosave int _newsrc_reads, _newsrc_cache_hits;
private nosave mapping _idiots;

private void expire_boards();

protected void create() {
    int number, last;
    string line, *lines;

    num = 1;

    message_cache = ([ ]);
    _newsrc_cache = ([ ]);

    // These are the objects allowed to post...
    _allowed_objects = ({
        BOARD_HAND,
        BOARD_OBJ,
        "/obj/misc/board_mas",
        BOARD_WEB,
        "/www/secure/errors",
        "/handlers/club_handler",
        "/handlers/deity_handler",
        "/handlers/folder_handler",
        "/handlers/playtesters",
        "/handlers/error_tracker",
        "/handlers/twiki",
        "/cmds/player/news",
        "/cmds/player/apply",
        "/cmds/player/bug",
        "/cmds/player/typo",
        "/cmds/playtester/report",
        "/cmds/player/idea",
    });

    _idiots = (["no-one" : 1 ]);

    unguarded( (: cp, BOARD_FILE+".o", BACKUPS_DIR+"boards."+time() :) );

    lines = unguarded( (: get_dir, BACKUPS_DIR+"boards.*" :) );

    if( sizeof(lines) > 6 ) {
        last = time() - BACKUP_TIME_OUT;
        foreach( line in lines ) {
            sscanf( line, "boards.%d", number );
            if( number < last )
                unguarded( (: rm, BACKUPS_DIR+line :) );
        }
    }

    unguarded( (: restore_object, BOARD_FILE :) );

    if( !archives )
        archives = ([ ]);
    if( !boards )
        boards = ([ ]);
    if( !close )
        close = ([ ]);
    if( !priv )
        priv = ([ ]);
    if( !security )
        security = ([ ]);
    if( !timeouts )
        timeouts = ([ ]);
    if( !posted_stuff )
        posted_stuff = ([ ]);

    call_out( (: expire_boards :), 5 );

} /* create() */

/**
 * This method returns the posted_stuff mapping.
 * @return the posted stuff mapping
 */
mapping query_posted_stuff() { return posted_stuff; }

/**
 * This method returns the maximum amount of posts one can
 * make from the www boards.
 * @return the max amount of posts one can do from www boards
 */
int query_www_post_max() { return WWW_POST_MAX; }

/*
 * This is called when something is posted from the www boards,
 * it will increment the count and fiddle with stuff.
 */
void www_post_note( string name ) {
    class posted_information bing;

    if( file_name(PO) != BOARD_WEB )
        return;

    if( creatorp( name ) ) {
        if( !undefinedp(posted_stuff[name]) )
            map_delete( posted_stuff, name );
        return;
    }

    if( !undefinedp(posted_stuff[name]) )
        bing = (class posted_information)posted_stuff[name];
    else
        bing = new( class posted_information );

    if( time() > bing->time_first_posted + WWW_POST_INTERVAL ) {
        bing->time_first_posted = time();
        bing->count = 0;
    }

    bing->count++;
    posted_stuff[name] = bing;

} /* www_post_note() */

/*
 * This is called when a note is eaten from the www boards,
 * it will decrement the allowed number of posts.
 */
void www_delete_note( string name ) {
    class posted_information bing;

    if( file_name(PO) != BOARD_WEB )
        return;

    if( !undefinedp(posted_stuff[name]) ) {
        bing = (class posted_information)posted_stuff[name];
        if( time() > bing->time_first_posted + WWW_POST_INTERVAL ) {
            map_delete( posted_stuff, name );
        } else {
            bing->count--;
            posted_stuff[name] = bing;
        }
    }

} /* www_delete_note() */

/**
 * This method checks whether or not a player can post on the www boards.
 * @param name the player to test
 * @return 1 if they can post, 0 if they have used up their posts
 * for the day or similar
 */
int can_post_www_note( string name ) {
    class posted_information bing;

    if( file_name(PO) != BOARD_WEB )
        return 0;

    // No additional checks for cres.
    if( creatorp(name) )
        return 1;

    // Check to see if they are less than 6 hours old.
    if( PLAYER_H->test_age(name) > - 6 * 60 * 60 )
        return 0;

    // Inactive players can't post.
    if( !PLAYER_H->test_active(name) )
        return 0;

    if( undefinedp(posted_stuff[name]) )
        return 1;

    bing = (class posted_information)posted_stuff[name];

    if( time() > bing->time_first_posted + WWW_POST_INTERVAL ) {
        map_delete( posted_stuff, name );
        return 1;
    }

    // Up to N posts - number of days since last login.
    // test_last returns a -ve number.
    if( bing->count < ( WWW_POST_MAX - ( time() -
        PLAYER_H->test_last(name) ) / 86400 ) )
        return 1;

    return 0;

} /* can_post_www_note() */

/**
 * This method returns the file name of the message to use in retreiving
 * the message.
 * @param board the board to get the message from
 * @param num the number of the message to download
 */
private string get_filename( string board, int num ) {
    string fixed_board;

    fixed_board = replace( board, ({" ", "_", "'", ""}) );

    // If a file exists in the old folder then return its name.
    if( file_size( BOARD_DIR + num ) != -1 )
        return BOARD_DIR + num;

    // If a sub-directory doesn't exist for this board then make one.
    if( file_size( BOARD_DIR + fixed_board ) != -2 )
        unguarded( (: mkdir, BOARD_DIR + fixed_board :) );

    // Return the filename in the appropriate subdirectory.
    return BOARD_DIR + fixed_board + "/" + num;

} /* get_filename() */

/**
 * Returns the names of all the boards.
 * @return the names of all the boards
 */
string *query_boards() { return asort( keys(boards) ); }

/**
 * This method tests to see if the board exists.
 * @param board the name of the board to check
 * @return 1 if the board exists, 0 if it does not
 */
int is_board( string board ) {
    if( boards[board] )
        return 1;
    return 0;
} /* is_board() */

/**
 * This method sets what board 'closed' posts move to.
 * @return 1 if the successful, 0 if it not
 */
int set_close( string board_from, string board_to ) {
    if( member_array( board_from, keys(boards) ) == 1 )
        return 0;

    if( member_array( board_to, keys(boards) ) == 1 )
        return 0;

    close[board_from] = board_to;
    return 1;

} /* set_close() */

/**
 * Returns the board closed posts move to.
 * @return the board closed posts move to
 */
string query_close( string board_from ) {
    if( member_array( board_from, keys(boards) ) == -1 )
        return 0;
    return close[board_from];
} /* query_close() */

/**
 * Returns a list of board that have closed set to.
 * @return a list of board that can be closed
 */
mapping query_close_boards() { return copy(close); }

/**
 * Check to see if read access is allowed.
 * @param board the board to check
 * @param previous the previous object
 * @param name the name of the person doing stuff
 * @return 1 if it is allowed, 0 if not
 */
int test_can_read( string board, object previous, string name ) {
    int bit;

    // For the moment we will just log all bad access...
    if( member_array( base_name(previous), _allowed_objects ) == -1 &&
        board != "announcements") {
#ifdef DEBUG
        log_file("BAD_BOARD", ctime(time())+" (read): ["+board+"] "+
            base_name(previous) + sprintf(" (%O)\n", TP->query_name() ) );
#endif
        return 0;
    }

    bit = priv[board] & B_PRIV_TYPE_MASK;

    if( bit == B_PRIV_ACCESS_RESTRICTED )
        return lordp(name) || member_array( name, security[board] ) != -1;

    if( bit == B_PRIV_ACCESS_ADMIN )
        return adminp(name) || member_array( name, security[board] ) != -1;

    if( bit == B_PRIV_ACCESS_RESTRICTED_METHOD ) {
        if( lordp(name) )
            return 1;
        // This will now need to check the method and function to call.
        if( sizeof(security[board]) == 2 )
            return call_other( security[board][1], security[board][0],
                   B_ACCESS_READ, board, previous, name );
        return 0;
    }

    return 1;

} /* test_can_read() */

/**
 * Check to see if write access is allowed.
 * @param board the board to check
 * @param previous the previous object
 * @param name the name of the person doing stuff
 * @return 1 if it is allowed, 0 if not
 */
int test_can_write( string board, object previous, string name ) {
    int bit;

    if( _idiots[name] )
        return 0;

    if( board == "applications")
        return 1;

    if( member_array( base_name(previous), _allowed_objects) == -1 ) {
#ifdef DEBUG
        log_file("BAD_BOARD", ctime(time())+" (write): "+base_name(previous)+
            sprintf(" (%O)\n", TP ) );
#endif
        return 0;
    }

    bit = priv[board] & B_PRIV_TYPE_MASK;

    if( bit == B_PRIV_ACCESS_RESTRICTED_FILE )
        return member_array( base_name(previous), security[board] ) != -1;

    if( bit == B_PRIV_ACCESS_ADMIN )
        return adminp(name) || member_array( name, security[board] ) != -1;

    if( bit == B_PRIV_ACCESS_RESTRICTED_METHOD ) {
        if( lordp(name) )
            return 1;
        // This will now need to check the method and function to call.
        if( sizeof(security[board]) == 2 )
            return call_other( security[board][1], security[board][0],
                   B_ACCESS_WRITE, board, previous, name );
        return 0;
    }

    if( bit == B_PRIV_ACCESS_RESTRICTED || bit == B_PRIV_READ_ONLY )
        return lordp(name) || member_array( name, security[board] ) != -1;

    return 1;

} /* test_can_write() */

/**
 * Check to see if delete is allowed.
 * @param board the board to check
 * @param previous the previous object
 * @param name the name of the person doing stuff
 * @return 1 if it is allowed, 0 if not
 */
int test_can_delete( string board, object previous, string name ) {
    int bit;

    if( member_array( base_name(previous), _allowed_objects ) == -1 ) {
#ifdef DEBUG
        log_file("BAD_BOARD", ctime(time())+" (write): "+base_name(previous)+
            sprintf(" (%O)\n", TP ) );
#endif
        return 0;
    }

    bit = priv[board] & B_PRIV_TYPE_MASK;

    if( bit == B_PRIV_ACCESS_RESTRICTED_FILE )
        return lordp(name) ||
               member_array( base_name(previous), security[board] ) != -1;

    if( bit == B_PRIV_ACCESS_ADMIN )
        return adminp(name) || member_array( name, security[board] ) != -1;

    if( bit == B_PRIV_ACCESS_RESTRICTED || bit == B_PRIV_READ_ONLY )
        return lordp(name) || member_array(name, security[board]) != -1;

    if( bit == B_PRIV_ACCESS_RESTRICTED_METHOD ) {
        if( lordp(name) )
            return 1;
        // This will now need to check the method and function to call.
        if( sizeof(security[board]) == 2 ) {
            return call_other( security[board][1], security[board][0],
                   B_ACCESS_DELETE, board, previous, name );
        }
    }

    return lordp(name);

} /* test_can_delete() */

/**
 * Get the subjects for the specifed board.  The subjects are
 * returns in a special array format.  See the include file for the
 * defines to get at the members of the array.
 * @see /include/board.h
 * @param name the board name to lookup
 * @return the subject array
 */
mixed get_subjects( string name, string person ) {
    if( member_array( file_name(PO), ({ BOARD_WEB,
        "/d/playtesters/handlers/login_calls" }) ) == -1 ) {
        if( TP )
            person = (string)TP->query_name();
        else
            person = "unknown";
    }

    if( file_name(PO) == "/d/playtesters/handlers/login_calls" ) {
        return boards[name];
    }

    if( !test_can_read( name, PO, person ) || !boards[name] )
        return ({ });

    return boards[name];

} /* get_subjects() */

/**
 * Get the text of a specific message.  This will look up the
 * text on a board with the given number and return that to the
 * caller.  The number is the offset into the subject array in
 * which to get the message from.
 * @param board the board name to get the message from
 * @param num the message number to use
 * @param name the person doing the reading
 * @return the message or 0 if it failed
 */
string get_message( string board, int num, string name ) {
    if( file_name(PO) != BOARD_WEB ) {
        if( file_name(PO)[0..14] != BOARD_OBJ )
            name = "unknown";
        else
            name = (string)TP->query_name();
    }

    if( !test_can_read( board, PO, name ) )
        return 0;

    if( num < 0 || num >= sizeof(boards[board]) )
        return 0;

    if( !message_cache )
        message_cache = ([ ]);

    total_reads++;

    // If it's not in the cache, put it in there.
    if( !message_cache[boards[board][num][B_NUM]] ) {
        name = get_filename( board, boards[board][num][B_NUM] );

        if( file_size(name) <= 0 )
            return 0;

        if( find_call_out("clean_cache") == -1 &&
            sizeof(message_cache) > CACHE_SIZE )
            call_out("clean_cache", 30 );

        message_cache[boards[board][num][B_NUM]] = new( class cached_mess,
            last : time(), mess : unguarded( (: read_file, name :) ) );

    } else {
        message_cache[boards[board][num][B_NUM]]->last = time();
        cache_hits++;
    }

    return message_cache[boards[board][num][B_NUM]]->mess;

} /* get_message() */

private int sort_by_last( int one, int two ) {
    if( message_cache[one]->last < message_cache[two]->last )
        return 1;
    if( message_cache[one]->last > message_cache[two]->last )
        return -1;
    return 0;
} /* sort_by_last() */

/**
 * @ignore yes
 * Prevent the cache from getting too big.
 */
void clean_cache() {
    string name;
    int i, *list;

    list = sort_array( keys(message_cache),
        (: sort_by_last( $1, $2 ) :) )[CACHE_SIZE..];

    foreach( i in list )
        map_delete( message_cache, i );

    foreach( name in keys(_newsrc_cache) )
        if( !_newsrc_cache[name]->changed &&
            _newsrc_cache[name]->cached < time() - CACHE_TIMEOUT )
            map_delete( _newsrc_cache, name );

} /* clean_cache() */

private void save_me() {
    unguarded( (: save_object, BOARD_FILE :) );
} /* save_me() */

/**
 * Return the archive file location for the board.
 * @param board the board to get the archive location for
 * @return the archive file location, 0 on failure
 */
string query_archive( string board ) {
    if( !boards[board] )
        return 0;

    if( undefinedp(archives[board]) )
        return ARCHIVE_DIR+board;

    return archives[board];

} /* query_archive() */

/** @ignore yes */
int zap_message( string board, int off ) {
    int num;
    string nam, archive;

    if( off < 0 || off >= sizeof(boards[board]) )
        return 0;

    num = boards[board][off][B_NUM];
    nam = get_filename( board, num );
    archive = query_archive(board);

    if( archive ) {
        mixed stuff;

        stuff = boards[board][off];

        // When we archive it, strip the colours out.
        unguarded( (: write_file, archive, sprintf("\n----\n"
            "Note #%d by %s posted at %s\nTitle: '%s'\n\n", off,
            stuff[B_NAME], ctime(stuff[B_TIME]), stuff[B_SUBJECT]) +
            strip_colours( unguarded( (: read_file, nam :) ) ) :) );

        if( unguarded( (: file_size, archive :) ) > MAX_ARCHIVE_SIZE )
            unguarded( (: rename, archive, archive+"."+time() :) );
    }

    boards[board] = delete( boards[board], off, 1 );
    unguarded( (: rm, nam :) );

    save_me();
    return 1;

} /* zap_message() */

/**
 * Adds a new message onto the board.  This call can only be done from
 * verified source, like the bulletin oard objects themselves.  The
 * number used as a reply to should be the message number itself, not
 * the logical index.  If the reply_to is 0 then it is not
 * replying to anything at all.
 * @param board the board to add the message to
 * @param cap_name the name ofthe person posting
 * @param subj the subject of the message
 * @param body the main section of the text
 * @param reply_to the note the message is replying to
 * @return the note number, or 0 on failure
 */
int add_message( string board, string cap_name, string subj,
                 string body, int reply_to, class reply_type bing ) {
    int irp, index;
    string fname, name, from_mess, mail_to;
    class reply_type reply;

    name = lower_case(cap_name);

    // Check to see what should happen to the reply.
    if( reply_to ) {
        for( index = 0; index < sizeof(boards[board]); index++ ) {
            if( boards[board][index][B_NUM] == reply_to &&
                boards[board][index][B_REPLY_TYPE] ) {
                // Do something special.
                reply = (class reply_type)boards[board][index][B_REPLY_TYPE];

                if( reply->type == B_REPLY_POSTER )
                    mail_to = boards[board][index][B_NAME];
                else if( reply->type == B_REPLY_NAMED )
                    mail_to = reply->data;

                // Send mail instead.
                if( mail_to ) {
                    MAIL_H->do_mail_message( mail_to, name, subj, "", body );
                    return 1;
                }
            }
        }
    }

    if( !test_can_write( board, PO, name ) )
        return 0;

    if( !boards[board] )
        return 0;
    else
        boards[board] += ({ ({ subj, cap_name, num++, time(), bing, reply_to }) });

    if( file_name(PO)[1..4] == "www/")
        from_mess = " [Web post]";
    else
        from_mess = "";

    fname = get_filename( board, num-1 );
    unguarded( (: rm, fname :) );
    fname = get_filename( board, num-1 );

    unguarded( (: write_file, fname, body :) );
    save_me();

    // Add this new message to the cache.
    message_cache[num-1] = new( class cached_mess, last : time(), mess : body );

    if( timeouts[board] && timeouts[board][T_MAX] &&
        sizeof(boards[board]) > timeouts[board][T_MAX] ) {
        // Should be at most one message we eat...
        while( sizeof(boards[board]) > timeouts[board][T_MAX] ) {
            zap_message( board, 0 );
            irp++;
        }

        if( ( priv[board] & B_PRIV_TYPE_MASK ) == B_PRIV_ACCESS_RESTRICTED_METHOD ) {
            // This will now need to check the method and function to call.
            if( sizeof(security[board]) == 2 )
                call_other( security[board][1], security[board][0],
                    B_ACCESS_INFORM, board, 0, cap_name, irp );
        }

        if( !( priv[board] & B_PRIV_NO_INFORM ) ) {
            event( filter( users(), (: test_can_read( $2, PO,
                $1->query_name() ) :), board ), "inform", sprintf(
                "%s posts a message to %s and %d message%s in sympathy%s",
                cap_name, board, irp, ( irp > 1 ? "s explode" : " explodes"),
                from_mess ), "message");
        }
    } else {
        if( ( priv[board] & B_PRIV_TYPE_MASK ) == B_PRIV_ACCESS_RESTRICTED_METHOD ) {
            // This will now need to check the method and function to call.
            if( sizeof(security[board]) == 2 )
                call_other( security[board][1], security[board][0],
                    B_ACCESS_INFORM, board, 0, cap_name, 0 );
        }
        if( !( priv[board] & B_PRIV_NO_INFORM ) ) {
            event( filter( users(), (: test_can_read( $2, PO,
                $1->query_name() ) :), board ),"inform", sprintf(
                "%s posts a message to %s%s", cap_name, board, from_mess ),
                "message");
        }
    }

    return num-1;

} /* add_message() */

/**
 * This method creates a new board.
 * @param board the name of the board to create
 * @param privileges is this board only allowed priviliged access?
 * @param person the person to add into the security array initially
 * @return 0 on a failure, 1 on success
 */
int create_board( string board, int privileges, string person ) {

    if( file_name(PO) != "/secure/cmds/admin/boardtool" )
        return 0;

    if( boards[board] )
        return 0;

    if( !person )
        person = TP->query_name();

    boards[board] = ({ });
    security[board] = ({ person });

    if( privileges )
        priv[board] = privileges;

    save_me();
    return 1;

} /* create_board() */

/**
 * Adds a member into the security array for a board.  This allows
 * certain people to read boards they may not normaly have
 * access to.
 * @param board the board to change the access on
 * @param name the name of the person to add to the array
 * @return 0 on failure, 1 on success
 */
int add_allowed( string board, string name ) {
    string nam;
    int board_type;

    board_type = priv[board] & B_PRIV_TYPE_MASK;

    if( sscanf( file_name(PO), "/obj/misc/board%s", nam ) != 1 )
        return 0;

    nam = (string)TP->query_name();

    if( !test_can_write( board, PO, nam ) ||
        ( board_type != B_PRIV_ACCESS_RESTRICTED &&
        board_type != B_PRIV_READ_ONLY &&
        board_type != B_PRIV_ACCESS_RESTRICTED_FILE ) )
        return 0;

    if( !PLAYER_H->test_user(name) )
        return 0;

    security[board] += ({ name });
    save_me();

    printf("Added %s to the security array for %s.\n", name, board );
    return 1;

} /* add_allowed() */

/**
 * Remove someone from the allowed array of the board.
 * @param board the board to remove the person from
 * @param name the name of the person to remove
 * @return 0 on nfailure and 1 on success
 */
int remove_allowed( string board, string name ) {
    string nam;
    int i, board_type;

    if( sscanf( file_name(PO), "/obj/misc/board%s", nam ) != 1 )
        return 0;

    nam = geteuid(PO);
    board_type = priv[board] & B_PRIV_TYPE_MASK;

    if( !test_can_write( board, PO, nam ) ||
        ( board_type != B_PRIV_ACCESS_RESTRICTED &&
        board_type != B_PRIV_READ_ONLY &&
        board_type != B_PRIV_ACCESS_RESTRICTED_FILE ) )
        return 0;

    security[board] = delete( security[board], i, 1 );
    save_me();

    printf("Removed %s from the security array for %s.\n", name, board );
    return 1;

} /* add_allowed() */

/**
 * This method sets the method to call to check for allowed postings
 * to a board setup as an method controlled post board.
 * @param board the name of the board to setup the method for
 * @param method the method to call on the object
 * @param name the object to call the method on
 * @return 0 if the method failed, 1 if it was successful
 */
int set_method_access_call( string board, string method, string name ) {
    string pl;

    if( !boards[board] ||
        ( priv[board] & B_PRIV_TYPE_MASK ) != B_PRIV_ACCESS_RESTRICTED_METHOD )
        return 0;

    if( TP )
        pl = (string)TP->query_name();
    else
        pl = "unknown";

    if( lordp(pl) || file_name(PO) == CLUB_HANDLER ) {
        security[board] = ({ method, name });
        save_me();
        return 1;
    }

    return 0;

} /* set_method_access_call() */

/**
 * This method changes the type of the board to be a method access call
 * access restriction, instead of whatever it had before.
 * @param board the name of the board to control the access for
 */
int force_board_method_access_restricted( string board ) {
    string pl;

    if( !boards[board] )
        return 0;

    if( TP )
        pl = (string)TP->query_name();
    else
        pl = "unknown";

    if( lordp(pl) || file_name(PO) == CLUB_HANDLER ) {
        priv[board] = ( priv[board] & ~B_PRIV_TYPE_MASK ) |
                        B_PRIV_ACCESS_RESTRICTED_METHOD;
        save_me();
        return 1;
    }

    return 0;

} /* force_board_method_access_restricted() */

/**
 * Check to see if the named person can delete the message.
 * @param pname the player name
 * @param board the board name
 * @param off the offset to delete
 * @see delete_message()
 */
int can_delete_message( string board, int off, string pname ) {
    if( !boards[board] )
        return 0;

    if( off >= sizeof(boards[board]) )
        return 0;

    if( !test_can_delete( board, PO, pname ) &&
        ( lower_case(boards[board][off][B_NAME]) != lower_case(pname) ) )
        return 0;

    return 1;

} /* can_delete_message() */

/**
 * Remove a message from a board.  The offset is the offset into the
 * subjects array.
 * @param board the board to remove the message from
 * @param off the offset to delete
 * @param override_name used by the web boards
 * @return 0 on failure and 1 on success
 */
int delete_message( string board, int off, string override_name ) {
    string nam;

    nam = ( file_name(PO) == BOARD_WEB ?
            override_name : TP->query_name() );

    if( !can_delete_message( board, off, nam ) )
        return 0;

    return zap_message( board, off );

} /* delete_message() */

/**
 * Returns the security array for the given board.
 * @param board the board to get the security array for
 * @return the security array
 */
string *query_security( string board ) {
    string *str;

    str = security[board];

    if( !str )
        return str;

    return copy(str);

} /* query_security() */

/**
 * Complete erase a board.
 * @param board the board to delete
 * @return 0 on failure and 1 on success
 */
int delete_board( string board ) {
    string nam;

    if( file_name(PO) != "/secure/cmds/admin/boardtool")
        return 0;

    if( !boards[board] )
        return 0;

    nam = geteuid(PO);

    if( !lordp(nam) || file_name(PO) == CLUB_HANDLER )
        return 0;

    while( sizeof(boards[board]) ) {
        if( !zap_message( board, 0 ) )
            return 0;
    }

    map_delete( boards, board );
    map_delete( security, board );
    map_delete( priv, board );
    map_delete( archives, board );
    map_delete( timeouts, board );

    board = BOARD_DIR + replace( board, ({" ", "_", "'", ""}) ) + "/";

    // Delete its directory as well if its empty.
    if( dir_exists(board) && !sizeof( get_dir(board) ) )
        unguarded( (: rmdir, board :) );

    save_me();
    return 1;

} /* delete_board() */

/**
 * This method returns the list of www boards for the
 * specified player name.
 * @param name the name of the player to get the board list for
 * @return the list of www boards for the player
 */
string *list_of_www_boards( string name ) {
    string *www_boards, board;

    www_boards = ({ });

    foreach( board in keys(boards) ) {
        if( !boards[board] )
            continue;

        if( priv[board] ) {
            int bit;

            bit = priv[board] & B_PRIV_TYPE_MASK;

            if( bit == B_PRIV_ACCESS_RESTRICTED && !lordp(name) &&
                member_array( name, security[board] ) == -1 )
                continue;

            if( bit == B_PRIV_ACCESS_ADMIN && !adminp(name) &&
                member_array( name, security[board] ) == -1 )
                continue;

            if( bit == B_PRIV_ACCESS_RESTRICTED_METHOD && !lordp(name) &&
                !( sizeof(security[board]) == 2 && call_other(
                security[board][1], security[board][0], B_ACCESS_READ,
                board, PO, name ) ) )
                continue;
        }

        www_boards += ({ board });

    }

    return www_boards;

} /* list_of_www_boards() */

/**
 * Change the time before a message automatic gets deleted off a
 * board.
 * @param board the name of the board to set the timeout for
 * @param timeout the timeout (in seconds)
 * @return 0 on failure and 1 on success
 */
int set_timeout( string board, int timeout ) {
    string nam;

    if( !boards[board] )
        return 0;

    if( board == "bugs")
        return 0;

    nam = geteuid(PO);

    if( !test_can_write( board, PO, nam ) )
        return 0;

    if( !timeouts[board] ) {
        timeouts[board] = ({ DEFAULT_MIN, DEFAULT_MAX, timeout });
        return 1;
    }

    timeouts[board][T_TIMEOUT] = timeout;
    save_me();

    printf("Set the automagic timeout to %d days for %s.\n", timeout, board );
    return 1;

} /* set_timeout() */

/**
 * Sets the minimum number of message to keep on a board.
 * If there is less than this number then they will not be auto deleted.
 * @param board the board to set the minimum for
 * @param min the number of message to keep
 * @return 0 on failure and 1 on success
 */
int set_minimum( string board, int min ) {
    string nam;

    if( !boards[board] )
        return 0;

    nam = geteuid(PO);

    if( !test_can_write( board, PO, nam ) )
        return 0;

    if( !timeouts[board] ) {
        timeouts[board] = ({ min, DEFAULT_MAX, DEFAULT_TIMEOUT });
        return 1;
    }

    timeouts[board][T_MIN] = min;
    save_me();

    printf("Set the minimum number of messages to %d for %s.\n", min, board );
    return 1;

} /* set_minimum() */

/**
 * Set the maximum number of message before they start being auto deleted
 * when someone posts to the board.
 * @param board the board to set the maximum for
 * @param max the maximum number of messages
 * @return 0 if it failed and 1 on success
 */
int set_maximum( string board, int max ) {
    string nam;

    if( !boards[board] )
        return 0;

    nam = geteuid(PO);

    if( !test_can_write( board, PO, nam ) )
        return 0;

    if( !timeouts[board] ) {
        timeouts[board] = ({ DEFAULT_MIN, max, DEFAULT_TIMEOUT });
        return 1;
    }

    timeouts[board][T_MAX] = max;
    save_me();

    printf("Set the maximum number of messages to %d for %s.\n", max, board );
    return 1;

} /* set_maximum() */

/**
 * Set the archive file location.  This is where all deleted messages
 * wil be stored.
 * @param board the board to set the archive for
 * @param file the file name to set it to
 * @return 0 on failure and 1 on success
 */
int set_archive( string board, string file ) {
    string nam;

    if( !boards[board] )
        return 0;

    nam = geteuid(PO);

    if( !test_can_write( board, PO, nam ) )
        return 0;

    if( !file || file == "" )
        map_delete( archives, board );
    else
        archives[board] = file;
    save_me();

    printf("Set the archive file to %s for %s.\n", file, board );
    return 1;

} /* set_archive() */

/**
 * Return the timeout time of the board.
 * @param board the board to get the timeout for
 * @return the timeout in seconds
 * @see set_timeout()
 */
int query_timeout( string board ) {
    if( !timeouts[board] )
        return 0;
    return timeouts[board][T_TIMEOUT];
} /* query_timeout() */

/**
 * Return the minimum number of message allowed on the board.
 * @param board the board to get the minimum numbr of message for
 * @return 0 on failure, the minimum number of messages on success
 */
int query_minimum( string board ) {
    if( !timeouts[board] )
        return 0;
    return timeouts[board][T_MIN];
} /* query_minimum() */

/**
 * Return the maximum number of message allowed on the board.
 * @param board the board to get the maximum numbr of message for
 * @return 0 on failure, the maximum number of messages on success
 */
int query_maximum( string board ) {
    if( !timeouts[board] )
        return 0;
    return timeouts[board][T_MAX];
} /* query_maximum() */

/**
 * This method checks to see if the board is in restricted access mode.
 * @param board the name of the board to check
 * @return 1 if it is, 0 if it is not
 */
int query_restricted_access( string board ) {
    return (priv[board] & B_PRIV_TYPE_MASK) == B_PRIV_ACCESS_RESTRICTED;
} /* query_restricted_access() */

/**
 * This method checks to see if the board is in restricted access file
 * mode.
 * @param board the name of the board to check
 * @return 1 if it is, 0 if it is not
 */
int query_restricted_access_file( string board ) {
    return (priv[board] & B_PRIV_TYPE_MASK) == B_PRIV_ACCESS_RESTRICTED_FILE;
} /* query_restricted_access_file() */

/**
 * This method checks to see if the board is in a read only mode.
 * @param board the name of the board to check
 * @return 1 if it is read only, 0 if not
 */
int query_read_only( string board ) {
    return (priv[board] & B_PRIV_TYPE_MASK) == B_PRIV_READ_ONLY;
} /* query_read_only() */

/**
 * This method checks to see if the board is in a no inform mode.
 * @param board the name of the board to check
 * @return 1 if it is no inform, 0 if not
 */
int query_no_inform( string board ) {
    return priv[board] & B_PRIV_NO_INFORM;
} /* query_no_inform() */

/**
 * This method returns the current privilege level of the board in
 * question.  This should be used for testing only.
 * @return the current privilege level
 */
int query_privilage( string board ) { return priv[board]; }

/**
 * This method runs through all the messages and expires any which are
 * too old.
 */
private void expire_boards() {
    string nam;
    int tim, num, *val;

    foreach( nam, val in timeouts ) {
        if( nam == "bugs")
            continue;
        num = 0;
        if( ( tim = val[T_TIMEOUT] ) &&
            sizeof(boards[nam]) > val[T_MIN] &&
            boards[nam][0][B_TIME]+(tim*(24*60*60)) < time() ) {
            // Got to delete some...
            while( sizeof(boards[nam]) > val[T_MIN] &&
                boards[nam][0][B_TIME]+(tim*24*60*60) < time() ) {
                zap_message( nam, 0 );
                num++;
            }
            event( filter( users(), (: test_can_read( $2, PO,
                $1->query_name() ) :), nam ), "inform",
                sprintf("Board handler removes %d message"+
                ( num > 1 ? "s" : "")+" from %s", num, nam ), "message");
        }
    }

    call_out( (: expire_boards :), 60*60 );

} /* expire_boards() */

/**
 * The current max board number.
 * @return the current max board number
 */
int query_num() { return num; }

/** @ignore yes */
int load_newsrc( string player ) {
    string fname, board;

    if( !PLAYER_H->test_user( player ) )
        return 0;

    _newsrc_reads++;

    if( _newsrc_cache[player] ) {
        _newsrc_cache_hits++;
        return 1;
    }

    fname = NEWSRC_SAVE_DIR+player[0..0]+"/"+player+".o";

    if( unguarded( (: file_size( $(fname) ) :) ) > 0 ) {
        _newsrc_cache[player] =
            unguarded( (: restore_variable( read_file($(fname)) ) :) );
        if( arrayp(_newsrc_cache[player]->newsrc) ) {
            _newsrc_cache[player]->newsrc = ([ ]);
            if( find_call_out("flush_newsrc") == -1 )
                call_out("flush_newsrc", NEWSRC_SAVE_DELAY );
        }
    } else {
        _newsrc_cache[player] = new( class newsrc, cached : time(),
            kill : ({ }), newsrc : ([ ]), board_order : ({ }) );
        if( PLAYER_H->test_property( player, NEWS_RC ) )
            _newsrc_cache[player]->newsrc =
                PLAYER_H->test_property( player, NEWS_RC );
        if( PLAYER_H->test_property( player, BOARD_ORDER ) )
            _newsrc_cache[player]->board_order =
                PLAYER_H->test_property( player, BOARD_ORDER );

        foreach( board in keys(boards) )
            if( PLAYER_H->test_property( player, "news_kill_"+board ) )
                _newsrc_cache[player]->kill += ({ board });

        _newsrc_cache[player]->changed = 1;

        if( find_call_out("flush_newsrc") == -1 )
            call_out("flush_newsrc", NEWSRC_SAVE_DELAY );
    }

    if( sizeof( _newsrc_cache[player]->board_order ) ) {
        string *a;

        a = filter( _newsrc_cache[player]->board_order, (: !is_board($1) :) );

        if( sizeof(a) ) {
            _newsrc_cache[player]->board_order -= a;
            _newsrc_cache[player]->changed = 1;
        }
    }

    return 1;

} /* load_newsrc() */

/** @ignore yes */
void flush_newsrc() {
    string fname, player, board;
    object ob;

    foreach( player in keys(_newsrc_cache) ) {
        if( !_newsrc_cache[player]->changed )
            continue;

        fname = NEWSRC_SAVE_DIR+player[0..0]+"/"+player+".o";

        // Save their file.
        if( unguarded( (: file_size($(fname)) :) ) > 0 ) {
            unguarded( (: write_file($(fname),
                save_variable(_newsrc_cache[$(player)]), 1 ) :) );
        } else if( ob = find_player(player) ) {
            // If they're around and don't have a file then write a new one
            // and clear their properties.
            unguarded( (: write_file($(fname),
                  save_variable(_newsrc_cache[$(player)]), 1 ) :) );
            ob->remove_property(NEWS_RC);
            ob->remove_property(BOARD_ORDER);
            foreach( board in keys(boards) )
                ob->remove_property("news_kill_"+lower_case(board) );
        } else {
            // They're not around and they don't have a file so just
            // update their properties.
            // I don't like this.
            // - Sandoz.
            LOGIN_OBJ->special_add_property( player, NEWS_RC,
                _newsrc_cache[player]->newsrc );
        }
        _newsrc_cache[player]->changed = 0;
    }
} /* flush_newsrc() */

/**
 * This method returns a player's newsrc.
 * @param string the name of the player
 * @return their newsrc mapping
 */
mapping query_newsrc( string player ) {
    if( !load_newsrc(player) )
        return ([ ]);

    _newsrc_cache[player]->cached = time();

    return _newsrc_cache[player]->newsrc;

} /* query_newsrc() */

/**
 * This method sets a player's newsrc.
 * @param string the name of the player
 * @param newsrc their new newsrc
 * @return 1 for success, 0 for failure
 */
int set_newsrc( string player, mapping newsrc ) {
    if( !load_newsrc(player) )
        return 0;

    _newsrc_cache[player]->newsrc = (mapping)newsrc;
    _newsrc_cache[player]->cached = time();
    _newsrc_cache[player]->changed = 1;

    if( find_call_out("flush_newsrc") == -1 )
        call_out("flush_newsrc", NEWSRC_SAVE_DELAY );

    return 1;

} /* set_newsrc() */

/**
 * Find out if a given board is in a player's killfile.
 * @param string the name of the player
 * @param string the name of the board (in lowercase)
 * @return 1 if it is, 0 if it isn't
 */
int query_killfile( string player, string board ) {
    if( !load_newsrc( player ) )
        return 0;

    _newsrc_cache[player]->cached = time();

    return member_array( board, _newsrc_cache[player]->kill ) != -1;

} /* query_killfile() */

/**
 * Add a board to someone's killfile.
 * @param string the name of the player
 * @param string the name of the board (in lowercase)
 * @return 1 for success, 0 for failure
 */
int set_killfile( string player, string board ) {
    if( !load_newsrc(player) )
        return 0;

    if( member_array( board, _newsrc_cache[player]->kill ) != -1 )
        return 1;

    _newsrc_cache[player]->kill += ({ board });
    _newsrc_cache[player]->changed = 1;
    _newsrc_cache[player]->cached = time();

    if( find_call_out("flush_newsrc") == -1 )
        call_out("flush_newsrc", NEWSRC_SAVE_DELAY );

    return 1;

} /* set_killfile() */

/**
 * This method removed a player's killfile.
 * @param player the player whose killfile to remove
 * @param the board to remove the killfile for
 * @return 1 upon success, 0 upon failure
 */
int remove_killfile( string player, string board ) {
    if( !load_newsrc(player) )
        return 0;

    if( member_array( board, _newsrc_cache[player]->kill ) == -1 )
        return 1;

    _newsrc_cache[player]->kill -= ({ board });
    _newsrc_cache[player]->changed = 1;
    _newsrc_cache[player]->cached = time();

    if( find_call_out("flush_newsrc") == -1 )
        call_out("flush_newsrc", NEWSRC_SAVE_DELAY );

    return 1;

} /* remove_killfile() */

/**
 * This method returns a player's killfile list.
 * @param string the players name
 * @return the array of boards in their killfile
 */
string *list_killfile( string player ) {
    if( !load_newsrc(player) )
        return ({ });

    return _newsrc_cache[player]->kill;

} /* list_killfile() */

/**
 * This method returns a player's board order.
 * @param string the players name
 * @return the list of boards, in order
 */
string *query_board_order( string player ) {
    if( !load_newsrc(player) )
        return ({ });

    _newsrc_cache[player]->cached = time();

    if( !_newsrc_cache[player]->board_order )
        return ({ });

    return _newsrc_cache[player]->board_order;

} /* query_board_order() */

/**
 * This method returns the board order for a given player.
 * @param string a players name
 * @param new_order the list of boards
 * @return 1 for success, 0 for failure
 */
int set_board_order( string player, string *new_order ) {
    if( !load_newsrc(player) )
        return 0;

    _newsrc_cache[player]->board_order = new_order;
    _newsrc_cache[player]->changed = 1;
    _newsrc_cache[player]->cached = time();

    if( find_call_out("flush_newsrc") == -1 )
        call_out("flush_newsrc", NEWSRC_SAVE_DELAY );

    return 1;

} /* set_board_order() */

/**
 * @ignore yes
 * Prevents us from being shadowed.
 */
int query_prevent_shadow() { return 1; }

/** @ignore yes */
void query_cache() {
    printf("The messages being cached are (sorted by last hit):\n%-*#s\n",
        (int)TP->query_cols(), implode( map( sort_array( keys(message_cache),
        (: sort_by_last( $1, $2 ) :) ),
        (: sprintf("%i ("+$2[$1]->last+")", $1 ) :), message_cache ), "\n") );
} /* query_cache() */

/**
 * This method is called when a player is deleted by bulk_delete,
 * and will delete their post history and newsrc.
 * @param name the name of the player being deleted
 */
void delete_player( string name ) {
    if( file_name(PO) != BULK_DELETE_H )
        return;

    if( !undefinedp( posted_stuff[name] ) ) {
        map_delete( posted_stuff, name );
        save_me();
    }

    if( _newsrc_cache[name] )
        map_delete( _newsrc_cache, name );

    unguarded( (: rm, NEWSRC_SAVE_DIR+name[0..0]+"/"+name+".o" :) );

} /* delete_player() */

/** @ignore yes */
mixed stats() {
    if( !total_reads )
        total_reads = 1;
    if( !cache_hits )
        cache_hits = 1;
    if( !_newsrc_reads )
        _newsrc_reads = 1;

    return ({
      ({"messages read", total_reads }),
      ({"cache hit percent", ( cache_hits * 100 ) / total_reads }),
      ({"messages in cache", sizeof(message_cache) }),
      ({"newsrc reads", _newsrc_reads }),
      ({"newsrc hit percent", ( _newsrc_cache_hits * 100 ) / _newsrc_reads }),
      ({"newsrcs in cache", sizeof(_newsrc_cache) }),
      ({"current post number", num }),
    });
} /* stats() */

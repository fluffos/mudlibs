/**
 * The leaflet handler keeps track of pages in leaflets,
 * so that each of 100 identical leaflets won't have to
 * store all text in their save files.  It also caches
 * the data a little to reduce disk access.
 * @author Sandoz, 2002.
 */

#include <leaflet.h>
#include <language.h>
#include <origin.h>

#define LEAFLET_SAVE_DIR   SAVE_DIR "/leaflets/"
#define PRINT_RUN_SAVE_DIR LEAFLET_SAVE_DIR "print_runs/"

#define FILE(x)            LEAFLET_SAVE_DIR+x
#define PRINTER_DIR(x)     PRINT_RUN_SAVE_DIR+x+"/"

#define MAX_CACHE          5
#define DAY                (60*60*24)
#define TIME_OUT           (DAY*30)

/**
 * This class stores the data for a specific leaflet.
 * @member author the person who printed the leaflet
 * @member id the id of the leaflet
 * @member created the time this leaflet was created
 * @member time the time this leaflet was last accessed
 * @member text the content of the leaflet
 * @member copyright the copyright holder of the leaflet
 */
class leaflet_data {
    string author;
    int id;
    int created;
    int time;
    mixed text;
    string copyright;
}

/**
 * This class stores the data for different printers.
 * @member name the name of the printer
 * @member long the long desc of their leaflets
 */
class printer_data {
    string name;
    string long;
}

/**
 * This method stores the data for a single player
 * in the specified print shop.
 * @member id the id of the shop the data is for
 * @member name the name of the player the data is for
 * @member works the pending works for the player in the shop
 */
class player_print_data {
    int id;
    string player;
    class print_data *works;
}

private int *banned;
private mapping printers, copy;

private nosave mapping cache;
private nosave int current_id;
private nosave class player_print_data current_player_data;
private nosave string *shops;

private void clean_shop();
private void expire_print_runs();

private void save_me() {
    unguarded( (: save_object, LEAFLET_SAVE_DIR+"main" :) );
} /* save_me() */

/** @ignore yes */
void create() {
    if( !unguarded( (: dir_exists, LEAFLET_SAVE_DIR :) ) )
        unguarded( (: mkdir, LEAFLET_SAVE_DIR :) );

    if( !unguarded( (: dir_exists, PRINT_RUN_SAVE_DIR :) ) )
        unguarded( (: mkdir, PRINT_RUN_SAVE_DIR :) );

    if( unguarded( (: file_exists, LEAFLET_SAVE_DIR+"main.o" :) ) )
        unguarded( (: restore_object, LEAFLET_SAVE_DIR+"main" :) );

    cache = ([ ]);

    if( !banned )
        banned = ({ });

    if( !mapp(printers) )
        printers = ([ ]);

    if( !mapp(copy) )
        copy = ([ ]);

    expire_print_runs();

} /* create() */

/**
 * This method returns the time after which unclaimed print
 * runs expire and are deleted.
 */
int query_time_out() { return TIME_OUT; }

/** @ignore yes */
private void delete_new_leaflet( class print_data data ) {
    object ob;

    if( ob = clone_object( data->file ) ) {
        int id;

        if( data->save ) {
            if( data->save[0] )
                ob->init_static_arg( data->save[0] );
            if( data->save[1] )
                ob->init_dynamic_arg( data->save[1] );
        }

        if( intp( id = ob->query_leaflet_id() ) && id > 0 ) {
            unguarded( (: rm, FILE(id) :) );
            map_delete( cache, id );
        }

        ob->dest_me();
    }

    if( ob )
        destruct(ob);

} /* delete_new_leaflet() */

/**
 * This method is called by the refresh handler.
 * @param name the name of the player being refreshed
 */
void player_refreshed( string name ) {
    string *all, file;

    if( origin() != ORIGIN_LOCAL && PO != find_object(REFRESH_H) )
        return;

    if( !sizeof( all = unguarded( (: get_dir, PRINT_RUN_SAVE_DIR :) ) ) )
        return;

    foreach( file in all ) {
        file = PRINTER_DIR(file)+name+".o";
        if( unguarded( (: file_exists, file :) ) ) {
            class player_print_data data;

            data = restore_variable( unguarded( (: read_file, file :) ) );

            if( classp(data) ) {
                class print_data run;

                foreach( run in data->works )
                    if( run->new_leaflet )
                        delete_new_leaflet( run );
            }

            unguarded( (: rm, file :) );
        }
    }

    current_player_data = 0;

} /* player_refreshed() */

/** @ignore yes */
private void clean_shop() {
    class player_print_data data;
    class print_data run;
    string shop, *players, player;

    if( sizeof(shops) ) {
        shop = PRINTER_DIR(shops[0]);
        shops = shops[1..];
    }

    if( !sizeof(shops) )
        call_out( (: expire_print_runs() :), DAY );
    else
        call_out( (: clean_shop() :), 60 );

    if( !sizeof( players = unguarded( (: get_dir, shop :) ) ) ) {
        unguarded( (: rmdir, shop :) );
        return;
    }

    foreach( player in players ) {
        if( !PLAYER_H->test_user( player[0..<3] ) ) {
            player_refreshed( player[0..<3] );
            continue;
        }

        player = shop + player;
        data = restore_variable( unguarded( (: read_file, player :) ) );

        if( !classp(data) ) {
            unguarded( (: rm, player :) );
            continue;
        }

        foreach( run in data->works ) {
            if( run->time + TIME_OUT < time() ) {
                data->works -= ({ run });
                if( run->new_leaflet )
                    catch( delete_new_leaflet( run ) );
            }
        }

        if( !sizeof(data->works) )
            unguarded( (: rm, player :) );

    }

    if( !sizeof( unguarded( (: get_dir, shop :) ) ) ) {
        unguarded( (: rmdir, shop :) );
        return;
    }

} /* clean_shop() */

/** @ignore yes */
private void expire_print_runs() {
    if( !sizeof( shops = unguarded( (: get_dir, PRINT_RUN_SAVE_DIR :) ) ) ) {
        call_out( (: expire_print_runs() :), DAY );
        return;
    }

    call_out( (: clean_shop() :), 60 );

} /* expire_print_runs() */

/** @ignore yes */
private void check_cache() {
    if( sizeof(cache) > MAX_CACHE && find_call_out("clean_cache") == -1 )
        call_out("clean_cache", 1 );
} /* check_cache() */

/** @ignore yes */
private int load_leaflet( int id ) {
    class leaflet_data leaflet;

    if( cache[id] ) {
        ((class leaflet_data)cache[id])->time = time();
        return 1;
    }

    if( !intp(id) || !file_exists( FILE(id) ) )
        return 0;

    leaflet = restore_variable( unguarded( (: read_file, FILE(id) :) ) );
    leaflet->time = time();
    cache[id] = leaflet;

    check_cache();
    return 1;

} /* load_leaflet() */

/** @ignore yes */
private void save_leaflet( int id ) {
    if( !cache[id] )
        return;

    unguarded( (: write_file, FILE(id), save_variable( cache[id] ), 1 :) );

} /* save_leaflet() */

/**
 * This method deletes a leaflet by id.  Use with care.
 * @param id the id of the leaflet to delete
 * @return 1 upon success, 0 upon failure
 */
int delete_leaflet( int id ) {
    if( !lordp(TP) && !sizeof( filter( previous_object(-1),
        (: $1->query_leaflet_shop() :) ) ) ) {
        write("Sorry, only lords can delete leaflets.\n");
        return 0;
    }

    if( !id || !intp(id) )
        return 0;

    unguarded( (: rm, FILE(id) :) );
    map_delete( cache, id );
    return 1;

} /* save_leaflet() */

/**
 * This method returns the leaflets that have been banned.
 * @return the banned leaflets
 */
int *query_banned() { return banned; }

/**
 * This method bans a leaflet with a specified id.
 * Use with care.
 * @param id the id to ban
 * @return 1 upon success, 0 upon failure
 */
int ban_leaflet( int id ) {
    if( !lordp(TP) ) {
        write("Sorry, only lords can ban leaflets.\n");
        return 0;
    }

    if( !intp(id) || member_array( id, banned ) != -1 )
        return 0;

    banned += ({ id });
    save_me();
    return 1;

} /* ban_leaflet() */

/**
 * This method removes the ban from a specified leaflet id.
 * It is practically useless, as no ids should be unbanned,
 * unless you're absolutely certain there are no leaflets
 * left in game with the id.
 * @param id the id to unban
 */
void unban_leaflet( int id ) {
    if( lordp(TP) )
        banned -= ({ id });
    save_me();
} /* unban_leaflet() */

/**
 * @ignore yes
 * This method cleans up the cache.
 */
void clean_cache() {
    int *ids, id;
    function f;

    if( sizeof(cache) <= MAX_CACHE )
        return;

    f = function( mixed i, mixed j ) {
            i = ((class leaflet_data)cache[i])->time;
            j = ((class leaflet_data)cache[j])->time;
            if( i < j )
                return 1;
            if( i > j )
                return -1;
            return 0;
        };

    ids = sort_array( keys(cache), f );
    ids = ids[MAX_CACHE..];

    // Update the time stamp and delete them from cache.
    foreach( id in ids ) {
        save_leaflet( id );
        map_delete( cache, id );
    }

} /* clean_cache() */

/**
 * This method figures out an id for a new leaflet.
 * @return the new id
 */
int query_new_id() {
    int id;

    id = current_id;

    while( unguarded( (: file_size, FILE(id) :) ) > 0 )
        id++;

    current_id = id + 1;

    return id;

} /* query_new_id() */

/**
 * This method creates a new leaflet and returns
 * the unique id number for it.
 * @param author the author of the leaflet
 * @param text the content of the leaflet
 * @param copyright the copyright holder of the leaflet
 * @return the unique id of the leaflet
 */
int new_leaflet( string author, mixed text, string copyright ) {
    class leaflet_data leaflet;
    int id, tmp;

    if( !sizeof(text) || !author || author == "")
        return 0;

    id = query_new_id();

    if( !sizeof(copyright) )
        copyright = 0;

    leaflet = new( class leaflet_data,
        author : author,
        id : id,
        created : time(),
        time : time(),
        text : text,
        copyright : copyright );

    cache[id] = leaflet;
    save_leaflet(id);

    if( copyright ) {
        tmp = sizeof( text[READ_MESS] );
        if( !pointerp(copy[tmp]) )
            copy[tmp] = ({ });
        copy[tmp] += ({ id });
        save_me();
    }

    check_cache();

    return id;

} /* new_leaflet() */

/**
 * This method copyrights the specified leaflet.
 * This fails if the leaflet already has a copyright holder.
 * @param id the id of the leaflet to copyright
 * @param copyright the copyright holder of the leaflet
 * @return 1 if successful, 0 if not
 */
int copyright_leaflet( int id, string copyright ) {
    int tmp;
    class leaflet_data data;

    if( !sizeof(copyright) || !load_leaflet( id ) ||
        ((class leaflet_data)cache[id])->copyright )
        return 0;

    ((class leaflet_data)cache[id])->copyright = copyright;
    ((class leaflet_data)cache[id])->time = time();
    save_leaflet(id);

    data = cache[id];
    tmp = sizeof( data->text[READ_MESS] );

    if( !pointerp(copy[tmp]) )
        copy[tmp] = ({ });
    copy[tmp] += ({ id });
    save_me();

    return 1;

} /* copyright_leaflet() */

/**
 * This method returns a mapping of all copyrighted leaflets.
 * It will be in the form of -
 * ([ tsize1 : ({ id1, id2 }), tsize2 : ({ id3 }) ]),
 * where tsize is the size of text on the leaflet, and ids are
 * the ids of leaflets with that same amount of text.
 * @return a mapping of all copyrighted leaflets
 */
mapping query_copyrighted() { return copy; }

/**
 * This method tests whether or not the text we are trying
 * to copy is under copyright.
 * @param text the text to test
 * @return the id of the leaflet we're identical with, 0 if not
 */
int query_copyright_protected( string text ) {
    int id, *arr;
    class leaflet_data data;

    if( !arr = copy[sizeof(text)] )
        return 0;

    foreach( id in arr )
        if( load_leaflet(id) ) {
            data = cache[id];
            if( data->text[READ_MESS] == text )
                return id;
        }

    return 0;

} /* query_copyright_protected() */

/** @ignore yes */
class leaflet_data query_leaflet_data( int id ) {
    if( !load_leaflet( id ) )
        return 0;

    ((class leaflet_data)cache[id])->time = time();

    return cache[id];

} /* query_leaflet_data() */

/**
 * This method returns the text for the specified leaflet id.
 * @param id the id to get the pages for
 * @return the text for the specified leaflet
 */
mixed query_text( int id ) {
    class leaflet_data data;

    if( member_array( id, banned ) != -1 )
        return ({"Sorry, your leaflet appears to have been banned.", 0,
            "common", 1 });

    if( !classp( data = query_leaflet_data(id) ) )
        return ({ });

    data->time = time();
    return data->text;

} /* query_text() */

/**
 * This method returns the author of the specified
 * leaflet.
 * @param id the id to get the author for
 * @return the author of the specified leaflet
 */
string query_author( int id ) {
    if( !load_leaflet( id ) )
        return 0;
    ((class leaflet_data)cache[id])->time = time();
    return ((class leaflet_data)cache[id])->author;
} /* query_author() */

/**
 * This method returns the person who holds the copyright of
 * the specified leaflet.
 * @param id the id to get the copyright for
 * @return the person holding the copyright of the leaflet
 */
string query_copyright( int id ) {
    if( !load_leaflet( id ) )
        return 0;
    ((class leaflet_data)cache[id])->time = time();
    return ((class leaflet_data)cache[id])->copyright;
} /* query_copyright() */

/** @ignore yes */
mapping query_cache() { return cache; }

/**
 * This method queries if the specified printer exists.
 * @param id the id of the printer to test
 * @return 1 if they exist, 0 if not
 */
int query_printer( int id ) { return !undefinedp(printers[id]); }

/**
 * This method returns the id of the specified printer name.
 * @param str the name of the printer to get the id for
 * @return the id, or 0 if there is none by the name
 */
int query_printer_id( string str ) {
    int id;
    class printer_data data;

    foreach( id, data in printers )
        if( data->name == str )
            return id;

    return 0;

} /* query_printer_id() */

/**
 * This method figures out a new id for a new printer.
 * @return the new printer id
 */
int query_new_printer_id() {
    int id;

    while( query_printer(++id) );

    return id;

} /* query_new_printer_id() */

/**
 * This method adds a new printer into the handler.
 * @param the name of the printer to add
 * @param the str desc of their leaflets
 * @return the new id of the printer, or 0 if we failed
 */
int add_printer( string name, string str ) {
    int id;
    class printer_data data;

    if( !name || name == "")
        return 0;

    if( id = query_printer_id( name ) )
        return id;

    if( !str || str == "")
        str = "This $size$ leaflet looks like it has been churned out from "
              "one of the cities' printing presses.";

    id = query_new_printer_id();

    data = new( class printer_data,
        name : name,
        long : str );

    printers[id] = data;
    save_me();
    return id;

} /* add_printer() */

/**
 * This method returns the long description of the
 * specified leaflet company.
 * @param id the id of the leaflet company to get the long desc for
 * @return the long desc for the company
 */
string query_leaflet_long( int id ) {
    if( !query_printer(id) )
        return "This $size$ leaflet looks like it has been churned out from "
               "one of the cities' printing presses.\n";

    return replace_string( printers[id]->long+"\n",
        "$shop$", printers[id]->name );

} /* query_leaflet_long() */

/**
 * This method sets the long description for leaflets
 * printed in the specified company.
 * @param id the printer id set the long desc for
 * @param str the long description
 * @return 1 upon success, 0 upon failure
 */
int set_leaflet_long( int id, string str ) {
    if( !query_printer(id) || !str || str == "")
        return 0;

    printers[id]->long = str;
    save_me();
    return 1;

} /* set_leaflet_long() */

/**
 * This method returns the name of the specified printing company.
 * @param id the id of the name to get
 * @return the name of the printer
 */
string query_printer_name( int id ) {
    if( !query_printer(id) )
        return "Leaflets Galore";

    return printers[id]->name;

} /* query_printer_name() */

/**
 * This method removes a printer.
 * @param id the id of the printer to remove
 * @return 1 if successfully removed, 0 if not
 */
int remove_printer( int id ) {
    if( !lordp(TP) ) {
        write("Sorry, only lords can remove printers.\n");
        return 0;
    }

    map_delete( printers, id );
    save_me();
    return 1;

} /* remove_printer() */

/**
 * This method returns all printers and their data.
 * @return all data for printers
 */
mapping query_printers() { return printers; }

/** @ignore yes */
string normalize_name( string name ) {
    int i;

    name = lower_case(name);

    for( i = 0; i < strlen(name); i++ ) {
        if( name[i] == ''' ) {
            name = name[0..i-1] + name[i+1..];
            i--;
            continue;
        }

        if( name[i] < 'a' || name[i] > 'z')
            name[i] = '_';
    }

    return implode( explode( name, "_") - ({ 0, "" }), "_");

} /* normalize_name() */

/**
 * This method restores the print runs for the specified player.
 * @param id the shop id to restore the player's print runs for
 * @param player the name of the player to restore the print runs for
 */
private int restore_current_player_data( int id, string player ) {
    class player_print_data data;
    string name;

    if( classp(current_player_data) && current_player_data->id == id &&
        current_player_data->player == player )
        return 1;

    if( !name = query_printer_name( id ) )
        return 0;

    name = normalize_name( name );

    if( unguarded( (: file_exists, PRINTER_DIR(name)+player+".o" :) ) ) {
        data = restore_variable( unguarded( (: read_file,
               PRINTER_DIR(name)+player+".o" :) ) );
        if( classp(data) ) {
            current_player_data = data;
            return 1;
        }
    }

    current_player_data = new( class player_print_data,
                               id     : id,
                               player : player,
                               works  : ({ }) );
    return 1;

} /* restore_current_player_data() */

/**
 * This method saves the print runs for the current player,
 * if the shop id and player name match.
 * @param id the shop id to save the player's print runs for
 * @param player the name of the player to save the print runs for
 */
private int save_current_player_data( int id, string player ) {
    string name;

    if( id != current_player_data->id ||
        player != current_player_data->player )
        return 0;

    if( !name = query_printer_name( id ) )
        return 0;

    name = normalize_name( name );

    if( unguarded( (: file_exists, PRINTER_DIR(name)+player+".o" :) ) &&
        ( !classp(current_player_data) ||
        !sizeof(current_player_data->works) ) ) {
        unguarded( (: rm, PRINTER_DIR(name)+player+".o" :) );
        current_player_data = 0;
        return 1;
    }

    if( !unguarded( (: dir_exists, PRINTER_DIR(name) :) ) )
        unguarded( (: mkdir, PRINTER_DIR(name) :) );

    return unguarded( (: write_file, PRINTER_DIR(name)+player+".o",
                         save_variable( current_player_data ), 1 :) );

} /* save_current_player_data() */

/**
 * This adds an object into the current set to be collected,
 * and saves the auto load info for the object.
 * @param name the name of the person adding the run
 * @param data the print run data
 * @return 1 if successfully added, 0 if not
 * @see query_print_run()
 * @see remove_print_run()
 */
int add_print_run( string name, class print_data data ) {
    if( !classp(data) || !sizeof(name) ||
        !restore_current_player_data( data->id, name ) )
        return 0;

    current_player_data->works += ({ data });

    return save_current_player_data( data->id, name );

} /* add_print_run() */

/**
 * This method returns the array of documents awaiting collection
 * for the specified player in the specified shop.  If there are
 * no documents, this returns 0.
 * @param id the id of the shop to get the documents for
 * @param name the player to get the documents for
 * @return an array containing the player information, or 0 if none
 * @see add_print_run()
 * @see remove_print_run()
 */
class print_data *query_print_run( int id, string name ) {
    if( !sizeof(name) || !restore_current_player_data( id, name ) ||
        !sizeof(((class player_print_data)current_player_data)->works) )
        return 0;

    return current_player_data->works;

} /* query_print_run() */

/**
 * This method will remove a players print run.
 * @param id the id of the shop to remove the print run in
 * @param name the player whose print run is to be removed
 * @param data the run to remove
 * @see add_print_run()
 * @see query_print_run()
 */
int remove_print_run( int id, string name, class print_data data ) {
    if( !sizeof(name) || !restore_current_player_data( data->id, name ) ||
        !sizeof(current_player_data->works) )
        return 0;

    current_player_data->works -= ({ data });

    return save_current_player_data( id, name );

} /* remove_print_run() */

class player_print_data query_current_player_data() {
    return current_player_data;
} /* query_current_player_data() */

/** @ignore yes */
void dest_me() { destruct(TO); }

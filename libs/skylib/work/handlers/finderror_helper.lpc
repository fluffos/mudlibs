/**
 * This handler contains the methods to handle the creators list of
 * directories to control bugs in.
 */
#include <config.h>

inherit ERRORS_BASE;

string name, *dirs;
nosave int _no_calls;

protected void recursive_add_dir( string word, string dir );

/**
 * This method initialises the data for a particular creator.
 * @param word the creator name to get the data for
 */
void init_data( string word ) {
    name = word;
    dirs = ({ });
} /* init_data() */

/**
 * This method loads up the data file for the particular player.
 * @param word the creator name to load the data for
 */
int get_data_file( string word ) {
    if( name != word ) {
        seteuid( geteuid(TP) );
        if( file_size("/w/"+word+"/finderror.o") > 0 ) {
            unguarded( (: restore_object, "/w/"+word+"/finderror" :) );
            name = word;
        } else {
            init_data( word );
            return 0;
        }
    }

    return 1;

} /* get_data_file() */

/**
 * The methods saves the information stored into the error information
 * in their directory.
 * @param word the player name to save the data for
 */
void save_data_file( string word ) {
    unguarded( (: save_object, "/w/"+word+"/finderror" :) );
} /* save_data_file() */

/**
 * This method gets the next directory which has an error in it from
 * the creators list of directories to search.
 * @param word the creator to get the next directory for
 */
string get_next_dir( string word ) {
    string dir, str, query;
    mixed ret;

    get_data_file( word );

    if( sizeof( dirs ) ) {
        query = "SELECT Id FROM errors WHERE Directory = '%s' AND Status = 'OPEN';";

        if( ret = init_errors( word, CONFIG_DB_USER ) )
            return 0;

        foreach( dir in dirs ) {
            ret = sql_query( word, query, dir[0..<2] );
            if( !stringp(ret) && ret > 0 ) {
                str = dir;
                break;
            }
        }

        if( str ) {
            dirs -= ({ str });
            dirs += ({ str });
            save_data_file( word );
        }

        finish_errors( word );
    }

    return str;

}  /* get_next_dir() */

/**
 * This method adds the directory to the creators directory list to check.
 * @param word the creator to add the directory to
 * @param dir the directory to add
 * @param recursive to add the directory recursively
 */
int add_dir( string word, string dir, int recursive ) {
    int res;

    get_data_file( word );

    res = member_array( dir, dirs );
    dirs -= ({ dir });
    dirs = ({ dir }) + dirs;

    if( recursive )  {
        _no_calls++;
        call_out( (: recursive_add_dir :), 1, word, dir );
    }

    save_data_file( word );
    return res;

}  /* add_dir() */

/**
 * This method adds all the subdirectories of the specified dir into the
 * search list.
 * @param word the creatro to add to the list of
 * @param dir the directory to recursively add to
 */
protected void recursive_add_dir( string word, string dir ) {
    mixed *directories, *file;

    _no_calls--;

    directories = get_dir( dir, -1 );

    if( directories ) {
        foreach ( file in directories ) {
            if( file[ 1 ] == -2 )
                add_dir( word, dir + file[ 0 ] +"/", 1 );
        }
    }

    if( !_no_calls ) {
        tell_object( find_player( word ), "All subdirectories have been "
            "added to the list.\n" );
    }

}  /* recursive_add_dir() */

/**
 * This method will remove a directory from the list that a player
 * checks.
 * @param word the creator to remove the directory from
 * @param dir the directory to remove
 * @param recursive to recursively remove them
 */
int remove_dir( string word, string dir, int recursive ) {
    int res, len;
    string d;

    get_data_file( word );

    if( recursive ) {
        len = sizeof( dir ) - 1;
        d = dir;
        dirs = filter( dirs, (: $1[ 0 .. $(len) ] != $(d) :) );
        res = 1;
    } else {
        res = member_array( dir, dirs );
        dirs -= ({ dir });
    }

    save_data_file( word );
    return res;

} /* remove_dir() */

/**
 * This method returns the list of dirs associated with this creator.
 * @param word the creator to look up the directories for
 * @return the array of directories
 */
string *query_dirs( string word ) {
    get_data_file( word );
    return dirs;
}  /* query_dirs() */

/**
 * This method returns the error counts for all the directories in the
 * list of directories to watch.
 * @param word the creator to get the dir count for
 */
string *query_dirs_count( string word ) {
    string dir, query, *result = ({ });
    int key, total = 0;
    mixed ret;

    get_data_file(word);

    if( dirs && sizeof(dirs) ) {
        key = time();

        if( ( ret = init_errors( key, CONFIG_DB_USER ) ) )
            return ({ sprintf("Error connecting to the errors database: %s", ret ) });

        query = "SELECT Id FROM errors WHERE Directory = '%s' AND Status = 'OPEN';";

        foreach( dir in dirs ) {
            ret = sql_query( key, query, dir[0..<2] );
            if( stringp(ret) ) {
                result += ({ sprintf("%s: %s", dir, ret ) });
                continue;
            }
            if( ret > 0 ) {
                total += ret;
                result += ({ sprintf("%s: %d", dir, ret ) });
            }
        }

        if( total )
            result += ({ sprintf("Total: %d", total ) });

        finish_errors(key);
    }

    return result;

} /* query_dirs_count() */

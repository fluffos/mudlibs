/**
 * By Sin
 */

#include <config.h>

inherit "/global/player/path";
inherit ERRORS_BASE;

string domain = "unset";
string tracker_name = "generic error tracker";
string error_file = "/ERROR_REPORTS";
string *other_dirs = ({ });
int period = 604800;
int nexttime;

nosave string *queue;
nosave string *messages;
nosave object tester;
nosave string save_file;
nosave int error_total;
nosave int typo_total;
nosave int idea_total;
nosave int key;

void do_the_work();

protected void save_me() {
    if( domain != "unset")
        unguarded( (: save_object, save_file, 0 :) );
} /* save_me() */

void create() {
    int retval;

    queue = ({ });
    messages = ({ });
    tester = 0;

    seteuid( master()->creator_file( file_name() ) );
    save_file = file_name();

    if( catch( retval = unguarded( (: restore_object, save_file, 1 :) ) ) ||
        !retval ) {
        string tmp;

        tmp = "/save/"+replace(file_name()[1..], "/", "_");
        if( catch( retval = unguarded( (: restore_object, tmp, 1 :) ) ) ||
            !retval ) {
            // The save file doesn't exist.  Try to make it here, then save.
            if( catch( save_me() ) )
                save_file = tmp;
        } else {
            save_file = tmp;
        }
    }

    if( !retval )
        nexttime = 0;

    if( nexttime < time() )
        do_the_work();
    else
        call_out("do_the_work", nexttime - time() );

} /* create() */

void dest_me() {
    save_me();
    if( key )
        finish_errors(key);
    destruct(TO);
} /* dest_me() */

nomask mixed dwep() {
    if( key )
        finish_errors(key);
    destruct(TO);
    return "Destructed With Extreme Prejudice";
} /* dwep() */

protected int post( string message ) {
    if( tester ) {
        tester->more_string(message);
        tester = 0;
        return 0;
    }

    return BOARD_H->add_message( domain, CAP(tracker_name),
        "Error summaries for "+CAP(domain), message);

} /* post() */

protected int *errors( string dir ) {
    mapping map;
    string query;
    mixed ret;
    int count;

    query = sprintf("SELECT Directory, Type FROM errors WHERE "
        "LEFT( Directory, %d ) = '%s' AND Status = 'OPEN' AND Type != 'Comment'\n",
        sizeof(dir), dir );

    map = ([ ]);

    if( stringp( ret = sql_query( key, query ) ) ) {
        log_file("ERROR_TRACKER",
            "%s Error counting reports for directory %s : %s\n",
            ctime(time()), dir, ret );
    } else if( ret ) {
        count = ret + 1;

        for( int i = 1; i < count; i++ ) {
            if( stringp( ret = get_row( key, i ) ) ) {
                log_file("ERROR_TRACKER",
                    "%s Error counting reports for directory %s : %s\n",
                    ctime(time()), dir, ret );
            } else {
                if( !map[ret["Directory"]] )
                    map[ret["Directory"]] = ([ ]);
                map[ret["Directory"]][ret["Type"]]++;
            }
        }
    }

    ret = "";

    foreach( dir in asort( keys(map) ) ) {
        mapping m;

        m = map[dir];

        ret += sprintf("%4d %4d %4d %s\n", m["BUG"], m["TYPO"], m["IDEA"], dir );
        error_total += m["BUG"];
        typo_total += m["TYPO"];
        idea_total += m["IDEA"];
    }

    return ret;

} /* errors() */

protected void iterate() {
    if( sizeof(queue) ) {
        string dir;

        dir = queue[0];

        if( sizeof(queue) > 1 )
            queue = queue[1..];
        else
            queue = ({ });

        messages += ({ errors(dir) });
        iterate();
    } else {
        string message;

        message = implode( messages - ({ 0 }), "");
        if( sizeof(message) == 0 ) {
            message = "Congratulations!  There are no errors in all of "+
                CAP(domain)+"!\n";
        } else {
            message = "There are reports in the following directories in "+
                CAP(domain)+":\n BUG TYPO IDEA\n" + message +
                sprintf("%4d %4d %4d TOTAL\n",
                error_total, typo_total, idea_total );
        }
        post(message);
        messages = ({ });
        finish_errors(key);
        key = 0;
    }
} /* iterate() */

void do_the_work() {
    string ret;

    if( domain == "unset")
        return;

    nexttime = time() + period;
    call_out("do_the_work", period );
    save_me();

    queue = ({"/d/"+domain }) + other_dirs;
    messages = ({ });
    error_total = 0;
    idea_total = 0;
    typo_total = 0;
    key = time();

    ret = init_errors( key, CONFIG_DB_USER );

    if( ret ) {
        log_file("ERROR_TRACKER", "%s Error initializing errors database for "
            "domain %s : %s\n", ctime(key), domain, ret );
        return;
    }

    iterate();

} /* do_the_work() */

varargs void test( string dir ) {
    mixed ret;

    tester = TP;

    if( dir && stringp(dir) && dir != "")
        queue = ({ dir });
    else
        queue = ({"/d/calarien"});

    messages = ({ });
    error_total = 0;
    idea_total = 0;
    typo_total = 0;
    key = time();

    if( ret = init_errors( key, CONFIG_DB_USER ) ) {
        printf("Error initializing errors database for directory %s : %s\n",
            dir, ret );
        return;
    }

    iterate();

} /* test() */

void set_name(string name) {
    tracker_name = name;
    save_me();
} /* set_name() */

void set_domain(string name) {
    domain = name;
    save_me();
} /* set_domain() */

void set_period(int length) {
    remove_call_out("do_the_work");
    nexttime -= period;
    period = length;
    nexttime += period;
    save_me();

    if( nexttime < time() )
        do_the_work();
    else
        call_out("do_the_work", nexttime - time() );

} /* set_period() */

void set_error_file(string name) {
    error_file = name;
    save_me();
} /* set_error_file() */

void set_other_dirs(string *others) {
    if( arrayp(others) )
        other_dirs = others;
    else
        other_dirs = ({ });
    save_me();
} /* set_other_dirs() */

mixed stats() {
    return ({
      ({"domain", domain }),
      ({"name", tracker_name }),
      ({"error file", error_file }),
      ({"period", period }),
      ({"next time", ctime(nexttime) }),
      ({"testing by", tester }),
      ({"queue length", sizeof(queue) }),
      ({"message length", sizeof(messages - ({ 0 })) }),
      ({"other dirs", sizeof(other_dirs) ? implode(other_dirs, ", ") : 0 }),
      ({"save file", save_file }),
    });
} /* stats() */

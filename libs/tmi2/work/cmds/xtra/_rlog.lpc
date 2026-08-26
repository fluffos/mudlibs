/* File:       _rlog.c
// Purpose:    displays only the log reports you havn't read.
// Credits:
// 93-07-10    Written by Grendel@tmi-2 (based on idea by Pallando)
//             Similar to _log.c but uses timestamps.
// 93-07-20    Altered by Grendel@tmi-2 to not show entries you make yourself
// 93-07-21    "all" option added by Pallando.
*/

#include <config.h>
#include <mudlib.h>

inherit DAEMON;

#define SYNTAX "Usage: rlog [ -<num> ] <logfile> | all\n"
#define DELIM "-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-"
#define REPORT_TYPES ({ "PRAISES", "IDEAS", "QUERIES", "BUGS", "TYPOS" })

mixed do_rlog( string path, int many, int arg_time )
{
    string contents, *entries, *output, *tmp, d_path, name;
    int i, num, cur_time, last_read;
 
    // calculate the path of the log
    path = LOG_DIR + path;
    
    // check the file exists and we can read it
    if(!file_exists(path)) {
	write("Log: " + path + " does not exist.\n");
	return 0;
    }
    if(!(contents=read_file(path))) {
	write("log: could not read "+path+"\n");
	return 0;
    }

    // calculate the current time, and the last time the file was read
    cur_time=time();
    d_path=replace_string(path,"/",".");
    last_read=(int)this_player()->query("logtimes/"+d_path);
    if(arg_time >= 0 && arg_time < last_read)
	last_read = arg_time;
    name=(string)this_player()->query("cap_name");
    if(undefinedp(last_read))
	last_read=0;

    // calculate the list of entries, and display them at the same time
    entries=filter_array(
	explode(contents,DELIM),"not_read",this_object(),({last_read,name}));

    // update the player's log time
    this_player()->set("logtimes/"+d_path,cur_time);

    // display the entries or report there were none
    if (!(num = sizeof(entries)))
    {
	if( many ) return 0;
	return ({ "No unread entries in " + path });
    } else {
        output = ({ });
        for (i = 0; i < num; i++) {
            tmp = explode(entries[i], "\n");
            tmp[0] = "[ " + tmp[0] + " ]";
            output += tmp;
        }
        return ({ path }) + output;
    }

    return 1;
}

int not_read(string entry, mixed *info)
{
    int i;
    string str, name;

    if(sscanf(entry,"%d\n%s at %s", i, name, str)!=3)
	return 0;
    
    if((name!=info[1]) && (i>=info[0]))
	return 1;
    
    return 0;
}

int cmd_rlog( mixed arg )
{
    int loop, size;
    string *output;
    mixed tmp;
    mixed path;
    int last_read, fixed_time;

    notify_fail( SYNTAX );
    if( !arg ) return 0;

    // if the argument contains a '-x' we get it, otherwise we treat
    // the whole argument as the path
    if( sscanf(arg, "-%d %s", fixed_time, path) == 2 ) {
	last_read = time() - (fixed_time * 24*60*60);
	if(last_read < 0)
	    last_read = 0;
    }
    else {
	last_read = -1;
	path = arg;
    }

    if(!path || path == "") return 0;
    if( path == "all" ) path = REPORT_TYPES;
    else path = ({ path });

    output = ({ });
    size = sizeof( path );
    for( loop = 0 ; loop < size ; loop++ )
        if( tmp = do_rlog( path[loop], ( size - 1 ), last_read ) )
            output += tmp;

    if( sizeof( output ) )
        this_player()-> more( output, 1 );

    return 1;
}

int help()
{
   write( SYNTAX + "\n" + @HELP
This wizard command is used to read special timestamped logs.  The
command displays all the entries that have been added to the log since
the last time the user used the command to read that particular log,
or if an number is given on the command line, all the entries that have
been added in the last <num> days.
Example: "rlog IDEAS"
HELP
    "The \"all\" option does " + implode( REPORT_TYPES, " " ) + "\n"
    );
   return 1;
}
/* EOF */

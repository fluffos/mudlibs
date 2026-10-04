//
// the "set" command
// Part of the TMI distribution mudlib (and Portals too!)
//
// Zak, 930610: cleaned up a lot, added restrictions for players.
// Pallando, 930908: Allowed for non-string vals
// Leto 21 Dec-94, unallowed ESC codes.

#include <uid.h>
#include <mudlib.h>
#include <ansi.h>

inherit DAEMON;


#define PLAYER_VALID ({ \
    "mail_notification", "mail_entry_unread", "mail_no_cc" \
     "prompt" \
})

nomask int valid_set(object them, string x)
{
    if (this_player()->link_data("wizard"))
	return 1;
    return (member_array(x, PLAYER_VALID) + 1);	// returns +ve if in VALID_SET
						// 0 otherwise.
}

int cmd_set(string arg)
{
    int i;
    string * vars;
    mixed val;
    string var;
    object act_ob;

    act_ob = previous_object();
    if (!arg)
    {
	vars = (string *)act_ob->regexp_query_env(".*");
	if (!vars || !sizeof(vars))
	{
	    notify_fail ("No environment variables set.\n");
	    return 0;
	}
        vars = sort_array(vars, "sort_set", this_object());
	printf("Environment variables:\n");
	i = sizeof(vars);
	while (i--)
            if( !undefinedp( val = act_ob->query_env(vars[i]) ) )
            {
                if( stringp( val ) )
                    printf("%-15s\t%s\n",vars[i],val);
                else
                    printf("%-15s\t%O\n",vars[i],val);
            }
	return 1;
    }
    // tricky bits are to stop the %d from interpreting
    // "set title 2 down!" as "set title 2"
    if ( ( ( sscanf(arg,"%s %d",var,val) != 2 ) || ( arg != var+" "+val ) ) &&
         (sscanf(arg,"%s %s",var,val) != 2)    )
    {
	val = "";
	var = arg;
    }
    if (   (   this_player(1) != previous_object()
	    && geteuid(previous_object()) != ROOT_UID )
	|| (   !valid_set(act_ob, var) ) )
    {
	printf("Sorry, you are not allowed to set the variable '%s'.\n",var);
	return 1;
    }
    if (var == "MVIS" || var == "MINVIS" || var == "MHOME" ||
      var == "MDEST" || var == "MCLONE" || var == "MIN" || var == "MOUT" ||
      var == "MMIN" || var == "MMOUT" || var == "TITLE" || var == "prompt")
    val = val + "%^RESET%^";
  if (stringp(val)) val = replace_string(val,ESC, "Esc") ;
    i = act_ob->set_env(var,val);
    if (var=="prompt") this_player()->do_new() ;
    printf("Variable %s: %s\n", (i ? "updated" : "added"), var);
    return 1;
}

protected int sort_set(string one, string two)
{
    return strcmp(two, one);
}


void help()
{
    write( @HELP
Usage: set [variable [value]]

Used by itself, set lists all environment variables which have been set.

With just a variable name as an argument, set will set the value of that
environment variable to \"\".

If given a second argument, a value, a variable is created with that name and
that value if it doesn't exist.  If it already exists, the old value is
replaced with the new one.

Some of the possible environment variables are:
prompt - set your prompt.
history - set the size of your history buffer (default 20).
LINES - set the number of lines on your screen (default 24).
TZONE - your timezone (one of EST, CST, MST, PST, BST, GMT, CET, EET, AST).
	Lets the game display all times in your time zone's units.
HELP
    );
    if (this_player()->link_data("wizard")) {
	write ("PAGER - the file used to page files at you (default more).\n"+
"START - the room which you appear in when you log in.\n"+
"home - the room where the home command takes you (default workroom.c)\n"+
"\n  There are also the movement messages: TITLE, MOUT, MIN, MMOUT, MMIN\n"+
"MDEST, MCLONE, MVIS, and MINVIS. Type \"help movement_messages\" for help\n"+
"with those.\n") ;
    }

}

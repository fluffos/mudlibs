// File  :  /cmds/xtra/_people.c
//
// Written By Jubal @ TMI
// Sulam changed the title stuff 1/2/92
// Modified for time zones by DocZ @ TMI (1/20/92)
// Modified a tad to include guild info, sulam (april 4, 1992)
// Modified sulam's tad for the new guild info, jubal (Apr12/92)
// Modified to respect invisibility by Mobydick@TMI-2, 10-10-92
// Help added by Mobydick on 11-13-92, from the people.command doc file.
// Inactive label in Idle column added by Watcher on 1-14-93.
// Watcher changed query("invisible") check to use visible(), 4-14-93.
// Grendel added sorting by domain level 07-13-93
// Names in all caps for those in announce flag. - Publius - 8-3-93
// 93-08-05 Grendel [ ] for those that are hidden, and days,years to age

#include <mudlib.h>
#include <writef.h>
#include <daemons.h>
#include <domains.h>
 
inherit DAEMON ;
inherit TIME_D;

string divide;

create()
{
        int i;
	::create();

	for (divide = "", i = 0 ; i<78 ; i++ )
		divide += "_";
	divide += "\n";
}


// use this mapping so we dont have to do DOMAIN_D->query_domain_level
// every single time the sort function is called
// sort_array cannot take the extra argument the way filter array can,
// so it has to be global
mapping levels;

int cmd_people(string arg) {
    object *list;
    string line, zone_name;
    string *announce;
    int i,time_zone;
    mapping domains ;
    object link ;
    string lines;

    // so that admins can see hidden admins...
    seteuid(getuid(previous_object()));

    lines=divide;
 
    levels=([ ]);
  if( adminp(geteuid(this_player())) )
  {
	list = users();
  map_array(list, "kludgyFix", this_object() );
  }
	else
  {
    list = filter_array(users(), "filter_users", this_object());
  }
    list = sort_array(list, "sort_users", this_object());
 
    if(!sizeof(list)) {
	lines+="\tWow, no one is logged on. How'd you manage that? ;)\n"+divide;
	write(lines);
    return 1; }
 
    if (sizeof(list) > 1)
	lines+="\t\t   There are "+ sizeof(list) +" users connected.\n";
    else
// Buddha thought of this message :-)
	lines+="\t\tHow lonely!  You're the only one here.\n";

// Time zone code, by Docz
    zone_name = (string)this_player()->getenv("TZONE");
    time_zone = query_tzone(zone_name);
    if (!time_zone)
        lines += "\t\tMud time is " + ctime( time() ) + "\n" ;
    else
	lines += "\t\t"+zone_name+" time is " + ctime ( time_zone ) + "\n" ;

/* In Moby's opinion the extra divides are very ugly. He feels strongly.
    lines+=divide;
*/
    lines+=sprintf("%s%-13s%-12s%-10s%-5s%-5s %-20s\n%s",divide,
        "Name", "Position", "Domain", "Zz", "Age", "Location",divide);
/*
    lines+=divide;
*/

    announce=this_player()->query("announce");
    for (i=0; i<sizeof(list); i++)
    {   string field;
	mixed val;

	field = (string) list[i] -> link_data("name");
	if (!field)
	    field = "(null)";
// Put in all caps for those in announce - Publius
        else if(announce && member_array(field,announce)>-1)
            field=all_caps(field);
	else
	    field = capitalize(field);
	if(hiddenp(list[i])) field = "[" + field + "]";
	else if(list[i]->query("invisible"))  field = "(" + field + ")";
 
        if ((int)list[i]->query("npc")) field += " [M]";
 
	if (!list[i]->query("inactive") && 
	    (in_edit(list[i]) || in_input(list[i])))
		field = "*" + field;
        line = sprintf("%-13s", field);
	link = (object) list[i]->query_link() ;
	field = DOMAIN_D->query_domain_level(link) ;
	if (!field) field = "-";
        line += sprintf("%-12s", field);
	field = DOMAIN_D->query_domain(link) ;
	if (!field) field = "-";
        line += sprintf("%-10s", field);
	val = query_idle(list[i]);
        if (list[i]->query("inactive"))  field = "IN";

	else if ( val <= 0 ) field = "";
	else if( val >= 86400 ) field = val/86400 + "d";
	else if( val >= 3600 ) field = val/3600 + "h";
	else if( val >= 60 ) field = val/60 + "m";
	else field = "";
        line += sprintf("%-5s", field);
        val = list[i]->query("age");
        if (val<86400) field = (val/3600)+"h";
	else if( val >= 31536000 ) field = val/31536000 + "y";
        else
        field = (val/86400)+ "d";
        line += sprintf("%-5s ", field);
	val = environment(list[i]);
	if (!val) field = "(null)";
	else field = file_name(val);
        if(field[0..2]=="/u/") field = "~"+ (field [5..<1]);
        line += sprintf("%-22s", field);
	lines += line + "\n" ;
    }
    lines+=divide;
    write(lines);
    return 1;
}

int
sort_users(object u1, object u2)
{
    return (levels[u1]<levels[u2]) ? 1 : (levels[u1]>levels[u2]) ? -1 : 0;
}

//  Can one wizard see the other wizard? 
 
int filter_users(object obj) {
    object ob;
    if(visible(obj,this_player())) {
	ob=(object)obj->query_link();
	levels[obj]=member_array((string)DOMAIN_D->query_domain_level(ob),
				    LEVEL_LIST);
	return 1;
    }
    return 0;
}

void kludgyFix(object obj ){
  object ob;
  ob = (object)obj->query_link();
  levels[obj]=member_array((string)DOMAIN_D->query_domain_level(ob),
			LEVEL_LIST);
}
 
int help() {
	write ( "Usage: people\n\n"+@HELP
The people command lists the following facts about logged on users:
guild membership and position, idle time, and current location.  People
marked with an asterisk (*) are using the editor.  It also prints the
time of day and the number of people logged on. If a wizard sets his
invisibility to \"wizard\", then he will not appear on the output of
the people command unless the command is invoked by an administrator.
If someone is invisible they are displayed in parentheses, "()", if
hidden they show up in square braces, "[]". Also, the names of those
listed in your announce flag are shown in all caps.

See also: who, finger.
HELP
	    ) ;
	return 1;
}
/* EOF */

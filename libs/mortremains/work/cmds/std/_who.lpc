// File  :  /cmds/std/_who.c
//          originally _people.c, but has been modified a fuckload.
//          by Zur.
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
// 4-30-97 Zur totally fucked the people command up and made it _who.c
//         I mainly changed it to look presentable, and I didn't want
//         to write all that damn object filtering shit over again.
// 10-18-98 Cyanide added support for awareness and nondetection.
//         See_invis is covered by "visible()".
// 05-22-99 Cyanide updated the rank switch a bit.
// 05-05-00 Cyanide fixed the filter_players a bit.

#include <mudlib.h>
#include <writef.h>
#include <daemons.h>
#include <domains.h>

inherit DAEMON ;
inherit TIME_D;

string divide;

create() {
    int i;
    ::create();
    i = 39;
    divide = "";
    while(i--)
	divide += "-=";
    divide += "\n";
}

// use this mapping so we dont have to do DOMAIN_D->query_domain_level
// every single time the sort function is called
// sort_array cannot take the extra argument the way filter array can,
// so it has to be global
mapping levels;

int cmd_who(string arg) {
    object *list;
    string line, zone_name;
    int i,time_zone, lvl, flag;
    mapping domains ;
    object link ;
    string lines, rank;

    // so that admins can see hidden admins...
    seteuid(getuid(previous_object()));

    lines=divide;

    levels=([ ]);
    list = filter_array(users(), "filter_users", this_object());
    list = sort_array(list, "sort_users", this_object());

    if(!sizeof(list)) {
	lines+="\tWow, no one is logged on. How'd you manage that? ;)\n"+divide;
	write(lines);
	return 1; 
    }
    lines += sprintf("%|78s", "Who's currently on "+MUD_NAME) + "\n";

    lines+=divide;

    for (i=0; i<sizeof(list); i++)
    {   
	string field, Istring;
	mixed val;

	field = (string) list[i] -> link_data("name");
	if (!field)
	    field = "[Someone is logging on.]" ;
	else      
	    field = list[i]->query_title();

	if(hiddenp(list[i])) field = "[" + field + "]";
	if (list[i]->query("invisible")) field = "(" + field + ")";

	if ((int)list[i]->query("npc")) field += " [M]";

	if (!list[i]->query("inactive") &&
	  (in_edit(list[i]) || in_input(list[i])))
	    field = "*" + field;
	line = sprintf("%-13s", field);

	val = query_idle(list[i]);
	field = "";
	Istring = "";
	if (list[i]->query("inactive"))  Istring = "<inactive>";
	if(val >= 60) Istring = "<idle>";
	//line += sprintf("%-18s", field);
	link = (object) list[i]->query_link() ;
	if(wizardp(list[i]))
	{
	    switch(DOMAIN_D->query_domain_level(link))
	    {
	    case "Administrator" :  rank = "ADMIN";break;
	    case "Elder":           rank = "ELDER"; break;
	    case "Domain Lord":     rank = "LORD"; break;
	    case "Speaker":         rank = "SPEAKER"; break;
	    case "Builder":         rank = "BUILDER"; break;
	    case "Neophyte":
	    case "Domainless":      rank = "NEO"; break;
	    default:              
		rank = DOMAIN_D->query_domain_level(link);
		break;
	    }
	}
	line = sprintf("%:-56s %:9s%:-10s", line, 
	  (wizardp(list[i])) ? "["+rank+"]" : "", Istring);

	lines += line + "\n" ;
    }

    lines+=divide;
    lines+="Currently "+ sizeof(list) +" users connected.  ";
    zone_name = (string)this_player()->getenv("TZONE");
    time_zone = query_tzone(zone_name);
    // Time zone code, by Docz
    if (!time_zone)
	lines += "Mud time is " + ctime( time() ) + "\n" ;
    else
	lines += ""+zone_name+" time is " + ctime ( time_zone ) + "\n" ;

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
    int lvl, flag = 1;

    lvl = TP->query_level();
    lvl += 5;
    if (TP->query_level("thief")) lvl += 1;

    if(visible(obj,TP)) {
	ob=(object)obj->query_link();
	levels[obj]=member_array((string)DOMAIN_D->query_domain_level(ob),
	  LEVEL_LIST);
	flag = 1;
    } else {
	if (!wizardp(obj)) {
	    if (TP->query_skill("Awareness")) 
	    {
		if (obj->query_skill("Nondetection"))
		{
		    flag = 0;
		} else {
		    flag = (lvl > obj->query_level());
		}
	    } else {
		flag = 0;
	    }
	} else flag = 0;
    }

    return flag;
}

void kludgyFix(object obj ){
    object ob;
    ob = (object)obj->query_link();
    levels[obj]=member_array((string)DOMAIN_D->query_domain_level(ob),
      LEVEL_LIST);
}

string help(){
    return @EndHelp
This command displays people logged on which are visible to you.
Abbreviations appear in brackets for the following:
   ADMIN - An administrator. 
   ELDER - Elder - A trusted advisor to the admin.
    LORD - Domain Lord - The head of a particular domain.
 SPEAKER - Speaker - A "master" coder.
 BUILDER - Builder - A "rank and file" coder.
     NEO - Neophyte - A relatively new wizard.
EndHelp;
}






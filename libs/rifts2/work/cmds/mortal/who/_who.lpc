//	/cmds/mortal/_who.c
//	from DarkeMUD Mudlib
//	lists users in desired format
//	-Diewarzau 3/16/94

#include <std.h>
#include <who.h>
#include <daemons.h>
 
string *argv;
 
inherit DAEMON;

string list_users(string *races, string order);
object *master_sort(object *tmp, string order);

int cmd_who(string str) {
    int j;
    string *args, *races, *other;
    string tmp, order;
    string which;
    int i, len;

    races = ({});
    argv = ({});
    other = ({});
    order = DEFAULT_SORT;
    if(str) {
	i=sizeof(args = explode(str," "));
	while(i--) {
	    if(args[i][0..2] == "-o:" && strlen(args[i]) > 3)
		order = args[i][3..3];
	    else if(args[i][0] == '-' && (len=strlen(args[i])) > 1)
		{ len --;
		tmp = args[i][1..len];
		argv += ({ tmp }); }
	    else if(RACE_D->is_race(args[i])) races += ({ args[i] });
	    else other += ({ args[i] });
	}
    }
    if((j=member_array("def",argv,1)) > -1) {
	races = explode(argv[j],":");
	if(sizeof(races) > 1)
	{
	    this_player()->set_default_who(races[1]);
	    write("Default who set to: "+races[1]);
	    return 1;
	}
	this_player()->set_default_who("normal");
	write("Default who set to normal.\n");
	return 1;
    }
    if(member_array("peo",argv,1) > -1) which = "people";
    else if(member_array("line",argv) > -1) which = "line";
    else if(member_array("sho",argv,1) > -1) which = "short";
    else if(member_array("norm",argv,1) > -1) which = "normal";
    else which = (string)this_player()->query_default_who();
    switch(which) {
	case "normal":
	    this_player()->more(explode(list_users(races, order),"\n"));
	    return 1;
	case "people":
	    if(races && sizeof(races)) {
		cmd_people(order, implode(other," ")); }
	    else cmd_people(order);
	    return 1;
	case "line":
	    return cmd_users(order);
	case "short":
	    return cmd_short(order);
	default:
	    this_player()->more(explode(list_users(races, order),"\n"));
	    return 1;
    }
    return 1;
}

string list_users(string *races, string order) {
    object *who, *tmp;
    int max;
    int num, i, j, total;
    string type_str, who_list, line;

    who = filter_array(users(), "which_users", this_object(), races);
    total = sizeof(who);
    if(file_exists("/news/who_header"))
	who_list = read_file("/news/who_header");
    else
   	who_list = "ERROR: No who_header found\n\n";
    if(total == 1 && sizeof(users()) == 1)
        who_list += "You are the only current player logged in.\n";
    else
	 who_list += "Number of users: "+sizeof(users())+" ("
	    +total+" shown)\n";
    for(i=0;i<NUM_TYPES;i++) {
        type_str = capitalize(implode(explode(POS_TYPES[i],"_")," "));
        tmp = filter_array(who, "filter_"+POS_TYPES[i], this_object());
	tmp = master_sort(tmp, order);
	max = sizeof(tmp);
	if(max) {
	who_list += "\n";
	who_list += "Number of "+pluralize(type_str)+": "+max+"\n";
	for(j=0;j<max;j++) {
	line = "";
	    if((string)tmp[j]->query_title())
		line += (string)tmp[j]->query_title();
	    else if(!wizardp(tmp[j])) {
		line += capitalize((string)tmp[j]->query_name());
		line += " the " + capitalize((string)tmp[j]->query_race());
		line += " " + capitalize((string)tmp[j]->query_class());
	    } else
		line += "{"+(string)tmp[j]->query_name(1)+"}";
	    line = arrange_string(line,65);
	    line = " "+line;
	    if(in_edit(tmp[j]) || in_input(tmp[j]))
		line = "%^BOLD%^E%^RESET%^"+line;
	    else
		line = " " + line;
	    if(query_idle(tmp[j]) > 120)
		line = "%^BOLD%^I%^RESET%^"+line;
	    else
		line = " "+line;
	    if(tmp[j] == this_player())
		line = "%^BOLD%^"+line;
	    line += "\n";
	    who_list += line;
	} }
    }
    return who_list;
}

object *master_sort(object *tmp, string order) {
	switch(order) {
	   case "a":
		tmp = sort_array(tmp,"sort_by_name",this_object());
		break;
	   case "b":
		tmp = sort_array(tmp,"sort_by_birth",this_object());
		break;
	   case "d":
		tmp = sort_array(tmp,"sort_by_deaths",this_object());
		break;
	   case "k":
		tmp = sort_array(tmp,"sort_by_kills",this_object());
		break;
	   case "l":
		tmp = sort_array(tmp,"sort_by_level",this_object());
		break;
	   case "p":
		tmp = sort_array(tmp,"sort_by_playing_time",this_object());
		break;
	   case "q":
		tmp = sort_array(tmp,"sort_by_quests",this_object());
		break;
	   case "t":
		tmp = sort_array(tmp,"sort_by_login_time",this_object());
		break;
	   default:
	 	tmp = sort_array(tmp,"sort_by_birth",this_object());
	}
    return tmp;
}
	
int which_users(object who, string *races) {
    string my_race;
    int i;
 
    if(member_array("line",argv) > -1) return 1;
    if(!who->query_name()) return 0;
    if(who->query_invis() && wizardp(who) && !archp(this_player()))
      return 0;
    if(!(i=sizeof(races))) return 1;
   my_race = (string)who->query("race");
     while(i--) if(races[i]== my_race) return 1;
    return 0;
}

int sort_by_birth(object alpha, object beta) {
    int a, b;
 
    a = (int)alpha->query_birthday();
    b = (int)beta->query_birthday();
    if(a == b) return strcmp((string)alpha->query_name(),
(string)beta->query_name());
    else if(a > b) return 1;
    else return -1;
}
 
int sort_by_name(object alpha, object beta) {
    return strcmp((string)alpha->query_name(), (string)beta->query_name());
}

int sort_by_playing_time(object alpha, object beta) {
    int a, b;
 
    a = (int)alpha->query_age();
    b = (int)beta->query_age();
    if(a==b) return strcmp((string)alpha->query_name(),
(string)beta->query_name());
    else if(a > b) return -1;
    else return 1;
}
 
int sort_by_login_time(object alpha, object beta) {
    int a, b;
 
    a = (int)alpha->query_login_time();
    b = (int)beta->query_login_time();
    if(a==b) return strcmp((string)alpha->query_name(),
(string)beta->query_name());
    else if(a>b) return 1;
    else return -1;
}

int sort_by_level(object alpha, object beta) {
    int a, b;
 
    a = (int)alpha->query_level();
    b = (int)beta->query_level();
    if(a > b) return -1;
    if(b > a) return 1;
    a = wizardp(alpha);
    b = wizardp(beta);
    if( (a && b) || (!a && !b) )
      return strcmp((string)alpha->query_name(), (string)beta->query_name());
    if(a) return 1;
    return -1;
}

int sort_by_kills(object alpha, object beta) {
    int a, b;
 
    if((a=sizeof((string *)alpha->query_kills())) > (b=sizeof((string
*)beta->query_kills())))
      return -1;
    else if(a < b) return 1;
    else return strcmp((string)alpha->query_name(), (string)beta->query_name());
}
 
int sort_by_deaths(object alpha, object beta) {
    int a, b;
 
    a = sizeof((mixed *)alpha->query_deaths());
    b = sizeof((mixed *)beta->query_deaths());
    if(a>b) return -1;
    else if(a<b) return 1;
    else return strcmp((string)alpha->query_name(), (string)beta->query_name());
}

int sort_by_quests(object alpha, object beta) {
    int a, b;
 
   if((a=(int)alpha->query_quest_points()) >
 (b=(int)beta->query_quest_points()))
      return -1;
    else if(a < b) return 1;
    else return strcmp((string)alpha->query_name(), (string)beta->query_name());
}

int filter_arch(object ob) {
    return archp(ob);
}

int filter_wizard(object ob) {
    return wizardp(ob) && !archp(ob);
}

int filter_high_mortal(object ob) {
    return high_mortalp(ob);
}

int filter_ambassador(object ob) {
    return ambassadorp(ob) && !high_mortalp(ob) &&
	!wizardp(ob);
}

int filter_mortal(object ob) {
    int res;
    res = !wizardp(ob) && !high_mortalp(ob) && !ambassadorp(ob);
    return res;
}

int help() {
    write("help: mortal command\n"+
	"\nform: who [-o:<order> <race1> <race2>...]\n"+
	"\nLists all interactive users who belong to the races\n"+
	"supplied, or all users if no races are supplied.\n"+
	"Order may be a,d,k,l,p,q, or t.  These mean:\n"+
        "a - sort by name               b - sort by birth date\n"+
	"d - sort by deaths		k - sort by kills\n"+
	"l - sort by level (default)	p - sort by playing time\n"+
	"q - sort by quests		t - sort by login time\n");
    write("The -def:<default-who> specifier changes your defaul who.");
    write("With the -line specifier:");
    help_line();
    write("With the -short specifier: ");
    help_short();
    if(wizardp(this_player()) || ambassadorp(this_player()) || high_mortalp(
	this_player()))
	help_people();
    write("\nThe -normal specifier gives you the normal who if your default "
	"is different");
    return 1;
}

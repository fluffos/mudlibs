//      /bin/mortal/_who.c
//      from the Nightmare Mudlib
//      lists users() in an interesting format and sorting order
//      created by Descartes of Borg 03 july 1993
//	redesigned by Kalinash 12 Jan 94
 
#include <std.h>
#include <daemons.h>
 
#define DEFAULT_SORT "l";
 
inherit DAEMON;
 
string list_users(string *races, string order);
 
int cmd_who(string str) {
    string *args, *races;
    string order;
    int i;
 
    races = ({});
    order = DEFAULT_SORT;
    if(str) {
        i = sizeof(args = explode(str, " "));
        while(i--) {
            if(args[i][0] == '-' && strlen(args[i]) > 1) order = args[i][1..1];
            else if(RACE_D->is_race(args[i])) races += ({ args[i] });
        }
   }
     this_player()->more(explode(list_users(races, order), "\n"));
    return 1;
}
 
string list_users(string *races, string order) {
   object *who, *hms, *ims, *nbs, *nrs, *abs;
     string tmp, mark, borg;
    int i, max, x;
    hms = ({});
    ims = ({});
    nbs = ({});
    nrs = ({});
    abs = ({});
    who = filter_array(users(), "which_users", this_object(), races);
    for(x=0;x<sizeof(who);x++) {
        if(creatorp(who[x]))
	  if(!ims) ims = ({ who[x] }); else ims += ({ who[x] });
        else if(high_mortalp(who[x]))
	  if(!hms) hms = ({ who[x] }); else hms += ({ who[x] });
        else if((int)who[x]->query_level() < 6)
	  if(ambassadorp(who[x]))
	    { if(!abs) abs = ({ who[x] }); else abs += ({ who[x] }); } else
	    { if(!nbs) nbs = ({ who[x] }); else nbs += ({ who[x] }); }
	else 
	  if(!nrs) nrs = ({ who[x] }); else nrs += ({ who[x] });
    }
    switch(order) {
        case "a":
            hms = sort_array(hms, "sort_by_name", this_object());
            ims = sort_array(ims, "sort_by_name", this_object());
            nbs = sort_array(nbs, "sort_by_name", this_object());
            nrs = sort_array(nrs, "sort_by_name", this_object());
            abs = sort_array(abs, "sort_by_name", this_object());
            break;
        case "b":
            hms = sort_array(hms, "sort_by_birth", this_object());
            ims = sort_array(ims, "sort_by_birth", this_object());
            nbs = sort_array(nbs, "sort_by_birth", this_object());
            nrs = sort_array(nrs, "sort_by_birth", this_object());
            abs = sort_array(abs, "sort_by_birth", this_object());
            break;
        case "d":
            hms = sort_array(hms, "sort_by_deaths", this_object());
            ims = sort_array(ims, "sort_by_deaths", this_object());
            nbs = sort_array(nbs, "sort_by_deaths", this_object());
            nrs = sort_array(nrs, "sort_by_deaths", this_object());
            abs = sort_array(abs, "sort_by_deaths", this_object());
            break;
        case "k":
            hms = sort_array(hms, "sort_by_kills", this_object());
            ims = sort_array(ims, "sort_by_kills", this_object());
            nbs = sort_array(nbs, "sort_by_kills", this_object());
            nrs = sort_array(nrs, "sort_by_kills", this_object());
            abs = sort_array(abs, "sort_by_kills", this_object());
            break;
        case "l":
	    hms = sort_array(hms, "sort_by_level", this_object());
	    ims = sort_array(ims, "sort_by_level", this_object());
	    nbs = sort_array(nbs, "sort_by_level", this_object());
	    nrs = sort_array(nrs, "sort_by_level", this_object());
	    abs = sort_array(abs, "sort_by_level", this_object());
            break;
        case "p":
            hms = sort_array(hms, "sort_by_playing_time", this_object());
            ims = sort_array(ims, "sort_by_playing_time", this_object());
            nbs = sort_array(nbs, "sort_by_playing_time", this_object());
            nrs = sort_array(nrs, "sort_by_playing_time", this_object());
            abs = sort_array(abs, "sort_by_playing_time", this_object());
            break;
        case "q":
            hms = sort_array(hms, "sort_by_quests", this_object());
            ims = sort_array(ims, "sort_by_quests", this_object());
            nbs = sort_array(nbs, "sort_by_quests", this_object());
            nrs = sort_array(nrs, "sort_by_quests", this_object());
            abs = sort_array(abs, "sort_by_quests", this_object());
            break;
        case "t":
            hms = sort_array(hms, "sort_by_login_time", this_object());
            ims = sort_array(ims, "sort_by_login_time", this_object());
            nbs = sort_array(nbs, "sort_by_login_time", this_object());
            nrs = sort_array(nrs, "sort_by_login_time", this_object());
            abs = sort_array(abs, "sort_by_login_time", this_object());
            break;
        default:
            hms = sort_array(hms, "sort_by_birth", this_object());
            ims = sort_array(ims, "sort_by_birth", this_object());
            nbs = sort_array(nbs, "sort_by_birth", this_object());
            nrs = sort_array(nrs, "sort_by_birth", this_object());
            abs = sort_array(abs, "sort_by_birth", this_object());
            break;
    }
    max = sizeof(who);
    borg = "%^RED%^%^BOLD%^          Our Reality Which Is Nightmare\n";
    if(sizeof(races) && max == 1)
        borg += "%^RED%^There is only one such person experiencing our Nightmare!\n";
    else
        if(max == 1)
            borg += "%^RED%^   You are the only person experiencing our Nightmare!\n";
        else
            borg += "%^RED%^   There are currently "+max+" people in our Nightmare!\n";
    borg +="\n";
    max = sizeof(hms);
    if(sizeof(races) && max == 1)
        borg += "%^RED%^There is only one such High mortal experiencing our Nightmare!\n";
    else if(max > 0)
        borg += "%^RED%^There are currently "+max+" High mortals in our Nightmare :\n";
    if(max)
	borg += "\n";
    if(max)
    for(i=0; i<max; i++) {
	tmp = "  ";
	if((string)hms[i]->query_title()) tmp += (string)hms[i]->query_title(); else
          tmp += "("+capitalize((string)hms[i]->query_name())+")";
	tmp += ", ";
        tmp += capitalize((string)hms[i]->query_race());
        tmp += " ";
        tmp += capitalize((string)hms[i]->query_class());
        tmp = arrange_string(tmp, 65);
	if(in_edit(hms[i]) || in_input(hms[i]))
          tmp += "*ed*";
        else
          tmp += "    ";
        tmp = arrange_string(tmp, 71);
        if(query_idle(hms[i]) > 60)
          tmp += "-id-";
        else
          tmp += "    ";
    borg += "%^MAGENTA%^%^BOLD%^"+tmp;
    borg += "\n";
    }
    max = sizeof(nrs);
    if(max == 1)
        borg += "\n%^RED%^There is only one such mid-level player experiencing our Nightmare!\n";
    else if(max > 0)
        borg += "\n%^RED%^There are currently "+max+" mid-level players in our Nightmare :\n";
    if(max)
	borg += "\n";
    if(max)
    for(i=0; i<max; i++) {
	tmp = "  ";
	if((string)nrs[i]->query_title()) tmp += (string)nrs[i]->query_title(); else
          tmp += "("+capitalize((string)nrs[i]->query_name())+")";
	tmp += ", ";
        tmp += capitalize((string)nrs[i]->query_race());
        tmp += " ";
        tmp += capitalize((string)nrs[i]->query_class());
        tmp = arrange_string(tmp, 65);
	if(in_edit(nrs[i]) || in_input(nrs[i]))
          tmp += "*ed*";
        else
          tmp += "    ";
        tmp = arrange_string(tmp, 71);
        if(query_idle(nrs[i]) > 60)
          tmp += "-id-";
        else
          tmp += "    ";
    borg += "%^CYAN%^"+tmp;
    borg += "\n";
    }
    max = sizeof(nbs);
    if(sizeof(races) && max ==1)
        borg += "\n%^RED%^There is only one such newbie player experiencing our Nightmare!\n";
    else if(max > 0)
        borg += "\n%^RED%^There are currently "+max+" newbie players in our Nightmare :\n";
    if(max)
	borg += "\n";
    if(max)
    for(i=0; i<max; i++) {
	tmp = "  ";
	if((string)nbs[i]->query_title()) tmp += (string)nbs[i]->query_title(); else
          tmp += "("+capitalize((string)nbs[i]->query_name())+")";
	tmp += ", ";
	if(!(string)nbs[i]->query_race()) tmp += "null"; else
	  tmp += capitalize((string)nbs[i]->query_race());
	  tmp += " ";
	if(!(string)nbs[i]->query_class()) tmp += "null"; else
	  tmp += capitalize((string)nbs[i]->query_class());
          tmp = arrange_string(tmp, 65);
	if(in_edit(nbs[i]) || in_input(nbs[i]))
          tmp += "*ed*";
        else
          tmp += "    ";
        tmp = arrange_string(tmp, 71);
        if(query_idle(nbs[i]) > 60)
          tmp += "-id-";
        else
          tmp += "    ";
    borg += "%^MAGENTA%^"+tmp;
    borg += "\n";
    }
    max = sizeof(abs);
    if(sizeof(races) && max ==1)
        borg += "\n%^RED%^There is only one such ambassador experiencing our Nightmare!\n";
    else if(max > 0)
        borg += "\n%^RED%^There are currently "+max+" ambassadors in our Nightmare :\n";
    if(max)
	borg += "\n";
    if(max)
    for(i=0; i<max; i++) {
	tmp = "  ";
	if((string)abs[i]->query_title()) tmp += (string)abs[i]->query_title(); else
          tmp += "("+capitalize((string)abs[i]->query_name())+")";
	tmp += ", ";
	tmp += capitalize((string)abs[i]->query_race());
	tmp += " ";
	tmp += capitalize((string)abs[i]->query_class());
        tmp = arrange_string(tmp, 65);
	if(in_edit(abs[i]) || in_input(abs[i]))
          tmp += "*ed*";
        else
          tmp += "    ";
        tmp = arrange_string(tmp, 71);
        if(query_idle(abs[i]) > 60)
          tmp += "-id-";
        else
          tmp += "    ";
    borg += "%^GREEN%^"+tmp;
    borg += "\n";
    }
    max = sizeof(ims);
    if(sizeof(races) && max ==1)
        borg += "\n%^RED%^There is only one such Immortal experiencing our Nightmare!\n";
    else if(max > 0)
        borg += "\n%^RED%^There are currently "+max+" Immortals in our Nightmare :\n";
    if(max)
	borg += "\n";
    if(max)
    for(i=0; i<max; i++) {
	tmp = "  ";
        if((int)ims[i]->query_invis() && !archp(this_player())) continue;
	if((string)ims[i]->query_title()) tmp+=(string)ims[i]->query_title(); else
          tmp += "("+capitalize((string)ims[i]->query_name())+")";
	tmp += " - ";
	tmp += capitalize((string)ims[i]->query_position());
        tmp = arrange_string(tmp, 65);
	if(in_edit(ims[i]) || in_input(ims[i]))
          tmp += "*ed*";
        else
          tmp += "    ";
        tmp = arrange_string(tmp, 71);
        if(query_idle(ims[i]) > 60)
          tmp += "-id-";
        else
          tmp += "    ";
    if(archp(ims[i]))
        borg += "%^BLUE%^%^BOLD%^"+tmp;
    else borg += "%^BLUE%^"+tmp;
    borg += "\n";
    }
    return borg;
}
 
int which_users(object who, string *races) {
    string my_race;
    int i;
 
    if((int)who->query_invis(this_player())) return 0;
    if(!who->query_title()) return 0;
    if(who->query_invis() && creatorp(who) && !archp(this_player()))
      return 0;
    if(!(i=sizeof(races))) return 1;
   my_race = (string)who->query_race();
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
    a = creatorp(alpha);
    b = creatorp(beta);
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
 
void help() {
    write(
      "Syntax: <who [-][abdklpqt] [race1 race2 ... raceN]>\n\n"+
      "Lists all players online or all players of the race(s) given.\n"+
      "If no arguments are given, it simply lists all players sorted by\n"
      "birthdate.\n" );
}

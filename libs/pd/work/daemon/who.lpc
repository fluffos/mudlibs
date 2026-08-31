#include <std.h>
#include <daemons.h>
 
#define DEFAULT_SORT "l";
 
inherit DAEMON;
#define GR "%^RESET%^%^GREEN%^"
#define BO "%^BOLD%^%^GREEN%^"
string list_users(string *races, string order);
void do_player_html();
string do_who_html(string str);
void create()
{
 do_who_html("");
 do_player_html();
} 
void do_player_html()
{
 mapping players;
 int i;
 string out;

 call_out("do_player_html", 600);
 out = "";
 players = PLAYER_D->query_player_list();
 i = sizeof(players);
out = "<body bgcolor=\"#000000\" text=\"#ffffff\">";
out += "<pre>    Player Name        Level      Class<br>";
out +="-----------------------------------------------------<br>";
 for(int a=0; a<i; a++)
  {
   out += arrange_string(sprintf("%d) ", a+1), 4);
   out += arrange_string(capitalize(players[a]["name"]), 20);
   out += arrange_string(players[a]["level"], 10);
   out += arrange_string(capitalize(players[a]["class"]), 10);
   out += "<br>";
  }
 rm("/tmp/player.html");
 write_file("/tmp/player.html", out);
}
string do_who_html(string str) {
    string *args, *races;
    string order;
    string disp;
    int i;

    call_out("do_who_html", 20); 
    races = ({});
    order = DEFAULT_SORT;
    if(str) {
        i = sizeof(args = explode(str, " "));
        while(i--) {
            if(args[i][0] == '-' && strlen(args[i]) > 1) order = args[i][1..1];
            else if(RACE_D->is_race(args[i])) races += ({ args[i] });
        }
   }
    rm("/tmp/who.html");
 disp = list_users(races, order);
 disp = replace_string(disp, "%^BOLD%^", "%^STRONG%^");
 disp = "<body bgcolor=\"#000000\" fgcolor=\"#ffffff\">"+
        TERMINAL_D->html_it(disp);
write_file("/tmp/who.html", disp);    

}
 
string list_users(string *races, string order) {
   object *who, *hms, *ims, *arc, *nbs, *nrs, *abs;
     string tmp, titl, mark, borg;
    int i, max, x;
    hms = ({});
     ims = ({});
    arc = ({});
    nbs = ({});
    nrs = ({});
    abs = ({});
    who = filter_array(users(), "which_users", this_object(), races);
    for(x=0;x<sizeof(who);x++) {
        if (archp(who[x]))
          if (!arc) arc = ({ who[x] }); else arc += ({ who[x] });
        else if(wizardp(who[x]))
	  if(!ims) ims = ({ who[x] }); else ims += ({ who[x] });
        else if(high_mortalp(who[x]))
	  if(!hms) hms = ({ who[x] }); else hms += ({ who[x] });
        else if((int)who[x]->query_level() < 6)
	  if(ambassadorp(who[x]))
	    { if(!abs) abs = ({who[x]}); else abs += ({ who[x] }); } else
	    { if(!nbs) nbs = ({who[x]}); else nbs += ({ who[x] }); }
	else 
	  if(!nrs) nrs = ({who[x]}); else nrs += ({ who[x] });
    }
    switch(order) {
        case "a":
            arc = sort_array(arc, "sort_by_name", this_object());
            hms = sort_array(hms, "sort_by_name", this_object());
            ims = sort_array(ims, "sort_by_name", this_object());
            nbs = sort_array(nbs, "sort_by_name", this_object());
            nrs = sort_array(nrs, "sort_by_name", this_object());
            abs = sort_array(abs, "sort_by_name", this_object());
            break;
        case "b":
            arc = sort_array(arc, "sort_by_birth", this_object());
            hms = sort_array(hms, "sort_by_birth", this_object());
            ims = sort_array(ims, "sort_by_birth", this_object());
            nbs = sort_array(nbs, "sort_by_birth", this_object());
            nrs = sort_array(nrs, "sort_by_birth", this_object());
            abs = sort_array(abs, "sort_by_birth", this_object());
            break;
        case "d":
            arc = sort_array(arc, "sort_by_deaths", this_object());
            hms = sort_array(hms, "sort_by_deaths", this_object());
            ims = sort_array(ims, "sort_by_deaths", this_object());
            nbs = sort_array(nbs, "sort_by_deaths", this_object());
            nrs = sort_array(nrs, "sort_by_deaths", this_object());
            abs = sort_array(abs, "sort_by_deaths", this_object());
            break;
        case "k":
            arc = sort_array(arc, "sort_by_kills", this_object());
            hms = sort_array(hms, "sort_by_kills", this_object());
            ims = sort_array(ims, "sort_by_kills", this_object());
            nbs = sort_array(nbs, "sort_by_kills", this_object());
            nrs = sort_array(nrs, "sort_by_kills", this_object());
            abs = sort_array(abs, "sort_by_kills", this_object());
            break;
        case "l":
            arc = sort_array(arc, "sort_by_level", this_object());
	    hms = sort_array(hms, "sort_by_level", this_object());
	    ims = sort_array(ims, "sort_by_level", this_object());
	    nbs = sort_array(nbs, "sort_by_level", this_object());
	    nrs = sort_array(nrs, "sort_by_level", this_object());
	    abs = sort_array(abs, "sort_by_level", this_object());
            break;
        case "p":
            arc = sort_array(arc, "sort_by_playing_time", this_object());
            hms = sort_array(hms, "sort_by_playing_time", this_object());
            ims = sort_array(ims, "sort_by_playing_time", this_object());
            nbs = sort_array(nbs, "sort_by_playing_time", this_object());
            nrs = sort_array(nrs, "sort_by_playing_time", this_object());
            abs = sort_array(abs, "sort_by_playing_time", this_object());
            break;
        case "q":
            arc = sort_array(arc, "sort_by_quests", this_object());
            hms = sort_array(hms, "sort_by_quests", this_object());
            ims = sort_array(ims, "sort_by_quests", this_object());
            nbs = sort_array(nbs, "sort_by_quests", this_object());
            nrs = sort_array(nrs, "sort_by_quests", this_object());
            abs = sort_array(abs, "sort_by_quests", this_object());
            break;
        case "t":
            arc = sort_array(arc, "sort_by_login_time", this_object());
            hms = sort_array(hms, "sort_by_login_time", this_object());
            ims = sort_array(ims, "sort_by_login_time", this_object());
            nbs = sort_array(nbs, "sort_by_login_time", this_object());
            nrs = sort_array(nrs, "sort_by_login_time", this_object());
            abs = sort_array(abs, "sort_by_login_time", this_object());
            break;
        default:
            arc = sort_array(arc, "sort_by_birth", this_object());
            hms = sort_array(hms, "sort_by_birth", this_object());
            ims = sort_array(ims, "sort_by_birth", this_object());
            nbs = sort_array(nbs, "sort_by_birth", this_object());
            nrs = sort_array(nrs, "sort_by_birth", this_object());
            abs = sort_array(abs, "sort_by_birth", this_object());
            break;
    }

    borg = "%^WHITE%^%^BOLD%^<pre>                    The realm of Primal Darkness%^BR%^";
borg+="%^BLUE%^------------------------------------------------------------------------------- %^BR%^%^RESET%^";
    max = sizeof(arc);
  if(max)
   for(i=0; i<max; i++) {
   tmp = "[Adm] ";
  if((string)arc[i]->query_title())
   tmp+= (string)arc[i]->query_title();
    else  tmp += "("+capitalize((string)arc[i]->query_name())+")";

        tmp = arrange_string(tmp, 52);
        borg += "%^BLUE%^%^BOLD%^"+tmp;
        tmp = capitalize((string)arc[i]->query_position());
        tmp = arrange_string(tmp, 13);
        tmp += "%^BR%^";
        borg += "%^RESET%^%^WHITE%^"+tmp;


}
    max = sizeof(ims);
    if(max)
    for(i=0; i<max; i++) {
  if (ims[i]->query_name() == "detach") tmp = "[Doc] ";
  else tmp = "[Imm] ";
  if((string)ims[i]->query_title()) 
   tmp+= (string)ims[i]->query_title();
    else  tmp += "("+capitalize((string)ims[i]->query_name())+")";

        tmp = arrange_string(tmp, 52);
        borg += "%^BLUE%^%^BOLD%^"+tmp;
        tmp = capitalize((string)ims[i]->query_position());
        tmp = arrange_string(tmp, 13);
        tmp += "%^BR%^";
        borg += "%^RESET%^%^WHITE%^"+tmp;
        
       }


    max = sizeof(hms);

    if(max)
    for(i=0; i<max; i++) {

   tmp = GR+"["+BO+hms[i]->query_level()+GR+"]%^GREEN%^";
   if (hms[i]->query_level() > 49)
      tmp = GR+"["+BO+hms[i]->query_level()+GR+"]%^ORANGE%^";
        tmp = arrange_string(tmp, 6);
        borg += tmp;
        if((string)hms[i]->query_title())
          {
          tmp = (string)hms[i]->query_title();
          tmp = arrange_string(tmp, 45);
          }else
          {
          tmp = "("+capitalize((string)hms[i]->query_name())+")";
          tmp = arrange_string(tmp,45); // 56
          }
          borg += tmp;
          tmp=" ";
          tmp += capitalize((string)hms[i]->query_race());
          tmp += " ";
          tmp += capitalize((string)hms[i]->query_class());
          tmp = arrange_string(tmp, 25);
          borg += tmp+"%^RESET%^%^BR%^";


    }
    max = sizeof(nrs);
    if(max)
    for(i=0; i<max; i++) {
   tmp = GR+"["BO+nrs[i]->query_level()+GR+"]%^CYAN%^";
        tmp = arrange_string(tmp, 6);
        borg += tmp;
        if((string)nrs[i]->query_title())
          {
          tmp = (string)nrs[i]->query_title();
          tmp = arrange_string(tmp, 45);
          }else
          {
          tmp = "("+capitalize((string)nrs[i]->query_name())+")";
          tmp = arrange_string(tmp,45);
          }
          borg += tmp;
          tmp=" ";
          tmp += capitalize((string)nrs[i]->query_race());
          tmp += " ";
          tmp += capitalize((string)nrs[i]->query_class());
          tmp = arrange_string(tmp, 25);
    borg += tmp+"%^BR%^";

    }
    max = sizeof(nbs);

    if(max)
    for(i=0; i<max; i++) {

        tmp = GR+"["+BO+nbs[i]->query_level()+GR"]%^MAGENTA%^";
        tmp = arrange_string(tmp, 6); 
        borg += tmp;
	if((string)nbs[i]->query_title()) 
          {
          tmp = (string)nbs[i]->query_title();
          tmp = arrange_string(tmp, 45);
          }else
          {
          tmp = "("+capitalize((string)nbs[i]->query_name())+")";
          tmp = arrange_string(tmp,45);
          }
	   borg += tmp;
           tmp=" ";
	if(!(string)nbs[i]->query_race()) tmp += "Unborn"; else
	  tmp += capitalize((string)nbs[i]->query_race());
	  tmp += " ";
	if(!(string)nbs[i]->query_class()) tmp += "Child"; else
	  tmp += capitalize((string)nbs[i]->query_class());
          tmp = arrange_string(tmp, 25);
    borg += tmp+"%^BR%^";

    }
    max = sizeof(abs);

    if(max)
    for(i=0; i<max; i++) {
	tmp = "["+abs[i]->query_level()+"]  ";
	if((string)abs[i]->query_title()) tmp += (string)abs[i]->query_title(); else
          tmp += "("+capitalize((string)abs[i]->query_name())+")";
	tmp += ", ";
	tmp += capitalize((string)abs[i]->query_race());
	tmp += " ";
	tmp += capitalize((string)abs[i]->query_class());
        tmp = arrange_string(tmp, 65);
    borg += "%^GREEN%^"+tmp+"%^BR%^";

    }
   if (find_living("sigma") && environment(find_living("sigma")))
     {
    borg +=GR+"["+BO+"1"+GR+"]%^MAGENTA%^   Mascot Sigma the friendly bird                Dodo Bird";
   }
    return borg;
}
 
int which_users(object who, string *races) {
    string my_race;
    int i;
 
    if(!who->query_name()) return 0;
    if(who->query_invis() && wizardp(who))
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
 


/*    /cmds/ambassador/_people.c
 *    from Nightmare IV
 *    a listing of users for creators and ambassadors
 *    created by Descartes of Borg 940724
 */

#include <std.h>
#include <config.h>
#include <dirs.h>
#include <daemons.h>

inherit DAEMON;

nosave private int *__SortFlags;

private string query_time();

int cmd_people(string str) {
    object *who, *display;
    string *args;
    string msg, tmp;
    int i, maxi, aflag, bflag, cflag, eflag, gflag, hflag, lflag, mflag;
    int nflag, pflag, rflag, sflag, uflag;

    if(!str || str == "" || strlen(str) == 1 || str[0] != '-') args = ({});
    else args = explode(str[1..strlen(str)-1], "");
    i = sizeof(args);
    while(i--) {
        switch(args[i]) {
            case "a": aflag = 1; break; /* list arches */
            case "b": bflag = 1; break; /* list ambassadors */
            case "c": cflag = 1; break; /* list creators */
            case "e": eflag = 1; break; /* sort by race */
            case "g": gflag = 1; break; /* sort by age */
            case "h": hflag = 1; break; /* list high mortals */
            case "l": lflag = 1; break; /* sort by level */
            case "m": mflag = 1; break; /* page through more */
            case "n": nflag = 1; break; /* list newbies */
            case "p": pflag = 1; break; /* list regular mortals */
            case "r": rflag = 1; break; /* sort by realm location */
            case "s": sflag = 1; break; /* sort by class */
            case "u": uflag = 1; break; /* list undead */
        }
    }
    who = filter_array(users(), "filter_invis", this_object());
    if(!aflag && !bflag && !cflag && !hflag && !nflag && !pflag && !uflag)
      display = who;
    else {
        display = ({});
        if(aflag) display += filter_array(who, "filter_arches", this_object());
        if(bflag) display += filter_array(who, "filter_ambass", this_object());
        if(cflag) display += filter_array(who, "filter_cres", this_object());
        if(hflag) display += filter_array(who, "filter_hms", this_object());
        if(nflag) display += filter_array(who, "filter_newbie", this_object());
        if(pflag) display += filter_array(who, "filter_mortal", this_object());
        if(uflag) display += filter_array(who, "filter_undead", this_object());
        display = distinct_array(display);
    }
    if(!eflag && !gflag && !lflag && !rflag && !sflag)
      maxi = sizeof(display=sort_array(display,"general_sort",this_object()));
    else {
        __SortFlags = ({ eflag, gflag, lflag, rflag, sflag });
        maxi = sizeof(display = sort_array(display,"special_sort",this_object()));
    }
    msg = implode(map_array(display, "map_info", this_object()), "\n");
    msg = "------------------------------------------------------------------"
      "--------\n"+center(maxi+" people in current sort", 25)+
      center(query_time(), 50)+"\n--------"
      "------------------------------------------------------------------\n" +
      msg+"\n------------------------------------------------------------------"
      "--------\n"+center(mud_name(), 75);
    if(mflag) this_player()->more(explode(msg, "\n"), "system");
    else message("system", msg, this_player());
    return 1;
}

protected int filter_invis(object ob) {
    if(!((int)ob->query_name())) return 0;
    if(!((int)ob->query_invis(this_player()))) return 1;
    if(archp(this_player())) return 1;
    if(archp(ob)) return 0;
    return 1;
}

protected int filter_arches(object ob) { return archp(ob); }

protected int filter_ambass(object ob) { return ambassadorp(ob); }

protected int filter_cres(object ob) { return (creatorp(ob) && !archp(ob)); }

protected int filter_hms(object ob) { return high_mortalp(ob); }

protected int filter_newbie(object ob) {
    return (!creatorp(ob) && !ambassadorp(ob) && (MAX_NEWBIE_LEVEL >=
      (int)ob->query_level()));
}

protected int filter_mortal(object ob) {
    if(creatorp(ob) || high_mortalp(ob) || ambassadorp(ob)) return 0;
    if((int)ob->query_level() <= MAX_NEWBIE_LEVEL) return 0;
    return 1;
}

protected int filter_undead(object ob) { return (int)ob->query_ghost(); }

protected int general_sort(object alpha, object beta) {
    int x, y;

    if(archp(alpha)) {
        if(!archp(beta)) return -1;
        else return strcmp((string)alpha->query_CapName(),
          (string)beta->query_CapName());
    }
    else if(archp(beta)) return 1;
    if(creatorp(alpha)) {
        if(!creatorp(beta)) return -1;
        else return strcmp((string)alpha->query_CapName(),
          (string)beta->query_CapName());
    }
    else if(creatorp(beta)) return 1;
    if(ambassadorp(alpha)) {
        if(!ambassadorp(beta)) return -1;
        else return strcmp((string)alpha->query_CapName(),
          (string)beta->query_CapName());
    }
    else if(ambassadorp(beta)) return 1;
    if((x = (int)alpha->query_level()) > (y = (int)beta->query_level()))
      return -1;
    else if(x < y) return 1;
    else return strcmp((string)alpha->query_CapName(),
      (string)beta->query_CapName());
}

protected int special_sort(object alpha, object beta) {
    string a, b;
    int x, y;

    if(__SortFlags[4]) {
        if((a=(string)alpha->query_class())!=(b=(string)beta->query_class())) {
            if(!a) a = "zzzz";
            if(!b) b= "zzzz";
            return strcmp(a, b);
        }
    }
    if(__SortFlags[0]) {
        if((a=(string)alpha->query_race()) != (b=(string)beta->query_race())) {
            if(!a) a = "zzzz";
            if(!b) b = "zzzz";
            return strcmp(a, b);
        }
    }
    if(__SortFlags[3]) {
        if((a = file_name(environment(alpha))) !=
          (b = file_name(environment(beta)))) return strcmp(a, b);
    }
    if(__SortFlags[2]) {
        if((x = (int)alpha->query_level()) != (y=(int)beta->query_level())) {
            if(x > y) return -1;
            else return 1;
        }
    }
    if(__SortFlags[1]) {
        if((x = (int)alpha->query_age()) != (y = (int)beta->query_age())) {
            if(x > y) return -1;
            else return 1;
        }
    }
    return 0;
}

protected string map_info(object ob) {
    string age, nom, blk, lev, ip, env, idle;
    int x;

    x = (int)ob->query_age();
    if(x > 86400) age = sprintf("%:-2d D", x/86400);
    else if(x > 3600) age = sprintf("%:-2d h", x/3600);
    else age = sprintf("%:-2d m", x/60);
    nom = (string)ob->query_CapName();
    if((int)ob->query_invis()) nom = "("+nom+")";
    if(in_edit(ob) || in_input(ob)) nom = "["+nom+"]";
    if(creatorp(ob)) {
        if((int)ob->query_blocked("all")) blk = "ACG";
        else {
            if((int)ob->query_blocked("cre")) blk = " C";
            else blk = "  ";
            if((int)ob->query_blocked("gossip")) blk += "G";
            else blk += " ";
        }
    }
    else blk = "   ";
    if(!(x = (int)ob->query_level())) lev = "-";
    else lev = x+"";
    if((x = query_idle(ob)) < 60) idle = "";
    else if(x >= 2600) idle = sprintf("%:-3d h", x/3600);
    else idle = sprintf("%:-2d m", x/60);
    ip = query_ip_name(ob);
    if(!environment(ob)) env = "no environment";
    else env = file_name(environment(ob));
    if(!strsrch(env, REALMS_DIRS))
      env = "~"+env[strlen(REALMS_DIRS)+1..strlen(env)-1];
    else if(!strsrch(env, DOMAINS_DIRS))
      env = "^"+env[strlen(DOMAINS_DIRS)+1..strlen(env)-1];
    return sprintf("%:-5s %:-2s %:-17s %:-15s %:-5s %:-3s %:-22s",
      age, lev, nom, ip, idle, blk, env);
}

protected string query_time() {
    string tmp, ret;
    int tzone;

    tzone=(int)TIME_D->query_tzone(tmp=(string)this_player()->getenv("TZONE"));
    if(!tmp) ret = mud_name()+" local time is: ";
    else ret = tmp+" time is: ";
    return ret + ctime(tzone);
}

void help() {
    message("help", "Syntax: people [-abceghlmnprsu]\n\n"
      "Gives you a listing of people on "+mud_name()+".  Output is "
      "formatted into columns with the following meanings:\n"
      "    amount of time spent total on "+mud_name()+"\n"
      "    level\n"
      "    name\n"
      "    address from which the person is connecting\n"
      "    amount of time idle\n"
      "    blocking information, if any... A is all, C cre, G gossip\n"
      "    current environment file name\n\n"
      "Command flags have the following meanings:\n"
      "    -a list all arches\n"
      "    -b list all ambassadors\n"
      "    -c list all non-arch creators\n"
      "    -e sort the listing by race\n"
      "    -g sort the listing by age\n"
      "    -h list all high mortals\n"
      "    -l sort the listing by level\n"
      "    -m pipe the listing through the more pager\n"
      "    -n list all newbies\n"
      "    -p list all non-newbie and non-high mortal mortals\n"
      "    -r sort the listing by current environment\n"
      "    -s sort the listing by class\n"
      "    -u list all undead people\n\n"
      "People in the editor or in mail or posting will be marked with [].  "
      "People who are invisible to others, but not to you will be marked "
      "with ().  The default sort is by arch, then by creator, then by "
      "ambassador, then by level.  You can perform multiple sorts, but "
      "you cannot change the priority.  Sorts priority is: class, race, "
      "realm, level, age.  You can also include multiple groups in your "
      "listing.\n\nSee also: who, users", this_player());
}

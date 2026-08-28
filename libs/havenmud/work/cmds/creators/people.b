/*    /cmd *    from Foundation II
 *    a listing of users for creators and ambassadors
 *    created by Descartes of Borg 940724
 */

#include <lib.h>
#include <localtime.h>
#include <config.h>
#include <dirs.h>
#include <daemons.h>

inherit LIB_DAEMON;

static private int *__SortFlags;

static private string query_time();
private string calculateFormatString(int screenSize);

int cmd(string str) {
    object *who, *display;
    string *args;
    string msg, tmp1, tmp2;
    int i, maxi, aflag, bflag, cflag, eflag, gflag, hflag, lflag, mflag;
    int nflag, pflag, rflag, sflag, uflag;
    int screenSize;
    string formatString;
    string bar;

    if (angelp(this_player())) {
         this_player()->eventPrint("You don't count as people yet.");
         return 1;
         }
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
            case "m": mflag = 1; break; /* page through eventPage */
            case "n": nflag = 1; break; /* list newbies */
            case "p": pflag = 1; break; /* list regular mortals */
            case "r": rflag = 1; break; /* sort by realm location */
            case "s": sflag = 1; break; /* sort by class */
            case "u": uflag = 1; break; /* list undead */
        }
    }
    who = filter(users(), "filter_invis", this_object());
    if(!aflag && !bflag && !cflag && !hflag && !nflag && !pflag && !uflag)
      display = who;
    else {
        display = ({});
        if(aflag) display += filter(who, "filter_arches", this_object());
        if(bflag) display += filter(who, "filter_ambass", this_object());
        if(cflag) display += filter(who, "filter_cres", this_object());
        if(hflag) display += filter(who, "filter_hms", this_object());
        if(nflag) display += filter(who, "filter_newbie", this_object());
        if(pflag) display += filter(who, "filter_mortal", this_object());
        if(uflag) display += filter(who, "filter_undead", this_object());
        display = distinct_array(display);
    }
    if(!eflag && !gflag && !lflag && !rflag && !sflag) 
      maxi = sizeof(display=sort_array(display,"general_sort",this_object()));
    else {
        __SortFlags = ({ eflag, gflag, lflag, rflag, sflag });
        maxi = sizeof(display = sort_array(display,"special_sort",this_object()));
    }
    screenSize = ((int*)this_player()->GetScreen())[0];
    formatString = calculateFormatString(screenSize);
    // 74 '-'s.
    bar = "--------------------------------------------------------------------------";
    for(i = 75; i < screenSize; i++) bar += "-";
    bar += "\n";
    msg = bar;
    tmp1 = " " + maxi + ((maxi != 1) ? " people" : " person") + " in current sort ";
    tmp2 = query_time() + " ";
    i = sizeof(tmp1) + sizeof(tmp2);
    msg += tmp1;
    for(i = sizeof(tmp1) + sizeof(tmp2) + 1; i < screenSize; i++) msg += " ";
    msg += tmp2 + "\n";
    msg += bar;
    msg += implode(map_array(display, "map_info", this_object(), formatString), "\n") + "\n";
    msg += bar;
    msg += center("Haven", screenSize -1);
    if(mflag) this_player()->eventPage(explode(msg, "\n"), "system");
    else message("system", msg, this_player());
    return 1;
}

static int filter_invis(object ob)
{
  if (!((int)ob->GetKeyName())) return 0;
  if (rank(this_player()) < ob->GetInvis()) return 0;
  return 1;
}

static int filter_arches(object ob) { return archp(ob); }

static int filter_ambass(object ob) { return demigodp(ob); }

static int filter_cres(object ob) { return (creatorp(ob) && !archp(ob)); }

static int filter_hms(object ob) { return high_mortalp(ob); }

static int filter_newbie(object ob) {
    return (!creatorp(ob) && !demigodp(ob) && (MAX_NEWBIE_LEVEL >=
      (int)ob->GetLevel()));
}

static int filter_mortal(object ob) {
    if(creatorp(ob) || high_mortalp(ob) || demigodp(ob)) return 0;
    if((int)ob->GetLevel() <= MAX_NEWBIE_LEVEL) return 0;
    return 1;
}

static int filter_undead(object ob) { return (int)ob->query_ghost(); }

static int general_sort(object alpha, object beta) {
  int x = rank(beta) - rank(alpha);
  if (x) return x;
  if (playerp(alpha))
  {
    x = beta->GetLevel() - alpha->GetLevel();
    if (x) return x;
  }
  return strcmp(alpha->GetCapName(), beta->GetCapName());
}

static int special_sort(object alpha, object beta) {
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
        if((x = (int)alpha->GetLevel()) != (y=(int)beta->GetLevel())) {
            if(x > y) return -1;
            else return 1;
        }
    }
    if(__SortFlags[1]) {
        if((x = (int)alpha->GetAge()) != (y = (int)beta->GetAge())) {
            if(x > y) return -1;
            else return 1;
        }
    }
    return 0;
}

private string calculateFormatString(int screenSize) {
  int nomSize = (((screenSize - 21) * 12) / 54);
  int ipSize = (((screenSize - 21) * 18) / 54);
  int envSize = (((screenSize - 21) * 24) / 54);

  if(nomSize < 12) nomSize = 12;
  if(ipSize < 18) ipSize = 18;
  if(envSize < 24) envSize = 24;
  
  return "%:-6s %:-3s %:-" + (nomSize-1) + "s %:-" + ipSize
    + "s %:-6s %:-3s %:-" + envSize + "s";
}

static string map_info(object ob, string formatString) {
    string age, nom, blk, lev, ip, env, idle;
    int* x;
    int tmp;

    x = time_units( (int)ob->GetAge(), 1);
    if(x[1]) age = sprintf("%:-4d D", x[1]);
    else if(x[2]) age = sprintf("%:-4d h", x[2]);
    else age = sprintf("%:-4d m", x[3]);
    nom = (string)ob->GetCapName();
    if((int)ob->GetInvis()) nom = "("+nom+")";
    if(in_edit(ob) || in_input(ob)) nom = "["+nom+"]";
    if((int)ob->GetBlocked("all")) blk = "ALL";
    if((int)ob->GetBlocked("imm")) blk = " I";
      else blk = "  ";
    if((int)ob->GetBlocked("ooc")) blk += "O";
       else blk += " ";
    if (!blk) blk = "   ";    
   if(!(tmp = (int)ob->GetLevel())) lev = "-";
     else lev = tmp + "";
   if (angelp(ob))    lev = "ANG";
   if (immortalp(ob)) lev = "IMM";
   if (spiritp(ob))   lev = "MUS";
   if (sagep(ob))     lev = "GMS";
   if (assistp(ob))   lev = "ARC";
   if (securep(ob))   lev = "LES";
   if (adminp(ob))    lev = "GRE";
   if (duukp(ob))     lev = "~D~";
   if (ob->GetTestChar()) lev = "TC ";
   if (ob->GetProperty("assumed")) lev = "RP ";
  if ((tmp = query_idle(ob)) < 60) idle = "";
  else
  {
    x = time_units(tmp);
    if (x[0]) idle = sprintf("%2dw%:2dd", x[0], x[1]);
    else if (x[1]) idle = sprintf("%2dd%:2dh", x[1], x[2]);
    else if (x[2]) idle = sprintf("%2dh%:2dm", x[2], x[3]);
    else if (x[3]) idle = sprintf("%2dm%:2ds", x[3], x[4]);
  }

  ip = query_ip_name(ob);
  if (rank(ob) > rank(this_player())) ip = "<private>";
  if (!environment(ob)) env = "no environment";
  else env = file_name(environment(ob));
  if (environment(ob)) {
  	if (vehiclep(environment(ob))) 
  	  env = base_name(environment(environment(ob)));
  	  }
  if (!strsrch(env, REALMS_DIRS)) 
    env = "~" + env[strlen(REALMS_DIRS)+1..];
  else if (!strsrch(env, DOMAINS_DIRS))
    env = "^"+env[strlen(DOMAINS_DIRS)+1..strlen(env)-1];
  env = short_file(env);
  return sprintf(formatString, age, lev, nom, ip, idle, blk, env);
}

static private string query_time() {
    string tzone;
    int x;

    tzone = (string)this_player()->GetTimeZone() || localtime(time())[LT_ZONE];
    x = (int)TIME_D->GetOffset(tzone) * 3600;
   return tzone + " time is: " + ctime(time());
}
    
string GetHelp (string blah) {
    return "Syntax: people [-abceghlmnprsu]\n\n"
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
      "listing.\n\nSee also: allstatus, morals, summ, who";
}

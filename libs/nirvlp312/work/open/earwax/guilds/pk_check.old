int       TotPKills;   /* Total number of Player Kills */
string   *PKills;      /* Array of two key elements, the name of a Player killed,
                          and an array of every time the Shardak has killed
                          that Player */

getTime()
{
    string c, m, cx;
    c = ctime();

    switch(m = c[4..6]) {  /* un-truncate the month */
      case "Jan": m = "January";    break;
      case "Feb": m = "February";   break;
      case "Mar": m = "March";      break;
      case "Apr": m = "April";      break;
      case "Jun": m = "June";       break;
      case "Jul": m = "July";       break;
      case "Aug": m = "August";     break;
      case "Sep": m = "September";  break;
      case "Oct": m = "October";    break;
      case "Nov": m = "November";   break;
      case "Dec": m = "December";   break;
    }

    cx = c[8..9];
    if(cx[0] == ' ') cx = cx[1..1];
    return (m + " " + cx + ", " + c[20..23]);
}

kill_check(ob) {
  if(ob->is_player() && !ob->id("masakado")) {
    string oname;
    int i;
    if(!environment(environment()) || environment(environment())->query_spar_area()) return;
    tell_object(environment(), "\n\t\
You have slain " + (oname = ob->query_name()) + " and have recorded the kill.\n\n");
    CHANNELD->broadcast(environment()->query_name() + 
      " has killed " + oname + ".\n", 1, "[Servants]");
    TotPKills += ((int)ob->query_level() + (int)ob->query_extra_level());
    if(!PKills) PKills = ({ });
    i = member_array((oname = (string)ob->query_real_name()), PKills);
    if(i == -1)
      PKills += ({ oname, ({ getTime() }) });
    else
      PKills[i + 1] += ({ getTime() });

    save_me();
  }
}

query_pkills() { return PKills; }
query_tot_pkills() { return TotPKills; }

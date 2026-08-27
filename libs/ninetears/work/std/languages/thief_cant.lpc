
/*
 * The language of Thieves. *revised by Bivins*
 */


string long() {
  return "This is the Thieves Cant.\n";
}

mixed garble_say(string start, string rest) {
  string nam, loud;
  int roll;

  sscanf(start, "%s %s:", nam, start);
  if (sscanf(start, "%s loudly", start) == 1)
    loud = " and then coughs";
  else
    loud = "";
  switch (start) {
    case "asks" :
       nam = nam+" goes through a series of shaky gestures"+loud;
       break;
    case "exclaims" :
       nam = nam+" goes through a series of confident gestures"+loud;
       break;
    default :
       nam = nam+" goes through a series of quick gestures"+loud;
       break;
  }
roll=(random(20))+((int)this_player()->query_dex());
if(roll > 25)
  return ({ nam+".", "" });
 else
  return ({ " " });
}


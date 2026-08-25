/*
 * The language of the werewolf.
 */

string long() {
  return "The lonely howl of a werewolf.\n";
}

mixed garble_shout(string start, string rest)
{
  return ({ "wolf howls.","" });
}

mixed garble_say(string start, string rest) {
  string nam, loud;

  sscanf(start, "%s %s:", nam, start);
  if (sscanf(start, "%s loudly", start) == 1)
    loud = " loudly";
  else
    loud = "";
  switch (start) {
    case "asks" :
       nam = nam+" whines"+loud;
       break;
    case "exclaims" :
       nam = nam+" snarls"+loud;
       break;
    default :
     nam = nam+" howls"+loud;
       break;
  }
  return ({ nam+".", "" });
}

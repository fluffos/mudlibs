/*
 * The language of the wondrous Ducks.
 */

string long() {
  return "Consists of quacking noises.\n";
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
       nam = nam+" quizzically quacks"+loud;
       break;
    case "exclaims" :
       nam = nam+" pointedly quacks"+loud;
       break;
    default :
       nam = nam+" quacks"+loud;
       break;
  }
  return ({ nam+".", "" });
}

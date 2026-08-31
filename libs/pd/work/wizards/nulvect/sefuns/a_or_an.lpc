//   This Simul Efun determines of a or an is required in
//   a sentence.
//   Draconus 00-Aug-7
// changed to use switch by Nulvect 2007-11-10

string a_or_an(string str) {
  string res, check;

  str = strip_color(str);
  if (!str || !strlen(str)) return "";
  str = lower_case(str);

  switch (str[0..0]) {
  case "a": case "e": case "i": case "o": case "u":
    return "an";
  case "y":
    switch(str[1..1]) {
    case "a": case "e": case "i": case "o": case "u":
      return "a";
    default:
      return "an";
    }
  default:
    return "a";
  }

  return "a";
}

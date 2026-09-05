/*
 * lib/parse.c
 * Parse routines
 * Rumplemintz
 */

#pragma strong_types
#pragma no_clone
#pragma no_inherit

#include <libs.h>

inherit "basic/quote";
inherit "basic/create";

private string *num_s, *num_t;
private string *ord_s, *ord_t, *ord_n;

void create() {
  num_s = ({ "one","two","three","four","five","six","seven","eight","nine",
             "ten","eleven","twelve","thirteen","fourteen","fifteen",
             "sixteen","seventeen","eighteen","nineteen" });
  num_t = ({ "twenty","thirty","forty","fifty","sixty","seventy",
             "eighty","ninety" });
  ord_s = ({ "first","second","third","fourth","fifth","sixth","seventh",
             "eighth","ninth","tenth","eleventh","twelfth","thirteenth",
             "fourteenth","fifteenth","sixteenth","seventeenth","eighteenth",
             "nineteenth" });
  ord_t = ({ "twentieth","thirtieth","fortieth","fiftieth",
             "sixtieth","seventieth","eightieth","ninetieth" });
  ord_n = ({ "0th","1st","2nd","3rd","4th","5th","6th","7th","8th","9th" });
}

int parse_numeral(string str) {
  int s, t;
  string s_s, s_t;

  if (sscanf(str,"%d%s",s,s_t) == 2 && s && s_t == "")
    return s;
  if (sscanf(str,"%s-%s",s_t,s_s) == 2) {
    s = member(num_s, lower_case(s_s)) + 1;
    t = member(num_t, s_t) + 1;
    if (s && s < 10 && t)
      return t*10 + 10 + s;
  }
  if (s = member(num_s, lower_case(str)) + 1)
    return s;
  if (t = member(num_t, str) + 1)
    return t*10 + 10;
  return 0;
}

string get_numeral(int n) {
  return LIB_LANGUAGE->word_number(n);
}

int parse_ordinal(string str) {
  int s, t;
  string s_s, s_t;

  if (str == "last")
    return -1;
  if (strlen(str) > 3 &&
      sscanf(str[0..strlen(str)-4],"%d",t) == 1 && t &&
      (s=member(ord_n, extract(str,strlen(str)-3))) >= 0)
    return t*10 + s;
  if ((s=member(ord_n, str)) > 0)
    return s;
  if (sscanf(str,"%s-%s",s_t,s_s) == 2) {
    s = member(ord_s, s_s) + 1;
    t = member(num_t, s_t) + 1;
    if (s && s < 10 && t)
      return t*10 + 10 + s;
  }
  if ((s=member(ord_s, str) + 1))
    return s;
  if ((t=member(ord_t, str) + 1))
    return t*10 + 10;
  return 0;
}

varargs string get_ordinal(int n,status brief) {
  if (n < 0)
    return "even-lessth";  // well, raise_error() instead?
  if (n == 0)
    return "zeroth";  // dito
  if (n > 99 || brief) {
    if ((n % 100) < 11 || (n % 100) > 13) 
      switch (n % 10) {
      case 1:
        return n + "st";
      case 2:
        return n + "nd";
      case 3:
        return n + "rd";
      }
      return n + "th";
  }
  else if (n < 20)
    return ord_s[n-1];
  else if (!(n % 10))
    return ord_t[n/10 - 2];
  return num_t[n/10 - 2] + "-" + ord_s[n%10 - 1];
}

string singular(string str) {
#if 0
  string b, t;
  if (strlen(str) < 2)
    return str;
  b = str[0..strlen(str)-4];
  t = str[strlen(str)-4..strlen(str)-1];
  if (str == "corpses")
    return "corpse";
       if (t == "ses") return b + "s";
  else if (t == "xes") return b + "x";
  else if (t == "hes") return b + "h";
  else if (t == "ies") return b + "y";
  else if (t == "ves") return b + "fe";
  else if (t[2] == 's')
    return b + t[0..1];
  switch (str) {
  case "teeth":
    return "tooth";
  case "feet":
    return "foot";
  case "men":
    return "man";
  case "women":
    return "woman";
  case "children":
    return "child";
  case "sheep":
    return "sheep";
  }
  return str;
#else
  // this might not show exactly the same behaviour as the disabled part
  // above. i think this will not result in a problem though because to
  // 'singularize' an english plural word is not an easy task and all code
  // will make mistakes on that.
  mixed h;
  if (str[<4..] == "sses")  // special case: glasses, kisses, ...
    return str[0..<3];
  h = LIB_LANGUAGE->to_singular(str) - ({ str });
  if (!sizeof(h))
    return str;
  return find_map_extreme(h,#'strlen,#'>);
#endif
}


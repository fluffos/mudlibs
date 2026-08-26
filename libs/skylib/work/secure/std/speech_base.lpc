
/* command, trial out by Turrican for a commands daemon. */
#include <language.h>
#include <player.h>

varargs string query_word_type(string str, string def) {
  int i;

  if(!str || strlen(str) < 1)
    return "";

  for (i=strlen(str)-1; str[i] == ' '; i--);
  switch (str[i]) {
  case '!' :
    return "exclaim";
  case '?' :
    return "ask";
  default:
    if (def)
      return def;
    else
      return "say";
  }
} /* query_word_type() */

string mangle_tell(string mess, object dest) {
  int i;
  string ret;
  
  if(!TP || !environment(TP))
    return mess;
  
  if(environment(TP)->query_property( "reverse_tell" ) &&
     !creatorp(dest) && !creatorp(TP))
  {
    for (i=0;i<strlen(mess);i++)
      ret = mess[i..i]+ret;
    return ret;
  }
  return mess;
} /* mangle_tell() */
     
string drunk_speech(string str) {
  /* I think I like replace already */
  return replace(str, ({ "S", "sh", "r", "rr", "ing", "in'", "x", "xsh",
                         "S", "SH", "R", "RR" }));
} /* drunk_speech() */

string de_eight(string arg) {
/*  string replace_num;

  arg = "@ " + arg + "@";
  replace_num = ({ " seven plus one", " nine minus one",
                   " two to the power of three",
                   " four times two" })[random(4)];
  arg = implode(explode(arg, " eight"), replace_num);
  replace_num = ({ "(7+1)", "(9-1)", "(2^3)", "(4*2)" })[random(4)];
  arg = implode(explode(arg, "8"), replace_num);
  arg = arg[2..<2]; */
  return arg;
} /* de_eight() */

/* to properly columnate word_typed things */
void my_mess(string fish, string erk) {
  int bing;

  if (!interactive(TP)) {
    return;
  }
  bing = strlen(fish);
  if (bing > 15) {
     bing = 15;
  }
  efun::tell_object(TP, TP->fix_string(sprintf("%s%s\n", fish, erk),
                                       (int)TP->query_cols(), bing));
} /* my_mess() */

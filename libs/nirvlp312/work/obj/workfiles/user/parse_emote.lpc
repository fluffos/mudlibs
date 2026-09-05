/* parse_emote.c
  Generic emote parser for general usage
  By illarion 5 dec 2004
  Based on code by Vertebraker
*/

#define QN(x) (string)x->query_name();
#define POS(x) (string)x->query_possessive();
#define PRO(x) (string)x->query_pronoun();
#define OBJ(x) (string)x->query_objective();
#include <ansi.h>

string *PCodes, *ACodes, *TCodes;

void
reset(status arg)
{
  if (arg)
    return;

  PCodes = ({ "HB", "HY", "HR", "HG", "HC", "HW", "HK", "HM",
               "B", "Y", "R", "G", "C", "W", "K", "M", "H", "N" });

  ACodes = ({ HIB, HIY, HIR, HIG, HIC, HIW, HIK, HIM,
              BLU, YEL, RED, GRN, CYN, WHT, BLK, MAG, BOLD, NORM });
  
  TCodes = ({ "MN", "MP", "MS", "MO", "TN", "TP", "TS", "TO", "RET" });
}

varargs string replace_code(string str,object a,object b);

varargs string parse_emote(string str,object user,object targ) {
  string *frag;
  int s;
  frag = explode(str, "#");
  s = sizeof(frag);
  while(s--) frag[s] = replace_code(frag[s],user,targ);
  frag = explode(implode(frag, ""), "$");
  s = sizeof(frag);
  while(s--) frag[s] = replace_code(frag[s],user,targ);
  return implode(frag, "");
}

varargs string replace_code(string str,object a,object b) {
  string tmp;
  status cap;
  int code;
  if(!str)
    return "";
  code=member_array(str,PCodes);
  if(code != -1) return ACodes[code];
  if(sscanf(str,"C%s",tmp) && member_array(tmp,TCodes) != -1) {
    str=tmp;
    cap=1;
  }
  switch(str) {
    case "MN": if(a) str=QN(a);
      break;
    case "MP": if(a) str=POS(a);
      break;
    case "MS": if(a) str=PRO(a);
      break;
    case "MO": if(a) str=OBJ(a);
      break;
    case "TN": if(b) str=QN(b);
      break;
    case "TP": if(b) str=POS(b);
      break;
    case "TS": if(b) str=PRO(b);
      break;
    case "TO": if(b) str=OBJ(b);
      break;
    case "RET": str="\n";
      break;
  }
  if(!str) return "";
  return cap?capitalize(str):str;
}

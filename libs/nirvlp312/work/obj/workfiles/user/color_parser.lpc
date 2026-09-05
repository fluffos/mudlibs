#include <ansi.h>

string *PCodes, *ACodes;

void
reset(status arg)
{
  if (arg)
    return;

  PCodes = ({ "HB", "HY", "HR", "HG", "HC", "HW", "HK", "HM",
               "B", "Y", "R", "G", "C", "W", "K", "M", "H", "N" });

  ACodes = ({ HIB, HIY, HIR, HIG, HIC, HIW, HIK, HIM,
              BLU, YEL, RED, GRN, CYN, WHT, BLK, MAG, BOLD, NORM });
}

string
parse_pcodes(string arg) 
{
  string *t;
  int i, siz, code;

  siz = sizeof(t = explode(arg, "$"));

  for (i = 0; i < siz; i++)
  {
    if (i > 0 && t[(i - 1)] == "\\") /* Escape char */
      t[i] = "$";
    else
    {
      code = member_array(t[i], PCodes);

      if (code > -1)
        t[i] = ACodes[code];
    }
  }

  return (implode(t, ""));
}


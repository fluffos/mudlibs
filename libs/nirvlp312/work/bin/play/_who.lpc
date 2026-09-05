/******************************************************************************
 * Program: _who.c
 * Path: /bin/play
 * Type: Executable for who command
 * Created: 
 *
 * Purpose: Nirvana Player listing
 * 
 * History:
 *          04/24/2014 - Gnar
 *            Updated for prestige. Prestige level now shows and the sort
 *            is based on prestige score.
 ******************************************************************************/
/* I like this who, and it's still legal - Rumplemintz
   Parts taken from Illarion and Verte's who
*/

#include <ansi.h>

#define FAKE_PRES_SCORE 100000000
#define LEVEL_WIDTH 10

sort_by_score( object a, object b ) {
  return (a->is_wizard() ? (int)a->query_level()+FAKE_PRES_SCORE : (int)a->query_prestige_score()) <
         (b->is_wizard() ? (int)b->query_level()+FAKE_PRES_SCORE : (int)b->query_prestige_score());
}

string
add_zero(mixed str) {
  str = "" + str;
  if (strlen(str) == 1)
    str = "0" + str;
  return str;
}

int
cmd_who() {
  int lev, xlev, invis, plev;
  object *ppl;
  int x, count1, count2;
  string shrt, levstring;

  ppl = sort_array( users(), "sort_by_score");
  
  write("\n");
  write(BLU+
"<-------------------------------------------------------------------------->"+
NORM+"\n");
  write(HIW);
  write("\t\t\t  n  i  r  v  a  n  a\n");
  write(NORM);
  write("\t\t  ...since 1991: still the original.\n");
  write(BLU+
"<-------------------------------------------------------------------------->"+
NORM+"\n");
  for (x = 0; x <sizeof(ppl); x++) {
    string tmpstr;
    lev = (int)ppl[x]->query_level();
    invis = (int)ppl[x]->query_invis();
    shrt = (string)ppl[x]->short();
    xlev = (int)ppl[x]->query_extra_level();
    plev = (int) ppl[x]->query_prestige_level();
    if ((invis&&this_player()->query_level()+this_player()->query_extra_level()
         <  lev+xlev) ||
        lev < 1)
      continue;
    if (!shrt)
      shrt = "("+ppl[x]->query_real_name()+")";
    if (lev > 19) {
      levstring = BLU+"[";
      switch (lev) {
      case 100000:
        tmpstr = HIW+BLINK+"GOD";
        break;
      case 10000:
        tmpstr = HIR+"DEMI";
        break;
      case 5000..9999:
        tmpstr = HIY+"ARCH";
        break;
      case 1000:
        tmpstr = HIG+"ELDER";
        break;
      case 101..999:
        tmpstr = CYN+"DIRECTOR";
        break;
      case 100:
        tmpstr = HIC+"SENIOR";
        break;
      case 41..99:
        tmpstr = HIM+"MENTOR";
        break;
      case 30..40:
        tmpstr = CYN+"WIZARD";
        break;
      case 21..29:
        tmpstr = MAG+"NEWWIZ";
        break;
      case 20:
        tmpstr = WHT+"APPWIZ";
        break;
      }
      if((string)ppl[x]->query_real_name() == "illarion")
        tmpstr = YEL+"MONKEY";
      levstring +=  ralign( tmpstr, LEVEL_WIDTH-1 ) + NORM+BLU+" ]"+NORM;
      write(levstring);
      write(shrt);
      write("\n");
      count2++;
    } else {
      levstring = BLU+"{"+NORM+center(lev+(xlev ? "+"+add_zero(xlev) : "")+(plev ? HIG+"{"+plev+"}"+NORM : ""),LEVEL_WIDTH) +  BLU+"}"+NORM;
      /*
      if (xlev = (int)ppl[x]->query_extra_level())
        levstring = BLU+" {"+NORM+" "+lev+(plev ? HIG+"["+plev+"]" : "")"+"+pad(add_zero(xlev),3);
      else
        levstring = BLU+" {"+NORM+"   "+pad(""+lev,2)+"  ";
      levstring += BLU+"}"+NORM+" ";
      */
      write(levstring);
      write(shrt);
      write("\n");
      count1++;
    }
  }
  write(BLU+
"<-------------------------------------------------------------------------->"+
NORM+"\n");
  write("    "+count2+" wizard"+(count2 == 1 ? "" : "s")+" online");
  write("    "+count1+" player"+(count1 == 1 ? "" : "s" )+" online\n");
  return 1;
}

/* I like this who, and it's still legal - Rumplemintz
   Parts taken from Illarion and Verte's who
*/

#include <ansi.h>

inherit "/players/rumplemintz/closed/ansi_pad";

object *
sort_by_level(object *who) {
  int i, j, sorted;
  object tmp;

  j = sizeof(who);
  sorted = 0;
  while (!sorted) {
    sorted = 1;
    j --;
    for (i = 0; i < j; i ++) {
      if (who[i]->query_level() < 20) {
        if (who[i]->query_level() + who[i]->query_extra_level() <
            who[i+1]->query_level() + who[i+1]->query_extra_level()) {
          tmp = who[i];
          who[i] = who[i+1];
          who[i+1] = tmp;
          sorted = 0;
        }
      } else if (who[i]->query_level() < who[i+1]->query_level()) {
        tmp = who[i];
        who[i] = who[i+1];
        who[i+1] = tmp;
        sorted = 0;
      }
    }
  }
  return who;
}

string
add_zero(mixed str) {
  str = "" + str;
  if (strlen(str) == 1)
    str = "0" + str;
  return str;
}

int
cmd_who4() {
  int lev, xlev, invis;
  object *ppl;
  int x, count1, count2;
  string shrt, levstring;
  string *shrt2;
  string short_line1;
  string short_line2;
  int shrt2_count, y;

  ppl = sort_by_level(users());

  write("\n");
write(YEL+
"     ________________________________________________________________________\n"+
"    /  \\                         "+HIW+"n  i  r  v  a  n  a"+NORM+YEL+"                         \\ \n"+
"   |    |                "+NORM+"..since 1991: still the original.."+NORM+YEL+"                  | \n"+
"   |\\__/_____________________________________________________________________/"+NORM+"\n"+
YEL+
"   |                                                                        | "+NORM+"\n");
  for (x = 0; x <sizeof(ppl); x++) {
    lev = (int)ppl[x]->query_level();
    invis = (int)ppl[x]->query_invis();
    shrt = (string)ppl[x]->short();
    xlev = (int)ppl[x]->query_extra_level();
    if ((invis&&this_player()->query_level()+this_player()->query_extra_level()
         < lev+xlev) || lev < 1)
      continue;

    if (!shrt)
      shrt = "("+ppl[x]->query_real_name()+")";
    if (lev > 19) {
      switch (lev) {
      case 100000:
        levstring = BLU+"[     "+HIW+BLINK+"GOD"+NORM+BLU+" ]"+NORM;
        break;
      case 10000:
        levstring = BLU+"[    "+HIR+"DEMI"+NORM+BLU+" ]"+NORM;
        break;
      case 5000..9999:
        levstring = BLU+"[    "+HIY+"ARCH"+NORM+BLU+" ]"+NORM;
        break;
      case 1000:
        levstring = BLU+"[   "+HIG+"ELDER"+NORM+BLU+" ]"+NORM;
        break;
      case 101..999:
        levstring = BLU+"["+CYN+"DIRECTOR"+NORM+BLU+" ]"+NORM;
        break;
      case 100:
        levstring = BLU+"[  "+HIC+"SENIOR"+NORM+BLU+" ]"+NORM;
        break;
      case 41..99:
        levstring = BLU+"[  "+HIM+"MENTOR"+NORM+BLU+" ]"+NORM;
        break;
      case 30..40:
        levstring = BLU+"[  "+CYN+"WIZARD"+NORM+BLU+" ]"+NORM;
        break;
      case 21..29:
        levstring = BLU+"[  "+MAG+"NEWWIZ"+NORM+BLU+" ]"+NORM;
        break;
      case 20:
        levstring = BLU+"[  "+WHT+"APPWIZ"+NORM+BLU+" ]"+NORM;
        break;
      }
	  count2++;
	} else
	{
      if (xlev = (int)ppl[x]->query_extra_level())
        levstring = BLU+" {"+NORM+" "+lev+"+"+pad(add_zero(xlev),3);
      else
        levstring = BLU+" {"+NORM+"   "+pad(""+lev,2)+"  ";
      levstring += BLU+"}"+NORM+" ";
	  count1++;
	
	}

		
                shrt2 = explode(ansi_format(shrt, 59), "\n");
		shrt2_count = sizeof(shrt2);
		for(y=0; y <shrt2_count; y++)
		{
			write(YEL+"   | "+(y==0?levstring:NORM+"           "));
			write(ansi_pad(shrt2[y], 59));
			write(YEL+" |"+NORM+"\n");		
		}
  }
write(YEL+
" /\\|                                                                        |   \n"+
"|  |                      "+NORM+count2+" wizard"+(count2 == 1 ? " " : "s")+" online"+
"     "+count1+" player"+(count1 == 1 ? " " : "s" )+" online"+YEL+
"             | \n"+
" \\/________________________________________________________________________/"+NORM+"\n");
  return 1;
}

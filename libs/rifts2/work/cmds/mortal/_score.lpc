/* $Header: /mud/tkv/bin/player/RCS/_score.c,v 1.2 1995/08/26 23:41:43 mudriver Exp $
 * $Log: _score.c,v $
 * Revision 1.2  1995/08/26  23:41:43  mudriver
 * Changed the query_[hp,mp,sp,max_hp,max_sp,max_mp] calls
 * to reflect the new query_body(string what) function.
 *
 * Revision 1.1  1995/07/09  10:00:50  mudriver
 * Initial revision
 *
 * /bin/player/_score.c
 * created completely by Zortek
 */
#include <std.h>

inherit DAEMON;

#define MAX_BAR_COLS 55

		      string
		      bargraph(int gauge, int max, int flag)
		      {
			  string          borg;
			  int             i,
			  columns;

			  if (!max)
			      max = 1;
			  columns = (MAX_BAR_COLS * gauge) / max - 1;
			  if(flag)
			      switch(to_int(columns)) {
			  case -100..6:
			      borg = "%^FLASH%^%^B_RED%^%^YELLOW%^";
			      break;
			  case 7..14:
			      borg = "%^B_RED%^%^YELLOW%^";
			      break;
			  case 15..30:
			      borg = "%^YELLOW%^";
			      break;
			  case 31..45:
			      borg = "%^BLUE%^BOLD%^";
			      break;
			  case 46..54:
			      borg = "%^GREEN%^%^BOLD%^";
			      break;
			  default:
			      borg = "";
			      break;
			  }
			  else
			      switch(to_int(columns)) {
			  case -100..6:
			      borg = "";
			      break;
			  case 7..14:
			      borg = "%^BOLD%^GREEN%^";
			      break;
			  case 15..30:
			      borg = "%^BOLD%^BLUE%^";
			      break;
			  case 31..45:
			      borg = "%^YELLOW%^";
			      break;
			  case 46..50:
			      borg = "%^B_RED%^%^BOLD%^";
			      break;
			  default:
			      borg = "%^FLASH%^%^B_RED%^%^YELLOW%^";
			      break;
			  }
			  for (i = 0; i < MAX_BAR_COLS; i++)
			      borg += (i <= columns ? "*" : " ");

			  return borg;
		      }

		      string          dashes =
		      "----------------------------------------------------------------------";

			  string          title,
			  alerts,

			  *pic_string,
			  *attrib,
			  borg,
			  gm,
			  age3, hand, hand2, ccatch,
			  foo;
			  int             hp,
			  max_hp,
			  sdc,
			  max_sdc,
			  mp,
			  max_mp,
			  sp,
			  max_sp,
			  level,
			  intox,
			  qp,
			  age2;
			  object          tp,
			  op;
                          int exp,nexp,lexp,nlevel;
		      int
		      cmd_score(string who)
		      {


			  tp = this_player();
			  attrib = ({ "", "", "", "", "", "", "", "", });

			  if (!who)
			      op = tp;
			  else if (!wizardp(tp))
			      return 0;
			  else if (!(op = find_living(who)))
			      return 0;
			  else if (!(op = find_living(who)))
			      return 0;

                          level=op->query_level();
                          nlevel=level+1;
                          exp=op->query_exp();

			  title = (string) op->query_title();
			  hp = (int) op->query_hp();
			  max_hp = (int) op->query_max_hp();
			  sdc = (int) op->query_sdc();
			  max_sdc = (int) op->query_max_sdc();
			  sp = (int) op->query_internal_encumbrance();
			  max_sp = (int) op->query_max_internal_encumbrance();
			  mp = (int) op->query_ppe();
			  max_mp = (int) op->query_max_ppe();
                          ccatch = (string) op->query_catch();

			  // Some Mods by Drizzt 3/27/96
			      age2 = (int) op->query_age();
			      qp = (int) op->query_quest_points();
				if(age2>86400) age3 = (age2/86400 + " Days");
				else if(age2>3600) age3 = (age2/3600) + " Hours";
				else age3 = (age2/60) + " Min";
			    hand2 = "Unknown Handedness";

			      attrib[0] = sprintf("%d", (int) op->query_level());
			      attrib[1] = op->query_race() ? capitalize((string) op->query_race()) : "N/A";
			      attrib[2] = age3;
			      attrib[3] = sprintf("%d", (int)op->query_property("dev points"));
			      intox = (int) op->query_intox();
			      switch (intox) {
				case 420..10000: attrib[4] = "FUBAR"; break;
				case 300..419:   attrib[4] = "Smashed"; break;
				case 180..299:   attrib[4] = "Roaring drunk"; break;
				case 90..170:    attrib[4] = "Drunk"; break;
				case 36..89:     attrib[4] = "Tipsy"; break;
				case 1..35:      attrib[4] = "Buzzed"; break;
				case 0:
				default:         attrib[4] = "Sober"; break;
			      }
			      // reusing variable
			      intox = (int)op->query_quenched();
			      switch (intox) {
				case 420..10000: attrib[5] = "Liquid Blob!"; break;
				case 300..419:   attrib[5] = "Bloated"; break;
				case 180..299:   attrib[5] = "Full"; break;
				case 90..170:    attrib[5] = "Satisfied"; break;
				case 36..89:     attrib[5] = "Thirsty"; break;
				case 1..35:      attrib[5] = "Parched"; break;
				case 0:
				default:         attrib[5] = "Dehydrated"; break;
			      }
			      // reusing variable AGAIN :)
			      intox = (int)op->query_stuffed();
			      switch (intox) {
				case 420..10000: attrib[6] = "Glutton!"; break;
				case 300..419:   attrib[6] = "Distended"; break;
				case 180..299:   attrib[6] = "Full"; break;
				case 90..170:    attrib[6] = "Satisfied"; break;
				case 36..89:     attrib[6] = "Hungry"; break;
				case 1..35:      attrib[6] = "Malnurished"; break;
				case 0:
				default:         attrib[6] = "Starving"; break;
			      }
			      attrib[7] = (op->query_class() ) ? capitalize((string) op->query_class()) : "";
			      alerts = (op->query_poisoning() ? "Poison " : " ");

			      message("Ninfo", "%^BOLD%^%^WHITE%^" + sprintf("%|72s\n", title), tp);
			      message("Ninfo", "%^BLUE%^" + sprintf("%s\n", dashes), tp);

			      message("Ninfo", "%^BLUE%^       +------------------------------------------------------------+%^RESET%^ \n", tp);
			      message("Ninfo", "    HP %^BLUE%^|%^RESET%^" + bargraph(hp, max_hp,1)   + "%^RESET%^%^BLUE%^|%^RESET%^ " + hp  + "\n", tp);
				  message("Ninfo", "   SDC %^BLUE%^|%^RESET%^" + bargraph(sdc, max_sdc,1) + "%^RESET%^%^BLUE%^|%^RESET%^ " + sdc + "\n", tp);
			      message("Ninfo", "   PPE %^BLUE%^|%^RESET%^" + bargraph(mp, max_mp,1)   + "%^RESET%^%^BLUE%^|%^RESET%^ " + mp  + "\n", tp);
			      message("Ninfo", "%^BLUE%^       +------------------------------------------------------------+\n", tp);

			      message("Ninfo", "%^BLUE%^" + sprintf("%s\n", dashes), tp);

			      message("Ninfo", "%^BLUE%^ Level: %^RESET%^" + sprintf("%-15s", attrib[0]) + "%^BLUE%^|%^RESET%^" + "                   " + "%^BLUE%^|%^GREEN%^          WEALTH\n", tp);

			      message("Ninfo", "%^BLUE%^  Race: %^RESET%^" + sprintf("%-15s", attrib[1]) + "%^BLUE%^|%^RESET%^" +  "                   " + "%^BLUE%^|%^RESET%^" + sprintf("%12s:  %11i\n","Credits", op->query_money("credits")), tp);

			      message("Ninfo", "%^BLUE%^   Age: %^RESET%^" + sprintf("%-15s", attrib[2]) + "%^BLUE%^|%^RESET%^" + "                   " + "%^BLUE%^|%^RESET%^\n", tp);

			      message("Ninfo", "%^BLUE%^ State: %^RESET%^" + sprintf("%-15s", attrib[4]) + "%^BLUE%^|%^RESET%^" + "                   " + "%^BLUE%^|%^RESET%^\n", tp);

			      message("Ninfo", "%^BLUE%^Thirst: %^RESET%^" + sprintf("%-15s", attrib[5]) + "%^BLUE%^|%^RESET%^" + "                   " + "%^BLUE%^|--------------------------\n", tp);

                  message("Ninfo", "%^BLUE%^Hunger: %^RESET%^" + sprintf("%-15s", attrib[6]) + "%^BLUE%^|%^RESET%^" + "                   " + "%^BLUE%^|%^RESET%^ Experience:  " + sprintf("%12i\n", op->query_exp()), tp);

			      message("Ninfo", "%^BLUE%^Catch:  %^RESET%^" + sprintf("%-15s", ccatch)    + "%^BLUE%^|%^RESET%^" + "                   " + "%^BLUE%^|%^RESET%^\n" , tp);

			      message("Ninfo", "%^BLUE%^Alerts: %^RESET%^" + sprintf("%-15s", alerts) + "%^RESET%^%^BLUE%^|                   |%^RESET%^\n", tp);

			      message("Ninfo", sprintf("%-21s", hand2) + "  %^BLUE%^|%^RESET%^                   " + "%^BLUE%^|%^RESET%^\n", tp);

			      message("Ninfo", "%^BLUE%^" + sprintf("%s\n", dashes) + "%^RESET%^", tp);
			      return 1;
			  }

			  int
			  help()
			  {
			      write(@HELP
Syntax:  score [person]
This command give you information about your character.

See also: status, biography, skills, stats, money, inventory
HELP
);
			      return 1;
			  }


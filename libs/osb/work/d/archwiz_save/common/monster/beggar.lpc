/* Cadra@Nightfall 03-10-1994 */

#include "path.h"

inherit "/std/npc";

create() {
  if (::create()) return 1;
  SetName("beggar");
  SetLong("A really filthy looking poor beggar.\n");
  SetLevel(5);
  SetRace("human");
  SetAlign(200);
  SetAC(5);
  InitChats(1,
({"Beggar says: Please, give money to a poor beggar!\n",
  "Beggar says: Why can't I find any money ?\n",
  "Beggar says: two coins please !\n"}) );
  InitAChats(20,
({"Beggar says: Why do you do this to me ?\n"}) );
  SetMaxDrink(5000);
  SetMaxAlc(5000);
}
init() {
  ::init();
  add_action("give_me","give");
}

int give(string str) {
  if (!str) return 0;
  if (!this_player()) return 0;
  }

// made by magictcs - 8 may 1997
// part of the library of the madmonks

#include <properties.h>
#include "/p/guilds/madmonks/madmonks.h"

#define SLIB "/lib/string"

inherit "/std/thing";

void close_quests_scroll() {
  if (TP) {
    show(NAME+" closes the scroll of quests.\n");
    write("You close the scroll of Quests.\n");
  }
}

/*int list_quests(string str) {
  object scroll;
  if (!str) return 0;
  scroll=search(this_player(),"scroll from bag")
  if (!scroll) return 0;
//  if (str=="scroll" || str=="scroll of quests") {
  if (scroll==id("mmscroll")) {
    show(NAME+" opens the scroll of quests.\n");
    write("You open the scroll of quests.\n"
          "You read the scroll of quests.\n");
    SLIB->smore(QUESTMASTER->ListQuests(TP),TP->QueryPageSize(),TO,
      "close_quests_scroll");
    return 1;
  }
  return 0;
}
*/

string list_quests() {
  show(NAME+" opens the scroll of quests.\n");
  write("You open the scroll of quests.\n"
        "You read the scroll of quests.\n");
  SLIB->smore(QUESTMASTER->ListQuests(TP),TP->QueryPageSize(),TO,
      "close_quests_scroll");
  return " ";
}

create() {
  ::create();
  SetShort("a scroll");
  SetLong("The scroll contains all available quests. Okazi updates "
              "this scroll if a new quests is available - because it's "
              "his job.\n");
  AddId(({"scroll","scroll of quests","mmscroll"}));
  SetWeight(120);
  SetValue(5);
  SetReadMsg(#'list_quests);
}
/*
init() {
  ::init();
  add_action("list_quests","read");     // because using smore!
}
*/

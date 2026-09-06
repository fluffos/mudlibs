// made by magictcs - 8 may 1997
// part of the library of the madmonks

#include <properties.h>
#include "/p/guilds/madmonks/madmonks.h"

inherit "/std/thing";

int number;
void SetNumber(int num) { number=num; }

string list_quests() {
  string ret;
  ret="You open the scroll.\n"
      "You read the scroll.\n";
  ret+=QUESTMASTER->QueryQuestLong(number-1);
  if (QUESTMASTER->QueryQuestSolved(number-1,TP))
    ret+="You have already solved this quest - congratulation.\n";
  ret+="You close the scroll of quest "+number+".\n";
  return ret;
}

string QueryLong() {
  return
  "The scroll contains the quest description of quest number "+number+".\n"
  "You can read it.\n";
}

string QueryShort() {
  return "a scroll of quest "+number;
}

create() {
  ::create();
  AddId(({"scroll","mmscroll"}));
  SetWeight(120);
  SetValue(5);
  SetReadMsg(#'list_quests);
}

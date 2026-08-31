// Grand prize for waterworld !!
//     coded by Ironman

#include <std.h>
#include <waterworld.h>

inherit OBJECT;

int additions();

void create() {
  ::create();
  set_name("atlantian ambrosia");
  set_id(({"atlantian ambrosia","ambrosia","bottle","vial"}));
  set_short("The %^MAGENTA%^At%^ORANGE%^lan%^RED%^ti%^BLUE%^an%^RESET%^ %^YELLOW%^Ambro%^BLACK%^%^BOLD%^si%^RED%^%^BOLD%^a%^RESET%^");
  set_long(
   "Legend has it that whomever uses this vial will have their abilities increased dramatically!"
   " There is a label on the bottle. Perhaps you can %^BOLD%^read bottle%^RESET%^ and figure out how to use it.");

  set_read("default",
   " This is a special blend of our rarest flower, the ambrosia!"
   "\nIf you %^BOLD%^quaff vial%^RESET%^ you will be given the opportunity to enhance your powers dramatically."
   "\n\n Signed\n\n     Poseidon, Lord of Atlantis");
  set_weight(10);
  set_curr_value("gold",10);
}

void init() {
  ::init();
  add_action("quaff","quaff");
}

int quaff(string str) {
  object TP=this_player();
  object TR=environment(TP);
  string cap_tp=TP->query_cap_name();

  if(str && str=="vial") {
    message("info","Time seems to stand still as an image of Lord Poseidon enters your mind.",TP);
    additions();
    return 1;
  }
}

void additions() {
  object TP=this_player();
  object TR=environment(TP);
  string cap_tp=TP->query_cap_name();
  string target;

  message("say","Lord Poseidon echos in your mind: "+cap_tp+", you have drunk from the Ambrosia nectar!! Now you must select which of your stats you wish to improve!!",TP);
  message("info",cap_tp+" seems to freeze in place as a soft blue haze seals them in...",TR,TP);

  message("info",
   "\n\nEnter a number as follows;"
   "\n      (1) Constitution"
   "\n      (2) Strength"
   "\n      (3) Dexterity"
   "\n      (4) Wisdom"
   "\n      (5) Intelligence"
   "\n      (6) Charisma"
   "\n\nChoose wisely!!\n\n"
   ,TP);
  remove_action("quaff","quaff");
  add_action("choose","choose");
}
int choose(string choice) {
  object TP=this_player();
  object ME=this_object();
  int value=(2+(random(random(8))));
  string target;
  int points;

  switch(choice) {

  case "1": target="constitution";
    break;
  case "2": target="strength";
    break;
  case "3": target="dexterity";
    break;
  case "4": target="wisdom";
    break;
  case "5": target="intelligence";
    break;
  case "6": target="charisma";
    break;
  default: message("info","That is an invalid selection",TP);
  }

  points=TP->query_stats(target);
  TP->set_stats(target,(points+value));
  message("info","Your "+target+" has changed from "+points+" to "+(points+value)+"!! Congratulations.",TP);
  ME->remove();
}

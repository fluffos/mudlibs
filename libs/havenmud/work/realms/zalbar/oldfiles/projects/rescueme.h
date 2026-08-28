// Title : Durgoroth Town
// File: rescueme.h
// Author: Tim Morris aka Morgoth@Haven
// Date: March 1998
//
// Abstract:	Inheritable which allows town leaders to summon
//				a guard to defend them from attackers.
//
// Revision History: For Kylin Outpost
//

void summonGuard();
void toMe();
void leaderToMe();
void anotherGuard();
void newGuard();
void toMeGuard();
int IDie();


void summonGuard() {
  object who = this_object();
  if (!(present("durgoroth guard", environment(who)))) {
    who->eventForce("speak Help! Guards!");
    call_out((: newGuard :), 15);
  }
}

void toMe() {
  object who = this_object();
  if (!(present("durgoroth guard", environment(who)))) {
    who->eventForce("speak To me men! To me!");
    call_out((: toMeGuard :), 15);
  }
}

void leaderToMe() {
  object who = this_object();
  who->eventForce("speak To me men! To me!");
  if (!(present("durgoroth guard", environment(who)))) {
    call_out((: toMeGuard :), 15);
  } else call_out((: toMeGuard :), 90) n;
}

void newGuard() {
  object who = this_object();
  object grd;
  message("enter", "A burly Durgoroth guard charges in, "
    "responding to " + who->GetCapName() + "'s cries for help.",
    environment(who));
  grd = new(D_NPC + "/guard");
  grd->eventMove(environment(who));
  call_out((: call_other, grd, "eventForce", "snarl" :), 2);
  call_out((: call_other, grd, "eventForce",
    "speak Die villian!" :), 5);
}

void toMeGuard() {
  object who = this_object();
  object grd;
  message("enter", "A burly Durgoroth guard charges to the aid "
    "of " + who->GetCapName() + ".", environment(who));
  grd = new(D_NPC + "/guard");
  grd->eventMove(environment(who));
  call_out((: call_other, grd, "eventForce", "snarl" :), 2);
  call_out((: call_other, grd, "eventForce",
    "speak Die scum!" :), 5);
}

int IDie() {
  return 1;
}

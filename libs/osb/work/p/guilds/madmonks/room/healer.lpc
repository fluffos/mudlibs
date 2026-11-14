// the healer room for the madmonks guild
// made by Magictcs - 11  may 97
// the room will not log missing details

#include <rooms.h>
#include <properties.h>
#include <moving.h>
#include <guild.h>

#ifdef ONESTEPBEYOND
#include <secure/wizlevels.h>
#else
#include <wizlevels.h>
#endif

#include <news.h>
#include <npc.h>
#include <health.h>
#include "/p/guilds/madmonks/madmonks.h"

inherit "/obj/healer";

string lookrunes() {
  return
  "You read: The healer office - written with blood.\n"
  "     --> Self Service <--\n";
}

string Name(mixed cap) {
  if (cap) return "Some words appears in the air right before you:\n";
  else return "some words appears in the air right before you:\n";
}

// overload see and show
/*
int see (string *msgs) {
dtell("magictcs","SEE_OUT: "+msgs+"\n");
  return ::see(msgs);
}

object *show (string *msg, object *excl ) {
dtell("magictcs","SHOW_OUT: "+msg+"\n");
  return ::show(msg,excl);
}
*/

// overload the Say function for better fitting the buttons
mixed change_msg(mixed str) {
  mixed new;
//  new=string_replace(new,"","");
//  new=string_replace(new,"","");
//  new=string_replace(new,"buy","deposit");
  new=str;
  return new;
}

public void Say(mixed message) {
  mixed new;
  string ms;
  // copied from /obj/lib/communication for better fitting - little bit changed
  if (!TP||!environment(TP)) return;
  if (closurep(message))
    ms = funcall(message,TP,Name());
  else
    ms = message;
//dtell("magictcs","SAY_OUT: "+message+" || "+ms+"\n");
  new=change_msg(ms);
  if (stringp(ms))
    {
      see(({wrap(Name(1)+parse_string(ms),0,3),
            wrap("Someone says: "+parse_string(ms),0,3)}));
      show(({wrap(Name(1)+parse_string(ms),0,3),
             wrap("Someone says: "+parse_string(ms),0,3)}));
    }
}

// overload Emote and see and show too :(((((((((

// no healer here - so do not emote!
//public void Emote(mixed message) {}

//*******************
// press white button
//*******************
// cure poison
void press_white_button() {
  write("You press the white button!\n");
  show(NAME+" operates with the buttons.\n");
  cmd_cure("poison");
}

//*******************
// press green button
//*******************
// ????
// maybe inform about health?
void press_green_button() {
  write("You press the green button!\n");
  show(NAME+" operates with the buttons.\n");
}

//********************
// press yellow button
//********************
// ????
void press_yellow_button() {
  write("You press the yellow button!\n");
  show(NAME+" operates with the buttons.\n");
}

//********************
// press orange button
//********************
// ???
void press_orange_button() {
  write("You press the orange button!\n");
  show(NAME+" operates with the buttons.\n");
}

//*****************
// press red button
//*****************
// treat serious wounds
void press_red_button() {
  write("You press the red button!\n");
  show(NAME+" operates with the buttons.\n");
  if (cmd_treat("serious wounds")) { write("You are healed a bit.\n"); }
  else { write("You are perfectly healthy.\n"); };
}

//*******************
// press black button
//*******************
// ???
void press_black_button() {
  write("You press the black button!\n");
  show(NAME+" operates with the buttons.\n");
}

//*************
// press button
//*************
int press_button(string s) {
  string str;
  if (!s) { notify_fail("Try: press <color> button\n"); return 0; }
  str=norm_id(s);
  switch (str) {
    case "white button":  { press_white_button();  return 1; }
    case "green button":  { press_green_button();  return 1; }
    case "yellow button": { press_yellow_button(); return 1; }
    case "orange button": { press_orange_button(); return 1; }
    case "red button":    { press_red_button();    return 1; }
    case "black button":  { press_black_button();  return 1; }
  }
  notify_fail("Try: press <color> button\n");
  return 0;
}

create() {
  ::create();
  SetIntShort("The madmonk healer");
  SetIntLong(
    "You're in a small room.\n"
    "On the south wall are some runes and some buttons.\n");

  /* detail */
  RemoveDetail("sign");                         // the standard one
  RemoveDetail(({"hut","entrance"}));
  RemoveDetail(({"man","healer","old man"}));

  AddDetail(({"small room","madmonk healer","healer"}),#'IntLong);
  AddDetail("runes",
    "The runes are very old. They are written in red color.\n"
    "Must be blood! But you can still read them.\n");
  AddDetail(({"color","red color"}),
    "The color looks like red blood!\n");
  AddDetail("blood",
    "You touch it with your fingers.\n"
    "Yes it's really blood!\n");
  AddDetail("south wall",
    "The south wall has some rune some it!\n");
  AddDetail(({"wall","walls"}),
    "The walls are looking as every wall in the Dojo.\n");
  AddReadMsg(({"runes","old runes","very old runes"}),
    #'lookrunes);

  /* the buttons */
  AddDetail(({"buttons","some buttons"}),
    "You see a buttons of different colors:\n"
    "Pressing the buttons will cost you some money!\n"
    "white, green, yellow, orange, red and black.\n");
  AddDetail("button","Try: look <color> button\n");
  AddDetail(({"white button"}),
    "Pressing the white button will cure poison.\n");
  AddDetail("green button",
    "If you press the green button, your virus will be gone.\n");
  AddDetail("yellow button",
    "");
  AddDetail("orange button",
    "");
  AddDetail(({"red button","simple red button","button red"}),
    "It is a simple red button - pressing it will heal your serious wounds.\n");
  AddDetail("black button",
    "It is a black button - ?????\n");

  // The healer will heal all: wounds,poison,virus,curse
  //  AllowCurse();

  SetTreatMsg(({
    "Some rays of red light are shot from the wall to you. Your body is\n"
    "enveloped with the red light. After some seconds the light vanishes.",
    "Some rays of red light shoot out of the wall to @@PlName@@ and heals\n"
    "@@PlPossessive@@ body.\n"}));
  SetPoisonMsg(({
    "Some rays of white light are shot from the wall to you. Your body is\n"
    "enveloped with the white light. The white light sucks the poison out of\n"
    "your body!\n",
    "Some rays of white light shoot out of the wall to @@PlName@@ and removes\n"
    "the poison of @@PlPossessive@@ body.\n"}));
  SetVirusMsg(({"s","we"}));
  SetCurseMsg(({"x","w"}));

  SetIndoors(1);

  AddExit("east",MONKROOM("restaurant"));
  AddRoomCmd("press","press_button");
}


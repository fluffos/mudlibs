/* 
 * entry to the library
 * possibility: clean,smash,break,open,close,enter window
 * made by magictcs 1 jun 97
 *
 * last changes:
 * [m] 11 jan 97 - remade
 */

#include <properties.h>
#include <moving.h>
#include <npc.h>
#include <regions.h>
#include <coordinates.h>
#include <sykorath.h>

inherit SY_STREET;

string dirty;

//********************
// dirty prop handling
//********************
string SetDirty(string str) { if (str) dirty=str; return dirty; }
string QueryDirty() { return dirty; }

//****************
// detail handling
//****************
string lookwall() {      // has to be a closure (because of the dirty string)
  return
  "The walls of the other houses form this road. It is a little bit dark\n"
  "here, because the high walls block all the sunlight.\n"
  "A "+dirty+" window is in the north wall.\n";
}

string lookhouse() {
  return
  "You see only some walls of them. But there is a "+dirty+" window here.\n";
}

string lookwindow() {
  string ret;
  if (dirty=="broken") {
    return
    "The window is broken now. You can't see anything except the room\n"
    "behind the smashed window.\n"
    "You may enter the window now.\n";
  }
  ret="A window in a this road? Very mysterious!\n"
    "It doesn't look like a normal window. There seems to be something\n"
    "special with this window?\n";
  if (dirty=="dirty") {
    ret+=
    "But the window is really dirty. You can't see anything in it. Maybe\n"
    "you can clean the window to see something more?\n";
  }
  if (dirty=="clean") {
    ret+=
    "The window is cleaned now. You look at the window and take a direct\n"
    "view into the library of the city:\n\n";
    ret+=call_other(INNER("library"),"GetIntDesc");
    ret+="\nWow what for a useful window. Why was it so dirty?\n";
    ret+="You can't understand this!\n";
  }
  return ret;
}

string lookdirtywindow() {
  if (dirty!="dirty")
    return "There is no dirty window anywhere.\n";
  return lookwindow();
}

string lookcleanwindow() {
  if (dirty!="clean")
    return "There is no clean window anywhere.\n";
  return lookwindow();
}

string looksmashwindow() {
  if (dirty!="broken")
    return "There is no broken window anywhere.\n";
  return lookwindow();
}

// if window == broken --> heap of glass is left
string lookglass() {
  if (dirty!="broken")
    return
    "There is no heap of glass here!\n";
  return
  "Only a little heap of glass. Nothing to be more mentioned.\n";
}

//*****************
// clean the window
//*****************
int cleanwindow(string str) {
  if (!str) { notify_fail("Clean what?\n"); return 0; }
  if (str=="window" || str=="dirty window") {
    if (dirty!="dirty") {
      write("The window is cleaned already.\n");
      return 1;
    }
    write(
      "You clean the dirty window. Now you can try to take a closer look at\n"
      "the window.\n");
    show(NAME+" cleans the window.\n");
    dirty="clean";
    return 1;
  }
  notify_fail("There is no "+str+" to clean.\n");
  return 0;
}

//*******************
// smash/break window
//*******************
int smashwindow(string str) {
  if (!str) return 0;
  str=norm_id(str);
  if ((str=="window" && dirty!="broken")
    || (str=="dirty window" && dirty=="dirty")
    || (str=="clean window" && dirty=="clean")) {
    TP->ReduceHP(5,5);    // maybe use Defend?
    write(
      "You smash the "+str+" to pieces. The glass cuts your skin a little\n"
      "bit. Better to do such actions not very often!\n"
      "There are only a heap of glass left now.\n");
    show(NAME+" smashes the window to pieces.\n");
    TP->SetExplored();
    dirty="broken";
    return 1;
  }
  notify_fail("There is no "+str+" to smash or break.\n");
  return 0;
}

int smashwindow1(string str) {
  if (!str) { notify_fail("Smash what?\n"); return 0; }
  return smashwindow(str);
}

int smashwindow2(string str) {
  if (!str) { notify_fail("Break what?\n"); return 0; }
  return smashwindow(str);
}

int smashwindow3(string str) {
  if (!str) { notify_fail("Destroy what?\n"); return 0; }
  return smashwindow(str);
}

//*************
// enter window
//*************
int enterwindow(string str) {
  if (!str) { notify_fail("Where do you want to enter?\n"); return 0; }
  if ((str=="window" && dirty!="broken") 
    || (str=="dirty window" && dirty=="dirty")
    || (str=="clean window" && dirty=="clean")) {
    write("Haha nice joke - how do you want to enter a closed window?\n");
    show(NAME+" tries to enter a closed window, but fails.\n");
    return 1;
  }
  if (dirty=="broken" && (str=="broken window" || str=="window")) {
    write("You enter the broken window into the library.\n");
    TP->move(SYKORATH("library"),M_GO,"into the window");
    return 1;
  }
  notify_fail("Enter where?\n");
  return 0;
}

//************
// open window
//************
int openwindow(string str) {
  if (!str) { notify_fail("Open what?\n"); return 0; }
  if (dirty=="broken") {
    write(
    "The window is broken. You can't open it anylonger. A heap of glass\n"
    "is lying on the ground.\n");
    show(NAME+" tries to open the broken window - haha very funny.\n");
    return 1;
  }
  if (str=="window" || (str=="dirty window" && dirty=="dirty")
    || (str=="clean window" && dirty=="clean")) {
    write(
      "You open the "+str+". You are not very astonished, that there is\n"
      "a wall behind the window. The wall has an inscription on it.\n"
      "You try to read the inscription, but the window closes automatically.\n"
      "Maybe the window is protected by some strong magic?.\n");
    show(NAME+" opens the window.\n"
      "But the windows closes itself by a strong magic force.\n");
    return 1;
  }
  notify_fail("There is no "+str+" to open.\n");
  return 0;
}

//*************
// close window
//*************
int closewindow(string str) {
  notify_fail("Close what?\n");
  if (strstr(str,"window")== -1) return 0;
  write("There is no opened window here.\n");
  return 1;
}


//************
// create room
//************
create() {
  ::create();
  dirty="dirty";
  SetIntShort("A road");
  SetIntLong(
    "The road leads west in direction to the townwall and southeast to "
    "main plaza. The road is formed by walls of other houses. There is a "
    "@@QueryDirty@@ window to the north.\n"
  );

  SetIndoors(0);
  SetCoordinates( ({ ({560,560,0}), C_SYKORATH }));
  SetRegion(REGION_CITY);

  SetMap("inner");

  /* details */
  AddDetail(({"road"}),#'IntLong);
  AddVItem( ([
    P_IDS:  ({"walls","wall"}),
    P_ADS:  ({"north"}),
    P_LONG: #'lookwall ]) );
  AddVItem( ([
    P_IDS:  ({"house","houses"}),
    P_LONG: #'lookhouse ]) );
  AddVItem( ([
    P_IDS:  ({"window"}),
    P_LONG: #'lookwindow ]) );
  AddVItem( ([
    P_IDS:  ({"dirty window"}),
    P_LONG: #'lookdirtywindow ]) );
  AddVItem( ([
    P_IDS:  ({"clean window"}),
    P_LONG: #'lookcleanwindow ]) );
  AddVItem( ([
    P_IDS:  ({"broken window"}),
    P_LONG: #'looksmashwindow ]) );
  AddVItem( ([
    P_IDS:  ({"glass","heap","heap of glass"}),
    P_LONG: #'lookglass ]) );

  AddVItem( ([
    P_IDS:  ({"townwall"}),
    P_ADS:  ({"high"}),
    P_LONG: "It is a very old wall, built of big stones, made of "
            "granite. The townwall is a very high ones.\n" ]) );
  AddVItem( ([
    P_IDS:  ({"plaza"}),
    P_ADS:  ({"main"}),
    P_LONG: "The way southeast leads back to the main plaza. You can "
            "see much from here. The road blocks the sight.\n" ]) );

  /* commands */
  AddRoomCmd("open",#'openwindow);
  AddRoomCmd("close",#'closewindow);
  AddRoomCmd("smash",#'smashwindow1);
  AddRoomCmd("break",#'smashwindow2);
  AddRoomCmd("destroy",#'smashwindow3);
  AddRoomCmd("clean",#'cleanwindow);
  AddRoomCmd("enter",#'enterwindow);

  /* exits */
  AddExit("southeast","./mainplazanw");
  AddExit("west","./darkend");

  Set(P_INT_WIZMSG,
    "%^RED%^change exit west?, replace windows by vwindows, but vwindows "
    "cannot do so much :(?!%^RESET%^\n"
    "then remove this message :)\n"
  );
}

//**************************
// make a nice special reset
//**************************
reset() {
  ::reset();
  switch (dirty) {
    case "dirty": return;
    case "broken":
      tell_room(TO,
      "An old dwarf comes along and sees the broken window.\n"
      "He says: Oh I have to repair this!\n"
      "And he uses some items and repairs the window.\n"
      "The dwarf says: So - I'm ready - okay - bye bye.\n"
      "And the dwarf runs to southeast, but forgot to clean the window.\n");
      break;
    case "clean":
      tell_room(TO,
      "An old dwarf comes along and sees the clean window.\n"
      "He says: Oh what a nice window!\n"
      "And he touches the clean window with his dirty hands.\n"
      "The dwarf says: bye bye.\n"
      "And the dwarf runs to the southeast.\n");
      break;
  }
  dirty="dirty";
}


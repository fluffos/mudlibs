// part of the town
// made by magictcs - 3 jul 97
// TODO: update coords

#include <properties.h>
#include <moving.h>
#include <npc.h>
#include <nightday.h>
#include <regions.h>
#include <coordinates.h>
#include <sykorath.h>

inherit BASEROOM;

//***********
// climb tree
//***********
int climbtree(string str) {
  notify_fail("Climb where?\n");
  if (!str) return 0;
  if (member(({"huge tree","tree","oak","huge oak"}),str)!=-1) {
    write("You can't climb the oak. There are no low branches left.\n");
    show(NAME+" tries to climb the tree, but fails.\n");
    return 1;
  }
  return 0;
}

//******
// relax
//******
int relax(string str) {
  notify_fail("Use: relax\n");
  if (str) return 0;
  if (!(TP->Query("SITDOWN"))) {
    write("First sit down!\n");
    return 1;
  }
  write("You relax while sitting near the oak.\n");
  show(NAME+" relaxes near the tree.\n");
  return 1;
}

//*********
// sit down
//*********
int sitdown(string str) {
  notify_fail("Sit where?\n");
  if (!str) return 0;
  if (member(({"down","down in the shadow","down in the shadows",}),str)!=-1) {
    write("You sit down near the tree.\n");
    show(NAME+" sits down.\n");
    TP->Set("SITDOWN",1);
    return 1;
  }
  return 0;
}

//*********
// stand up
//*********
int stand(string str) {
  notify_fail("Stand up?\n");
  if (!str) return 0;
  if (str=="up") {
    write("You stand up.\n");
    show(NAME+" stands up.\n");
    TP->Set("SITDOWN",0);
    return 1;
  }
  return 0;
}

//*********************
// special quit command
//*********************
// returns ever with 0 --> call the real quit command!
int quit(string str) {
  if (str) return 0;
  TP->Set("SITDOWN",0);
  return 0;
}

//*******
// create
//*******
create() {
  ::create();
  SetIntShort("The east-west road");
  SetIntLong(
    "You are on the east-west road. A huge oak stands here.\n"
    "The way east leads into the inner city.\n");
  SetIndoors(0);
  SetCoordinates( ({ ({0,0,0}), C_SYKORATH }));
  Set(P_REGION,REGION_CITY);

  /* details */
  AddDetail(({"road","east west road","east-west road"}),#'IntLong);
  AddDetail(({"city"}),
    "Yeah you are standing in it.\n");
  AddDetail(({"inner city"}),
    "The inner city can be seen to the east.\n");
  AddDetail(({"east","way east","east way"}),
    "The way to the east leads into the inner city.\n");
  AddDetail(({"huge tree","tree","oak","huge oak"}),
    "It is the oak of your dreams. You can sit down and relax in the shadow\n"
    "of the tree (if the sun is shining).\n");
  AddDetail(({"shadow","shadow of tree","shadow of the tree"}),
    "You can see a shadow, but only if the sun is shining.\n");

  /* commands */
  AddRoomCmd("sit","sitdown");
  AddRoomCmd("stand","stand");
  AddRoomCmd("relax","relax");
  AddRoomCmd("climb","climbtree");
  AddRoomCmd("quit","quit");          // special command

  /* exits */
  AddExit("west","./roadw2");
  AddExit("east","./beforegate");
  AddExit("northeast","./oakstreetn1");
  AddExit("southwest","./oakstreets1");
}

// forbid leaving of player which are sit in the shadow
int prevent_leave(object dest,int method,mixed extra) {
  if (!TP->Query("SITDOWN")) return 0;    // allowed
  write("First stand up!\n");
  return ME_NO_LEAVE;
}


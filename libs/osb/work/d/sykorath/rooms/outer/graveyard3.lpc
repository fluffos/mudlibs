/*
 * part of the graveyard of the outer city
 *
 * introduced:
 * Magictcs 02 jul 97 - first version
 *
 * updated:
 * Magictcs - 17 feb 98 - remade, added skills
 */

// TODO: details: tombstone(s), dig|open|close grave(s)
// TODO: allow pulling out the stone -> object brick
// TODO: if object brick available --> allow lifting back to wall

#include <properties.h>
#include <moving.h>
#include <npc.h>
#include <regions.h>
#include <coordinates.h>
#include <skills.h>
#include <combat.h>                        // define for WHIPs
#include <sykorath.h>

inherit BASEROOM;

int whip;

//*****
// pull
//*****
int pull(string str) {
  object obj;
  notify_fail("Pull what out of where?\n");
  if (!str) return 0;
  if (sizeof(regexplode(norm_id(str),
    "^(the|a|an|some|special|[ ])*brick out of (the|a|an|some|[ ])*"
    "(rotten|small|[ ])*(wall)$"))==3) {
    write("You pull the brick out of the wall.\n");
    show(NAME+" works with the wall.\n");
    if (whip) {
      write("Behind the brick you find a long whip.\n");
      obj=clone_object(W_WHIPS("lwhip"));
      TP->Take(obj,PUTGET_FULL);
      write("You put the brick back into the wall.\n");
      whip--;
    } else {
      write("But you found nothing behind the brick. You put it back into "
        "the wall.\n");
    }
    return 1;
  }
  notify_fail("Pull brick out of where?\n");
  return 0;
}

//*******
// create
//*******
create() {
  string v_wall,v_brick1,v_brick2;
  ::create();
  whip=1;
  SetIntShort("On a graveyard");
  SetIntLong(
    "You are standing on an old graveyard. To the east is a small chapel "
    "and the entrance is to the west. The graveyard is surrounded by "
    "a small wall.\n");
  SetIndoors(0);
  SetCoordinates( ({ ({780,640,0}), C_SYKORATH }));
  SetRegion(REGION_CITY);
  AddNowayMsg(({"northeast","southeast"}),
    "You bump against the small wall.\n");

  /* details */
  AddVItem( ([
    P_IDS:  ({"graveyard","yard"}),
    P_ADS:  ({"old"}),
    P_LONG: #'IntLong ]) );
  v_wall = AddVItem( ([
    P_IDS:  ({"wall"}),
    P_ADS:  ({"rotten","small"}),
    P_PREPS:({"of","in"}),
    P_LONG: "The wall is nearly rotten, but still around one metres "
            "huge. There is a special brick in this wall.\n" ]) );
  v_brick1 = AddVItem( ([
    P_IDS:  ({"brick"}),
    P_ADS:  ({"special"}),
    P_LONG: "Maybe you can pull it out?\n" ]) );
  v_brick2 = AddVItem( ([
    P_IDS:  ({"brick"}),
    P_ADS:  ({"special"}),
    P_LONG: "Maybe you can pull it out?\n" ]), v_wall);
  AddVItem( ([
    P_IDS:  ({"exit"}),
    P_LONG: "You can leave the graveyard by going west.\n" ]) );
  AddVItem( ([
    P_IDS:  ({"grave","graves"}),
    P_LONG: "This is the place where the founders of the city are buried. "
            "Let they rest in peace!\n" ]) );

  /* commands */
  AddSkill(SK_SEARCH,"wall",20,v_wall);
  AddSkill(SK_SEARCH,"brick",20,v_brick1);
  AddSkill(SK_SEARCH,"brick2",20,v_brick2);
  AddRoomCmd("pull",#'pull);

  /* exits */
  AddExit("north",    "./graveyard5");
  AddExit("west",     "./graveyard1");
  AddExit("northwest","./graveyard2");
  AddExit("east",     "./gravechapel");
  AddExit("south",    "./graveyard6");
  AddExit("southwest","./graveyard4");

  Set(P_INT_WIZMSG,
    "%^RED%^add more to the brick, add details!%^RESET%^\n"
    "then remove this message :)\n"
  );
}

// special reset
reset() {
  ::reset();
  whip=1;
}


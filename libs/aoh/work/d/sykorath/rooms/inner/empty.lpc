/*
 * an empty room - made by Magictcs - 11 jun 97
 * nothing is here (only fun)
 *
 * last changes:
 * [m] 08 jan 97 - remade
 */

#include <properties.h>
#include <npc.h>
#include <regions.h>
#include <coordinates.h>
#include <sykorath.h>
#include <skills.h>

int amulet;

inherit SY_STREET;

//******************
// property handling
//******************
int QueryMedallion() { return amulet; }
int SetMedallion(int set) { amulet=set; return amulet; }

// clone a medallion and move it into the player
// belongs to 'search' and 'get' function
object clone_medallion() {
  object obj;
  obj=clone_object("/std/armour");
  obj->SetStandard(AT_AMULET,0,PSIZE_NORMAL);
  obj->SetProperties( ([
    P_SHORT: "a small medallion",
    P_LONG:
    "A small medallion, a perfect work.\n",
    P_IDS: ({"medallion","work"}),
    P_ADS: ({"small","perfect"}),
    P_WEIGHT: 4000,
    P_VALUE: 800 ]) );
  return obj;
}

void move_medallion(object pl) {
  object ob;
  amulet--;
  ob=clone_medallion();
  pl->Take(ob,PUTGET_FULL);
  pl->SetExplored();             // give one explorer point for it
}

//***************
// search command
//***************
int OnSucceedSearchingSomething() {
  if (amulet) {
    write("You search something and find a small mdeallion.\n");
    show(NAME+" searches something.\n");
    move_medallion(TP);
    return 1;
  } else {
    write("You search and search - but do you think you can find "
          "something here in this empty room?\n");
    show(NAME+" searches the room.\n");
    return 1;
  }
}

int OnFailSearchingSomething() {
  write("You search something, but this room is really empty.\n");
  return 1;
}

// search ruin (and the others is handled automatically by the skill
// server - thanx Softbyte :)
// we haven't to do anything

//****************
// detail handling
//****************
string lookspecial() {
  return
  "You see nothing special (because the room is empty).\n";
}

//*******
// create
//*******
create() {
  string v_id;
  ::create();
  amulet=1;
  SetIntShort("An empty room");
  SetIntLong(
    "Uh what for a strange place - the wizard who built this room on the "
    "ruins of an old house, forgot something as he waved his wand? "
    "This is a real empty room, nothing special here!\n"); 

  SetIndoors(0);
  SetCoordinates( ({ ({560,660,0}), C_SYKORATH }));
  SetRegion(REGION_CITY);

  SetMap("inner");

  /* details */
  AddVItem( ([
    P_IDS:  ({"place","room"}),
    P_ADS:  ({"strange","empty"}),
    P_LONG: #'IntLong ]) );

  v_id=AddVItem( ([
    P_IDS:  ({"house"}),
    P_ADS:  ({"old"}),
    P_NOGET:"There is no house here.\n",
    P_LONG: "There is no house here anymore. It is vanished as the "
            "wizard waved his wand. But he made a mistake. Nothing "
            "is here yet. The place is really empty!\n",
    P_PREPS:({"of"}) ]) );

  // look ruin(s) of (old) house
  AddVItem( ([
    P_IDS:  ({"ruins","ruin"}),
    P_NOGET:"Getting ruins? A bit stupid?\n",
    P_LONG: "Hey are you soo stupid? This place is empty - the ruins "
            "are gone! You can't see them anymore here\n" ]) , v_id );
  // look ruin(s)
  AddVItem( ([
    P_IDS:  ({"ruins","ruin"}),
    P_NOGET:"Getting ruins? A bit stupid?\n",
    P_LONG: "Hey are you soo stupid? This place is empty - the ruins "
            "are gone!\n" ]) );

  AddDetail("something",
    "Yes the great wizard forgot something here.\n");
  AddVItem( ([
    P_IDS:  ({"nothing","nothing special"}),
    P_LONG: #'lookspecial ]) );
  AddDetail("mistake",
    "Yes one wizard made a mistake here - or can you see anything here?\n");
  AddDetail("anything",
    "No anything is here. This is a real empty room.\n");
  AddVItem( ([
    P_IDS:  ({"wizards"}),
    P_ADS:  ({"great"}),
    P_LONG: "No wizards are here.\n" ]) );
  AddVItem( ([
    P_IDS:  ({"wizard"}),
    P_ADS:  ({"great"}),
    P_LONG: "The one who made the mistake is not here. He is gone to "
            "another location to try his luck there.\n" ]) );
  AddVItem( ([
    P_IDS:  ({"wand"}),
    P_NOGET:"There is no wand here!\n",
    P_LONG: "Do you believe that a wizard lost his wand here? Haha very "
            "funny.\n" ]) );
  AddVItem( ([
    P_IDS:  ({"medallion"}),
    P_ADS:  ({"small"}),
    P_LONG: "There is no medallion here.\n" ]) );

  /* commands */
  AddSkill(SK_SEARCH,"something",10,({"something","for something"}));
  AddSkill(SK_SEARCH,"ruin",250,({"place","strange place","room",
    "empty room","ruins","ruin","ruins of house","ruins of old house",
    "old house","house","nothing","nothing special"}));

  /* exits */
  AddExit("northwest","./oguild");

  Set(P_INT_WIZMSG,
    "%^RED%^change the explorerfile!!!, check the coords, "
    "add details!%^RESET%^\n"
    "then remove this message :)\n"
  );
}

//**************
// special reset
//**************
reset() {
  ::reset();
  amulet=1;
}

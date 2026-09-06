// This is the entrance to the northern defense tower of the harbour
// created:          Sonic [26-May-1997]
// last changed:     Sonic [05-Jul-1997] added regions/coordinates
//                   Tune  [25-Jan-1998] descriptions, details

#include <silvere.h>
#include <specialrooms.h>
#include <properties.h>
#include <coordinates.h>
#include <msgclass.h>
#include <regions.h>
#include <moving.h>
#include <macros.h>
#include <rooms.h>
#include <nightday.h>

inherit HARBOUR_BASEROOM;

string CheckChains()
{
   string desc;
   int north, south;

   north = ({int})SIL_NORTH_MACHINEROOM->QueryChain() || 0;
   south = ({int})SIL_SOUTH_MACHINEROOM->QueryChain() || 0;

   if( (north == 1) && (south == 1) )
      desc =
         "A large and heavy chain hangs stretched between the two towers "
         "which guard the north and south sides of the harbour bay. The "
         "chain, suspended above the choppy waters of the bay by several "
         "feet, will stop any ship which might foolishly attempt to enter "
         "the harbour without permission, and quite possibly damage its "
         "hull beyond repair. ";
   else
   {
      if( north == 1 )
         desc =
            "A large and heavy chain hangs down from the northern "
            "tower, vanishing some way between the towers into the "
            "murky depths of the bay water. ";
      else desc =
            "A large and heavy chain hangs down from the northern "
            "tower and vanishes into the water nearly at the wall of "
            "that building. ";
      if( south == 1 )
         desc +=
            "The other end of the chain is hanging down from the "
            "southern tower. It vanishes into the water some way "
            "between the two buildings.";
      else desc +=
            "The other end of the chain is hanging down from the "
            "southern tower. It vanishes immediately in the water "
            "of the harbour.";
   }
   return desc;
}

// Tune 18jan98: what is desc for? isn't used in CheckGuards()
//               changed guards to nr_of_guards (makes it more clear)

int CheckGuards()
{
   object guard;
   int nr_of_guards;

   nr_of_guards = 0;

   for( guard=first_inventory(); guard; guard = next_inventory(guard) )
      if(({int})guard->id("guard")) nr_of_guards++;

   return nr_of_guards;
}

string CheckWalls()
{
   string desc;
   int guards;

   desc=
      "The wall of the tower rises high into the sky before your "
      "eyes. On top of it you can faintly make out battlements. ";

   if( !({int})NIGHTDAY->IsDay() )
      desc += "Flaming, smoking torches burn brightly atop the "
              "tower, bright beacons to guide the ships "
              "home through the black of night.\n";

   guards = CheckGuards();

   if(guards)
   {
      if( guards > 1 )   desc +=
         CAP(itoa(guards))+" guards are standing here, watching the "
         "entrance into the tower.\n";
      else desc+=
         "A single guard stands watch at the entrance "
         "to the tower.\n";
   }
   else desc+="The gate leading into the tower is not guarded.\n";

   return desc;
}

string CheckEntrance()
{
   string desc;
   int guards;

   desc="The entrance leads into the tower. ";
   guards=CheckGuards();

   if(guards)
   {
      if(guards>1) desc+=
         CAP(itoa(guards))+" guards are standing here, watching the "
         "entrance into the tower.\n";
      else desc+="A guard is standing here, watching the entrance "
         "into the tower.\n";
   }
   else desc+="The entrance into the tower is not guarded.\n";
   return desc;
}

int move_tower()
{
   if(CheckGuards())
   {
      msg_write(CMSG_GENERIC,
         "A guard blocks the way into the tower, demanding to see a "
         "pass giving you leave to enter.\n");
      msg_say(CMSG_ROOM,
         "A guard asks "+CAP(NAME(TP))+" for "+HISHER(TP)+" permission "
         "to enter the tower.\n", ({TP}) );
      if(present("tower_permit",TP))
      {
         msg_write(CMSG_GENERIC,
            "The guard examines the pass you wave before him, and "
            "replies: Thou are granted leave to enter the tower.\n");
         msg_say(CMSG_ROOM,
            "The guard examines the pass "+CAP(NAME(TP))+" carries, "
            "replying: Thou are granted leave to enter the tower.\n",
            ({ TP }) );
         TP->move(SIL_HARBOUR("ntower1"),M_GO);
         return 1;
      }
      msg_room(TO,CMSG_ROOM,
         "The guard says: Thou hath no permission to enter the tower, "+
         CAP(NAME(TP))+".\n");
      return 1;
   }
   TP->move(SIL_HARBOUR("ntower1"),M_GO);
   return 1;
}

string lookAtTower()
{
   string desc;

   desc =  "The tower walls rise, sleek and stony, straight into the sky. "
           "On the southern wall is an opening in the tower wall, "
           "framed in timber, through which the harbour chain can be reeled "
           "in for protection or dropped to let ships pass into the bay. "
           "High above are the battlements, where ";

   if( ({int})NIGHTDAY->IsDay() )
      desc +=  "a fine white banner flutters in the sea breeze, "
              "proudly displaying the sigil of the Royal House of "
              "Silvere.\n";
   else
      desc +=  "smoky fires burn brightly, to guide the ships "
              "home into the safety of the bay.\n";

   return desc;
}

int enter_tower(string str)
{
   notify_fail("Enter what?\n",NOTIFY_ILL_ARG);
   if(!str) return 0;
   if(strstr(lower_case(str),"tower")!=-1 ||
      strstr(lower_case(str),"west")!=-1)
   {
      return move_tower();
   }
   return 0;
}

varargs void create()
{
   ::create();
   Set(P_INDOORS,0);
   Set(P_INT_SHORT,"Before a high tower");
   Set(P_INT_LONG,
      "The easterly side of the quay ends abruptly before a square, stone "
      "tower, crowned with battlements high above. Set into the thick "
      "eastern wall of the tower is an entrance leading into a gloomy "
      "interior. A second tower on the southern quay mirrors this one.\n");

      //"A high tower is standing here. An entrance leads west into the "
      //"tower. Quays are leading away to the east. At the western end of "
      //"the southern quay is another tower, that looks exactly like the "
      //"one here.\n");

   Set(P_INT_WIZMSG,
"The harbourmaster will have the permits for the guards (not done yet).\n"
" East: City-Gates, Harbourmaster, Inn, quays\n"
" West: Into the tower\n");

   AddDetail(  ({ "chain", "chains" }), #'CheckChains /*'*/);

   AddDetail( ({ "tower","high tower","towers","defense towers",
                 "defense tower"}),
      "Which tower do you mean? Directly before you stands the "
      "northern tower. The southern tower stands on the far end of "
      "the southern quay.\n");

   AddDetail( ({"south tower","southern tower"}),
      "The harbour of Silvere is bowl shaped, with an opening to the "
      "sea at the west side. To the north and south of the entrance to "
      "the bay stand two guard towers, one on each side. "
      "The southern tower can be found on the far end of the quay on the "
      "southern side of the harbour.\n");

   AddDetail( ({"north tower","northern tower"}), #'lookAtTower /*'*/);

   AddDetail( ({"wall","walls","towerwall","towerwalls"}),#'CheckWalls /*'*/);

   AddVItem(
      ([ P_IDS: ({ "stone", "stones", "chunks" }),
         P_ADS: ({ "large", "grey", "tower" }),
         P_LONG: ({
           "The stones of the tower walls are simple and grey, revealing "
           "nothing unusual even under close scrutiny. The blocks are "
           "large and square. After they were set they were carefully "
           "smoothed, so that not a crevice or crack remains. Even the "
           "most experienced climber could not scale this wall without "
           "the help of special tools.\n",

           "Close scrutiny reveals not even the smallest spot of lichen or "
           "moss growing on the tower stones, not a crack, not a gap, "
           "nothing which could allow access to the heights.\n"
         })
      ]) );

   AddDetail( ({"tool","tools"}),
      "Guards are not renowned for being brilliant thinkers, but not even "
      "they would be stupid enough to carelessly leave climbing tools "
      "lying about.\n");


   AddDetail( ({"entrance","towerentrance","tower-entrance", "tower entrance"}),#'CheckEntrance /*'*/);

   AddDetail( "opening",
      "A square opening in the southern side of the guard tower is "
      "just visible from the quay. A heavy chain passes through the "
      "opening and disappears beneath the surface of the water. "
      "An identical opening in the southern tower mirrors this one.\n");

   AddDetail( ({"south quay","southern quay","other quay"}),
      "The southern quay is, as it's name already mentioned, to the "
      "south. If you walk to the east and continue at the crossing "
      "to the south, you will find it.\n");

   AddDetail( ({"north quay","northern quay"}),
      "That's where you are standing at the moment.\n");

   Set(P_INT_MAP,"harbour");
   Set(P_REGION, REGION_CITY|REGION_HARBOUR);
   Set(P_COORDINATES, ({ ({ -270,0,0 }), C_SILVERE }) );

   AddRoomCmd("enter",#'enter_tower /*'*/);

   Set(P_NOWAY_MSG,
     "As you try to go there you nearly slip from the quay into "
     "the murky water of the harbour. Now, that's not the best "
     "thing you could do...\n");

   AddExit("west", #'move_tower /*'*/);
   AddExit("east", SIL_HARBOUR("quay1_3"));

   AddItem(NPC("towerguard"),REFRESH_REMOVE,2,
   ([ P_QUESTIONS:
      ([ "permission":
            "The guard says:\n"
            "Thou need a permission to enter the tower. If ye have "
            "business here, go to the harbourmaster and ask him about "
            "a permission for ye.\n",
         "harbourmaster":
            "The guard says:\n"
            "Thou may find the harbourmaster in his office near the "
            "walls of our city.\n",
         "office":
            "The guard points at the city and says:\n"
            "Just follow the road to the city and thou will find it.\n",
         "city":
            "The guard says:\n"
            "The city of Silvere is our home. Thou are welcome there, "
            "as long as ye follow the law. Thou may visit the council "
            "hall if ye are curious.\n",
         "silvere":
            "The guard says:\n"
            "The city of Silvere is our home. Thou are welcome there, "
            "as long as ye follow the law. Thou may visit the council "
            "hall if ye are curious.\n",
         "council hall":
           "The guard says:\n"
           "Thou may find the council hall in the western part of our "
           "proud city. It's very easy to find, if ye look where ye "
           "are walking.\n",
         "council":
            "The guard says:\n"
            "The council is placed in the council hall. Some wise "
            "citizens of the city are talking about business and "
            "politics. Of course most of the politicial dealings "
            "are done by the Lu'meyn, but day to day business is "
            "done by the council. That's nothing the Lu'meyn has "
            "to be bothered with as long as it's not important "
            "enough.\n",
         "lu'meyn":
            "The guard says:\n"
            "The Lu'meyn and his wife, the Lu'meyna are the rulers "
            "of our city. They live in the palace in the center of "
            "Silvere.\n",
         "lu'meyna":
            "The guard smiles and says:\n"
            "The Lu'meyna is a beautiful woman. She rules the city "
            "of Silvere together with her husband, the Lu'meyn. She "
            "is a very good person and all of us would die for her, "
            "if that is necessary.\n",
         "palace":
            "The guard says:\n"
            "The Palace? Sure I can tell you where to find it. Just "
            "go to the city of Silvere and follow the road to the "
            "east. Thou can't miss it then.\n",
      ]),
      P_SHRUG_MSG:
         "The guard says:\n"
         "I know nothing about that. Thou may ask someone else.\n",
   ]) );
}

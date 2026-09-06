// inside the northern tower. You will find a machine here, to raise the
// chain between the two towers.
// created:          Sonic [26-May-1997]
// last changed:     Sonic [05-Jul-1997] added regions/coordinates
//                   Sonic [27-Jul-1997] added description/details

#include <silvere.h>
#include <properties.h>
#include <coordinates.h>
#include <msgclass.h>
#include <regions.h>
#include <moving.h>
#include <macros.h>
#include <nightday.h>
#include <rooms.h>
#include <combat.h>
inherit BASEROOM;

int rMachine, rHandle, rChain;

int QueryChain()     { return rChain; }
int QueryMachine()   { return rMachine; }
int QueryHandle()    { return rHandle; }

int SetChain(int nr)
{
   if(!nr) nr=0;
   rChain=nr;
   return rChain;
}

int SetMachine(int nr)
{
   if(!nr) nr=0;
   rMachine=nr;
   return rMachine;
}

int SetHandle(int nr)
{
   if(!nr) nr=0;
   rHandle=nr;
   return rHandle;
}

int MoveChain3()
{
   object *items;

   /* make sure, that all guards except those
    * with enemies are removed
    */
   if(items=all_inventory(TO))
   {
      int a;

      for(a=0; a<sizeof(items); a++)
      {
         object guard;

         guard=items[a];
         if(({int})guard->id("tguard"))
         {
            int b;
            mixed *inv;

            if(sizeof(({object *})guard->Query(P_ENEMIES))==0)
            {
               inv=all_inventory(guard);
               for(b=0; b<sizeof(inv); b++)
                  inv[b]->remove();
               guard->remove();
            }
            else msg_room(TO,CMSG_ROOM,
               CAP(NAME(guard))+" refuses to leave, as "+HISHER(guard)+
               "is fighting at the moment.\n");
         }
      }
   }
   msg_room(TO,CMSG_ROOM,
      "The commanding officer orders the soldiers to stop and then "
      "leads them out of the room. Without the people to move the "
      "machine, the wheel stops.\n");
   SetMachine(0);
   if(rHandle==1) SetChain(1);
   else SetChain(0);
   return 1;
}

int MoveChain2()
{
   if(rHandle==1)
      msg_room(TO,CMSG_ROOM,
         "The wooden wheel starts to turn and the chain moves down from "
         "it through the machine into the opening. From the outside you "
         "hear water splashing.\n\n");
   else
      msg_room(TO,CMSG_ROOM,
         "The wooden wheel starts to turn and the chain moves from the "
         "opening in the wall through the machine on the wheel. From "
         "outside you hear the water splashing.\n\n");
   call_out("MoveChain3",8);
   return 1;
}

int MoveChain()
{
   object npc;
   int a;

   for(a=0; a<4; a++)
   {
      npc=clone_object(NPC("silvere/towerguard"));
      if(npc) npc->move(TO,M_GO);
   }
   npc=clone_object(NPC("silvere/towerlieutnant"));
   if(npc) npc->move(TO,M_GO);
   msg_room(TO,CMSG_ROOM,
      "The soldiers take the rope. Then the lieutnant commands them to "
      "pull the rope. There is some movement from inside the machine, "
      "as the soldiers start to work.\n\n");
   SetMachine(1);
   call_out("MoveChain2",6);
   return 1;
}

int PushCommand(string str)
{
   notify_fail("Push what?\n",NOTIFY_ILL_ARG);
   if(!str) return 0;
   if(strstr(lower_case(str),"rope")!=-1)
   {
      msg_write(CMSG_GENERIC,"You push the rope, but nothing happens.\n");
      msg_room(TO,CMSG_ROOM,CAP(NAME(TP))+" pushes the rope, but "
         "nothing happens.\n", ({TP}) );
      return 1;
   }
   if(strstr(lower_case(str),"handle")!=-1)
   {
      if(rMachine==1)
      {
         msg_write(CMSG_GENERIC,
            "The machine is already running.  Wait until it is "
            "finished and try again.\n");
         return 1;
      }
      if(rHandle==0)
      {
         msg_write(CMSG_GENERIC,"The handle is already raised.\n");
         return 1;
      }
      msg_say(CMSG_ROOM,CAP(NAME(TP))+" pushes the handle.\n");
      msg_write(CMSG_GENERIC,
         "You push the handle. It moves smoothly to the higher position. "
         "On the plaque it points now to 'Raise'.\n");
      msg_say(CMSG_GENERIC,
         "A bell rings inside the machine. You hear feet moving "
         "from above.\n\n");
      SetHandle(0);
      call_out("MoveChain",2);
      return 1;
   }
}

int PullCommand(string str)
{
   notify_fail("Pull what?\n",NOTIFY_ILL_ARG);
   if(!str) return 0;
   if(strstr(lower_case(str),"rope")!=-1)
   {
      msg_write(CMSG_GENERIC,
         "You pull at the rope, but it doesn't move.\n");
      msg_room(TO,CMSG_ROOM,CAP(NAME(TP))+" pulls at the rope "
         "but nothing happens. In fact, the rope doesn't even "
         "move.\n", ({TP}) );
      return 1;
   }
   if(strstr(lower_case(str),"handle")!=-1)
   {
      if(rMachine==1)
      {
         msg_write(CMSG_GENERIC,
            "The machine is already running.  Wait until it is "
            "finished and try again.\n");
         return 1;
      }
      if(rHandle==1)
      {
         msg_write(CMSG_GENERIC,"The handle is already lowered.\n");
         return 1;
      }
      msg_say(CMSG_ROOM,CAP(NAME(TP))+" pulls the handle.\n");
      msg_write(CMSG_GENERIC,
         "You pull the handle. It moves smoothly to the lower position. "
         "On the plaque it points now to 'Lower'.\n");
      msg_say(CMSG_GENERIC,
         "A bell rings inside the machine. You hear feet moving "
         "from above.\n\n");
      SetHandle(1);
      call_out("MoveChain",2);
      return 1;
   }
}

string CheckHandle()
{
   string desc;

   desc=
      "The handle is made out of wood and comes out of the machine. "
      "There is also a small plaque next to it. ";
   if(rHandle==0)
      desc+=
         "The handle is on 'Raise' position. How about pulling "
         "the handle?\n";
   else desc+=
         "The handle is on 'Lower' position. How about pushing "
         "the handle?\n";
   return desc;
}

string CheckHandleNoise()
{
   if(rMachine==1) return
      "The machine is working and there is a metal clank from the chain "
      "as it is moved.\n";
   else return
      "You can't hear any noise from the machine.\n";
}

string CheckOpening()
{
   string desc;

   desc=
      "The opening is right here in the southern wall. A large chain "
      "is running through it. ";
   switch(({int})NIGHTDAY->QueryState())
   {
      case ND_NIGHT:
         desc+=
            "Outside of the opening it's dark. Maybe it is night?\n";
         break;
      case ND_PREDAWN..ND_SUNRISE:
      case ND_TWILIGHT..ND_EVENING:
         desc+=
            "Outside of the opening is some light. It shines "
            "through it and gives more light to parts of the "
            "room. You can also barely make out the southern "
            "tower and the murky water of the harbour.\n";
         break;
      case ND_EARLY_MORNING..ND_SUNSET:
         desc+=
            "It's bright outside of the tower and the sun sends some "
            "light through the opening into the room. Outside you "
            "can see the southern tower and the murky water of the "
            "harbour. On the southern quay are people doing their "
            "work. It looks like a very busy place.\n";
         break;
      default:
         desc+=
            "There is something to the outside of the room, but "
            "you can't clearly define it.\n";
         break;
   }
   return desc;
}

string CheckQuay()
{
   string desc;

   desc="The southern quay is on the other side of the harbour. ";
   switch(({int})NIGHTDAY->QueryState())
   {
      case ND_NIGHT:
         desc+=
            "It is too dark to see anything there. The only light "
            "is coming from the opening in the southern tower.\n";
         break;
      case ND_PREDAWN..ND_SUNRISE:
      case ND_TWILIGHT..ND_EVENING:
         desc+=
            "You can barely make out some few workers, who are "
            "walking around on the quay.\n";
         break;
      case ND_EARLY_MORNING..ND_SUNSET:
         desc+=
            "Lots of workers are walking around on the southern "
            "quay, doing their work.\n";
         break;
      default:
         desc+=
            "There is something to the outside of the room, but "
            "you can't clearly define it.\n";
         break;
   }
   return desc;
}

string CheckWorkers()
{
   string desc;

   switch(({int})NIGHTDAY->QueryState())
   {
      case ND_NIGHT:
         desc=
            "It is too dark to see something on the south quay. But as "
            "it is night and there is nothing to be seen, it is highly "
            "possible, that there are no workers at the moment.\n";
         break;
      case ND_PREDAWN..ND_SUNRISE:
      case ND_TWILIGHT..ND_EVENING:
         desc=
            "You can barely make out some few workers, who are "
            "walking around on the quay. From that distance, you "
            "can't see anything else, so if you want to know more "
            "about them, go over there and look again.\n";
         break;
      case ND_EARLY_MORNING..ND_SUNSET:
         desc=
            "Lots of workers are walking around on the southern "
            "quay, doing their work. But from that distance, you "
            "can't see any details, except that they are human (or "
            "look like them). If you want to know more, just walk "
            "over there and have a look.\n";
         break;
      default:
         desc=
            "There is something on the quay but you can't clearly "
            "define it.\n";
         break;
   }
   return desc;
}

string CheckSouthTower()
{
   string desc;

   desc="Through the opening you can see the south tower. ";
   switch(({int})NIGHTDAY->QueryState())
   {
      case ND_NIGHT:
         desc+=
            "At least you can see the opening there, as the room "
            "is lighted. On top of the tower is also some light, "
            "that shines into the darkness of the ocean to guard "
            "incoming ships and see them coming.\n";
         break;
      case ND_PREDAWN..ND_SUNRISE:
      case ND_TWILIGHT..ND_EVENING:
         desc+=
            "Through the dim light outside you can see at least some "
            "dark shadow, which could be the tower. Some light comes "
            "from an opening just some way above the waterline. On top "
            "of the tower is also some light, that shines out on the "
            "ocean to guard ships and see them coming.\n";
         break;
      case ND_EARLY_MORNING..ND_SUNSET:
         desc+=
            "It looks very strong. The walls are made out of some "
            "grey stone. Just a little above the waterline is an "
            "opening in the towerwall, where you can see a chain "
            "coming out. On top of the tower are some battlements, "
            "where some soldiers are standing, looking out on the "
            "ocean.\n";
         break;
      default:
         desc+=
            "Unfortunately, the fog outside is too thick. It blocks "
            "your view to the southern tower.\n";
         break;
   }
   return desc;
}

string CheckBattlements()
{
   string desc;

   desc="Through the opening you look at the south tower ";
   switch(({int})NIGHTDAY->QueryState())
   {
      case ND_NIGHT:
         desc+=
            "but it is too dark to see much of them. There is a big "
            "light on top of the south tower, which shows you the "
            "outline of the battlements, but that is all.\n";
         break;
      case ND_PREDAWN..ND_SUNRISE:
      case ND_TWILIGHT..ND_EVENING:
         desc+=
            "and see the outline of the battlements on top of it. "
            "There is a big fire on top of the tower, but except of "
            "that you can't see any details.\n";
         break;
      case ND_EARLY_MORNING..ND_SUNSET:
         desc+=
            "and see the battlements on top of it. They are made "
            "from the same stone as the rest of the tower and every "
            "now and then there is a soldier walking around, looking "
            "out on the ocean.\n";
         break;
      default:
         desc+=
            "but the fog outside is too thick to see anything.\n";
         break;
   }
   return desc+
      "If you want to see more of them, just go to the south "
      "tower and have a look or wait for the sun to shine down, "
      "so that you have enough light to see them.\n";
}

void reset()
{
   ::reset();
   if(rHandle!=1)
   {
      SetHandle(1);
      msg_room(TO,CMSG_ROOM,
         "Suddenly the handle moves to position 'Lower', but "
         "except of that, nothing happens.\n");
   }
   SetMachine(0);
   SetChain(0);
}

varargs void create()
{
   ::create();
   Set(P_INDOORS,1);
   Set(P_INT_SHORT,"Tower basement, western end");
   Set(P_INT_LONG,
      "This is the western end of the room. To the north is a big "
      "wheel, where the chain is stored. At the western wall is a "
      "big machine and to the south is an opening, where the chain "
      "runs through.\n");

   Set(P_INT_WIZMSG,
      " East:  the exit of the tower\n"
      " North: the storeroom of the chains.\n");

   AddDetail( "opening",SF(CheckOpening));

   AddDetail( ({"quay","southern quay"}),SF(CheckQuay));

   AddDetail( ({"people","workers"}),SF(CheckWorkers));

   AddDetail( ({"tower","defense tower"}),
      "Which tower do you mean? You are standing in the basement of the "
      "northern tower. Through the opening you can also have a look at "
      "the southern tower.\n");

   AddDetail( ({"north tower","north defense tower",
                "basement","room","level"}),
      "That's the place you are standing at the moment. Just have a look "
      "if you want to know more about it.\n");

   AddDetail( ({"south tower","south defense tower"}),SF(CheckSouthTower));

   AddDetail( ({"battlement","battlements"}),SF(CheckBattlements));

   AddDetail( ({"towerwall","towerwalls"}),
      "If you want to have a closer look on the walls of the south "
      "tower, just go there and have a look.\n");

   AddVItem(
   ([ P_IDS:({"stone","stones"}),
      P_ADS:({"grey"}),
      P_LONG:
         "The stones are grey and there is nothing unusual about them. "
         "The single stones are placed on each other to form the wall. "
         "After that, the single pieces are smoothed to prevent someone "
         "from hurting himself on their surface.\n",
   ]) );

   AddDetail( "waterline",
      "The waterline is the border between the land and the sea.\n");

   AddDetail( "harbour",
      "The harbour belongs to Silvere, one of the largest cities of the "
      "world. Ships arrive and depart from here.\n");

   AddDetail( ({"city","silvere"}),
      "Silvere is one of the largest cities of the world. There is a "
      "good chance, that it is the largest city of the world, though. "
      "If you want to enter the city, just go to the east.\n");

   AddVItem(
   ([ P_IDS:({"water"}),
      P_ADS:({"murky"}),
      P_LONG:
         "The water is not very clean. Remains of jellyfish, seaweed and "
         "lots of other things are floating around there.\n",
      P_SMELL:
         "The water has a very special odor. Stale fish, old seaweed and "
         "lots of other smells are hanging in the air.\n",
   ]) );

   AddVItem(
   ([ P_IDS:({"end"}),
      P_ADS:({"western","west"}),
      P_LONG:
         "That's the end of the room, you are standing at the moment. "
         "There is a big machine with a handle, an opening in the south "
         "wall and a big chain, running from the opening through the "
         "maching to the north on a big wheel.\n",
   ]) );

   AddVItem(
   ([ P_IDS:({"wheel"}),
      P_ADS:({"big","wooden"}),
      P_LONG:
         "The wheel can be found to the north. It holds the chain, "
         "when the harbour is closed and the chain between the towers "
         "is raised.\n",
   ]) );

   AddVItem(
   ([ P_IDS:({"chain"}),
      P_ADS:({"long","heavy","iron"}),
      P_LONG:
         "The chain is made from iron. It is very long and looks heavy. "
         "It comes from the wheel to the north, runs through machine and "
         "leaves through the opening in the southern wall.\n",
      P_SMELL:
         "The chain doesn't smell. The odor of rust hangs in the air "
         "though.\n",
      P_NOISE:
         "The waves are moving the chain a little bit. Every now and "
         "then there is a sound from the opening, when the chain moves "
         "over the stone.\n"
   ]) );

   AddVItem(
   ([ P_IDS:({"machine"}),
      P_ADS:({"big"}),
      P_LONG:
         "The machine is made out of wood, stones and iron. There are "
         "also some ropes. It looks like a total mess. The chain is "
         "running through the machine and there is a handle with two "
         "positions on the machine.\n",
      P_NOISE:SF(CheckHandleNoise),
      P_SMELL:
         "The machine doesn't smell at all.\n"
   ]) );

   AddDetail( ({"wall","walls"}),
      "Which wall do you mean? The room has a northern, a southern, a "
      "western and an eastern wall. They are all made out of the same "
      "grey stone, but everyone of them is different.\n");

   AddDetail( ({"west wall","western wall"}),
      "At the western wall is a big machine and a handle. A chain leads "
      "into the machine from the north and vanishes then through the "
      "opening in the southern wall.\n");

   AddDetail( ({"east wall","eastern wall"}),
      "In the eastern wall is the exit from the tower.\n");

   AddDetail( ({"north wall","northern wall"}),
      "At the north wall can you find the wheel, where the chain is "
      "stored, when the harbour is closed and therefor the chain is "
      "raised to prevent ships from entering the harbour.\n");

   AddDetail( ({"south wall","southern wall"}),
      "The only thing at the south wall is the opening, where the "
      "chain leads through. Next of the opening is a glowing globe, "
      "that spends some light. Except of that, there is nothing of "
      "interest.\n");

   AddVItem(
      ([ P_IDS:({"globe"}),
         P_ADS:({"glowing","glass"}),
         P_LONG:
            "The globe is hanging on the southern wall, just next to "
            "the opening in the southern wall. It glows in a friendly, "
            "yellow light. The globe is obviously made out of glass. "
            "Below of the globe is a small, locked box with a symbol "
            "on it.\n",
         P_SMELL:
            "The globe doesn't smell. But from the flame you sense "
            "the odor of burned oil.\n",
         P_NOISE:
            "You hear a muted crackling from the small flame inside "
            "the globe.\n",
      ]) );

   AddVItem(
      ([ P_IDS:({"flame"}),
         P_LONG:"The flame is burning inside the globe.\n",
         P_SMELL:"From the flame you smell the odor of burned oil.\n",
         P_NOISE:
            "You hear a muted crackling from the small flame.\n",
      ]) );

   AddDetail( "symbol",
      "The symbol shows you a single flame. It is painted on the "
      "box below the globe.\n");

   AddVItem(
      ([ P_IDS:({"box"}),
         P_ADS:({"small","locked"}),
         P_LONG:
            "The box is directly connected to the globe. A small "
            "symbol, that resembles a flame is painted on it. There"
            "is also a small lock, where the box can be opened.\n",
         P_SMELL:
            "The box doesn' smell. At least you are not able "
            "to sense something from it.\n",
         P_NOISE:
            "There is nothing, you can hear from the box. It is "
            "silent there.\n",
      ]) );

   AddDetail( "handle",SF(CheckHandle));

   AddDetail( ({"ground","floor"}),
      "The floor of the room is full of dirt. It seems, that nobody "
      "felt responsible for cleaning the room in a long time. In the "
      "dirt are some footprints, leading to the north and east.\n");

   AddDetail( "dirt",
      "The dirt is lying on the floor. In the dirt are some footprints "
      "leading to the north and east.\n");

   AddDetail( ({"footprints","footprint","mark","marks"}),
      "The footprints are leading to the north and east. Lots of beings "
      "walked here recently.\n");

   AddVItem(
      ([ P_IDS:({"being","beings"}),
         P_ADS:({"lots of"}),
         P_LONG:
            "Their footprints are marked into the dirt on the floor. "
            "There are several different marks here though. Some small, "
            "some big and some medium sized marks can be seen on the "
            "ground.\n",
      ]) );

   AddDetail( "ceiling",
      "The ceiling is made out of wooden beams. It looks "
      "very heavy.\n");

   AddVItem(
      ([ P_IDS:({"beam","beams"}),
         P_ADS:({"wooden","heavy"}),
         P_LONG:
            "The beams are building the ceiling of the rooms here at "
            "the basement of the tower. Every now and then you hear "
            "someone walking by above you.\n",
         P_NOISE:
            "Every now and then someone seems to walk around above "
            "you.\n",
      ]) );

   AddDetail( "iron",
      "The iron is a metal, that is used for strong things. The chain "
      "is made out of it and the machine has also some iron parts.\n");

   AddDetail( ({ "iron parts","parts" }),
      "Some parts of the machine are made out of iron.\n");

   AddDetail( "rope",
      "The rope is attached to the machine. It is used to move some "
      "parts of the machine.\n");

   AddDetail( "wood",
      "The wood is used all over the place. At the ceiling, the wheel "
      "and at the machine.\n");

   AddDetail( ({"jellyfish","remains of jellyfish"}),
      "As you look out of the opening, you see some remains of "
      "jellyfish floating on the water.\n");

   AddDetail( ({"seaweed","old seaweed"}),
      "On the water, just outside the opening in the wall, is some "
      "old seaweed floating on the water.\n");

   AddDetail( ({"things","other things"}),
      "There are some things floating on the water too. You are not "
      "able to identify them anymore. They are too rotten.\n");

   AddReadMsg( ({"plaque","small plaque","words"}),
      "You find two words on the plaque: Raise and Lower.\n");

   Set(P_INT_NOISE,
      "You hear the water of the harbour hurling against the "
      "tower walls.\n");
   Set(P_INT_SMELL,
      "The odor of harbour hangs in the air. You can smell dead fish, "
      "old seaweed and such things.\n");

   AddRoomCmd("pull",SF(PullCommand));
   AddRoomCmd("push",SF(PushCommand));

   Set(P_INT_MAP,"harbour");
   Set(P_REGION, REGION_CITY|REGION_HARBOUR);
   Set(P_COORDINATES, ({ ({ -290,0,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,"You run into a wall.\n");
   AddExit("east", SIL_HARBOUR("ntower1"));
   AddExit("north",SIL_HARBOUR("ntower4"));

   SetHandle(1);  /* make sure, that the handle is down, */
   SetMachine(0); /* the machine is not running          */
   SetChain(0);   /* and the chain is lowered.           */
}

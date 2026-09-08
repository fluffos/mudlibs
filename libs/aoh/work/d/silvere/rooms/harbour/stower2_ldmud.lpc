// This is the inside of the tower.
// created:          Sonic [26-May-1997]
// last changed:     Sonic [05-Jul-1997] added regions/coordinates
//                   Sonic [28-Jul-1997] added commands to raise chain
//                                       temporary stuff for testing

#include <silvere.h>
#include <properties.h>
#include <coordinates.h>
#include <nightday.h>
#include <regions.h>
#include <moving.h>
#include <rooms.h>
#include <msgclass.h>
#include <macros.h>
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

int PushHandle(string str)
{
   notify_fail("Push what?\n",NOTIFY_ILL_ARG);
   if(!str) return 0;
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

int PullHandle(string str)
{
   notify_fail("Pull what?\n",NOTIFY_ILL_ARG);
   if(!str) return 0;
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
         "A bell rings inside the machine. You hear feet moving from "
         "above.\n\n");
      SetHandle(1);
      call_out("MoveChain",2);
      return 1;
   }
}

int SearchCmd(string str)
{
   notify_fail("Search what?\n", NOTIFY_ILL_ARG);
   if(!str) return 0;
   if(strstr(lower_case(str),"ground")!=-1 ||
      strstr(lower_case(str),"floor")!=-1)
   {
      msg_write(CMSG_GENERIC,
         "You kneel down on the ground and search through "
         "the dirt and the dust lying around there. Except "
         "of the dirt on your hands you find nothing.\n");
      if(!({int})TP->Query(P_INVIS)) msg_room(TO, CMSG_ROOM,
         CAP(NAME(TP))+" kneels down and searches through the "
         "dirt and dust on the ground. Looking at "+HISHER(TP)+
         " face after "+HESHE(TP)+" stood up tells you, that "+
         HESHE(TP)+" hasn't found anything.\n");
      return 1;
   }
   if(strstr(lower_case(str),"dirt")!=-1)
   {
      msg_write(CMSG_GENERIC,
         "You kneel down and search through the dirt on the floor. "
         "Alas, you find nothing of interest there.\n");
      if(!({int})TP->Query(P_INVIS)) msg_room(TO, CMSG_ROOM,
         CAP(NAME(TP))+" kneels down and searches through the dirt. "
         "After a few moments, "+HESHE(TP)+" stands up with a "
         "dissapointed look on "+HISHER(TP)+" face.\n", ({TP}) );
      return 1;
   }
   if(strstr(lower_case(str),"dust")!=-1)
   {
      msg_write(CMSG_GENERIC,
         "You kneel down on the ground and search through the dust. "
         "Except of footprints which leads east, west and south you "
         "find nothing of interest. Somehow you can't surpress a "
         "deep sigh.\n");
      if(!({int})TP->Query(P_INVIS)) msg_room(TO, CMSG_ROOM,
         CAP(NAME(TP))+" kneels down on the ground and searches through "
         "the dirt. "+CAP(HESHE(TP))+" looks interested at some "
         "footprints there. After a few moments, "+HESHE(TP)+" stands "
         "up again and sighs deeply. Obviously "+HESHE(TP)+" was not "
         "successful in finding something.\n", ({TP}) );
      return 1;
   }
}

string CheckTower()
{
   string desc;

   desc="You are standing in the basement of the tower at the moment.";
   switch(({int})NIGHTDAY->QueryState())
   {
      case ND_NIGHT:
         desc+="\n";
         break;
      case ND_PREDAWN..ND_SUNRISE:
      case ND_TWILIGHT..ND_EVENING:
         desc+=
            " Through the twilight outside the tower you can barely "
            "make out another tower on the other side of the harbour. "
            "You can't see any details, though.\n";
         break;
      case ND_EARLY_MORNING..ND_SUNSET:
         desc+=
            " Through the opening you have an excellent look on the "
            "harbour. On the other side of it you can see a high "
            "tower, that looks exactly like the one you are standing "
            "at the moment.\n";
         break;
      default:
         desc+="\n";
         break;
   }
   return desc;
}

mixed CheckTower2()
{
   mixed desc;

   switch(({int})NIGHTDAY->QueryState())
   {
      case ND_NIGHT:
         return 0;
         break;
      case ND_PREDAWN..ND_SUNRISE:
      case ND_TWILIGHT..ND_EVENING:
         desc=
            "Through the dim light outside you can see the dark shadow "
            "of a big tower on the other side of the harbour. Some "
            "light shines through an opening near the waterline over "
            "there. A large, iron chain leads out of the opening and "
            "vanishes into the water.\n";
         break;
      case ND_EARLY_MORNING..ND_SUNSET:
         desc=
            "Through the opening you can see an high tower on the other "
            "side of the harbour. Near the waterline is an opening, "
            "where a large, iron chain leads out of the tower into the "
            "water of the harbour. On top of the tower are battlements "
            "and a large mirror, which points to the south.\n";
         break;
      default:
         return 0;
         break;
   }
   return desc;
}

mixed CheckMirror()
{
   switch(({int})NIGHTDAY->QueryState())
   {
      case ND_EARLY_MORNING..ND_SUNSET:
         return
            "The mirror stands on top of the northern tower behind the "
            "battlements. It points southward.\n";
         break;
      default:
         return 0;
         break;
   }
   return 0;
}

mixed CheckBattlements()
{

   switch(({int})NIGHTDAY->QueryState())
   {
      case ND_EARLY_MORNING..ND_SUNSET:
         return
            "The battlements of the northern tower are high enough to "
            "cover people in case someone is shooting at them. On the "
            "other hand, they can easily shoot back at the attackers "
            "at the same time. They also prevent people from falling "
            "down from the tower by accident.\n";
         break;
      default:
         return 0;
         break;
   }
   return 0;
}

mixed CheckQuay()
{
   mixed desc;

   switch(({int})NIGHTDAY->QueryState())
   {
      case ND_PREDAWN..ND_SUNRISE:
      case ND_TWILIGHT..ND_EVENING:
         desc=
            "You can barely make out some few workers, who are "
            "walking around on the quay on the other side of the "
            "harbour.\n";
         break;
      case ND_EARLY_MORNING..ND_SUNSET:
         desc=
            "Lots of workers are walking around on the quay on the "
            "other side of the harbour. They seems to be very busy.\n";
         break;
      default:
         return 0;
         break;
   }
   return desc;
}

string CheckWorkers()
{
   mixed desc;

   switch(({int})NIGHTDAY->QueryState())
   {
      case ND_PREDAWN..ND_SUNRISE:
      case ND_TWILIGHT..ND_EVENING:
         desc=
            "You can barely make out some few workers, who are "
            "walking around on the quay on the other side of the "
            "harbour. From that distance, you can't see anything "
            "else, so if you want to know more about them, go over "
            "there and look again.\n";
         break;
      case ND_EARLY_MORNING..ND_SUNSET:
         desc=
            "Lots of workers are walking around on the quay on the "
            "other side of the harbour. It seems that they are busy "
            "doing their work. But from that distance, you can't see "
            "any details, except that they are human (or look like "
            "them). If you want to know more, just walk over there and "
            "have a closer look.\n";
         break;
      default:
         return 0;
         break;
   }
   return desc;
}

string CheckHandle()
{
   string desc;

   desc=
      "The handle is made out of wood and sticks out of the machine. "
      "There is also a small plaque next to it. ";
   if(rHandle==0)
      desc+=
         "The handle is on 'Raise' position. How about pulling the "
         "handle?\n";
   else desc+=
      "The handle is on 'Lower' position. How about pushing the "
      "handle?\n";
   return desc;
}

string CheckOpening()
{
   string desc;

   desc=
      "The opening is right here in the northern wall. A large "
      "chain is running through it. ";
   switch(({int})NIGHTDAY->QueryState())
   {
      case ND_NIGHT:
         desc+=
            "It's dark outside the opening. Maybe it is night "
            "there?\n";
         break;
      case ND_PREDAWN..ND_SUNRISE:
      case ND_TWILIGHT..ND_EVENING:
         desc+=
            "There is some light shining through the opening "
            "and lights some few parts of the room. Outside you "
            "can barely see the water of the harbour.\n";
         break;
      case ND_EARLY_MORNING..ND_SUNSET:
         desc+=
            "Light shines through the opening and sends some "
            "rays of bright light through the room. Outside "
            "you have a good view on the harbour of Silvere "
            "and the tower on it's other side. On the quay "
            "near the tower are lots of workers, which seems "
            "to be very busy.\n";
      default:
         desc+=
            "There is something outside the opening, but "
            "you can't clearly define it.\n";
         break;
   }
   return desc;
}

string CheckHandleSound()
{
   if(rMachine==1) return
      "The machine is working and there is a metal clank from the "
      "chain as it is moved.\n";
   else return
      "You can't hear any noise from the machine.\n";
}

string CheckChainSound()
{
   if(rMachine==1) return
      "The chain is moving through the machine and there is lots "
      "of noise from it.\n";
   else return
      "There is no noise from the chain at the moment. It doesn't "
      "even move.\n";
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
   Set(P_INT_SHORT,"Tower basement, northern corner");
   Set(P_INT_LONG,
      "This is the western end of the room. Right at the wall to the "
      "west is a large machine, which is connected with a large, iron "
      "chain to a huge, wooden wheel to the south. The iron chain runs "
      "through the machine into a small opening in the northern wall, "
      "where it vanishes. To the east is the exit from the tower and "
      "southeast is a large stairway leading up.\n");

   Set(P_INT_WIZMSG,
      " East:  the exit of the tower\n"
      " South: the storeroom of the chains.\n");

   AddDetail( ({"here","place","room","western end","western corner",
                "corner"}),SF(IntLong));

   AddDetail( ({"tower","defense tower"}), SF(CheckTower));

   AddDetail( ({"north tower","north defense tower"}), SF(CheckTower2));

   AddVItem(
   ([ P_IDS:({"mirror"}),
      P_ADS:({"large","bronze"}),
      P_LONG:SF(CheckMirror),
   ]) );

   AddDetail( "battlements", SF(CheckBattlements));

   AddVItem(
   ([ P_IDS:({"water"}),
      P_ADS:({"murky","dirty"}),
      P_SMELL:
         "The water has a very special odor. Stale fish, old seaweed and "
         "lots of other smells are hanging in the air.\n",
      P_LONG:
         "The water is not very clean. Remains of jellyfish, seaweed and "
         "lots of other things are floating around there.\n",
   ]) );

   AddDetail( "waterline",
      "The waterline is the border between the quays of the harbour and "
      "the water.\n");

   AddDetail( ({"quay","quays"}), SF(CheckQuay));

   AddDetail( "workers", SF(CheckWorkers));

   AddDetail( "harbour",
      "The harbour belongs to Silvere, one of the largest cities of the "
      "world. Ships arrive and depart from here.\n");

   AddDetail( ({"city","silvere"}),
      "Silvere is one of the largest cities of the world. On the other "
      "hand, there is a good chance, that it is the largest city of the "
      "world. If you want to enter the city, just leave the tower and "
      "follow the quays to the east.\n");

   AddDetail( "ceiling",
      "The ceiling is above you. It is made out of wooden beams.\n");

   AddVItem(
   ([ P_IDS:({"beam","beams"}),
      P_ADS:({"heavy","wooden"}),
      P_LONG:
         "The beams are building the ceiling of the rooms here at the "
         "basement of the tower. Every now and then you hear someone "
         "walking by above you.\n",
      P_NOISE:
         "Every now and then someone seems to walk around above you. "
         "On the other hand, that could also be an hallucination or "
         "some kind of woodworms?\n",
   ]) );

   AddVItem(
   ([ P_IDS: ({"floor","ground"}),
      P_ADS: ({"dirty"}),
      P_LONG:
         "The floor here is full of dirt. It seems, that nobody felt "
         "responsible for cleaning the room in a long time. In the dirt "
         "are some footprints leading to the south and east.\n",
   ]) );

   AddDetail( "dirt",
      "The dirt is lying on the floor. As you look a bit closer, you "
      "see some footprints leading to the east and south.\n");

   AddDetail( "dust",
      "The dust is lying on the floor. Footprints can be seen there, "
      "leading to the south and east.\n");

   AddDetail( ({"wall","walls"}),
      "Which wall do you mean? The room has a northern, a southern, a "
      "western and an eastern wall. They are all made out of the same "
      "grey stone, but everyone of them is different.\n");

   AddVItem(
   ([ P_IDS:({"stone","stones"}),
      P_ADS:({"grey"}),
      P_LONG:
         "The stones are grey and there is nothing unusual about them. "
         "The single stones are placed on each other to form the wall. "
         "After that, the single pieces are smoothed to prevent someone "
         "from hurting himself on their surface.\n",
   ]) );

   AddDetail( ({"west wall","western wall","west"}),
      "Directly at the western wall is a large machine. A heavy, iron "
      "chain runs from a large, wooden wheel to the south through the "
      "machine into the opening in the northern wall. There is also an "
      "wooden handle on the machine, which looks quite interesting.\n");

   AddDetail( ({"east wall","eastern wall","east"}),
      "At the eastern wall is the exit out of the tower. There is also "
      "a small glowing globe hanging next to it, but it's light barely "
      "reach this place.\n");

   AddDetail( ({"north wall","northern wall","north"}),
      "At the northern wall is a small opening, where you can see the "
      "water of the harbour. Directly next to the opening is a small "
      "glowing globe, that spends some light.\n");

   AddDetail( ({"south wall","southern wall","south"}),
      "To the south is a bare wall, but at it's eastern end is a "
      "stairway, leading up to the higher level of the tower. There "
      "is also a small glowing globe next to it, but it's light doesn't "
      "reach this place.\n");

   AddVItem(
   ([ P_IDS:({"globe"}),
      P_ADS:({"glowing","glass"}),
      P_LONG:
         "The globe is hanging on the northern wall, just next to a "
         "small opening in the wall. There is another globe at the "
         "exit to the east and to the stairway south, but their "
         "light doesn't reach this place. The globe is glowing in a "
         "friendly, yellow light and light this corner of the room. "
         "It is made out of glass. There is also a small, locked box "
         "below the globe.\n",
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

   AddVItem(
   ([ P_IDS:({"machine"}),
      P_ADS:({"large","huge","wooden"}),
      P_NOISE:
         "There is nothing you can hear from the machine at the "
         "moment. It doesn't move.\n",
      P_SMELL:"The machine doesn't smell at all.\n",
      P_LONG:
         "The machine is placed at the western wall. It is "
         "something huge. The chain runs through it on it's way "
         "from the wheel to the opening. A handle is placed on "
         "the machine.\n",
   ]) );

   AddVItem(
   ([ P_IDS:({"handle"}),
      P_ADS:({"wooden"}),
      P_LONG:SF(CheckHandle),
      P_NOISE:SF(CheckHandleSound),
   ]) );

   AddVItem(
   ([ P_IDS:({"chain"}),
      P_ADS:({"large","iron","heavy"}),
      P_LONG:
         "The chain looks very heavy. It is made out of iron and runs "
         "down from the wheel through the machine into the opening in "
         "the wall.\n",
      P_SMELL:
         "The chain doesn't smell at all. The odor of rust hangs in the "
         "air though.\n",
      P_NOISE:SF(CheckChainSound),
   ]) );

   AddVItem(
   ([ P_IDS:({"wheel"}),
      P_ADS:({"large","huge","big","wooden"}),
      P_LONG:
         "The wheel can be found to the south. It holds the chain, "
         "when the harbour is closed and the chain between the two "
         "towers is raised. If you want to find out more about it, "
         "you should go south and look again.\n",
   ]) );

   AddVItem(
   ([ P_IDS:({"opening"}),
      P_ADS:({"small"}),
      P_LONG:SF(CheckOpening),
   ]) );

   AddDetail("exit",
      "The exit from the tower can be seen in the eastern wall. "
      "A small globe is hanging at the wall next to it.\n");

   AddVItem(
   ([ P_IDS:({"stairway"}),
      P_ADS:({"large"}),
      P_LONG:
         "The stairway can be found to the southeast. A small globe "
         "spends some light next to it. The stairway leads up to the "
         "higher levels of the tower.\n",
   ]) );

   AddDetail("southeast",
      "To the southeast is a stairway, which leads up to the higher "
      "levels of the tower. There is also a small, glowing globe at "
      "the wall there.\n");

   AddVItem(
   ([ P_IDS:({"level","levels"}),
      P_ADS:({"high","higher","upper"}),
      P_LONG:
         "On top of the stairway are the upper levels of the tower."
         "If you want to have a look, you may follow the stairway "
         "up.\n",
   ]) );

   AddRoomCmd("pull",   SF(PullHandle));
   AddRoomCmd("push",   SF(PushHandle));
   AddRoomCmd("search", SF(SearchCmd));

   Set(P_INT_MAP,"harbour");
   Set(P_REGION, REGION_CITY|REGION_HARBOUR);
   Set(P_COORDINATES, ({ ({ -290,20,0 }), C_SILVERE }) );

   SetHandle(1);   // set the handle to lower chains
   SetMachine(0);  // turn off the machine
   SetChain(0);    // the chain is lowered.

   Set(P_NOWAY_MSG,"You run into a wall.\n");
   AddExit("east", SIL_HARBOUR("stower1"));
   AddExit("south",SIL_HARBOUR("stower4"));
}

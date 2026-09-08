// North tower, second level: A storeroom for boulders.
// created:          Sonic [26-May-1997]
// last changed:     Sonic [05-Jul-1997] added regions/coordinates
//                         [01-Aug-1997] added description/details

#include <silvere.h>
#include <properties.h>
#include <coordinates.h>
#include <msgclass.h>
#include <regions.h>
#include <moving.h>
#include <macros.h>
#include <rooms.h>
inherit BASEROOM;

#define MININAME  "sil_bouldermove"

mixed bouldermoved, boulders;

/* This function moves one boulder to the south on the
 * platform and notifies the room about it. If the player
 * has moved 10 boulders to the south, a miniquest is set.
 *
 * // TODO: Add directions to the command, e.g.
 * // TODO: push boulder south / push boulder north
 */
int PushBoulder(string str)
{
   notify_fail("Push what?\n",NOTIFY_ILL_ARG);
   if(!str) return 0;
   if(!TP)  return 0;
   if(strstr(lower_case(str),"boulder")!=-1 ||
      strstr(lower_case(str),"stone")!=-1)
   {
      mapping temp;
      mixed keys, desc;

      msg_write(CMSG_GENERIC,
         "You push one of the boulders with full might "
         "through the exit on the platform to the south.\n");
      msg_room(TO,CMSG_ROOM,CAP(NAME(TP))+
         "pushes a boulder to the south.\n", ({TP}) );
      temp=Query(P_EXITS);
      if(temp)
      {
         int a;

         keys=m_indices(temp);
         desc=m_values(temp);
         if((a=member(keys,"south"))!=-1)
         {
            int b;

            desc[a]->AddBoulder(1);
            if((b=member(bouldermoved,RNAME(TP)))!=-1)
               boulders[b]+=1;
            else
            {
               bouldermoved+=({ RNAME(TP) });
               boulders+=({1});
            }
            if((b=member(bouldermoved,RNAME(TP)))!=-1)
            {
               if(boulders[b]==10)
               {
                  int pstr;

                  if(!({int})QUESTMASTER->QueryQuestSolved(MININAME,TP))
                     QUESTMASTER->SetPlayerQuest(MININAME,TP);
                  msg_write(CMSG_STATUS,
                     "After moving that much boulders, you feel "
                     "your muscles bulge.\n\n");
                  pstr=({int})TP->Query(P_STR);
                  if(pstr) TP->Set(P_STR,pstr+1);

               }
            }
            TP->move(desc[a],M_GO);
            return 1;
         }
      }
      return 1;
   }
   return 0;
}

int PullBoulder(string str)
{
   notify_fail("Pull what?\n",NOTIFY_ILL_ARG);
   if(!str) return 0;
   if(!TP)  return 0;
   if(strstr(lower_case(str),"boulder")!=-1 ||
      strstr(lower_case(str),"stone")!=-1)
   {
      msg_write(CMSG_GENERIC,
         "You pull one of the boulders, but it does't move. It's far "
         "too heavy for you.\n");
      msg_room(TO,CMSG_ROOM,CAP(NAME(TP))+" pulls one of the boulders, "
         "but "+HESHE(TP)+" has no success. The boulder doesn't even "
         "move.\n", ({TP}) );
      return 1;
   }
}

varargs void create()
{
   ::create();
   Set(P_INDOORS,1);
   Set(P_INT_SHORT,"A storeroom");
   Set(P_INT_LONG,
      "This is a large storeroom. Boulders are piled in this room on "
      "the floor. A glowing globe hangs at the southern wall next to "
      "the exit.\n");

   Set(P_INT_WIZMSG,
" South: To a platform, leading up\n");

   AddDetail( ({"ground","floor","wooden floor"}),
      "The ground is made out of large wooden beams. There is some "
      "dust, where you can see lots of footprints. In addition, you "
      "see lots of stone boulders lying around.\n");

   AddDetail( "dust",
      "Some dust is lying on the beams of the floor. You can see some "
      "footprints leading through the exit to the south.\n");

   AddDetail( ({"footprint","footprints"}),
      "Some footprints can be seen at the floor between the boulders. "
      "They are all leading in or out of the room through the exit to "
      "the south.\n");

   AddDetail( "ceiling",
      "The ceiling is made out of large wooden beams. They look very "
      "heavy.\n");

   AddVItem(
   ([ P_IDS:({"beam","beams"}),
      P_ADS:({"wooden","heavy"}),
      P_LONG:
         "The beams are building the floor and the ceiling of the "
         "rooms here at the tower. Every now and then you hear "
         "someone walking by above you.\n",
      P_NOISE:
         "Every now and then someone seems to walk around above "
         "you.\n",
   ]) );

   AddDetail( ({"storeroom","large storeroom","room","here","tower",
                "north tower","defense tower","north defense tower",
                "place","this place"}),
      "That's the place you are standing at the moment. If you want "
      "to find out about it, just have a look.\n");

   AddVItem(
   ([ P_IDS:({"globe"}),
      P_ADS:({"glowing"}),
      P_LONG:
         "The globe is hanging on the southern wall. It is made out "
         "of glass and a small flame burns there in a friendly, "
         "yellow light. Below the globe is a small, locked box with "
         "a symbol on it.\n",
      P_SMELL:
         "The globe doesn't smell. But from the flame you sense "
         "the odor of burned oil.\n",
      P_NOISE:
         "You hear a muted crackling from the small flame inside "
         "the globe.\n",
   ]) );

   AddDetail( "glass","The glowing globe is made out of glass.\n");

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

   AddDetail( "symbol",
      "The symbol shows you a single flame. It is painted on the "
      "box below the globe.\n");

   AddVItem(
   ([ P_IDS:({"flame"}),
      P_LONG:"The flame is burning inside the globe.\n",
      P_SMELL:"From the flame you smell the odor of burned oil.\n",
      P_NOISE:
         "You hear a muted crackling from the small flame.\n",
   ]) );

   AddVItem(
   ([ P_IDS:({"boulder","boulders"}),
      P_ADS:({"large","stone"}),
      P_LONG:
         "The stones are very heavy. They are lying on the floor.\n",
      P_WEIGHT:50000,
   ]) );

   AddDetail( ({"wall","walls"}),
      "The walls are made out of the same kind of stone as the whole "
      "tower. In the southern wall is an exit. Next to it you see a "
      "glowing globe, lighting the room.\n");

   AddDetail( ({"exit","exits"}),
      "The only exit from this room is the exit in the southern "
      "wall.\n");

   AddDetail( ({"south wall","southern wall"}),
      "In the southern wall is an exit, where you can leave the room. "
      "There you see also an glowing globe, lighting the room.\n");

   AddDetail( ({"north wall","northern wall"}),
      "The north wall is absolutely bare from anything except the "
      "stones it is made from.\n");

   AddDetail( ({"east wall","eastern wall"}),
      "The eastern wall is absolutely bare from anything except the "
      "stones, it is made from.\n");

   AddDetail( ({"west wall","western wall"}),
      "The western wall is absolutely bare from anything except the "
      "stones, it is made from.\n");

   AddRoomCmd("push",SF(PushBoulder));
   AddRoomCmd("pull",SF(PullBoulder));

   bouldermoved=({ });
   boulders=({ });

   Set(P_INT_MAP,"harbour");
   Set(P_REGION, REGION_CITY|REGION_HARBOUR);
   Set(P_COORDINATES, ({ ({ -290,-10,10 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,"You run into a wall.\n");
   AddExit("south",SIL_HARBOUR("ntower7"));
}

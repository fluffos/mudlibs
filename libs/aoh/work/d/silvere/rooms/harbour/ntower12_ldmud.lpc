// on top of the tower. At a mirror
// created:          Sonic [26-May-1997]
// last changed:     Sonic [05-Jul-1997] added regions/coordinates
//                   Sonic [24-Sep-1997] added description, some cmds

#include <silvere.h>
#include <properties.h>
#include <coordinates.h>
#include <msgclass.h>
#include <regions.h>
#include <moving.h>
#include <macros.h>
#include <rooms.h>
inherit BASEROOM;

// TODO: Finish shoving someone from the tower
int ShoveDown(string str)
{
   notify_fail(
      "Shove someone from the tower is not finished yet. "
      "Please be patient.\n",NOTIFY_ILL_ARG);
   return 0;
}

int JumpDown(string str)
{
   notify_fail("Jump where?\n",NOTIFY_ILL_ARG);
   if(!str) return 0;
   if(!TP)  return 0;
   if(strstr(lower_case(str),"down")!=-1 ||
      strstr(lower_case(str),"tower")!=-1)
   {
      notify_fail(
         "Now, you could jump into the water or down on the street "
         "of the harbour. You should therefore a little bit more "
         "specific.\n", NOTIFY_ILL_ARG);
      return 0;
   }
   if(strstr(lower_case(str),"ocean")!=-1 ||
      strstr(lower_case(str),"water")!=-1)
   {
      notify_fail(
         "Jumping down into the water of the harbour is not possible "
         "(yet).\n", NOTIFY_ILL_ARG);
      return 0;
   }
   if(strstr(lower_case(str),"street")!=-1 ||
      strstr(lower_case(str),"harbour")!=-1)
   {
      int pHP, pWimp;

      TP->move(SIL_HARBOUR("ntower_enter"),M_SPECIAL,
         ({
            "climbs on the battlements and looks down. Then "
            +HESHE(TP)+" steps forward and falls down. A little "
            "moment later you hear a loud noise from below and a "
            "short scream, followed by an alarmed cry from someone "
            "below",

            "falls down from the tower and lies badly hurt on the "
            "road. After some time, "+HESHE(TP)+" stands up and "
            "checks "+HISHER(TP)+" body, if everything is still "
            "in place",

            "climb on the battlements and look down. A little bit "
            "to the right is the entrance to the tower and directly "
            "below is the roof a a small house, about 20 feet below. "
            "After looking for some time, you walk into the air and "
            "jump down.\n\nSPLAT!\n\n"
            "You squarely hit the roof of the small building and from "
            "there you continue your fall to the ground. You hit the "
            "road right in front of the entrance to the tower"

         }) );
      pHP=  ({int})TP->Query(P_HP);
      pWimp=({int})TP->Query(P_WIMPY);

      TP->Set(P_WIMPY,0);  /* switch to brave mode */
      TP->DoDamage(pHP,random(10)+1);
      TP->Set(P_WIMPY,pWimp); /* restore old setting */
      return 1;
   }
   return 0;
}

varargs void create()
{
   ::create();
   Set(P_INDOORS,0);
   Set(P_INT_SHORT,"On the tower");
   Set(P_INT_LONG,
      "This is the top of the tower at the exit of the harbour. To the "
      "west you have a great view on the open ocean with the gulf of "
      "Silvere. To the east is the city itself, surrounded by high "
      "city walls made from some kind of red stones. To the south, "
      "on the other side of the harbour is another tower of the same "
      "kind you are standing at the moment. Behind the landscape "
      "continues to the horizon into some fields and a huge forest. "
      "A big mirror stands directly at the battlements, pointing to the "
      "south. A small tent can be found to the north.\n");

   Set(P_INT_WIZMSG,
      " West:  To the platform and the stairs down\n"
      " North: To the shelter.\n");

   AddVItem(
   ([ P_IDS:({"tower","place","here"}),
      P_ADS:({"north","northern","defense","top of","top of the"}),
      P_LONG:
         "That's the place you are standing at the moment. Right in "
         "front of you are the battlements with a large mirror pointing "
         "to the south. You can also see the whole harbour and the wall "
         "of Silvere.\n",
   ]) );

   AddDetail( ({"south tower","southern tower"}),
      "There is another tower just on the other side of the harbour. "
      "It looks just like the tower you are standing at the moment.\n");

   AddDetail( "battlements",
      "The battlements are built to the east and south. They are about "
      "4 feet high and prevent you from falling down from the tower on "
      "the street or the water of the tower. Of course you could always "
      "jump down, but that's something else. A large mirror is standing "
      "right in front of the battlements too.\n");

   AddDetail( "water",
      "The water can be found about 30 feet below in the harbour. It "
      "seems to be somewhat dirty and very wet. Seems to be a nice "
      "place to swim.\n");

   AddDetail( ({"quay","quays"}),
      "One of the quays of the harbour starts at the base of the tower "
      "and leads to the east toward the city. It seems to be a very bad "
      "idea to jump down the 30 feet from here, as the paved stones of "
      "the quay seems to be very hard.\n");

   AddDetail( ({"street","streets"}),
      "The streets are at the base of the tower, just about 30 feet "
      "below. It seems to be a very bad idea to jump down there, as "
      "the paved stones of the street seems to be very hard.\n");

   AddDetail( ({"stones","paved stones"}),
      "The stones are building one of the quays of the harbour of "
      "Silvere.\n");

   AddDetail( ({"harbour","harbour of silvere"}),
      "The harbour of Silvere lies within a small bay, guarded by "
      "two towers. You are standing on one of the towers at the "
      "moment and have a great view down on the harbour.\n");

   AddDetail( ({ "city","silvere"}),
      "The city of Silvere can be found to the east, just behind the "
      "harbour. It is protected by a large citywall, which blocks also "
      "most of the buildings of Silvere. You can make out only lots of "
      "roofs behind the wall and a few higher buildings of the city. "
      "They look impressive, though. Maybe they are worth a visit?\n");

   AddVItem(
   ([ P_IDS:({"building","buildings"}),
      P_ADS:({"high","higher","impressive"}),
      P_LONG:
         "The buildings are a part of Silvere. They are somewhat higher "
         "so that you can see them from here. Maybe they are so high, "
         "because they are important? Should be interesting to visit "
         "them later.\n",
   ]) );

   AddDetail( ({"roof","roofs"}),
      "The roofs of the buildings are made from some kind of red "
      "tile.\n");

   AddDetail( ({ "wall","city wall","citywall"}),
      "The wall surrounds the city of Silvere. It was built a long time "
      "ago to keep unwanted guests out of the city.\n");

   AddVItem(
   ([ P_IDS:({"tile","tiles"}),
      P_ADS:({"red"}),
      P_LONG:
         "The tiles are bright red when the sun shines down on them. "
         "They are building the roofs of some of the buildings, you can "
         "see from this place.\n",
   ]) );

   AddDetail( ({"sea","ocean","gulf of silvere","gulf"}),
      "The Gulf of Silvere lies just to the west on the other side of "
      "the tower. It is part of the Sea of Shamyra, which extends all "
      "the way to the horizon.\n");

   AddDetail( "horizon",
      "The horizon is the end of the world. The Sea of Shamyra can be "
      "seen there.\n");

   AddDetail( ({"shamyra","sea of shamyra"}),
      "The Sea of Shamyra is a large ocean to the west. It extends from "
      "the coast to the horizon and beyond it.\n");

   AddDetail( ({"coast","coast of silvere"}),
      "The coast runs along the city of Silvere to the north and west. "
      "A large fortress is sitting on the top of a hill directly to the "
      "north. The coast continues to the south, but you can see much of "
      "it from here.\n");

   AddDetail( ({"fortress","huge fortress"}),
      "The fortress sits on top of the hill to the north of the tower. "
      "It is a very strong building, which was built for the protection "
      "of the city.\n");

   AddVItem(
   ([ P_IDS:({"hill"}),
      P_ADS:({"large"}),
      P_LONG:
         "The hill can be found directly to the north behind the tower. "
         "There is a huge fortress on top of it. At the base of the "
         "tower is a small forest which opens on a long beach at the "
         "coast.\n",
   ]) );

   AddDetail( ({"ground","floor"}),
      "The ground is made out of large beams of wood. There is no "
      "dirt or dust here but instead you can see a large tent. To "
      "the south is a large, bronze mirror pointing south.\n");

   AddVItem(
   ([ P_IDS:({"mirror"}),
      P_ADS:({"bronze","large"}),
      P_LONG:
         "The mirror stands in front of the battlements. It points "
         "toward the south. Except of that, it seems to be pretty "
         "useless.\n",
   ]) );

   AddDetail( ({ "landscape"}),
      "The landscape around the city is quite nice. To the north is a "
      "hill with a fortress sitting on top of it. At the base of the "
      "hill is a small forest. To the south, on the other side of the "
      "harbour are some large fields on both sides of a large river.\n");

   AddDetail( ({"field","fields"}),
      "The fields can be found to the south, behind the tower on the "
      "other side of the harbour. The fields are placed on both sides "
      "of a large river.\n");

   AddDetail( ({"river","large river"}),
      "The river lies to the south of the harbour. It flows from east "
      "to west into the Gulf of Silvere. On both shores are large "
      "fields.\n");

   AddDetail( "tree","trees",
      "There are lots of trees at the base of the hill. From here you "
      "can't make out any details, but there are lots of different "
      "trees there.\n");

   AddVItem(
   ([ P_IDS:({"forest"}),
      P_ADS:({"small"}),
      P_LONG:
         "The forest can be seen at the base of the hill. Lots of trees "
         "are standing there. At the western end of the forest is a "
         "beach, to the east is the road between the fortress and the "
         "city of Silvere.\n",
   ]) );

   AddDetail( "beach",
      "The beach lies just at the coast to the north. You can't see "
      "any details from the place here.\n");

   AddDetail( ({"tent","small tent"}),
      "The tent lies to the north and seems to be empty.\n");

   AddRoomCmd("shove",#'ShoveDown);
   AddRoomCmd("jump",#'JumpDown);

   Set(P_INT_MAP,"harbour");
   Set(P_REGION, REGION_CITY|REGION_HARBOUR);
   Set(P_COORDINATES, ({ ({ -280,0,20 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,"You run into the battlements.\n");
   AddExit("north",SIL_HARBOUR("ntower11"));
   AddExit("west", SIL_HARBOUR("ntower9"));
}

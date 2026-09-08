// on top of the tower. A small shelter is here
// created:          Sonic [26-May-1997]
// last changed:     Sonic [05-Jul-1997] added regions/coordinates
//                   Sonic [24-Sep-1997] added description/details
//                   Sonic [28-Sep-1997] jumping command (no skills yet)

#include <silvere.h>
#include <properties.h>
#include <coordinates.h>
#include <msgclass.h>
#include <regions.h>
#include <moving.h>
#include <macros.h>
#include <rooms.h>
inherit BASEROOM;

int JumpDown(string str)
{
   notify_fail("Jump where?\n",NOTIFY_ILL_ARG);
   if(!str) return 0;
   if(!TP)  return 0;
   if(strstr(lower_case(str),"down")!=-1 ||
      strstr(lower_case(str),"tower")!=-1 ||
      strstr(lower_case(str),"street")!=-1)
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
      // make sure, the player is in brave-mode, or the DoDamage
      // will move him out of the room before jumping down. :-)
      TP->Set(P_WIMPY,0);
      TP->DoDamage(pHP, random(10)+1);
      TP->Set(P_WIMPY,pWimp);
      return 1;
   }
   return 0;
}

int ShoveDown(string str)
{
   object *temp, *livs;

   notify_fail("Shove whom?\n",NOTIFY_ILL_ARG);
   if(!str) return 0;
   if(!TP)  return 0;
   temp=all_inventory(TO);
   if(temp)
   {
      int a;

      livs=({ });
      for(a=0; a<sizeof(temp); a++)
      {
         if(({int})temp[a]->Query(P_IS_LIVING)) livs+=({ temp[a] });
      }
      msg_write(CMSG_GENERIC,"*** Debug Start.\n Argument-string is "+str+".\n");
      msg_write(CMSG_GENERIC," Size of living-array: "+sizeof(livs)+".\n");
      for(a=0; a<sizeof(livs); a++)
      {
         msg_write(CMSG_GENERIC,sprintf("%2d: %s\n",a+1, RNAME(livs[a])));
      }
      msg_write(CMSG_GENERIC, "*** End Debug.\n");
      for(a=0; a<sizeof(livs); a++)
      {
         if(strstr(lower_case(str),RNAME(livs[a]))!=-1)
         {
            int pHP, pWimp;

            msg_write(CMSG_GENERIC,
               "You walk innocently behind "+CAP(NAME(livs[a]))+" and "
               "shove "+HIMHER(TP)+" over the battlements.\n");
            livs[a]->move(SIL_HARBOUR("ntower_enter"),M_SPECIAL,
               ({
                  "is shoved over the battlements by "+NAME(TP),

                  "falls down from the tower and lies badly hurt on the "
                  "road. After some time, "+HESHE(TP)+" stands up and "
                  "checks "+HISHER(TP)+" body, if everything is still "
                  "where it should be",

                  "are shoved over the battlements by "+CAP(NAME(TP))+
                  ". You immediately start to fall down.\n\nSPLAT!\n\n"
                  "You squarely hit the roof of the small building and "
                  "from there you continue your fall to the ground. You "
                  "hit the road right in front of the entrance to the "
                  "tower"
               }) );
            pHP=  ({int})livs[a]->Query(P_HP);
            pWimp=({int})livs[a]->Query(P_WIMPY);
            // make sure, the player is in brave-mode, or the DoDamage
            // will move him out of the room before jumping down. :-)
            livs[a]->Set(P_WIMPY,0);
            livs[a]->DoDamage(pHP, random(10)+1);
            livs[a]->Set(P_WIMPY,pWimp);
            return 1;
         }
      }
   }
   notify_fail("That's not here, you can't shove it down.\n",
      NOTIFY_ILL_ARG);
   return 0;
}

varargs void create()
{
   ::create();
   Set(P_INDOORS,0);
   Set(P_INT_SHORT,"On the tower");
   Set(P_INT_LONG,
      "This is the top of the tower. You have a great view of the city "
      "of Silvere and the landscape to the north which surrounds the "
      "city. Directly in front of you is a small tent, which was set up "
      "here for permanent use by the guards. To the west is a big "
      "catapult aiming toward the open sea. South you can see some "
      "kind of a mirror.\n");

   Set(P_INT_WIZMSG,
      " %^BOLD%^*** Details not finished yet ***%^RESET%^\n"
      " West:  To the catapult\n"
      " South: To a mirror.\n");

   AddDetail( ({"tower","top of the tower","towertop"}),
      "You are standing here at the moment. Right in front of you at "
      "the battlements is a small tent, which is set up permanently "
      "here. To the south is a large, bronze mirror, pointing toward "
      "the southern tower. To the east is a large catapult, aiming "
      "toward the open sea.\n");

   AddDetail( ({"here","place"}),
      "That's the place you are standing at the moment. If you want to "
      "find out more about it, just have a look.\n");

   AddDetail( ({"sea","ocean","water","gulf of silvere"}),
      "The Gulf of Silvere lies just to the west. It is a part of the "
      "Great Western Sea and runs along the coast of Silvere to the "
      "north and south.\n");

   AddDetail( ({"shamyra","sea of shamyra"}),
      "The Sea of Shamyra is a large ocean to the west.\n");

   AddDetail( ({"coast","coast of silvere"}),
      "The coast runs along the city of Silvere to the north and west. "
      "A large fortress is sitting on the top of a hill directly to the "
      "north. The coast continues to the south, but you can't see much "
      "from here.\n");

   AddDetail( ({"wall","citywall","citywall of silvere"}),
      "The wall surrounds the city of Silvere. It was built a long time "
      "ago to keep unwanted guests out of the city.\n");

   AddDetail( ({"roof","roofs"}),
      "The roofs of the buildings are made from some kind of red "
      "tile.\n");

   AddVItem(
   ([ P_IDS:({"tile","tiles"}),
      P_ADS:({"red"}),
      P_LONG:
         "The tiles are bright red when the sun shines down on them. "
         "They are building the roofs of some of the buildings, you can "
         "see from this place.\n",
   ]) );

   AddVItem(
   ([ P_IDS:({"building","buildings"}),
      P_ADS:({"high","higher"}),
      P_LONG:
         "The buildings are a part of Silvere. They are somewhat higher "
         "so that you can see them from here. Maybe they are so high, "
         "because they are important? Should be interesting to visit "
         "them later.\n",
   ]) );

   AddDetail( ({"city","silvere"}),
      "The city of Silvere can be found to the east. You see lots of "
      "buildings there, but most of them are hidden by the citywalls "
      "so that you can only see their roofs. Some of the buildings of "
      "the cities are somewhat higher and look very impressive, though. "
      "Maybe they are worth a visit?\n");

   AddDetail( ({"view","great view"}),
      "The view out on the sea is astonishing. The Gulf of Silvere is "
      "just to the west and ships are sailing there.\n");

   AddDetail( "catapult",
      "The catapult can be found at the other end of the tower to the "
      "west, standing at the battlements and aiming toward the sea.\n");

   AddVItem(
   ([ P_IDS:({"mirror"}),
      P_ADS:({"bronze","large"}),
      P_LONG:
         "The mirror can be found to the south. It standing there "
         "at the southern battlements, pointing south to the tower "
         "at the other end of the harbour. If you want to find out "
         "more about that, just go there and look.\n",
   ]) );

   AddDetail( ({"ground","floor"}),
      "The ground is made out of large beams of wood. There is no "
      "dirt or dust here but instead you can see a large tent. To "
      "the south is a large, bronze mirror pointing south.\n");

   AddDetail( "battlements",
      "The battlements can be found directly east and north of you. "
      "They are about 4 feet high and prevent you from jumping down "
      "into the water by accident (which could be dangerous for you). "
      "In front of the battlements is a large tent.\n");

   AddDetail( "north",
      "To the north is the end of the tower. The battlements are "
      "blocking the way there. On the other side you have a great "
      "look on the landscape there. A large hill can be seen there "
      "with a huge fortress. A road leads down from the fortress to "
      "the city. The coast runs to the north along a beautiful beach. "
      "There are also lots of trees, which build a rather small forest "
      "at the base of the hill.\n");

   AddDetail( "south",
      "To the south you can see a large, bronze mirror pointing toward "
      "the tower on the other side of the harbour.\n");

   AddDetail( "west",
      "The Gulf of Silvere lies just to the west. It is part of the "
      "great western sea and runs along the coast of Silvere to the "
      "north. A large catapult is standing at the battlements there, "
      "too.\n");

   AddDetail( "east",
      "To the east is the city of Silvere. Over the battlements you see "
      "the visible parts of the city, but most of it is blocked by the "
      "citywall.\n");

   AddDetail( "landscape",
      "The landscape to the north is very nice. Directly north of the "
      "tower is a large hill with a huge fortress on top. A road leads "
      "from it down to the city. A small forest can be seen at the base "
      "of the hill and a nice beach extends along the coast to the "
      "north.\n");

   AddVItem(
   ([ P_IDS:({"hill"}),
      P_ADS:({"large"}),
      P_LONG:
         "The hill can be found directly to the north behind the tower. "
         "There is a huge fortress on top of it. At the base of the "
         "tower is a small forest which opens on a long beach at the "
         "coast.\n",
   ]) );

   AddDetail( "fortress","huge fortress",
      "The fortress sits on top of the hill to the north of the "
      "tower. It is a very strong building, which was built for "
      "the protection of the city.\n");

   AddDetail( "road",
      "The road leads from the fortress down to the city. A small "
      "forest can be seen next to it at the base of the hill.\n");

   AddDetail( "coast",
      "The coast leads from north to south. There is lots of sand "
      "and further to the north there are some cliffs. A really "
      "beautiful beach can be seen just next to a small forest around "
      "the hill.\n");

   AddDetail( "beach","beautiful beach",
      "The beach looks very beautiful. A small forest can be seen east "
      "of it. Lots of sand and blue water makes it a nice place to rest "
      "and refresh yourself.\n");

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
         "very nice beach, to the east is the road between the fortress "
         "and the city of Silvere.\n",
   ]) );

   AddDetail( ({"cliff","cliffs"}),
      "Some cliffs can be seen to the north. They are far away but the "
      "view from here is impressive. From here you can't see any detail "
      "but they are very high.\n");

   AddDetail( "tent",
      "The tent is standing here. It is used as shelter for the guards "
      "here, in case of bad weather or if the sun is getting to hot.\n");

   AddDetail( "guards",
      "There are no guards here at the moment. That's a little bit "
      "strange, as there should be someone here to watch for incoming "
      "ships. Maybe they are busy somewhere else?\n");

   AddRoomCmd("jump",   #'JumpDown);
   AddRoomCmd("shove",  #'ShoveDown);

   Set(P_INT_MAP,"harbour");
   Set(P_REGION, REGION_CITY|REGION_HARBOUR);
   Set(P_COORDINATES, ({ ({ -280,-10,20 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,"You run into the battlements.\n");
   AddExit("south",SIL_HARBOUR("ntower12"));
   AddExit("west", SIL_HARBOUR("ntower10"));
}

// A catapult is standing here
// created:          Sonic [26-May-1997]
// last changed:     Sonic [05-Jul-1997] added regions/coordinates
//                   Sonic [31-Aug-1997] added details

#include <silvere.h>
#include <specialrooms.h>
#include <properties.h>
#include <msgclass.h>
#include <coordinates.h>
#include <regions.h>
#include <moving.h>
#include <macros.h>
#include <rooms.h>
inherit BASEROOM;

// TODO: There will be a little quest where you have to aim a catapult
// TODO: at an incoming ship and sink it. There is a good possibility
// TODO: that you run out of stones, so you have to get some from the
// TODO: storeroom below with the platform. Or simply load a player/
// TOOD: wizard on the catapult and use him/her as ammo. ;-)
// TODO: Add possibility for the ship to return fire (maybe) *grin*

// TODO: fun-command: jump [down|into water] to be finished (shoving too)
// TODO: possible change to die/injuries (?)
// TODO: on the other hand, the whole harbour is a wonderful place to
// TODO: learn swimming (or drowning) :-)

int catapult_loaded, available_stones;
int catapult_aim;
string catapult_target, catapult_item;

/* some little defines for nicer code */
#define AIM_SHIP     1
#define AIM_CITY     2
#define AIM_HARBOUR  3
#define AIM_TOWER    4
#define AIM_FORTRESS 5
#define AIM_OTHER    6

int PullHandle(string str)
{
   notify_fail("Pull what?\n",NOTIFY_ILL_ARG);
   if(!str) return 0;
   if(!TP)  return 0;
   if(strstr(lower_case(str),"handle")!=-1 ||
      strstr(lower_case(str),"lever")!=-1)
   {
      if(catapult_loaded)
      {
         string desc;
         object item, room, liv;

         if(catapult_aim==0)
         {
            notify_fail(
               "You have to aim the catapult first. The catapult "
               "aims toward the open sea with no special target.\n",
               NOTIFY_ILL_ARG);
            return 0;
         }
         msg_write(CMSG_GENERIC,"You pull the handle.\n");
         msg_room(TO,CMSG_ROOM,
            CAP(NAME(TP))+" pulls the handle of the catapult.\n",({TP}));
         desc="The catapult fires it's load high into the air ";
         switch(catapult_aim)
         {
            case AIM_SHIP: desc+="toward the ships.\n"; break;
            case AIM_CITY: desc+="toward the city of Silvere.\n"; break;
            case AIM_HARBOUR: desc+="at the harbour.\n"; break;
            case AIM_FORTRESS: desc+="at the fortress.\n"; break;
            case AIM_TOWER: desc+="at the southern tower.\n"; break;
            case AIM_OTHER: desc+="at "+CAP(catapult_target)+".\n";
                            break;
         }
         msg_room(TO, CMSG_ROOM, desc);
         if(catapult_item=="stone")
         {
            desc=
               "A stone hits the ground just before your feet. That's "
               "something strange. Maybe a wizard is in a extremely bad "
               "mood, the weather is getting bad or someone is playing "
               "with a catapult...\n";
            switch(catapult_aim)
            {
               case AIM_CITY:
                  msg_room(CATAPULT_CITY, CMSG_ROOM, desc);
                  break;
               case AIM_SHIP:
                  msg_room(CATAPULT_SHIP, CMSG_ROOM, desc);
                  break;
               case AIM_HARBOUR:
                  msg_room(CATAPULT_HARBOUR, CMSG_ROOM, desc);
                  break;
               case AIM_FORTRESS:
                  msg_room(CATAPULT_FORTRESS, CMSG_ROOM, desc);
                  break;
               case AIM_TOWER:
                  msg_room(CATAPULT_STOWER, CMSG_ROOM, desc);
                  break;
               case AIM_OTHER:
               {
                  liv=find_living(catapult_target);
                  if(liv)
                  {
                     room=environment(liv);
                     if(room)
                        msg_room(room, CMSG_ROOM, desc);
                     else msg_write(CMSG_GENERIC,
                        "Something strange happened. The stone vanishes "
                        "in midair. Maybe something went wrong here or "
                        "your target just vanished. Anyways, it's not "
                        "the worst idea to ask a wizard for help...\n");
                  }
                  else msg_write(CMSG_GENERIC,
                     "Something strange happened. The stone vanishes "
                     "in midair. Maybe something went wrong here or "
                     "your target just vanished. Anyways, it's possibly "
                     "a good idea to ask a wizard for help...\n");
                  break;
               }
               default:
                  msg_write(CMSG_GENERIC,
                     "Something strange happened. The stone vanishes in "
                     "midair. Maybe something went wrong here or your "
                     "target just vanished. Anyways, it's possibly a "
                     "good idea to ask a wizard for help...\n");
                  break;
            }
            catapult_loaded=0;
            catapult_target="";
            catapult_item="";
            catapult_aim=0;
            return 1;
         }
         /* there is no stone on the catapult, but it is loaded
          * so it is a player/wizard...
          */
         liv=find_living(catapult_item);
         if(liv)
         {
            room=environment(liv);
            if(room)
            {
               object target, player;

               player=find_living(catapult_target);
               desc=
                  CAP(NAME(liv))+" falls down from the sky with a "
                  "loud scream and hits the ground just in front of "
                  "you with a loud SPLAT! "+CAP(HESHE(liv))+" moans "
                  "a lot, but finally manages to stand up on "+
                  HISHER(liv)+" feet. "+CAP(HESHE(liv))+" looks badly "
                  "shaken, though.\n";
               switch(catapult_aim)
               {
                  case AIM_CITY:
                     msg_room(CATAPULT_CITY, CMSG_ROOM, desc);
                     break;
                  case AIM_SHIP:
                     msg_room(CATAPULT_SHIP, CMSG_ROOM, desc);
                     break;
                  case AIM_HARBOUR:
                     msg_room(CATAPULT_HARBOUR, CMSG_ROOM, desc);
                     break;
                  case AIM_FORTRESS:
                     msg_room(CATAPULT_FORTRESS, CMSG_ROOM, desc);
                     break;
                  case AIM_TOWER:
                     msg_room(CATAPULT_STOWER, CMSG_ROOM, desc);
                     break;
                  case AIM_OTHER:
                  {
                     if(player)
                     {
                        target=environment(player);
                        if(target)
                           msg_room(target, CMSG_ROOM, desc);
                        else
                           msg_write(CMSG_GENERIC,
                              "Something strange happened. The stone "
                              "vanishes in midair. Maybe something went "
                              "wrong here or your target just vanished. "
                              "Anyways, it's possibly a good idea to ask "
                              "a wizard for help...\n");
                     }
                     else msg_write(CMSG_GENERIC,
                        "Something strange happened. The stone "
                        "vanishes in midair. Maybe something went "
                        "wrong here or your target just vanished. "
                        "Anyways, it's possibly a good idea to ask "
                        "a wizard for help...\n");
                     break;
                  }
                  default:
                     msg_write(CMSG_GENERIC,
                        "Something strange happened. The stone "
                        "vanishes in midair. Maybe something went "
                        "wrong here or your target just vanished. "
                        "Anyways, it's possibly a good idea to ask "
                        "a wizard for help...\n");
                     break;
               }
               liv->move(target,M_SILENT);
               liv->LookAfterMove();
               catapult_loaded=0;
               catapult_aim=0;
               catapult_item="";
               catapult_target="";
               return 1;
            }
            msg_write(CMSG_GENERIC,
               "Something strange happened. The stone vanishes in "
               "midair. Maybe something went wrong here or your "
               "target just vanished. Anyways, it's possibly a good "
               "idea to ask a wizard for help...\n");
            return 1;
         }
         msg_write(CMSG_GENERIC,
            "Something strange happened. The stone vanishes in "
            "midair. Maybe something went wrong here or your "
            "target just vanished. Anyways, it's possibly a good "
            "idea to ask a wizard for help...\n");
         return 1;
      }
      notify_fail("You should load the catapult first.\n",
         NOTIFY_ILL_ARG);
      return 0;
   }
   return 0;
}

int ShoveDown(string str)
{
   notify_fail(
      "Shove someone is not yet finished here.\n",
      NOTIFY_ILL_ARG);
   return 0;
}

int JumpDown(string str)
{
   notify_fail("Jump where?\n",NOTIFY_ILL_ARG);
   if(!str) return 0;
   if(!TP)  return 0;
   if(strstr(lower_case(str),"down")!=-1 ||
      strstr(lower_case(str),"tower")!=-1 ||
      strstr(lower_case(str),"ocean")!=-1 ||
      strstr(lower_case(str),"water")!=-1)
   {
      notify_fail("Jumping down from the tower is not possible yet.\n", NOTIFY_ILL_ARG);
      return 0;
   }
   return 0;
}

int LoadCatapult(string str)
{
   string what, item;

   notify_fail("Put what where?\n", NOTIFY_ILL_ARG);
   if(!str) return 0;
   if(!TP)  return 0;
   if(sscanf(lower_case(str),"%s into %s", item, what)==2 ||
      sscanf(lower_case(str),"%s on %s", item, what)==2)
   {
      notify_fail("Put what WHERE?\n", NOTIFY_ILL_ARG);
      if(strstr(what,"catapult")!=-1 ||
         strstr(what,"engine")!=-1 ||
         strstr(what,"machine")!=-1)
      {
         object load;

         notify_fail("Put WHAT on the catapult?\n",NOTIFY_ILL_ARG);
         load=present(item);
         if(load ||
            strstr(item,"stone")!=-1 ||
            strstr(item,"boulder")!=-1 ||
            strstr(item,"rock")!=-1)
         {
            if(catapult_loaded==1)
            {
               notify_fail(
                  "The catapult is already loaded.\n",
                  NOTIFY_ILL_ARG);
               return 0;
            }
            catapult_loaded=1;
            catapult_item="stone";
            msg_write(CMSG_GENERIC,
               "You put "+(load?CAP(NAME(load)):"a stone")+" on the "
               "catapult.\n");
            msg_room(TO,CMSG_ROOM,
               CAP(NAME(TP))+" puts "+(load?CAP(NAME(load)):"a stone")+
               " on the catapult.\n", ({TP,load}) );
            if(load)
            {
               msg_object(load, CMSG_GENERIC,
                  CAP(NAME(TP))+" puts you on the catapult.\n");
               catapult_item=lower_case(NAME(load));
            }
            return 1;
         }
      }
   }
}

int AimCatapult(string str)
{
   string what, where;

   notify_fail("Aim what?\n", NOTIFY_ILL_ARG);
   if(!str) return 0;
   if(!TP)  return 0;
   if(sscanf(lower_case(str),"%s at %s", what, where)==2)
   {
      if(strstr(what,"catapult")!=-1 ||
         strstr(what,"engine")!=-1 ||
         strstr(what,"machine")!=-1)
      {
         object target;

         target=find_living(where);
         if(target)
         {
            if(RNAME(target)==RNAME(TP))
            {
               notify_fail(
                  "You can't aim the catapult at yourself.\n",
                  NOTIFY_ILL_ARG);
               return 0;
            }
            if(catapult_aim!=AIM_OTHER && catapult_target!=where)
            {
               catapult_aim=AIM_OTHER;
               catapult_target=where;
               msg_write(CMSG_GENERIC,
                  "You look at the engine for a moment. Then you turn a "
                  "handle at the base of it. After that you can pull "
                  "the big machine very easy. By looking through a "
                  "little tube with a small cross in it you aim it "
                  "at the general direction of "+CAP(where)+".\n");
               msg_room(TO, CMSG_ROOM,
                  CAP(NAME(TP))+" looks at the engine for a moment. "
                  "Then "+HESHE(TP)+" turns a handle and by looking "
                  "through a small tube, aims the engine toward an "
                  "target, which seems to be very far away.\n",
                  ({TP}) );
               return 1;
            }
            notify_fail("The catapult is already aiming at "+
               CAP(where)+".\n",
               NOTIFY_ILL_ARG);
            return 0;
         }
         if(strstr(where,"ship")!=-1)
         {
            if(catapult_aim!=AIM_SHIP)
            {
               catapult_aim=AIM_SHIP;
               msg_write(CMSG_GENERIC,
                  "You look at the engine for a moment. Then you turn a "
                  "handle at the base of it. After that you can pull "
                  "the big machine very easy. By looking through a "
                  "little tube with a small cross in it you aim it "
                  "directly at an incoming ship.\n");
               msg_room(TO, CMSG_ROOM,
                  CAP(NAME(TP))+" looks at the engine for a moment. "
                  "Then "+HESHE(TP)+" turns a handle and by looking "
                  "through a small tube, aims the engine toward an "
                  "incoming ship.\n",
                  ({TP}) );
               return 1;
            }
            notify_fail(
               "The catapult is already aiming in that direction.\n",
               NOTIFY_ILL_ARG);
            return 0;
         }
         if(strstr(where,"city")!=-1 ||
            strstr(where,"silvere")!=-1)
         {
            if(catapult_aim!=AIM_CITY)
            {
               catapult_aim=AIM_CITY;
               msg_write(CMSG_GENERIC,
                  "You look at the engine for a moment. Then you turn a "
                  "handle at the base of it. After that you can pull "
                  "the big machine very easy. By looking through a "
                  "little tube with a small cross in it you aim it "
                  "directly at the city of Silvere.\n");
               msg_room(TO, CMSG_ROOM,
                  CAP(NAME(TP))+" looks at the engine for a moment. "
                  "Then "+HESHE(TP)+" turns a handle and by looking "
                  "through a small tube, aims the engine toward the "
                  "city of Silvere.\n",
                  ({TP}) );
               return 1;
            }
            notify_fail(
               "The catapult is already aiming in that direction.\n",
               NOTIFY_ILL_ARG);
            return 0;
         }
         if(strstr(where, "harbour")!=-1)
         {
            if(catapult_aim!=AIM_HARBOUR)
            {
               catapult_aim=AIM_HARBOUR;
               msg_write(CMSG_GENERIC,
                  "You look at the engine for a moment. Then you turn a "
                  "handle at the base of it. After that you can pull "
                  "the big machine very easy. By looking through a "
                  "little tube with a small cross in it you aim it "
                  "directly at the harbour of Silvere.\n");
               msg_room(TO, CMSG_ROOM,
                  CAP(NAME(TP))+" looks at the engine for a moment. "
                  "Then "+HESHE(TP)+" turns a handle and by looking "
                  "through a small tube, aims the engine toward the "
                  "harbour of Silvere.\n",
                  ({TP}) );
               return 1;
            }
            notify_fail(
               "The catapult is already aiming in that direction.\n",
               NOTIFY_ILL_ARG);
            return 0;
         }
         if(strstr(where,"tower")!=-1)
         {
            if(catapult_aim!=AIM_TOWER)
            {
               catapult_aim=AIM_TOWER;
               msg_write(CMSG_GENERIC,
                  "You look at the engine for a moment. Then you turn a "
                  "handle at the base of it. After that you can pull "
                  "the big machine very easy. By looking through a "
                  "little tube with a small cross in it you aim it "
                  "directly at the tower on the other side of the "
                  "harbour.\n");
               msg_room(TO, CMSG_ROOM,
                  CAP(NAME(TP))+" looks at the engine for a moment. "
                  "Then "+HESHE(TP)+" turns a handle and by looking "
                  "through a small tube, aims the engine toward the "
                  "tower on the other side of the harbour.\n",
                  ({TP}) );
               return 1;
            }
            notify_fail(
               "The catapult is already aiming in that direction.\n",
               NOTIFY_ILL_ARG);
            return 0;
         }
         if(strstr(where,"fortress")!=-1 ||
            strstr(where,"hill")!=-1)
         {
            if(catapult_aim!=AIM_FORTRESS)
            {
               catapult_aim=AIM_FORTRESS;
               msg_write(CMSG_GENERIC,
                  "You look at the engine for a moment. Then you turn a "
                  "handle at the base of it. After that you can pull "
                  "the big machine very easy. By looking through a "
                  "little tube with a small cross in it you aim it "
                  "toward the fortress on the hill to the north.\n");
               msg_room(TO, CMSG_ROOM,
                  CAP(NAME(TP))+" looks at the engine for a moment. "
                  "Then "+HESHE(TP)+" turns a handle and by looking "
                  "through a small tube, aims the engine toward the "
                  "fortress on the hill at the north.\n",
                  ({TP}) );
               return 1;
            }
            notify_fail(
               "The catapult is already aiming in that direction.\n",
               NOTIFY_ILL_ARG);
            return 0;
         }
         notify_fail("Aim catapult at what?\n", NOTIFY_ILL_ARG);
         return 0;
      }
      notify_fail("Aim WHAT?\n", NOTIFY_ILL_ARG);
      return 0;
   }
}

string CheckStones()
{
   string desc;

   desc=
      "The stones are used for the catapult, in case someone "
      "uninvited arrives. You can put them on the catapult and "
      "then fire them at the ship. ";
   if(available_stones)
      desc+="There are "+itoa(available_stones)+" lying there.\n";
   else desc+=
      "Unfortunately, there are no stones here at the moment. "
      "Maybe you can go and get some?\n";
   return desc;
}

string CheckCatapult()
{
   string desc;

   desc="The catapult is a large, wooden engine. ";
   switch(catapult_aim)
   {
      case AIM_CITY: desc+="It points toward the city of Silvere.";
                     break;
      case AIM_TOWER: desc+="It points toward the south tower.";
                     break;
      case AIM_HARBOUR: desc+="It points at the harbour of Silvere.";
                        break;
      case AIM_SHIP: desc+="It points at the sea directly at an "
                           "incoming ship.";
                     break;
      case AIM_FORTRESS: desc+="It points at the fortress to the "
                               "north.\n";
                         break;
      case AIM_OTHER: desc="It points toward a strange place.\n"; break;
      default:       desc+="It points toward the open sea."; break;
   }
   desc+=
      " A wheel is attached to some kind of frame on which the "
      "catapult is sitting. A rope leads from the engine to a ring "
      "on the ground. A small handle is attached on the engine. ";
   if(catapult_loaded)
   {
      if(catapult_item=="stone")
         desc+=
            "The catapult is loaded with a large rock and ready to "
            "fire. ";
         else
            desc+=
               "The catapult is loaded with "+CAP(catapult_item)+
               " and ready to fire.\n";
   }
   else desc+="The catapult is empty. ";
   switch(available_stones)
   {
      case 0: break;
      case 1..5:  desc+=
                     "A small heap of stones is lying next to the "
                     "catapult.";
                   break;
      case 6..15: desc+=
                     "There are a few stones making a sizeable "
                     "heap next to the catapult.";
                  break;
      default: desc+=
                  "Lots of stones are placed on a big heap next to "
                  "the catapult.";
   }
   return desc+"\n";
}

void reset()
{
   ::reset();
   catapult_aim=0;
   catapult_target="";
   catapult_item="";
   if(catapult_loaded)
   {
      msg_room(TO,CMSG_ROOM,
         "Suddenly the handle at the ring on the ground moves and "
         "the catapult shoots the boulder high into the air toward "
         "the ocean.\n");
      catapult_loaded=0;
   }
   if(available_stones<10)
   {
      msg_room(TO,CMSG_ROOM,
         "A small group of workers appears and place some boulders "
         "next to the catapult.\n");
      available_stones=10;
   }
}

varargs void create()
{
   ::create();
   Set(P_INDOORS,0);
   Set(P_INT_SHORT,"On the tower");
   Set(P_INT_LONG,
      "This is the top of the tower. You have a great view over the "
      "sea. A large catapult is standing here aiming toward the sea. "
      "South of you is an opening in the ground, where you can reach "
      "the lower levels of the tower. A small tent can be found to the "
      "east.\n");

   Set(P_INT_WIZMSG,
" East:  To a tent\n"
" South: To the platform and the stairs\n");

   AddDetail( ({"tower","top of the tower","towertop"}),
      "You are standing here at the moment. Right in front of you at "
      "the battlements is a large, wooden catapult, aiming toward the "
      "open sea. To the south is a platform and stairs, which are "
      "leading down to the lower levels. To the east is a small tent "
      "which serves as a shelter for the guards here.\n");

   AddDetail( ({"here","place"}),
      "That's the place, you are standing at the moment. If you want to "
      "find out more about it, just have a look.\n");

   AddDetail( ({"sea","ocean","water","gulf of silvere"}),
      "The Gulf of Silvere lies just to the west. It is a part of the "
      "Sea of Shamyra and runs along the coast of Silvere to the north "
      "and south.\n");

   AddDetail( ({"shamyra","sea of shamyra"}),
      "The Sea of Shamyra is a large ocean to the west.\n");

   AddDetail( ({"coast","coast of silvere"}),
      "The coast runs along the city of Silvere to the north and west. "
      "A large fortress is sitting on the top of a hill directly to the "
      "north. The coast continues to the south, but you can't see much "
      "from here.\n");

   AddDetail( ({"silvere","city"}),
      "The city of Silvere is to the east, but from this place you "
      "can't see very much of it, because the tent to the east is "
      "blocking most of it. You see the citywall of Silvere and the "
      "roofs of some of the higher buildings in the city.\n");

   AddDetail( ({"wall","citywall","citywall of silvere"}),
      "The wall surrounds the city of Silvere. It was built a long time "
      "ago to keep unwanted guests out of the city.\n");

   AddDetail( ({"roof","roofs"}),
      "The roofs of the buildings are made from some kind of red "
      "tiles.\n");

   AddVItem(
   ([ P_IDS:({"tile","tiles"}),
      P_ADS:({"red"}),
      P_LONG:
         "The tiles are bright red, when the sun shines down on them. "
         "They are building the roofs of some of the buildings, you can "
         "see from this place.\n",
   ]) );

   AddVItem(
   ([ P_IDS:({"building","buildings"}),
      P_ADS:({"high","higher"}),
      P_LONG:
         "The buildings are a part of Silvere. They are somewhat higher "
         "so that you can see them from here. Maybe they are important, "
         "because they are so high? Should be interesting to visit them "
         "later.\n",
   ]) );

   AddDetail( ({"view","great view"}),
      "The view out on the sea is astonishing. The Gulf of Silvere is "
      "just to the west and ships are sailing there.\n");

   AddDetail( ({"ship","ships"}),
      "There are some ships sailing on the ocean. Some are sailing "
      "toward Silvere and some are sailing away from the city.\n");

   AddVItem(
   ([ P_IDS:({"catapult"}),
      P_ADS:({"wooden","big","huge"}),
      P_LONG:SF(CheckCatapult),
   ]) );

   AddVItem(
   ([ P_IDS:({"wheel"}),
      P_ADS:({"small","wooden"}),
      P_LONG:
         "The small wheel is attached to the frame, where the engine "
         "sits. A small chain is running from it into the frame. It "
         "seems that you can aim the catapult at a target with it...\n",
   ]) );

   AddVItem(
   ([ P_IDS:({"handle"}),
      P_ADS:({"wooden","small"}),
      P_LONG:
         "A small handle is sitting at the ground next to a small ring. "
         "It seems that it can be pulled...\n",
   ]) );

   AddVItem(
   ([ P_IDS:({"ring"}),
      P_ADS:({"small","iron"}),
      P_LONG:
         "The ring is made from iron and is holding a rope. The ring is "
         "sitting on the ground next to a handle.\n",
   ]) );

   AddVItem(
   ([ P_IDS:({"boulder","boulders","stone","stones"}),
      P_ADS:({"heavy"}),
      P_LONG:SF(CheckStones),
   ]) );

   AddDetail( "opening",
      "The opening can be found just south of here. A small wooden "
      "frame is build on top of it. Next to the opening are stairs, "
      "leading down into the tower.\n");

   AddDetail( ({"stair","stairs"}),
      "To the south are some stairs next to an opening in the ground. "
      "The stairs are leading down into the tower.\n");

   AddVItem(
   ([ P_IDS:({"frame"}),
      P_ADS:({"small","wooden"}),
      P_LONG:
         "There is a small wooden frame placed on top of the opening. "
         "Ropes are leading from the top of the frame down into the "
         "opening. If you want to find out more about it, go closer "
         "and look again.\n",
   ]) );

   AddDetail( ({"ground","floor"}),
      "The ground is made out of large beams of wood. There is no "
      "dirt or dust here but instead you can see an opening to the "
      "south. Right in front of you is a large catapult standing "
      "at the battlements of the tower, aiming toward the ocean.\n");

   AddVItem(
   ([ P_IDS:({"level","levels"}),
      P_ADS:({"lower"}),
      P_LONG:
         "The levels below can be reached with the stairs to the "
         "south. If you want to know more about them, just go "
         "there and have a look.\n",
   ]) );

   AddVItem(
   ([ P_IDS:({"tent","shelter"}),
      P_ADS:({"small"}),
      P_LONG:
         "The small tent can be found to the east. You are a little "
         "bit too far to see many details, so if you want to find out "
         "more about it, just go there and look at it.\n",
   ]) );

   AddDetail( "battlements",
      "The battlements are standing directly west of you. They are "
      "about 4 feet high and prevent you from jumping down into the "
      "water (which could be dangerous for you). In front of the "
      "battlements here is a large catapult which aims at the sea.\n");

   AddDetail( "north",
      "To the north is the end of the tower. The battlements are "
      "blocking the way. On the other side you have a great look on "
      "the landscape there. A large hill can be seen there with a "
      "huge fortress. A road leads down from the fortress to the "
      "city. The coast runs to the north along a beautiful beach. "
      "There are also lots of trees, which build a rather small "
      "forest at the base of the hill.\n");

   AddDetail( "south",
      "To the south you can see an opening in the floor of the "
      "tower. Some stairs leadto the lower levels of the tower. "
      "At the other side of the harbour is the southern tower, "
      "but the battlements are blocking most of your view. So, "
      "if you want to look, go there and try again.\n");

   AddDetail( "west",
      "The Gulf of Silvere lies just to the west. It is part of the "
      "Sea of Shamyra and runs along the coast of Silvere to the "
      "north and south. Lots of ships are sailing there, aiming "
      "toward the harbour or away from it.\n");

   AddDetail( "east",
      "To the east is a small tent. Over the battlements you see some "
      "parts of Silvere, but the tent blocks most of your view in that "
      "direction.\n");

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
         "The hill can be found directly to the north behind the "
         "tower. There is a huge fortress on top of it. At the "
         "base of the tower is a small forest which opens on a "
         "long beach at the coast.\n",
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

   // jumping business
   AddRoomCmd("jump",   SF(JumpDown));
   AddRoomCmd("shove",  SF(ShoveDown));

   // Catapult handling... loading, aiming and firing
   // the put command has to be added instead of load because of the
   // wizard load-cmd... everything works fine, if a wizard can use
   // put instead of load.. then he will get the right error-msgs...
   AddRoomCmd( ({"put","load"}), SF(LoadCatapult));
   AddRoomCmd("aim",             SF(AimCatapult));
   AddRoomCmd("pull",            SF(PullHandle));

   Set(P_INT_MAP,"harbour");
   Set(P_REGION, REGION_CITY|REGION_HARBOUR);
   Set(P_COORDINATES, ({ ({ -290,-10,20 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,"You run into the battlements.\n");
   AddExit("south",SIL_HARBOUR("ntower9"));
   AddExit("east", SIL_HARBOUR("ntower11"));

   available_stones=10;
   catapult_loaded=0;
   catapult_aim=0;
}

// The top of the tower. Stairs are leading down
// created:          Sonic [26-May-1997]
// last changed:     Sonic [05-Jul-1997] added regions/coordinates
//                   Sonic [03-Aug-1997] added description/details
//                   Sonic [11-Aug-1997] added pull/push-commands

// TODO: add handling of boulders, if available

#include <silvere.h>
#include <properties.h>
#include <coordinates.h>
#include <msgclass.h>
#include <regions.h>
#include <moving.h>
#include <macros.h>
#include <rooms.h>
inherit BASEROOM;

int rHandle, rBoulder;

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
      // TODO: Check for jumping skill.
      // TODO: total fail: You hit a underwater stone and die
      // TODO: clumsy:     You hit the water and get injured
      // TODO: success:    You jump into the water and start swimming
      // TODO: I possibly have to do some thinking about that, but
      // TODO: it's a start ;-)
      TP->move(SIL_HARBOUR("nwater2"),M_SPECIAL,
         ({ "jumps over the battlements into the water of the harbour",
            "jumps down from the tower",
            "jump down from the tower"
         }) );
      return 1;
   }
   return 0;
}

int QueryBoulder()   {  return rBoulder;  }

int SetBoulder(int nr)
{
   if(!nr) nr=0;
   rBoulder=nr;
   return rBoulder;
}

int AddBoulder()
{
   rBoulder++;
   return rBoulder;
}


string Boulder_Amount()
{
   string desc;

   switch(rBoulder)
   {
      case 1:     desc="A boulder lies"; break;
      case 2..20: desc=CAP(itoa(rBoulder))+" boulders are lying"; break;
      default:    desc="Lots of boulders are lying"; break;
   }
   return desc;
}

string CheckBoulders()
{
   string desc;

   if(!rBoulder) return 0;
   desc=
      "The boulders are large rocks. @@Boulder_Amount@@ on the platform "
      "here.\n";
   return process_string(desc);
}

int QueryHandle()  {  return rHandle;   }
int SetHandle(int nr)
{
   if(!nr) nr=0;
   rHandle=nr;
   return rHandle;
}

int move_platform(object obj)
{
   obj->SetPlatform(1);
   rBoulder=({int})obj->QueryBoulders();
   msg_room(obj,CMSG_ROOM,
      "The platform moves upwards and fills the opening in the "
      "ceiling.\n");
   msg_room(TO,CMSG_ROOM,"The platform arrives from below.\n");
   return 1;
}

int move_platform2(object obj)
{
   obj->SetPlatform(0);
   msg_room(obj,CMSG_ROOM,
      "The platform moves downwards and reveals an opening in the "
      "ceiling.\n");
   msg_room(TO,CMSG_ROOM,
      "The wheels stop, as the platform arrives below.\n");
   return 1;
}

int PullFunction(string str)
{
   notify_fail("Pull what?\n",NOTIFY_ILL_ARG);
   if(!str) return 0;
   if(!TP)  return 0;
   if(strstr(lower_case(str),"rope")!=-1)
   {
      mapping exits;
      mixed ekeys, edesc;

      exits=({mapping})TO->Query(P_EXITS);
      if(exits)
      {
         int a;

         ekeys=m_indices(exits);
         edesc=m_values(exits);
         a=member(ekeys,"down");
         if(a!=-1)
         {
            object room;

            room=load_object(edesc[a]);
            if(room)
            {
               if(rHandle==1)
               {
                  room->SetPlatform(3);
                  msg_write(CMSG_GENERIC,"You pull at the rope.\n");
                  msg_room(TO,CMSG_ROOM,CAP(NAME(TP))+
                     " pulls at the rope.\n",({TP}) );
                  msg_room(TO,CMSG_ROOM,
                     "There are some noises from the opening. There "
                     "are also some wheels on the frame, which are "
                     "moving a rope up from below.\n\n");
                  msg_room(room,CMSG_ROOM,
                     "The platform moves upwards.\n");
                  call_out("move_platform",3,room);
                  return 1;
               }
               else
               {
                  room->SetPlatform(2);
                  msg_write(CMSG_GENERIC,"You pull at the rope.\n");
                  msg_room(TO,CMSG_ROOM,CAP(NAME(TP))+
                     " pulls at the rope.\n",({TP}) );
                  msg_room(TO,CMSG_ROOM,
                     "There are some noises from the frame atop the "
                     "platform. Then the platform is suddenly moving "
                     "down to the room below.\n\n");
                  msg_room(room,CMSG_ROOM,
                     "The platform moves downwards.\n");
                  call_out("move_platform2",3,room);
                  return 1;
               }
            }
         }
         notify_fail(
            "Something went wrong here. Please notify a wizard about "
            "strange behaviours at this place.\n", NOTIFY_NOT_VALID);
         return 0;
      }
   }
   if(strstr(lower_case(str),"handle")!=-1)
   {
      if(rHandle==1)
      {
         msg_write(CMSG_GENERIC,
            "You pull at the handle. It moves upward and from the "
            "wheels you hear a click.\n");
         msg_room(TO,CMSG_ROOM,CAP(NAME(TP))+
            " pulls the handle. It moves upward and from the wheels "
            "at the frame you hear a click.\n", ({TP}) );
         SetHandle(0);
         return 1;
      }
      msg_write(CMSG_GENERIC,
         "The handle doesn't move.\n");
      msg_room(TO,CMSG_ROOM,CAP(NAME(TP))+
         " pulls at the handle, but nothing happens.\n", ({TP}) );
      return 1;
   }
   return 0;
}

int PushFunction(string str)
{
   notify_fail("Push what?\n",NOTIFY_ILL_ARG);
   if(!str) return 0;
   if(!TP)  return 0;
   if(strstr(lower_case(str),"rope")!=-1)
   {
      msg_write(CMSG_GENERIC,
         "You push the rope, but nothing happens.\n");
      msg_room(TO,CMSG_ROOM,CAP(NAME(TP))+
         " pushes the rope, but except that "+HESHE(TP)+" looks rather "
         "silly nothing happens.\n", ({TP}) );
      return 1;
   }
   if(strstr(lower_case(str),"handle")!=-1)
   {
      if(rHandle==0)
      {
         msg_write(CMSG_GENERIC,
            "You push at the handle. It moves downward and from the "
            "wheels you hear a click.\n");
         msg_room(TO,CMSG_ROOM,CAP(NAME(TP))+
            " pushes the handle. It moves downward and from the wheels "
            "at the frame you hear a click.\n", ({TP}) );
         SetHandle(1);
         return 1;
      }
      msg_write(CMSG_GENERIC,
         "The handle doesn't move.\n");
      msg_room(TO,CMSG_ROOM,CAP(NAME(TP))+
         " pushes at the handle, but nothing happens.\n", ({TP}) );
      return 1;
   }
}

string CheckHandle()
{
   string desc;

   desc=
      "The handle is attached at the frame above the opening. It seems "
      "that it has something to do with the small wheels on top of the "
      "frame, where the rope leads through. ";
   if(rHandle==0) return desc+"It points upwards.\n";
   else return desc+"It points downwards.\n";
}

string CheckPlatform()
{
   mapping exits;
   mixed keys, desc;

   exits=({mapping})TO->Query(P_EXITS);
   if(exits)
   {
      int a;

      keys=m_indices(exits);
      desc=m_values(exits);
      if((a=member(keys,"down"))!=-1)
      {
         object room2;
         string ddesc;
         int b;

         ddesc="";
         room2=load_object(desc[a]);
         if(room2)
         {
            b=({int})room2->QueryPlatform();
            switch(b)
            {
               case 0: return 0; break;
               case 1:
                  ddesc+=
                     "There is a platform at the opening. It is made "
                     "out of wood.";
                     if(rBoulder)
                     {
                        if(rBoulder==1) ddesc+=
                           " A single boulder is lying there.";
                        else ddesc+=" "+CAP(itoa(rBoulder))+" "
                           "boulders are lying there.";
                        ddesc+="\n";
                     }
                  break;
               case 2:
                  ddesc+=
                     "There is a platform at the opening. It is made "
                     "out of wood and moves slowly down to the room "
                     "below.\n";
                  break;
               case 3:
                  ddesc+=
                     "There is a platform at the opening. It is made "
                     "out of wood and moves slowly up from the room "
                     "below.\n";
                  break;
               default:
                  ddesc+=
                     "The opening is filled with some kind of fog, "
                     "which blocks your view on the platform. Obviously "
                     "something went wrong here. Please notify one of "
                     "the wizards for some help.\n";
                  break;
            }
            return ddesc;
         }
      }
   }
   return
      "Something went wrong here. Suddenly the opening is filled with "
      "some kind of fog, that prevents any look at the opening. The "
      "fog could be dangerous or maybe not, so better ask one of the "
      "wizards for help.\n";
}

string CheckOpening()
{
   mapping exits;
   mixed keys, desc;

   exits=({mapping})TO->Query(P_EXITS);
   if(exits)
   {
      int a;

      keys=m_indices(exits);
      desc=m_values(exits);
      if((a=member(keys,"down"))!=-1)
      {
         object room2;
         string ddesc;
         int b;

         ddesc=
            "An opening in the floor leads down. A wooden frame is "
            "placed above it with some ropes leading down. ";
         room2=load_object(desc[a]);
         if(room2)
         {
            b=({int})room2->QueryPlatform();
            switch(b)
            {
               case 0:
                  ddesc+=
                     "You see a small platform on the floor of the room "
                     "below.\n";
                  break;
               case 1:
                  ddesc=
                  "The opening is blocked with the platform.\n";
               break;
               case 2:
                  ddesc=
                     "There is a platform at the opening, which moves "
                     "slowy down to another room.\n";
                  break;
               case 3:
                  ddesc=
                     "A platform moves slowly up from the room below.\n";
                  break;
               default:
                  ddesc=
                     "The opening is leading down. If you think, you "
                     "will survive it, you can jump down, but it is "
                     "easier to use the stairs.\n";
                  break;
            }
            return ddesc;
         }
      }
   }
   return
      "Something went wrong here. Suddenly the opening is filled with "
      "some kind of fog, that prevents any look at the opening. The "
      "fog could be dangerous or maybe not, so better ask one of the "
      "wizards for help.\n";
}

string CheckFrame()
{
   mapping exits;
   mixed keys,desc;
   string ddesc;

   ddesc=
      "A wooden frame is placed on top of the opening. It is high "
      "enough for a human to stand below it, if he can find something "
      "to place his feet on. At the frame is a handle, attached to some "
      "wheels at the top of frame. ";
   exits=({mapping})TO->Query(P_EXITS);
   if(exits)
   {
      int a;

      keys=m_indices(exits);
      desc=m_values(exits);
      if((a=member(keys,"down"))!=-1)
      {
         object room2;

         room2=load_object(desc[a]);
         if(room2)
         {
            int b;

            b=({int})room2->QueryPlatform();
            switch(b)
            {
               case 0:
                  ddesc+=
                     "A small platform is below the opening. Ropes are "
                     "leading down from the top of the frame to the "
                     "platform below.\n";
                  break;
               case 1:
                  ddesc+=
                     "A small platform fills the opening. Ropes are "
                     "leading from the platform up to the top of the "
                     "frame.\n";
                  break;
               case 2:
                  ddesc+=
                     "A small platform hangs on some ropes and is "
                     "moving slowly down to the room below.\n";
                  break;
               case 3:
                  ddesc+=
                     "A small platform hangs on some ropes and is "
                     "moving slowly up from the room below.\n";
                  break;
               default: break;
            }
         }
      }
   }
   else ddesc+=
      "A strange fog fills the opening below the frame, that prevents "
      "looking down. It shouldn't be there, so better call a wizard "
      "and ask for some help.\n";
   return ddesc;
}

varargs void create()
{
   ::create();
   Set(P_INDOORS,0);
   Set(P_INT_SHORT,"On top of the tower");
   Set(P_INT_LONG,
      "This is the top of the tower. You have a great view over the "
      "whole harbour, some parts of the city and on the ocean from "
      "here. Stairs are leading down to the lower levels of the "
      "building and a wooden frame is place above an opening. To the "
      "north is a large catapult, which aims toward the open sea. "
      "Directly to the east is a large mirror, which points south.\n");

   Set(P_INT_WIZMSG,
" Down:  To the second level of the tower.\n"
" East:  To a mirror...\n"
" North: To the catapult\n");

   AddVItem(
   ([ P_IDS:({"floor","ground"}),
      P_LONG:
         "The floor is made out of large beams of wood. There is no "
         "dirt or dust here but instead you can see an opening with "
         "a wooden frame on top of it. Stairs are leading down next "
         "to it.\n",
   ]) );

   AddDetail( ({"north tower", "top","top of the tower","place","here",
                "room","building"}),
      "That's the place you are standing at the moment. If you want to "
      "find out more, just have a look around.\n");

   AddDetail( ({"silvere","city of silvere","some parts of the city",
                "parts of the city","cityparts","citypart"}),
      "The city of silvere is to the east, but from here the mirror "
      "blocks parts of your view. You see the wall which surrounds "
      "Silvere and some buildings inside the wall.\n");

   AddDetail( "buildings",
      "Most of that buildings are of smaller size, but some of them "
      "are very impressive.\n");

   AddDetail( ({"wall","city wall","citywall"}),
      "The wall surrounds the city of Silvere. It was built to keep "
      "unwanted guests out of the city a long time ago.\n");

   AddVItem(
   ([ P_IDS:({"stair","stairs"}),
      P_ADS:({"wooden"}),
      P_LONG:
         "The wooden stairs leads down to the lower levels of the "
         "tower. Next to the stairs is an opening with a wooden "
         "frame on top of if.\n",
   ]) );

   AddVItem(
   ([ P_IDS:({"level","levels"}),
      P_ADS:({"lower","other"}),
      P_LONG:
         "The levels below can be reached with the stairs. If you want "
         "to know more about them, just go there and have a look.\n",
   ]) );

   AddDetail("opening",SF(CheckOpening));

   AddVItem(
   ([ P_IDS:({"platform"}),
      P_ADS:({"wooden"}),
      P_LONG:SF(CheckPlatform),
   ]) );

   AddVItem(
   ([ P_IDS:({"frame"}),
      P_ADS:({"wooden"}),
      P_LONG:SF(CheckFrame),
   ]) );

   AddVItem(
   ([ P_IDS:({"wheel","wheels"}),
      P_ADS:({"wooden"}),
      P_LONG:
         "The wheels are placed on top of the frame. A rope leads "
         "through them and back to the ground and some other ropes "
         "are leading down to the platform.\n",
   ]) );

   AddVItem(
   ([ P_IDS:({"rope","ropes"}),
      P_ADS:({"long"}),
      P_LONG:
         "The rope is lying on the ground. It leads up to the top of "
         "the frame to some kind of wheels.\n",
   ]) );

   AddVItem(
   ([ P_IDS:({"handle"}),
      P_ADS:({"wooden"}),
      P_LONG:SF(CheckHandle),
   ]) );

   AddVItem(
   ([ P_IDS:({"catapult","machine"}),
      P_ADS:({"large","wooden"}),
      P_LONG:
         "The catapult is a big wooden machine to the north. "
         "If you want to find out more about it, just go there "
         "and have a look at it.\n",
   ]) );
   AddDetail( ({"harbour","harbour of silvere","whole harbour"
                "harbour area"}),
      "You see a small bay just outside the city of silvere. "
      "Some houses and two quays are forming the harbour inside "
      "a small bay. The towers at the western ends of the quays "
      "protect the harbour from unwanted quests.\n");

   AddDetail( ({"house","houses"}),
      "Outside the wall of Silvere you see a few houses. They are "
      "standing directly at the wall with a street leading to the "
      "harbour area.\n");

   AddDetail( ({"quay","quays","north quay","south quay"}),
      "The quays are the areas of the harbour, where ships are "
      "docking. At the western end of each quay is a tower.\n");

   AddDetail( ({"ocean","sea","open sea","gulf of silvere"}),
      "The Gulf of Silvere lies just to the east. It is part of the "
      "Sea of Shamyra and runs along the coast of Silvere to the "
      "north and south.\n");

   AddDetail( ({"shamyra","sea of shamyra"}),
      "The Sea of Shamyra can be found to the west. It continues "
      "there from the harbour here to the horizon. It's a stunning "
      "view from here.\n");

   AddDetail( ({"boulder","boulders"}),SF(CheckBoulders));

   AddVItem(
   ([ P_IDS:({"mirror"}),
      P_ADS:({"signal","large"}),
      P_LONG:
         "The signal mirror can be found to the east. If you want to "
         "find out more about it, just go east and look at it.\n",
   ]) );

   AddRoomCmd("pull",   SF(PullFunction));
   AddRoomCmd("push",   SF(PushFunction));
   AddRoomCmd("jump",   SF(JumpDown));

   Set(P_INT_MAP,"harbour");
   Set(P_REGION, REGION_CITY|REGION_HARBOUR);
   Set(P_COORDINATES, ({ ({ -290,0,20 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,"You run into the battlements.\n");
   AddExit("down", SIL_HARBOUR("ntower7"));
   AddExit("north",SIL_HARBOUR("ntower10"));
   AddExit("east", SIL_HARBOUR("ntower12"));
}

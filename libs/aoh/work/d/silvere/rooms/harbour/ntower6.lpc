// A small room for the guards. Noone is here though.
// created:          Sonic [26-May-1997]
// last changed:     Sonic [05-Jul-1997] added regions/coordinates
//                   Sonic [29-Jul-1997] added description/details

#include <silvere.h>
#include <properties.h>
#include <coordinates.h>
#include <msgclass.h>
#include <regions.h>
#include <moving.h>
#include <macros.h>
#include <rooms.h>
inherit BASEROOM;

mixed chairs;
int cards, locker_closed, locker_locked, bed_clean;

int GetThings(string str)
{
   object obj;

   notify_fail("Take what?\n",NOTIFY_ILL_ARG);
   if(!str) return 0;
   if(!TP)  return 0;
   if(strstr(lower_case(str),"card")!=-1)
   {
      if(cards==1)   /* cards are already gone */
      {
         notify_fail("You don't find cards to take.\n",NOTIFY_ILL_ARG);
         return 0;
      }
      obj=clone_object(OBJ("silvere/cards"));
      if(obj)
      {
         if(({int})obj->move(TP,M_GET)==1)
         {
            msg_write(CMSG_GENERIC,"You take the cards from the table.\n");
            cards=1;
            return 1;
         }
         msg_write(CMSG_GENERIC,"The cards vanish, as you touch them.\n");
         cards=1;
         return 1;
      }
      notify_fail("There are no cards you could take.\n",NOTIFY_NOT_OBJ);
      return 0;
   }
}

int CleanBed(string str)
{
   notify_fail("Clean what?\n",NOTIFY_ILL_ARG);
   if(!str) return 0;
   if(!TP)  return 0;
   if(strstr(lower_case(str),"bed")!=-1)
   {
      object key;

      if(bed_clean==1)
      {
         notify_fail(
            "The bed is already clean. There is no need to clean it "
            "twice or more.\n",NOTIFY_ILL_ARG);
         return 0;
      }
      msg_room(TO,CMSG_ROOM,CAP(NAME(TP))+" cleans one of the bed.\n",
         ({TP}) );
      msg_write(CMSG_GENERIC,
         "You take everything from the bed and drop it on the ground. "
         "Then you put the mattress back on the bed and cover it with "
         "the more or less white linen. On top of that you put the "
         "pillow and the blanket.\n");
      bed_clean=1;
      TP->SetExplored();
      key=clone_object("/std/thing");
      if(key)
      {
         key->Set(P_SHORT,"a small key");
         key->Set(P_LONG,"This is a small key.\n");
         key->Set(P_IDS,({"key","ntlkey"}) );
         key->Set(P_ADS,({"small"}) );
         key->Set(P_WEIGHT,50);
         key->Set(P_VALUE,5);
         if(({int})key->move(TP,M_GET)!=ME_OK)
         {
            msg_write(CMSG_GENERIC,
               "A small key lies on the ground. It seems, that it was "
               "hidden in the bed.\n");
            return 1;
         }
         msg_write(CMSG_GENERIC,
            "You see a small key lying on the floor, which you take.\n");
         return 1;
      }
      return 1;
   }
}

int LockLocker(string str)
{
   notify_fail("Lock what?\n",NOTIFY_ILL_ARG);
   if(!str) return 0;
   if(!TP)  return 0;
   if(strstr(lower_case(str),"locker")!=-1)
   {
      if(!present("ntlkey",TP))
      {
         notify_fail("You need a key to lock the locker.\n",
            NOTIFY_ILL_ARG);
         return 0;
      }
      if(locker_closed==0)
      {
         msg_write(CMSG_GENERIC,"You close the locker.\n");
         msg_room(TO,CMSG_ROOM,CAP(NAME(TP))+" closes the locker.\n",
            ({TP}) );
         locker_closed=1;
      }
      if(locker_locked==0)
      {
         msg_write(CMSG_GENERIC,"You lock the locker.\n");
         msg_room(TO,CMSG_ROOM,CAP(NAME(TP))+" locks the locker.\n",
            ({TP}) );
         locker_locked=1;
         return 1;
      }
      notify_fail("The locker is already locked.\n",NOTIFY_ILL_ARG);
      return 0;
   }
}

int UnlockLocker(string str)
{
   notify_fail("Unlock what?\n",NOTIFY_ILL_ARG);
   if(!str) return 0;
   if(!TP)  return 0;
   if(strstr(lower_case(str),"locker")!=-1)
   {
      if(!present("ntlkey",TP))
      {
         notify_fail("You need a key to unlock the locker.\n",
            NOTIFY_ILL_ARG);
         return 0;
      }
      if(locker_locked==1)
      {
         msg_write(CMSG_GENERIC,"You unlock the locker.\n");
         msg_room(TO,CMSG_ROOM,CAP(NAME(TP))+" unlocks the locker.\n",
            ({TP}) );
         locker_locked=0;
         return 1;
      }
      notify_fail("The locker is not locked.\n",NOTIFY_ILL_ARG);
      return 0;
   }
}

int OpenLocker(string str)
{
   notify_fail("Open what?\n",NOTIFY_ILL_ARG);
   if(!str) return 0;
   if(!TP)  return 0;
   if(strstr(lower_case(str),"locker")!=-1)
   {
      if(!present("ntlkey",TP))
      {
         notify_fail("You need a key to open the locker.\n",
            NOTIFY_ILL_ARG);
         return 0;
      }
      if(locker_locked==1)
      {
         msg_write(CMSG_GENERIC,"You unlock the locker.\n");
         msg_room(TO,CMSG_ROOM,CAP(NAME(TP))+" unlocks the locker.\n",
            ({TP}) );
         locker_locked=0;
      }
      if(locker_closed==1)
      {
         msg_write(CMSG_GENERIC,"You open the locker.\n");
         msg_room(TO,CMSG_ROOM,CAP(NAME(TP))+" opens the locker.\n",
            ({TP}) );
         locker_closed=0;
         return 1;
      }
      notify_fail("The locker is already open.\n",NOTIFY_ILL_ARG);
      return 0;
   }
}

int CloseLocker(string str)
{
   notify_fail("Close what?\n",NOTIFY_ILL_ARG);
   if(!str) return 0;
   if(!TP)  return 0;
   if(strstr(lower_case(str),"locker")!=-1)
   {
      if(locker_closed==0)
      {
         msg_write(CMSG_GENERIC,"You close the locker.\n");
         msg_room(TO,CMSG_ROOM,CAP(NAME(TP))+" closes the locker.\n",
            ({TP}) );
         locker_closed=1;
         return 1;
      }
      notify_fail("The locker is already closed.\n",NOTIFY_ILL_ARG);
      return 0;
   }
}

int SitDown(string str)
{
   notify_fail("Sit on what?\n",NOTIFY_ILL_ARG);
   if(!str) return 0;
   if(!TP) return 0;
   if(strstr(lower_case(str),"chair")!=-1)
   {
      if(sizeof(chairs)==4)
      {
         msg_write(CMSG_GENERIC,
            "All the chairs are used at the moment. It looks as if you "
            "have to wait for a moment.\n");
         if(!({int})TP->Query(P_INVIS))
            msg_room(TO,CMSG_ROOM,CAP(NAME(TP))+
               " tries to sit on a chair, but they are all used.\n",
               ({TP }) );
         return 1;
      }
      if(member(chairs, RNAME(TP))!=-1)
      {
         msg_write(CMSG_GENERIC,
            "You already sit on the chair, don't you remember?\n");
         return 1;
      }
      msg_write(CMSG_GENERIC, "You sit on a chair.\n");
      if(!({int})TP->Query(P_INVIS))
         msg_room(TO,CMSG_ROOM,CAP(NAME(TP))+
            " sits on a chair.\n",
            ({TP}) );
      chairs+=({ RNAME(TP) });
      if(sizeof(chairs)==4)
         msg_room(TO,CMSG_ROOM,"The chairs are all used now.\n");
      return 1;
   }
}

int StandUp(string str)
{
   notify_fail("Stand up from what?\n",NOTIFY_ILL_ARG);
   if(!str) return 0;
   if(!TP) return 0;
   if(strstr(lower_case(str),"chair")!=-1)
   {
      if(member(chairs, RNAME(TP))==-1)
      {
         msg_write(CMSG_GENERIC,
            "Why do you want to stand up from a chair? You don't sit "
            "on it.\n");
         return 1;
      }
      chairs-=({RNAME(TP) });
      msg_write(CMSG_GENERIC,"You stand up from the chair.\n");
      if(!({int})TP->Query(P_INVIS))
         msg_room(TO,CMSG_ROOM,CAP(NAME(TP))+
            " stands up from a chair.\n",
            ({TP}) );
      return 1;
   }
}

string CheckLocker()
{
   string desc;

   desc=
      "The locker is used by the guards to put their private items "
      "inside, while they are on duty. ";
   if(locker_closed)
   {
      desc+="It is closed";
      if(locker_locked) desc+=" and locked.\n";
      else desc+=".\n";
   }
   else desc+="It is opened, but empty.\n";
   return desc;
}

string CheckTable()
{
   string desc;

   desc=
      "The table is made out of wood and looks quite old. Several "
      "chairs are standing around it.";
   if(cards==0) return
      desc+" On top of the table you see some cards.\n";
   else return desc+"\n";
}

string CheckCards()
{
   if(cards==0) return
      "The cards are just lying on the table. It seems, that somebody "
      "just dropped them there.\n";
   else return 0;
}

mixed CheckBed()
{
   string desc1, desc2;

   desc1=
      "Two beds are standing at the eastern wall. They are made out "
      "of wood. One of them is used by a guard, who seems to sleep. "
      "At least he doesn't move.\n";

   desc2=desc1;
   if(bed_clean==0) desc2+=
      "The other bed is unused, but could need some cleanup.\n";
   else desc2+=
      "The other bed is unused and looks as if someone has recently "
      "cleaned it up.\n";
   return ({desc1, desc2 });

}
string CheckChairs()
{
   string desc;

   desc=
      "The chairs are standing around the table. They are made out of "
      "wood and doesn't look very comfortable. ";
   if(sizeof(chairs)==0) desc+="They are empty.\n";
   else
   {
      int a;

      chairs=sort_array(chairs,#'>);
      for(a=0; a<sizeof(chairs); a++)
      {
         if(chairs[a]==lower_case(RNAME(TP)))
         {
            if(a==0) desc+="You";
            else desc+="you";
         }
         else desc+=CAP(chairs[a]);
         if(sizeof(chairs)>1)
         {
            if(a!=sizeof(chairs)-1)
            {
               if(a==sizeof(chairs)-2) desc+=" and";
               else desc+=",";
            }
         }
         desc+=" ";
      }
      if(sizeof(chairs)==1) desc+="sit there.\n";
      else desc+="are sitting there.\n";
   }
   return desc;
}

// make sure that a player sitting on the chair stands up, when
// leaving the room.
int prevent_leave(mixed dest, int method, mixed extra)
{
   if(member(chairs, lower_case(RNAME(TP)))!=-1)
   {
      msg_write(CMSG_GENERIC,"You stand up from the chair.\n");
      chairs-=({ RNAME(TP) });
   }
   return ME_NO_PREVENT;
}

void reset()
{
   string desc;

   desc="A guard enters the room and puts his sword in the rack. ";
   if(sizeof(chairs)!=4) desc+=
      "He sits on the chairs at the table and gets a set of cards "
      "from a bag at his girdle. ";
   else desc+=
      "He looks at the table and sighs. Then he walks over to the beds "
      "and sits on one of them. There he takes a set of cards from a "
      "bag at his girdle and plays idly with them. ";
   if(cards) desc+=
      "Suddenly a bell is heard. The guard curses, drops the cards "
      "on the table and gets his sword from the weapon rack and "
      "bolts through the western exit.\n";
   else desc+=
      "Suddenly a bell is heard. The guard curses, puts the cards back "
      "in the bag, gets his sword from the rack and bolts through the "
      "western exit.\n";
   cards=0;
   locker_closed=1;
   locker_locked=1;
   bed_clean=0;
   msg_room(TO,CMSG_ROOM,desc);
   ::reset();
}

varargs void create()
{
   ::create();
   Set(P_INDOORS,1);
   Set(P_INT_SHORT,"Guardroom");
   Set(P_INT_LONG,
      "This is a small room. A table stands in the center of the room "
      "with some few chairs around it. Two crude beds are placed at the "
      "eastern wall. A wooden rack is standing at the western wall and "
      "a locker can be found next to the exit to the west. A wooden "
      "door leads to the north.\n");

   Set(P_INT_WIZMSG,
" West:  To the stairs up and the platform\n"
" North: To the stairs downwards\n");

   AddVItem(
   ([ P_IDS:({"globe"}),
      P_ADS:({"glowing"}),
      P_LONG:
         "The globe is hanging on the eastern wall. It is made out "
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

   AddDetail( "ceiling",
      "The ceiling is made out of large wooden beams. They are very "
      "heavy.\n");

   AddDetail( ({"floor","wooden floor","ground"}),
      "The ground is made out of the same beams of wood as the "
      "ceiling. You can see some footprints in the dust there.\n");

   AddDetail( "dust",
      "Lots of dust is lying on the wooden floor. You can see "
      "some footprints there.\n");

   AddDetail( ({"footprint","footprints"}),
      "The footprints are leading down the stairs and to the south. "
      "It seems,that someone is frequently is walking by here.\n");

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

   AddDetail( ({"room","small room","place","tower","northern tower",
                "defense tower"," northern defense tower","here"}),
      "That's the place, you are standing at the moment. If you want "
      "to know more about it, have a look around.\n");

   AddVItem(
   ([ P_IDS:({"table"}),
      P_ADS:({"wooden"}),
      P_LONG:SF(CheckTable),
   ]) );

   AddDetail( ({"card","cards"}),SF(CheckCards));

   AddVItem(
   ([ P_IDS: ({"chair","chairs"}),
      P_ADS: ({"wooden","uncomfortable"}),
      P_LONG:SF(CheckChairs),
      P_NOISE:"There is no noise from the chairs.\n",
      P_SMELL:"The chair doesn't smell.\n",
   ]) );

   AddVItem(
   ([ P_IDS:({"bed","beds"}),
      P_ADS:({"crude","wooden"}),
      P_LONG:SF(CheckBed),
      P_NOISE:"You hear someone snore in one of the beds.\n",
      P_SMELL:"Someone should clean the beds. They smell awful.\n",
   ]) );

   AddDetail( ({"guard","sleeping guard"}),
      "The guard lies in one of the bed and is sleeping. You hear "
      "him snoring.\n");

   AddVItem(
   ([ P_IDS: ({"rack"}),
      P_ADS: ({"weapon","wooden"}),
      P_LONG:"The weapon rack is made out of wood. It is empty.\n",
   ]) );

   AddDetail( ({"locker","large locker"}),SF(CheckLocker));

   AddDetail( ({"wall","walls"}),
      "The walls are made out of stone. At the wall next to the western "
      "exit hangs a glowing globe, which lights the room. Two beds are "
      "standing at the eastern wall. To the south you can see a large "
      "locker and to the north is a opened door.\n");

   AddDetail( ({"stone","stones","grey stone","grey stones"}),
      "The stones are grey and there is nothing unusualy about them. "
      "The single stones are placed on each other to form the wall. "
      "After that was done, someone went over it and smoothed the wall "
      "to prevent people from hurting themself at the wall.\n");

   AddDetail( ({"south wall","southern wall"}),
      "A large locker is standing there at the wall.\n");

   AddDetail( ({"north wall","northern wall"}),
      "A wooden door leads through the wall there. It is opened.\n");

   AddDetail( ({"west wall","western wall"}),
      "At the western wall stands a wooden rack, which is used by the "
      "guards to store weapons there, while not on duty. Unfortunately "
      "it is empty.\n");

   AddDetail( ({"east wall","eastern wall"}),
      "At the eastern wall are two beds. One of the beds is used by "
      "someone.\n");

   AddDetail( "exit",
      "There is an exit, leading to the west. You can go there, if "
      "you want.\n");

   AddDetail( ({"door","wooden door"}),
      "The door leads to the north. It is opened.\n");

   AddRoomCmd("unlock", SF(UnlockLocker));
   AddRoomCmd("lock",   SF(LockLocker));
   AddRoomCmd("open",   SF(OpenLocker));
   AddRoomCmd("close",  SF(CloseLocker));
   AddRoomCmd("sit",    SF(SitDown));
   AddRoomCmd("clean",  SF(CleanBed));
   AddRoomCmd( ({"stand","leave"}), SF(StandUp));
   AddRoomCmd( ({"get","take"}),    SF(GetThings));

   chairs=({ });
   cards=0;
   locker_closed=1;
   locker_locked=1;
   bed_clean=0;

   Set(P_INT_MAP,"harbour");
   Set(P_REGION, REGION_CITY|REGION_HARBOUR);
   Set(P_COORDINATES, ({ ({ -280,0,10 }), C_SILVERE }) );
   Set(P_NOWAY_MSG,"You run into a wall.\n");
   AddExit("north",SIL_HARBOUR("ntower5"));
   AddExit("west", SIL_HARBOUR("ntower7"));
}

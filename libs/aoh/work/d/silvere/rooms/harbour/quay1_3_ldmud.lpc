// The way to the northern quay and the tower.
// created:          Sonic [26-May-1997]
// last changed:     Taurec [13-Jun-1997]
//                   Sonic [05-Jul-1997] added region/coordinates

#include <silvere.h>
#include <properties.h>
#include <coordinates.h>
#include <msgclass.h>
#include <regions.h>
#include <macros.h>
#include <moving.h>
#include <rooms.h>
#include <nightday.h>
inherit HARBOUR_BASEROOM;

// funstuff ;-)
int gethook_func()
{
   switch(random(5))
   {
      case 0:
      case 3:
      {
         if(!(present("hook",TP)))
         {
            object item;

            if(present("hook",TO)) break;
            item=clone_object("/std/thing");
            if(item)
            {
               item->Set(P_IDS,({"hook"}) );
               item->Set(P_ADS,({"old","rusty"}) );
               item->Set(P_SHORT,"an old, rusty hook");
               item->Set(P_LONG,
                  "This is an old, rusty hook. It's pretty "
                  "useless.\n");
               item->Set(P_WEIGHT,5);
               item->Set(P_VALUE,0); /* grin*/
               item->Set(P_SIZE, PSIZE_SMALL);
               item->Set(P_SMELL,
                  "The hook has the scent of  rust around it.\n");
               item->move(TP, M_GET);
               msg_write(CMSG_GENERIC,
                  "You get a hook from the ground.\n");
               msg_room(TO,CMSG_ROOM,
                  CAP(NAME(TP))+" get's a hook from the ground.\n",
                  ({TP}) );
               return 1;
            }
         }
         msg_write(CMSG_GENERIC,
            "You already have a hook. Don't you think, "
            "that you have enough of them?\n");
         return 1;
      }
      default:
         if(present("hook",TP))
         {
            msg_write(CMSG_GENERIC,
               "You already have a hook. Don't you think, "
               "that you have enough of them?\n");
            return 1;
         }
         if(present("hook",TO)) break;
         msg_write(CMSG_GENERIC,
            "You feebly grab at the hook. Of course you hurt your "
            "hand on the sharp and rusty surface of it.\n");
         msg_room(TO,CMSG_ROOM,
            CAP(NAME(TP))+" grabs at a hook on the ground. Suddenly "+
            HESHE(TP)+" cries out and hold "+HISHER(TP)+" hand.\n",
            ({TP}) );
         TP->DoDamage(5);
         return 1;
   }
   return 0;
}

int catch_hook(string str)
{
   notify_fail("Catch what?\n", NOTIFY_ILL_ARG);
   if(!str) return 0;
   if(strstr(lower_case(str),"hook")!=-1)
   {
      gethook_func();
      return 1;
   }
   return 0;
}

int get_hook(string str)
{
   notify_fail("Take what?\n", NOTIFY_ILL_ARG);
   if(!str) return 0;
   if(strstr(lower_case(str),"hook")!=-1)
   {
      gethook_func();
      return 1;
   }
   return 0;
}

int burn_oars(string str)
{
   notify_fail("Burn what?\n", NOTIFY_ILL_ARG);
   if(!str) return 0;
   if(!TP)  return 0;
   if(strstr(lower_case(str),"oar")!=-1 ||
      strstr(lower_case(str),"firewood")!=-1)
   {
      if(present("torch",TP))
      {
         msg_write(CMSG_GENERIC,
            "You try to light the oars, but it is too "
            "wet to burn.\n");
         msg_room(TO,CMSG_ROOM,
            CAP(NAME(TP))+" puts a torch on the oars, but nothing "
            "happens.\n", ({TP}) );
         return 1;
      }
      notify_fail("You need something to light the oars.\n",
         NOTIFY_ILL_ARG);
   }
   return 0;
}

// daystate-changing details
// functions are mixed, as they return either a string or 0
mixed look_shadows()
{
   switch(({int})NIGHTDAY->Query(P_DAY_STATE))
   {
      case ND_SUNRISE:
      case ND_EARLY_MORNING:
         return
            "The long shadows of the towers can be seen behind them "
            "on the water of the sea.\n";
         break;
      case ND_LATE_MORNING:
         return
            "The shadows of the towers are somewhat shorter now, as "
            "the sun stands nearly at the middle of the sky.\n";
         break;
      case ND_NOON:
         return
            "The shadows of the towers are very short, as the "
            "sun stands nearly above the towers.\n";
         break;
      case ND_EARLY_AFTERNOON:
         return
            "The shadows of the towers can be seen on some parts "
            "of the quays.\n";
         break;
      case ND_LATE_AFTERNOON:
      case ND_SUNSET:
         return
            "The shadows of the towers can be seen over almost the "
            "whole length of the quays. The vanishing sun makes it "
            "somewhat hard to see them in the twilight, though.\n";
         break;
      default:
         return 0;
         break;
   }
   return 0;
}

varargs void create()
{
   ::create();
   Set(P_INDOORS,0);

   Set(P_INT_SHORT,"The quay at Silvere");
   Set(P_INT_LONG,
      "The quay runs along the murky water out to one of the towers "
      "guarding the entrance to the bay. Torn sails, fishing line and "
      "discarded oars litter the sides of the quay. @@TimeMsg@@\n");

   Set(P_INT_WIZMSG,
     " East: City gates of Silvere, harbourmaster, Inn, quays.\n"
     " West: The northern defense tower.\n");

   Set(P_TIME_MSG,
    ([
     ND_NIGHT:
       "The lapping of the waves against the quays is the only sound "
       "which disturbs the dark stillness of night along the docks.",
     ND_DAWN:
      "The dock area comes to life as fishermen prepare to sail out "
       "for the morning catch.",
     ND_PREDAWN:
        "The dock area comes to life as fishermen prepare to sail out "
        "for the morning catch.",
     ND_SUNRISE:
        "The dock area comes to life as fishermen prepare to sail out "
        "for the morning catch.",
     ND_EARLY_MORNING:
        "The sunlight plays off the water, casting strange shadows on "
        "the tower walls.",
     ND_LATE_MORNING:
         "The sunlight plays off the water, casting strange shadows on "
         "the tower walls.",
     ND_NOON:
        "The sunlight plays off the water, casting strange shadows on "
        "the tower walls.",
     ND_EARLY_AFTERNOON:
        "The long shadows of the defense towers stretch lazily across "
        "the quays, as the sun sinks gently into the sea.",
     ND_LATE_AFTERNOON:
         "As the shadows lengthen into night, the docks begin to empty "
         "as people head for home or the taverns.",
     ND_EVENING:
         "As the shadows lengthen into night, the docks begin to empty "
         "as people head for home or the taverns.",

  ]));

   AddDetail(({"sails","sail","rubbish"}),
     "Torn and thrown away remains of sails. Nobody cares for all that "
     "rubbish here.\n");

   AddDetail(({"fishing line","line","lines"}),
     "Useless fishing lines are littered everywhere. Take care you "
     "don't get caught on one of the nasty hooks.\n");

   AddDetail("hooks",
      "Thay look really nasty. Take care you don't get caught on one "
      "of them.\n");

   AddDetail(({"oar","oars"}),
     "Hmm... these oars are nothing more than firewood now.\n");

   AddDetail( ({"tower","towers"}),
      "The towers can be found at the end of each quay. They are high "
      "and it seems that they watch over the harbour of Silvere. They "
      "look quite interesting though.\n");

   AddDetail( "shadows",#'look_shadows /*'*/);

   // fun stuff :-)
   AddRoomCmd( ({"burn","light"}), "burn_oars");
   AddRoomCmd( ({"get","take"}),"get_hook");
   AddRoomCmd("catch",  "catch_hook");

   Set(P_REGION, REGION_CITY|REGION_HARBOUR);
   Set(P_COORDINATES, ({ ({ -260,0,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,
     "As you try to go there you nearly slip from the quay into "
     "the murky water of the harbour. Now, that's not the best "
     "thing you could do...\n");
   AddExit("west", SIL_HARBOUR("ntower_enter"));
   AddExit("east", SIL_HARBOUR("quay1_2"));
}

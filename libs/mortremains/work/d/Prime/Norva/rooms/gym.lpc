// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM ;

void create() {
  seteuid(getuid()) ;
  set("author", "chronos");
  set("light", 1) ;
  set("short", "The Gym.");
  set("long", @ENDLONG
You stand at the front desk of the Gym on base.
A bored-looking young man sits behind the desk, staring at you
expectantly.  There is a sign on the desk.
ENDLONG
  );
  set("item_desc", ([
    "sign" : "You could read it if you tried.\n",
    "desk" : "There is a sign on it.\n",
    "clerk" : "He's pretty buff for a younger guy.\n",
  ]) ) ;
  set("exits", ([
    "west" : ROOMS(base5),
    "east" : ROOMS(gym1),
  ]) ) ;
  ::create();
  reset();
}

void init() {
  add_action("check_pass", "go") ;
  add_action("read_sign", "read") ;
}

int read_sign(string str) {
  if (!str) {
    write("Read what?\n");
    return 1;
  }
  if (str != "sign") return 0;
  write(@ENDSIGN
The sign reads:

        You must present your membership card every time you want
        to use the Gym facilities.  There are no exceptions, and
        no excuses.

                                        -- The Management.
ENDSIGN
  );
  say(TPN+" reads the sign carefully.\n");
  return 1;
}

int check_pass(string str) {
  if (str != "east") return 0 ;
  if (!present("#GYM_PASS#", TP)) {
    switch(random(6)) {
    case 0: write(@ENDCLERK
The clerk refuses to let you enter without your Gym Pass.
ENDCLERK
     )  ;
     break;
    case 1: write(@ENDCLERK
Clerk says: Hey Buddy, where's your Gym Pass.  You're not getting in
        without one.
ENDCLERK
      ) ;
      break ;
    case 2: write(@ENDCLERK
The clerk points at the sign on his desk.
Clerk says: Ahem.
ENDCLERK
      )  ;
      break ;
    case 3: write(@ENDCLERK
Clerk says: I'm getting tired of you people not reading the sign.
Clerk points at the sign.
ENDCLERK
      ) ;
      break ;
    case 4: write(@ENDCLERK
The clerk stops you from entering the Gym.
Clerk says: No pass, no get in.  Simple enough?
ENDCLERK
      ) ;
      break ;
    default: write(@ENDCLERK
The clerk stops you in your tracks.
Clerk says: Where is your Gym Pass?  Didn't you read the sign?
Clerk points at the sign on the desk.
ENDCLERK
      ) ;
      break ;
    }
    if (wizardp(TP)) {
     write("Clerk notices you are a wizard.\nClerk says: Oh, excuse me!  You can go.\n") ;
      return 0 ;
    }
    return 1;
  }
  write(@ENDOK
You show the clerk your Gym Pass as you walk by.
Clerk says [to you]: Have a great workout!
ENDOK
  );
  say(TPN+" shows the clerk a Gym Pass.\n");
  say("Clerk says [to "+TPN+"]: Have a great workout!\n") ;
  return 0 ;
}


#include <mudlib.h>
#include "../defs.h"

inherit MONSTER ;

void create () {
    ::create() ;
    seteuid(getuid()) ;
    set ("short",  "a ripped workout fanatic");
    set ("long", @ENDLONG
This guy is addicted to working out and taking supplements.  He's HUGE, and very mean-looking.
Watch out for Roid Rage!
ENDLONG
  );
    set ("id", ({"workout fanatic", "fanatic", "man"}) );
    set_name("workout fanatic");
    set ("gender", "male") ;
    set ("race", "human");
    enable_commands() ;
    set ("damage", ({ 10, 17 }) ) ;
    set ("weapon_name", "powerful fists");
  set("author", "Chronos") ;
    set_verbs( ({ "punche at", "swing at", "swipe at" }) ) ;
    set_size(6);
    set_level(20);
   set("prevent_summon", 1) ;
   set("wealth", 2300 + random(240) ) ;
  set("chat_chance", 5) ;
  set("chat_output", ({ 
   "Workout Fanatic says [to you]: You need to workout some more buddy.\n",
    "Workout Fanatic does some squats.\n",
   "Workout Fanatic does some curls.\n",
  "Workout Fanatic does some one-armed pushups.\n",
   "Workout Fanatic does some pull-ups on the pull-up bar.\n",
   "Workout Fanatic poses in the mirror.\n",
   "Workout Fanatic pops some pills in the corner.\n",
  }) ) ;
  set("att_chat_output", ({
    "Workout Fanatic flexes at you!\n",
   "Workout Fanatic picks you up off the ground with ease.\n",
   }) ) ;
}

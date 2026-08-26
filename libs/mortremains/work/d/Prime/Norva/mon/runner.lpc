#include <mudlib.h>
#include "../defs.h"

inherit MONSTER ;

int x;


void create () {
    ::create() ;
    seteuid(getuid()) ;
    set ("short", "a runner");
    set ("long", @ENDLONG
He's gung-ho navy in his Navy PT gear.
ENDLONG
  );
    set ("id", ({ "runner"}) );
    set_name("runner");
  set("smell", "He smells like sweat.") ;
    set ("gender", "male") ;
    set ("race", "human");
   clone_object(OBJ(gym_pass))->move(TO) ;
   set("prevent_summon", 1 ) ;
    enable_commands() ;
    set ("stat/constitution", 17);
    set ("stat/strength", 14);
    set ("base_ac", 8);
    set ("armor_class", 7);
    set ("damage", ({ 1, 4 }) ) ;      
    set ("weapon_name", "fists");
    set("chat_chance",2);
    set("chat_output", ({
       "The runner sings some cadence to help him run.\n",
       "The runner glances at you warily.\n",
       "The runner runs right past you.\n"
       }) ) ;
    set ("CLASS", "warrior");
    set_verbs( ({ "punche at", "swing at", "swipe at", "attack" }) ) ;
    set_size(5);
  set_level(12) ;
}

int run_your_ass_off() {
  if (!query_current_attacker()) {
  if (!x) {
     x++;
      command("go west") ;
  } else {
     x=0 ;
     command("go east") ;
  }
  }
  call_out("run_your_ass_off", random(3) + 2 ) ;
}




#include <mudlib.h>

inherit MONSTER ;

object hero ;

void create () {
    ::create() ;
    seteuid(getuid()) ;
   set("prevent_summon", 1) ;
    set("short", "a handsome stud (following Shya)") ;
    set ("long", @ENDLONG
This is Shya's personal slave boy.  He's tanned and ripped.
ENDLONG
    );                                
    set ("id", ({"boy", "man", "hunk", "stud"}) );
    set_name("stud");
    set("race", "human") ;
    set ("gender", "male") ;
    set ("race", "human");
    enable_commands() ;
    set ("stat/constitution", 15);
    set ("stat/strength", 18);
    set ("base_ac", 2);
    set ("armor_class", 1);
    set ("damage", ({ 1, 4 }) ) ;
    set ("weapon_name", "fists");
    set ("CLASS", "warrior");
    set_verbs( ({ "punche at", "swing at", "attack" }) ) ;
    set_size(6);
    set_level(15) ;
    if (!hero) hero=find_player("shya") ;
}

void init() {
   if (!hero) hero=find_player("shya") ;
   add_action("duh", "quit") ;
}

int duh() {
  if (TPN=="Shya") TO->move("/u/s/shya/workroom") ;
  return 0 ;
}

void heart_beat() {
    if (hero)  {
      if (environment() != environment(hero)) {
          tell_object(environment(),  
               "A handsome stud walks in, following Shya.\n") ;
          TO->move(environment(hero)) ;
          tell_object(hero, "A handsome stud follows behind you..\n") ;
          message("whore", "A handsome stud follows behind Shya.\n",
              environment(hero), ({ hero }) ) ;
      }
    }
    heal_up();
    ::heart_beat() ;
} 

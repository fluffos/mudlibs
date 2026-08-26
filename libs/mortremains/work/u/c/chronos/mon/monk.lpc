#include <mudlib.h>

inherit MONSTER ;

object hero ;

void create () {
    ::create() ;
    seteuid(getuid()) ;
   set("prevent_summon", 1) ;
    set("short", "a hooded figure (following Chronos)") ;
    set ("long", @ENDLONG
This is one of the Dark Monk's assigned to follow Chronos.
A wise man would steer clear of him.
ENDLONG
    );                                
    set ("id", ({"dark monk", "monk", "figure", "man", "hooded"}) );
    set_name("dark monk");
    set("race", "human") ;
    set ("gender", "male") ;
    set ("race", "human");
    enable_commands() ;
    set ("stat/constitution", 15);
    set ("stat/strength", 15);
    set ("base_ac", 2);
    set ("armor_class", 1);
    set ("damage", ({ 1, 4 }) ) ;
    set ("weapon_name", "fists");
    set ("CLASS", "warrior");
    set_verbs( ({ "punche at", "swing at", "chop at", "attack" }) ) ;
    set_size(6);
    set_level(45) ;
    if (!hero) hero=find_player("chronos") ;
}

void init() {
   if (!hero) hero=find_player("chronos") ;
   add_action("duh", "quit") ;
}

int duh() {
  if (TPN=="Chronos") TO->move("/u/c/chronos/workroom") ;
  return 0 ;
}

void heart_beat() {
    if (hero)  {
      if (environment() != environment(hero)) {
          tell_object(environment(),  
               "The hooded figure glides silently away, following Chronos.\n") ;
          TO->move(environment(hero)) ;
          tell_object(hero, "A hooded figure glides in behind you.\n") ;
          message("whore", "A hooded figure glides in behind Chronos.\n",
              environment(hero), ({ hero }) ) ;
      }
    }
    heal_up();
    ::heart_beat() ;
} 

#include <mudlib.h>

inherit MONSTER ;

object hero ;

void create () {
    ::create() ;
    seteuid(getuid()) ;
    set("prevent_summon", 1) ;
    set("author", "tyran") ;
    set("short", "the Lady Lyra Silvermaine") ;
    set ("long", @ENDLONG
This is the Lady Lyra Silvermaine.  She is the Saveyan Elf
Ambassador to the Ruling Council of Thilasia.  She has long
silver hair and pale skin.  She is wearing elfin chainmail
covered over in a long green cloak.  Her eyes are a fiery
green, and her ears are slightly pointed.
ENDLONG
    );                                
    set ("id", ({"elf", "Lyra", "lyra", "lady", "woman", "maiden"}) );
    set_name("Lyra");
    set ("gender", "female") ;
    set ("race", "elf");
    enable_commands() ;
    set ("stat/constitution", 18);
    set ("stat/strength", 17);
    set ("stat/dexterity", 19);
    set ("stat/intelligence", 19);
    set ("stat/charisma", 18);
    set ("stat/wisdom", 18);
    set ("armor class", 0);
    set ("damage", ({ 8, 15 }) ) ;
    set ("weapon_name", "fists");
    set_verbs( ({ "punch at", "swing at", "attack" }) ) ;
    set_size(5);
    set_level(30) ;
    set ("wealth", 10000);
    if (!hero) hero=find_player("tyran") ;
}

void init() {
   if (!hero) hero=find_player("tyran") ;
   add_action("duh", "quit") ;
}

int duh() {
  if (TPN=="Tyran") TO->move("/u/t/tyran/workroom") ;
  return 0 ;

}

void heart_beat() {
    if (hero)  {
      if (environment() != environment(hero)) {
          tell_object(environment(),  
               "The Lady Lyra enters the room behind Tyran.\n") ;
          TO->move(environment(hero)) ;
          tell_object(hero, "The Lady Lyra follows behind you..\n") ;
          message("whore", "The Lady Lyra follows behind Tyran.\n",
              environment(hero), ({ hero }) ) ;
      }
    }
    heal_up();
    ::heart_beat() ;
} 
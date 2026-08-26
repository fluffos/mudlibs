// light_saber.c
// Written by Dent@TMI-2
// Header added by Mobydick@TMI-2, 8-24-93.
// This is a powered weapon, and has a limited charge. It can be turned
// on or off. When on, it's a pretty good weapon, and runs its charge down.
// When off, or out of power, it's a pretty lousy weapon. :)


#include <mudlib.h>

inherit WEAPON ;

void create() {
  set ("id", ({ "saber", "light-saber" }) ) ;
  set ("short", "@@query_short");
  set ("long", "@@query_long");
  set ("mass", 60) ;
  set ("bulk", 35) ;
    set ("value", ({ 600, "credits" }) ) ;
  set ("weapon", 2) ;
  set ("damage", ({ 1, 4 }) ) ;
  set ("type", "blunt") ;
  set ("name", "light-saber") ;
  set ("power", 1000);
  set_verbs( ({ "attack", "swing at", "charge at", "swipe at" }) ) ;
}

string query_long() {

  int pow;

  if ( query ("on") ) {
    pow = remove_call_out("fizzle");
    call_out ("fizzle", pow);
    return("This is a white police light-sabre. It's turned on and a long"+
           " beam of\nlight shoots out from the handle.\n"+
           "It has "+pow/10+"% energy left.\n");
  }
  return ("This is a white police light-sabre. It's turned off.\n"+
          "It has "+query("power")/10+"% energy left.\n");
}

string query_short() {
  if ( !query ("on") ) 
    return "a light saber (off)" ;
   return "a light saber (on)" ;
}

void init() {
  add_action ("turn_c", "turn");
}

int turn_c ( string arg ) {

  string what;
  int turn;

  if (!arg) return 0;
  
  turn = query("on");
  
  if ( !sscanf ( arg, "%s light-saber", what ) ) {
    if ( !sscanf ( arg, "%s saber", what ) ) {
      if ( !sscanf ( arg, "saber %s", what ) ) {
        if ( !sscanf ( arg, "light-saber %s", what ) ) return 0;
      }
    }
  }
  
  if ( what == "on" ) {
    if ( turn ) {
      notify_fail ("It's already turned on.\n");
      return 0;
    }
    if ( !query("power") ) {
      write ("It seems to be out of power.\n");
      return 1;
    }
    write ("Bzzzrrmmm! You turn your light-saber on.\n");
    set ("on", 1);
    set ("weapon", 12) ;
    set ("damage", ({ 10, 20 }) ) ;
    set ("type", "cutting");
    call_out ("fizzle", query("power"));
    return 1;
  }

  if ( what == "off" ) {
    if ( !turn ) {
      notify_fail ("It's not turned on.\n");
      return 0;
    }
   write ("You turn off your light-saber.\n") ;
    set ("on", 0);
    set ("weapon", 2) ;
    set ("damage", ({ 1, 4 }) ) ;
    set ("type", "blunt");
    set ("power", remove_call_out ("fizzle") );
    return 1;
  }
}

void fizzle() {
  tell_object ( environment ( this_object() ),
               "Your light-saber fizzles and dies.\n");
  set ("on", 0);
  set ("weapon", 2) ;
  set ("damage", ({ 1, 4 }) ) ;
  set ("type", "blunt");
  set ("power", 0);
}

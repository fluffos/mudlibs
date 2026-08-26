// Chronos's quicky grenade.  Speedcoded for a wizwar.
#include <mudlib.h>
#define DELAY 6

inherit OBJECT ;

void broadcast_boom() ;
int live ;

void create() {
  seteuid(getuid()) ;
  set("short", "a grenade") ;
  set("long", @ENDLONG
It's a grenade.  You can "pull pin" or "throw <victim | direction>" it.
ENDLONG
  );
  set("id", ({ "grenade" }) ) ;
  set("value", 5000) ;
}

void init() {
  add_action("throw", "throw") ;
  add_action("pull", "pull");
}

int pull(string str) {
  if (!str) {
    write("Pull what?\n") ;
    return 1;
  }
  if (str == "pin" )  {
    if (live==1) {
      write("This grenade is already live!\n");
      return 1;
    }
    write("You pull the pin from the grenade! ("+DELAY+" seconds until detonation.)\n");
    live = 1;
   set("short", "a grenade (live)") ;
   call_out("boom", DELAY) ;
    return 1;
  }
  write("Pull what?\n") ;
  return 1;
}

int boom() {
  object *inv;
  object victim;
  int i ;
  victim = environment(TO) ;
  if (living(victim)) {
    tell_object(victim, "The grenade explodes in your hands!\n");
    victim->receive_damage(999999, "force") ;
    message("combat", "A grenade explodes in "+victim->query("cap_name")+
      "'s hands!\n",  environment(victim), ({ victim }) ) ;
  } else {
    message("combat", "A grenade explodes suddenly in the room!\n", victim ) ;
  }   
  if (!living(environment(TO))) inv = all_inventory(environment(TO)) ;
  else inv = all_inventory (environment(environment(TO))) ;
  for(i=0;i<sizeof(inv);i++) {
    tell_object(inv[i],"You are blasted by the shrapnel from the grenade!\n") ;
    inv[i]->receive_damage(1000 + random(1000), "force") ;
  }
  broadcast_boom() ;
  remove() ;
}

int throw(string str) {
  object victim ;
  int dir ;
  mapping exits ;
  string val ;
  if (!userp(environment(TO))) {
    write("You must be holding the grenade to throw it!\n") ;
    return 1;
  }
  if (!str) {
    write("Throw the grenade at who?  Or in which direction?\n") ;
    return 1;
  }
  switch(str) {
    case "north":case "n" : case "North" : str = "north"; dir = 1; break ;
    case "south":case "s" : case "South" : str = "south"; dir = 1; break ;
    case "east":case "e" : case "East" : str = "east"; dir = 1; break ;
    case "west":case "w" : case "West" : str = "west"; dir = 1; break ;
    default: break ;
  }
  if (!dir) {                   // Begin user targeting.
    victim = find_living(lower_case(str)) ;
    if (!victim) {
      write("Couldn't find that victim.\n") ;
      return 1;
    }
    if (environment(victim)==environment(TP)) {
      write("You throw the grenade in the center of the room!\n") ;
      say(TPN+" throws a grenade in the center of the room!\n") ;
      if (live) say("THE GRENADE IS LIVE!\n") ;
      TO->move(environment(TP)) ;
      return 1;
    }
    write("You heave a grenade at "+victim->query("cap_name")+"!\n") ;
    say(TPN+" heaves a grenade across the Mud!\n") ;
    TO->move(environment(victim)) ;
    if (!live) {
      message("combat", "A grenade comes rolling into the room!\n",
        environment(victim) ) ;
    } else {
      message("combat", "A LIVE grenade comes rolling into the room!\n",
        environment(victim) ) ;
    }
    return 1;
  }      // end if (!dir) .. user targeting.
  exits = environment(TP)->query("exits") ;
  if (!exits) {
    write("You can't throw the grenade in that direction.\n");
    return 1;
  }
  val = exits[str];
  if (!val) {
    write("You can't throw the grenade in that direction.\n");
    return 1;
  }
  victim = find_object_or_load(val) ;
  if (!victim) {
    write("You can't throw the grenade in that direction.\n");
    return 1;
  }
  write("You heave the grenade to the "+str+".\n") ;
  message("combat", TPN + " heaves a grenade to the "+str+".\n",
     environment(TP), ({ TP }) ) ;
  TO->move(victim) ;
  if (live) message("combat", "A LIVE grenade comes rolling into the room.\n",
     victim ) ;
  else message("combat", "A grenade comes rolling into the room.\n",
     victim ) ;
  return 1;
}

void broadcast_boom() {
  mapping exits ;
  int i ;
  object victim ;
  string *keys;
  string *vals;
  string dir ;
  victim = environment(TO) ;
  if (userp(victim)) victim=environment(victim) ;
  exits = victim->query("exits") ;
  if (!exits) return ;
  keys = keys(exits) ;
  vals = values(exits) ;
  if (!keys || !vals) return ;
  for(i=0;i<sizeof(keys);i++) {
    victim = find_object_or_load(vals[i]) ;
    if (!victim) continue ;
    switch(keys[i]) {
      case "up" : dir = "below"; break ;
      case "down" : dir = "above" ; break ;
      case "northeast" : dir = "southwest" ; break ;
      case "southeast" : dir = "northwest"; break ;
      case "northwest" : dir = "southeast" ; break ;
      case "southwest" : dir = "northeast"; break ;
      case "north" : dir = "south" ; break;
      case "south" : dir = "north" ; break ;
      case "west" : dir = "east"; break ;
      case "east" : dir = "west" ; break ;
      default: dir = "somewhere nearby" ; break ;
    }
    message("combat", "You hear a loud explosion from "+dir+".\n",
      victim);
  }
  return ;
}


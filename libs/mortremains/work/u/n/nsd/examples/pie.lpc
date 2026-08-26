// The infamous cream pie!
// By chronos.
#include <mudlib.h>

inherit OBJECT;

int face; 

void create() {
  seteuid(getuid()) ;
    set("author", "Chronos") ;
  set("short", "a cream pie") ;
  set("long", @ENDLONG
It's a delicious-looking cream pie.

Commands:
	eat pie
	pie <person>
ENDLONG
  );
    set("id", ({ "pie", "cream pie" }) ) ;
}

void init() {
   if (!face) {
    add_action("eat", "eat") ;
    add_action("pie", "pie") ;
  }
}

int eat(string str) {
   if  (!str) return 0 ;
   if (str != "pie") return 0 ;
   if (!face) {
     write("You eat the pie.  It's delicious.\n") ;
     say(TPN+" eats a cream pie.\n") ;
  } else {
     write("You lick the pie off your face.\n") ;
     say(TPN+ " licks the pie off "+
           possessive(TP->query("gender")) + " face.\n");
  }
   remove() ;
  return 1;
}

int pie(string str) {
  object target;
  if (!str) {
    write("Pie who?\n") ;
    return 1; 
  }
  target = find_player(str) ;
  if (!target || target->query("invisible")) {
     write("Can't find that player online.\n") ;
    return 1;
  }
  if (target==TP) {
      write("You can't do that, idiot.\n") ;
     return 1;
  }
  if (target->query("busy")) {
     write("They have the busy flag set.  You can't fuck with them right now.\n") ;
     return 1;
   }
  str = capitalize(str) ;
  if (environment(TP) == environment(target)) {
    write("You smash a cream pie in "+str+"'s face!\n") ;
    message("cream pie", TPN+
        " smashes a cream pie in "+str+"'s face!\n",
           environment(TP), ({ TP, target }) ) ;
    tell_object(target, TPN+ 
          " smashes a cream pie in your face!\n") ;
 } else {          
    write("You heave a cream pie across the Mud!\n") ;
    say(TPN+" heaves a cream pie across the Mud!\n") ;
   tell_object(target, "You are suddenly hit in the face with a cream pie!\n") ;
    message("cream pie", 
  "A cream pie comes flying into the room and smashes into "+str+
         "'s face!\n", environment(target), ({ target }) ) ;
 }
  TO->move(target) ;
  delete("short") ;
  delete("id") ;
  face++ ;
  delete("long") ;
  set("extra_look", "$N's face is covered with cream pie filling.\n") ;
  call_out("remove_pie", 30) ;
  return 1;
}

int remove_pie() {
   message("blah", "The cream pie filling finally slides off "+
            environment()->query("cap_name")+"'s face.\n", environment(environment()),
  ({ environment() }) ) ;
  tell_object(environment(), "The cream pie filling finally slides off your face.\n") ;
  remove() ;
}
  

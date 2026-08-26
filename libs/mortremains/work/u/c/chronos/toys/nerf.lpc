// The nerf!  By Chronos.
// (06-22-00) Modified to respect invisible people.. ;)
#include <mudlib.h>

inherit OBJECT;

void create() {
  seteuid(getuid()) ;
  set("short", "an orange Nerf football") ;
  set("long", @ENDLONG
It's a bright orange Nerf Football!

Usage:
		handoff <person>
                pass <person>
		spike
		punt
ENDLONG
  );
  set("author", "Chronos") ;
  set("id", ({ "nerf", "football", "ball" }) ) ;
}
void init() {
  add_action("handoff", "handoff") ;
  add_action("pass", "pass") ;
  add_action("punt", "punt") ;
  add_action("spike", "spike") ;
}

int pass(string str) {
  object target;
   int ld ;
  string str2, str3;
  if (!str) {
     write("Usage: pass <person>\n") ;
     return 1;
  }
  target = find_player(str) ;
  if (str=="alucard") target=present("alucard", environment(TP)) ;
  if (!target || target->query("invisible")) {
    write("NERF: Cannot find that player on the Mud.\n") ;
     return 1;
  }
  if (target==TP) {
  write("You throw the ball up in the air and catch it.\n") ;
   say(TPN+" throws the ball up in the air and catches it.\n") ;
  return 1;
  }
  str = capitalize(str) ;
  if (environment(target) == environment(TP)) {
    write("You make a short pass to "+str+
               ".\n") ;
    message("football", TPN+" makes a short pass to "+
       str+".\n", environment(TP), ({ TP, target }) ) ;
    tell_object(target, TPN + " makes a short pass to you!\n") ;
  } else {
    ld = 1 ;
    write("You drop back and make a long pass to "+
         str +".\n") ;
    say(TPN+" drops back for a long pass and "+
        "throws the ball across the Mud!\n") ;
     tell_object(target, TPN+ " makes a long pass to you!\n") ;
     message("football", 
  "Suddenly, a football flies into the room right at "+
   str+"!\n", environment(target), ({ target }) ) ;
  }
// Do we catch it?   4% chance per point of dexterity.
  if (((int)target->query("stat/dexterity")*4) > random(100)) {
     switch(random(8)) {
      case 0:  str2= str+" catches the pass.\n" ;
   		 str3= "You catch the pass.\n" ;
				break ; 
      case 1:  str2= str+" makes the big catch!\n" ;
			str3="You make the big catch!\n";
				break ;
      case 2:  str2= str+" makes an amazing diving catch!\n" ;
		str3 = "You make an amazing diving catch!\n";
				break ;
      case 3:  str2= str+" barely manages to make the catch.\n" ;
		str3= "You barely manage to make the catch.\n" ;
				break ;
      case 4:  str2= str+" catches the ball with one hand.\n" ;
		str3 = "You catch the ball with one hand, like a Pro!\n";
				break ;
      case 5:  str2= str+" almost drops the pass, but hangs"+ 			" on to it!\n";
		str3= "You almost drop it, but manage to hang on!\n";
					break ;
      default:  str2= str+" easily catches the pass.\n" ;
			str3= "You easily catch the pass.\n";
					break ;
  }
    tell_object(TP, str2) ;
   message("football", str2, environment(TP), ({ TP, target }) ) ;
     tell_object(target, str3) ;
   if (ld) 
     message("football", str2,
         environment(target), ({ target }) ) ;
    TO->move(target) ;
    return 1; 
  }
  switch(random(8)) {
    case 0:  str3= "You drop the pass.\n"; 
                str2=str+" drops the pass.\n" ;break ;
    case 1:  str3="You miss the big catch!\n";
                str2=str+" misses the big catch.\n" ;break ;
    case 2:  str3="You almost catch it.\n";
                str2=str+" almost catches it.\n" ;break ;
    case 3:  str3="You drop the ball.\n";
                str2=str+" drops the ball.\n" ;break ;
    case 4:  str3="You trip and miss the catch!\n"; 
                str2=str+" trips and misses the catch.\n" ;break ;
    case 5:  str3 = "You catch the ball, but can't hold on to it.\n"; 
                str2=str+" catches the ball, but can't hold onto"+
                                          " it.\n";break;
    default: str3="You drop the pass, like an idiot.\n"; 
		str2=str+" drops the pass, like an idiot.\n" ;break ;
  }
   message("football", str2, environment(TP), ({ target }) ) ;
  if (ld) 
  message("football", str2, environment(target), ({ target }) ) ;
  tell_object(target, str3 ) ;
  TO->move(environment(target)) ;
  return 1;
}

int spike(string str) {
   write("You spike the ball on the ground in victory!\n") ;
   say(TPN+" spikes the ball on the ground in victory!\n") ;
   TO->move(environment(TP)) ;
   return 1;
}

int handoff(string str) {
  object target;
  if (!str) {
     write("Usage: handoff <person>\n") ;
     return 1;
  }
  target = present(str) ;
  if (!target || target->query("invisible") ) {
     write("NERF: Cannot find that player.\n") ;
     return 1;
   }
  if (!userp(target)) {
     write("You cannot handoff to an inanimate object, dumbass.\n") ;
     return 1;
  }
  if (target==TP) {
    write("You cannot do that, dumbass.\n") ;
   return 1;
  }
  TO->move(target) ;
  write("You handoff to "+capitalize(str)+".\n") ;
  say(TPN+" hands the ball off to "+capitalize(str)+".\n") ;
  return 1;
}

int punt(string str) {
  object *users;
  object target;
  write("You punt the Nerf football high in the air!\n");
  say(TPN + " punts the Nerf football high in the air!\n") ;
  users = users() ;
  if (!users) {
     write("The ball drops right in front of you.\n"); 
     say("The ball drops right in front of you.\n"); 
     return 1;
  }
  target=users[random(sizeof(users))] ;
  if (target == TP) {
    write("The ball bounces off your head!\n") ;
    say(wrap("The ball bounces off "+TPN+"'s head and bounces"+
       " around in front of you!")) ;
    TO->move(environment(TP)) ;
     return 1;
  }
  message("toys", "A Nerf football sails into the room and bounces off "+
     target->query("cap_name")+"'s head!\n", environment(target),
     ({ target }) ) ;
  tell_object(target, "A Nerf football sails into the room and bounces off"+
      " your head.\n") ;
  TO->move(environment(target)) ;
  return 1;
}

// The infamous Chronos doll v2.0
// (07-09-00) Remade by Chronos cuz he felt like the mud needed it.
#include <mudlib.h>

inherit OBJECT;

int awake ;

void create() {
  seteuid(getuid()) ;
  awake  = 1;
  set("short", "@@query_short") ;
  set("long", @ENDLONG
This is a cute little doll that resembles Chronos, one of your MUD
Administrators.  Remarkably enough, the little doll appears to have
life of its own somehow..

You notice a small string hanging from its back.

Commands are:
                            hug doll
                            tickle doll
                            pull string
                            wake doll (for when he's sleeping)
                            send doll to <person>
ENDLONG
  ) ; 
  set("id", ({ "doll", "chronos doll" }) ) ;
  set("prevent_clean", 1) ;
  call_out("toggle_sleep", 60 * (random(10) + 5)) ;
}

void init() {
  add_action("hug", "hug") ;
  add_action("send", "send") ;
  add_action("tickle", "tickle") ;
  add_action("pull", "pull") ;
  add_action("wake", "wake") ;
}

int pull(string str) {
  if (!str || str != "string") return 0 ;
  write("You pull the string on the Chronos doll.\n") ;
  say(TPN+" pulls the string on "+
      possessive(TP->query("gender")) + 
            " Chronos doll.\n") ;
  if (!awake) {
     write("The Chronos doll mutters something in its sleep.\n") ;
     return 1;
  }
  switch(random(20)) {
     case 0:  str = "Who can code better?  Cyanide or Chronos?";
           break ;
     case 1:  str = "I love you!";
           break ;
     case 2:  str = "Aren't I sickeningly cute?";
           break ;
     case 3:  str = "Chronos coded me all by himself!";
           break ;
     case 4: str = "Do you wipe sitting down or standing up?" ; 
           break ;
     case 5:  str = "I'm not nearly as cool as Alucard..";
           break ;
     case 6:  str = "Are you a Yankees fan?";
           break ;
     case 7:  str = "Chronos is addicted to Diablo 2.  He needs help.";
           break ;
     case 8:  str = "Gosh, I love mudding.";
           break ;
     case 9:  str = "I have a lot to say!";
           break ;
     case 10:  str = "My favorite toy on the mud is the Nerf Football!";
           break ;
     case 11:  str = "I hope nobody copies me!";
           break ;
     case 12:  str = "Hey baby.. do you like my beard?  Huh-huh.  Huh-huh.";
           break ;
     case 13:  str = "It doesn't matter if you fall down, just as long as you"+
             " pick something up off the floor when you get up.";
           break ;
     case 14:  str = "Smoking on the mud is strictly prohibited.  No if's, "+
           " and's, or butts.";
           break ;
     case 15:  str = "Biology is the only science where multiplication is the "+
               "same as division.";
           break ;
     case 16:  str = "It takes a strong man to cry.  It takes a stronger man "+
             " to laugh at the guy who is crying.";
           break ;
     case 17:  str = "I'm full of stupid quotes!";
           break ;
     case 18:  str = "If you find any problems with me, tell Chronos!";
           break ;
     default:  str = "Umm... I can't think of anything witty right now.";
           break ;
     }
   write(iwrap("Chronos doll says: "+str)) ;
    say(iwrap("Chronos doll says: "+str)) ;
  return 1;
}

int hug(string str) {
  if (!str || !id(str)) return 0 ;
  write("You hug the Chronos doll.\n") ;
   say(TPN+" hugs "+possessive(TP->query("gender"))+
       " Chronos doll.\n") ;
  if (awake) {
    write("The Chronos doll hugs you back fiercely.\n") ;
    say("The Chronos doll hugs "+
    objective(TP->query("gender")) + 
          " back fiercely.\n") ;
       return 1;
  }
  write("The Chronos doll smiles in its sleep.\n") ;
  return 1;
}

int tickle(string str) {
  if (!str || !id(str)) return 0 ;
  write("You tickle the Chronos doll.\n") ;
   say(TPN+" tickles "+possessive(TP->query("gender"))+
       " Chronos doll.\n") ;
  if (awake) {
    write("The Chronos doll giggles and squirms.\n") ;
    say("The Chronos doll giggles and squirms.\n") ;
       return 1;
  }
  write("The Chronos doll giggles in its sleep.\n") ;
  return 1;
}

int wake(string str) {
  if (!str || !id(str)) return 0 ;
  if (awake) {
       write("The Chronos doll is already awake, silly.\n") ;
       return 1;
  }
  write(@ENDHI
You gently wake up the Chronos doll.
It sits up, rubs its eyes sleepily, and looks at you expectantly.
ENDHI
  ) ;
  say(TPN+" gently wakes up "+
   possessive(TP->query("gender")) + 
          " Chronos doll.\n") ;
  awake = 1;
  call_out("toggle_sleep", 60 * (random(10) + 5)) ;
  return 1;
}

int toggle_sleep() {
   if (awake) 
     {   awake =0 ;
         write("The Chronos doll falls asleep and starts snoring softly.\n") ;
   }
}

string query_short() {
  if (awake) return "a Chronos doll" ;
   else return "a Chronos doll (asleep)" ;
}



int send(string str) {
  string name ;
  object who ;
  if (!str) return 0 ;
  if (sscanf(str, "doll to %s", name) != 1) {
     write("Usage: send doll to <person>\n") ;
       return 1;
  }
  who = find_player(name) ;
  name = capitalize(name) ;
  if (!who) {
     write("Chronos doll says: I cannot find "+name+" on the mud!\n") ;
      return 1;
  }
  if (environment(TP) != environment(who)) {
      write("The Chronos doll jumps down and scampers away!\n") ;
      say("A Chronos doll jumps out of "+TPN+
                 "'s arms and scampers away!\n") ;
      message("movement", 
 "A Chronos doll scampers into the room and jumps into "+
                name+"'s arms!\n",environment(who), ({ who }) ) ;
    tell_object(who,  
      "A Chronos doll scampers into the room and jumps into your arms!\n");
   } else {
     write("The Chronos doll jumps down and runs over to "+name+"!\n") ;
     message("movement", wrap("A Chronos doll jumps out of "+TPN+
       "'s arms and runs over to "+name+" and jumps into "+
            possessive(TP->query("gender")) + 
                           " arms.") , environment(TP), 
           ({ TP, who }) ) ;
       tell_object(who, "A Chronos doll scampers away from "+TPN+
            " and jumps up into your arms!\n") ;
     }
  TO->move(who) ;   
  return 1;
}

#include <mudlib.h>

inherit ARMOR ;

string spouse ;

void create() { 
  seteuid(getuid());
  set("prevent_drop", 1) ;
  set("prevent_insert", 1) ;
  set("prevent_sell",1 ) ;
  set("id", ({ "ring", "wedding ring" }) ) ;
  set("prevent_clean", 1 ) ;
  set("prevent_steal", 1) ;
  set_armor_type("ring") ;
  set("size", -1 ) ;
}

int query_auto_load() { return 1; }

void init() {
  object Spouse ;
  set("short", TPN+"'s wedding ring") ;
  spouse =  TP->query("spouse") ;
  Spouse = find_player(lower_case(spouse)) ;
  set("long", "This is your wedding ring, representing your love for "+
                 spouse+".\n  Type \"ringhelp\" for help on ring commands.\n");
  set("extra_look", "$N is married to "+spouse+".\n") ;
  add_action("ringhelp", "ringhelp") ;
  add_action("sweetblah", "sweet") ;
  add_action("blowkiss", "blowkiss") ;
  add_action("loveline", "loveline") ;
  add_action("locate", "locate" ) ;
  add_action("miss", "miss") ;
  if (Spouse && !environment()->query("invisible")) {
  tell_object(find_player(lower_case(spouse)), 
     "[*- The love of your life, "+TPN+", just logged on. -*]\n") ;
   }
}

int ringhelp() {
   write(@ENDHELP
Available commands are:

     loveline               blowkiss              miss
     locate spouse          ringhelp              sweet

Any suggestions/comments/ideas/hatemail can be forwarded to Chronos.
ENDHELP
  ) ;
  return 1;
}

int locate(string str) {
   object ob ;
  if (!str || str != "spouse") return 0 ;
  ob = find_player(lower_case(spouse)) ;
  if (!ob) {
    write("You cannot find your spouse online.\n") ;
   return 1;
  }
  if (wizardp(ob) && ob->query("invisible")) {
    write("You cannot find your spouse online.\n") ;
    return 1;
  }
  write("You sense your spouse's location..\n") ;
  write(spouse+" is at: "+environment(ob)->query("short")+"\n") ;
  say(TPN+ " concentrates for a moment.\n") ;
  tell_object(ob, "You sense "+TPN+"'s yearning for you.\n") ;
  return 1;
}

int miss(string str) {
  object ob ;
   ob = find_player(lower_case(spouse)) ;
  if (ob && environment(ob) == environment(TP)) {
    write(spouse+" is right here next to you, silly.\n") ;
  return 1;
  }
  write("You miss "+spouse+" deeply.\n") ;
  say(TPN+" misses "+possessive(TP->query("gender"))+" beloved ");
  switch(TP->query("gender")) {
    case "male": say("wife, ") ; break ;
    case "female" : say("husband, "); break ;
    default: say("spouse, ") ; break ;
  }
  say(spouse+".\n") ;
   if (ob) 
  tell_object(ob, "You sense that your beloved "+TPN+" misses you deeply.\n") ;
  return 1;
}

int loveline(string str) {
   object ob ;
   if (!str) {
    write("Usage: loveline <chat>\n") ;
    return 1;
  }
  ob = find_player(lower_case(spouse)) ;
  if (!ob || (wizardp(ob) && ob->query("invisible"))) {
    write("[LoveLine] Your spouse is not online right now.\n") ;
    return 1;
  }
  tell_object(ob, "[LoveLine] "+TPN+" says: "+str+"\n") ;
  write("[LoveLine] You say: "+str+"\n") ;
  return 1;
}

int blowkiss(string str) {
  object ob ;
   ob = find_player(lower_case(spouse)) ;
  if (ob && environment(ob) == environment(TP)) {
    write(spouse+" is right here next to you, silly.\n") ;
  return 1;
  }
  write("You blow a kiss across the world to "+spouse+".\n") ;
  say(TPN+" blows a kiss across the world to "+ possessive(TP->query("gender"))+" ");
  switch(TP->query("gender")) {
    case "male": say("wife, ") ; break ;
    case "female" : say("husband, "); break ;
    default: say("spouse, ") ; break ;
  }
  say(spouse+".\n") ;
  tell_object(ob, "You feel the warm lips of "+TPN+" as though "+
        subjective(TP->query("gender"))+" were right here next to you.\n") ;
   message("blah", spouse+" smiles as though "+
   subjective(ob->query("gender"))+ 
    " were just kissed by someone special.\n",
          environment(ob), ({ ob }) ) ;
  return 1;
} 

int sweetblah(string str) {
  object ob ;
   ob = find_player(lower_case(spouse)) ;
  if (!ob || environment(ob) != environment(TP)) {
    write(spouse+" needs to be here with you to do that action.\n") ;
    return 1;  
  }
  write("You whisper sweet nothings in "+spouse+"'s ear.\n") ;
  tell_object(ob, TPN+" whispers sweet nothings in your ear.\n") ;
  message("blah", 
   TPN +" whispers sweet nothings in "+spouse+"'s ear.\n",
          environment(ob), ({ ob, TP }) ) ;
  return 1;
} 

#include "/players/snakespear/closed/ansi.h"
inherit "/obj/treasure";

string color;

short() { 
  return (GRY+"The tell of the Gentleman"+NORM);
}

long() { 
   write("    A teller. 'wt <msg>' to tell, 'wte <msg>' to emote. \n"); 
}

id(str) { 
   return str == "teller"; 
}


init() {
   if(!environment()) detruct(this_object());
   if(this_player()->query_real_name() != "snakespear") destruct(this_object());
   add_action("wiz_tell", "wt");
   add_action("wiz_mote", "wte");
   add_action("wiz_ech", "wee");
}
wiz_tell(str) {
   object plyr;
   string who, what, myname;
   choose_color();
   if(!str) { 
      write("Tell what?\n"); 
      return 1; 
   }
   if(sscanf(str,"%s %s",who,what) != 2) {
      write("Tell <who> <what>.\n"); 
      return 1; 
   }
   plyr = find_living(who);
   myname = capitalize(this_player()->query_real_name());
   if(!plyr) { 
      write(capitalize(who)+" is not online now.\n");
      return 1; 
   }
   if(in_editor(find_player(who))) { write("Person is in edit...\n"); return 1; }
   tell_object(plyr,GRY+"["+HIW+"*"+HIR+"\\|/"+HIW+"*"+GRY+"] "+HIW+myname+" speaks: "+color+what+NORM+"\n");
   write("You tell "+capitalize(who)+": "+color+what+NORM+"\n");
   return 1;
}

wiz_mote(str) {
   object plyr;
   string who, what, myname;
   choose_color();
   if(!str) {
      write("Emote what?\n");
      return 1;
   }
   if(sscanf(str,"%s %s",who,what) != 2) {   
      write("Emote <who> <what>?\n");
      return 1;
   }
   plyr = find_living(who);   
   myname = capitalize(this_player()->query_real_name());
   if(!plyr) {
      write(capitalize(who) +" is not online now.\n");
      return 1;
   }
   if(in_editor(find_player(who))) { write("Person is in edit...\n"); return 1; }
   tell_object(plyr,GRY+"["+HIW+"*"+HIR+"\\|/"+HIW+"*"+GRY+"] "+NORM+color+myname+" "+what+NORM+"\n");
   write("Emoted to "+capitalize(who)+": "+color+myname+" "+what+NORM+"\n");
   return 1;
}
wiz_ech(str) {
   object plyr;
   string who, what, myname;
   choose_color();
   if(!str) { 
      write("Echo what?\n"); 
      return 1; 
   }
   if(sscanf(str,"%s %s",who,what) != 2) {
      write("Echo <who> <what>.\n"); 
      return 1; 
   }
   plyr = find_living(who);
   myname = capitalize(this_player()->query_real_name());
   if(!plyr) { 
      write(capitalize(who)+" is not online now.\n");
      return 1; 
   }
   if(in_editor(find_player(who))) { write("Person is in edit...\n"); return 1; }
   tell_object(plyr,GRY+"["+HIW+"*"+HIR+"\\|/"+HIW+"*"+GRY+"] "+color+what+NORM+"\n");
   write("You echo to "+capitalize(who)+": "+color+what+NORM+"\n");
   return 1;
}
drop() { return 1; }

choose_color() {
   int blah;
   blah = random(14);
   switch(blah) {
   case 0:      color = RED; break;
   case 1:      color = GRN; break;
   case 2:      color = YEL; break;
   case 3:      color = BLU; break;
   case 4:      color = MAG; break;
   case 5:      color = CYN; break;
   case 6:      color = BOLD+BLK; break;
   case 7:      color = HIR; break;
   case 8:      color = HIG; break;
   case 9:      color = HIY; break;
   case 10:     color = HIB; break;
   case 11:     color = HIM; break;
   case 12:     color = HIC; break;
   case 13:     color = HIW; break;
   }
   return 1;
}


   

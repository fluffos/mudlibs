/*
** File: m8ball.c
** Purpose: Well, mostly because tarot cards are too much of a
**    bother to code...
** Credits:
**    01 Jul 97  Cyanide created the file.
*/

#include <mudlib.h>

inherit WEAPON;

// Prototypes:
int shake (string);
void f_message();
void shaken (object);

string says;

void create() {
   set("short", "a Magic 8-Ball (tm)");    
   set ("long", "@@query_long");
   set ("mass", 1);
   set ("id", ({ "8-ball", "ball", "magic ball"}) );
   set("name", "Magic 8 Ball");
   set_weapon_type("club");
   set_verbs ( ({ "shake", "thwop", "whomp"}) );
   set ("value", 3);
   f_message();
}

void init() {
  add_action("shake", "shake");
}

int shake (string ball) {
   if ((ball!="8-ball") && (ball!="ball")) {
      write("Shake what?\n");
      return 1;
   }
   say (TPN+" shakes "+POSS+" Magic 8-ball (tm).\n"); 
   write("You joyfully shake your Magic 8-ball.\n");    

   f_message();
   call_out("shaken", 2, this_player());   
   return 1;
}

void f_message() {
   switch(random(8)) {  
      case 0 : says = "Yes"; break; 
      case 1 : says = "My sources say yes"; break; 
      case 2 : says = "No"; break; 
      case 3 : says = "My sources say no"; break; 
      case 4 : says = "Maybe"; break;         
      case 5 : says = "Ask again later"; break; 
      case 6 : says = "Prospects look good"; break; 
      case 7 : says = "Prospects not so good"; break; 
   }
}

void shaken (object ob) {
   tell_object(ob, "A single cryptic message slowly becomes "+
      "visible in the\nsphere's window: \n");
   tell_object(ob, "\t\""+says+"\".\n");
   return ;
}

string query_long() {
   string short;

   short = (@EndShort
It seems to be a largish black sphere about four inches in 
diameter and bearing a small round window, opposite of which
a white numeral "8" is painted. Within the window is a simple,
cryptic message:
EndShort
);
  short += "\t\""+says+"\".\n";

  return short;
}

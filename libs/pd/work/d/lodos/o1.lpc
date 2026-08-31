#include <std.h>
#include <lodos.h>                                         
inherit VAULT;

void create() {
 ::create();
   set_short("Obstacle Course: Prep Room");
   set_long("%^RESET%^%^ORANGE%^"
     "This room is a large grey slab floating in the middle of "
     "nowhere. A tall dark man is here. A door floats in midair to the "
     "south. All around, is only white space as far as the eye can see. "
     "The grey stone slab is smooth and flawless. You somehow doubt that "
     "their is neither night nor day in this place.");
   set_items(([
     "door" : "For one reason or another, the door just floats there.",
     "slab" : "A stone slab floating in the middle of nowhere.. how odd.",
     "sky"  : "The sky is a white expanse as far as the eye can see."
   ]));
   set_properties(([ "light" : 2, "night light" : 2, "outdoors" : 1,
     "no bump" : 1, "no attack" : 1, "no magic" : 1, "no teleport" : 1,
     "no steal" : 1 ]));
   set_door("door", ROOMS"o2", "south", "");

   set_exits(([
     "quit"  : ROOMS"l1m8"
   ]));
}

int explain(string str) {
   if (!str || str != "rules") return 0;
   if (!present("obrinutine", this_object())) return 0;
   write("%^RESET%^%^CYAN%^The man says:%^RESET%^ If you are here "
     "attempting to become an angel, then this course is for you. If you "
     "are not, I suggest you <quit> and tell noone that you were here. The "
     "following is an obstacle course for those true of heart and spirit. "
     "When you are ready to being, <start> so I know when to start my "
     "watch. Remember, you must do this alone, not with a friend or ally "
     "of any sort. Once you have <start>ed, go south and your obstable "
     "course will begin. When you have reached the end of the course, you "
     "will find a flag. Bring that flag back and <give flag to man>. Only "
     "when you give me that flag will I stop the timer and tell you how "
     "you did. I will give you one hint; pay close attention to "
     "your surroundings. You may try the obstacle course as many times as "
     "you wish, so you may want to go through and take your time at first. "
     "Good luck!");
   return 1;
}

int try_give(string str) {
   object ob;
   if (!str || str != "flag to man") return 0;
   if (!(ob = present("obrinutine", this_object()))) return 0;
   if (!present("obstacleflag", this_player())) return 0;
   else present("obstacleflag", this_player())->remove();
   write("You give a red flag to man.");
   write("Man stops his timer.");
   write("%^RESET%^%^CYAN%^The man says:%^RESET%^ You did good, "
     +this_player()->query_cap_name()+".");
   write("The man looks at his stop watch and shakes his head.");
   if (ob->query_time() >= 198)
     write("%^RESET%^%^CYAN%^The man says:%^RESET%^ I'm sorry to say you "
       "took too long, my friend.");
   else
     write("%^RESET%^%^CYAN%^The man says:%^RESET%^ I'm sorry to say you "
       "went too fast, how can I be sure you were not cheating? Please "
       "slow down, this is no race!");
   ob->stop_timer();
   return 1;
}

int start() {
   object ob;
   if (! (ob = present("obrinutine", this_object()))) return 0;
    if (!this_player()->query_mini_quests() || sizeof(this_player()->query_mini_quests()) < 9) {
      write("%^RESET%^%^CYAN%^The man says:%^RESET%^ I'm sorry, but you must "
        "prove your worth through good deeds before you may enter here.");
      return 1;
    }
   ob->start_timer();
   write("%^RESET%^%^CYAN%^The man says:%^RESET%^ You can <stop> the timer "
     "at any time if you give up or want to start over. Ready? Go!");
   if (member_array("south", query_exits()) == -1)
     add_exit(ROOMS"o2", "south");
   return 1;
}

int stop() {
   object ob;
   if (! (ob = present("obrinutine", this_object()))) return 0;
   ob->stop_timer();
   write("%^RESET%^%^CYAN%^The man says:%^RESET%^ Time stopped.");
   return 1;
}


void init() {
 ::init();
   add_action("explain", "explain");
   add_action("start", "start");
   add_action("stop", "stop");
   add_action("try_give", "give");
}

void reset() {
 ::reset();
   if (!present("obrinutine"))
     make(MOB"obrinutine");
}

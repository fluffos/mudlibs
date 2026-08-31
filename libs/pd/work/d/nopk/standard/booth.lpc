//     /d/standard/booth.c
//     from the Nightmare mudlib
//     voting booth
//     created by Gregon@Nightmare Jan 1994
 
#include <daemons.h>
#include <std.h>
#include <sindarii.h>
inherit ROOM;
 
int a,b;
mapping vote;
 
void create() {
  ::create();
  set("short", "Carnage referendum room");
  set_property("light", 2);
  set_property("indoors", 1);
  set("long",
       "This is the referendum room of Carnage.  Players come here to vote "
       "on issues that the wizards desire input on.  The current voting "
       "question is posted on the wall <read question> will display it."); 
   
      set_exits( (["down" : ROOMS"adv_main"]) );
  vote=([]);
  restore_object(DATAS"votes");
}

void init() {
  ::init();
  add_action("vote", "vote");
  add_action("read", "read");
  if(archp(this_player())) add_action("check", "check");
  
}
 
int vote(string str) {
    string me;
 
    me=(string)this_player()->query_name();
    if(str!="a" && str!="b") {
       notify_fail("You may only vote for a or b.\n");
       return 0;
    }
    if(MULTI_D->non_voter(me)) {
       write("You are listed as a second character.  You may not vote.");
       return 1;
    }
    if(vote[me]) {
       write("You have already voted.");
       return 1;
    }
    if(str=="a") {
      vote[me]="a";
      a++;
      write("Vote counted.  Thank you.");
      save_object("/d/standard/data/votes");
      return 1;
    }
    if(str=="b") {
      vote[me]="b";
      b++;
      write("Vote counted.  Thank you.");
      save_object(DATAS"votes");
      return 1;
    }
    
}
 
int read(string str) {
    if(!str || str != "question") return 0;
    write("The current voting question is this:\n\n"
          "Should we have the kataan class?\n"
	  "\nYou may vote one of two ways:\n\n"
          "A. No, the kataan class is too much like a rogue/cleric "
          "and would undermine both the clerics and the rogues.\n"
          "B. Yes, but restrict their abilites severely. "
           "\n"
	  "\nTo vote for one of these choices, type <vote a> or <vote b>.  Of "
	  "course you may only vote once, and seconds are not allowed to vote."
	  );
    return 1;
}
 
int check(){
   write("A: "+a+"\nB: "+b);
   return 1;
}

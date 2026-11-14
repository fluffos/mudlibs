#include <properties.h>

inherit "/std/npc";

int waiting,wake,count;

create() {
  if (::create()) return 1;
  SetName("Scott");
  AddId("montgomery");
  AddId("scotty");
  SetShort("Montgomery Scott");
  SetRace("human");
  SetLevel(3);
  SetHands( ({ ({"left hand",0,6}),({"right hand",0,6}) }) );
  SetAC(1);
  SetGender(GENDER_MALE);
  SetAlign(1000);
  enable_commands();
  waiting=0;
  reset();
}

reset() {
  if (!waiting) test();
  wake=0;
}

init() {
  ::init();
  add_action("kick","kick");
}

QueryLong() {
    if (!wake) {
       return "This is the chief engenieer of the spaceship Enterprise. "+
	      "He sleeps like a log and his snoring sounds like "+
	      "a power saw. It seems this guy needs a very hard kick "+
	      "to wake up.\n";
    }
    return "This is the chief engenieer of the Enterprise.\n";
}

kick(string str) {
    if (str!="scott" && str!="montgomery") return;
    if (wake) {write("Scott says: OUTCH!\n"); return 1; }
    write("Scott murmurs: Where is my coffee? Then he falls asleep again.\n");
    write("You think this guy needs very much coffee to wake up. Strong coffee.\n");
    write("Very strong coffee. Espresso coffee ...\n");
    return 1;
}

test() {
   waiting=1;
   if (!present("espresso",this_object())) call_out("test",5);
   else drink_drink();
}

drink_drink() {
   object esp;
   waiting=0;
   if (!present("espresso",this_object())) return;
   wake=1;
   count=0;
   esp=present("espresso",this_object());
   if (esp) esp->remove();
   say("Mr. Scott drinks a hot espresso.\n");
   call_out("do_action",3);
}

do_action() {
   count++;
   switch(count) {
     case 1: say("Mr. Scott awakes.\n"); call_out("do_action",3); break;
     case 2: init(); call_out("do_action",5); break;
     case 3: say("Mr Scott says: Oh! I have some work to do. Bye!\n");
	     call_out("do_action",2); break;
     case 4: command_me("east"); call_out("do_action",3); break;
     case 5: command_me("south"); call_out("do_action",3); break;
     case 6: command_me("west"); call_out("do_action",5); break;
     case 7: say("Mr. Scott begins to repair the transporter.\n");
	     call_out("do_action",3);
     case 8: say("It seems to be a very difficult repair; it takes more than 3 seconds.\n");
	     call_out("do_action",5);
     case 9: say("Mr. Scott shouts: Now the work is done. I have fixed the cable\n"+
		 "for the power supply.\n"); call_out("do_action",3);
		 call_other(environment(this_object()),"repair_trans");
	     break;
     case 10: say("Mr. Scott leaves to some place.\n"); destruct(this_object()); break;
     default: say("Mr. Scott sighs.\n");
   }
}

//  Created by Whit
#include <std.h>
#include <citrin.h>

inherit ROOM;

object tp;
int search, yes;

void create() {
    ::create();
    set_name("High in the Sky");
    set_short("High in the Sky");
    set_long("The walls of this room are made of pure marble.  Stone pillars "
      "stand tall in the center and corners of the room.  In the center "
      "of the pillars is an altar.  A spirit floats overtop of the altar.  "
      "Your motionless body has been laid down on what looks to be a pentagram.");
}

void init() {
    ::init();
    add_action("block_cmd", "");
}

int block_cmd(string str) {
    if(yes == 1) {
	if(query_verb() == "say") {
	    if(str == "Sic Para Bellum") {
		remove_call_out("delay_death");
		write("%^CYAN%^You mutter to yourself: %^RESET%^Sic Para Bellum\n");
		write("Instantly, the spirits begin to screan in %^BOLD%^%^RED%^agony.\n");
		call_out("end", 3);
		return 1;
	    }
	    write("Nothing happens.\n");
	}
    }
    if(this_player()->query_name() == "whit") return 0;
    write("You are motionless laying on the floor.\n");
    return 1;
}

int start(object ob) {
    tp = ob;
    write("You remain uncontious for just a second.  When you come to you have "
      "no feeling.  By the huge mirror on the ceiling you can see that "
      "you are laying on a pentagram.");
    call_out("a", 4);
}

int a() {
    write("%^CYAN%^The spirit says: %^RESET%^Ahh, so you finally awaken.  "
      "I must thank you very much for releasing me and my friends from deep "
      "within the soul chamber hidden within the Citrin Forest.");
    call_out("b", 5);
}

int b() {
    write("%^CYAN%^The spirit says: %^RESET%^  We have "
      "been held there for a long time.  Thankfully, you have released us.  "
      "We can now set out and finish our mission.  We need a mortal soul "
      "to sacrifice to the gods of the underworld.  Only then shall our "
      "bodies be reincarnated.");
    call_out("c", 8);
}

int c() {
    write("%^CYAN%^The spirit says: %^RESET%^See,  if we can "
      "be reincarnated, we will be able to take over the world.  "
      "We also though that when we would be released it would be "
      "hard to find a willing soul.  But fortuantly, we have you.");
    call_out("d", 10);
}

int d() {
    write("%^CYAN%^The spirit says: %^RESET%^So "+tp->query_cap_name()
      +" are you ready to become our sacrifice?\n");
    write("\n%^CYAN%^A strange voice enters your head.  It says: %^RESET%^Remember "
      "the sacred incantation.  What releases them will also "
      "imprison them.\n");
    call_out("delay_death", 20);
    yes=1;
}

int delay_death() {
    write("%^CYAN%^The spirit says: %^RESET%^So you will good.  Then DIE!\n");
    call_out("delay_death_die_already", 2);
}

int delay_death_die_already() {
    write("The spirit raises your hand.  A burning sensation is felt "
      "throughout your entire body as it is turned to ash.\n");
    write("Write before you die, you hear the spirit yell:  IT DIDNT WORK!\n");
    tp->die();
}

int end() {
    write("The spirits slowly decipate into the floor.  Your body once "
      "again regains motion.  You are moved back to the stones.\n");
    tp->move("/d/citrin/rooms/stones");
}


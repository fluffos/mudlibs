//  Created by Whit

#include <std.h>
#include <citrin.h>

inherit MONSTER;

int done;

void create() {
    ::create();
    set_name("guardian");
    set_long("This guardian is one of "
      "the many guardians of the forest.  The guardian "
      "seems to have a worried look on its face.");
    set_short("forest guardian");
    set_id(({"goblin","dark goblin"}));
    set_race("goblin");
    set_body_type("goblin");
    if(random(2))
        set_level(70);
    else set_level(70);
    if(random(2))
        set_gender("male");
    else set_gender("female");
    set_property("passive", 1);
    set_emotes(15, ({"The guardian paces about, obviously thinking of what to do."
      , "The guardian stares up at the white wall of petrified wood."}), 0);
}

void init() {
   ::init();
   add_action("ftalk", "talk");
}

void ftalk() {
   if(!wizardp(this_player())) return;
   if(done) return;
   done=1;
   this_object()->force_me("say It seems something has happened in the realms.  Something "
     "that could prove to be very dangerous if loosed.  I have managed to seal the forest "
     "to prevent the possiblity.");
   call_out("continue1", 30);
}

int continue1() {
   this_object()->force_me("say If you all will be of service to me, and venture into "
     "the forest and help destroy what lurks in the shadows, I and my fellow guardians "
     "will stop hunting the people that venture into the forest.");
   call_out("continue2", 30);
}

int continue2() {
   this_object()->force_me("say To enter the forest, you can climb the outter wall "
     "only in this spot.  To prevent anyone from entering parts of the forest "
     "already doomed, I have cast a spell that will not allow gating of any "
     "sorts.");
}


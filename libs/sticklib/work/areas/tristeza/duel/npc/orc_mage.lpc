#include <npc.h>
#include <daemons.h>
#include <quests.h>
#include <areas.h>

#define	END_ROOM	"/u/tron/virtual/world/nrooms/puzzle_room"

void
create_monster() {

    set_level(30);
    set_hp(1200);
    set_name("Ghost of Orchinie");
    set_id(({"ghost", "orchinie", "ghost of orchinie"}));
    set_short("The Ghost of Orchinie");
    set_long("It's mostly transparent ghost with burning red eyes.");
    set_wc(35);
    set_ac(30);
    set_chance(10);
    set_spell_dam(80);
    set_alignment(-500);
    set_spell_mess2("You are hit by a vibrating electric flare.");
    set_spell_mess1("Ghost of Orchius launches a vibrating flare.");

    load_a_chat(8, ({ "The ghost screams: You came to steal my cloak!",
	"The ghost groans: You puny mortal, you die!",
	"The ghost says: You will never get the cloak!",
	"The ghost shouts: You dared to disturb my peace, don't ask why you die!."}));

    set(NPC_AGGRESSIVE);
    set(LIV_UNDEAD);
    set_dead_ob(this_object());
}

int
monster_died() {

    if(!this_player()) return 0;

    if(find_object(AREA_TRISTEZA "duel/obj/cloak")) {
	this_player()->tell_me("The last words you hear the ghost say: I told you, no cloak. It was stolen, I hate to admit.");
    }
    else {
	this_player()->tell_me("The ghost says: You are strong enough to carry"+
	  " the cloak. Wear it with pride.");
	move_object(AREA_TRISTEZA "duel/obj/cloak", environment());
	command("get cloak", this_player());
    }

    if(QUEST_D->add_quest(this_player(),QUEST_CLOAK)) {
	write("You solved the quest! You feel more experienced.\n");
	// Quest daemon adds the exp now
	//      this_player()->add_exp(10000);
    }
    this_player()->move_player("X", END_ROOM);
}   

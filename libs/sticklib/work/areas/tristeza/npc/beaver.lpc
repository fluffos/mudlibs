#include <npc.h>

int
prevent_stab(object att)
{
    att->tell_me("This beaver is too quick to be stabbed!");
    return 1;
} 

void
create_monster()
{
    set_level(3);
    set_name("beaver");
    set_short("Happy Beaver");
    set_race("beaver");
    set_long("This happy beaver looks funny. It has a flat tail, \
and a big, stupid grin. Looks like it has escaped from \
someone's Beaver Den.");
    // set(NPC_NOT_AGGRESSIVE);
    load_chat(8, ({
	"Beaver looks like it's saying: Eat me!",
	"Beaver chews on your leg.",
	"Beaver looks happy.",
	"Beaver wiggles its flat tail.",
	"Beaver picks up some wood and twigs.",
	"Beaver chews on some wood.",
	"Beaver grunts and looks a bit worried.",
	"Beaver grunts.",
	"Beaver grumbles.",
	"Beaver seems to be thinking hard."}));
    set_wander(11);
} 

// random_move()
// {
//    command(({"north","south","east","west",
//       "northwest","southwest","northeast","southwest"})[random(8)]);
// }

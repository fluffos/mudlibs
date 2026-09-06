/* Sewer Rat - some may have the plague */
#include <npc.h>
#include "../DEFS.h"

int infected;

void
create_monster()
{
    set_level(2);
    set_wc(6);
    set_ac(5); /* Quick-n-small */
    set_name("sewer rat");
    set_short("Sewer rat");
    set_race("rat");
    set(NPC_AGGRESSIVE);
    set_wander(11);

    if(!random(10)) { set_long("This rat seems to be sick."); infected = 1; }
    else infected = 0;
}

/* Redefined attack() for possible infection */
attack() {
    int att;
    object att2;

    att = ::attack();
    if (infected && att && !random(40) && (att2 = query_attack()) &&
      !present("plague",att2))
	move_object(clone_object(OBJ_DIR+"plague"), att2);
    return att;
}

/* Redefine random_move(): don't wander out of own level */
random_move()
{
    command(({"north","south","east","west",
	"northwest","southwest","northeast","southwest"})[random(8)]);
}

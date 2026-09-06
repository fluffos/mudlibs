#include <npc.h>

#include <disease.h>

void
create_monster()
{
    object disease;

    set_name("beggar");
    set_level(2 + random(4));
    set_money(level * random(10));
    set_alignment(query_level() * 50);
    set_race("human");
    set_gender(random(2) ? G_MALE : G_FEMALE);
    set_long("A really filthy looking poor beggar.");
    set_random_pick(7);
    set_wander(6);

    if(random(100) < 30) {
	disease = clone_object(GENERIC_DISEASE_PLAGUE);
	move_object(disease,this_object());
    }
}

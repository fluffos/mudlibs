// Sakura

#include <std.h>
#include <sakura.h>
inherit MONSTER;


void create() {
    ::create();
    set_name("ant");
    set_short("Worker Ant");
    set_id(({"ant", "worker ant"}));
    set_level(30);
    set_race("Giant Ant");
    set_body_type("ant");
    set_gender("neuter");
    set_long("Almost a meters long, these giant ants are a disturbing sight. They have eight spindly legs and an insectoid face; their mandibles are not overly huge but could do substancial damage with a good bite. Just to make things worse, they drip with a corrosive acid which the ants spray at anything they bite. The acid is far more then regular ant's, as well, and has been known to melt through even the hardest of armour.");

    set_die( (: call_other, this_object(), "death_func":) );

}

int death_func() {

    message("say", "The ant chitters painfully as it's blood oozes from between the cracks in it's exoskeleton, curling up into a ball as it dies from it's wounds.", environment(this_object()));

    return 1;
}

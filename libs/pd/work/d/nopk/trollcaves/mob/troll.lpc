#include <std.h>
#include <sakura.h>
inherit MONSTER;

string heorshe;

void create() {
    ::create();
    set_name("troll");
    set_short("A Troll");
    set_id(({"troll"}));
    set_level(random(5)+13);
    set_race("troll");
    set_body_type("human");
    if(random(2) == 1) { set_gender("male"); heorshe = "he";}
    else { set_gender("female"); heorshe = "she";}
    set_long("Standing at almost eight feet tall, the lankey troll is hunched over in this cramped tunnel. With a dark green/blue skin and covered in hairy warts, this creature looks as disgusting as "+heorshe+" smells; considering the absolutely foul stench eminating from this creature that seems to burn at your nostrils, this is quite a statement. It's fingers and toes each end in large, black claws which it could use most effectively to slice and dice whatever they were applied to.");
    set_die( (: call_other, this_object(), "death_func":) );

    swarm = 1;

}

int death_func() {

    message("say", "The troll emits a howl and falls to the ground, blood spraying out from a variety of wounds. It trashes for a moment, then is quiet.", environment(this_object()));
    return 1;
}

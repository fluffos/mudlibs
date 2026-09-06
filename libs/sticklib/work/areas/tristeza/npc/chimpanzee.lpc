#include <npc.h>

status executing;

void create_monster()
{
    set_name("chimpanzee");
    set_id(({ "chimp", "monkey" }));
    set_race("ape");
    set_short("A cute little chimpanzee");
    set_long("Oh, isn't this a cute little chimpanzee! It makes you feel "+
      "like ruffling its glistening fur. The chimp grins at you "+
      "mischievously.");
    set_level(3);
    set_wc(5);
    set_ac(15);
    set_wimpy();
    set_spell_mess1("The chimp throws a rock with an uncanny accuracy.");
    set_spell_mess2("The chimp hits you with a well thrown rock.");
    set_spell_chance(50);
    set_spell_dam(5);
}

catch_tell() {
    string who;
    if(!this_player() || !query_verb() || this_player() == this_object() ||
      !(who = this_player()->query_name()))
	return;
    call_out("perform", 0, query_verb()+" "+lower_case(who));
}

perform(cmd) {
    command(cmd);
}

query_ob() { return this_object(); }

#include <std.h>
#include <cp.h>
inherit MONSTER;

void check_quest(string *what);

create() {
         ::create();
         set_name("Minotuar Shaman");
         set_id(({ "minotaur", "shaman", "minogaur shaman" }));
         set_short("A Minotaur shaman");
         set_long("The gigantic shaman is lost in a prayer. He "
                 "appears to be sad, slightly frowning. One of "
                 "his horns is partially broken while the other "
                 "still comes to a sharp point.");
         set_race("minotaur");
         set_class("fighter");
         set_subclass("berserker");
         set_money("platinum", 40);
         set_body_type("minotaur");
         set("aggressive", 0);
         set_gender("male");
         set_level(80);
         set_spell_chance(50);
         set_spells(({"jab"}));
}
void catch_tell(string str) {
    object ob;
    string a, b;

    if(this_player() == (ob = this_object())) return;
    if(sscanf(str, "%squest%s", a, b) == 2) {
        this_object()->force_me("say Ahh, the gods have answered "
         "my countless prayers I see. Yes, I do have a task I "
	 "need completed. My mask.. my mask is missing.");
        return;
    }
    if(sscanf(str, "%smask%s", a, b) == 2) {
        this_object()->force_me("say Yes, my prized mask. "
         "It was given to me decades ago by my teacher. "
	 "I fear it's in the hands of that damned Ogre who "
	 "claims to be shaman. Bah, imposters. Anyway, if "
	 "you would be so kind as to retrieve it for me, "
	 "I'm sure the gods would smile upon you. The dream "
	 "shown to me last night showed the cursed Ogre "
	 "encased in the earth and surrounded by hundreds of "
	 "red ants.");
        return;
    }
    if(sscanf(str, "%s gives you %s", a, b) == 2) {
        call_out("check_quest", 2, ({ lower_case(a), lower_case(b) }) );
    }
}

void check_quest( string *what ) {
    object tp, ob;
    string who, that;

    who = what[0];
    that = what[1];
    tp = present(who, environment(this_object()));
    ob = present("mask");
    if(!tp) return;
    if(!ob) {
        tell_object(tp, "The shaman grunts.");
        return;
    }
    if(!ob->id("voodoo mask")) {
        tell_object(ob, "Minotaur shaman says: This "
         "is not what I seek.");
        force_me("give "+that+" to "+who);
        return;
    }
    tell_room(environment(this_object()), "The shamans face lights up.",
      this_object());
    tell_object(tp, "%^RESET%^%^CYAN%^Minotaur shaman says:%^RESET%^ My "
         "prayers have been answered indeed!");
    if(!tp->set_mini_quest("mask", 100, "You returned a voodoo "
         "mask to the Minotaur shaman.\n"))
        tp->add_exp(1000000+random(250000));
}

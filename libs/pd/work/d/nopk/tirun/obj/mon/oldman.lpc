#include <std.h>
#include <tirun.h>

inherit MONSTER;

void check_quest(string *what);

void create() {
    ::create();
    set_name("old man");
    set("id",  ({ "man", "old man", "monster" }) );
    set("short", "an old man");
    set_gender("male");
    set("aggressive", 0);
    set_class("mage");
    set_subclass("wizard");
    set_skill("magic attack", 200);
    set_level(28);
    set("long", "The old man fidgets nervously.  He seems worried about something.");
    set_alignment(1000);
    set("race", "human");
    set_max_hp(100000);
    set_hp(100000);
    set_spells(({"blast"}));
    set_spell_chance(70);
    set_body_type("human");
}

void catch_tell(string str) {
    object ob;
    string a, b;

    if(this_player() == (ob = this_object())) return;
    if(sscanf(str, "%squest%s", a, b) == 2) {
	this_object()->force_me("say Could you help me?  I seem to have lost my book.");
	return;
    }
    if(sscanf(str, "%sbook%s", a, b) == 2) {
	this_object()->force_me("say It is a very special book.  It is bound in stone.  You cant miss it.");
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
    ob = present("book");
    if(!tp) return;
    if(!ob) {
	tell_object(tp, "An old man looks at you quizzically.");
	return;
    }
    if(!ob->id("stone_book_qo")) {
	tell_object(ob, "%^CYAN%^An old man says: %^RESET%^This is very nice, but I do not need it.");
	force_me("give "+that+" to "+who);
	return;
    }
    tell_room(environment(this_object()), "The old man smiles and begins rummaging through his belongings.",
      this_object());
    tell_object(tp, "%^RESET%^%^CYAN%^An old man says:%^RESET%^ Thank you very much for helping me.  This is the least I can do in return.");
    ob->remove();
    ob = new("/d/nopk/tirun/obj/misc/itorch");
    ob->move(this_object());
    this_object()->force_me("give torch to "+tp->query_name());
    if(!tp->set_mini_quest("stone book", 100, "You found the old mage's lost book.\n"))
	tp->add_exp(200+random(200));
}

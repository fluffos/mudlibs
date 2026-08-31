#include <std.h>
#include <tirun.h>
#include <vampq.h>
inherit MONSTER;
void check_quest(string *what);
void catch_tell(string str);
void create() {
    ::create();
    set_name("vampire");
    set_id( ({ "ghost", "undead", "vampire", "human", "man" }) );
    set("short", "a pale-skinned man");
    set("aggressive", 9);
    set_level(12);
    set("long", "The man's long, ebony fangs glisten in the little light of the room. His face is blood stained and he appears angry.");
    set_alignment(-100);
    set("race", "vampire");
    set_property("no_corpse", 1);
    set_gender("male");
    set_money("platinum",random(30));
    set_body_type("human");
    set_die( "The vampire falls %^RED%^dead%^RESET%^ before you.\nThe corpse turns to dust and blows away." );
    set_emotes(2, ({
	"The Pale-skinned Man mummbles something about being thirsty for blood.",
	"%^CYAN%^The Pale-skinned Man says:%^RESET%^ I lost my flask, I need it in a flask.",
	"The Pale-skinned Man mummbles secrets about vampires.",
	"The Pale-skinned man stares at your neck as if thirsty for blood."
      }), 0);
    new(VO"vampire_fang")->move(this_object());
}

void catch_tell(string str) {
    object tp, ob;
    string a, b;
    tp = this_player();

    if(this_player() == (ob = this_object())) return;
    if(sscanf(str, "%sflask to vampire%s", a, b) == 2) {
	write("%^CYAN%^A Pale-skinned man says:%^RESET%^ Thank you!");
	write("A Pale-skinned man takes a long drink from the flask and is rejuvenated.");
	write("\n%^CYAN%^A Pale-skinned man says:%^RESET%^ For helping me I will help you.");
	write("A Pale-skinned man places his hand on your temple and pulls you in a trance.");
	this_player()->move_player(VR"transroom1");
	find_object(VR"transroom4")->start_fmv("vampire");
	this_player()->add_hp(-200);
	return;
    }
}
void check_quest( string *what ) {
    object tp, ob;
    string who, that;

    who = what[0];
    that = what[1];
    tp = present(who, environment(this_object()));
    ob = present("flask");
    if(!tp) return;
    if(!ob) {
	tell_object(tp, "The Pale-skinned man stares at your neck as if thirsty for blood.");
	return;
    }
    if(!ob->id("flask")) {
	tell_object(ob, "%^CYAN%^The Pale-skinned man says: %^RESET%^If you try to bring me something useless again I'm going to bite you.");
	force_me("give "+that+" to "+who);
	return;
    }

}

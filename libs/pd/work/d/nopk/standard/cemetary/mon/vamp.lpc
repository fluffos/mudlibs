#include <std.h>
inherit MONSTER;

void create() {
 ::create();
   set_name("vampire");
   set_id( ({ "ghost", "undead", "vampire", "human", "man" }) );
   set("short", "a pale-skinned man");
   set("aggressive", 9);
   set_level(12);
   set("long", "The man's long, ebony fangs glisten in the little "
       "light of the room. His face is blood stained and he appears "
       "angry.");
   set_alignment(-100);
   set("race", "vampire");
   set_property("no_corpse", 1);
   set_gender("male");
   set_money("platinum",random(30));
   set_body_type("human");
   set_die( "The vampire falls %^RED%^dead%^RESET%^ before you.\nThe corpse turns to dust and blows away." );
}

void catch_tell(string str) {
    object ob;
    string a, b;

    if(sscanf(str, "%s says: %s", a, b) == 2) {
	ob = present( lower_case(a), environment(this_object()));
	if(ob) {
           tell_room(environment(this_object()), "The vampire glowers.", ({ this_object() }));
           force_me("say Shutup, "+a+".");
	}
    }
}

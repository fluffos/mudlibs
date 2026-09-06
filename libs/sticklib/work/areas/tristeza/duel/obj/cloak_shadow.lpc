#include "/sys/configuration.h"

#include <visibility.h>

object shadowed;

nomask void
do_shadow(object ob) {
    if(!ob) return;
    if(shadow(ob)) {
	shadowed = ob;
	configure_object(this_object(), OC_HEART_BEAT, 1);
    }
}

void
heart_beat() {
    if(!shadowed) {
	destruct(this_object());
	return;
    }

    if(!shadowed->query_invis()) shadowed->set_invis(INVISIBLE);

    if(!random(10)) {
	tell_room(environment(shadowed),
	  ({ "A cloaked figure lurks in the shadows.\n",
	    "A vaguely transparent cloaked creature floats in the air.\n",
	    "Blue sparks whirl in the air when a strange cloaked figure"+
	    " decides to vanish.\n",
	    "The air vibrates around a cloaked figure.\n",
	    "A black cloaked figure stares at you with burning red eyes.\n" })[random(5)], ({shadowed}));
    }
}

status
query_prevent_where() { return 1; }

string
short() { return "A cloaked figure"; }

string
query_name() { return "Cloaked figure"; }

string
query_long() {
    string s;

    this_player()->tell_me(({"You see two burning red eyes stare at you from"+
	" the cover of a strange black cloak. You shiver"+
	" from cold and turn your head away as quickly as"+
	" you can.",
	"You see a faint shape of somone hiding in the "+
	"cover of a pitch black cloak. Suddenly the "+
	"shape changes to a bunch of blue sparks whirling "+
	"around inside the cloak.",
	"The figure vanishes.",
	"You feel sick, the world turns upside down. Just "+
	"when you start to fall, you manage to maintain "+
	"your balance. The figure hides in the shadows.",
	"You stare and see something: "+
	((s=(string)this_player()->query_desc()) ? s :
	  "nothing."),
	"There is nothing there."
      }) [random(6)]);
}

status
id(string s) {
    if(s && (s == "a cloaked figure" || s == "cloaked figure" 
	|| s == "figure")) return 1;
}

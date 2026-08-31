//  Created by Whit
#include <std.h>
#include <citrin.h>
inherit OBJECT;

void create() {
    ::create();
    set_name("a sign");
    set_short("a run down sign");
    set_long("The sign has been battered "
      "up and is hard to read.");
    set_prevent_get("The sign is tight in "
      "the ground.");
    set_id(({"run down sign","sign"}));
}

void init() {
    ::init();
    add_action("read_sign", "read");
}

int read_sign(string str) {
    if(!str || str != "sign") {
	write("Read what?\n");
	return 1;
    }
    say(this_player()->query_cap_name()+" "
      "reads the sign.");
    write("The sign is old and hard to "
      "read.  Only a few letters can be made "
      "out of it.");
    write("\nTu.n a... .ow ..for. .ts .oo ..te.");
    write("You cannot make out anymore of it.");
    call_out("sign_remove", 20);
    return 1;
}

int sign_remove() {
    tell_object(environment(this_object()), 
      "A lightening bolt comes from the skies and destroys the "
      "sign leaving a hole where it once stood.");
    this_object()->remove();
    return 1;
}


#include <mudlib.h>
#include <path.h>

inherit MONSTER ;

void create () {
    ::create();
    set("short", "Jessica, the hologram");
    set("long", @Endtext
She is a hologram projected to serve as a representative for the
immortals to determine wizship eligibility.  If you wish to know
the requirements, type <inquire> for a listing.  If you meet these
standards and wish to become a wizard, type <advance> to join the
ranks of the immortals.
Endtext
    );
    set("prevent_summon", 1);
    set("id", ({ "jessica", "hologram" }) );
    set_name("jessica");
    set_living_name("jessica");
    enable_commands();
    set("no_attack", 1);
    set("race", "hologram");
    set("gender", "female");
    set("chat_chance", 5);
    set("chat_output", ({
      "Jessica fizzles out of sight for a second.\n",
    }) );
    set_level(1);
}

void init() {
    add_action("kill_me", "kill");
}

int kill_me(string str) {
    if(str == "jessica" || str == "hologram") {
	write("You attack passes right through Jessica.\n");
	say(TPCN+ " tried to attack the hologram.\n");
	return 1;
    }
    return 0;
}

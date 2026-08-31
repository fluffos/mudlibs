// Sakura

#include <std.h>
inherit MONSTER;

string revealed = "no";

void create() {
    ::create();
    set_name("figure");
    set_short("%^BOLD%^%^WHITE%^A ghostly, demonic figure");
    set_id(({"figure"}));
    set_level(1000);
    set_race("demon");
    set_body_type("demon");
    set_gender("male");
    set_long("This huge, translucent demonic figure stands over seventeen feet tall. His skin is a blotchy black colour, apart from two massive ivory horns which grow from his forehead and two coal black batlike wings which sprout from his back.");

}

int is_invincible() {

    if (revealed = "yes"){

	message("say", this_player()->query_cap_name()+" attempts to engage the Asmodeus, but is repulsed by a strange black light.", environment(this_object()), this_player());
	message("say", "A strange black light bursts forth from Asmodeus, repulsing you.", this_player());
	return 1; 
    }
    else {
	message("say", this_player()->query_cap_name()+" attempts to engage the demonic creature, but is repulsed by a strange black light.", environment(this_object()), this_player());
	message("say", "A strange black light repulses you.", this_player());
	return 1; 
    }
}

int reveal() {
    revealed = "yes";
    set_name("asmodeus");
    set_short("%^BOLD%^%^BLUE%^Asmodeus, Lord of the Netherworld");
    set_id(({"asmodeus"}));
    set_long("This huge, translucent demonic figure stands over seventeen feet tall. His skin is a blotchy black colour, apart from two massive ivory horns which grow from his forehead and two coal black batlike wings which sprout from his back.");
}

int kill(){
    this_object()->remove();
}

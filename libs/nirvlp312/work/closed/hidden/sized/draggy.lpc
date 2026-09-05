#include "/players/dragnar/closed/color.h";

int count;
id(str) { return str == "healer"; }
reset(arg) {
set_heart_beat(1);
if(!arg) count=0;
}
short() {
write("A magical healer.\n");
}
long() {
	write("A magical healer that will heal you when your hit points fall\n" +
"below 75.  You can also 'heal' if you wish.\n");
}
init() {
	add_action("check","check");
	add_action("heal","heal");
	}
heart_beat() {
object user;
	user=environment(this_object());
if (environment(this_object())->query_hp() < 100)  {
	count=count+1;
        (environment(this_object())->heal_self(350));
	tell_object(user, CYA + BOLD +"The healer senses your needs and heals you.\n");
	tell_object(user, WHI + NOSTYLE +"The healer vanishes.\n");
	}
}
heal() {
	this_player()->heal_self(350);
	write(RED + BOLD +"You heal yourself with the healer.\n");
	write(WHI + NOSTYLE +"The healers loses it's magic and vanishes.\n");
	say(capitalize(this_player()->query_real_name()) + "heals themself useing the healer.\n");
	destruct(this_object());
	return 1;
	}
check() {
	write("You have used "+count+" heals.\n");
	return 1;
}
get () { return 1; }
query_weight() { return 0; }
query_value() { return 5000; }

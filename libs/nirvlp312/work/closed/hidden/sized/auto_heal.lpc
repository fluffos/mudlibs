#include "/players/dragnar/closed/color.h";

int hps;
id(str) { return str == "healer"; }
reset() { }
short() {
	return "A magical healer";
}
long() {
	write("A magical healer that will heal you when your hit points fall\n" +
"below a certain amount.  To set the amount type sethps <#>.  When your\n"+
"hitpoints fall below the amount that you set it will automatically heal\n" +
"you.  You can also 'heal' if you wish.  If you don't set the amount\n"+
"it will heal you when your hit points fall below 50.\n");
}
init() {
call_out("heal_me",1);
	add_action("heal","heal");
	add_action("set_hitpoints","sethps");
}
set_hitpoints(str) {
sscanf(str,"%d",hps);
	write("Healer will now heal you when your hit points fall below "+hps+"\n");
	return 1;
}
heal_me() {
object user;
	user=environment(this_object());
if (environment(this_object())->query_hp() < hps)  {
        (environment(this_object())->heal_self(350));
	tell_object(user, CYA + BOLD +"The healer senses your needs and heals you.\n");
	tell_object(user, WHI + NOSTYLE +"The healer vanishes.\n");
	destruct(this_object());
	}
	if(environment(this_object())->query_hp() < 50) {
	command("heal", environment(this_object()));
	}
call_out("heal_me",1);
}
heal() {
	this_player()->heal_self(350);
	write(RED + BOLD +"You heal yourself with the healer.\n");
	write(WHI + NOSTYLE +"The healers loses it's magic and vanishes.\n");
	say(capitalize(this_player()->query_real_name()) +" is magically healed by the healer.\n");
	destruct(this_object());
	return 1;
	}
get () { return 1; }
query_weight() { return 0; }
query_value() { return 5000; }

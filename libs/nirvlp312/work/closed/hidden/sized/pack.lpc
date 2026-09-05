#include "/players/dragnar/closed/color.h";

int shit;
id(str) { return str == "pack"; }
int charge;
reset(arg) {
set_heart_beat(1);
	if(!arg) charge=350;
}
short() {
	return "A pack of healing";
}
long() {
	write("A pack of healing that will heal you a random number of hit points\n"+
"per round.  To set the number type 'setamt <#>'.  Example: if you type \n"+
"'setamt 10' it will heal you a random 10 hit points per round.  If you don't set\n"+
"it the default is zero.  You can also 'chargme' to heal the amount of charges\n"+
"that are left.  It looks like there are "+charge+" charges left.\n");
}
init() {
	add_action("set_amount","setamt");
	add_action("chargeme","chargeme");
	}
set_amount(str) {
sscanf(str,"%d",shit);
	write("The pack will know heal you a random "+shit+" points per round.\n");
	return 1;
}
heart_beat() {
object user, att;
int amt;
	amt=random(shit);
	user=environment(this_object());
	att=user->query_attack();
	if(!user->query_attack()) {
	return 0;
} else{
	if(user->query_attack() && shit > 0) {
	user->heal_self(amt);
	charge=charge-amt;
	tell_object(user, "You are healed "+BOLD+""+amt+" "+NOSTYLE+"by your healing pack.\n");
	if(charge < 1) {
	tell_object(user, "Your pack runs out of charges and dissapears.\n");
	tell_object(user, "The pack dissapears.\n");
	destruct(this_object());
	}
	return 1;
}
}
}
chargeme() {
	this_player()->heal_self(charge);
	write("You use the rest of your pack of healing to heal yourself "+charge+"\n");
write("The pack dissapears.\n");
	say(capitalize(this_player()->query_name())+ " uses the rest of the pack of healing.\n");
	destruct(this_object());
	return 1;
	}
get () { return 1; }
query_weight() { return 0; }
query_value() { return 5000; }
query_save_flag() { return 1; }

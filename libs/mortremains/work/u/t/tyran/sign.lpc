
// This is a sign you can give someone when they do
// something REALLY stupid!  Inspired by the comedy
// of Bill Engvall
// Coded by Tyran, June 11, 2000

inherit OBJECT;

void create() {
    set("author", "tyran");
    set("short", "a small yellow sign");
    set("long", @EndLong
    This is a small diamond shaped yellow sign.  It
has a black border.  In big black letters, it says
"I'M STUPID!".  You can "present" it to someone who's
done something boneheaded enough to warrant it.
EndLong
    );
    set("id", ({ "sign", "yellow sign" }) );
    set("prevent_give", 1);
    set("prevent_drop", 1);
    set("prevent_clean", 1);
}

void init() {
    add_action("sign_func", "sign");
    add_action("dest_sign", "dest");

}

int sign_func ( string str ) {
    string name;
    object target;
    if (TPN=="Sebastian") {
	write("You're not EVIL enough to SIGN anyone.. MUHAHAHA!!!\n");
	return 1;
    }
    if (!str) {
	write("Sign who?\n");
	return 1;
    }

    // Make sure the syntax is in the form 'present sign to who'
    if (sscanf(str, "%s", name) != 1) {
	write("Who do you want to present the sign to?\n");
	return 1;
    }

    target = find_player(name);
    if (!target) {
	write("There's no player named "+capitalize(name)+
	  " on the mud!\n");
	return 1;
    }
    if (target->query("busy") ) {
	write("That person is busy at the moment...\n");
	return 1;
    }

    // All the cool notifications.
    write("You present a small yellow sign to "+target->query("cap_name")+".\n");
    say(TPN+" sends a small yellow sign out of the room.\n");
    tell_object(target, wrap(
	"A small yellow sign materializes out of nowhere and "+
	"pins itself to your chest.  The sign proclaims to the "+
	"world just how boneheaded you were.") );

    // Here we actually move the object.
    move( target );
    return 1;   
}
int dest_sign(string str) {
    if (TP->query("name") != "sebastian") return 0;
    if (TPN=="Sebastian") {
	write("YOU are not EVIL enough to dest it!!! MUHAHAHAHA!\n");
	return 1;
    }
}

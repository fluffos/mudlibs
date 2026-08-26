// This is an example of an object that can be shot or thrown
// across the mud to land in another player's directory.
// Cyanide coded this, 2 April 2000

inherit OBJECT;

void create() {
    set("author", "cyanide");
    set("short", "an elastic band");
    set("long", @EndLong
This is a standard elastic band. You can 'shoot' it at
anybody you like.
EndLong
    );
    set("id", ({ "elastic", "band", "elastic band" }) );
}

void init() {
    add_action("shoot_func", "shoot");
}

int shoot_func( string str ) {
    string name;
    object target;

    if (!str) {
	write("Shoot elastic at who?\n");
	return 1;
    }

    // Make sure the syntax is in the form 'shoot band at blah'
    if (sscanf(str, "%s at %s", str, name) != 2) {
	write("Who do you want to shoot the elastic at?\n");
	return 1;
    }

    // Here we see if the player is trying to 'shoot' the band,
    // or another object.
    if (str!="band" && str!="elastic" && str!="elastic band") {
	return 0;
    }

    target = find_player(name);
    if (!target) {
	write("There's no player named "+capitalize(name)+
	  " on the mud!\n");
	return 1;
    }

    // All the cool notifications.
    write("You shoot the elastic band at "+target->query("cap_name")+".\n");
    say(TPN+" shoots an elastic band.\n");
    tell_object(target, wrap(
	"An elastic band comes flying out of nowhere and "+
	"hits you in the back!") );

    // Here we actually move the object.
    move( target );
    return 1;
}

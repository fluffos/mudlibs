// This is an example of an object that can be shot or thrown
// across the mud to land in another player's directory.
// Cyanide coded this, 2 April 2000

inherit OBJECT;

void create() {
    set("author", "cyanide");
    set("short", "a sweet, creamy chocolate pie");
    set("long", @EndLong
This pie, perfect for throwing has just been thrown in your face.
however by the powers vested in magical things such as this, if you
remove it from your face, you can throw it at someone else.
EndLong
    );
    set("id", ({ "pie", "chocolate pie" }) );
}

void init() {
    add_action("throw_func", "throw");
}

int throw_func( string str ) {
    string name;
    object target;

    if (!str) {
        write("Throw pie  at who?\n");
	return 1;
    }

    // Make sure the syntax is in the form 'throw pie  at blah'
    if (sscanf(str, "%s at %s", str, name) != 2) {
        write("Who do you want to throw the pie at?\n");
	return 1;
    }

    // Here we see if the player is trying to 'shoot' the band,
    // or another object.
    if (str!="pie" && str!="chocolate pie") {
	return 0;
    }

    target = find_player(name);
    if (!target) {
	write("There's no player named "+capitalize(name)+
	  " on the mud!\n");
	return 1;
    }

    // All the cool notifications.
    write("You throw the pie with a mighty scream! at "+target->query("cap_name")+".\n");
    say(TPN+" Throws an awesome looking chocolate pie.\n");
    tell_object(target, wrap(
        "A chocolate pie comes flying out of nowhere and "+
        "hits you in the face!") );

    // Here we actually move the object.
    move( target );
    return 1;
}

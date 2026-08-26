
inherit OBJECT;

void create() {
 set("author" , "Shya");
 set("short" , "a huge snowball");
    set("long", @EndLong
 This huge snowball is meant to be thrown.  You can 'throw' it at anybody you like.
EndLong
    );
 set("id" , ({ "snowball"}) );
}

void init() {
 add_action("throw_func", "throw");
}

int throw_func( string str ) {
    string name;
    object target;

    if (!str) {
 write("Throw snowball at who?\n");
	return 1;
    }

    if (sscanf(str, "%s at %s", str, name) != 2) {
 write("Who do you want to throw the snowball at?\n");
	return 1;
    }

if (str!="snowball") {
	return 0;
    }

    target = find_player(name);
    if (!target) {
	write("There's no player named "+capitalize(name)+
	  " on the mud!\n");
	return 1;
    }

 write("You throw the snowball at "+target->query("cap_name"));
say(TPN+ "throws a snowball.\n");
    tell_object(target, wrap(
 "A snowball comes flying out of nowhere and "+
 "hits you in the face!") );

    move( target );
    return 1;
}

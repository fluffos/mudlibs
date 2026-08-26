
inherit OBJECT;

void create() {
 set("author" , "Shya");
 set("short" , "a pillow");
    set("long", @EndLong
 This multi-colored pillow is meant for a fight.  
You can 'hit' anybody you like.
EndLong
    );
 set("id" , ({ "pillow"}) );
}

void init() {
 add_action("hit", "hit");
}

int hit( string str ) {
    string name;
    object target;

    if (!str) {
 write("Start a pillow fight with who?\n");
	return 1;
    }
if (str!="pillow") {
	return 0;
    }

    target = find_player(name);
    if (!target) {
	write("There's no player named "+capitalize(name)+
	  " on the mud!\n");
	return 1;
    }

 write("You start a pillow fight with "+target->query("cap_name"));
say(TPN+ "starts a pillow fight.\n");
    tell_object(target, wrap(
 "A multi-colored pillow comes flying out of nowhere and "+
 "hits you in the face!") );
    return 1;
}

inherit ARMOR;

void create() {
    set("author", "shya");
    set ("short", "leather skirt");
    set ("long", wrap(
	"This short skirt shows off more ass than hides it.\n"+
	"It is made of very fine black leather to match a halter-top.\n"+
      "You want to wear it and seduce someone.\n"));
    set ("id", ({ "leather", "skirt", "leather skirt" }) ) ;
}
void init() {
    add_action ("wear_skirt", "wear");
    add_action ("remove_skirt", "remove");
    add_action ("seduce", "seduce");
}
int wear_skirt(string str) {
    if (!str || str!="skirt") {
	write("What do you wish to wear?\n");
	return 1;
    }
    say(TPN+" wiggles into a very tight, black leather skirt.\n");
    write(wrap(
	"Wears a leather skirt as a sign of rebellion.\n"));
    return 1;
}
int remove_skirt (string str) {
    if (!str || str!="skirt") {
	write("Remove what?\n");
	return 1;
    }
    say(
      TPN+" unzips the skirt slowly and wiggles out of it.\n");
    write(wrap(
	"You unzip the leather skirt slowly.\n"));
    return 1;
}
int seduce (string str) {
    object victim;

	if (!str) {
		write ("Seduce who in your leather skirt?\n");
                say(TPN+" wants to seduce someone.\n") ;
		return 1;
	}
	victim = find_player(str);
	if (!victim) {
		write("There's no player named "+capitalize(str)+
			" on the mud!\n");
		return 1;
    }
    
    tell_object(victim, this_player()->query("cap_name")+
		" seduces you with a crook of a finger!\n");
    say (this_player()->query("cap_name")+
		" seduces "+
      victim->query("cap_name") + 
            " with a crook of a finger.\n", victim ) ;
    write ("You seduce " +
      victim->query("cap_name")+ " effortlessly.\n") ;
    return 1;
}



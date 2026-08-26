inherit ARMOR;

void create() {
    set("author", "shya");
    set ("short", "leather halter-top");
    set ("long", wrap(
	"This leather halter-top helps boost the bust of the wearer.\n"+
	"This halter-top pushes the nipples into holes especailly made for them.\n"+
      "It makes you want to wear it and seduce someone.\n"));
    set ("id", ({ "leather", "halter-top", "leather halter-top" }) ) ;
}
void init() {
    add_action ("wear_leather", "wear");
    add_action ("remove_leather", "remove");
    add_action ("seduce", "seduce");
}
int wear_leather(string str) {
    if (!str || str!="leather") {
	write("What do you wish to wear?\n");
	return 1;
    }
    say(TPN+" wears a leather halter-top erotically.\n");
    write(wrap(
	"Wears a leather halter-top to seduce someone.\n"));
    return 1;
}
int remove_leather (string str) {
    if (!str || str!="leather") {
	write("Remove what?\n");
	return 1;
    }
    say(
      TPN+" unzips the halter-top slowly.\n");
    write(wrap(
	"You unzip the leather halter-top slowly.\n"));
    return 1;
}
int seduce (string str) {
    object victim;

	if (!str) {
		write ("Seduce who in your leather halter-top?\n");
                say(TPN+" wants to seduce someone.\n") ;
		return 1;
	}
	victim = find_player(str);
	if (!victim) {
		write("There's no player named "+capitalize(str)+
			" on the mud!\n");
		return 1;
    }
    tell_object(victim, "You are seduced effortlessly by "+
           this_player()->query("cap_name")+".\n");
    say (this_player()->query("cap_name")+
		" seduces "+
      victim->query("cap_name") + 
            " with a crook of a finger.\n", victim ) ;
    write ("You seduce " +
      victim->query("cap_name")+ " effortlessly.\n") ;
    return 1;
}



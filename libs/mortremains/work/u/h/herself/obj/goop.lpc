object ob;

inherit OBJECT;

void create() {
    set("author" , "herself");
    set("short" , "some goop");
    set("long", @EndLong
Green slimy goop. Do with it as you please.
You can:
throw goop at <person>
slime <person>
eat goop
drop goop
EndLong
    );
    set("id" , ({"goop" , "goo" , "stuff" , "slime"}) );
}

void init() {
    add_action("throw_goop" , "throw");
    add_action("slime" , "slime");
    add_action("eat_goop" , "eat");
    add_action("drop_goop" , "drop");
}

int throw_goop(string str) {
    string name;
    object target;

    if (!str) {
	write("Throw goop at who?\n");
	return 1;
    }

    if (sscanf(str, "%s at %s", str, name) != 2) {
	write("Who do you want to throw the goop at?\n");
	return 1;
    }

    if(str!="goop" && str!="slime" && str!="goo"){
	return 0;
    }

    target = find_player(name);
    if (!target) {
	write("There's no player named "+capitalize(name)+
	  " on the mud!\n");
	return 1;
    }
    if(target->query("busy")) {
	write("That person is busy at the moment... \n");
	return 1;
    }

    write("You throw the goop at "+target->query("cap_name")+"!\n");
    say(wrap(
	TPN+" throws some goop across the MUD at "+
	target->query("cap_name")+"!\n"));
    tell_object(target, wrap(
	"You have just been GOOPED! \n"+
	TPN+" just threw some slimy green goop at you. \n"+
	"How gross!\n") );

    move( target );
    return 1;
}
int slime(string str) {
    object ob;
    if (!str) return 0;

    ob = present(str , environment(TP));
    if (!ob) {
	write("Slime who?\n");
	return 1;
    }

    if (!living(ob)) {
	notify_fail ("You don't know where that person is. \n");
	return 0;
    }

    write(wrap(
	"You slap some goop onto "+ob->query("cap_name")+
	"'s face. It slowly slides off, into "+
	possessive(ob->query("gender"))+" hands. \n"));

    say(
      TPN+" just slimed "+ob->query("cap_name")+"!\n", ({ob}) );
    tell_object(ob, 
      TPN+" rears back and slaps some goop in your face.\n"+
      "Your face now has a green hue. \n");
    set("extra_look" , (capitalize(subjective(TP->query("gender"))))+
      " has a green hue and a hint of green slime in "+
      possessive(ob->query("gender"))+" hair. \n");
    move(ob);
    return 1;
}
int drop_goop (string str) {
    if (str!="goop") {
	return 0;
    }
    write(wrap("You drop some goop. \n\n\n\n"+
	"It bounces back up onto your head!\n"));
    say(wrap(
	TPN+" drops some goop, but it bounces back up "+
	"onto "+possessive(TP->query("gender"))+" head!\n"));
    set("extra_look", (capitalize(subjective(TP->query("gender"))))+
      " has goop on "+possessive(TP->query("gender"))+
      " head.\n");
    return 1;
}
int eat_goop(string str) {
    if(str!="goop") {
	return 0;
    }
    write("You stuff some goop into your mouth, and swallow it whole!\n");
    say(TPN+" stuffs some goop into "+possessive(TP->query("gender"))+
      " mouth, and swallows it whole! \n");
    remove();
    return 1;
}
/*EOF*/

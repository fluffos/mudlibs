
inherit OBJECT;

void create() {
    set("author" , "herself");
    set("short" , "a fluffy white pillow");
    set("long", @EndLong
A fluffy white pillow. You can hit someone
with it, or throw it at someone on the mud.
Better be prepared, you just might start
a pillow fight!
EndLong
    );
    set("id" , ({"pillow", "fluffy pillow" , "white pillow"}) );
}

void init() {
    add_action("throw_pillow" , "throw");
    add_action("hit" , "hit");
    add_action("beat" , "beat");
}

int throw_pillow(string str) {
    string name;
    object target;

    if (!str) {
	write("Throw pillow at who?\n");
	return 1;
    }

    if (sscanf(str, "%s at %s", str, name) != 2) {
	write("Who do you want to throw the pillow at?\n");
	return 1;
    }

    if (str!="pillow" && str!="fluffy pilllow" && str!= "white pillow"){
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

    write("You throw the pillow at "+target->query("cap_name")+"!\n");
    say(TPN+" throws a pillow across the MUD!\n");
    tell_object(target, wrap(
	"WHOOOMP!!! "+
	TPN+" just beaned you in the back of the head with "+
	"a fluffy white pillow! "));

    move( target );
    return 1;
}
int hit(string str) {
    object ob;
    if (!str) return 0;

    ob = present(str , environment(TP));
    if (!ob) {
	write ("Hit who with your pillow?\n");
	return 1;
    }

    if (!living(ob)) {
	notify_fail ("Your arms just aren't long enough to hit that person.\n");
	return 0;
    }

    write(wrap(
	"You hit "+ob->query("cap_name")+
	" in the back of the head with your pillow!\n"));

    say(
      "WHOOMP!!!\n"+
      TPN+" just beaned "+ob->query("cap_name")+
      " in the back of the head with a pillow!\n", ({ ob }) );
    tell_object(ob, 
      "WHOOMP!!!\n"+
      TPN+" just beaned you in the back of the \n"+
      "head with a fluffy white pillow!\n"+
      "You think maybe "+TPN+" is trying to start a pillow fight!\n");
    return 1;
}
int beat(string str) {
    object ob;
    if (!str) return 0;

    ob = present(str, environment(TP));
    if (!ob) {
	write("Beat on who? \n");
	return 1;
    }
    if (!living(ob)) {
	notify_fail ("You can't reach that person. \n");
	return 0;
    }

    write(wrap(
	"You repeatedly beat on "+ob->query("cap_name")+
	"with your pillow. \n"));
    say(
      TPN+" takes "+objective(TP->query("gender"))+
      " pillow and repeatedly beats "+ob->query("cap_name")+
      " over the head with it! \n");
    tell_object(ob,
      TPN+" takes "+objective(TP->query("gender"))+
      " pillow and repeatedly beats you in the back of"+
      " the head with it!\n");
    return 1;
}

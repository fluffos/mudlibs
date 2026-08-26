/*
** File: chocolate.c
** Author: Lady Nsd
*/

inherit OBJECT;

void create() {
    set("author", "nsd");
    set("long", @EndText
A bowl of chocolate cream. Excellent to 'dip' an
object in it or 'spread' it on your <partner>.
You can spread it on yourself too by typing:
'spreadme'.
EndText);
    set("short", "a chocolate cream bowl");
    set("id", ({ "bowl", "chocolate", "chocolate cream",
      "bowl of chocolate" }) );
    set("mass", 0);
}

void init() {
    add_action("spread", "spread");
    add_action("spreadme", "spreadme");
    add_action("dip", "dip");
    add_action("lick", "lick");
    add_action("lickme", "lickme");
}
int spreadme(string str) {
    write(wrap(
	"You spread the chocolate cream all over yourself.\n"+
	"Now tell your partner to lick you. ;-P\n"));
    say(wrap(
	TPN+" spreads the whip cream all over "+
	objective(TP->query("gender"))+"self.\n"+
	"Now "+TPN+" is looking for someone to lick "+
	objective(TP->query("gender"))+".\n"));
    return 1;
}
int spread(string str) {
    object ob;
    if (!str) return 0;
    ob = present(str, environment(TP));
    if (!ob) {
	write ("Spread who?\n");
	return 1;
    }
    if (!living(ob)) {
	notify_fail ("That player is not in the room.\n");
	return 0;
    }
    write(wrap(
	"You spread the chocolate cream all over "+ob->query("cap_name")+
	"'s body.\n"+
	"Be naughty and lick "+objective(ob->query("gender"))+".\n"));
    say(
      TPN+" spreads chocolate cream all over "+ob->query("cap_name")+
      "'s body.\n"+
      TPN+" gets ready to lick "+objective(ob->query("gender"))+
      ".\n", ({ ob }) );
    tell_object(ob, 
      TPN+" spreads chocolate cream all over your body.\n"+
      "You wonder if "+TPN+" has the guts to lick you.\n");
    return 1;
}
int lick(string str) {
    object ob;
    if (!str) return 0;
    ob = present(str, environment(TP));
    if (!ob) {
	write ("Lick who?\n");
	return 1;
    }
    if (!living(ob)) {
	notify_fail ("That player is not in the room.\n");
	return 0;
    }
    write(wrap(
	"You lick "+ob->query("cap_name")+"'s body entirely til"+
	" there's no\n"+ "chocolate cream left.\n"));
    say(
      TPN+" licks "+ob->query("cap_name")+"'s body entirely til"+
      " there's no\n"+ "chocolate cream left.\n", ({ ob }) );
    tell_object(ob, wrap(
	TPN+" licks your body entirely til there's no\n"+
	"chocolate cream left.\n"));
    return 1;
}
int lickme(string str) {
    object ob;
    if (!str) return 0;
    ob = present(str, environment(TP));
    if (!ob) {
	write ("Who you want to lick you?\n");
	return 1;
    }
    if (!living(ob)) {
	notify_fail ("That player is not in the room.\n");
	return 0;
    }
    write(wrap(
	ob->query("cap_name")+" licks your entire body til there's\n"+
	"no chocolate cream left.\n"));
    say(
      ob->query("cap_name")+" licks "+TPN+"'s entire body til there's\n"+
      "no chocolate cream left.\n", ({ ob }) );
    tell_object(ob, wrap(
	"You lick "+TPN+"'s entire body til there's\n"+
	"no chocolate cream left.\n"));
    return 1;
}
/* End of file */

// I'm sick of getting hit with anvils.
// Cyanide.

inherit OBJECT;

void create() {
    set("id", ({ "#BLAH#" }) );
}

void init() {
    set("extra_look", "$N is enveloped in a black sphere of force.\n");
    add_action("no_go_bro", "");
    add_action("blah", "blah");
}

int blah(string str) {
    object ob;

    if (!adminp(TP)) return 0;
    ob = find_player(str);

    if (!ob) {
	write("That player isn't on the mud anymore.\n");
    }

    move(ob);
    write("You direct the evil orb at "+ob->query("cap_name")+".\n");
    tell_object(ob, "Suddenly, a black orb forms around you, trapping you!\n");
    tell_room(environment(ob), "Suddenly, a black orb appears "+
      "surrounding "+ob->query("cap_name")+"!\n", ({ ob }) );

    return 1;
}

int no_go_bro() {
    if (TPN=="Cyanide") return 0;

    write("You are stuck within the orb, and can do nothing.\n");
    say(TPN+" tries desperately to do something, and fails.\n");

    return 1;
}

/* EOF */

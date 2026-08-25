inherit "std/Object";

void init() {
    ::init();
    add_action("scry", "scry");
}

void create() {
    ::create();
    set_name("ball");
    set_id( ({ "ball", "base", "crystal ball", "honor_quest_ob" }) );
    set_short( "%^CYAN%^a crystal ball%^RESET%^");
    set_long("It has some writing on its base.");
    set_read("From your grandfather with love.");

    set_mass(190);
    set_value(50);
    set_vendor_type("magic");
    set_property("magic item", ({"scry"}) );
    set_destroy();
}

int scry(string str) {
    object ob, env;

    if(!str) return notify_fail("Scry what?\n");
    write("You gaze into the crystal ball.");
    if((int)this_player()->query_mp() < 5) {
        write("Your magic powers are just too weak to help you.");
        return 1;
    }
    if(!(ob = find_living(str)) || creatorp(ob)) {
        write("No such person in our reality.");
        return 1;
    }
    if(!environment(ob)) return notify_fail("Gurble gurble gurble.\n");
    if(environment(ob)->query_property("no scry"))
        {
        write("Something is blocking your concentration.");
        return 1;
    }
    this_player()->add_mp(-5);
    if(!(env = environment(ob))) {
        write(ob->query_cap_name()+" is lost.");
        return 1;
    }
    write("You find "+ob->query_cap_name()+" in the crystal ball at:\n");
    write(env->query_short()+"\n");
    return 1;
}

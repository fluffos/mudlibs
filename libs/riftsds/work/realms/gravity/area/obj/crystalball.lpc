#include <lib.h>

inherit LIB_ITEM;

void create() {
    ::create();
    SetKeyName("ball");
    SetId( ({ "ball", "base", "crystal ball", "honor_quest_ob" }) );
    SetShort("%^CYAN%^a crystal ball%^RESET%^");
    SetLong("It has some writing on its base.");
    SetRead("From your great-grandaddy, with love.");
    SetMass(190); // Adjusted from set_weight to SetMass
    SetValue(50);
    SetProperty("magic item", ({"scry"}) );
}

void init() {
    ::init();
    add_action("scry", "scry");
}

int scry(string str) {
    object ob, env;
    
    if(!str || str == "") {
        write("You must specify a target to scry.");
        return 1;
    }

    write("You gaze into the crystal ball.");
    if(this_player()->GetPPE() < 5) { // Changed from query_magic to GetPPE
        write("Your magic powers are just too weak to help you.");
        return 1;
    }
    ob = find_living(str);
    if(!ob || wizardp(ob)) {
        write("No such person in our reality.");
        return 1;
    }
    env = environment(ob);
    if(!env || env->GetProperty("no scry")) { // Changed from query_property to GetProperty
        write("Something is blocking your concentration.");
        return 1;
    }
    this_player()->AddPPE(-5); // Changed from add_mp to AddPPE
    write("You find " + ob->GetCapName() + " in the crystal ball at:\n");
    write(env->GetShort() + "\n"); // Changed from query_cap_name and query_short to GetCapName and GetShort
    return 1;
}

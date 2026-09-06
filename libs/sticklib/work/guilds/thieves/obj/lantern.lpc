#include <torch.h>

void create_torch() {
    set_weight(2);
    set_name("lantern");
    set_short("A lantern");
    set_long("It's a fine hooded lantern. Type 'fill lantern' to fill it. "+
      "You would probably need oil to do that.");
    set_fuel(3750);
}

query_thief_item() { return 1; }

init() {
    ::init();
    add_action("fill","fill");
}

fill(arg) {
    object ob;
    if(!arg) return 0;
    if(!id(arg)) return 0;

    ob = present("oil flask",this_player());
    if(!ob) {
	write("You have no oil.\n");
	return 1;
    }
    write("Ok. The lantern is full.\n");
    move_object(ob,do_find_object("room/void"));
    destruct(ob);
    remove_call_out("out_of_fuel");
    amount_of_fuel = 4000;
    if(is_lighted) {
	call_out("out_of_fuel",8000);
	amount_of_fuel = 0;
    }
    return 1;
}

/* Doesn't disappear when it goes out */
out_of_fuel() {
    object ob;
    if (set_light(-1) == 0)
	say("There is darkness as a lantern goes dark.\n");
    else
	say("The lantern goes dark.\n");
    is_lighted = 0;
}

#define MY_BAR "u/v/vera/bar"

object occupant;

short() { return "Inside a spotlessly clean WC"; }
long() {
    write(short() + ".\n");
    write("The bar is east from here\n");
}

reset(arg) {
    if (!arg) set_light(1);
}
init() {
    if(occupant && present(occupant, this_object()))
    {
	write("Sorry, the WC is currently being used by ");
	write(occupant->query_name() + ".\n");
	move_object(this_player(), MY_BAR);
	return;
    }
    occupant = this_player();
    add_action("east", "east");
}
east() {
    this_player()->move_player("into the bar#u/v/vera/bar");
    occupant = 0;
    return 1;
}


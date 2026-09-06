inherit "basic/id";

reset(arg) {
    if(arg)
	return;
    set_short("A note");
    set_long("Dear nephew,\n\nIt is time for you to come back home. You can trust this kind adventurer.\n\n\t\tUncle Leo");
    set_name("note");
    set_id(({"note_from_leo"}));
}

query_weight() { return 1; }
drop() { return 0; }
get() { return 1; }

init() {
    add_action("read","read");
}

read(str) {
    if(!id(str)) return;
    write(long_desc);
    return 1;
}

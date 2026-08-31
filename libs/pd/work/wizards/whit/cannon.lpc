//  Whit
//  Snowball canon 2.0

inherit "/std/object";

void create() {
    ::create();
    set_name("snowball cannon");
    set_short("snowball cannon");
    set_long("Type fire cannon to shoot everyone in the mud.");
    set_prevent_get( "Too bad.\n" );
    set_id(({"cannon", "snowball cannon"}));
}

void init() {
    ::init();
    add_action("fire","fire");
}

int fire(string str) {
    int i;
    object *user;
    if(!wizardp(this_player())) return notify_fail("Nice try,  but too bad.  "
	  "No fun for you!\n");
    if(!str || str != "cannon")
	write("Bombs away!\n");
    i = sizeof(user=users());
    while(i--) {
	if(!wizardp(user[i]) && interactive(user[i])) {
	    this_player()->force_me("snowball "+user[i]->query_name());
	} else 
	if(interactive(user[i]))
	    write(user[i]->query_cap_name()+" is saved by its wizardness.\n");
    }
    return 1;
}


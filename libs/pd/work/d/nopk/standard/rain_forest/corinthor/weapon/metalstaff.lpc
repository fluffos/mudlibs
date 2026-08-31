inherit WEAPON;

void create() {
::create();
set_name("staff");
set_short("A metal staff");
set_id(({"staff", "metal staff"}));
set_long("This staff has been made of strong metal rather than wood. It is just more than three feet long and one end has a small hand guard, making this a one handed weapon.");
set_wc(3);
set_type("blunt");
set_curr_value("gold", 15);
set_mass(11);
}

int query_auto_load() {
    if(this_player()->query_level() > 4) return 1;
    return 0;
}

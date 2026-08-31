inherit WEAPON;

void create() {
::create();
set_name("staff");
set_short("A staff");
set_id(({"staff"}));
set_long("This staff is made of wood and is about three feet long. One end has been weighted with steel, making it easy to wield in one hand.");
set_wc(2);
set_type("blunt");
set_curr_value("gold", 13);
set_mass(8);
}

int query_auto_load() {
    if(this_player()->query_level() > 2) return 1;
    return 0;
}

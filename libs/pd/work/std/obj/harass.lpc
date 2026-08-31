//  Harass Obj
inherit "/std/object";
void create() {
    ::create();
    set_name("harass_logger");
    set_short("");
    set_long("You should not see this!");
    set_id(({ "harass_logger" }));
}
int put() { return 1; }
int drop() {
    if (this_player()->query_name() == "inferno") return 0;
    return 1;
}
int bury() {
    if (this_player()->query_name() == "inferno") return 0;
    return 1;
}

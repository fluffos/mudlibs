#include <std.h>
#include <sakura.h>
inherit OBJECT;

void create() {
    ::create();
    set_name("A smashed and broken chest");
    set_id( ({ "broken chest", "chest" }) );
    set_short("A smashed and broken chest");
    set_long("This was once a very ornately decorated and expensive chest but is now just splinters of matchwood. There appears to be a blood-like substance leaking out through the cracks.");
    set_mass(9999);
    set_value(50);
    set_prevent_get("This chest is too badly damaged for you to pick up and move.");

    call_out("set_desc", 0);
}

int set_desc() {

    environment(this_object())->set_long("The cavern twists and winds, then opens up into a dead end. A ruined chest sits in plain sight at the very end of this passage of tunnel, broken into hunks of wood. Strangely, there appears to be dark red gelatinous substance leaking out from the cracks in the chest. This area is almost completely white limestone except for the floor, which has a large stain of blood around the area where the chest sits.");
    environment(this_object())->set_smell("default", "The air reeks from the smell of the red goo leaking from the broken chest. It smells somewhat like blood.");
}

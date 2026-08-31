/* Do not remove the headers from this file! see /USAGE for more info. */

inherit HIDDEN_DOOR;

object get_sibling();

void do_on_open()
{
    ::do_on_open();
    environment(this_object())->set_room_state("electronic_door");
}

void do_on_close()
{
    ::do_on_close();
    environment(this_object())->clear_room_state("electronic_door");
}

void override_successful()
{
    call_out("close_and_lock", 60 + random(10));
}

void close_and_lock()
{
    this_object()->do_close();
    environment(this_object())->clear_room_state("electronic_door");
    set_locked("electronic_door_downtown");
    tell_from_inside(environment(), "The " + this_object()->short() + " does a reboot of its security system and relocks.\n");
    tell_from_inside(environment(get_sibling()), "The " + this_object()->short() + " does a reboot of its security system and relocks.\n");
}

void on_clone(mixed args...)
{
    ::on_clone(args...);
    if (is_open())
        do_on_open();
    else
        do_on_close();
}

void add_reader()
{
    if (environment())
        environment()->add_item("card reader", "reader", "The card reader seems be vulnerable to various attacks to be overridden.\n  override door (Association skill)\n  pick door with <lockpick> (if you have a lockpick)");
}

void setup(string dir, string room)
{
    set_id("door");
    set_adj("electronic", "metal");
    set_long("It is about 12 feet tall metal door, with an electronic card reader at one side.");
    set_locked("electronic_door_downtown");
    set_strength_vs_picking(500 + (random(5) * 100));
    set_strength_vs_override(10 + (random(5) * 10));
    setup_door("electronic metal door", dir, room);
    call_out("add_reader",1);
}

/* Do not remove the headers from this file! see /USAGE for more info. */

inherit HIDDEN_DOOR;


void do_on_open()
{
    ::do_on_open();
    environment( this_object())->set_room_state( "service_hatch");
}

void do_on_close()
{
    ::do_on_close();
    environment( this_object())->clear_room_state( "service_hatch");
}

void on_clone(mixed args...)
{
    ::on_clone(args...);
    if( is_open() ) do_on_open();
    else do_on_close();
}

void setup(string dir, string room)
{
    set_id("hatch","service_hatch");
    set_adj("service", "small");
    set_long("It is a small service hatch, but seems to be able to open.");
    setup_door("service hatch", dir, room);
}

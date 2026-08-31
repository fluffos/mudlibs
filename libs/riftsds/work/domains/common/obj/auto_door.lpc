/* Do not remove the headers from this file! see /USAGE for more info. */

inherit HIDDEN_DOOR;

void auto_close()
{
    ::set_closed(1);
    do_on_close();
    object_event("The $o closes.\n");
}

void do_on_open()
{
    ::do_on_open();
    if (environment(this_object()))
        environment(this_object())->set_room_state("auto_door");
    call_out("auto_close", 2);
}

void do_on_close()
{
    ::do_on_close();
    if (environment(this_object()))
        environment(this_object())->clear_room_state("auto_door");
}

void on_clone(mixed args...)
{
    KBUG(args);
    ::on_clone(args...);
    if (is_open())
        do_on_open();
    else
        do_on_close();
}

void setup(string dir, string room)
{
    set_id("panel");
    set_adj("automatic");
    set_long("A flat panel with no handle stands between you and the next room.");
    setup_door("auto_panel", dir, room);
    do_on_open();
}

int direct_close_obj()
{
    write("There doesn't seem to be a way to manually close the panel.\n");
    return 0;
}

int direct_open_obj() {
    write("There doesn't seem to be a way to manually open the panel.\n");
    return 0;
}

mixed door_check(string dir, object who) {
    if (query_closed()) {
        set_closed(0);
        object_event("The $o opens.\n");
    }

    if(!load_object(query_method_destination("go")))
        return "Error, the destination does not exist, please mail the creator of this room";
    return 1;
}

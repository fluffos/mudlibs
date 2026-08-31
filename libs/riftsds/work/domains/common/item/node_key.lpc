inherit OBJ;
inherit M_GETTABLE;

void mudlib_setup()
{
    ::mudlib_setup();
    set_id("archway key", "key", "plexus key", "portal key");
    set_proper_name("a plexus key");
    set_in_room_desc("A plexus archway key.");
    add_adj("plexus");
    set_weight(0.25);
    set_long("This flat metal plate has strange symbols on it. Inserting this key into a Plexus archway will active the portal.");
}

mixed direct_put_obj_wrd_obj(object ob1, string prep, object ob2)
{
    if (environment(this_object()) == this_body())
        return 1;
    return 0;
}
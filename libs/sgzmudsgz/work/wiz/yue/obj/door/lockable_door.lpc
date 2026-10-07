// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

inherit SECRET_DOOR;

void update_sibling()
{
    object sibling = get_sibling();
    // Needed for initial load ...\
    if( !sibling )
        return;

    // Magic ...
    if( is_open())
        sibling->do_on_open();
    else sibling->do_on_close();
    ::update_sibling();
}

void do_on_open()
{
    environment( this_object())->set_room_state( "oak_door");
}

void do_on_close()
{
    environment( this_object())->clear_room_state( "oak_door");
}

void setup(string dir)
{
    set_id("door", "门");
    set_unit("扇");
    set_adj("巨大的橡木", "巨大的", "橡木");
    set_long("它高约两丈，极尽华美之能事。\n");
    
    add_hook( "open", (: do_on_open :));
    add_hook( "close", (: do_on_close :));
    set_closed(1);
    setup_door("大橡木门", dir);
    set_in_room_desc("一扇巨大的橡木门占去了" + DIRECTION_D->cdir(dir) + "墙上很大一部分面积。");
}

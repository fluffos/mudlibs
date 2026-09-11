//  jf_door.c
//  将府小门
//  created by tset 1/23/98
//  last updated by tset 1/23/98
 
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
    environment( this_object())->set_room_state( "jf_door");
}

void do_on_close()
{
    environment( this_object())->clear_room_state( "jf_door");
}

void setup(string dir)
{
    set_id("door", "小门");
    set_unit("扇");
    set_adj("普普通通的"); 
    set_long("它毫不起眼，不注意根本看不到。\n");
 
    add_hook( "open", (: do_on_open :));
    add_hook( "close", (: do_on_close :));
    set_closed(1);   
    setup_door("小门", dir);
}

/* A 'second' part of the window. */

inherit "/basic/id";

object master;
string master_room;

void set_master(object ob, string s)
{
    master = ob;
    master_room = s;
    return;
}
void get_master()
{
    if(!master) {
	if(!master_room) return;
	master_room -> load_me();
	master = find_object(master_room);
	master = present("window", master);
    }
}
void init()
{
    if(!master) get_master();
    if(master && this_player()) master -> player_passed(this_player());
    return;
}
void
create()
{
    set_name("window");
    set_short(0);
    /* 'invisible', usually 'seen' in room's desc. */
}

varargs string
query_long(string what, object who)
{
    if (!master) get_master();
    if (!master) return
	"The window is so dirty that you can't see anything through it.";
    return (string) master -> query_inside_text();
}
status get() { return 0; }

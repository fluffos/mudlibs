// seeker
#include <std.h>
#include <daemons.h>
inherit OBJECT;
#include <ocean.h>
int *query_coords() { return environment(this_object())->query_coords(); }
string goto;
void create()
{
    set_name("raft");
    set_short("A wooden raft");
    set_long("The wooden raft seems it came from a boat out in the ocean.");
    set_id ( ({ "boat", "wooden boat", "wood boat" }) );
    set_prevent_get("You surely cant lift the raft.");
    set_no_clean(1);
}
void set_goto(string str)
{
    goto = str;
}
void init()
{
    ::init();
    add_action("go_boat", "enter");
}
int go_boat(string str)
{
    object o;
    int *i;
    if (!str || str=="") return 0;
    if ( present(str, environment(this_object())) !=this_object()) return 0;
    o=OCEAN_D->find_player_ship(goto);
    if(o->query_xy()[0] != query_coords()[0] || o->query_xy()[1] != query_coords()[1]) {
	write("The boat that the raft belongs to is not here.\n");
	return 1;
    }
    write("You enter the raft and row to the boat.");
    this_player()->move_player(o, "away in the raft");
    i = environment( this_object() )->query_coords();
    this_object()->remove();
    return 1;
}

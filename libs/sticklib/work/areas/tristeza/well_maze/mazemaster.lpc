/* An invisible monster who picks up the stuff it finds in the maze */

#include <npc.h>
#include <invis_levels.h>
#include <areas.h>

void tell_maze(string s);


void
create_monster()
{
    set_name("mazemaster");
    set_invis(IL_INVISIBLE);
    set_long("You can't see anything except for faint\
 outlines of some human-like creature.");
    set_level(2);
    // set_wimpy(20);
    set_wc(9);
    set_ac(3);

    call_out("wander_maze",10);
}

void
reset_monster()
{
    object *x;
    int i, s;
    if ((s = sizeof(x = all_inventory())) > 10) {
	for (i = 10; i < s; i++)
	    destruct(x[i]);
    }
}

void
pick_any_obj()
{
    int i;
    object *inv;
    string sh;

    if (!environment()) return;
    inv = all_inventory(environment());

    for (i = 0; i < sizeof(inv); i++) 
    {
	if (inv[i]->get()&&!living(inv[i])
	  &&(sh = (string)inv[i]->query_name())) 
	{
	    if (!random(2))
		tell_maze("\nYou hear a voice saying: I wonder who has left "
		  +sh+" in my maze?");
	    else
		tell_maze("\nYou hear someone saying: My, my, someone has left "+
		  sh+" in my maze!");
	    move_object(inv[i],this_object());
	    break;
	}
    }
}

void
wander_maze()
{
    this_object()->move_player("X", 
      ({ AREA_TRISTEZA+"well_maze/maze1",
	AREA_TRISTEZA+"well_maze/maze2",
	AREA_TRISTEZA+"well_maze/maze3",
	AREA_TRISTEZA+"well_maze/maze4" })[random(4)]);
    if (!random(4)) pick_any_obj();
    call_out("wander_maze",10 + random(10));
}

/* We can carry as much as we want... */
status
add_weight(int x) { return 1; }

void
tell_maze(string msg)
{
    (AREA_TRISTEZA+"well_maze/maze1")->tell_here(msg);
    (AREA_TRISTEZA+"well_maze/maze2")->tell_here(msg);
    (AREA_TRISTEZA+"well_maze/maze3")->tell_here(msg);
    (AREA_TRISTEZA+"well_maze/maze4")->tell_here(msg);
    (AREA_TRISTEZA+"well_maze/maze5")->tell_here(msg);
}

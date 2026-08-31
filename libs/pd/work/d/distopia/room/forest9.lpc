#include <std.h>
#include <hermes.h>
inherit ROOM;
int i;
void init()
{
	::init();
	add_action("out","out");
}
void create()
{
	::create();
	
	
	set_properties
	(
	        (["light" : 2, "night light" : 1, "forest" : 1, "no bump" : 1])
	);
	set_short("Road to Distopia.");
	set_long
	(
		"%^BOLD%^Bones%^GREEN%^...%^WHITE%^bones %^GREEN%^everywhere... And a single solitary %^RED%^figure%^GREEN%^ sitting in the center of everything. "
		"%^GREEN%^%^BOLD%^A %^BLUE%^crack%^GREEN%^ of a %^WHITE%^bone%^GREEN%^ and his head darts up, eyes narrowing on the intruder as he rises.  The woods "
		"%^GREEN%^%^BOLD%^seem to close and form a tight circle sealing the prey in... but wait, there is one way %^RED%^out "
		"%^GREEN%^%^BOLD%^and it might be the only hope."
	);
	set_smell("default", "The stench of decay hangs heavy.");
    set_listen("default", "The slow, eased sound of breathing.");
	set_items
	(
	        ([
	                "figure" : "It's an Archangel... maybe it's Ilithyd?",
	                "bones" : "Remains of dead animals...",
	                
	        ])
	);
}
void reset() 
{
	::reset();
	if(!present("ilithyd"))
	{
		new(MOB"ilithyd")->move(this_object());
	}
}
int out(string str)
{
	if(!str)
        {
/* Added by nesoo to fix leaving a room while performing abilities */
if( this_player()->query_disable() )
{
write("You can not exit while doing something else.");
return 1;
}
/* End of nesoo edit */
		i = random(50);
		if (i == 0 || i == 9)
		{
			i++;
		}
		write ("\n%^BOLD%^The forest closes behind you. After wondering around blindly you find your way onto more familer ground.\n");
		this_player()->move_player(ROOMS"forest"+ i);
		return 1;
	}
	else
	return 1;
}

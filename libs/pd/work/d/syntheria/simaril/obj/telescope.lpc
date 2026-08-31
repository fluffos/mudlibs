#include <std.h>
#include <daemons.h>

int peer_water(string);

inherit OBJECT;

void create() {
    ::create();
    set_id(({ "telescope", "scope", "spyglass" }));
    set_name("Telescope");
    set_long("A naval telescope made of brass. "
			 "It is covered in a woven leather, and has a leather sling. "
			 "It looks like it is in good condition, and could probably "
			 "be used to peep for land on the open ocean.");
    set_short("telescope");
    set_weight(1);
	set_curr_value("gold", 3 + random(3));
}

void init() {
	::init();
		add_action("peer_water", "peep");
}

int peer_water(string dir)
{
	int X,Y;
	object env, tp;
	string ret;
	tp = this_player();
	env = environment(tp);

	
	if(!env->is_boat())
	{
		return notify_fail("You can not use the telescope here!\n");	
	}
	if(dir != "south" && dir != "north" && dir != "east"
		&& dir != "west" && dir != "northeast"
		&& dir != "northwest" && dir != "southeast"
		&& dir != "southwest")
	{
		return notify_fail("You can not peep in that direction.\n");	
	}
	X = env->query_xy()[0];
	Y = env->query_xy()[1];
	
	if(dir == "north")
	{
		if (OCEAN_D->get_xy(X, Y-1)=="+" || OCEAN_D->get_xy(X, Y-2)=="+"
			|| OCEAN_D->get_xy(X, Y-3)=="+") 
		{
			ret = "You see land to the "+dir;
		}
		else if (OCEAN_D->get_xy(X, Y-1)=="#" || OCEAN_D->get_xy(X, Y-2)=="#"
			|| OCEAN_D->get_xy(X, Y-3)=="#") 
		{
			ret = "You see ice to the "+dir;
		}
		else
		{
			ret = "You see only the open ocean.";
		}		
	}
	if(dir == "northeast")
	{
		if (OCEAN_D->get_xy(X+1, Y-1)=="+" || OCEAN_D->get_xy(X+2, Y-2)=="+"
			|| OCEAN_D->get_xy(X+3, Y-3)=="+") 
		{
			ret = "You see land to the "+dir;
		}
		else if (OCEAN_D->get_xy(X+1, Y-1)=="#" || OCEAN_D->get_xy(X+2, Y-2)=="#"
			|| OCEAN_D->get_xy(X+3, Y-3)=="#") 
		{
			ret = "You see ice to the "+dir;
		}
		else
		{
			ret = "You see only the open ocean.";
		}		
	}	
	if(dir == "east")
	{
		if (OCEAN_D->get_xy(X+1, Y)=="+" || OCEAN_D->get_xy(X+2, Y)=="+"
			|| OCEAN_D->get_xy(X+3, Y)=="+") 
		{
			ret = "You see land to the "+dir;
		}
		else if (OCEAN_D->get_xy(X+1, Y)=="#" || OCEAN_D->get_xy(X+2, Y)=="#"
			|| OCEAN_D->get_xy(X+3, Y)=="#") 
		{
			ret = "You see ice to the "+dir;
		}
		else
		{
			ret = "You see only the open ocean.";
		}		
	}
	if(dir == "southeast")
	{
		if (OCEAN_D->get_xy(X+1, Y+1)=="+" || OCEAN_D->get_xy(X+2, Y+2)=="+"
			|| OCEAN_D->get_xy(X+3, Y+3)=="+") 
		{
			ret = "You see land to the "+dir;
		}
		else if (OCEAN_D->get_xy(X+1, Y+1)=="#" || OCEAN_D->get_xy(X+2, Y+2)=="#"
			|| OCEAN_D->get_xy(X+3, Y+3)=="#") 
		{
			ret = "You see ice to the "+dir;
		}
		else
		{
			ret = "You see only the open ocean.";
		}		
	}
	if(dir == "south")
	{
		if (OCEAN_D->get_xy(X, Y+1)=="+" || OCEAN_D->get_xy(X, Y+2)=="+"
			|| OCEAN_D->get_xy(X, Y+3)=="+") 
		{
			ret = "You see land to the "+dir;
		}
		else if (OCEAN_D->get_xy(X, Y+1)=="#" || OCEAN_D->get_xy(X, Y+2)=="#"
			|| OCEAN_D->get_xy(X, Y+3)=="#") 
		{
			ret = "You see ice to the "+dir;
		}
		else
		{
			ret = "You see only the open ocean.";
		}		
	}
	if(dir == "southwest")
	{
		if (OCEAN_D->get_xy(X-1, Y+1)=="+" || OCEAN_D->get_xy(X-2, Y+2)=="+"
			|| OCEAN_D->get_xy(X-3, Y+3)=="+") 
		{
			ret = "You see land to the "+dir;
		}
		else if (OCEAN_D->get_xy(X-1, Y+1)=="#" || OCEAN_D->get_xy(X-2, Y+2)=="#"
			|| OCEAN_D->get_xy(X-3, Y+3)=="#") 
		{
			ret = "You see ice to the "+dir;
		}	
		else
		{
			ret = "You see only the open ocean.";
		}	
	}
	if(dir == "west")
	{
		if (OCEAN_D->get_xy(X-1, Y)=="+" || OCEAN_D->get_xy(X-2, Y)=="+"
			|| OCEAN_D->get_xy(X-3, Y)=="+") 
		{
			ret = "You see land to the "+dir;
		}
		else if (OCEAN_D->get_xy(X-1, Y)=="#" || OCEAN_D->get_xy(X-2, Y)=="#"
			|| OCEAN_D->get_xy(X-3, Y)=="#") 
		{
			ret = "You see ice to the "+dir;
		}	
		else
		{
			ret = "You see only the open ocean.";
		}	
	}
	if(dir == "northwest")
	{
		if (OCEAN_D->get_xy(X-1, Y-1)=="+" || OCEAN_D->get_xy(X-2, Y-2)=="+"
			|| OCEAN_D->get_xy(X-3, Y-3)=="+") 
		{
			ret = "You see land to the "+dir;
		}
		else if (OCEAN_D->get_xy(X-1, Y-1)=="#" || OCEAN_D->get_xy(X-2, Y-2)=="#"
			|| OCEAN_D->get_xy(X-3, Y-3)=="#") 
		{
			ret = "You see ice to the "+dir;
		}		
		else
		{
			ret = "You see only the open ocean.";
		}
	}

	message("info", ""+ret, this_player());
	return 1;
}

int query_auto_load() { return 1; }

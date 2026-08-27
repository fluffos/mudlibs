//#pragma save_binary

// The New Room.c (probably old by the time you read this, of course)
// Brought to you by... Buddha@TMI (where else?)
// This file is part of the TMI/MudOS mudlib.  Please retain the header.
// Written 4-19-92 and onwards.
// Doors are added in the standard door object.
// The two files are seperate so that rooms without doors (ie, most) can
// save 50 or so bytes. It adds up in the end...


#include <config.h>
#include <exits.h>
#include <mudlib.h>
#include <daemons.h>

inherit ROOM_OBJECT;

void __INIT()
{
	if (!ob_data) ob_data = ([]);
	if (!tmp_ob_data) tmp_ob_data = ([]);
}

void create()
{
	seteuid(getuid());
	call_out("reset", 0);  // this is good for virtual rooms.
}

int valid_exit(string dir)
{
	if( ob_data["exits"] && ob_data["exits"][dir] ) return 1;
}

void reset() 
{
	int i, count;
	object ob;
	string *objects, name;

	seteuid(getuid());
	__INIT();
	if (ob_data["objects"]) {
		if( !mapp(ob_data["objects"]) ) return;
		if( undefinedp(tmp_ob_data["__objects__"]) || !mapp(tmp_ob_data["__objects__"] ) )
			tmp_ob_data["__objects__"] = allocate_mapping( sizeof(ob_data["objects"]) );
		objects = keys(ob_data["objects"]);
		for( i=0; i<sizeof(objects); i++ ) {
			if( tmp_ob_data["__objects__"][objects[i]] ) continue;
			tmp_ob_data["__objects__"][objects[i]] = new(ob_data["objects"][objects[i]]);
			tmp_ob_data["__objects__"][objects[i]]->move(this_object());

//			if ( tmp_ob_data["__objects__"][objects[i]]->query("npc") ) {
			if ( ob = find_object(base_name(tmp_ob_data["__objects__"][objects[i]])) ) 
				call_out( "clear_mob", 3, ob );
//			}

		}
	}
	return;
}

// this function is create for clear mob's main backup to save some memory
// Ideal by Annihilator@ES
// add by Ruby@ES at 95-11-14

void clear_mob(object ob)
{
	if ( nullp(ob) ) return;
	destruct(ob);
}

// This is here to support outside rooms. If you define a room to
// be outside, then two things happen: the "outside" property is set to a
// capital letter (which indicates which weather zone it's in) and 
// the room's light property is overridden to call_out to the daemon
// to reflect outside light.

varargs void set_outside (string zone)
{
	if (!zone) zone="ES";
	set( "outside", zone);
	if( !query("light") )
		set( "light", "@@query_ambient_light");
	// JIC we need to load the weather daemon...
	seteuid(getuid()) ;
	WEATHER_D->request_weather_notices(this_object()) ;
	return ;
}

// This calls out to the weather daemon to check the ambient light.
int query_ambient_light()
{
	return (int)WEATHER_D->query_ambient_light() ;
}

int check_light() 
{
	int i, j ;
	object *obs, *obs2 ;
 
	// First, if this object is emitting light, we have a light source.
	if( query("light") ) return 1;
 
	// Second, if this object has no inventory, we do not have a light source.
	obs = all_inventory(this_object());
	if( !obs ) return 0;

	// Third, check objects in this room have or carry any light ? 
	for( i=0; i<sizeof(obs); i++ ) {
		if( obs[i]->query("light") ) return 1;
		else {
			if ( !obs2 = all_inventory(obs[i])) continue;
			for ( j = 0; j< sizeof(obs2) ; j ++ )
				if ( obs2[j]->query("light") ) return 1;
		}
	}
	
	return 0;
}

/* EOF */

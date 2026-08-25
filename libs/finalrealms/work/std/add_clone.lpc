nosave mixed *room_clones;
void clonem()
{
    int flags;
    string *init_data;

    if ( room_clones ) // From Laggard RoD
    {
	string thing;

	int i = sizeof(room_clones);
	// processing backwards yields room inventory in order of add_clones.
	// (for those who care)
	flags = 0;
	while ( i-- > 0 )
	{
	    if ( stringp(room_clones[i]) ) // See if it's a tag, if so we use it for now
	    {
		thing = room_clones[i];
		init_data = 0;
		flags = 0;
	    }
	    else if(sizeof(room_clones[i]) > 1) // init_data
	    {
		init_data = room_clones[i];
		flags = 0;
	    }
	    else if(room_clones[i])
	    {
		init_data = 0;
		flags = room_clones[i];
	    }
	    else if ( !room_clones[i] ) // fill up any empties using the tag
	    {
		//          Taniwha, clone, then TEST then move, so if it's screwed it still works
		room_clones[i] = clone_object(thing);
		if(room_clones[i])
		{
		    room_clones[i]->move(TO);
		    switch(sizeof(init_data))
		    {
		    default:
			break;
		    case 2:
			call_other(room_clones[i],init_data[0],init_data[1]);
			break;
		    case 3:
			call_other(room_clones[i],init_data[0],init_data[1],init_data[2]);
			break;
		    case 4:
			call_other(room_clones[i],init_data[0],init_data[1],init_data[2],init_data[3]);
			break;
		    }
		    switch(flags)
		    {
		    case 1: /* hide it */
			this_object()->add_hidden_object(room_clones[i]);
		    default:
			break;
		    }
		}
	    }
	}
    }
}

varargs void add_clone( string the_file, int how_many,mixed flags )
{
    // Laggard RoD 1995, minor mods by Taniwha
    //
	if ( !stringp(the_file) )
    {
	log_file("debug.log", ctime(time())
	  + " bad clone file: " + the_file
	  + ", " + file_name(this_object())
	  + "\n");
	return;
    }
    if ( !how_many ) how_many = 1;
    // don't make array unless we have something to put in it!
    if ( !room_clones )
    {
	room_clones = ({ });
    }
    while ( how_many-- > 0 )
    {
	// make space for objects in array
	room_clones += ({ 0 });
    }
    // last, for backward processing.
    if(flags) room_clones += ({flags});
    room_clones += ({ the_file });
}

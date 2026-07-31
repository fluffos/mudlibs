// virtuald.c
//
// This object is the virtual object server of ES2 mudlib.
//
// By Annihilator (07/06/95)
// Adapted for XKX (12/15/95)

void create()
{
	seteuid(getuid());
}

// This function is called by master object to return the "virtual" object
// of <file> when dirver failed to find such a file.
object compile_object(string file)
{
	string pname = file;
	object ob;

	while (1)
	{
		int idx = strsrch(pname, "/", -1);

		if(idx == -1)
			return 0;

		if( idx != 0 )
			pname = pname[0..idx-1];

		if(file_size(pname + ".c") >= 0)
			if(ob = pname->query_maze_room(file[idx+1..]))
			{
				ob->set_virtual_flag();
				return ob;
			}
		if(!idx)
			return 0;
	}

	return 0;
}
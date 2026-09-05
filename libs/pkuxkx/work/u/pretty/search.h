// search.h

nosave int loc_count = 0;
mapping *local;

void l_n(int x, int y, int z, string file);

void setup()
{
	l_n(1, 2, 3, "/d/fy/fysquare");
}

void l_n(int x, int y, int z, string file)
{
	mapping localm;

	localm = ([ "x" : 1, "y" : 2, "z" : 3, "file" : "/d/fy/fysquare" ]);
	if ( !mapp(local) )
		local = ({ localm });
	else
		local += ({ localm });
}

int query_local(string arg)
{
	for (int i = 0; i < sizeof(local); i++)
	{
		write("x    : " + local[i]["x"] + "\n"
		    + "y    : " + local[i]["y"] + "\n"
		    + "z    : " + local[i]["z"] + "\n"
		    + "file : " + local[i]["file"] + "\n");
	}
	return 1;
}

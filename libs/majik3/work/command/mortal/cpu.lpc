/* CPU COMMAND by namhas */

int
main (string str)
{
    mapping info;
    float i, j, k;
    int f_verbose;

    if (str == "-v" || str == "--verbose")
	f_verbose = 1;

    info = rusage();

    i = ( info["utime"] + info["stime"] ) / uptime ();
    j = info["utime"] * 100.0 / ( info["utime"] + info["stime"] );
    k = info["stime"] * 100.0 / ( info["utime"] + info["stime"] );

    if (!f_verbose)
    {
	printf (
	  "CPU usage: %2.02f%% (user: %2.02f%% system: %2.02f%%) Memory used: %dK\n"
	  + "Type 'cpu --verbose' if you want detailed info about cpu.\n",
	  i/10.0, j, k, memory_info() / 1024);
    }
    else
    {
	cat ("/data/proc/cpuinfo");
    }

    /*
    score = no*100/que;

	mapping info;
	int *luvut;

	int x,y;

	luvut = ({ 0, 0, 0 });
	info = rusage();
	x = ( info["utime"] + info["stime"] ) / uptime();
	if (x == 0)
	{
	    printf("CPU usage "+C_BLD+"0"+C_NRM+"."+C_BLD+"0"+C_NRM+"%% (");
	}
	else
	{
	    while (x > 9) 
	    {
		luvut[y] = x % 10;
		x = x / 10;
		y++;
	    }
	    luvut[y] = x;
	    if (luvut[2] == 0)
		printf("CPU usage: "+C_BLD+"%d"+C_NRM+"."+C_BLD+"%d"+C_NRM+"%% (",luvut[1],luvut[0]);
	    else
		printf("CPU usage: "+C_BLD+"%d"+"%d"+C_NRM+"%% (",luvut[2],luvut[1]);
	}
	info = rusage();
	write("utime: " + info["utime"] + "ms, ");
	write("stime: " + info["stime"] + "ms) " + query_load_average() + "\n");
    */
    return 1;
}

query_author ()
{
  return "namhas";
}

query_synopsis ()
{
  return "cpu [--verbose]";
}

query_help ()
{
  return "This command shows you some information based on cpu usage.";
}

query_see_also ()
{
  return "uptime(1)";
}

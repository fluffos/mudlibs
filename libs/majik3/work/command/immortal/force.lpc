#include <security.h>

int main (string str)
{
    string who, what;
    object ob;
    int i, utime1, stime1, utime2, stime2, tmp;
    mapping rusage_info;

    rusage_info = rusage();

    if (!str)
		return 0;
    if (sscanf(str, "%s to %s", who, what) == 2 ||
		sscanf(str, "%s %s", who, what) == 2) {
        if (!present(lower_case(who),ENV(THIS)))
            ob = (find_player(lower_case(who)) || find_living(who) || find_object(who));
	else
           ob = present(lower_case(who),ENV(THIS));
	if (!ob) {
	    write("No such player.\n");
	    return 1;
	}
	if (ob->query_security() > this_player()->query_security() ||
		(THIS->query_security() < SEC5 && interactive(ob)))
	{
	    write ("Permission denied.\n");
		if (ob->query_security() > 0)
			tell_object (ob, capitalize(THIS->query_name()) + " tried to force you to: "+what+"\n");
	    return 1;
	}
	if (THIS->query_name() != "namhas")
	    tell_object(ob, capitalize(this_player()->query_name()) + " force you to: " + what + "\n");
	utime1 = rusage_info["utime"];
	stime1 = rusage_info["stime"];
	i = ob->force_us (what);
	rusage_info = ([ ]);
	rusage_info = rusage();
	utime2 = rusage_info["utime"];
	stime2 = rusage_info["stime"];
	if (THIS->query_security() > 10)
	{
	    tmp = (utime2 - utime1) + (stime2 - stime1);
	    message ("wizinfo",
	      "Evaluation cost      : ^c1"+ i +"^c0 = ^c1"+(i/1024)+"^c0K\n" +
	      "CPU usage difference : ^c1"+tmp+"^c0 ms (^c1" + (utime2 - utime1) + "^c0 ms user, ^c1" +
	      (stime2 - stime1) + "^c0 ms system)\n", THIS);
	}

	write("Done.\n");
	write_file ("/log/force", ctime(time()) + " :: " +THIS->query_cap_name() +
	  " forces "+ob->query_cap_name()+" to: " + what + "\n");
	return 1;
    }
    return 0;
}


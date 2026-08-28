/*
 * Informer            by Dazzt
 * */

inherit ITEM;

string msg;
int delay;
int active;

init()
{
    add_action("do_set", "informer");
}

long()
{
    string str;
    active = 0;


    str = "Informer is here to inform the mud from various things.\n" +
    "It can be controlled with 'informer' command.\n" +
    "Currently it has the following message to say:\n " +
    msg + "\n" +
    "It echoes it every " + delay / 60 + " seconds.\n";
    if (active)
	str += "It's active.\n";
    else 
	str += "It's inactive.\n";
    return str;
}

create_item()
{
    if (!msg)
	msg = "";

    set_name(({"informer", "mystic", "whizzo'mystic"}));
    set_short("a mystical whizzo'mystic is here spamming the mud");

	set_no_get(1);
    set_hp(50000);
    set_max_hp(50000);
    set_material("steel");
}

infotus()
{
	message("info", msg, users());
    call_out("infotus", delay);
}

do_set(string str)
{
    string a1, a2;

    if (!str)
    {
	write("usage: informer [msg/delay/start/stop] <message>/<delay in minutes>\n");
	return 1;
    }
    if (sscanf(str, "%s %s", a1, a2) == 2)
    {
	if (a1 == "msg")
	{       
	    msg = a2 + "\n";
	    write("Message set to: " + msg);
	    return 1;
	}
	if (a1 == "delay")
	{
	    sscanf(a2, "%d", delay);
	    if (delay == 0)
	    {
		write("Please set delay first!\n");
		return 1;
	    }
	    delay = delay * 60;
	    write("Delay set to " + delay / 60 + " minutes.\n");
	    return 1;
	}
    }
    if (str == "start")
    {
	call_out("infotus", delay);
	write("Informer is now active.\n");
	active = 1;
	return 1;
    }
    if (str == "stop")
    {
	remove_call_out("infotus");
	write("Informer is now disabled.\n");
	active = 0;
	return 1;
    }
    write("usage: informer [msg/delay/start/stop] <message>/<delay in minutes>\n");

    return 1;
}






#define TP this_player()

int ctime_cmd(string str)
{
    int time;

    if(!TP->query_coder_level())
	return 0;

    if(!str) {
	notify_fail("Usage: ctime <command>\n");
	return 0;
    }

    time=command(str,TP);

    if(time)
	printf("Command: \"%s\" took %d ticks.\n",str,time);
    else {
	notify_fail("No such command.\n");
	return 0;
    }
    return 1;
}

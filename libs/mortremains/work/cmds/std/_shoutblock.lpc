inherit DAEMON;

int cmd_shoutblock() {
    int i;

    i = TP->query("shoutblock");

    if (i) {
	write("You turn your shoutblock off.\n");
	TP->delete("shoutblock");
    } else {
	write("You turn your shoutblock on.\n");
	TP->set("shoutblock", 1);
    }

    return 1;
}

string help() {
    return (wrap("Having your shoutblock on prevents you from hearing shouts.") );
}
/* EOF */

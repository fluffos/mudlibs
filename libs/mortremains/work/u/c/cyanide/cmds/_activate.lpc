int cmd_activate(string str) {
    object ware;

    if (!str) {
	write("Activate what?\n");
	return 1;
    }

    ware = present(str, TP);

    if (!ware) {
	write("You do not have that.\n");
	return 1;
    }

    if (!ware->query_cyberware()) {
	write("That is not cyberware.\n");
	return 1;
    }

    if (ware->query_active()) {
	write("That item is already actiave.\n");
	return 1;
    }

    if (ware->std_activate(TP)) 
	write("Successful.\n");
    else
	write("Failed.\n");

    return 1;
}

// EOF

// Cyanide - 3/15/00
// Allows people to be added to a gang.

inherit DAEMON;

int cmd_gangallow( string str ) {
    int i;

    i = TP->query("gangallow");

    if (i) {
        write("You can no longer be added to a gang.\n");
        TP->delete("gangallow");
    } else {
        if (TP->query("gang")) {    
            write("You are already a member of a gang.\n"+
            "Type 'gquit' to leave your gang.\n");
            TP->delete("gangallow");
        } else {
            write("You may now be added to a gang.\n");
            TP->set("gangallow", 1);
        }
    }
    
    return 1;
}

string help() {
    return 
    ("This command makes it possible for other to add you to their "+
    "gang.\n");
}

/* EOF */
/*
** FILE:    _ammo.c
** PURPOSE: Tells a player how much ammo he/she is carrying.
** CREDITS:
**    12 Jun 99  Cyanide created the file.
*/ 

int cmd_ammo(string str) {
    int i, sz, *v_ammo;
    string *k_ammo;
    mapping ammo = ([]);

    if (TP->query("ammo")) 
	ammo = TP->query("ammo");

    v_ammo = values(ammo);
    k_ammo = keys(ammo);
    sz = sizeof(v_ammo);

    if (!sz) {
        write("You are carrying no ammunition at this time.\n") ;
	return 1;
    }

    write("You are carrying the following ammunition:\n");
    for (i=0; i<sz; i++) {
	write(sprintf("  %10s   :   %-d\n", k_ammo[i], v_ammo[i]));
    }

    return 1;
}

string help() {
    string help;

    help = "This command shows the amount and type of ammunition "+
    "you currently carry.";

    return wrap(help);
}
/* EOF */

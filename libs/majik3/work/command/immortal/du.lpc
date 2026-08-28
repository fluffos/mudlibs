int total = 0;

Recurse(string);

int main (string str) {
    total = 0;
    if (!str) str = ".";
    if (!absolute_path(str)) { 
	str = THIS->query_cwd() + str ;
    }
    str = resolve_path(str) ;
    if (file_size(str) != -2) {
	notify_fail (str + ": No such directory.\n");
	return 0 ;
    }
    Recurse (str + "/");
    message("misc", sprintf("%-20s ^cW%-10d^c0 bytes\n", "Total Disk Usage", total), this_player());
    return 1 ;
}

Recurse(string dir) {
    mixed *junk;
    int i;

    write(dir + "\n");
    junk = get_dir(dir, -1);
    for (i=0; i<sizeof(junk); i++) {
	if (junk[i][1] == -2)
	    Recurse (dir + junk[i][0] + "/");
	else 
	    total += junk[i][1];
    }
    return 1;
}
